#include <iostream>
#include <vector>


class ImprovedUnionFind {
	size_t n;
	std::vector<int> id;
	std::vector<int > sz; // size of each subset
public:
	ImprovedUnionFind(size_t n) {
		this->n = n;
		for(int i = 0;i < n;i++) {
			id.push_back(i);
			sz.push_back(1);
		}
	}

	int root(int i) {
		while(i != id[i]) { 
			//path compression by forming direct link between a node and its grand parents
			id[i] = id[id[i]];
			i = id[i];

			}
		return i;
	}

	bool find(int a, int b) {
		return root(a) == root(b);
	}

	// always link the root of the samller tree to the root of the larger tree
	// This makes prevents the tree from growing too tall
	void Union(int a, int b) {
		int aid = root(a); 
		int bid = root(b);
		if(sz[aid] >= sz[bid]){
			id[bid] = aid;
			sz[aid] += sz[bid];
		}
		else {
			id[aid] = bid;
			sz[bid] += sz[aid];
		}
	}

	void printId() {
		for(int i =0;i < this->n ;i++) {
			std::cout<< "id["<<i<<"]"<<" = "<<id[i]<<"\n";
		}
	}

};


int main() {
	ImprovedUnionFind* uf = new ImprovedUnionFind(10);
 
	uf->Union(0,1);
	uf->Union(2,0);
	uf->Union(4,5);
	uf->Union(4,2);
	uf->Union(9,5);

	uf->Union(6,7);
	uf->Union(3,7);
	uf->printId();

	return 0;
}