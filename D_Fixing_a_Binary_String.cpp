#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    string s; cin>>s;
    vector<int> cnt(n);
    int ct = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1]) {
            ct++;
        } else {
            int j = i - 1;
            while(j >= 0 && cnt[j] == 0) {
                cnt[j--] = ct;
            }
            ct = 1;
        }
    }
    int j = n - 1;
    while(j >= 0 && cnt[j] == 0) {
        cnt[j--] = ct;
    }
    
    // for(auto it :cnt) cerr<<it<<" "; cerr<<endl;

    int f = 0, p = -1;
    vector<int> pos;
    for(int i = n - 1; i >= 0; i--) {
        if(cnt[i] >= k) {
            int now = cnt[i];
            while(i >= 0 && cnt[i] == now) i--;
            while(i >= 0 && cnt[i] == k) i--;
            p = i + 1;
            if(p == 0) p = n;
            pos.push_back(p);
            if(p - k > 0) pos.push_back(p - k);
            break;
        }
    }

    auto generateString = [&] (int p) {
        string str = "";
        for(int i = p; i < n; i++) str += s[i];
        for(int i = p - 1; i >= 0; i--) str += s[i];

        // cerr<<str<<endl;

        cnt.assign(n, 0);
        ct = 1;
        for(int i = 1; i < n; i++) {
            if(str[i] == str[i - 1]) {
                ct++;
            } else {
                int j = i - 1;
                while(j >= 0 && cnt[j] == 0) {
                    cnt[j--] = ct;
                }
                ct = 1;
            }
        }
        j = n - 1;
        while(j >= 0 && cnt[j] == 0) {
            cnt[j--] = ct;
        }

        // for(auto it : cnt) cerr<<it<<" "; cerr<<endl;

        for(auto it : cnt) {
            if(it != k) {
                return false;
            }
        }
        return true;
    };

    // cerr<<"p: "<<p<<endl;
    
    if(p == -1) {
        cout<<-1<<endl;
    } else {

        // for(auto it : pos) cerr<<it<<" "; cerr<<endl;

        for(auto it : pos) {
            if(generateString(it)) {
                cout<<it<<endl;
                return;
            }
        }
        cout<<-1<<endl;
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