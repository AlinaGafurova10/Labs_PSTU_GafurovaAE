#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    bool f = false;
    int a, b;

    cin >> a;
    if(a == 0)
    {
        cout << "Не последовательность" << endl;
    }
    else
    {
        cin >> b;

        while((b!= 0) && !f)
        {
            if(a < b)
            {
                a = b;
                cin >> b;
            }
            else
            {
                f = true;
            }
        }

        if(f)
        {
            cout << "Последовательность не упорядочена по возрастанию" << endl;
        }
        else
        {
            cout << "Последовательность упорядочена по возрастанию" << endl; 
        }
    }

    

    return 0;
}