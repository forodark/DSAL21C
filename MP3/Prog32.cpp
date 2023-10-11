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
            {"Philippines", 1000, 200, 300},
            {"Japan", 400, 500, 600},
            {"China", 700, 800, 900},
            {"Malaysia", 1000, 200, 300},
            {"Singapore", 400, 500, 600}
        };

        table table1[] = {
            COL("Country", covid_data, country, "20s"),
            COL("Active", covid_data, active, "10d"),
            COL("Recoveries", covid_data, recoveries, "12d"),
            COL("Deaths", covid_data, deaths, "10d"),
            END_TABLE
        }; printTableFull("COVID-19 Data", table1);
        if(!getBool("Do you want to try again? (y/n): ", 'n', 'y'))
            break;
    }
    return 0;
}