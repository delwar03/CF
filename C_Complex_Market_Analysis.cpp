#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;
vector<int> siv(N, 1);

void solve() {
    int n, e; cin>>n>>e;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(siv[v[i]]) {
            int l = 1, r = 1;
            for(int j = i + e; j < n; j += e) {
                if(v[j] == 1) r++;
                else break;
            }
            for(int j = i - e; j >= 0; j -= e) {
                if(v[j] == 1) l++;
                else break;
            }
            // cout<<l<<" "<<r<<endl;
            ans += l * r - 1;
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    siv[0] = siv[1] = 0;
    for(int i = 2; i * i < N; i++) {
        if(siv[i]) {
            for(int j = i * i; j < N; j += i) {
                siv[j] = 0;
            }
        }
    }
    // int cnt = 0;
    // for(int i = 0; i <= 100; i++) {
    //     if(siv[i]) {cout<<i<<endl; cnt++;}
    // }
    // cout<<"cnt: "<<cnt<<endl;

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