# 1489. Encontrar Arestas Críticas e Pseudo-Críticas na Árvore Geradora Mínima

## Descrição do Problema

Dado um grafo não direcionado ponderado conectado com `n` vértices numerados de 0 a n - 1, e um array `edges` onde `edges[i] = [ai, bi, weighti]` representa uma aresta bidirecional e ponderada entre os nós `ai` e `bi`. Uma árvore geradora mínima (MST) é um subconjunto das arestas do grafo que conecta todos os vértices sem ciclos e com o menor peso total possível das arestas.

Encontre todas as arestas críticas e pseudo-críticas na árvore geradora mínima (MST) do grafo dado. Uma aresta crítica da MST é aquela cuja remoção do grafo causaria um aumento no peso da MST. Por outro lado, uma aresta pseudo-crítica é aquela que pode aparecer em algumas MSTs, mas não em todas.

Note que você pode retornar os índices das arestas em qualquer ordem.

## Exemplos

### Exemplo 1:

**Entrada:**
```
n = 5
edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
```

**Saída:** `[[0,1],[2,3,4,5]]`

**Explicação:** 
A figura acima descreve o grafo. A figura seguinte mostra todas as MSTs possíveis:

Note que as duas arestas 0 e 1 aparecem em todas as MSTs, portanto são arestas críticas, então as retornamos na primeira lista da saída. As arestas 2, 3, 4 e 5 são apenas parte de algumas MSTs, portanto são consideradas arestas pseudo-críticas. Nós as adicionamos à segunda lista da saída.

### Exemplo 2:

**Entrada:**
```
n = 4
edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
```

**Saída:** `[[],[0,1,2,3]]`

**Explicação:** 
Podemos observar que, como todas as 4 arestas têm peso igual, escolher quaisquer 3 arestas das 4 dadas resultará em uma MST. Portanto, todas as 4 arestas são pseudo-críticas.

## Restrições

- `2 <= n <= 100`
- `1 <= edges.length <= min(200, n * (n - 1) / 2)`
- `edges[i].length == 3`
- `0 <= ai < bi < n`
- `1 <= weighti <= 1000`
- Todos os pares `(ai, bi)` são distintos