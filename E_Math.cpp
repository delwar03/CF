#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int INF = 1e15 + 10;
const int N = 3e5 + 10;

map<int, int> mp;
set<int> powerOfTwo;

void primeFactors(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                mp[i]++;
                n /= i;
            }
        }
    }
    if(n > 1) mp[n]++;
}

void solve() {
    int n; cin>>n;
    primeFactors(n);
    int ans = 1, cnt = 0;
    // for(auto it : mp) cerr<<it.first<<" -> "<<it.second<<endl;
    int mx = -1, mn = INF;
    for(auto it : mp) {
        ans *= it.first;
        mx = max(mx, it.second);
        mn = min(mn, it.second);
    }
    if(mx == 1 || mx == -1) {
        ans = n;
        cnt = 0;
    } else if(mx == mn) {
        int p = 0, ind = 1;
        while(ind < mx) {
            ind *= 2;
            p++;
        }
        if(powerOfTwo.count(mx)) {
            cnt = p;
        } else {
            cnt = p + 1;
        }
    } else {
        int p = 0, ind = 1;
        while(ind < mx) {
            ind *= 2;
            p++;
        }
        cnt = p + 1;
    }
    cout<<ans<<" "<<cnt<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 1; i <= 32; i++) {
        powerOfTwo.insert(1LL << i);
    }

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