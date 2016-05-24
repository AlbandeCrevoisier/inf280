/* Mice and Maze */
#include <stdio.h>
#include <climits>
#include <algorithm>
#define N 101
using namespace std;

int
main(void)
{
	int c_nb;
	scanf("%d", &c_nb);
	for (int c = 0; c < c_nb; c++) {
		int n, e, t, m, s = 0;
		int g[N][N];
		scanf("%d %d %d %d", &n, &e, &t, &m);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (i == j)
					g[i][j] = 0;
				else
					g[i][j] = INT_MAX/2;
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			g[a][b] = c;
		}
		/* Floyd - Warshall */
		for (int k = 1; k < (n+1); k++) {
			for (int i = 1; i < (n+1); i++) {
				for (int j = 1; j < (n+1); j++) {
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
				}
			}
		}
		for (int i = 1; i < (n+1); i++)
			if (g[i][e] <= t)
				s++;
		printf("%d\n", s);
		if (c < c_nb-1)
			printf("\n");
	}

	return 0;
}

