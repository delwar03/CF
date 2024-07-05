#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e6 + 10;
const int INF = 1e18 + 10;

int prime[N];

void solve() {
    int n, q; cin>>n>>q;
    map<int, int> mp;
    if(n == 1) mp[1] = 0;
    int tmp = n;
    while(tmp > 1) {
        int d = prime[tmp];
        while(tmp % d == 0) {
            tmp /= d;
            mp[d]++;
        }
    }
    auto now = mp;
    // for(auto it : now) cerr<<it.first<<" -> "<<it.second<<endl; cerr<<endl;

    auto multiply = [&] (int x, map<int, int>& mp) {
        while(x > 1) {
            int d = prime[x];
            while(x % d == 0) {
                x /= d;
                mp[d]++;
            }
        }
    };

    auto isDivisible = [&] {
        map<int, int> fact;
        for(auto it : now) {
            multiply(it.second + 1, fact);
        }
        for(auto it : fact) {
            if(now.count(it.first) && now[it.first] >= it.second) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    };

    while(q--) {
        int k; cin>>k;
        if(k == 1) {
            int x; cin>>x;
            multiply(x, now);
            cout<<(isDivisible() ? "YES" : "NO")<<endl;
        } else {
            now = mp;
        }
    }
    cout<<endl;
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