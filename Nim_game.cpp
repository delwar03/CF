#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define f first
#define s second
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    int m = n + 1;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i <= 100; i++) {
        cout<<(i ^ (i + 1) ^ (i + 2) ^ (i + 3))<<endl;
    }

    int x = 0;
    for(int i = 1; i <= 100; i++) {
        x ^= i;
        cerr<<i % 4<<" -> "<<x<<" ";
        switch(i % 4) {
            case 0:
                cerr<<i<<endl;
                break;
            case 1:
                cerr<<1<<endl;
                break;
            case 2:
                cerr<<i + 1<<endl;
                break;
            case 3:
                cerr<<0<<endl;
                break;
        }
    }

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