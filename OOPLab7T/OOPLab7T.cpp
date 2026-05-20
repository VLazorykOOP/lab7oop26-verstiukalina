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


template <typename T>
class TsyklichnaCherha
{
private:
    T *arr;
    int size;
    int front;
    int rear;
    int count;

public:
    TsyklichnaCherha(int s)
    {
        size = s;
        arr = new T[size];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~TsyklichnaCherha()
    {
        delete[] arr;
    }

    bool chyPorozhnya()
    {
        return count == 0;
    }

    bool chyZapovnena()
    {
        return count == size;
    }

    void dodaty(T value)
    {
        if (chyZapovnena())
        {
            cout << "Черга заповнена\n";
            return;
        }

        rear = (rear + 1) % size;
        arr[rear] = value;
        count++;
    }

    T vydalyty()
    {
        if (chyPorozhnya())
        {
            cout << "Черга порожня\n";
            return T();
        }

        T value = arr[front];
        front = (front + 1) % size;
        count--;
        return value;
    }

    void druk()
    {
        if (chyPorozhnya())
        {
            cout << "Черга порожня\n";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            cout << arr[(front + i) % size] << " ";
        }
        cout << endl;
    }
};

template <typename T>
class MiyMasyv
{
private:
    T *arr;
    int size;

public:
    MiyMasyv(int s)
    {
        size = s;
        arr = new T[size];
    }

    ~MiyMasyv()
    {
        delete[] arr;
    }

    void vstanovyty(int index, T value)
    {
        arr[index] = value;
    }

    T otrymaty(int index)
    {
        return arr[index];
    }

    int otrymatyRozmir()
    {
        return size;
    }
};

template <typename T>
class IteratorMasyvu
{
private:
    MiyMasyv<T> *array;
    int index;

public:
    IteratorMasyvu(MiyMasyv<T> *a)
    {
        array = a;
        index = 0;
    }

    bool yeNastupnyi()
    {
        return index < array->otrymatyRozmir();
    }

    T nastupnyi()
    {
        T value = array->otrymaty(index);
        index++;
        return value;
    }
};


void vvestyZKlaviatury(int arr[], int n)
{
    cout << "Введіть " << n << " цілих чисел: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void vvestyZFailu(int arr[], int n)
{
    ifstream file("task1_int.txt");

    for (int i = 0; i < n; i++)
    {
        file >> arr[i];
    }

    file.close();
}

void zapovnytyVypadkovo(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}

template <typename T>
void drukuvatyMasyv(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}