#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int sum = 0;
    int mx = -INF, mn = INF;
    for(auto &x : v) {
        cin>>x;
        sum += x;
        mx = x > mx ? x : mx;
        mn = x < mn ? x : mn;
    }

    if(mx - mn < 2) {
        cout<<n<<endl;
        for(auto it : v) cout<<it<<" "; cout<<endl;
    } else {
        int a = count(v.begin(), v.end(), mn);
        int b = count(v.begin(), v.end(), mn + 1);
        int c = count(v.begin(), v.end(), mn + 2);

        vector<int> ans;
        int p = min(a, c);
        int q = b / 2;
        int match = n;

        if(p > q) {
            a -= p; c -= p; b += 2 * p;
            match -= 2 * p;
        } else {
            a += q; c += q; b -= 2 * q;
            match -= 2 * q;
        }

        for(int i = 0; i < a; i++) ans.push_back(mn);
        for(int i = 0; i < b; i++) ans.push_back(mn + 1);
        for(int i = 0; i < c; i++) ans.push_back(mn + 2);

        cout<<match<<endl;
        for(auto it : ans) cout<<it<<" "; cout<<endl;
    }


}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; //cin>>t;
    for(int c = 1; c <= t; c++) {
        // cerr<<"Case "<<c<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/