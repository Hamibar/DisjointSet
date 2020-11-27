# Disjoint-set (Merge-Find set, Union-Find set)

Implementation disjoint-set data structure using 2 heuristic:
* path compression,
* merge by rank.

## Time complexity.
Find: __O(log*(n))__ average, __O(n)__ worst </br>
Merge: __O(log*(n))__ average, __O(n)__ worst


## Practice 
For demonstration of speed implemented 2 version Kruskal algorithm.
* Fast algorithm using disjoint-set. Time complexity __O(E*log(E))__;
* Slow algorithm using std::vector. Time complexity __O(E\*log(E) + V*V)__;
