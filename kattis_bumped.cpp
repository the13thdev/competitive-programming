#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define lim 50000
#define inf 999999999999999
using namespace std;

int scanInt()
{
    int n = 0, ch = getchar_unlocked();
    while (ch < '0' || ch > '9')
        ch = getchar_unlocked();
    while (ch >= '0' && ch <= '9') {
        n = (n << 3) + (n << 1) + ch - '0';
        ch = getchar_unlocked();
    }
    return n;
}

int main()
{
    int N, M, F, S, T, x, y, c, temp, i, j;
    long long temp2;
    vector<vector<pair<int, int> > > graph(2 * lim);
    set<pair<long long, int> > pq;
    bool visited[2 * lim];
    long long shortest_dist[2 * lim], ans;
    N = scanInt(); 
    M = scanInt();
    F = scanInt();
    S = scanInt();
    T = scanInt();
    for (i = 0; i < M; ++i) {
        x = scanInt();
        y = scanInt();
        c = scanInt();
        graph[x].push_back(make_pair(y, c));
        graph[y].push_back(make_pair(x, c));
        graph[x + N].push_back(make_pair(y + N, c));
        graph[y + N].push_back(make_pair(x + N, c));
    }
    for (i = 0; i < F; ++i) {
        x = scanInt();
        y = scanInt();
        graph[x].push_back(make_pair(y + N, 0));
    }
    /*printf("Cities graph:\n");
    for(i=0;i<N;++i){
        printf("%d: ",i);
        vector<pair<int, int> > list = graph[i];
        for(j=0;j<list.size();++j){
            printf("%d(%d) ",list[j].first,list[j].second);
        }
        printf("\n");
    }*/
    ans = inf;
    for (i = 0; i < 2 * N; ++i) {
        visited[i] = false;
        shortest_dist[i] = inf;
        pq.insert(make_pair(shortest_dist[i], i));
    }
    pq.erase(pq.find(make_pair(shortest_dist[S], S)));
    shortest_dist[S] = 0;
    pq.insert(make_pair(shortest_dist[S], S));
    while (!pq.empty()) {
        temp = (pq.begin())->second;
        temp2 = (pq.begin())->first;
        visited[temp] = true;
        //printf(".. visited %d (%lld)\n",temp,temp2);
        pq.erase(pq.begin());
        for (j = 0; j < graph[temp].size(); ++j) {
            //printf("..on edge j=%d,%d (%d)\n",j,graph[temp][j].first,graph[temp][j].second);
            if (!visited[graph[temp][j].first] && (temp2 + graph[temp][j].second * 1ll) < shortest_dist[graph[temp][j].first]) {
                pq.erase(pq.find(make_pair(shortest_dist[graph[temp][j].first], graph[temp][j].first)));
                shortest_dist[graph[temp][j].first] = temp2 + graph[temp][j].second * 1ll;
                //printf("..updated shortest_dist[%d]=%lld\n",graph[temp][j].first,shortest_dist[graph[temp][j].first]);
                pq.insert(make_pair(shortest_dist[graph[temp][j].first], graph[temp][j].first));
            }
        }
    }
    ans = shortest_dist[T] < shortest_dist[T + N] ? shortest_dist[T] : shortest_dist[T + N];
    printf("%lld\n", ans);
    return 0;
}