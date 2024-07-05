#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int INF = 1e15 + 10;
const int N = 1000100;

int phi[N], sum[N];

void solve() {
    int n; cin>>n;
    int ans = n * sum[n];
    ans /= 2;
    ans += n;
    cout<<ans<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 1; i < N; i++) phi[i] = i;

    for(int i = 2; i < N; i++) {
        if(phi[i] == i) {
            for(int j = i; j < N; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }

    // for(int i = 1; i < 100; i++) cerr<<phi[i]<<" ";

    for(int i = 2; i < N; i++) {
        for(int j = i; j < N; j += i) {
            sum[j] += phi[i] * i;
        }
    }

    // for(int i = 1; i < 100; i++) cerr<<sum[i]<<" ";

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