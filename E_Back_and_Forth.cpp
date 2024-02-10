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
    int a, b, c, d; cin>>a>>b>>c>>d;
    for(int i = 0; i < d - b; i++) cout<<"U";
    for(int i = 0; i < c - a; i++) cout<<"R";
    for(int i = 0; i < d - b; i++) cout<<"D";
    for(int i = 0; i < c - a + 1; i++) cout<<"L";
    for(int i = 0; i < d - b + 1; i++) cout<<"U";
    for(int i = 0; i < c - a + 1; i++) cout<<"R";
    cout<<"DR";
    for(int i = 0; i < d - b + 1; i++) cout<<"D";
    for(int i = 0; i < c - a + 1; i++) cout<<"L";
    cout<<"U"<<endl;
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