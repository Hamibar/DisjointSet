#pragma once
#include <vector>
#include <algorithm>
#include "DisjSet.h"


struct Edge {
	int v;
	int u;
	int w;
};

void KruscalFast(std::vector<Edge>& edges, int node_count, std::vector<Edge>& treeOut) {
	treeOut.clear(); 
	DisjSet ds = DisjSet(node_count);
	std::sort(edges.begin(), edges.end(), [](Edge& th, Edge& oth) {return th.w < oth.w; });
	for (auto& e : edges) {
		if (ds.getSetsCount() == 1) { return; }
		if (ds.find(e.v) != ds.find(e.u)) {
			treeOut.push_back(e);
			ds.merge(e.v, e.u);
		}
	}
}

void KruscalSlow(std::vector<Edge>& edges, int node_count, std::vector<Edge>& treeOut) {
	treeOut.clear();
	std::sort(edges.begin(), edges.end(), [](Edge& th, Edge& oth) {return th.w < oth.w; });
	std::vector<int> treeId(node_count);
	for (int i = 0; i < treeId.size(); i++) {
		treeId[i] = i;
	}

	for (auto& e : edges) {
		if (treeOut.size() == node_count - 1) { return; }
		if (treeId[e.v] == treeId[e.u]) { continue; }
		treeOut.push_back(e);
		int old_id = treeId[e.v];
		int new_id = treeId[e.u];
		for (int i = 0; i < treeId.size(); i++) {
			if (treeId[i] == old_id) {
				treeId[i] = new_id;
			}
		}
	}
}