#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;
int n, l, r;
vector<int> v;

int UB(int x) {
    int l = 0, r = n, ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1LL;
        if(v[mid] >= x) {ans = mid; r = mid - 1;}
        else l = mid + 1;
    }
    return ans;
}

int LB(int x) {
    // if(x < v[0]) return 0;
    int l = 0, r = n, ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1LL;
        if(v[mid] <= x) {ans = mid; l = mid + 1;}
        else r = mid - 1;
    }
    return ans;
}


void solve() {
    cin>>n>>l>>r;
    v.resize(n);
    for(auto &x : v) cin>>x;
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += upper_bound(v.begin() + 1 + i , v.end(), r - v[i]) - lower_bound(v.begin() + 1 + i, v.end(), l - v[i]);
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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