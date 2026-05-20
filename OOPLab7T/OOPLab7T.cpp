#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <windows.h>

using namespace std;

template <typename T>
double serednie(T arr[], int n)
{
    T sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return (double)sum / n;
}

template <>
double serednie<char *>(char *arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += strlen(arr[i]);
    }

    return (double)sum / n;
}