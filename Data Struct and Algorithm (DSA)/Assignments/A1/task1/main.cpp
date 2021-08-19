#include<iostream>
using namespace std;

class Stack
{
private:
	char *arr;
	int size;
	int top;

public:
	Stack()
	{
		arr = nullptr;
		size = 0;
		top = -1;
	}
	Stack(int size)
	{
		arr = new char[size];
		this->size = size;
		top = -1;
	}
	~Stack()
	{
		delete[]arr;
		top = -1;
	}
	bool isFull()
	{
		if (top == size - 1)
		{
			return true;
		}
		return false;
	}
	void Push(char value)
	{
		if (!isFull())
		{
			top++;
			arr[top] = value;
		}
		else
		{
			cout << "Stack Overflow!" << endl;
		}
	}
	void Pop()
	{
		if (!isEmpty())
		{
			top--;
		}
	}
	char Top()
	{
		if (!isEmpty())
		{
			return arr[top];
		}
	}
	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		return false;
	}
	bool checkBalancedParan(char exp[],int SIZE)
	{
		char var;

		for (int i = 0; i < SIZE; i++)
		{
			if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			{
				Push(exp[i]);
				continue;
			}

			if (isEmpty())
			{
				return false;
			}
			else
			{
				if (exp[i] == ')')
				{
					var = Top();
					Pop();
					if (var == '{' || var == '[')
					{
						return false;
					}
				}
				else if (exp[i] == '}')
				{
					var = Top();
					Pop();
					if (var == '(' || var == '[')
					{
						return false;
					}
				}
				else if (exp[i] == ']')
				{
					var = Top();
					Pop();
					if (var == '(' || var == '{')
					{
						return false;
					}
				}
			}
		}

		if (isEmpty())
		{
			return true;
		}
	}
};

int sizeOfArr(char arr[])
{
	int size = 0;

	for (int i = 0; arr[i] != '\0'; i++)
	{
		size++;
	}

	return size;
}


int main()
{
	char exp[] = "{()}[]";
	int size = sizeOfArr(exp);

	Stack stk(size);

	if (stk.checkBalancedParan(exp, size) == true)
	{
		cout << "Balanced!" << endl;
	}
	else
	{
		cout << "Not Balanced!" << endl;
	}

	return 0;
}
