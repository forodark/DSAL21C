#include <iostream>
#include "glenlib.hpp"

using namespace std;
using namespace gl;

int main() {
    double monthly_sales[12];
    double quarterly_sales[4];

    for(int i = 0; i < 12; i++) {
        cout << "Enter Sales for Month " << i+1 << ": ";
        monthly_sales[i] = getDouble("");
    }

    cout << ln
         << "  Quarter | Sales             " << endl
         << ln;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            quarterly_sales[i] += monthly_sales[(3*i)+j];

        }
        cout <<"  " << i+1 << "       | " << fixed << setprecision(2) << quarterly_sales[i] << endl;
    }
    cout << ln;

    return 0;   
}
