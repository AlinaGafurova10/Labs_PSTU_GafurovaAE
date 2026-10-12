#include <iostream>

using namespace std;

int main() {
    int n = 1, m = 1;

    cout << "n = " << n << ", m = " << m << endl;

    // m - ++n
    cout << "\n1 выражение" << endl;
    int result1 = m - ++n; // 1 - 2 т.к префиксные ++
    cout << result1 << endl;
    cout << "n = " << n << ", m = " << m << endl;

    n = 1, m = 1;

    // ++m > --n
    cout << "\n2 выражение" << endl;
    bool result2 = ++m > --n; // 2 > 0 т.к ++ и -- префиксные
    cout << result2 << endl;
    cout << "n = " << n << ", m = " << m << endl;

    n = 1, m = 1;

    //--n < ++m
    cout << "\n3 выражение" << endl;
    bool result3 = --n < ++m; // 0 < 2 т.к ++ и -- префиксные
    cout << result3 << endl;
    cout << "n = " << n << ", m = " << m << endl;

    return 0;


}