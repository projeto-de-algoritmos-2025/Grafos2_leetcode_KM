#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

vector<ll> dijkstra(int n, int inicio, vector<vector<pair<int,int>>>& grafo) {
    vector<ll> distancia(n, INF);
    distancia[inicio] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> fila;
    fila.push({0, inicio});

    while (!fila.empty()) {
        auto [d, u] = fila.top(); fila.pop();
        if (d > distancia[u]) continue;

        for (auto [v, peso] : grafo[u]) {
            if (distancia[v] > d + peso) {
                distancia[v] = d + peso;
                fila.push({distancia[v], v});
            }
        }
    }
    return distancia;
}

class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& arestas, int origem1, int origem2, int destino) {
        vector<vector<pair<int,int>>> grafo(n), grafoReverso(n);
        for (auto &aresta : arestas) {
            int u = aresta[0], v = aresta[1], peso = aresta[2];
            grafo[u].push_back({v, peso});
            grafoReverso[v].push_back({u, peso});
        }

        auto distancia1 = dijkstra(n, origem1, grafo);
        auto distancia2 = dijkstra(n, origem2, grafo);
        auto distancia3 = dijkstra(n, destino, grafoReverso);

        ll resposta = INF;
        for (int meio = 0; meio < n; meio++) {
            if (distancia1[meio] == INF || distancia2[meio] == INF || distancia3[meio] == INF) continue;
            resposta = min(resposta, distancia1[meio] + distancia2[meio] + distancia3[meio]);
        }

        return resposta == INF ? -1 : resposta;
    }
};
