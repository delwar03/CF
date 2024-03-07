#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
map<int, int> mp;

bool isPossible(int x) {
    auto cnt = mp;
    int i = 0;
    while(x) {
        if(x & 1) {
            if(cnt.find(i) == cnt.end() || cnt[i] == 0) return false;
            cnt[i]--; 
        }
        cnt[i + 1] += cnt[i] / 2;
        if(cnt[i] == 0) cnt.erase(i);
        x /= 2;
        i++;
    }
    return true;
}

void solve() {
    int q; cin>>q;
    while(q--) {
        int type, val; cin>>type>>val;
        if(type == 1) {
            mp[val]++;
        } else {
            if(isPossible(val)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
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