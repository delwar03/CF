#include <bits/stdc++.h>
using namespace std;

struct State {
    int next[26];
    int link;
    int len;
    State() {
        fill(begin(next), end(next), -1);
        link = -1;
        len = 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    if (!getline(cin, s1)) return 0;
    if (!getline(cin, s2)) s2 = "";

    // Build SAM for s1
    int n = (int)s1.size();
    vector<State> st;
    st.reserve(max(2, 2 * n));
    st.push_back(State()); // state 0
    int last = 0;

    auto sa_extend = [&](int c) {
        int cur = (int)st.size();
        st.push_back(State());
        st[cur].len = st[last].len + 1;
        int p = last;
        while (p != -1 && st[p].next[c] == -1) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = (int)st.size();
                st.push_back(st[q]); // copy q
                st[clone].len = st[p].len + 1;
                // adjust links
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    };

    for (char ch : s1) sa_extend(ch - 'a');

    // Walk SAM with s2 to find LCS length
    int v = 0, l = 0, best = 0;
    for (char ch : s2) {
        int c = ch - 'a';
        if (st[v].next[c] != -1) {
            v = st[v].next[c];
            ++l;
        } else {
            while (v != -1 && st[v].next[c] == -1) v = st[v].link;
            if (v == -1) {
                v = 0;
                l = 0;
            } else {
                l = st[v].len + 1;
                v = st[v].next[c];
            }
        }
        if (l > best) best = l;
    }

    cout << best << '\n';
    return 0;
}
