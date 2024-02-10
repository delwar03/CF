#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;


void solve() {
    int n; cin>>n;
    multiset<int> start, end;
    for(int i = 0; i < n; i++) {
        char ch;
        int a, b; cin>>ch>>a>>b;
        if(ch == '+') {
            start.insert(a);
            end.insert(b);
        } else {
            start.erase(start.find(a));
            end.erase(end.find(b));
        }
        if(start.size() && *end.begin() < *start.rbegin()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
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