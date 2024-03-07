#include <bits/stdc++.h>
#define int long long
// #define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;
string res;

void query(int a, int b, int c, int d) {
    cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    cin>>res;
}

void solve() {
    int n; cin>>n;
    
    int p = 0;
    for(int i = 1; i < n; i++) {
        query(p, p, i, i);
        if(res == "<") {
            p = i; // storing maximum
        }
    }
    int mx = 0;
    for(int i = 1; i < n; i++) {
        query(p, mx, p, i);
        if(res == "<") {
            mx = i;
        } else if(res == "=") {
            query(mx, mx, i, i);
            if(res == ">") {
                mx = i;
            }
        }
    }
    cout<<"! "<<mx<<" "<<p<<endl;
    // cout.flush();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 