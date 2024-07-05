#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, k; cin>>n>>k;
    map<int, int> mp;
    vector<int> v(n);
    for(auto &x : v) {
        cin>>x;
        mp[x]++;
        mp[x] %= 2;
    }

    int ans = 0;
    
    vector<int> del;
    for(auto it : mp) {
        if(it.second == 0) {
            del.push_back(it.first);
        }
    }
    for(auto it : del) mp.erase(it);

    // for(auto it : mp) cerr<<it.first<<" -> "<<it.second<<endl;


    map<int, multiset<int>> mp1;

    for(auto it : mp) {
        mp1[it.first % k].insert(it.first);
    }
    int f = 0;

    for(auto it : mp1) {
        auto st = it.second;
        if(st.size() & 1) {
            f++;
            if(n % 2 == 0 && f) {
                cout<<-1<<endl;
                return;
            } else if(f > 1) {
                cout<<-1<<endl;
                return;
            }
        }
        if(st.size() & 1) {
            int ff = 1, sm = 0;
            vector<int> vv;
            while(st.size() > 1) {
                int v1 = *st.begin(); st.erase(st.begin());
                int v2 = *st.begin(); st.erase(st.begin());
                sm += v2 - v1;
                vv.push_back(v1);
                vv.push_back(v2);
            }
            vv.push_back(*st.begin());
            int mn = sm;
            for(int i = vv.size() - 2; i >= 0; i--) {
                if(ff) {
                    // - +
                    sm -= vv[i];
                    sm += vv[i + 1];
                } else {
                    sm += vv[i];
                    sm -= vv[i + 1];
                }
                ff ^= 1;
                mn = min(mn, sm);
            }
            ans += mn / k;
        } else {
            while(st.size() > 1) {
                int v1 = *st.begin(); st.erase(st.begin());
                int v2 = *st.begin(); st.erase(st.begin());
                // cout<<v1<<" "<<v2<<endl;
                ans += (v2 - v1) / k;
            }
        }
    }
    cout<<ans<<endl;
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