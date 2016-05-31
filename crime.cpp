/* Perfect Police Patrol System: color a graph with two colors. */
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int
main(void)
{
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF) {
		int s = 0;
		int c[1000] = {0};
		vector<vector<int>> g;
		for (int i = 0; i < n; i++)
			g.push_back(vector<int> ());
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			g[a - 1].push_back(b - 1);
			g[b - 1].push_back(a - 1);
		}

		/* BFS: color the connected components of the graph
		 * colors : 1, 2. Initialised at 0.
		 */
		for (int i = 0; i < n; i++) {
			if (c[i] != 0)
				continue;
			int s1 = 0, s2 = 0;
			queue<int> q;
			vector<int> tmp;
			tmp.push_back(i);
			c[i] = 1;
			q.push(i);
	
			while (!q.empty()) {
				int v = q.front();
				q.pop();
				for (auto w : g[v]) {
					if (c[w] == 0) {
						c[w] = (c[v] == 1 ? 2 : 1);
						q.push(w);
						tmp.push_back(w);
					} else if (c[v] + c[w] != 3) {
						goto err_impossible;
					}
				}
			}
			for (auto j : tmp) {
				if (c[j] == 1)
					s1++;
				else
					s2++;
			}
			s += ((s1 > s2) ? s2 : s1);
		}
		printf("%d\n", s);
		continue;
	err_impossible:
		printf("Impossible\n");
	}
	return 0;
}
