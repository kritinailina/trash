#include <iostream>
#include <string>
using namespace std;

int gcd(int x, int y) {
    while (x != y) {
        if (x > y) {
            x = x - y;
        }
        else {
            y = y - x;
        }
    }
    return x;
}

double division(double m, double n) {
    double res = m - n;
    return res;
}

string division(string m, string n) {
    int res; int res1;
    int m1 = stof(m.substr(0, m.find("/")));
    int m2 = stof(m.substr(m.find("/") + 1, m.size() - m.find("/")));
    int n1 = stof(n.substr(0, n.find("/")));
    int n2 = stof(n.substr(n.find("/") + 1, n.size() - n.find("/")));
    if (m2 == n2) {
        res = m1 - n1;
        res1 = m2;
    }
    else {
        res = m1 * n2 - m2 * n1;
        res1 = m2 * n2;
    }
    int div = gcd(res, res1);
    res = res / div;
    res1 = res1 / div;
    string res3 = to_string(res) + "/" + to_string(res1);
    return res3;
}

int main()
{
    string m; string n;
    cin >> m >> n;
    if (m.find("/") < 18446744073709551615) {
        cout << division(m, n);
    }
    else {
        double m1 = stof(m);
        double n1 = stof(n);
        cout << division(m1, n1);
    }
}