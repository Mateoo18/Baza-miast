//
// Created by mateusz on 23.03.23.
//

#ifndef PROJECTC____GRAPH_H
#define PROJECTC____GRAPH_H
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> iPair;
class Graph {
    int V;
    list<pair<int, int>> *adj;
public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<iPair>[V];
    }
    void addEdge(int u, int v, int w);
    void najkrotsza(int s,int kon,int n);
};

#endif //PROJECTC____GRAPH_H
