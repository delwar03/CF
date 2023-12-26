#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;
int n, m;
string s;

bool isPossible(int i) {
    int chuto = i - 1, boro = m - i;
    for(auto ch : s) {
        if(ch == '1') {
            if(chuto == 0) return false;
            chuto--;
            chuto /= 2;
        } else {
            if(boro == 0) return false;
            boro--;
            boro /= 2;
        }
    }
    return true;
}

void solve() {
    cin>>n>>s;
    m = (1LL << n);
    vector<int> ans;
    for(int i = 1; i <= m; i++) {
        if(isPossible(i)) ans.push_back(i);
    }
    for(auto it : ans) cout<<it<<" ";
    cout<<endl;
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