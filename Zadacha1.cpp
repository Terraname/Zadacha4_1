// Zadacha1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

int sign(int a)
{ 
    return (a > 0) - (a < 0); 
}

int main()
{
    std::cout << "This program moves all elments of array n steps\n";
    int k, n;
    double c;
    std::cout << "Enter k(number of elements of the array)\n";
    std::cin >> k;
    while (std::cin.fail() || k <= 0)
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Wrong k!\n";
        std::cout << "Enter k another time\n";
        std::cin >> k;
    }
    double* array = new double[k];
    std::cout << "Enter k elements of the array\n";
    for (int i = 0; i < k; i++)
    {
        std::cin >> array[i];
        while (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Wrong element's value!\n";
            std::cout << "Enter element № " << (i+1) << "  of the array another time\n";
            std::cin >> array[i];
        }
    }
    std::cout << "Enter integer n \n";
    std::cin >> n;
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Wrong n!\n";
        std::cout << "Enter n another time\n";
        std::cin >> n;
    }

    // заменяем n на аналогичное положительное
    n =  (k + sign(n) * (abs(n) % k)) % k;

    for (int i = 0; i < n; i++)
    {
        c = array[k-1];
        for (int j = k - 1; j >= 0; j--)
        {
            array[j] = array[j-1];
        }
        array[0] = c;
    }
    std::cout << "\n" << "\n";
    std::cout << "The new array is: \n";
    for (int i = 0; i < k; i++)
    {
        std::cout << array[i] << "\n";
    }

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
