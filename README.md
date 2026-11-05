# AlgoVault

A C++17 learning repository for core data structures and algorithms. The first executable demonstrates linear search, binary search, bubble sort and breadth-first graph traversal.

## Build and run
```bash
cmake -S . -B build
cmake --build build
./build/algovault
```
On Windows, run `build\Debug\algovault.exe` or `build\Release\algovault.exe`, depending on the generator.

## Complexity
| Algorithm | Time | Extra space |
|---|---:|---:|
| Linear search | O(n) | O(1) |
| Binary search | O(log n) | O(1) |
| Bubble sort | O(n²) worst case | O(1) |
| BFS | O(V + E) | O(V) |

Binary search expects sorted input. BFS uses an adjacency-list graph.

## Roadmap
Add merge sort, quicksort, DFS, linked lists, stacks, queues, hash tables, binary search trees, Dijkstra's algorithm and automated tests. Each addition should include complexity notes and edge-case tests.
