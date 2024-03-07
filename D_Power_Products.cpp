#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
int n, k, ans = 0; 
map<map<int,int>, int> mp;

void getFactors(int n) {
    
    map<int, int> cnt;
    int i = 2;
    while(i * i <= n) {
        if(n % i == 0) {
            while(n % i == 0) {
                n /= i;
                cnt[i]++;
            }
            cnt[i] %= k;
        }
        i++;
    }
    if(n > 1) cnt[n]++, cnt[n] %= k;
    map<int, int> ache, lagbe;
    for(auto it : cnt) {
        if(it.second != 0) {
            ache[it.first] = it.second;
            lagbe[it.first] = k - it.second;
        }
    }
    ans += mp[lagbe];
    mp[ache]++;
}

void solve() {
    cin>>n>>k;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        getFactors(x);
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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