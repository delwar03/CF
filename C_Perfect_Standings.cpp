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

struct Node {
    int score; string name;
    bool operator < (const Node him) const {
        if(score != him.score) return score < him.score;
        return name > him.name;
    }
};

void solve() {
    int val[5];
    for(int i = 0; i < 5; i++) cin>>val[i];

    priority_queue<Node> pq;
    for(int i = 1; i < (1LL << 5); i++) {
        int sm = 0; string tmp;
        for(int j = 0; j < 5; j++) if(i >> j & 1) {
            tmp += ('A' + j);
            sm += val[j];
        }
        pq.push({sm, tmp});
    }

    while(sz(pq)) {
        // cerr<<pq.top().name<<" -> "<<pq.top().score<<endl;
        cout<<pq.top().name<<endl; pq.pop();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}