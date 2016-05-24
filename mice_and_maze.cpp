/* Mice and Maze */
#include <stdio.h>
#include <climits>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

int
main(void)
{
	int c_nb;
	scanf("%d", &c_nb);
	for (int i = 0; i < c_nb; i++) {
		int n, e, t, m, s = 0;
		int w[100][2];
		list<int> p, q;
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
		for (int j = 0; j < n; j++)
			w[j][1] = INT_MIN;
		w[e][0] = e;
		w[e][1] = t;
		p.push_back(e);
		q.remove(e);

		while (!q.empty()) {
			/* min */
			int m, l = INT_MIN;
			list<int>::const_iterator it;
			for (it = p.begin(); it != p.end(); it++)
				for (auto k : g[*it])
					if (binary_search(q.begin(), q.end(), k.first) && l < k.second) {
						m = k.first;
						l = k.second;
					}

			p.push_back(m);
			q.remove(m);

			/* update weights */
			for (auto j : g[m]) {
				if ((w[m][1] + j.second) > w[j.first][1]) {
					w[j.first][0] = m;
					w[j.first][1] = (w[m][1] + j.second);
				}
			}
		}
		/* count mice */
		for (int j = 0; j < n; j++)
			if (w[j][1] >= 0)
				s++;
		printf("%d\n", s);
	}

	return 0;
}

