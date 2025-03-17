#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<string> col = {"BG", "BR", "BY", "GR", "GY", "RY"};

void solve() {
    int n, q; cin>>n>>q;
    vector<string> v(n + 1);
    map<string, vector<int>> mp;
    for(int i = 1; i <= n; i++) {
        string s; cin>>s;
        v[i] = s;
        mp[s].push_back(i);
    }

    while(q--) {
        int x, y; cin>>x>>y;
        if(x > y) swap(x, y);
        string s1 = v[x], s2 = v[y];

        if(s1[0] == s2[0] || s1[0] == s2[1] || s1[1] == s2[0] || s1[1] == s2[1]) {
            cout<<abs(y - x)<<endl;
        } else {
            vector<string> tmp;
            for(auto str : col) {
                if(s1 == str) continue;
                if(s1[0] == str[0] || s1[0] == str[1] || s1[1] == str[0] || s1[1] == str[1]) {
                    tmp.push_back(str);
                }
            }
            assert(tmp.size() == 4);

            int ans = INF;

            for(auto str : tmp) {
                auto it = lower_bound(mp[str].begin(), mp[str].end(), x);
                if(it != mp[str].end()) {
                    ans = min(ans, abs(x - *it) + abs(*it - y));
                }
                if(it != mp[str].begin()) {
                    --it;
                    ans = min(ans, abs(x - *it) + abs(*it - y));
                }
            }

            cout<<(ans == INF ? -1 : ans)<<endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/