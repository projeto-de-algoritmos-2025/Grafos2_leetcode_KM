# 1579. Remover Número Máximo de Arestas para Manter o Grafo Totalmente Percorrível

**Dificuldade:** Difícil

## Descrição do Problema

Alice e Bob têm um grafo não direcionado de `n` nós e três tipos de arestas:

- **Tipo 1:** Pode ser percorrida apenas por Alice.
- **Tipo 2:** Pode ser percorrida apenas por Bob.
- **Tipo 3:** Pode ser percorrida tanto por Alice quanto por Bob.

Dado um array `edges` onde `edges[i] = [typei, ui, vi]` representa uma aresta bidirecional do tipo `typei` entre os nós `ui` e `vi`, encontre o número máximo de arestas que você pode remover de modo que, após remover as arestas, o grafo ainda possa ser totalmente percorrido por ambos Alice e Bob. O grafo é totalmente percorrido por Alice e Bob se, começando de qualquer nó, eles puderem alcançar todos os outros nós.

Retorne o número máximo de arestas que você pode remover, ou retorne -1 se Alice e Bob não puderem percorrer totalmente o grafo.

## Exemplos

### Exemplo 1:

**Entrada:**
```
n = 4
edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
```

**Saída:** `2`

**Explicação:** 
Se removermos as 2 arestas `[1,1,2]` e `[1,1,3]`, o grafo ainda será totalmente percorrível por Alice e Bob. Remover qualquer aresta adicional não permitirá isso. Então, o número máximo de arestas que podemos remover é 2.

### Exemplo 2:

**Entrada:**
```
n = 4
edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
```

**Saída:** `0`

**Explicação:** 
Note que remover qualquer aresta não fará com que o grafo seja totalmente percorrível por Alice e Bob.

### Exemplo 3:

**Entrada:**
```
n = 4
edges = [[3,2,3],[1,1,2],[2,3,4]]
```

**Saída:** `-1`

**Explicação:** 
No grafo atual, Alice não pode alcançar o nó 4 a partir dos outros nós. Da mesma forma, Bob não pode alcançar o nó 1. Portanto, é impossível tornar o grafo totalmente percorrível.

## Restrições

- `1 <= n <= 10^5`
- `1 <= edges.length <= min(10^5, 3 * n * (n - 1) / 2)`
- `edges[i].length == 3`
- `1 <= typei <= 3`
- `1 <= ui < vi <= n`
- Todas as tuplas `(typei, ui, vi)` são distintas