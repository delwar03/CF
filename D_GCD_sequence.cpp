#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e12 + 10;

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    int prv = 0, ind = -1;

    for(int i = 0; i < n - 1; i++) {
        int g = __gcd(a[i], a[i + 1]);
        if(g < prv) {
            ind = i;
            break;
        }
        prv = g;
    }

    if(ind == -1) {
        cout<<"YES"<<endl;
        return;
    }

    auto isPossible = [&] (int ind) {
        if(ind < 0) return false;

        int val = 0;
        for(int i = 0; i < n - 1; i++) {
            int g;
            if(i + 1 == ind) {
                if(i + 2 == n) {
                    g = a[i];
                    continue;
                } else {
                    g = __gcd(a[i], a[i + 2]);
                }
            } else if(i == ind) {
                if(i - 1 < 0) {
                    g = a[i + 1];
                    continue;
                } else {
                    g = __gcd(a[i - 1], a[i + 1]);
                }
            } else {
                g = __gcd(a[i], a[i + 1]);
            }
            if(g < val) return false;
            val = g;
        }
        return true;
    };


    bool hobe = false;
    hobe |= isPossible(ind - 1);
    hobe |= isPossible(ind);
    hobe |= isPossible(ind + 1);
    

    cout<<(hobe ? "YES" : "NO")<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/