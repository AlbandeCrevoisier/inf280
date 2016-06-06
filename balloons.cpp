/* Ballons in a box */
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#define PI 3.1415926535
#define N 6
#define MAX 720 /* N! */
using namespace std;

/* Hypothesis: the box has sides along the x = 0 hyperplans (and so on). */
int
main(void)
{
	int c_nb = 1;
	while (1) {
		int nb_p;
		int v_box = 1, v_max = 0;
		int idx = 0;
		int n = 0; /* number of points inside of the box */
		int box[2][3];
		int p[N][4]; /* 0-2: position, 3: squared radius */
		int v[MAX] = {0};
		int pr[N];
		scanf("%d", &nb_p);
		if (nb_p == 0)
			break;
		scanf("%d %d %d", &box[0][0], &box[0][1], &box[0][2]);
		scanf("%d %d %d", &box[1][0], &box[1][1], &box[1][2]);
		for (int tmp = 0; tmp < nb_p; tmp++) {
			int i, j, k;
			scanf("%d %d %d", &i, &j, &k);
			if (
				((box[0][0] < i) ^ (box[1][0] < i)) &&
				((box[0][1] < j) ^ (box[1][1] < j)) &&
				((box[0][2] < k) ^ (box[1][2] < k))) {
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
					int r = p[pr[j]][3] * p[pr[j]][3];
					int d0 = p[pr[i]][0] - p[pr[j]][0];
					int d1 = p[pr[i]][1] - p[pr[j]][1];
					int d2 = p[pr[i]][2] - p[pr[j]][2];
					d0 *= d0;
					d1 *= d1;
					d2 *= d2;
					if (d0 + d1 + d2 > r)
						d[j] = d0 + d1 + d2 - r;
				}
				for (int j = 0; j < 2; j++) {
					d[n+3*j] = p[pr[i]][0] - box[j][0];
					d[n+3*j + 1] = p[pr[i]][1] - box[j][1];
					d[n+3*j + 2] = p[pr[i]][2] - box[j][2];
				}
				for (int j = n; j < n + 6; j++)
					d[j] *= d[j];

				int m = INT_MAX;
				for (int j = 0; j < n + 6; j++)
					if (d[j] != 0 && d[j] < m)
						m = d[j];
				p[pr[i]][3] = m;
				v[idx] += (4 * PI * m * sqrt(m) / 3);
			}
			idx++;
		}
		for (int i = 0; i < MAX; i++)
			if (v[i] > v_max)
				v_max = v[i];
		for (int i = 0; i < 3; i++)
			v_box *= abs(box[0][i] - box[1][i]);

		printf("Box %d: %d\n\n", c_nb++, v_box - v_max);
	}
	return 0;
}
