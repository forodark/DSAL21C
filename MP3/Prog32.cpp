#include "glenlib.hpp"

using namespace std;
using namespace gl;

//Using arrays, create a complete C++ program that will display three columns of COVID-19 data; Active, Recoveries, and Deaths.

struct Data {
    string country;
    int active;
    int recoveries;
    int deaths;
};

int main() {
    while(true) {
        Data covid_data[] = {
            {"Manila", 64, 162852, 1939},
            {"Makati", 54, 95066, 737},
            {"Mandaluyong", 30, 53816, 559},
            {"Pasay", 12, 58159, 423},
            {"Taguig", 50, 93889, 593}
        };

        table table1[] = {
            COLUMN("Country", covid_data, country, "20s", Data),
            COLUMN("Active", covid_data, active, "10d", Data),
            COLUMN("Recoveries", covid_data, recoveries, "12d", Data),
            COLUMN("Deaths", covid_data, deaths, "10d", Data),
            END_TABLE
        }; printTableFull("COVID-19 Data in NCR", table1);
        if(!getBool("Do you want to try again? (y/n): ", 'n', 'y'))
            break;
    }
    return 0;
}