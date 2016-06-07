/* Roof */
#include <stdio.h>
#include <vector>
using namespace std;

int
main(void)
{
	int nb_c;
	scanf("%d", &nb_c);
	for (int c = 0; c < nb_c; c++) {
		int n;
		scanf("%d", &n);
		vector<vector<int>> r;
		vector<vector<int>> w_dep;
		for (int i = 0; i < n; i++) {
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			r.push_back(vector<int>() = {x1, y1, x2, y2});
		}
		/* Compute where water falls. */
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)
					continue;
				if (r[i][0] <= r[j][2] && r[j][2] <= r[i][2] &&
				r[j][2] < r[j][0]) {
					int turn = (r[i][2] - r[i][0]) *
						(r[j][3] - r[i][3]) -
						(r[j][2] -r[i][2]) *
						(r[i][3] - r[i][1]);
					if (turn > 0)
						w_dep[i].push_back(j);
				}
				if (r[i][0] <= r[j][0] && r[j][0] <= r[i][2] &&
				r[j][0] < r[j][2]) {
					int turn = (r[i][2] - r[i][0]) *
						(r[j][3] - r[i][3]) -
						(r[j][0] -r[i][2]) *
						(r[i][3] - r[i][1]);
					if (turn > 0)
						w_dep[i].push_back(j);
				}
			}
		}
		/* Go from left to right and compute where rain falls. */
	}
	return 0;
}
