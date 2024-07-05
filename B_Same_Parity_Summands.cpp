#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    if(k > n) {cout<<"NO"<<endl; return; }
    if(n == k) {cout<<"YES"<<endl; for(int i = 0; i < k; i++) cout<<1<<" \n"[i == k - 1]; return; }

    if(n & 1) {
        if(k & 1) {
            cout<<"YES"<<endl;
            for(int i = 0; i < k - 1; i++) cout<<"1 ";
            cout<<n - k + 1<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    } else {
        if(k > n / 2) {
            if(k & 1) {
                cout<<"NO"<<endl;
            } else {
                cout<<"YES"<<endl;
                for(int i = 0; i < k - 1; i++) cout<<"1 ";
                cout<<n - k + 1<<endl;
            }
        } else {
            cout<<"YES"<<endl;
            for(int i = 0; i < k - 1; i++) cout<<"2 ";
            cout<<n - 2 * (k - 1)<<endl;
        }
    }
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
