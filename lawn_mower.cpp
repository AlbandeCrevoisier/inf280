/* Lawn  Mower */
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int
main(void)
{
    string s;
    double w;
    int nx, ny;

    while (1) {
        cin >> nx >> ny >> w;
        if (nx == 0 && ny == 0 && w == 0)
            break;

        vector<double> x(nx);
        vector<double> y(ny);
        for (int i = 0; i < nx; i++)
            cin >> x[i];
        for (int i = 0; i < ny; i++)
            cin >> y[i];
    
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        if (x[0] > (w/2) || (75 - x[nx-1]) > (w/2))
            goto no;
        if (y[0] > (w/2) || (100 - y[ny-1]) > (w/2))
            goto no;
    
        for (int i = 0; i < (nx-1); i++)
            if ((x[i+1] - x[i]) > w)
                goto no;
    
        for (int i = 0; i < (ny-1); i++)
            if ((y[i+1] - y[i]) > w)
                goto no;
    
        s += "YES\n";
        continue;
no:
        s += "NO\n";
    }

    cout << s;
    return 0;
}

