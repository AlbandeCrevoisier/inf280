/* Mice and Maze */
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int
main(void)
{
    vector<map<int, int>> m;
    int c_nb;

    scanf("%d", c_nb);
    for (int c; c < c_nb; c++) {
        int n, e, t, m;
        scanf("%d %d %d %d", n, e, t, m);

