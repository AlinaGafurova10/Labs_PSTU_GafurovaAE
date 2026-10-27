#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, ".65001");
    
    const double a = 0.1, b = 1.0;
    const int k = 10;
    const double h = (b - a) / k;
    const int n_max = 25;
    const double eps = 0.0001;
    const double PI = acos(-1.0);
    const double c = cos(PI / 4.0);
    const double s = sin(PI / 4.0);

    cout << fixed << setprecision(6);
    cout << "------------------------------------------------------------\n";
    cout << "  X       SN          SE          Y\n";
    cout << "------------------------------------------------------------\n";

    for (double x = a; x <= b + 1e-9; x += h) {

        // Случай а): заданное n = 25
        double SN = 0.0;
        double t = 1.0;
        for (int n = 0; n <= n_max; n++) {
            double an = cos(n * PI / 4.0) * t;
            SN += an;
            t *= x / (n + 1);
        }

        // Случай б): заданная точность eps
        double SE = 0.0;
        t = 1.0;
        int n = 0;
        double an;
        do {
            an = cos(n * PI / 4.0) * t;
            SE += an;
            t *= x / (n + 1);
            n++;
        } while (fabs(an) >= eps);

        // Точное значение
        double Y = exp(x * c) * cos(x * s);

        cout << setw(6) << x
             << setw(12) << SN
             << setw(12) << SE
             << setw(12) << Y << "\n";
    }

    return 0;
}