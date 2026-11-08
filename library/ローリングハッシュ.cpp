//検索対象文字列S(n文字)に検索文字列T(m文字)が含めれるかどうか
//時間計算量O(n + m)
// ローリングハッシュ
const ull MOD = 0x1fffffffffffffff;
mt19937_64 mt{(unsigned int)time(NULL)};
ull base = mt() % MOD;
struct RollingHash {
    vector<ull> hashed, power;

    inline ull mul(ull a, ull b) const {
        __uint128_t res = __uint128_t(a) * b;
        res %= MOD;
        return res;
    }

    RollingHash(const string &s) {
        int n = s.size();
        hashed.resize(n + 1);
        power.resize(n + 1);
        power[0] = 1;
        for(int i = 0; i < n; i++) {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i];
            hashed[i + 1] %= MOD;
        }
    }

    //部分列s[l, ... ,r - 1]のハッシュ値を返す
    ull get(int l, int r) const {
        ull res = hashed[r] + MOD - mul(hashed[l], power[r - l]);
        res %= MOD;
        return res;   
    }

    //2つのハッシュ値h1とh2を連結したハッシュ値を返す
    //引数h2lenはハッシュ値h2を持つ文字列の長さ
    ull connect(ull h1, ull h2, int h2len) const {
        ull res = mul(h1, power[h2len]) + h2;
        res %= MOD;
        return res;
    }

    void connect(const string &s) {
        ll n = hashed.size() - 1;
        ll m = s.size();
        hashed.resize(n + m + 1);
        power.resize(n + m + 1);
        for(ll i = n; i < n + m; i++) {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i - n];
            hashed[i + 1] %= MOD;
        }
    }

    //2つの文字列区間[l1, r1), [l2, r2)における最長共通接頭辞(LCP)の長さを返す
    //引数bには比較対象のRollingHashを乗せる
    ll LCP(const RollingHash &b, ll l1, ll r1, ll l2, ll r2) {
        ll len = min(r1 - l1, r2 - l2);
        ll low = -1;
        ll high = len + 1;
        while(abs(high - low) > 1) {
            ll mid = (low + high) / 2;
            if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
            else high = mid;
        }
        return low;
    }
};






//ロリハ(値が小さいversion)
const int _base = 1e9 + 7;

struct RollingHash
{
  vector< unsigned > hashed, power;
  RollingHash(const string& s)
  {
    int sz = s.size();
    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
 
    power[0] = 1;
    for(int i = 0; i < sz; i++) {
      power[i + 1] = power[i] * _base;
    }
    for(int i = 0; i < sz; i++) {
      hashed[i + 1] = (hashed[i] + s[i]) * _base;
    }
  }
  unsigned get(int l, int r) // [l, r)
  {
    return((hashed[r] - hashed[l] * power[r - l]));
  }
  unsigned connect(int h1, int h2, int h2len)
  {
    return(h1 * power[h2len] + h2);
  }
  int LCP(RollingHash& b, int l1, int r1, int l2, int r2)
  {
    int len = min(r1 - l1, r2 - l2);
    int low = -1, high = len + 1;
    while(high - low > 1) {
      int mid = (low + high) >> 1;
      if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
      else high = mid;
    }
    return(low);
  }
};
