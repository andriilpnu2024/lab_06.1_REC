#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* a, const int size, const int Low, const int High, int i);
void Print(int* a, const int size, int i);
int sum1(int* a, const int size, int i, int sum);
void replacew0(int* a, const int size, int i);
int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 25;
	int a[n];
	int Low = 5;
	int High = 90;
	int sum = 0;
	Create(a, n, Low, High, 0);
	cout << "sum    = " << sum1(a, n, 0, sum) << endl;
	replacew0(a, n, 0);
	Print(a, n, 0);
	return 0;
}
void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}
int sum1(int* a, const int size, int i, int sum)
{
	if ((a[i] % 2 == 0) || !(i % 8 == 0))
		sum += a[i];
	if (i < size - 1) {
			sum1(a, size, i + 1, sum);
	}
	return sum;
}
void replacew0(int* a, const int size, int i)
{
	if ((a[i] % 2 == 0) || !(i % 8 == 0))
		a[i] = 0;
	if (i < size - 1) {
			replacew0(a, size, i + 1);
	}
}
void Print(int* a, const int size, int i)
{
	cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	if (i < size - 1)
		Print(a, size, i + 1);
}