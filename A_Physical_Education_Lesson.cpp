#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, x; cin>>n>>x;
    set<int> st;

    auto fact = [&] (int a) {
        for(int i = 1; i * i <= a; i++) {
            if(a % i == 0) {
                if(i % 2 == 0 && ((i + 2) / 2) >= x) st.insert((i + 2) / 2);
                int p = a / i;
                if(p % 2 == 0 && ((p + 2) / 2) >= x) st.insert((p + 2) / 2);
            }
        }
    };
    
    fact(n - x);
    fact(n + x - 2);
    cout<<(int) st.size()<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 