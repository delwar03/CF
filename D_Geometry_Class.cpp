#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
double PI = acos(-1.0);
double eps = 1e-5;

void solve() {
    double sine[3]; cin>>sine[0]>>sine[1]>>sine[2];
    double mx = 0, sm = 0;
    for(int i = 0; i < 3; i++) {
        sine[i] = round(asin(sine[i]) * 180.0 / PI);
        mx = max(mx, sine[i]);
        sm += sine[i];
    }
    if(sm == 180) {
        cout<<mx<<endl;
    } else {
        cout<<180 - mx<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 