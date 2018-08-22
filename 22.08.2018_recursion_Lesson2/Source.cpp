//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
//#include <algorithm>

using namespace std;

int n; // глобальная переменная, внутри функции может быть одноименная локальная переменная
// функция использует ближайшую переменную, т.е. берет локальную скорее всего
// для вызова глобальной нужно обозначить перед ней ::

// 1.	Написать функцию, определяющую среднее арифметическое элементов
// передаваемого ей массива.
template<typename type>
double average(type a[], int n) {
	if (n == 1) return a[n - 1];
	return (a[n - 1] + average(a, n - 1)*(n - 1)) / n;
}

// 2.	Написать функцию, определяющую количество положительных,
// отрицательных и нулевых элементов передаваемого ей массива.

template<typename type>
int count_pmz(type arr[], int size, int &pmz) {
	if (size == 1)
	{
		if (arr[size - 1] < 0)
			return pmz += 100;

		else if (arr[size - 1] > 0)
			return pmz += 10;

		else if (arr[size - 1] == 0)
			return pmz += 1;
	}

	else
	{
		if (arr[size - 1] < 0)
		return pmz + 100 + count_pmz(arr, size - 1, pmz);

		else if (arr[size - 1] > 0)
			return pmz + 10 + count_pmz(arr, size - 1, pmz);

		else if (arr[size - 1] == 0)
			return pmz + 1 + count_pmz(arr, size - 1, pmz);
	}
}

//// 3.	Написать функцию, определяющую минимум и максимум(значение и номер)
//// элементов передаваемого ей массива.
//int position(int arr[], int size, int &min, int &max, int &pos_min, int pos_max) {
//
//	if (size == 1)
//	{
//		cout << min << " ," << pos_min << endl;
//		cout << max << " ," << pos_max << endl << endl;
//		return 1;
//
//		if (arr[size - 1] < min)
//		{
//			min = arr[size - 1];
//			pos_min = size - 1;
//			return position(arr, size - 1, min, max, pos_min, pos_max);
//		}
//		if (arr[size - 1] > max)
//		{
//			max = arr[size - 1];
//			pos_max = size - 1;
//			return position(arr, size - 1, min, max, pos_min, pos_max);
//		}
//	}
//}
void print_char(int n) {
	if (n == 0)
		return;
	char c;
	cin >> c;
	print_char(n - 1);
	cout << c;
}
void print(int n) {
	if (n == 0)
		return;
	cout << char(97 + n); // сначала вывод латинской буквы f, т.е. порядок возрастающий
	print(n - 1);
	/*cout << char(97 + n);*/ //порядок распечатки будет обратный
}

void func(int n, int x) { // case 4
	::n = n * 2; // глобальная n равна локальная n умноженная на 2
	/*n = x * 2; */// глобальная n равна локальная x (НЕодноименная) умноженная на 2
}

void func2(int &x) {
	static int y;
	y = 10;

	x = y * 2;
}

void elka(int n, int k) {
	if (n == 0)
		return;
	
	for (int i = 1; i < n; i++)
		cout << "_";

	for (int i = 1; i <= k; i++)
			cout << "*";

	for (int i = 1; i < n; i++)
		cout << "_";

	cout << endl;

	k+=2;
	elka(n - 1, k); // recursion
}

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 3:
		{
			int a = 5;

			print_char(a);

			print(a);
		}
		break;
		case 4:
		{
			int a = 5;
			int x = 2;
			func(a, x);
			cout << n << endl;
			/*cout << x << endl;*/
		}
		break;
		case 5:
		{
			int a = 5;
			int b = 1;
			elka(a, b);
		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{

		}
		break;
		case 8:
		{

		}
		break;
		case 9:
		{

		}
		break;
		case 10:
		{

		}
		break;
		case 1:
		{
			double a[8] = { 2, 4.2, 6.4, 8, 10, 12.8, 14.5, 16 };

			cout << average(a, 8) << endl << endl;

		}
		break;
		case 2:
		{
			double a[7] = { 1.5, -2.5, -3.5, 4.5, 0, 6.5, 7.5 };
			int b[] = { -1, 0, 3, 0, 5, 6, 0 };

			int pmz = 0;

			cout << count_pmz(b, 7, pmz) << endl << endl;
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}