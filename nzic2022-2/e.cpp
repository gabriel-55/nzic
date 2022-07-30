#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1LL << 62;
#define rep(i,n) for(ll i = 0; i < ll(n); i++)
#define REP(i,a,b) for(ll i = a; i < ll(b); i++)

int main() {
   ll h, w, n;
   cin >> h >> w >> n;
   vector<ll> x(n), y(n);
   rep(i,n) cin >> y[i] >> x[i];
    
   ll df = 0, idf = 0;
   rep(i,n) {
      ll nd = (w-x[i])*(w-x[i]) + y[i]*y[i];
      if(nd > df) {
         df = nd;
         idf = i;
      }
   }

   set<ll> p;
   p.insert(0);
   for(auto &np : p) {
         ll di = 0, idi = 0;
         rep(i,n) {
            ll nd = (x[i]-np)*(x[i]-np) + y[i]*y[i];
            if(nd > di) {
                di = nd;
                idi = i;
            }
         }

      if(idi == idf) {
         if(np != 0) break;
         cout << x[idi] << '\n';
         return 0;
      }

      auto solve = [&](ll nx) -> bool {
         ll mxd = 0, mxidx = 0;
         rep(i,n) {
            ll nd = (x[i]-nx)*(x[i]-nx) + y[i]*y[i];
            if(nd > mxd) {
               mxd = nd;
               mxidx = i;
            }
         }
         if(mxidx == idi) return true;
         else return false;
      };

      ll ok = np, ng = w+1;
      while(abs(ok-ng) > 1) {
         ll m = ok + ng >> 1;
         if(solve(m)) ok = m;
         else ng = m;
      }

      if(ok <= w && ok+1 >= 0) p.insert(ok+1);
   }

   ll res = inf, ans = 0;
   for(auto &np : p) {
      ll nx = np;
      rep(k,2){
         if(nx >= 0 && nx <= w) {
            ll mxdist = 0;
            rep(i,n) {
               ll nd = (x[i]-nx)*(x[i]-nx) + y[i]*y[i];
               mxdist = max(mxdist, nd);
            }
            if(mxdist < res) {
               res = mxdist;
               ans = nx;
            } else if (mxdist == res) ans = min(ans, nx);
         }
         nx--;
      }
   }

   cout << ans << '\n';
   return 0;
}