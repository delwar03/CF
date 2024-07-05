#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, k; cin>>n>>k;
    int mx_k = (n * n) / 2;
    if((k & 1) || k > mx_k) {
        cout<<"No"<<endl;
    } else {
        cout<<"Yes"<<endl;
        vector<int> ans(n + 1);
        for(int i = 1; i <= n; i++) ans[i] = i;
        int cnt = 0;
        int i = 1, j = n;
        while(i <= j) {
            if(2 * (j - i) <= k) {
                swap(ans[i], ans[j]);
                k -= 2 * (j - i);
                cnt++;
                i++;
                j--;
            } else {
                i++;
            }


            if(k == 0) break;
        }
        for(int i = 1; i <= n; i++) cout<<ans[i]<<" "; cout<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; cin>>t;
    for(int c = 1; c <= t; c++) {
        // cerr<<"Case "<<c<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/