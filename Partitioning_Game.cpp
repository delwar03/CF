#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int dp[N];

int g(int n) {
    if(n <= 2) return 0;
    int &ans = dp[n];
    if(~ans) return ans;

    set<int> st;
    int m = (n / 2) - (n % 2 == 0);
    for(int i = 1; i <= m; i++) {
        st.insert(g(i) ^ g(n - i));
    }
    ans = 0;
    while(st.count(ans)) ans++;
    return ans;
}

void solve() {
    int n; cin>>n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        ans ^= g(x);
    }
    cout<<(ans ? "Alice" : "Bob")<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof dp);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}

/*
i/p: 
o/p: 
*/