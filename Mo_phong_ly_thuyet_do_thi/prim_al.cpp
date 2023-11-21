#define _CRT_SECURE_NO_DEPRECATE
#define MAX_N 100
#define MAX 10000000
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int soDinh, soCanh;
int picked[MAX_N];
int best_w_connect_to_T[MAX_N];
int node_from_T_connect_to_v_have_best_w[MAX_N];

struct edge {
	int u, v, w;
	edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};
vector<edge> adj[MAX_N];

// thuat toan Prim - lay canh co trong so nho nhat noi toi T
// cai dat O(V^2)
vector<edge> prim_algorithm(const vector<edge> adj[]) {
	vector<edge> res;
	for (int i = 1; i <= soDinh; i++) best_w_connect_to_T[i] = MAX;
	memset(picked, 0, sizeof(picked));
	best_w_connect_to_T[1] = 0;

	while (res.size() < soDinh) {
		// lay canh co trong so nho nhat ke do
		int u = -1, v = -1, w = 1e9;

		for (int nextnode = 1; nextnode <= soDinh; nextnode++) {
			if (picked[nextnode] == 0 && best_w_connect_to_T[nextnode] < w) {
				v = nextnode;
				u = node_from_T_connect_to_v_have_best_w[v];
				w = best_w_connect_to_T[nextnode];
			}
		}

		if (v == -1) return res; // het thanh phan lien thong

		picked[v] = true;
		// cap nhat lai cac canh noi toi T
		for (edge e : adj[v]) {
			if (best_w_connect_to_T[e.v] > e.w) {
				best_w_connect_to_T[e.v] = e.w;
				node_from_T_connect_to_v_have_best_w[e.v] = e.u;
			}
		}
		res.push_back({u, v, w});

	}
	return res;
}

void input() {
	freopen("input.txt", "r", stdin);
	cin >> soDinh >> soCanh;

	int u, v, w;
	for (int i = 0; i < soCanh; i++) {
		cin >> u >> v >> w;

		// nhap thong tin
		adj[u].push_back(edge(u, v, w));
		adj[v].push_back(edge(v, u, w));
	}
}

int main() {
	input();
	

	auto res = prim_algorithm(adj);

	for (const auto& e : res) {
		cout << e.u << ' ' << e.v << ' ' << e.w << endl;
	}

	return 0;
}
