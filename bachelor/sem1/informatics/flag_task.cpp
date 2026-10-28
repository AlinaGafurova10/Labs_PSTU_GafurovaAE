#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");
    bool f = false;
    int N, a, i = 1;
    
    cin >> N;

    while((i<=N) && !f)
    {
        cin >> a;

        if(a == 0)
        i += 1;
        else
        f = true;
    }
    if(f)
    {
        if(a > 0)
        cout<<"a = " << a << "положительное"<< endl;
        else
        cout<<"a = " << a << "отрицатеьное"<< endl;
    }
    else
    cout<<"Последовательность состоит из нулей" << endl;
}