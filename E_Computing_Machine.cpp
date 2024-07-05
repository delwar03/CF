#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    string s, t; cin>>s>>t;
    string s1 = s, t1 = t;

    for(int i = 1; i < n - 1; i++) {
        if(s[i - 1] == '0' && s[i + 1] == '0') t1[i] = '1';
    }

    map<int, vector<int>> mp;

    for(int i = 1; i < n - 1; i++) {
        if(s[i] == '1') {
            mp[i] = {-1, -1};
        } else {
            if(t1[i - 1] == '1' && t1[i + 1] == '1') {
                s1[i] = '1';
                mp[i] = {i - 1, i + 1};
                if(t[i - 1] != '1') mp[i][0]--;
                if(t[i + 1] != '1') mp[i][1]++;
            }
        }
    }

    vector<int> pf(n, 0), pf1(n, 0);
    pf[0] = (s[0] == '1');
    pf1[0] = (s[0] == '1');

    for(int i = 1; i < n; i++) {
        pf[i] = pf[i - 1] + (s[i] == '1');
        pf1[i] = pf1[i - 1] + (s[i] == '0' && s1[i] == '1');
    }

    int q; cin>>q;

    while(q--) {
        int l, r; cin>>l>>r; 
        --l; --r;

        int ans = pf[r] - (l - 1 >= 0 ? pf[l - 1] : 0);

        if(r - l + 1 <= 4) {
            for(int i = l; i <= r; i++) {
                if(s[i] == '0' && s1[i] == '1' && mp[i][0] >= l && mp[i][1] <= r) {
                    ans++;
                }
            }
        } else {
            for(int i : {l, l + 1, r, r - 1}) {
                if(s[i] == '0' && s1[i] == '1' && mp[i][0] >= l && mp[i][1] <= r) {
                    ans++;
                }
            }
            ans += pf1[r - 2] - pf1[l + 2 - 1];
        }

        cout<<ans<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}

/*
i/p: 
o/p: 
*/