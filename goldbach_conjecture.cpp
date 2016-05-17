/* Goldbach's conjecture */
#include <iostream>
#include <vector>
#include <string>
#define RANGE 1000000
using namespace std;

int
main(void)
{
    bool t[RANGE] = {false};
    vector<uint32_t> p;
    uint32_t n;

    /* Sive of Eratosthenes */
    for (int i = 2; i*i <= RANGE; i++)
        if (!t[i]) {
            p.push_back(i);
            for (int j = 2 * i; j < RANGE; j += i)
                t[j] = true;
        }

    cin >> n;
   while (n) {
        for (auto& i : p) {
            if ((n - i) < i)
                break;
            if (!t[n - i]) {
                cout << to_string(n) << " = ";
                cout << to_string(i) << " + ";
                cout << to_string(n - i) << endl;
                break;
            }
        }
        cin >> n;
    }

    return 0;
}

