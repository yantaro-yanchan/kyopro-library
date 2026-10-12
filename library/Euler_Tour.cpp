//オイラーツアー dfs
vector<int> vec; //オイラーツアーの頂点配列
vector<int> ind(n); //各頂点がオイラーツアー配列の何番目に最初に訪れるか
vector<vector<int>> cnt(n);
vector<int> dist(n);
vector<int> oud(n); //各頂点がオイラーツアー配列の何番目に最後に訪れるか

auto dfs = [&](auto dfs, int now, int par) -> void {
    ind[now] = vec.size();
    cnt[dist[now]].push_back(vec.size());
    vec.push_back(now);
    for(auto next_v : graph[now]) {
        if(next_v == par) continue;

        dist[next_v] = dist[now] + 1;
        dfs(dfs, next_v, now);
    }
    oud[now] = vec.size();
};

dist[0] = 0;
dfs(dfs, 0, -1);