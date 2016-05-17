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
    string s;

    /* Sive of Eratosthenes */
    for (int i = 2; i*i <= RANGE; i++) {
        if (!t[i]) {
            p.push_back(i);
            for (int j = 2 * i; j < RANGE; j += i)
                t[j] = true;
        }
    }

    cin >> n;
   
   while (n) {
        for (auto& i : p) {
            if ((n - i) < 0)
                break;
            if (!t[n - i]) {
                s += to_string(n);
                s += " = ";
                s += to_string(i);
                s += " + ";
                s += to_string(n - i);
                s += "\n";
                break;
            }
        }
        cin >> n;
    }

    cout << s;
    return 0;
}

