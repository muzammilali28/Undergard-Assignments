#include<iostream>
using namespace std;

void MaxAbsDifference(int A[], int N); //Q1
void MaxAbsSum(int A[], int N);  //Q2
void MinDifference(int A[], int N);  //Q3

int main()
{
	int arr[10] = { -3, -5, 50, 60, 0, 30, 41, 1, 10, 14 };
	int size = 10;

	cout << "A[10] = {-3 , -5 , 50 , 60 , 0 , 30 , 41 , 1 , 10 , 14}\n\n";
	cout << "Max Absolute Difference\n";
	MaxAbsDifference(arr, size);
	cout << "\nMax Indivisual Absolute Sum \n";
	MaxAbsSum(arr, size);
	cout << "\nMin Difference \n";
	MinDifference(arr, size);

	cout << endl;

	return 0;
}

void MaxAbsDifference(int A[], int N)
{
	int x = 0;
	int y = 0;
	int diff = 0;

	if (A[0] < A[1])
	{
		y = A[0];
		x = A[1];
	}
	else
	{
		y = A[1];
		x = A[0];
	}

	diff = x - y;

	for (int i = 2; i < N; i++)
	{
		if (A[i] - y > diff)
		{
			diff = A[i] - y;
			x = A[i];
		}
		else if (A[i] < y)
		{
			y = A[i];
		}
	}

	if (diff < 0)
	{
		diff *= -1;
	}

	cout << "|X - Y| => |" << x << " - " << y << " | = " << x - y << endl;

		return;
}

void MaxAbsSum(int A[], int N)
{
	int x = A[0];
	int y = A[0];
	int sum = 0;
	int temp = 0;

	if (x < 0)
	{
		x *= -1;
		y *= -1;
	}

	for (int i = 1; i<N; i++)
	{
		temp = A[i];

		if (temp < 0)
		{
			temp *= -1;
		}

		if (temp > x)
		{
			y = x;
			x = temp;
		}
		else if (temp > y && temp != x)
		{
			y = temp;
		}
		else if (x - y == 0)
		{
			y = temp;
		}
	}

	cout << "|X| + |Y| => |" << x << "| + |" << y << "| = " << x + y << endl;

	return;
}

void MinDifference(int A[], int N)
{
	int x = 0;
	int y = 0;
	int diff = INT_MAX;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (A[j] > A[i])
			{
				if (A[j] - A[i] < diff)
				{
					diff = A[j] - A[i];
					x = A[j];
					y = A[i];
				}
			}
			else if (A[i] - A[j] < diff)
			{
				diff = A[i] - A[j];
				x = A[i];
				y = A[j];
			}
		}
	}

	cout << "X - Y => " << x << " - " << y << " = " << x - y << endl;

	return;
}
