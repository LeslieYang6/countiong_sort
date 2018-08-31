#include<iostream>

using namespace std;

int range = 100;



void Counting_Sort(int arr[],int n)
{
	int count[100];
	memset(count, 0, sizeof(count));
	for (int i = 0; i<n; i++)
		count[arr[i]]++;
	int *output;
	output = new int[n];
	for (int i = 1; i < 100; i++)
		count[i] += count[i - 1];
	for (int i = n-1; i>=0; i--)
	{
		output[count[arr[i]]-1] = arr[i];
		count[arr[i]]--;
	}
	for (int i = 0; i<n; i++)
		arr[i] = output[i];
}


int main()
{
	int a[10] = { 85,47,25,25,25,85,8,5,47,47 };
	Counting_Sort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0;i<10; i++)
		cout << a[i] << " ";
	system("pause");
}