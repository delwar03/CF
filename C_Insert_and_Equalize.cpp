#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
map<int, int> mp;

bool isPossible(int x) {
    auto cnt = mp;
    int i = 0;
    while(x) {
        if(x & 1) {
            if(cnt.find(i) == cnt.end() || cnt[i] == 0) return false;
            cnt[i]--; 
        }
        cnt[i + 1] += cnt[i] / 2;
        if(cnt[i] == 0) cnt.erase(i);
        x /= 2;
        i++;
    }
    return true;
}

void solve() {
    int n; cin>>n;
    int g = 0;
    vector<int> v(n);
    for(auto &x : v) {
        cin>>x;
        g = __gcd(g, x);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    g = 0;
    for(int i = 1; i < n; i++) {
        g = __gcd(g, v[i] - v[i - 1]);
    }
    if(g == 0) {
        cout<<1<<endl;
        return;
    }
    // cout<<"g: "<<g<<endl;
    // for(auto it : v) cout<<it<<" "; cout<<endl;
    int val = 0;
    for(int i = 1; i < n; i++) {
        if((v[i] - v[i - 1]) / g > 1) {
            val = (v.back() - (v[i] - g)) / g;
        }
    }
    ans += val;
    // if(ans == 0) ans += (v.back() + g) / g;
    int p = v.back();
    if(ans == 0) p += g;
    for(int i = 0; i < n; i++) {
        ans += (p - v[i]) / g;
    }
    cout<<ans<<endl;
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