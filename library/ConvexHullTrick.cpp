//最小値version
struct ConvexHullTrick {
    struct Line {
        ll a, b;
        ll get(ll x) {return a * x + b;}
    };
    vector<Line> vec;
    int head = 0;
    bool check(Line a, Line b, Line c) {
        return (b.b - c.b) * (b.a - a.a) <= (a.b - b.b) * (c.a - b.a);
    }
    void add(ll a, ll b) {
        //最小値→傾きが単調減少 backが最小
        Line l{a, b};
        while(vec.size() > 1 && check(vec[vec.size() - 2], vec.back(), l)) {
            vec.pop_back();
        }
        vec.push_back(l);
    }
    ll query(ll x) {
        if(vec.empty()) return INF;
        //クエリが単調の場合(線形)
        while(vec.size() - head > 1 && vec[head].get(x) >= vec[head + 1].get(x)) {
            head++;
        }
        return vec[head].get(x);

        //クエリが単調でない場合(log n)
        // int low = -1;
        // int high = vec.size() - 1;
        // while(abs(high - low) > 1) {
        //     int mid = (high + low) / 2;
        //     if(vec[mid].get(x) >= vec[mid + 1].get(x)) {
        //         low = mid;
        //     } else {
        //         high = mid;
        //     }
        // }
        // return vec[high].get(x);
    }
};

//最大値version
struct ConvexHullTrick {
    struct Line {
        ll a, b;
        ll get(ll x) {
            return a * x + b;
        }
    };

    vector<Line> vec;
    int head = 0;
    bool check(Line a, Line b, Line c) {
        return (b.b - c.b) * (b.a - a.a) <= (a.b - b.b) * (c.a - b.a);
    }

    void add(ll a, ll b) {
        //最大値→傾きが単調増加 backが最大
        Line l{a, b};
        while(vec.size() - head > 1 && check(vec[vec.size() - 2], vec.back(), l)) {
            vec.pop_back();
        }
        vec.push_back(l);
    }

    ll query(ll x) {
        if(vec.empty()) return -INF;
        while(vec.size() - head > 1 && vec[head].get(x) <= vec[head + 1].get(x)) {
            head++;
        }
        return vec[head].get(x);

        //クエリが単調でない場合(log n)
        // int low = -1;
        // int high = vec.size() - 1;
        // while(abs(high - low) > 1) {
        //     int mid = (high + low) / 2;
        //     if(vec[mid].get(x) <= vec[mid + 1].get(x)) {
        //         low = mid;
        //     } else {
        //         high = mid;
        //     }
        // }
        // return vec[high].get(x);
    }
};