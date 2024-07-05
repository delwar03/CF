#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    string s = "";
    int cur, prev;
    for(int i = 0; i < n; i++) {
        cin>>cur;
        if(!i) {
            s += to_string(cur);
        } else {
            if(cur == 1) {
                s += ".";
                s += to_string(cur);
            } else if(cur == prev + 1) {
                while(s.size() && s.back() != '.')
                    s.pop_back();

                s += to_string(cur);
            } else {
                int cnt = 0;
                while(s.size() && cnt != 2) {
                    if(s.back() == '.') cnt++;
                    s.pop_back();
                }
                
                if(s.size()) s += ".";
                s += to_string(cur);
            }
        }
        prev = cur;
        cout<<s<<endl;
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