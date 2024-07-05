#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;

vector<int> d(N, 1);

void solve() {
    int a, b, c; cin>>a>>b>>c;
    int ans = 0;
    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            for(int k = 1; k <= c; k++) {
                ans += d[i * j * k];
            }
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 2; i < N; i++) {
        for(int j = i; j < N; j += i) {
            d[j]++;
        }
    }

    // for(int i = 0; i < 100; i++) {
    //     cerr<<d[i]<<" \n"[i == 99];
    // }

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
    1 -> 1
    2 -> 2
    4 -> 4
    5 -> 2
o/p: 
*/ 
