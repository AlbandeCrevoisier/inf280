/* Mice and Maze */
#include <stdio.h>
#include <climits.h>
#include <vector>
#include <map>
using namespace std;

int
main(void)
{
	int c_nb;

	scanf("%d", &c_nb);
	for (int i = 0; i < c_nb; i++) {
		int n, e, t, m;
		int p[100][2];
		vector<int> q;
		map<int, int> g[100];
		scanf("%d %d %d %d", &n, &e, &t, &m);
		for (int j = 0; j < n; j++)
			q.push_back(j);
		for (int j = 0; j < n; j++)
			p[j][1] = t;
		for (int j = 0; j < m; j++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			g[b].insert(pair<int, int>(a, -c));
		}

		/* Adapted Dijkstra: negative weight links and initial int weight.*/
		p[e][0] = e;
		p[e][1] = t;

		while (!q.empty()) {
			/* min */
			int m, l = INT_MIN;
			for (auto j : q) {

		}
	}
	


	return 0;
}
				   
