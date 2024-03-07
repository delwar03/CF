#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

vector<int> getFactors(int n) {
    vector<int> res;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            res.push_back(n / i);
        }
    }
    return res;
}

int isPossible(int x, vector<int> &v) {
    int sm = v[0], ct = 0, n = v.size();
    for(int i = 1; i < n; i++) {
        if(sm + v[i] > x && sm != x) return -1;
        if(sm + v[i] > x) {
            // ct++;
            sm = v[i];
        } else {
            ct++;
            sm += v[i];
        }
    }
    return sm == x ? ct : -1;
}

void solve() {
    int n; cin>>n;
    int sum = 0;
    vector<int> v(n);
    for(auto &x : v) {
        cin>>x;
        sum += x;
    }
    vector<int> factors = getFactors(sum);

    // for(auto it : factors) cerr<<it<<" "; cerr<<endl;

    

    int ans = INF;
    for(auto it : factors) {
        int cnt = isPossible(it, v);
        // cerr<<"cnt: "<<cnt<<endl;
        if(cnt != -1) ans = min(ans, cnt);
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 