/* Mice and Maze */
#include <stdio.h>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int
main(void)
{
	int c_nb;

	scanf("%d", &c_nb);
	for (int i = 0; i < c_nb; i++) {
		int n, e, t, m;
		int w[100][2];
		vector<int> p, q;
		map<int, int> g[100];
		scanf("%d %d %d %d", &n, &e, &t, &m);
		for (int j = 0; j < n; j++)
			q.push_back(j);
		for (int j = 0; j < n; j++)
			w[j][1] = t;
		for (int j = 0; j < m; j++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			g[b].insert(pair<int, int>(a, -c));
		}

		/* Adapted Dijkstra:
		 * negative weight links and initial int weight.
		 */
		w[e][0] = e;
		w[e][1] = t;
		p.push_back(e);
		q.erase(e);

		while (!q.empty()) {
			/* min */
			int m, l = INT_MIN;
			for (auto j : p) {
				for (auto k : g[j]) {
					if (binary_search(q.begin(), q.end(), k.first) && l < k.second) {
						m = k.first;
						l = k.second;
					}
				}

			}
			p.push_back(m);
			q.erase(m);
			/* update weights */

		}
	}
	


	return 0;
}

