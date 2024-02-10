#include<bits/stdc++.h>

using namespace std;

#define MAX 10005
#define pii pair<int,int>
vector< pair<int,int> > cities[MAX];
map<string,int> mp;
int dist[MAX];


void dijkstra(int src) {
    
    priority_queue<pii,vector<pii>,greater< pii > > pq;
    pq.push(pii(0,src));
    dist[src] = 0;
    while(!pq.empty()) {

        int u = pq.top().second;
        pq.pop();
        for(int i=0;i<cities[u].size();i++) {

            int v = cities[u][i].second;
            int c = cities[u][i].first;
            
            if(dist[u]+c < dist[v]) {

                dist[v] = dist[u]+c;
                pq.push(pii(dist[v],v));
            }
        }
    }
}

int main() {
    
    int t,n,p,nr,cost,r;
    scanf("%d",&t);

    while(t--) {

        scanf("%d",&n);
        char str[20];
        for(int i=0;i<n;i++) {
            scanf("%s%d",str,&p);
            mp[str] = i+1;
            for(int j=0;j<p;j++) {
                scanf("%d%d",&nr,&cost);
                cities[nr].push_back(pii(cost,i+1));
            }
        }

        scanf("%d",&r);
        char s1[20],s2[20];

        for(int i=0;i<r;i++) {

            scanf("%s%s",s1,s2);
            int u = mp[s1];
            int v = mp[s2];
            for(int j=0;j<=n;j++)
                dist[j] = 1000000000;

            dijkstra(u);

            printf("%d\n",dist[v]);
        }
        
        for(int i=0;i<=n;i++)
            cities[i].clear();
        mp.clear();
    }
}