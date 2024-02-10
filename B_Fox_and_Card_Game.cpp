#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

vector<int> getFactors(int n) {
    vector<int> v;
    v.push_back(1);
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            v.push_back(i);
            if(i != n / i) v.push_back(n / i);
        }
    }
    if(n != 1) v.push_back(n);
    return v;
}

void solve() {
    int n; cin>>n;
    int a = 0, b = 0;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int m; cin>>m;
        for(int j = 0; j < m; j++) {
            int x; cin>>x;
            if(j < m / 2) a += x;
            else if(j >= (m + 1) / 2) b += x;
            else v.push_back(x);
        }
    }
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < v.size(); i++) {
        if(i % 2 == 0) a += v[i];
        else b += v[i];
    }
    cout<<a<<" "<<b<<endl;
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