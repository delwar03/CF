#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e12 + 10;

vector<int> fact;
map<int, int> mp;

void solve() {
    int n; cin>>n;
    int ans = __builtin_popcountll(n);
    int cnt = INF;
    for(auto it : mp) {
        if(it.first <= n) {
            int m = n - it.first;
            cnt = it.second + __builtin_popcountll(m);
        }
        ans = min(ans, cnt);
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int f = 6, ind = 4;

    while(f < INF) {
        fact.push_back(f);
        f *= ind++;
    }

    // for(auto it : fact) cerr<<it<<" "; cerr<<endl;

    int sz = fact.size();

    // cerr<<sz<<endl;

    for(int i = 1; i < (1LL << sz); i++) {
        int sum = 0;
        for(int j = 31; j >= 0; j--) {
            if((i >> j) & 1) {
                sum += fact[j];
            }
        }
        mp[sum] = __builtin_popcountll(i);
    }

    // cerr<<mp.size()<<endl;
    // for(auto it : mp) cerr<<it.first<<" -> "<<it.second<<endl;

    int t = 1; cin>>t;
    while(t--) {
        solve();
    }
}

/*
i/p: 
o/p: 
*/