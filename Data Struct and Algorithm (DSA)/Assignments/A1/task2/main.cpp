#include<iostream>
using namespace std;

template<typename T>
class ThreeStack
{
private:
	T * Vs;
	int S1, S2, S3;
	int t1, t2, t3;

public:
	ThreeStack(int S, int s1 = 0, int s2 = 0)
	{
		Vs = new T[S];

		if (s1 == 0 && s2 == 0 && S % 2 != 0)
		{
			S1 = S / 3;
			S2 = S / 3;
			S3 = S - S1 - S2;

			t1 = -1;
			t2 = S1 - 1;
			t3 = (S1 + S2) - 1;
		}
		else
		{
			S1 = s1;
			S2 = s2;
			S3 = S - s1 - s2;

			t1 = -1;
			t2 = S1 - 1;
			t3 = (S1 + S2) - 1;
		}
	}
	void Push(int i, T V)
	{
		if (i == 0)
		{
			if (!isFull(i))
			{
				t1++;
				Vs[t1] = V;
			}
			else
			{
				cout << "Stack Overflow!" << endl;
			}
		}
		else if (i == 1)
		{
			if (!isFull(i))
			{
				t2++;
				Vs[t2] = V;
			}
			else
			{
				cout << "Stack Overflow!" << endl;
			}
		}
		else if (i == 2)
		{
			if (!isFull(i))
			{
				t3++;
				Vs[t3] = V;
			}
			else
			{
				cout << "Stack Overflow!" << endl;
			}
		}
	}
	void Pop(int i)
	{
		if (i == 0)
		{
			if (!isEmpty(i))
			{
				t1--;
			}
			else
			{
				cout << "Stack Underflow!" << endl;
			}
		}
		else if(i == 1)
		{
			if (!isEmpty(i))
			{
				t2--;
			}
			else
			{
				cout << "Stack Underflow!" << endl;
			}
		}
		else if(i == 2)
		{
			if (!isEmpty(i))
			{
				t3--;
			}
			else
			{
				cout << "Stack Underflow!" << endl;
			}
		}
	}
	T Top(int i)
	{
		if (i == 0)
		{
			if (!isEmpty(i))
			{
				return Vs[t1];
			}
		}
		else if (i == 1)
		{
			if (!isEmpty(i))
			{
				return Vs[t2];
			}
		}
		else if (i == 2)
		{
			if (!isEmpty(i))
			{
				return Vs[t3];
			}
		}
	}
	bool isEmpty(int i)
	{
		if (i == 0)
		{
			if (t1 == -1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (i == 1)
		{
			if (t2 == S1 - 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (i == 2)
		{
			if (t3 == (S1 + S2) - 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	bool isFull(int i)
	{
		if (i == 0)
		{
			if (t1 == S1-1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (i == 1)
		{
			if (t2 == (S1+S2)-1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (i == 2)
		{
			if (t3 == (S1+S2+S3)-1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	~ThreeStack()
	{
		if (Vs != nullptr)
		{
			delete[]Vs;
			Vs = nullptr;
		}
	}

	void Display(int i)
	{
		if (i == 0)
		{
			for (int i = 0; i <= t1; i++)
			{
				cout << Vs[i] << " ";
			}
			cout << endl;
		}
		else if (i == 1)
		{
			for (int i = S1; i <= t2; i++)
			{
				cout << Vs[i] << " ";
			}
			cout << endl;
		}
		else if (i == 2)
		{
			for (int i = S1+S2; i <= t3; i++)
			{
				cout << Vs[i] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	ThreeStack<int> Ss(9,3,3);
	Ss.Push(0, 100);
	Ss.Push(0, 200);
	Ss.Push(0, 300);

	Ss.Display(0);

	//Ss.Push(0, 111); //StackOverflow! Error

	Ss.Pop(0);

	Ss.Display(0);

	Ss.Push(1, 400);
	Ss.Push(1, 500);
	Ss.Push(1, 600);

	Ss.Display(1);

	//Ss.Push(1, 111); //StackOverflow! Error

	Ss.Pop(1);

	Ss.Display(1);
	
	Ss.Push(2, 700);
	Ss.Push(2, 800);
	Ss.Push(2, 900);

	Ss.Display(2);

	//Ss.Push(2, 111); //StackOverflow! Error

	Ss.Pop(2);

	Ss.Display(2);

	return 0;
}
