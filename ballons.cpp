/* Ballons in a box */
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <math.h>
#include <climits>
#define PI 3.1415926535
#define N 6
#define MAX 720 /* N! */
using namespace std;

int
main(void)
{
	int nb_p;
	scanf("%d", &nb_p);
	while (nb_p != 0) {
		int idx = 0;
		int n = 0; /* number of points inside of the box */
		int cube[2][3];
		int p[N][4]; /* 0-2: position, 3: squared radius */
		int v[MAX];
		int pr[N];
		scanf("%d %d %d", &cube[0][0], &cube[0][1], &cube[0][2]);
		scanf("%d %d %d", &cube[1][0], &cube[1][1], &cube[1][2]);
		for (int tmp = 0; tmp < nb_p; tmp++) {
			int i, j, k;
			scanf("%d %d %d", &i, &j, &k);
			if (
				((cube[0][0] < i) ^ (cube[1][0] < i)) &&
				((cube[0][1] < j) ^ (cube[1][1] < j)) &&
				((cube[0][2] < k) ^ (cube[1][2] < k))) {
				p[n][0] = i;
				p[n][1] = j;
				p[n][2] = k;
				n++;
			}
		}
		for (int i = 0; i < n; i++)
			pr[i] = i;

		/* compute volume and put it in v[] */
		while (next_permutation(pr, pr + n)) {
			for (int i = 0; i < n; i++) {
				int d[N + 6];
				for ( int j = 0; j < n; j++) {
					if (i == j)
						continue;
					int r = p[pr[i]][3] * p[pr[i]][3];
					int d0 = p[pr[i]][0] - p[pr[j]][0];
					int d1 = p[pr[i]][1] - p[pr[j]][1];
					int d2 = p[pr[i]][2] - p[pr[j]][2];
					d0 *= d0;
					d1 *= d1;
					d2 *= d2;
					if (d0 + d1 + d2 < r)
						d[j] = d0 + d1 + d2;
				}
				for (int j = 0; j < 2; j++) {
					int d0 = p[pr[i]][0] - cube[j][0];
					int d1 = p[pr[i]][1] - cube[j][1];
					int d2 = p[pr[i]][2] - cube[j][2];
					d0 *= d0;
					d1 *= d1;
					d2 *= d2;
					d[n + j] = d0 + d1 + d2;
				}
				for (int j = 0; j < n + 6; j++) {
					int m = INT_MAX;
					if (d[j] != 0 && d[j] < m) {
						m = d[j]
						/* TODO 
						 * get the idx of the min
						 */
					}
				}
			v[idx] += 4 * PI * 
			idx++;
		}
	}
	return 0;
}
