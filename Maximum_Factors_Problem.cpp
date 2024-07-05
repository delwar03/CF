#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int prm = 31;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    map<int, int> mp;
    auto getDivisor = [&] (int n) {
        int i = 2;
        while(i * i <= n) {
            if(n % i == 0) {
                while(n % i == 0) {
                    n /= i;
                    mp[i]++;
                }
            }
            i++;
        }
        if(n > 1)
            mp[n]++;
    };
    
    auto divCnt = [&] (int n) {
        mp[n]--;
        int res = 1;
        for(auto it : mp) {
            res *= (it.second + 1);
        }
        mp[n]++;
        return res;
    };
    getDivisor(n);
    int mx = 0;

    // for(auto it : mp) cerr<<it.first<<" -> "<<it.second<<endl; cerr<<endl;

    for(auto it : mp) {
        mx = max(mx, divCnt(it.first));
    }
    for(auto it : mp) {
        if(divCnt(it.first) == mx) {
            cout<<it.first<<endl;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/