/* Mice and Maze */ #include <stdio.h>
#include <climits>
#include <list>
#include <vector>
#include <set>
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
		set<int> p, q;
		vector<pair<int, int>> g[100];
		
		scanf("%d %d %d %d", &n, &e, &t, &m);
		e--;
		for (int j = 0; j < n; j++)
			q.insert(j);
		for (int j = 0; j < n; j++)
			w[j][1] = t;
		for (int j = 0; j < m; j++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			/* x-1 because input is from 1..n, but array 0..(n-1) */
			g[b-1].push_back(pair<int, int>(a-1, -c));
		}

		/* Adapted Dijkstra:
		 * negative weight links and initial int weight.
		 */
		for (int j = 0; j < n; j++)
			w[j][1] = INT_MIN;
		w[e][0] = e;
		w[e][1] = t;
		p.insert(e);
		q.erase(e);
		for (auto j : g[e])
			if ((w[e][1] + j.second) > w[j.first][1]) {
				w[j.first][0] = e;
				w[j.first][1] = (w[e][1] + j.second);
			}
		

		while (!q.empty()) {
			/* min */
			int m, l = INT_MIN;
			for (auto j : p)
				for (auto k : g[j])
					if (q.count(k.first) && l < k.second) {
						m = k.first;
						l = k.second;
					}

			p.insert(m);
			q.erase(m);

			/* update weights */
			for (auto j : g[m])
				if ((w[m][1] + j.second) > w[j.first][1]) {
					w[j.first][0] = m;
					w[j.first][1] = (w[m][1] + j.second);
				}
		}
		/* count mice */
		for (int j = 0; j < n; j++)
			if (w[j][1] >= 0)
				s++;
		printf("%d\n\n", s);
	}

	return 0;
}

