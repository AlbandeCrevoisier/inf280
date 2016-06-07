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
		for (int i = 0; i < n; i++) {
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			r.push_back(vector<int>() = {x1, y1, x2, y2});
		}
	}
	return 0;
}
