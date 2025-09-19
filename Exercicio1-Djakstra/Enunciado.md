# 2203. Subgrafo Ponderado Mínimo com os Requisitos Necessários

## Descrição do Problema

Você recebe um inteiro `n` que denota o número de nós de um grafo direcionado ponderado. Os nós são numerados de 0 a n - 1.

Você também recebe um array bidimensional de inteiros `edges` onde `edges[i] = [fromi, toi, weighti]` denota que existe uma aresta direcionada de `fromi` para `toi` com peso `weighti`.

Por último, você recebe três inteiros distintos `src1`, `src2` e `dest` denotando três nós distintos do grafo.

Retorne o peso mínimo de um subgrafo do grafo tal que seja possível alcançar `dest` tanto de `src1` quanto de `src2` através de um conjunto de arestas deste subgrafo. Caso tal subgrafo não exista, retorne -1.

Um subgrafo é um grafo cujos vértices e arestas são subconjuntos do grafo original. O peso de um subgrafo é a soma dos pesos de suas arestas constituintes.

## Exemplos

### Exemplo 1:

**Entrada:** 
```
n = 6
edges = [[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],[2,3,3],[2,3,4],[3,4,2],[4,5,1]]
src1 = 0, src2 = 1, dest = 5
```

**Saída:** `9`

**Explicação:**
A figura acima representa o grafo de entrada. As arestas azuis representam um dos subgrafos que produzem a resposta ótima. Note que o subgrafo `[[1,0,3],[0,5,6]]` também produz a resposta ótima. Não é possível obter um subgrafo com menos peso satisfazendo todas as restrições.

### Exemplo 2:

**Entrada:** 
```
n = 3
edges = [[0,1,1],[2,1,1]]
src1 = 0, src2 = 1, dest = 2
```

**Saída:** `-1`

**Explicação:**
A figura acima representa o grafo de entrada. Pode-se ver que não existe nenhum caminho do nó 1 para o nó 2, portanto não há subgrafos satisfazendo todas as restrições.

## Restrições

- `3 <= n <= 10^5`
- `0 <= edges.length <= 10^5`
- `edges[i].length == 3`
- `0 <= fromi, toi, src1, src2, dest <= n - 1`
- `fromi != toi`
- `src1`, `src2` e `dest` são mutuamente distintos
- `1 <= weight[i] <= 10^5`