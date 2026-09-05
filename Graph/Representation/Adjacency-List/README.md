# Graph Representation — Adjacency List

This implementation demonstrates how to represent a graph using an **Adjacency List** in C++.

The implementation covers:

* Undirected Graph
* Directed Graph
* Adjacency List using `unordered_map`
* Printing neighbours of each node

---

## What is a Graph?

A **Graph** is a non-linear data structure consisting of:

* **Vertices (Nodes)** — entities in the graph
* **Edges** — connections between vertices

A graph can be represented in multiple ways. The two most common representations are:

1. Adjacency List
2. Adjacency Matrix

This implementation uses an **Adjacency List**.

---

## Adjacency List

An adjacency list stores the neighbours of every vertex.

For example:

```text
        0
        |
        1
       / \
      2---3
       \ /
        4
```

The adjacency list is:

```text
0 → [1]

1 → [0, 2, 3]

2 → [1, 3, 4]

3 → [1, 2, 4]

4 → [2, 3]
```

---

## Implementation

The adjacency list is implemented using:

```cpp
unordered_map<int, vector<int>> adjList;
```

The structure can be understood as:

```text
Node → Vector of Neighbours
```

For example:

```cpp
adjList[1] = {0, 2, 3};
```

means that node `1` has three neighbours:

```text
1 → 0
1 → 2
1 → 3
```

---

## Undirected Graph

For an undirected graph, an edge between `u` and `v` exists in both directions.

```cpp
adjList[u].push_back(v);
adjList[v].push_back(u);
```

For example:

```cpp
addEdge(0, 1);
```

creates:

```text
0 ↔ 1
```

and stores:

```text
adjList[0] → 1
adjList[1] → 0
```

---

## Directed Graph

For a directed graph, the edge has a specific direction.

```text
u → v
```

Only one entry is required:

```cpp
adjList[u].push_back(v);
```

For example:

```cpp
addEdge(0, 1);
```

creates:

```text
0 → 1
```

but does not create:

```text
1 → 0
```

---

## Code Structure

### Graph Constructor

```cpp
Graph(int n) {
    this->n = n;
}
```

The constructor stores the number of nodes in the graph.

---

### Add Edge

```cpp
void addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
```

The current implementation represents an undirected graph.

For a directed graph, only the following line is required:

```cpp
adjList[u].push_back(v);
```

---

### Print Graph

```cpp
void print() {
    for(int u = 0; u < n; u++) {
        cout << "Neighbours of " << u << " : ";

        for(int v : adjList[u]) {
            cout << v << " ";
        }

        cout << endl;
    }
}
```

This traverses every vertex and prints its neighbours.

---

## Example

The following edges are added:

```cpp
graph1.addEdge(0, 1);
graph1.addEdge(1, 2);
graph1.addEdge(1, 3);
graph1.addEdge(2, 3);
graph1.addEdge(2, 4);
graph1.addEdge(3, 4);
```

The resulting graph is:

```text
        0
        |
        1
       / \
      2---3
       \ /
        4
```

The resulting adjacency list is:

```text
Neighbours of 0 : 1
Neighbours of 1 : 0 2 3
Neighbours of 2 : 1 3 4
Neighbours of 3 : 1 2 4
Neighbours of 4 : 2 3
```

---

## Complexity

Let:

* `V` = number of vertices
* `E` = number of edges

### Space Complexity

```text
O(V + E)
```

The adjacency list stores the vertices and their edges.

For an undirected graph, every edge is stored twice.

### Adding an Edge

For the vector-based adjacency list:

```text
O(1) amortized
```

An undirected edge requires two insertions.

### Traversing the Graph

Traversing all vertices and their neighbours:

```text
O(V + E)
```

---

## Adjacency List vs Adjacency Matrix

| Feature            | Adjacency List        | Adjacency Matrix  |
| ------------------ | --------------------- | ----------------- |
| Space              | `O(V + E)`            | `O(V²)`           |
| Edge lookup        | `O(degree)`           | `O(1)`            |
| Finding neighbours | Efficient             | Requires scanning |
| Sparse Graph       | Better                | Less efficient    |
| Dense Graph        | Can be less efficient | Better suited     |
| BFS / DFS          | Efficient             | Efficient         |

---

## Weighted Graph

For a weighted graph, instead of storing only the neighbour:

```cpp
vector<int>
```

we can store a pair:

```cpp
vector<pair<int, int>>
```

where:

```text
pair<neighbour, weight>
```

For example:

```text
0 → [(1, 10), (2, 5)]
```

represents:

```text
0 --10--> 1
0 --5---> 2
```

This representation is commonly used in algorithms such as Dijkstra's Algorithm.

---

## Common Mistakes

1. Forgetting to add the reverse edge for an undirected graph.
2. Treating a directed graph as undirected.
3. Confusing vertices with edges.
4. Using an adjacency matrix when an adjacency list is more appropriate.
5. Forgetting that an undirected edge is stored twice.

---

## Key Learnings

* An adjacency list maps each vertex to its neighbouring vertices.
* An undirected edge is stored in both directions.
* A directed edge is stored only from source to destination.
* An adjacency list generally requires `O(V + E)` space.
* BFS and DFS naturally operate on adjacency lists.
* The graph representation should be chosen according to the graph and the operations that need to be performed.

---

## Next Concepts

This implementation provides the foundation for:

```text
Graph Representation
        ↓
       BFS
        ↓
       DFS
        ↓
Connected Components
        ↓
Cycle Detection
        ↓
Topological Sort
        ↓
Shortest Path
        ↓
Minimum Spanning Tree
        ↓
DSU
```

---

## File

Implementation:

[`adjacency_list.cpp`](./adjacency_list.cpp)

---

## Note

This implementation is part of my DSA learning journey. The code and documentation will be improved as I learn more about graph data structures and algorithms.
