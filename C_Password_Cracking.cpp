#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define int long long
// #define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;

    auto qur = [&] (string t) {
        cout<<"? "<<t<<endl;
        int x; cin>>x;
        return x;
    };
    int f = 0;
    string s = "";
    
    while(1) {
        if(!f) {
            s = s + "0";
        } else {
            s = "0" + s;
        }
        int x = qur(s);
        if(x) {
            //
        } else {
            if(f) {
                s[0] = '1';
                x = 1;
            } else {
                s.pop_back();
                s += "1";
                int x = qur(s);
                if(x) {
                    //
                } else {
                    s.pop_back();
                    f = 1;
                }
            }
        }
        if((int) s.size() == n) {
            cout<<"! "<<s<<endl;
            break;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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