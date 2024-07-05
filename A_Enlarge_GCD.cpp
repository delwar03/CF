#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1.5e7 + 10;
const int INF = 1e15 + 10;

int prime[N], cnt[N];

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int g = 0;
    for(auto &x : v) {
        cin>>x;
        g = __gcd(g, x);
    }
    for(auto &x : v) {
        x /= g;
    }

    for(auto it : v) {
        while(it > 1) {
            int di = prime[it];
            cnt[di]++;
            while(it % di == 0) {
                it /= di;
            }
        }
    }
    int mx = -1;
    for(int i = 0; i < N; i++) {
        if(cnt[i]) {
            mx = cnt[i] > mx ? cnt[i] : mx;
        }
    }

    if(mx == -1) {
        cout<<mx<<endl;
    } else {
        cout<<n - mx<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < N; i++) prime[i] = i;

    for(int i = 2; i * i < N; i++) {
        if(prime[i] == i) {
            for(int j = 2 * i; j < N; j += i) {
                prime[j] = i;
            }
        }
    }

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