//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
//#include <algorithm>

using namespace std;

/*int n; */   // глобальная переменная, внутри функции может быть одноименная локальная переменная
// функция использует ближайшую переменную, т.е. берет локальную скорее всего
// для вызова глобальной нужно обозначить перед ней ::

const int n = 6;
const int m = 7;
const int p = 5;
int arr[n][m] = { {1, 0, 0, 0, 0, 1, 0},
				{0, 1, 1, 0, 0, 0, 0},
				{1, 0, 0, 1, 0, 0, 1} };

bool fs[n][m] = { 0 };
int summa = 0;

int arr1[p][n] = { {1, 0, 0, 0, 0, 0},
				{1, 1, 1, 0, 0, 0},
				{0, 0, 1, 1, 1, 1},
				{1, 0, 0, 0, 0, 1},
				{1, 1, 1, 1, 1, 1} };
bool flag[p][n] = { 0 };

// case 8
void maze(int i, int j) {
	if ((j >= 0 && j < n) && (i >= 0 && i < p)) { // проверка диапозона - установка границ матрицы

		if (arr1[p - 1][n - 1] == 1 && flag[p - 1][n - 1] == true)
			return;

		flag[i][j] = true;
		if (arr1[i][j - 1] ==1 && flag[i][j - 1] == false)
			maze(i, j - 1);
		if (arr1[i][j + 1] ==1 && flag[i][j + 1] == false)
			maze(i, j + 1);
		if (arr1[i - 1][j] ==1 && flag[i - 1][j] == false)
			maze(i - 1, j);
		if (arr1[i + 1][j] ==1 && flag[i + 1][j] == false)
			maze(i + 1, j);

		cout << i << " " << j << endl; // вывод координат единиц
	}
}
void maze_answer(int i, int j) {
	cout << endl << "Coordinates:" << endl;
	maze(i, j);
	if (flag[p - 1][n - 1] == true) cout << "There is Escape!" << endl << endl;
	else cout << "There is No Escape :(" << endl << endl;
}

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
	/*::n = n * 2; */// глобальная n равна локальная n умноженная на 2
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
	// все три цикла вкупе дают распечатку одной строки,
	// затем рекурсия запускает новую строку и так до базового случая выхода из рекурсии
	elka(n - 1, k); // recursion
}
void elka2(int n) {

	static int k = 1;

	if (n == 0)
		return;

	for (int i = 1; i < n; i++)
		cout << " ";

	for (int i = 1; i <= k; i++)
		cout << "*";

	for (int i = 1; i < n; i++)
		cout << " ";

	cout << endl;

	k += 2;
	elka2(n - 1); 
}

int fib(int n) {
	if (n == 1 || n == 0)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
int fib2(int n) {
	int f = 0;
	int f1 = 1;
	int f2 = 1;

	if (n == 0 || n == 1)
		return 1;

	for(int i=2; i<=n; i++)
	{
			f = f1 + f2;
			f1 = f2;
			f2 = f;
	}
	return f;
	}

// case 7
void infect(int i, int j){
	if ((j >= 0 && j < m) && (i >= 0 && i < n)) { // проверка диапозона - установка границ матрицы
		summa++; // сколько клеток заразятся от заданной
		fs[i][j] = true;
		if (arr[i][j - 1] != 0 && fs[i][j - 1] == false)
			infect(i, j - 1);
		if (arr[i][j + 1] != 0 && fs[i][j + 1] == false)
			infect(i, j + 1);
		if (arr[i - 1][j] != 0 && fs[i - 1][j] == false)
			infect(i - 1, j);
		if (arr[i + 1][j] != 0 && fs[i + 1][j] == false)
			infect(i + 1, j);
		if (arr[i - 1][j - 1] != 0 && fs[i - 1][j - 1] == false)
			infect(i - 1, j - 1);
		if (arr[i + 1][j + 1] != 0 && fs[i + 1][j + 1] == false)
			infect(i + 1, j + 1);
		if (arr[i - 1][j + 1] != 0 && fs[i - 1][j + 1] == false)
			infect(i - 1, j + 1);
		if (arr[i + 1][j - 1] != 0 && fs[i + 1][j + 1] == false)
			infect(i + 1, j - 1);
		cout << i << " " << j << endl; // когда в буллевом массиве приходим повторно к какой-то точке
		// т.е. там будет true(1), рекурсия останавливается и начинается вывод координат зараженных клеток
	}
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
		case 8:
		{
			maze_answer(0,0);
		}
		break;
		case 7:
		{
			infect(1, 2); // задаем координаты клетки, с которой пошло заражение
			cout << summa << endl;
		}
		break;
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
			int k = 1;
			elka(a, k);
			elka2(a);
		}
		break;
		case 6:
		{
			int a = 7;
			cout << fib(a) << endl;
			cout << fib2(a) << endl;
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