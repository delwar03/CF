#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
vector<int> inv(N);

int binPow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, k; cin>>n>>k;
    if(n & 1) {
        cout<<1<<" "<<n / 2<<" "<<n / 2<<endl;
    } else {
        if(n % 4 == 0)
            cout<<n / 4<<" "<<n / 4<<" "<<n / 2<<endl;
        else 
            cout<<2<<" "<<(n - 2) / 2<<" "<<(n - 2) / 2<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    inv[1] = 1;
    for(int i = 2; i < N; i++) {
        inv[i] = M - (M / i) * inv[M % i] % M;
    }

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