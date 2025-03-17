#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;

class SGTree {

public:
    vector<int> seg;
    
    SGTree(int n) {
        seg.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, vector<int> &a) {
        if(low == high) {
            seg[ind] = a[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, a);
        build(2 * ind + 2, mid + 1, high, a);

        // When returning from funcion call update SegTree
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {

        // No Overleap
        // [low high] [l r] or [l r] [low high]
        // Should not contribute in our Answer
        if(l > high || r < low) return INT_MAX;

        // Complete Overleap
        // [l low high r]
        else if(l <= low && r >= high) return seg[ind];

        // Partial Overleap
        // Go left + Go right
        else {
            int mid = low + (high - low) / 2;
            int left = query(2 * ind + 1, low, mid, l, r);
            int right = query(2 * ind + 2, mid + 1, high, l, r);
            return min(left, right);
        }
    }

    void update(int ind, int low, int high, int i, int val) {
        if(low == high) {
            seg[ind] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        if(i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

int dp[N][11][2];

void solve() {
    int n, m, k; cin>>n>>m>>k;
    string s; cin>>s;
    s = "#" + s;

    function<int(int, int, int)> magic = [&] (int ind, int prv, int isL) {
        if(ind == n) return (int) (s[ind] == 'W');
        if(ind > n) return 0LL;

        int &ans = dp[ind][prv][isL];
        if(~ans) return ans;

        ans = INF;

        if(isL) {
            for(int i = 1; i <= m && ind + i <= n + 1; i++) {
                // cerr<<ind + i<<" "<<s[ind + i]<<endl;

                if(s[ind + i] == 'L') {
                    ans = min(ans, magic(ind + i, i, 1));
                } else if(s[ind + i] == 'W') {
                    ans = min(ans, magic(ind + i, i, 0));
                }
            }
        } else {
            ans = min(ans, 1 + magic(ind + 1, 1, s[ind + 1] == 'L'));
        }

        return ans;
    };

    memset(dp, -1, sizeof dp);
    int cnt = 0;
    cnt = magic(1, 0, s[1] == 'L');

    cerr<<"cnt: "<<cnt<<endl;

    cout<<(cnt <= k ? "YES" : "NO")<<endl;
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