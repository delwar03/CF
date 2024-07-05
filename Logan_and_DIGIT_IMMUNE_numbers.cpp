#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int dp[20][315][16][2][2]; // (ind, rem with lcm[3, 5, 7, 9], mask, low_tight, high_tight)
int p[4] = {3, 5, 7, 9};

void solve() {
    int l, r, k; cin>>l>>r>>k;

    string a, b;

    function<int(int, int, int, int, int, int)> magic = [&] (int ind, int sum, int mask, int low_tight, int high_tight, int started) {
        if(ind == 18) {
            for(int i = 0; i < 4; i++) {
                if(((mask >> i) & 1) && sum % p[i] == 0) {
                    return 0LL;
                }
            }
            return 1LL;
        }

        int &ans = dp[ind][sum][mask][low_tight][high_tight];
        if(~ans) return ans;

        ans = 0;
        int lo = low_tight ? a[ind] - '0' : 0;
        int hi = high_tight ? b[ind] - '0' : 9;

        for(int i = lo; i <= hi; i++) {
            if(i == 0 && !started) {
                ans += magic(ind + 1, sum, mask, low_tight & (i == lo), high_tight & (i == hi), 0);
            } else if(i != 1 && (i & 1)) {
                ans += magic(ind + 1, (10 * sum + i) % 315, mask | (1LL << ((i / 2) - 1)), low_tight & (i == lo), high_tight & (i == hi), 1);
            }
        }
        return ans;
    };

    a = to_string(l);
    reverse(a.begin(), a.end());
    while(a.size() < 18) a += "0";
    reverse(a.begin(), a.end());

    int lo = l, hi = r, ans = -1;

    while(lo <= hi) {
        int mid = (lo + hi) / 2;

        b = to_string(mid);
        reverse(b.begin(), b.end());
        while(b.size() < 18) b += "0";
        reverse(b.begin(), b.end());


        memset(dp, -1, sizeof dp);
        int cur = magic(0, 0, 0, 1, 1, 0);
        // cerr<<cur<<endl;

        if(cur >= k) { // (ind, sum, mask, low_tight, high_tight, started)
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout<<ans<<endl;
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