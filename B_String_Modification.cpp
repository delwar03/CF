#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

string f(string s, int ind) {
    string a, b;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        if(i < ind) b.push_back(s[i]);
        else a.push_back(s[i]);
    }
    if((n - ind) & 1) reverse(b.begin(), b.end());
    string ans = a + b;
    return ans;
}

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    char mnChar = 'z';
    for(auto ch : s) {
        if(ch < mnChar) mnChar = ch; 
    }
    // cout<<mnChar<<endl;
    set<pair<string, int>> st;
    for(int i = 0; i < n; i++) {
        if(s[i] == mnChar) {
            string tmp = f(s, i);
            st.insert({tmp, i + 1});
        }
    }
    auto ans = *st.begin();
    cout<<ans.first<<"\n"<<ans.second<<endl;
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