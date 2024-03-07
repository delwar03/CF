#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

bool isSorted(vector<int> v) {
    for(int i = 1; i < v.size(); i++) {
        if(v[i] < v[i - 1]) return false;
    }
    return true;
}

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int mn = INF, id = -1;
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        if(v[i] < mn) {
            mn = v[i];
            id = i;
        }
    }
    if(id == 0) {
        if(isSorted(v)) {
            cout<<"0"<<endl;
        } else {
            cout<<"-1"<<endl;
        }
    } else {
        vector<int> tmp(n);
        int j = 0;
        for(int i = id; i < n; i++) {
            tmp[j++] = v[i];
        }
        for(int i = 0; i < id; i++) {
            tmp[j++] = v[i];
        }
        if(isSorted(tmp)) cout<<2 + id<<endl;
        else cout<<"-1"<<endl;
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