#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;
vector<int> freq(N, 0);

void solve() {
    int n; cin>>n;
    string s; cin>>s;

    string color = "RGB";
    vector<int> now(3);
    for(int i = 0; i < 3; i++) now[i] = i;

    int ans = INF;
    string optimal;
    
    do {
        string tmp;
        for(int i = 0; i < n; i++) {
            tmp.push_back(color[now[i % 3]]);
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] != tmp[i]) {
                cnt++;
            }
        }

        if(cnt < ans) {
            ans = cnt;
            optimal = tmp;
        }
    } while(next_permutation(now.begin(), now.end()));

    cout<<ans<<endl;
    cout<<optimal<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 
