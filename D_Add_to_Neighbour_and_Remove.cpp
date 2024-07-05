#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

vector<int> getFactors(int n) {
    vector<int> res;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(i ^ (n / i)) {
                res.push_back(n / i);
            }
        }
    }
    return res;
}

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int sum = 0;
    for(auto &x : v) {
        cin>>x;
        sum += x;
    }
    auto fact = getFactors(sum);

    int ans = n - 1;
    for(auto it : fact) {
        int cnt = 0, sm = v[0];
        for(int i = 1; i < n; i++) {
            if(sm + v[i] > it && sm != it) {
                cnt = INF;
                break;
            } else if(sm + v[i] > it) {
                sm = v[i];
            } else {
                sm += v[i];
                cnt++;
            }
        }
        if(sm != it) cnt = INF;
        ans = min(ans, cnt);
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