#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        int tmp = x;
        if(v.size() && v.back() == tmp) {
            while(v.size() && v.back() == tmp) {
                v.pop_back();
                tmp++;
            }
            v.push_back(tmp);
        } else {
            v.push_back(x);
        }
    }
    cout<<(int) v.size()<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 
