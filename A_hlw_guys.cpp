#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
int n, k, sum = 0;
vector<int> v;

int f(int i, int j, int s, int cnt) {
    if(cnt == k) return s;
    int x = f(i + 2, j, s - v[i] - v[i + 1], cnt + 1);
    int y = f(i, j - 1, s - v[j], cnt + 1);
    return max(x, y);
}

void solve() {
    cin>>n>>k;
    v.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        cin>>v[i];
    }
    sort(v.begin() + 1, v.end());
    for(int i = 1; i <= n; i++) v[i] += v[i - 1];
    int ans = 0;
    for(int i = 0; i <= k; i++) {
        ans = max(ans, v[n - k + i] - v[2 * i]);
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