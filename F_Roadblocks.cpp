#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Edge {
    int to, cost;
};

typedef pair<int, int> P;
const int INF = 10000007;

int N, R;
vector<Edge> g[5005];

int d[5005];
int sd[5005];

int solve() {
    fill(d, d + N, INF);
    fill(sd, sd + N, INF);
    priority_queue< P, vector<P>, greater<P> > pq;

    d[0] = 0;
    pq.push(P(0, 0));

    while (!pq.empty()) {
        P p = pq.top(); pq.pop();
        int v = p.second;

        if (sd[v] < p.first)
            continue;

        for (size_t i = 0; i < g[v].size(); i++) {
            Edge& e = g[v][i];
            int nd = p.first + e.cost;
            if (nd < d[e.to]) {
                swap(d[e.to], nd);
                pq.push(P(d[e.to], e.to));
            }
            if (d[e.to] < nd && nd < sd[e.to]) {
                sd[e.to] = nd;
                pq.push(P(sd[e.to], e.to));
            }
        }
    }
    return sd[N-1];
}

int main() {
    scanf("%d %d", &N, &R);
    for (int i = 0; i < R; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        a--; b--;
        g[a].push_back(Edge{b, w});
        g[b].push_back(Edge{a, w});
    }
    int ans = solve();
    printf("%d\n", ans);

    return 0;
}