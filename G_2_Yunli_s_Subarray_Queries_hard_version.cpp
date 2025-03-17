#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class SGTree {

public:
    vector<pair<int, int>> seg;
    
    SGTree(int n) {
        seg.resize(4 * n + 1, {INF, INF});
    }

    void build(int ind, int low, int high, vector<int> &a) {
        if(low == high) {
            seg[ind] = {a[low], low};
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, a);
        build(2 * ind + 2, mid + 1, high, a);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    pair<int, int> query(int ind, int low, int high, int l, int r) {

        if(l > high || r < low) return {INF, INF};
        if(l <= low && r >= high) return seg[ind];

        int mid = low + (high - low) / 2;
        auto left = query(2 * ind + 1, low, mid, l, r);
        auto right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void update(int ind, int low, int high, int i, int val) {
        if(low == high) {
            seg[ind] = {val, low};
            return;
        }

        int mid = low + (high - low) / 2;
        if(i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

void solve() {
    int n, k, q; cin>>n>>k>>q;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    for(int i = 0; i < n; i++) v[i] += n - i;

    auto getRight = [&] (vector<int> cur) {
        int n = (int) cur.size();
        vector<int> res(n), tmp;

        for(int i = n - 1; i >= 0; i--) {
            while(tmp.size() && cur[tmp.back()] >= cur[i]) 
                tmp.pop_back();
            
            res[i] = tmp.size() ? tmp.back() : n;
            tmp.push_back(i);
        }

        return res;
    };

    vector<int> ans(n + 1, 0), freq(2 * n + 5);
    multiset<int> st;

    auto upd = [&] (int x, int val) {
        auto it = st.find(freq[x]);
        if(it != st.end()) {
            st.erase(it);
        }
        freq[x] += val;
        st.insert(freq[x]);
    };

    for(int i = 0; i < n; i++) {
        upd(v[i], +1);
        
        if(i >= k - 1) {
            ans[i - (k - 1)] = k - *(--st.end());
            upd(v[i - (k - 1)], -1);
        }
    }

    // cerr<<"ans: ";
    // for(int i = 0; i < n; i++) cerr<<ans[i]<<" "; cerr<<endl;
    
    SGTree seg(n);
    seg.build(0, 0, n - 1, ans);

    auto rightInd = getRight(ans);

    vector<int> suff(n + 1);

    for(int i = n - 1; i >= 0; i--) {
        int r = rightInd[i];
        suff[i] = suff[r] + (r - i) * ans[i];
    }

    auto query = [&] (int l, int r) {
        int minInd = seg.query(0, 0, n - 1, l, r).S;
        int res = suff[l] - suff[minInd] + (r - minInd + 1) * ans[minInd];
        return res;
    };

    while(q--) {
        int l, r; cin>>l>>r;
        r -= (k - 1);
        --l; --r;
        // cerr<<"l: "<<l<<", r: "<<r<<endl;
        
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