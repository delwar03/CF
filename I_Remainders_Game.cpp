#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int INF = 1e15 + 10;
const int N = 1000010;

int prime[N], cnt[N];

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    auto LCM = [&] (int a, int b) {
        return a * b / __gcd(a, b);
    };
    int l = 1;
    for(auto &x : v) {
        cin>>x;
        l = __gcd(k, LCM(l, x));
    }
    cout<<(l == k ? "Yes" : "No")<<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 1; i < N; i++) prime[i] = i;

    for(int i = 2; i * i < N; i++) {
        if(prime[i] == i) {
            for(int j = i; j < N; j += i) {
                prime[j] = i;
            }
        }
    }

    // for(int i = 0; i <= 100; i++) cerr<<prime[i]<<" ";

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