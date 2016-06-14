/* X */
#include <stdio.h>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int
main(void)
{
	int nb_c;
	scanf("%d", &nb_c);
	for (int c = 0; c < nb_c; c++) {
		int n, a, b;
		vector<vector<int>> g;
		vector<pair<int, int>> d;
		queue<int> q;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			d.push_back(pair<int, int> (INT_MAX, -1));
		for (int i = 0; i < n; i++) {
			int m;
			g.push_back(vector<int>());
			scanf("%d", &m);
			for (int j = 0; j < m; j++) {
				int tmp;
				scanf("%d", &tmp);
				g[i].push_back(tmp);
			}
		}
		scanf("%d %d", &a, &b);

		/* BFS */
		q.push(a);
		d[a].first = 0;
		d[a].second = a;

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
		printf("%d %d %d\n", a, b, d[b].first - 1);
		if (c != (nb_c - 1))
			printf("\n");
	}
	return 0;
}
