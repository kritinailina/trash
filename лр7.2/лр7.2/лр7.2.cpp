#include <iostream>
#include <stdarg.h>
using namespace std;

int kvadr(int k, ...)
{
    int result = 0;
    va_list factor;
    va_start(factor, k);
    for (int i = 0; i < k; i++)
    {
        float n = sqrt(va_arg(factor, int));
        if (n == int(n))
        {
            result++;
        }
    }
    va_end(factor);
    return result;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Количество квадратов(3, 1, 3, 9) = " << kvadr(3,1,3,9);
    cout << "\nКоличество квадратов(7, 1, 4, 8, 15, 25, 0, 49) = " << kvadr(7, 1, 4, 8, 15, 25, 0, 49);
    cout << "\nКоличество квадратов(11, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121) = " << kvadr(11, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121);
}
