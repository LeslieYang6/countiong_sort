#include<iostream>

using namespace std;

int range = 100;


int Get_Max(int arr[], int n)
{
	int Max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > arr[i - 1])
			Max = arr[i];
	return Max;
}

void Counting_Sort(int arr[], int n,int exp)
{
	int count[10];
	memset(count, 0, sizeof(count));
	for (int i = 0; i<n; i++)
		count[arr[i]/exp%10]++;
	int *output;
	output = new int[n];
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; i--)
	{
		output[count[arr[i]/exp%10] - 1] = arr[i];
		count[arr[i]/exp%10]--;
	}
	for (int i = 0; i<n; i++)
		arr[i] = output[i];
}

void Radix_Sort(int arr[], int n)
{
	int Max = Get_Max(arr, n);
	for (int exp = 1; exp < Max; exp *= 10)
		Counting_Sort(arr, n, exp);
}


int main()
{
	int a[] = { 85,47,25,25,25,85,8,5,47,47,8565,4785,5445,455,8152,544,5585};
	Radix_Sort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i<sizeof(a)/sizeof(a[0]); i++)
		cout << a[i] << " ";
	system("pause");
}