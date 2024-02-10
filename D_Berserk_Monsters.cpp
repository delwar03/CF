#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> a(n), d(n), c(n);
    for(auto &x : a) cin>>x;
    for(auto &x : d) cin>>x;
    set<vector<int>> st;
    set<int> alive;

    for(int i = 0; i < n; i++) {
        int spell = d[i];
        if(i) spell -= a[i - 1];
        if(i < n - 1) spell -= a[i + 1];
        c[i] = spell;
        st.insert({spell, i});
        alive.insert(i);
    }

    alive.insert(-1);
    alive.insert(n);
    for(int i = 0; i < n; i++) {
        set<int> died, toBeUpdated;
        while(st.size() && (*st.begin())[0] < 0) {
            auto it = *st.begin();
            st.erase(st.begin());
            died.insert(it[1]);
            alive.erase(it[1]);
        }
        // for(auto it : died) cout<<it<<" "; cout<<endl;
        cout<<died.size()<<" \n"[i == n - 1];
        for(auto &x : died) {
            auto it = alive.upper_bound(x);
            if(*it != n) toBeUpdated.insert(*it);
            it--;
            if(*it != -1) toBeUpdated.insert(*it);
        }
        // for(auto it : toBeUpdated) cout<<it<<" "; cout<<endl;
        for(auto &x : toBeUpdated) {
            st.erase({c[x], x});
            auto it = alive.lower_bound(x);
            it--;
            int spell = d[x];
            if(*it != -1) spell -= a[*it];
            it++;
            it++;
            if(*it != n) spell -= a[*it];
            c[x] = spell;
            st.insert({c[x], x});
        }
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
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 