#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cmath>

double e(double dewpoint)
{
    return 6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (dewpoint + 273.16))));
}

double h(double dewpoint)
{
    return 0.5555 * (e(dewpoint) - 10.0);
}

double getDewpoint(double temperature, double humudex)
{
    return 1 / ((1 / 273.16) - ((log((((humudex - temperature) / 0.5555) + 10.0) / 6.11)) / 5417.7530)) - 273.16;
}

double getHumudex(double temperature, double dewpoint)
{
    return temperature + h(dewpoint);
}

double getTemperature(double humudex, double dewpoint)
{
    return humudex - h(dewpoint);
}

    using namespace std;

int main()
{
    string input;
    double currentT = 101;
    double currentD = 101;
    double currentH = 101;

    while (true)
    {
        for (int i = 0; i < 2; i++)
        {
            cin >> input;
            if (input == "E")
            {
                return 0;
            }
            else if (input == "T")
            {
                cin >> currentT;
            }
            else if (input == "D")
            {
                cin >> currentD;
            }
            else if (input == "H")
            {
                cin >> currentH;
            }
        }

        if (currentH == 101)
        {
            currentH = getHumudex(currentT, currentD);
        }
        else if (currentD == 101)
        {
            currentD = getDewpoint(currentT, currentH);
        }
        else if (currentT == 101)
        {
            currentT = getTemperature(currentH, currentD);
        }

        printf("T %.1lf D %.1lf H %.1lf\n", currentT, currentD, currentH);
        currentD = currentH = currentT = 101;
    }
}