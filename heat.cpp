/* Fighting the Heat */
#include <stdio.h>
#include <iostream>
#include <string>
#define MAX_L 40
#define MAX_W 400
using namespace std;

int
main(void)
{
	int n, m, k;
	string d[MAX_W];
	bool in_d[MAX_L][MAX_L] = {false};
	char g[MAX_L][MAX_L];
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++)
		cin >> d[i];
	for( int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> g[i][j];

	/* Aho-Corasik would be a pretty neat overkill.
	 * brut forcing with find instead.
	 */

	for (int w = 0; w < k; w++) {
		int w_size = d[w].size();
		/* horizontal */
		for (int i = 0; i < n; i++) {
			int found = string(g[i] + '\0').find(d[w]);
			int rfound;
			string rline;
			if (found != -1)
				for (int idx = found; idx < w_size; idx++)
					in_d[i][idx] = true;
			for (int idx = m - 1; idx > -1; idx--)
				rline.push_back(g[i][idx]);
			rfound = rline.find(d[w]);
			if (rfound != -1)
				for (int idx = m - rfound; idx < w_size; idx++)
					in_d[i][idx] = true;
		}
		/* vertical */
		for (int j = 0; j < m; j++) {
			int found, rfound;
			string s, rs;
			for (int i = 0; i < n; i++) {
				s.push_back(g[i][j]);
				rs.push_back(g[i][n - j]);
			}
			if ((found = v.find(d[w])) != -1)
				for (int idx = found; idx < w_size; idx++)
					in_d[idx][j] = true;
			if ((rfound = v.find(d[w])) != -1)
				for (int idx = n - rfound; idx < w_size; idx++)
					in_d[idx][j] = true;
		}
		/* diagonal: top left - bottow right */
		for (int idx = 0, idx < n + m; idx++) {
			int a, b;
			a = ((idx / (n - 1)) ? 0 : (n - 1) - idx);
			b = ((idx / (n - 1)) ? idx - (n - 1) : 0);
			while (a < n && b < m) {
				string s, rs;
				s.push_back(g[a][b]);
				/* TODO */
			}
		}
				
	}
	return 0;
}
