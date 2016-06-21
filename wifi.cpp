/* Optimal wifi coverage */
#include <stdio.h>
#include <vector>
using namespace std;

int
main(void)
{
	int nb_c;
	scanf("%d", &nb_c);
	for (int c = 0; c < nb_c; c++) {
		int n, m, d = 0;
		vector<pair<int, int>> w;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			int tmp;
			scanf("%d", &tmp);
			w.push_back(pair<int, int>(tmp, tmp));
		}

		for (int i = 0; i < (m - n); i++) {
			int idx_min;
			int min = w.back().second;
			for (int j = 0; j < (int) (w.size() - 1); j++) {
				if ((w[j + 1].second - w[j].first) < min) {
					min = w[j + 1].second - w[j].first;
					idx_min = j;
				}
			}
			w[idx_min].second = w[idx_min + 1].second;
			w.erase(w.begin() + idx_min + 1);
		}
		for (auto r : w)
			if ((r.second - r.first) > d)
				d = r.second - r.first;
		printf("%.1f\n", d / 2.0);
	}
	return 0;
}
