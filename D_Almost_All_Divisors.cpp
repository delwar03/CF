#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;

vector<int> getFactors(int n) {
    vector<int> res;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(n / i != i) {
                res.push_back(n / i);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    int mn = *min_element(v.begin(), v.end());
    int mx = *max_element(v.begin(), v.end());

    int num = mn * mx;

    for(auto it : v) {
        if(num % it != 0) {
            cout<<"-1"<<endl;
            return;
        }
    }
    auto fact = getFactors(num);
    // for(auto it : fact) cerr<<it<<" "; cerr<<endl;

    if(fact.size() - 2 == n) {
        cout<<num<<endl;
    } else {
        cout<<"-1"<<endl;
    }
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
