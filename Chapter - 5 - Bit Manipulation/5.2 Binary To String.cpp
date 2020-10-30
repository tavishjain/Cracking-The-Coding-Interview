#include <bits/stdc++.h>
using namespace std;

string binaryToStringMul(double binary)
{
    stringstream str;
    if (binary < 0 || binary > 1)
        return "ERROR";
    if (binary == 1)
        return "1";
    if (binary == 0)
        return "0";

    str << "0.";

    while (binary != 0)
    {
        if (str.tellp() > 32)
            return "ERROR";

        binary *= 2;
        if (binary >= 1)
        {
            str << '1';
            binary -= 1;
        }
        else
            str << '0';
    }
    return str.str();
}

string binaryToStringDiv(double binary)
{
    stringstream str;
    if (binary < 0 || binary > 1)
        return "ERROR";
    if (binary == 1)
        return "1";
    if (binary == 0)
        return "0";

    double mantissaBit = 0.5;
    str << "0.";

    while (binary != 0)
    {
        if (str.tellp() > 32)
            return "ERROR";

        if (binary >= mantissaBit)
        {
            str << '1';
            binary -= mantissaBit;
        }
        else
            str << '0';
        mantissaBit /= 2;
    }
    return str.str();
}

int main()
{
    double value = 0;
    double frac = 1.0 / 2 + 1.0 / 8;

    cout << setprecision(numeric_limits<double>::digits10 + 1);

    for (int i = 0; i < 10; ++i)
    {
        cout << value << ": " << binaryToStringMul(value) << "(b), " << binaryToStringDiv(value) << "(b)\n";
        value += frac;
        frac /= 16;
    }
}