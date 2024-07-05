#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e6 + 10;
const int INF = 1e15 + 10;

int prime[N];
vector<int> primes;

void solve() {
    int k; cin>>k;
    int ans = 0;
    if(prime[k] == k) {
        for(auto it : primes) {
            if(it > k) break;
            ans += it * k;
        }
    } else {
        for(auto it : primes) {
            if(it > prime[k]) break;
            ans += it * k;
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 0; i < N; i++) prime[i] = i;
    
    for(int i = 2; i * i < N; i++) {
        if(prime[i] == i) {
            for(int j = 2 * i; j < N; j += i) {
                if(prime[j] == j) {
                    prime[j] = i;
                }
            }
        }
    }
    // for(int i = 2; i <= 100; i++) cerr<<i<<" -> "<<prime[i]<<endl;
    
    for(int i = 2; i < N; i++) {
        if(prime[i] == i) {
            primes.push_back(i);
        }
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