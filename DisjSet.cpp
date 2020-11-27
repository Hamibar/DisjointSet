#include "DisjSet.h"

DisjSet::DisjSet(size_t size): size(size), count(size){
	parent = new int[size];
	rank = new int[size];
	for (size_t i = 0; i < size; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
}

DisjSet::~DisjSet() {
	delete[] rank;
	delete[] parent;
}

bool DisjSet::merge(unsigned int x, unsigned int y) { // return false if merge failed
	if (x >= size || y >= size || x == y) { return false; }

	unsigned int x_par = find(x);
	unsigned int y_par = find(y);
	
	if (x_par == y_par) { return true; }
	
	if (rank[x_par] < rank[y_par]) {
		parent[x_par] = y_par;
	}
	else {
		parent[y_par] = x_par;
		if (rank[x_par] == rank[y_par]) { rank[x_par]++; }
	}
	count--;
	return true;
}

int DisjSet::find(unsigned int x) {
	if (x >= size) { return -1; }
	if (parent[x] == x) { return x; }
	return parent[x] = find(parent[x]);  // path compression
}

size_t DisjSet::getSetsCount() {
	return count;
}
