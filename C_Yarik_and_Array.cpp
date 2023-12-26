#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

int maxSubArraySum(vector<int> v) {
    int ans = -INF, sum = 0;
    for(auto it : v) {
        sum = sum > 0 ? sum : 0;
        sum += it;
        ans = sum > ans ? sum : ans;
    }
    return ans;
}

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) {cin>>x;}
    vector<int> part = {0};
    for(int i = 0; i < n - 1; i++) {
        if((v[i] + v[i + 1]) % 2 == 0) part.push_back(i + 1);
    }
    part.push_back(n);
    int ans = -INF, l = part.size();
    for(int i = 0; i < l - 1; i++) {
        ans = max(ans, maxSubArraySum(vector<int>(v.begin() + part[i], v.begin() + part[i + 1])));
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