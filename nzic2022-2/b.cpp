#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < int(n); i++)

int main() {
    int n;
    cin >> n;

    int ans = 0;
    rep(i,n) {
        int w;
        cin >> w;
        vector<int> a(2), p(2);
        rep(j,2) cin >> a[j] >> p[j];
        if(p[0] > p[1]) {
            swap(p[0], p[1]);
            swap(a[0], a[1]);
        }

        rep(j,2) {
            if(w <= a[j]) {
                ans += p[j]*w;
                w = 0;
                break;
            } else {
                ans += p[j]*a[j];
                w -= a[j];
            }
        }
    }

    cout << ans << '\n';
    return 0;
}