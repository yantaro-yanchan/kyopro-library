//文字iを中心とする最長の回文の半径を記録した配列を構築する
//「a$b$a$a$b」みたいにすると奇数長でも偶数長でもできるようになる
vector<int> manacher(string &s) {
    int n = s.size();
    vector<int> res(n);
    int i = 0, j = 0;
    while(i < n) {
        while(i - j >= 0 && i + j < n && s[i - j] == s[i + j]) j++;
        res[i] = j;
        int k = 1;
        while(i - k >= 0 && k + res[i - k] < j) res[i + k] = res[i - k], k++;
        i += k;
        j -= k;
    }

    return res;
}


//回文判定
auto ispalin = [&](int l, int r) -> bool {
    int L = 2 * l;
    int R = 2 * r - 1;

    int mid = (L + R) / 2;
    int need = (R - L + 1) / 2;
    
    if(res[mid] == need) return true;
    else return false;
};