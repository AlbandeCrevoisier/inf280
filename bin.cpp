/* Easy bin */
#include <stdio.h>
#include <vector> // using a dqueue would have been better
#include<algorithm>
using namespace std;

int
main(void)
{
	int nb_c;
	scanf("%d", &nb_c);
	for (int c = 0; c < nb_c; c++) {
		int n, l, q = 0;
		vector<int> v;
		scanf("%d %d", &n, &l);
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		while (!v.empty()) {
			if ((v.front() + v.back() <= l) && v.size() > 1) {
				v.erase(v.begin());
				v.erase(--v.end());
				q++;
			} else {
				v.erase(--v.end());
				q++;
			}
		}
		printf("%d\n", q);
		if (c < nb_c - 1)
			printf("\n");
	}
	return 0;
}
