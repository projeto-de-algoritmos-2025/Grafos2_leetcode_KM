#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct DSU {
        vector<int> pai, nivel;
        int componentes;
        DSU(int n) {
            pai.resize(n+1);
            nivel.assign(n+1,0);
            for(int i=1;i<=n;i++) pai[i]=i;
            componentes = n;
        }
        int encontrar(int x){
            if(pai[x]!=x) pai[x]=encontrar(pai[x]);
            return pai[x];
        }
        bool unir(int x,int y){
            int paiX=encontrar(x), paiY=encontrar(y);
            if(paiX==paiY) return false;
            if(nivel[paiX]<nivel[paiY]) swap(paiX,paiY);
            pai[paiY]=paiX;
            if(nivel[paiX]==nivel[paiY]) nivel[paiX]++;
            componentes--;
            return true;
        }
    };
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& arestas) {
        DSU dsuAlice(n), dsuBob(n);
        int removidas = 0;
        
        for(auto &aresta : arestas){
            if(aresta[0]==3){
                bool uniuAlice = dsuAlice.unir(aresta[1], aresta[2]);
                bool uniuBob = dsuBob.unir(aresta[1], aresta[2]);
                if(!uniuAlice && !uniuBob) removidas++;
            }
        }
        
        for(auto &aresta : arestas){
            if(aresta[0]==1){
                if(!dsuAlice.unir(aresta[1], aresta[2])) removidas++;
            }
        }
        
        for(auto &aresta : arestas){
            if(aresta[0]==2){
                if(!dsuBob.unir(aresta[1], aresta[2])) removidas++;
            }
        }
        
        if(dsuAlice.componentes != 1 || dsuBob.componentes != 1) return -1;
        return removidas;
    }
};
