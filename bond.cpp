/* Bond */
#include <stdio.h>
using namespace std;

int
main(void)
{
	while(1) {
		int n, m, q;
		vector<int, int> t; /* towns */
		vector<int, int, int> e; /* edges */
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			e.push_back(tuple<int, int, int>(a, b, c));
		}
		scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			t.push_back(pair<int, int>(a, b));
		}

		/* TODO algo */
	}
	return 0;
}

	