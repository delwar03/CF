#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;

int f(int n) {
    int l = 1, r = 1e5;
    int res = 1;
    while(l <= r) {
        int m = (l + r) / 2;
        if(m * (m + 1) / 2 <= n) {res = m; l = m + 1; }
        else r = m - 1;
    }
    return res;
}

void solve() {
    int n; cin>>n;
    int ans = 0;
    int i = 2;
    set<int> st;
    map<int, int> mp;
    while(i * i <= n) {
        if(n % i == 0) {
            int j = i;
            while(n % i == 0) {
                st.insert(j);
                n /= i;
                mp[i]++;
            }
        }
        i++;
    }
    if(n > 1) {st.insert(n); mp[n]++; }
    for(auto it : mp) {ans += f(it.second); }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 