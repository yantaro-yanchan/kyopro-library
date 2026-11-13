// https://sotanishy.github.io/cp-library-cpp/data-structure/cht/li_chao_tree.hpp.html
// を最小値・最大値の両対応に改変したもの
//
// IsMin = true  : get(x) は min(a*x + b) を返す (直線が無ければ numeric_limits<T>::max())
// IsMin = false : get(x) は max(a*x + b) を返す (直線が無ければ numeric_limits<T>::lowest())
template <typename T, bool IsMin = true>
class LiChaoTree {
   public:
    LiChaoTree() = default;
    explicit LiChaoTree(const std::vector<T>& vs) : xs(vs) {
        assert(!xs.empty());
        std::sort(xs.begin(), xs.end());
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
        size = bit_ceil_int(xs.size());
        node.resize(2 * size, Line(0, ID));
        while ((int)xs.size() <= size) xs.push_back(xs.back() + 1);
    }
 
    // 直線 y = a x + b を追加
    void add_line(T a, T b) { update(Line(a, b), 1, 0, size); }
 
    // 線分 y = a x + b (x in [xl, xr)) を追加
    void add_segment(T a, T b, T xl, T xr) {
        int l = (int)(std::lower_bound(xs.begin(), xs.end(), xl) - xs.begin());
        int r = (int)(std::lower_bound(xs.begin(), xs.end(), xr) - xs.begin());
        // xl, xr が座標の範囲外でも node の範囲外に出ないように丸める
        l = std::min(l, size);
        r = std::min(r, size);
 
        Line line(a, b);
        int len = 1;
        int l0 = l, r0 = r;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1, len <<= 1) {
            if (l & 1) {
                update(line, l++, l0, l0 + len);
                l0 += len;
            }
            if (r & 1) {
                --r;
                r0 -= len;
                update(line, r, r0, r0 + len);
            }
        }
    }
 
    // x における最小値 (IsMin = false なら最大値) を返す
    // x はコンストラクタに渡した座標に含まれている必要がある
    T get(T x) const {
        int k = (int)(std::lower_bound(xs.begin(), xs.end(), x) - xs.begin());
        k += size;
        T res = node[k](x);
        while (k >>= 1) {
            T v = node[k](x);
            if (better(v, res)) res = v;
        }
        return res;
    }
 
   private:
    // 単位元: 最小値なら +INF, 最大値なら -INF
    static constexpr T ID = IsMin ? std::numeric_limits<T>::max()
                                  : std::numeric_limits<T>::lowest();
 
    struct Line {
        T a, b;
        Line(T a_, T b_) : a(a_), b(b_) {}
        T operator()(T x) const {
            if (a == 0 && b == ID) return ID;
            return a * x + b;
        }
    };
 
    // x が y より真に良いか (最小値なら x < y, 最大値なら x > y)
    static bool better(T x, T y) { return IsMin ? x < y : x > y; }
 
    int size;
    std::vector<T> xs;
    std::vector<Line> node;
 
    // std::bit_ceil(n) の代替: n 以上の最小の 2 のべき
    static int bit_ceil_int(std::size_t n) {
        int s = 1;
        while ((std::size_t)s < n) s <<= 1;
        return s;
    }
 
    void update(Line line, int k, int l, int r) {
        while (true) {
            int m = l + (r - l) / 2;  // midpoint の代替
            bool left_  = better(line(xs[l]), node[k](xs[l]));
            bool mid    = better(line(xs[m]), node[k](xs[m]));
            bool right_ = better(line(xs[r]), node[k](xs[r]));
 
            if (!left_ && !right_) break;
            if (left_ && right_) {
                node[k] = line;
                break;
            }
            if (mid) std::swap(node[k], line);
            if (r - l == 1) break;
            if (left_ != mid) {
                k = 2 * k;
                r = m;
            } else {
                k = 2 * k + 1;
                l = m;
            }
        }
    }
};
 
template <typename T>
using LiChaoTreeMin = LiChaoTree<T, true>;
template <typename T>
using LiChaoTreeMax = LiChaoTree<T, false>;