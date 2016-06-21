/* Optimal wifi coverage: dichotomy */
#include <stdio.h>
using namespace std;

int
main(void)
{
	int nb_c;
	scanf("%d", &nb_c);
	for (int c = 0; c < nb_c; c++) {
		int n, m, d = 0;
		vector<int> w;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			int tmp;
			scanf("%d", &tmp);
			w.push_back(tmp);
		}

		printf("%.1f\n",d / 2.0);
	}
	return 0;
}
