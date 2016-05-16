/* Goldbach's conjecture */
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#define RANGE 1000000
using namespace std;

int
main(void)
{
    bool t[RANGE] = {true};
    vector<uint32_t> p;
    uint32_t n;
    string s;

    cout << "start\n";
    /* Sive of Eratosthenes */
    for (int i = 2; i < sqrt(RANGE); i++) {
        if (t[i]) {
            cout << i;
            p.push_back(i);
            for (int j = 2; j < (RANGE/i); j++)
                t[i * j] = false;
        }
    }
    cout << "done\n";

    cin >> n;
    
    do {
        for (auto& i : p)
            if (t[n - i]) {
                cout << i;
                s += n;
                s += " = ";
                s += i;
                s += " + ";
                s += (n - i);
                s += "\n";
            }
        cin >> n;
    } while (n);

    cout << s;
    return 0;
}

