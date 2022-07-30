#include <bits/stdc++.h>
using namespace std;

int main() {  
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i-1]) {
            s[i] = 'X';
            ans++;
        }
    }
    
    cout << ans << '\n';
    return 0;
}