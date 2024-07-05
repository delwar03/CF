#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    set<char> st(s.begin(), s.end());
    map<char, char> mp;
    while(st.size() >= 2) {
        char ch1 = *st.begin();
        char ch2 = *st.rbegin();
        mp[ch1] = ch2;
        mp[ch2] = ch1;
        st.erase(st.begin());
        st.erase(--st.end());
    }
    if(st.size()) {
        char ch1 = *st.begin();
        mp[ch1] = ch1;
    }
    for(int i = 0; i < n; i++) {
        s[i] = mp[s[i]];
    }
    cout<<s<<endl;
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