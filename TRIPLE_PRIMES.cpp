#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int prime[N];
set<int> st;

void solve() {
    int n; cin>>n;
    n -= 4;
    for(auto c : st) {
        int x_sq = n - c * c;
        if(x_sq >= 0) {
            int x = sqrt(x_sq);
            if(x * x == x_sq) {
                if(st.count(x)) {
                    set<int> p;
                    p.insert(2);
                    p.insert(c);
                    p.insert(x);
                    if(p.size() == 3) {
                        cout<<"Yes"<<endl;
                        return;
                    }
                }
            }
        }
    }
    cout<<"No"<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < N; i++) prime[i] = i;

    for(int i = 2; i * i < N; i++) {
        if(prime[i] == i) {
            for(int j = 2 * i; j < N; j += i) {
                prime[j] = i;
            }
        }
    }

    for(int i = 2; i < N; i++) {
        if(prime[i] == i) {
            st.insert(i);
        }
    }

    // cerr<<st.size()<<endl;
    // for(auto it : st) cerr<<it<<" "; cerr<<endl;

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