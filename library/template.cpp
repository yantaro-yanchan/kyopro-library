#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
//using namespace atcoder;
//python3 expander.py main.cpp
//export CPLUS_INCLUDE_PATH="/home/yantaro/kyopro/ac-library-master"

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using lll = __int128_t;
using ulll = __uint128_t;

//using mint = modint; //mint::set_mod(M);
//using mint = modint998244353;
//using mint = modint1000000007;

template<class T> using pq = priority_queue<T>; //大きい順
template<class T> using pq_g = priority_queue<T, vector<T>, greater<T>>; //小さい順

#define vec_unique(v) v.erase(unique(v.begin(), v.end()), v.end()) //重複削除
#define vec_iota(v) iota(v.begin(), v.end(), 0) //0, 1, 2, 3, ..., n - 1にセット
#define concat(a, b) a.insert(a.end(), b.begin(), b.end())
#define debug(x) cerr << #x << " = " << x << endl
#define maxvalue(array) *max_element(array.begin(), array.end())
#define minvalue(array) *min_element(array.begin(), array.end())
#define sumvalue(array) accumulate(array.begin(), array.end(), 0ll)
#define popcount(x) __builtin_popcountll(x)

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
//int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

#define INF 2e18
#define INF2 2e9

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) {
        solve();
    }
    //cout << fixed << setprecision(15) << << endl;
    return 0;
}