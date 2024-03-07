#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;

void solve() {
    int n; cin>>n;
    set<string> st;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            for(int k = 0; k < 26; k++) {
                if(i + j + k != n - 3) continue;
                string str = "";
                str += i + 'a';
                str += j + 'a';
                str += k + 'a';
                st.insert(str);
            }
        }
    }
    cout<<(*st.begin())<<endl;
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