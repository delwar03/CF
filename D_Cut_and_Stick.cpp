#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
const int BLK = 555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int l, r, idx;
};

int freq[N], invFreq[N];
int mx = 0;

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<Node> que(q);

    for(int i = 0; i < q; i++) {
        cin>>que[i].l>>que[i].r;
        que[i].l--; que[i].r--;
        que[i].idx = i;
    }

    sort(que.begin(), que.end(), [] (Node a, Node b) {
        if(a.l / BLK != b.l / BLK) return a.l / BLK < b.l / BLK;
        return a.r < b.r;
    });

    auto add = [&] (int x) {
        invFreq[freq[x]]--;
        freq[x]++;
        invFreq[freq[x]]++;
        mx = max(mx, freq[x]);
    };

    auto del = [&] (int x) {
        invFreq[freq[x]]--;
        freq[x]--;
        invFreq[freq[x]]++;
        if(freq[x] < mx) {
            while(invFreq[mx] == 0) mx--;
        }
    };

    vector<int> ans(q);
    int lb = 0, rb = -1;

    for(int i = 0; i < q; i++) {
        int l = que[i].l, r = que[i].r, idx = que[i].idx;

        while(rb < r) add(v[++rb]);
        while(lb > l) add(v[--lb]);

        while(rb > r) del(v[rb--]);
        while(lb < l) del(v[lb++]);

        ans[idx] = (mx <= (r - l + 1 + 1) / 2 ? 1 : 2 * mx - (r - l + 1));
    }

    for(int i = 0; i < q; i++) cout<<ans[i]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/