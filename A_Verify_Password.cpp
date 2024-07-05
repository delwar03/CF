#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    string num = "", alpha = "";
    int end = n;
    for(int i = 0; i < n; i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            num += s[i];
        } else {
            end = i;
            break;
        }
    }
    for(int i = end; i < n; i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            cout<<"NO"<<endl;
            return;
        } else {
            alpha += s[i];
        }
    }
    // cout<<num<<" "<<alpha<<endl;
    if(is_sorted(num.begin(), num.end())) {
        if(is_sorted(alpha.begin(), alpha.end())) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    } else {
        cout<<"NO"<<endl;
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