#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    string s; cin>>s;

    auto f = [&] (char ch) {
        if(ch == ')') return '(';
        if(ch == '}') return '{';
        if(ch == ']') return '[';
        else assert(false);
    };

    stack<char> stk;
    for(auto ch : s) {
        if(ch == '(' || ch == '{' || ch == '[') {
            stk.push(ch);
        } else if(sz(stk) && stk.top() == f(ch)) {
            stk.pop();
        } else {
            cout<<"NO"<<endl; return;
        }
    }
    cout<<(sz(stk) ? "NO" : "YES")<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}