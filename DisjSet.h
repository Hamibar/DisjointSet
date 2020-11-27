#pragma once
#include <cstddef>
class DisjSet {
public:
	DisjSet(size_t size);
	~DisjSet();
	bool merge(unsigned int x, unsigned int y); // return false if merge failed
	int find(unsigned int x);
	size_t getSetsCount();
	const size_t size;
private:
	size_t count;
	int* parent;
	int* rank;
};

