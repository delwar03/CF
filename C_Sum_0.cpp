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

struct Node {
    int l, r;
};

void solve() {
    int n; cin>>n;
    vector<Node> ranges(n);
    vector<int> v(n);
    int sm = 0, L = 0, R = 0;
    for(int i = 0; i < n; i++) {
        int l, r; cin>>l>>r;
        L += l;
        R += r;
        sm += l;
        v[i] = l;
        ranges[i] = {l, r};
    }

    if(L > 0 || R < 0) {cout<<"No"<<endl; return; }

    int ind = 0;
    while(1) {
        int dif = 0 - sm, l = ranges[ind].l, r = ranges[ind].r;
        if(r - l >= dif) {
            v[ind] += dif;
            sm += dif;
            break;
        } else {
            v[ind] += (r - l);
            sm += (r - l);
        }
        ind++;
    }

    cout<<"Yes"<<endl;
    for(int i = 0; i < n; i++) cout<<v[i]<<" ";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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