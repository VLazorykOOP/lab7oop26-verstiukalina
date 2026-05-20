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

void zapustytyZadachu1()
{
    const int n = 5;
    int intArr[n];
    double doubleArr[n] = {2.5, 4.7, 6.1, 8.4, 10.3};
    char word1[] = "cat";
    char word2[] = "university";
    char word3[] = "oop";
    char word4[] = "template";
    char word5[] = "lab";
    char *words[n] = {word1, word2, word3, word4, word5};
    int inputChoice;

    cout << "\nЗадача 1.4. Середнє значення в масиві\n";
    cout << "Оберіть спосіб введення тільки для масиву int\n";
    cout << "1 - введення з клавіатури\n";
    cout << "2 - введення з файлу task1_int.txt\n";
    cout << "3 - випадкові значення\n";
    cout << "Ваш вибір: ";
    cin >> inputChoice;

    if (inputChoice == 1)
    {
        vvestyZKlaviatury(intArr, n);
    }
    else if (inputChoice == 2)
    {
        vvestyZFailu(intArr, n);
    }
    else
    {
        zapovnytyVypadkovo(intArr, n);
    }

    cout << "\nМасив int: ";
    drukuvatyMasyv(intArr, n);
    cout << "Середнє int: " << serednie(intArr, n) << endl;

    cout << "\nМасив double: ";
    drukuvatyMasyv(doubleArr, n);
    cout << "Середнє double: " << serednie(doubleArr, n) << endl;

    cout << "\nМасив char*: ";
    drukuvatyMasyv(words, n);
    cout << "Середня довжина рядків: " << serednie(words, n) << endl;
}

void zapustytyZadachu2()
{
    const int n = 5;
    int intArr[n];
    double doubleArr[n] = {4.5, 1.2, 8.7, 3.3, 2.1};
    char word1[] = "banana";
    char word2[] = "apple";
    char word3[] = "orange";
    char word4[] = "kiwi";
    char word5[] = "grape";
    char *words[n] = {word1, word2, word3, word4, word5};
    int inputChoice;

    cout << "\nЗадача 2.4. Впорядкування методом вилучення\n";
    cout << "Оберіть спосіб введення послідовності int\n";
    cout << "1 - введення з клавіатури\n";
    cout << "2 - введення з файлу task1_int.txt\n";
    cout << "3 - випадкові значення\n";
    cout << "Ваш вибір: ";
    cin >> inputChoice;

    if (inputChoice == 1)
    {
        vvestyZKlaviatury(intArr, n);
    }
    else if (inputChoice == 2)
    {
        vvestyZFailu(intArr, n);
    }
    else
    {
        zapovnytyVypadkovo(intArr, n);
    }

    cout << "\nМасив int до сортування: ";
    drukuvatyMasyv(intArr, n);
    sortuvatyMasyv(intArr, n);
    cout << "Масив int після сортування: ";
    drukuvatyMasyv(intArr, n);

    cout << "\nМасив double до сортування: ";
    drukuvatyMasyv(doubleArr, n);
    sortuvatyMasyv(doubleArr, n);
    cout << "Масив double після сортування: ";
    drukuvatyMasyv(doubleArr, n);

    cout << "\nМасив char* до сортування: ";
    drukuvatyMasyv(words, n);
    sortuvatyMasyv(words, n);
    cout << "Масив char* після сортування: ";
    drukuvatyMasyv(words, n);
}

void zapustytyZadachu3()
{
    TsyklichnaCherha<int> intQueue(5);
    TsyklichnaCherha<double> doubleQueue(5);
    TsyklichnaCherha<char *> wordQueue(5);

    char word1[] = "one";
    char word2[] = "two";
    char word3[] = "three";

    intQueue.dodaty(10);
    intQueue.dodaty(20);
    intQueue.dodaty(30);
    cout << "\nЧерга int: ";
    intQueue.druk();
    cout << "Видалено: " << intQueue.vydalyty() << endl;
    cout << "Черга int після видалення: ";
    intQueue.druk();
    intQueue.dodaty(40);
    intQueue.dodaty(50);
    cout << "Черга int після додавання: ";
    intQueue.druk();

    doubleQueue.dodaty(1.5);
    doubleQueue.dodaty(2.7);
    doubleQueue.dodaty(3.9);
    cout << "\nЧерга double: ";
    doubleQueue.druk();
    cout << "Видалено: " << doubleQueue.vydalyty() << endl;
    cout << "Черга double після видалення: ";
    doubleQueue.druk();

    wordQueue.dodaty(word1);
    wordQueue.dodaty(word2);
    wordQueue.dodaty(word3);
    cout << "\nЧерга char*: ";
    wordQueue.druk();
    cout << "Видалено: " << wordQueue.vydalyty() << endl;
    cout << "Черга char* після видалення: ";
    wordQueue.druk();
}

void zapustytyZadachu4()
{
    const int n = 5;
    int values[n];
    int inputChoice;
    MiyMasyv<int> arr(5);

    cout << "\nЗадача 4.4. Клас масиву та ітератор\n";
    cout << "Оберіть спосіб введення масиву int\n";
    cout << "1 - введення з клавіатури\n";
    cout << "2 - введення з файлу task1_int.txt\n";
    cout << "3 - випадкові значення\n";
    cout << "Ваш вибір: ";
    cin >> inputChoice;

    if (inputChoice == 1)
    {
        vvestyZKlaviatury(values, n);
    }
    else if (inputChoice == 2)
    {
        vvestyZFailu(values, n);
    }
    else
    {
        zapovnytyVypadkovo(values, n);
    }

    for (int i = 0; i < n; i++)
    {
        arr.vstanovyty(i, values[i]);
    }

    IteratorMasyvu<int> iterator(&arr);

    cout << "Елементи масиву: ";

    while (iterator.yeNastupnyi())
    {
        cout << iterator.nastupnyi() << " ";
    }

    cout << endl;
}

int main()
{
    srand(time(0));
    SetConsoleOutputCP(1251);

    int choice;

    do
    {
        cout << "\nМеню:\n";
        cout << "1 - Задача 1.4\n";
        cout << "2 - Задача 2.4\n";
        cout << "3 - Задача 3.4\n";
        cout << "4 - Задача 4.4\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1)
        {
            zapustytyZadachu1();
        }
        else if (choice == 2)
        {
            zapustytyZadachu2();
        }
        else if (choice == 3)
        {
            zapustytyZadachu3();
        }
        else if (choice == 4)
        {
            zapustytyZadachu4();
        }
    } while (choice != 0);

    return 0;
}
