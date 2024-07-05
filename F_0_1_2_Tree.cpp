#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int a, b, c; cin>>a>>b>>c;
    if(a != c - 1) {
        cout<<"-1"<<endl;
        return;
    } else {
        multiset<int> ms;
        int val = b / c;
        int rem = b % c;
        for(int i = 0; i < c; i++) {
            if(i < rem) ms.insert(val + 1);
            else ms.insert(val);
        }
        while(ms.size() > 1) {
            int a = *ms.begin();
            ms.erase(ms.begin());
            int b = *ms.begin();
            ms.erase(ms.begin());
            ms.insert(b + 1);
        }
        cout<<(*ms.begin())<<endl;
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