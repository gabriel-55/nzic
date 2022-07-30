#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < int(n); i++)
const int inf = 1 << 30;

int main() {
   cin.tie(nullptr);
   ios::sync_with_stdio(false);

   int n, e;
   cin >> n >> e;

   vector<vector<int>> g(n);
   rep(i,e) {
      int a, b;
      cin >> a >> b;
      g[a].emplace_back(b);
      g[b].emplace_back(a);
   }

   vector<int> d(n, inf);
   queue<int> q;

   int s, m;
   cin >> s >> m;

   if(m > 0) m--;
   m *= -1;

   rep(i,s){
      int t;
      cin >> t;
      d[t] = m;
      q.push(t);
   }

   while(!q.empty() && m < 0) {
       int k = q.size();
       rep(i,k){
           int x = q.front();
           q.pop();

           for(int nx : g[x]) {
               if(d[nx] <= m) continue;
               d[nx] = m;
               q.push(nx);
           }
       }
       m++;
   }

   d[0] = 1;
   q = {};
   q.push(0);

   while(!q.empty()) {
      int x = q.front();
      q.pop();

      for(int nx : g[x]) {
         if(d[nx] != inf) continue;
         d[nx] = d[x] + 1;
         q.push(nx);
      }
   }

   if(d[n-1] <= 0 || d[n-1] == inf) cout << "SELF_ISOLATE" << '\n';
   else cout << d[n-1] << '\n';
   return 0;
}