#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int prm = 31;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, k; cin>>n>>k;
    string s; cin>>s;
    string tmp = s;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            tmp[i] = '0';
        } else if(i > 0 && s[i - 1] == '1') {
            tmp[i] = '1';
        } else if(i < n - 1 && s[i + 1] == '1') {
            tmp[i] = '1';
        } else {
            tmp[i] = '0';
        }
    }
    swap(tmp, s);
    // cerr<<s<<endl;
    k--;
    if(k == 0) {
        cout<<s<<endl;
        return;
    }

    set<int> st;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            st.insert(i);
        }
    }

    vector<int> d(n, INF);
    for(int i = 0; i < n; i++) {
        auto it = st.lower_bound(i);
        if(it != st.end()) {
            d[i] = min(d[i], *it - i);
        }
        if(it != st.begin()) {
            d[i] = min(d[i], i - (*--it));
        }
    }

    // for(auto it : d) cerr<<it<<" "; cerr<<endl;

    for(int i = 0; i < n; i++) {
        if(k >= d[i] && (k - d[i]) % 2 == 0) {
            s[i] = '1';
        } else {
            s[i] = '0';
        }
    }
    cout<<s<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/