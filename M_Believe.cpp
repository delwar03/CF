#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

int binPow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

void solve() {
    vector<int> pow(16);
    for(int i = 1; i < 16; i++) {
        pow[i] = binPow(i, i);
    }
    int x; cin>>x;
    for(int i = 1; i < 16; i++) {
        if(pow[i] == x) {
            cout<<i<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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