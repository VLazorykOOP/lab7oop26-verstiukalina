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

template <typename T>
void sortuvatyMasyv(T arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        T temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

template <>
void sortuvatyMasyv<char *>(char *arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(arr[j], arr[minIndex]) < 0)
            {
                minIndex = j;
            }
        }

        char *temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}