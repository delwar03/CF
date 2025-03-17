#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    deque<int> a, b;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        a.push_back(x);
    }
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        b.push_back(x);
    }
    
    while(a.size() > 1 || b.size() > 1) {
        if(a.back() != b.back() && a.back() != b.front()) {
            cout<<"Alice"<<endl; return;
        }  else if(a.front() != b.back() && a.front() != b.front()) {
            cout<<"Alice"<<endl; return;
        } else {
            if(a.back() == b.back()) {
                a.pop_back();
                b.pop_back();
            } else if(a.back() == b.front()) {
                a.pop_back();
                b.pop_front();
            } else if(a.front() == b.front()) {
                a.pop_front();
                b.pop_front();
            } else {
                a.pop_front();
                b.pop_back();
            }
        }
    }

    cout<<(a.back() == b.back() ? "Bob" : "Alice")<<endl;
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