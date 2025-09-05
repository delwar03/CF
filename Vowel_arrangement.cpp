#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) (x.size())

const int N = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 1e18 + 10;

int n;
string s;
int dp[N][35][10];

int mp(char ch) {
    if(ch == 'a') return 0;
    if(ch == 'e') return 1;
    if(ch == 'i') return 2;
    if(ch == 'o') return 3;
    if(ch == 'u') return 4;
    else assert(false);
}

int magic(int ind, int mask, int prv) {
    if(ind == n) return 0;

    int &ans = dp[ind][mask][prv];
    if(~ans) return ans;
    ans = INF;

    for(int i = 0; i < 5; i++) {
        if(mask >> i & 1) continue;
        int op = i - mp(s[ind]);
        if(op < 0) op += 5;
        ans = min(ans, op + magic(ind + 1, mask | (1LL << i), i));
    }

    if(prv != 5) {
        int op = prv - mp(s[ind]);
        if(op < 0) op += 5;
        ans = min(ans, op + magic(ind + 1, mask, prv));
    }

    return ans;
}

void solve() {
    cin >> n >> s;
    for(int i = 0; i < n; i++) for(int j = 0; j < 32; j++) for(int k = 0; k < 6; k++) dp[i][j][k] = -1;
    cout<<magic(0, 0, 5)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; 
    cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cout<<"Case "<<tc<<":";
        solve();
    }
}