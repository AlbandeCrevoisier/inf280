/* Mice and Maze */ #include <stdio.h>
#include <climits>
#include <algorithm>
using namespace std;

int
main(void)
{
	int c_nb;
	scanf("%d", &c_nb);
	for (int i = 0; i < c_nb; i++) {
		int n, e, t, m, s = 0;
		int g[100][100];
		for (int j = 0; j < 100; j++)
			for (int k = 0; k < 100; k++)
				g[j][k] = INT_MAX;
		scanf("%d %d %d %d", &n, &e, &t, &m);
		for (int j = 0; j < m; j++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			g[a][b] = c;
		}
		/* Floyd - Warshall */
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				for (int l = 0; l < n; l++)
					g[k, l] = min(g[k, j] + g[j, l]);
		for (int j = 0; j < n; j++)
			if (g[e, j] >= 0)
				s++;
		printf("%d\n\n", s);
	}

	return 0;
}

