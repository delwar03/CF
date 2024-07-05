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
    vector<int> c(n);
    vector<int> freq(n + 1);
    for(auto &x : c) {cin>>x; freq[x]++; }

    sort(freq.rbegin(), freq.rend());

    int mn = INF;
    for(auto it : freq) {
        if(it) mn = it < mn ? it : mn;
    }
    mn++;

    int ans = n;
    for(int sz = 1; sz <= mn; sz++) {
        int cnt = 0;
        for(int i = 0; i <= n; i++) {
            if(!freq[i]) break;
            int box = (freq[i] + sz - 1) / sz;
            if(box * (sz - 1) <= freq[i]) {
                cnt += box;
            } else {
                cnt = INF;
                break;
            }
        }
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