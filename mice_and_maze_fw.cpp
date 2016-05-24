/* Mice and Maze */ #include <stdio.h>
#include <climits>
#include <algorithm>
using namespace std;

int
main(void)
{
	int c_nb;
	scanf("%d", &c_nb);
	for (int c = 0; c < c_nb; c++) {
		int n, e, t, m, s = 0;
		int g[100][100];
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				g[i][j] = INT_MAX;
		scanf("%d %d %d %d", &n, &e, &t, &m);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			g[a][b] = c;
		}
		/* Floyd - Warshall */
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		for (int i = 0; i < n; i++)
			if (g[i][e] <= t)
				s++;
		printf("%d\n\n", s);
	}

	return 0;
}

