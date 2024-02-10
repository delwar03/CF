#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

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
    int hi = 0, lo = 0;
    for(int i = 1; i < n; i++) {
        if(v[i] > v[i - 1]) hi++;
        if(v[i] < v[i - 1]) lo++;
    }
    cout<<hi<<" "<<lo<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 