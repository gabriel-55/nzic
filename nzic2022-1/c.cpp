#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < int(n); i++)

int main() {
    string s;
    cin >> s;
    vector<int> c(6, 0);
    string t = "GRM";
    int sz = s.size();
    rep(i,sz) rep(j,3) {
        if(s[i] == 'B') {
            if(i+1 == sz) {
                c[3]++;
                break;
            }
            if(s[i+1] == 'l') c[4]++;
            else if(s[i+1] == 'r') c[5]++;
            else c[3]++;
        }

        if(s[i] == t[j]) c[j]++;
    }

    vector<bool> ng(6, 0);
    int cnt = 0;
    rep(i,6) {
        if(c[i]%2 != 0) ng[i] = 1;
        else cnt++;
    }
    if(cnt == 6) {
        cout << "All paired up!" << '\n';
        return 0;
    }

    if(ng[0]) cout << "A Green shoe has no partner." << '\n';
    if(ng[3]) cout << "A Black shoe has no partner." << '\n';
    if(ng[1]) cout << "A Red shoe has no partner." << '\n';
    if(ng[4]) cout << "A Blue shoe has no partner." << '\n';
    if(ng[5]) cout << "A Brown shoe has no partner." << '\n';
    if(ng[2]) cout << "A Mustard shoe has no partner." << '\n';

    return 0;
}