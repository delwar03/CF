#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, a, b, k; cin>>n>>a>>b>>k;
    string s; cin>>s;
    int cnt = 0, possibleShips = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            cnt++;
        } else {
            cnt = 0;
        }
        if(cnt == b) {
            possibleShips++;
            cnt = 0;
        }
    }

    int shoots = possibleShips - a + 1;

    cout<<shoots<<endl;

    cnt = 0;
     
    for(int i = 0; i < n && shoots; i++) {
        if(s[i] == '0') {
            cnt++;
        } else {
            cnt = 0;
        }
        if(cnt == b) {
            cout<<i + 1<<" ";
            shoots--;
            cnt = 0;
        }
    }
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 
