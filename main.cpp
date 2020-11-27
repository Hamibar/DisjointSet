#include <iostream>
#include <numeric>
#include <chrono>
#include "Kruskal.h"


void kruskalTest(std::vector<Edge>& graph, int nodes_count, void (*kruskal_algo)(std::vector<Edge>&, int, std::vector<Edge>&)) {
	auto tree = std::vector<Edge>();
	auto start = std::chrono::high_resolution_clock::now();
	kruskal_algo(graph, nodes_count, tree);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cout << "edges count: " << graph.size() << std::endl;
	std::cout << "nodes count: " << nodes_count << std::endl;
	std::cout << "total execution time: " << elapsed.count() << "s" << std::endl;
	long long tot_w = std::accumulate(tree.begin(), tree.end(), 0, [](long long sum, Edge& el) { return sum + el.w; });
	std::cout << "tree weight: " << tot_w << std::endl;
	std::cout << "connected componenst: " << nodes_count - tree.size();
}

int main() {
	std::srand(std::time(NULL));
	int nodes_count = 100000;
	auto graph = std::vector<Edge>();
	auto tree = std::vector<Edge>();
	int edge_count = 10000000;
	for (int i = 0; i < edge_count; i++) {
		int v = std::rand() % nodes_count;
		int u = std::rand() % nodes_count;
		int w = std::rand() % nodes_count;
		graph.push_back({ v, u, w });
	}
	for (int i = 0; i < nodes_count - 1; i++) {
		graph.push_back({ i, i + 1, 100 });
	}

	std::cout << "Fast algorithm using disjoint set" << std::endl;
	kruskalTest(graph, nodes_count, *KruscalFast);
	std::cout << std::endl << std::endl;
	std::cout << "Slow algorithm using std::vector" << std::endl;
	kruskalTest(graph, nodes_count, *KruscalSlow);
	return 0;
}