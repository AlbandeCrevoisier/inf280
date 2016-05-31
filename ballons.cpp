/* Ballons in a box */
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <math.h>
#define PI 3.1415926535
#define MAX 720 /* 6! */
using namespace std;

int
main(void)
{
	int nb_p;
	scanf("%d", &nb_p);
	while (nb_p != 0) {
		int a[3]; b[3];
		int p[6][4]; /* 1-3: position, 4: radius */
		int s[MAX];
		scanf("%d %d %d", &a[0], &a[1], &a[2]);
		scanf("%d %d %d", &b[0], &b[1], &b[2]);
		for (int i = 0; i < nb_p; i++)
			scanf("%d %d %d", &p[i][0], &p[i][1], &p[i][2]);
	}
	return 0;
}
