#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i,n) for(ll i = 0; i < ll(n); i++)
#define REP(i,a,b) for(ll i = a; i < ll(b); i++)

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];

    vector<vector<ll>> dp(n, vector<ll>(101, -1));
    dp[0][0] = v[0];
    if(v[0] <= 100) dp[0][v[0]] = 0;

    REP(i,1,n) rep(j,101) {
        if(dp[i-1][j] == -1) continue;
        dp[i][j] = max(dp[i][j], dp[i-1][j]+v[i]);
        if(j+v[i] <= 100) dp[i][j+v[i]] = max(dp[i][j+v[i]], dp[i-1][j]);
        else dp[i][100] = max(dp[i][100], dp[i-1][j]);
    }

    ll ans = 0;
    rep(j,101) ans = max(ans, dp[n-1][j]*j);
    cout << ans << '\n';
    return 0;
}