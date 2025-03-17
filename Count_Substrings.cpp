#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, k, q; cin>>n>>k>>q;
    string s; cin>>s;

    vector<int> mxL(n + 1), mxR(n + 1), pf(n + 1);
    int cnt[2] = {};
    int j = 0;

    for(int i = 0; i < n; i++) {
        while(j < n && cnt[s[j] - '0'] + 1 <= k) cnt[s[j++] - '0']++;
        mxL[i] = j - 1;
        pf[i + 1] = pf[i] + mxL[i];
        cnt[s[i] - '0']--;
    }

    j = n - 1;
    for(int i = n - 1; i >= 0; i--) {
        while(j >= 0 && cnt[s[j] - '0'] + 1 <= k) cnt[s[j--] - '0']++;
        mxR[i] = j + 1;
        cnt[s[i] - '0']--;
    }

    for(int i = 0; i < n; i++) cerr<<mxL[i]<<" \n"[i == n - 1];

    auto query = [&] (int l, int r) {
        int mxInd = mxR[r] - 1;
        cerr<<"mxInd: "<<mxInd<<endl;

        int ans = 0;

        if(l <= mxInd) {
            ans += pf[mxInd + 1] - pf[l];
            ans += (r - mxInd) * r;
            
        } else {

        }

        return ans;
    };

    while(q--) {
        int l, r; cin>>l>>r;
        --l; --r;
        cout<<query(l, r)<<endl;
    }
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