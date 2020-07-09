#include <iostream>
#include <fstream>

using namespace std;

int simile(const void* one, const void* two)
{
    return (*(int*)one - *(int*)two);
}

int main()
{
    ifstream fileIn("INPUT.txt");
    ofstream fileOut("OUTPUT.txt");
    int N = 0, M = 0, count = 0;
    fileIn >> N >> M;
    int* num = new int[N];

    for (int i = 0; i != N; i++)
    {
        fileIn >> count;
        num[i] = count;
    }
    qsort(num, N, sizeof(int), simile);

    for (int i = 0; i != M; i++)
    {
        num[N - 1 - i] = -num[N - 1 - i];
    }

    count = 0;
    for (int i = 0; i != N; i++)
    {
        count += num[i];
    }

    fileOut << count;
}


/*Бакланов П.Э. ПС-22, Microsoft Visual Studio
  19.18. Смена знаков (3)
  Задан массив из N целых чисел (1 &lt; N ≤ 10 5 ) и натуральное число M (M ≤ N). Поменять знаки
ровно у M чисел так, чтобы сумма чисел стала минимальна. Найти полученную сумму.
Ввод. Первая строка файла INPUT.TXT содержит числа N и M. Во второй строки задаются N
целых чисел, не превышающих по модулю 10 6 . Все числа в строке разделены пробелом.
Вывод в файл OUTPUT.TXT. В единственной строке выводится полученная сумма.
  Пример
  Ввод
3 2
2 10 -3
  Вывод
-15
*/