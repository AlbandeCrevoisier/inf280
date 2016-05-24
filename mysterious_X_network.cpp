/* X */
#include <stdio.h>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int
main(void)
{
	int c_nb;
	scanf("%d", &c_nb);
	for (int c = 0; c < c_nb; c++) {
		int n, a, b;
		vector<int[100]> g;
		vector<pair<int, int>> d;
		queue<int> q;
		for (int i = 0; i < n; i++)
			d.push_back(pair<int, int> (INT_MAX, -1));
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int m;
			scanf("%d", &m);
			for (int j = 0; j < m; j++)
				scanf("%d", &g[i][j]);
		}
		scanf("%d %d", &a, &b);

		q.push(a);
		d[a].first = 0;

		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto w : g[v]) {
				if (d[w].first == INT_MAX) {
					d[w].first = d[v].first + 1;
					d[w].second = v;
					q.push(w);
				}
			}
		}
	}
	return 0;
}

