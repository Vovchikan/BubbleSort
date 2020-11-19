// BubbleSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int const MAX = 100;
int const MIN = -100;
string const sep = "---------------------------";

int GetArrayLengthFromConsole();
int* GenerateMassive(int);
int PrintMassive(int*, int);
int BubbleSort(int*, int);
int Swap(int*, int, int);


int main()
{
    int massiveLength = GetArrayLengthFromConsole();
    int* randomMassive = GenerateMassive(massiveLength);
    PrintMassive(randomMassive, massiveLength);
    BubbleSort(randomMassive, massiveLength);
    cout << endl << sep << " Sorting with bubble sort " << sep << endl;
    PrintMassive(randomMassive, massiveLength);
    cout << endl << "End of program.\n";
}

int GetArrayLengthFromConsole() {
    int length;
    cout << "Enter arrays's length(): ";

    while (!(cin >> length)) {
        cout << "ERROR: enter arrays's length(): ";
        cin.clear();
        cin.ignore(22, '\n');
    }

    return length;
}

int* GenerateMassive(int length) {
    int* massive = new int[length];
    for (int i = 0; i < length - 1; i++)
    {
        massive[i] = rand() % (MAX - MIN + 1) + MIN;
    }
    return massive;
}

int PrintMassive(int* massive, int length) {
    cout << endl << "Massive: ";
    for (int i = 0; i < length - 1; i++)
    {
        cout << "[" << massive[i] << "] ";
    }
    cout << endl;
    return 0;
}

int BubbleSort(int* massive, int length) {
    if (length <= 1)
        return 1;
    bool notSorted = true;
    while (notSorted) {
        notSorted = false;
        for (int i = 0, j = 1; i < length - 2; i++, j++)
        {
            if (massive[i] > massive[j]) {
                Swap(massive, i, j);
                notSorted = true;
            }
        }
    }
    return 0;
}

int Swap(int* massive, int i, int j) {
    int temp = massive[i];
    massive[i] = massive[j];
    massive[j] = temp;
    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
