int root = INF2; //根
vector<int> lc;
vector<int> rc;
vector<int> par;

void make_tree(vector<int> v) {
    stack<int> st;
    int n = v.size();
    lc.resize(n, -1);
    rc.resize(n, -1);
    par.resize(n, -1);
    for(int i = 0; i < n; i++) {
        while(!st.empty()) {
            int x = st.top();
            if(v[x] < v[i]) break;
            lc[i] = x;
            par[x] = i;
            st.pop();
        }
        if(!st.empty()) {
            rc[st.top()] = i;
            par[i] = st.top();
        }
        st.push(i);
    }
    return;
}

for(int i = 0; i < n; i++) {
    if(par[i] == -1) root = i;
}