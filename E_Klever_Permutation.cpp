#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    int a = 1, b = n;
    for(int j = 0; j < k; j++) {
        for(int i = 0; i < n  / k + 1; i++) {
            if(i * k + j < n) {
                if(j % 2 == 0) v[i * k + j] = a++;
                else v[i * k + j] = b--;
            }
        }
    }
    for(auto it : v) cout<<it<<" "; cout<<endl;
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