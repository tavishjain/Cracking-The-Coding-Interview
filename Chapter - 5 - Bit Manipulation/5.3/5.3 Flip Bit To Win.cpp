#include <bits/stdc++.h>
using namespace std;
#include "bitutils.hpp"

template <typename T>
int flipToWin(T bits)
{
    static_assert(is_unsigned<T>::value, "T must be unsigned integral type");

    int result = 1;
    int lenLeft = 0;
    int lenRight = 0;
    while (bits != 0)
    {
        if (bits & 1)
            ++lenLeft;
        else
        {
            // The current bit is 0 means that we counted right sequence length.
            // If the next bit will be 0, then right sequence length will reset to 0.
            lenRight = lenLeft;
            lenLeft = 0;
        }
        bits >>= 1;
        result = max(lenRight + lenLeft + 1, result);
    }
    // We can not flip bit to 1 if there was no bit 0
    return min(result, numeric_limits<T>::digits);
}

int main()
{
    for (auto testValue : {
                0b11011101111U
            ,  0b110111001111U
            , 0b1100111001111U
            , 0U
            , ~0U
        })
        cout << bits(testValue) << ": " << flipToWin(testValue) << endl;
}