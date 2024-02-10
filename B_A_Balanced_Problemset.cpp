#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 200;
const int INF = 1e15 + 10;

// vector<int> factors[N];

vector<int> getFactors(int n) {
    vector<int> fact;
    fact.push_back(1);
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            fact.push_back(i);
            if(i != n / i) {
                fact.push_back(n / i);
            }
        }
    }
    fact.push_back(n);
    return fact;
}

void solve() {
    int n, k; cin>>n>>k;
    vector<int> factors = getFactors(n);
    sort(factors.begin(), factors.end());
    int p = n / k;
    auto it = upper_bound(factors.begin(), factors.end(), p);
    if(it != factors.begin()) it--;
    cout<<*it<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        // cout<<"Scenario #"<<c++<<":\n";
        solve();
    }
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 