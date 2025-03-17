#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<string, int> mp;

void solve() {
    int arr[3];
    for(int i = 0; i < 3; i++)
        cin>>arr[i];
    string s; cin>>s;
    int mn = INF;
    for(int i = 0; i < 3; i++) {
        if(i == mp[s]) continue;
        mn = min(mn, arr[i]);
    }
    cout<<mn<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    mp["Red"] = 0;
    mp["Green"] = 1;
    mp["Blue"] = 2;

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/