#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
int mn = INF, sum = 0;

void solve() {

    string a, b; cin>>a>>b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string ans = "";
    int i = 0, j = 0;
    b += "0";
    while(i < a.size() && j < b.size() - 1) {
        if(b[j] >= a[i]) {
            ans += b[j] - a[i] + '0';
            i++;
            j++;
        } else {
            int x = (b[j] - '0') + (b[j + 1] - '0') * 10;
            x -= (a[i] - '0');
            if(x > 9 || x < 0) {
                cout<<"-1\n";
                return;
            }
            ans += x + '0';
            i++;
            j += 2;
        }
    }
    if(i < a.size()) cout<<"-1\n";
    else {
        while(j < b.size() - 1) ans += b[j++];
        int k = ans.size() - 1;
        while(ans[k] == '0') {
            ans.pop_back();
            k--;
        }
        reverse(ans.begin(), ans.end());
        cout<<ans<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 