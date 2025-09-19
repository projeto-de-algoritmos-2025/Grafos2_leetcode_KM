#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

struct Aresta { int u, v, peso, indice; };

ll prim(int n, vector<vector<tuple<int,int,int>>>& adjacencia, int banida=-1, int forcada=-1, const vector<Aresta>& arestas = vector<Aresta>()) {
    vector<bool> visitado(n,false);
    ll total = 0;
    int contador = 0;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> fila;

    if (forcada != -1) {
        auto aresta = arestas[forcada];
        total += aresta.peso;
        visitado[aresta.u] = true;
        visitado[aresta.v] = true;
        contador += 2 - (aresta.u == aresta.v);
        for (auto [destino, peso, indice] : adjacencia[aresta.u]) if(indice != forcada && indice != banida) fila.push({peso,{aresta.u,destino}});
        for (auto [destino, peso, indice] : adjacencia[aresta.v]) if(indice != forcada && indice != banida) fila.push({peso,{aresta.v,destino}});
    } else {
        visitado[0] = true;
        contador = 1;
        for (auto [destino,peso,indice] : adjacencia[0]) if(indice != banida) fila.push({peso,{0,destino}});
    }

    while(!fila.empty() && contador < n) {
        auto [peso, par] = fila.top(); fila.pop();
        int u = par.first, v = par.second;
        if(visitado[v]) continue;
        visitado[v] = true;
        total += peso;
        contador++;
        for(auto [destino, pesoDest, indice]: adjacencia[v]) {
            if(!visitado[destino] && indice != banida) fila.push({pesoDest,{v,destino}});
        }
    }

    return contador==n ? total : INF;
}

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& entradaArestas) {
        vector<Aresta> arestas;
        for(int i=0;i<entradaArestas.size();i++) arestas.push_back({entradaArestas[i][0], entradaArestas[i][1], entradaArestas[i][2], i});
        
        vector<vector<tuple<int,int,int>>> adjacencia(n);
        for(auto aresta : arestas) {
            adjacencia[aresta.u].push_back({aresta.v, aresta.peso, aresta.indice});
            adjacencia[aresta.v].push_back({aresta.u, aresta.peso, aresta.indice});
        }

        ll mstOriginal = prim(n, adjacencia, -1, -1, arestas);
        vector<int> criticas, pseudoCriticas;

        for(auto aresta: arestas) {
            ll semAresta = prim(n, adjacencia, aresta.indice, -1, arestas);
            if(semAresta > mstOriginal) { 
                criticas.push_back(aresta.indice); 
                continue; 
            }
            ll comArestaForcada = prim(n, adjacencia, -1, aresta.indice, arestas);
            if(comArestaForcada == mstOriginal) pseudoCriticas.push_back(aresta.indice);
        }

        return {criticas, pseudoCriticas};
    }
};
