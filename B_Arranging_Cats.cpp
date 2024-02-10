#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 200;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    string a, b; cin>>a>>b;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            if(a[i] == '0') cnt1++;
            else cnt2++;
        }
    }
    cout<<max(cnt1, cnt2)<<endl;
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