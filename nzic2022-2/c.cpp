#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < int(n); i++)
const int inf = 1 << 30;

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i,n) cin >> s[i];

    sort(s.begin(), s.end());
    int mx = inf*-1, mn = inf;
    rep(i,n/2) {
        int sum = s[i] + s[n-i-1];
        mx = max(mx, sum);
        mn = min(mn, sum);
    }

    cout << mx-mn << '\n';
    return 0;
}