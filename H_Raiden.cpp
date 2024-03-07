#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
	int n, m; cin>>n>>m;
    vector<int> s(m), c(m);
    for(int i = 0; i < m; i++) {
        cin>>s[i]>>c[i];
    }

    for(int i = 0; i <= 10000; i++) {
        string x = to_string(i);
        if(x.size() == n) {
            bool hobe = true;
            for(int j = 0; j < m; j++) {
                if(x[s[j] - 1] != c[j] + '0') {
                    hobe = false;
                    break;
                }
            }
            if(hobe) {
                cout<<i<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 