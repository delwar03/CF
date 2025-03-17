#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n + 1), diff(n + 1), pref(n + 1);
    
    for(int i = 1; i <= n; i++) {
        cin>>v[i];
        pref[i] = pref[i - 1] + v[i];
        diff[i] = diff[i - 1] + (v[i] != v[i - 1]);
    }

    // cout<<"v: ";
    // for(int i = 1; i <= n; i++) cout<<pref[i]<<" "; cout<<endl;
    // cout<<"diff: ";
    // for(int i = 1; i <= n; i++) cout<<diff[i]<<" "; cout<<endl;

    vector<int> ans(n + 1, INF);
    for(int i = 1; i <= n; i++) {
        if(i > 1 && v[i - 1] > v[i]) ans[i] = 1;
        if(i < n && v[i + 1] > v[i]) ans[i] = 1;

        // left
        int l = 1, r = i - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int sum = pref[i - 1] - pref[mid - 1];
            bool hobe = (diff[i - 1] - diff[mid]) > 0;
            if(sum > v[i] && hobe) {
                // cout<<sum<<" "<<hobe<<endl;
                ans[i] = min(ans[i], i - mid);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        // right
        l = i + 1, r = n;
        while(l <= r) {
            int mid = (l + r) / 2;
            int sum = pref[mid] - pref[i + 1 - 1];
            bool hobe = (diff[mid] - diff[i + 1]) > 0;
            if(sum > v[i] && hobe) {
                // cout<<sum<<" "<<hobe<<endl;
                ans[i] = min(ans[i], mid - i);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }


    for(int i = 1; i <= n; i++) {
        cout<<(ans[i] == INF ? -1 : ans[i])<<" \n"[i == n];
    }
    
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