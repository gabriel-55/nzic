#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < int(n); i++)
#define REP(i,x,y) for(int i = x; i < int(y); i++)
#define fi first
#define se second
const int inf = 1 << 30;

int n, sz;
vector<pair<int, int>> v;

int f(int x, int s) {
    int L = 0, R = sz;
    while(R-L > 0) {
        int M = (L+R)/2;
        if(v[M].fi >= s) R = M;
        else L = M+1;
    }
    
    if(L-1 < 0) return inf;
    if(v[L-1].se > x) return inf;
    return v[L-1].se;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> n >> a >> b;

    vector<int> d(n);
    rep(i,n) {
        int t;
        cin >> t;
        if(t >= a && t <= b) d[i] = 1;
        else d[i] = -1;
    }

    vector<int> s(n+1, 0);
    rep(i,n) s[i+1] = s[i] + d[i];

    vector<pair<int, int>> p(n+1);
    rep(i,n+1) p[i] = {s[i], i};
    sort(p.begin(), p.end());

    v.emplace_back(p[0]);
    int nv = 0;
    REP(i,1,n+1) {
        if(v[nv].fi == p[i].fi) v[nv].se = min(v[nv].se, p[i].se);
        else {
            v.push_back({p[i].fi, min(p[i].se, v[nv].se)});
            nv++;
        }
    }
    sz = v.size();

    int ans = 0;

    REP(i,1,n+1) {
        int x = f(i, s[i]);
        if(x != inf) ans = max(ans, i-x);
    }

    cout << ans << '\n';
    return 0;
}