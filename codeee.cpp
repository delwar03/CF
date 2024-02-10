#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int f(int b, vector<int> v) {
    int n = v.size();
    int res = 0;
    for(int i = 0; i < n; i++) {
        res += abs(v[i] - (b + i + 1));
    }
    return res;
}

void solve() {
    int n; cin>>n;
    vector<int> v;
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        v.push_back(x);
    }
    int l = 0, r = 1e15;
    int ans = INF, res = INF;
    while(l < r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int val1 = f(m1, v);
        int val2 = f(m2, v);
        if(val1 > val2) {
            l = m1 + 1;
        } else if(val2 > val1) {
            r = m2 - 1;
        } else {
            l = m1 + 1;
            r = m2 - 1;
        }
    }

    // int ans = 0;
    // for(auto it : v) {ans += it; cout<<it<<" ";}
    // cout<<endl;
    // ans /= n;
    // for(int i = 0; i <= 1000; i++)
    //     cout<<f(i, v)<<endl;
    cout<<f(l, v)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 