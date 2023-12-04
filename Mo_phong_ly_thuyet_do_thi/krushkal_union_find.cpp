#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1e9 + 10;
int n, m;

struct edge {
	int u, v, w;
	edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

vector<edge> Edges;

struct UnionFind {
	vector<int> parent;
	// khoi tao mot cau truc voi n phan tu

	UnionFind(int n) {
		parent = vector<int>(n);
		for (int i = 1; i <= n; i++)
			parent[i] = i;
	}

	// do phuc tap O(1)
	int Find(int x) {
		if (x == parent[x]) return x;
		return parent[x] = Find(parent[x]);
	}

	// do phuc tap O(1)
	void Unite(int x, int y) {
		parent[Find(x)] = Find(y);
	}
};

bool EdgeComp(const edge& a, const edge& b) {
	return a.w < b.w;
}

vector<edge> Krushkal(int n, vector<edge> Edges) {
	sort(Edges.begin(), Edges.end(), EdgeComp);
	UnionFind uf(n);
	vector<edge> res;

	for (const edge& e : Edges) {
		if (uf.Find(e.u) != uf.Find(e.v)) {
			res.push_back(e);
			uf.Unite(e.u, e.v);
		}
	}

	return res;
}

void input() {
	cin >> n >> m;
	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		Edges.push_back(edge(u, v, w));
	}
}

int main() {
	freopen("data.inp", "r", stdin);
	input();
	vector<edge> res = Krushkal(n, Edges);
	for (const edge& e : res)
		cout << e.u << ' ' << e.v << endl;

	return 0;
}
