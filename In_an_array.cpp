#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k, x, y; cin>>n>>k>>x>>y;
    vector<int> freq(1005);
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        freq[x]++;
    }
    int ans = 0;
    for(int i = 1; i <= 1000; i++) {
        if(freq[i]) {
            for(int j = i; j <= 1000; j++) {
                if(freq[j]) {
                    if((i + j) % k == x && (i * j) % k == y) {
                        ans += i == j ? (freq[i] * (freq[i] - 1) / 2) : freq[i] * freq[j];
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 