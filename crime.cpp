/* Perfect Police Patrol System: color a graph with two colors. */
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int
main(void)
{
	while(1) {
		int n, m, s1 = 0, s2 = 0;
		int c[1000];
		queue<int> q;
		vector<vector<int>> g;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			g.push_back(vector<int> ());
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			g[a - 1].push_back(b - 1);
			g[b - 1].push_back(a - 1);
		}

		/* BFS: color the graph
		 * colors : 1, 2. Initialised at 0.
		 */
		c[1] = 1;
		q.push(1);

		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto w : g[v]) {
				if (c[w] == 0) {
					c[w] = (c[v] == 1 ? 2 : 1);
					q.push(w);
				} else if (c[v] + c[w] != 3) {
					printf("Impossible\n");
					goto err_impossible;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (c[i] == 1)
				s1++;
			else
				s2++;
		}
		printf("%d\n", (s1 > s2) ? s2 : s1);
	err_impossible:
	}
	return 0;
}
