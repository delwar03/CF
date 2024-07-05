#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;
vector<int> freq(N, 0);

void solve() {
    int n, m, k; cin>>n>>m>>k;
    if(n % 2 == 0 && m % 2 == 0) {
        cout<<(k % 2 == 0 ? "YES" : "NO")<<endl;
    } else if(n % 2 == 0) {
        int maxHori = m * n / 2 - n / 2;
        cout<<(k % 2 == 0 && k <= maxHori ? "YES" : "NO")<<endl;
    } else {
        int firstRow = m / 2;
        k -= firstRow;
        cout<<(k >= 0 && k % 2 == 0 ? "YES" : "NO")<<endl;
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
