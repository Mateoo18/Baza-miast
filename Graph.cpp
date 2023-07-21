//
// Created by mateusz on 23.03.23.
//

#include "Graph.h"
#define INF 0x3f3f3f3f
#include <queue>

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
void Graph::najkrotsza(int src,int kon,int n)
{
    int poprzednik[2000];
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;//1 el waga dojscia do ->wierzohclka 2 sortowane od najmniejszego do najwiekszego
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {//sprawdzamy sasiadow danego wierzcholka
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));//dodanie do kolejki wierzcholka do ktorego mozemy dojsc na ten moment z taka waga
                poprzednik[v]=u;
            }
        }
    }
    cout<<"Najkrotsza droga dojedziesz w "<<dist[kon]<<" jednostki"<<endl;
    int sptr=0;


}
