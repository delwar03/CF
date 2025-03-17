#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

void solve() {
    int n; cin>>n;
    vector<vector<int>> mat = {
        {1, 1},
        {1, 0}
    };

    auto matIden = [&] (int n) {
        vector<vector<int>> iden(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                iden[i][j] = (int) !(i ^ j);
            }
        }
        return iden;
    };

    auto matMult = [&] (vector<vector<int>> mat1, vector<vector<int>> mat2) {
        int n = mat1.size();
        vector<vector<int>> res(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    res[i][j] += (mat1[i][k] * mat2[k][j]) % mod;
                    res[i][j] %= mod;
                }
            }
        }
        return res;
    };

    auto matPow = [&] (vector<vector<int>> mat, int k) {
        auto res = matIden(2);
        while(k) {
            if(k & 1) {
                res = matMult(res, mat);
            }
            mat = matMult(mat, mat);
            k >>= 1;
        }
        return res;
    };

    auto ans = matPow(mat, n);
    cout<<ans[0][1]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/
