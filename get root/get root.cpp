
#include <iostream>

using namespace std;

double powerfunc(double x, int y) {

    if (y == 0) return 1;

    return x * powerfunc(x, y - 1);
}

double RootHelper(double x, double low, double high, int root) {

    if (high - low < 0.000001) return low;

    double mid = (low + high) / 2.0;

    if (powerfunc(mid, root) > x) return RootHelper(x, low, mid, root);

    return RootHelper(x, mid, high, root);

}

double getRoot(double x, int n) {

    if (x < 1)  return RootHelper(x, x, 1, n);

    return RootHelper(x, 1, x, n);

}


int main()
{
    double result, x = 10.0;
    int y = 4;
    result = getRoot(x, y);
    cout << result;
    return 0;
}

