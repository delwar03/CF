#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string tmp = "aeiou";

void solve() {
    int n; cin>>n;
    int ct = (n + 5 - 1) / 5, md = (n % 5 != 0) ? n % 5 : 5, d = (5 - md) / 2;
    string st;
    // cerr<<"ct: "<<ct<<", md: "<<md<<endl;
    for(int i = 0; i < d; i++) {
        for(int j = 0; j < ct - 1; j++) {
            st += tmp[i];
            // cout<<tmp[i];
        }
    }
    for(int i = d; i < d + md; i++) {
        for(int j = 0; j < ct; j++) {
            st += tmp[i];
            // cout<<tmp[i];
        }
    }
    for(int i = d + md; i < 5; i++) {
        for(int j = 0; j < ct - 1; j++) {
            st += tmp[i];
            // cout<<tmp[i];
        }
    }
    cout<<st<<endl;
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