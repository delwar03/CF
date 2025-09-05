    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;

    // Fenwick for point updates + prefix sums
    struct Fenwick {
        int n;
        vector<ll> f;
        Fenwick(int _n): n(_n), f(n+1, 0) {}
        void update(int i, ll v) {
            for (; i <= n; i += i & -i) f[i] += v;
        }
        ll query(int i) const {
            ll s = 0;
            for (; i > 0; i -= i & -i) s += f[i];
            return s;
        }
        // sum on [l..r]
        ll range(int l, int r) const {
            if (l > r) return 0;
            return query(r) - query(l - 1);
        }
    };

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string S;
        int q;
        cin >> S >> q;
        int n = (int)S.size();

        // 1) Manacher
        vector<int> odd(n), even(n);
        // odd-length
        for(int center = 0, l = 0, r = -1; center < n; ++center) {
            int k = (center > r ? 1 : min(odd[l + r - center], r - center + 1));
            while (0 <= center - k && center + k < n && S[center - k] == S[center + k])
                ++k;
            odd[center] = k--;
            if (center + k > r) {
                l = center - k;
                r = center + k;
            }
        }
        // even-length
        for(int center = 0, l = 0, r = -1; center < n; ++center) {
            int k = (center > r ? 0 : min(even[l + r - center + 1], r - center + 1));
            while (0 <= center - k - 1 && center + k < n && S[center - k - 1] == S[center + k])
                ++k;
            even[center] = k--;
            if (center + k > r) {
                l = center - k - 1;
                r = center + k;
            }
        }

        // 2) Collect all (start,end) for palindromes
        //    Group them by end in a vector events[end].
        vector<vector<int>> events(n+1);
        // odd centers
        for(int i = 0; i < n; ++i) {
            for(int radius = 0; radius < odd[i]; ++radius) {
                int start = i - radius;
                int end   = i + radius;
                events[end+1].push_back(start+1);
            }
        }
        // even centers
        for(int i = 0; i < n; ++i) {
            for(int radius = 1; radius <= even[i]; ++radius) {
                int start = i - radius;
                int end   = i + radius - 1;
                events[end+1].push_back(start+1);
            }
        }

        // 3) Read queries, group by r
        vector<vector<pair<int,int>>> qry(n+1);
        for(int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            qry[r].emplace_back(l, i);
        }

        // 4) Sweep end = 1..n
        Fenwick bit(n);
        vector<ll> ans(q);
        for(int r = 1; r <= n; ++r) {
            // add all palindromes ending at r
            for(int start: events[r]) {
                bit.update(start, +1);
            }
            // answer queries ending at r
            for(auto &pr : qry[r]) {
                int l = pr.first, idx = pr.second;
                // count palindromes with start >= l
                ans[idx] = bit.range(l, n);
            }
        }

        // 5) Output
        for(ll x : ans)
            cout << x << "\n";

        return 0;
    }
