#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int INF = 1e15 + 10;
const int N = 15000010;
int prime[N];
int cnt[N];

void solve() {
    int n; cin>>n;
    int g = 0;
    vector<int> v(n);
    for(auto &x : v) {
        cin>>x;
        g = __gcd(g, x);
    }
    int mx = -1;
    for(auto &x : v) {x /= g; mx = x > mx ? x : mx; }

    for(auto x : v) {
        while(x > 1) {
            int di = prime[x];
            cnt[di]++;
            while(x % di == 0)
                x /= di;
        }
    }
    int maxi = -1;
    for(int i = 1; i <= mx; i++) {
        if(cnt[i]) {
            maxi = cnt[i] > maxi ? cnt[i] : maxi; 
        }
    }
    if(maxi == -1) {
        cout<<-1<<endl;
    } else {
        cout<<n - maxi<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 1; i < N; i++) {
        prime[i] = i;
    }

    for(int i = 2; i * i < N; i++) {
        if(prime[i] == i) {
            for(int j = i; j < N; j += i) {
                prime[j] = i;
            }
        }
    }

    // for(int i = 1; i < 100; i++) {
    //     cerr<<prime[i]<<" ";
    // }

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 