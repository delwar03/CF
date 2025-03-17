#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

int dp[50][11][11][11][5];

void solve() {
    int arr[3]; cin>>arr[0]>>arr[1]>>arr[2];
    
    int sum = arr[0] + arr[1] + arr[2];

    function<int(int, int, int, int, int)> magic = [&] (int ind, int one, int two, int three, int prv) {
        if(ind == sum + 1) {
            return (int) (one == arr[0] && two == arr[1] && three == arr[2]);
        }

        int &ans = dp[ind][one][two][three][prv];
        if(~ans) return ans;

        ans = 0;

        for(int i = 1; i <= 3; i++) {
            if(i ^ prv) {
                ans += magic(ind + 1, one + (i == 1), two + (i == 2), three + (i == 3), i);
            }
        }
        return ans;
    };

    memset(dp, -1, sizeof dp);
    cout<<(magic(1, 0, 0, 0, 4) ? "YES" : "NO")<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/