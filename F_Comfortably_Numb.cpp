#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;

struct SubData {
    vector<uint> vals;
    vector<array<int,2>> trie;
    SubData() { trie.push_back({-1,-1}); }
    SubData(uint x) {
        vals.push_back(x);
        trie.push_back({-1,-1});
        insert(x);
    }
    void insert(uint x) {
        int node = 0;
        for (int b = 30; b >= 0; --b) {
            int bit = (x >> b) & 1;
            if (trie[node][bit] == -1) {
                trie[node][bit] = (int)trie.size();
                trie.push_back({-1,-1});
            }
            node = trie[node][bit];
        }
    }
    // returns maximum XOR value (i.e., max_{s in trie} (x XOR s))
    uint query_max(uint x) const {
        int node = 0;
        uint ans = 0;
        for (int b = 30; b >= 0; --b) {
            int bit = (x >> b) & 1;
            int want = 1 - bit;
            if (trie[node][want] != -1) {
                ans |= (1u << b);
                node = trie[node][want];
            } else {
                node = trie[node][bit];
                if (node == -1) break;
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<uint> a(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<uint> pref(n+1); pref[0] = 0;
        for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] ^ a[i];

        // build Cartesian tree (max-heap)
        vector<int> leftc(n+1,0), rightc(n+1,0), parent(n+1,0), st;
        for (int i = 1; i <= n; ++i) {
            int last = 0;
            while (!st.empty() && a[st.back()] < a[i]) {
                last = st.back(); st.pop_back();
            }
            if (!st.empty()) { rightc[st.back()] = i; parent[i] = st.back(); }
            if (last) { leftc[i] = last; parent[last] = i; }
            st.push_back(i);
        }
        int root = st.empty() ? 0 : st.front();

        // postorder (iterative)
        vector<int> order;
        if (root) {
            vector<int> s; s.push_back(root);
            while (!s.empty()) {
                int v = s.back(); s.pop_back();
                order.push_back(v);
                if (leftc[v]) s.push_back(leftc[v]);
                if (rightc[v]) s.push_back(rightc[v]);
            }
            reverse(order.begin(), order.end());
        }

        vector<SubData*> data(n+1, nullptr);
        ll answer = 0;

        for (int v : order) {
            SubData *L = leftc[v] ? data[leftc[v]] : nullptr;
            SubData *R = rightc[v] ? data[rightc[v]] : nullptr;
            if (leftc[v]) data[leftc[v]] = nullptr;
            if (rightc[v]) data[rightc[v]] = nullptr;

            SubData *leftSet = L ? L : new SubData(pref[v-1]);
            SubData *rightSet = R ? R : new SubData(pref[v]);

            // iterate over smaller, query larger
            SubData *base, *other;
            if (leftSet->vals.size() < rightSet->vals.size()) {
                base = rightSet; other = leftSet;
            } else {
                base = leftSet; other = rightSet;
            }

            for (uint val : other->vals) {
                uint want = val ^ a[v];
                uint best = base->query_max(want); // this is the numbness candidate
                answer = max(answer, (ll)best);
            }

            // merge small into large
            for (uint val : other->vals) {
                base->insert(val);
                base->vals.push_back(val);
            }
            delete other;
            data[v] = base;
        }

        if (root && data[root]) { delete data[root]; data[root] = nullptr; }
        cout << answer << '\n';
    }
    return 0;
}