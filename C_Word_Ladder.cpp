#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    string a, b; cin>>a>>b;
    int n = a.size();
    vector<string> ans;
    for(int i = 0; i < n; i++) {
        int f = 1;
        for(int j = 0; j < n; j++) {
            if(a[j] != b[j]) {
                if(a[j] > b[j]) {
                    a[j] = b[j];
                    ans.push_back(a);
                    f = 0;
                    break;
                }
            }
        }
        if(!f) continue;

        for(int j = n - 1; j >= 0; j--) {
            if(a[j] != b[j]) {
                if(a[j] < b[j]) {
                    a[j] = b[j];
                    ans.push_back(a);
                    f = 0;
                    break;
                }
            }
        }

        if(f) break;
    }
    
    cout<<(int) ans.size()<<endl;
    for(auto it : ans) cout<<it<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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