/* Perfect Police Patrol System: color a graph with two colors. */
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int
main(void)
{
	while(1) {
		int n, m;
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

		/* BFS: color the graph */
		c[1] = 1;
		q.push(1);

		/* TODO */
	}
	return 0;
}
