//floor sum [n / i]
//グラフ上の格子点を考える
for(ll i = 1; i * i <= n; i++) {
    sum += (n / i - i) * 2;
    sum++; //重複分加算
}


//floor sum [n / i]
//√nで区切る
for(ll i = 1; i <= n; i++) {
    if(i * i <= n) k = i;
    else break;
}

//商が√nより大きい部分
for(ll i = 1; i <= k; i++) {
    ans += ((n / i) - (n / (i + 1))) * i;
}

//商が√n以下の部分
for(ll i = 1; i <= n / (k + 1); i++) {
    ans += n / i;
}