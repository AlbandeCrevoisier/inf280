/* Bond */
#include <stdio.h>
#include <queue>
using namespace std;

int
main(void)
{
	while(1) {
		int n, m, q;
		vector<int> d; /* danger */
		vector<int, int> t; /* towns */
		vector<int, int, int> e; /* edges */
		vector<vector<int, int>> g;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			e.push_back(tuple<int, int, int>(a, b, c));
			g.push_back(vector<int, int>());
			g[b].push_back(pair<int, int>(b, c));
			g[c].push_back(pair<int, int>(b, a));
		}
		scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			t.push_back(pair<int, int>(a, b));
		}

		k = -1;
		while (k++) {
			for (auto p : t) {
				/* BFS */
				queue<int> q;
				q.push(p.first);
				while(!q.empt(t()) {
					int v = q.front();
					q.pop();
					for (auto w : g[v]) {
						
			}
		}
	}
	return 0;
}
