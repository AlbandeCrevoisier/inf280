/* Mice and Maze */
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int
main(void)
{
    int c_nb;

    scanf("%d", &c_nb);
    for (int c = 0; c < c_nb; c++) {
        int n, e, t, m;
        map<int, int> p;
        vector<map<int, int>> g;
        scanf("%d %d %d %d", &n, &e, &t, &m);
        for (int i = 0; i < m; i++) {
            int a, b, l;
            scanf("%d %d %d", &a, &b, &l);
            g[b].insert(pair<int, int>(a, -l));
        }

        /* reverse Dijkstra-ih */
        p.insert(pair<int, pair<int, int>>(e, pair<int, int>(e, t));

    }
    


    return 0;
}
                   
