#include<iostream>
using namespace std;

//Ignore the commented Code/Section , it was written by to understand the flow of my program.

template<typename T>
class Stack
{
private:
	T * arr;
	int top;
	int size;

public:
	Stack()
	{
		arr = nullptr;
		top = -1;
		size = 0;
	}
	Stack(int size)
	{
		arr = new T[size];
		this->size = size;
		top = -1;
	}
	~Stack()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = nullptr; // each pointers who was pointing to the Node of the tree is NULL now.
		}
		delete[]arr; // deleting the array of pointers to act as a stack.
	}
	void push(T node)
	{
		top++;
		arr[top] = node;
	}
	void pop()
	{
		top--;
	}
	T Top()
	{
		return arr[top];
	}
	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isFull()
	{
		if (top == size - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


template<typename k, typename v>
class TNode
{
private:
	k key;
	v value;
	TNode <k, v>* leftChild;
	TNode <k, v>* rightChild;
	TNode <k, v>* root;

	int CalLength(TNode <k, v> * start)
	{
		if (start == nullptr)
		{
			return 0;
		}
		else
		{
			return (CalLength(start->get_leftChild()) + 1 + CalLength(start->get_rightChild()));
		}
	}

public:
	TNode()
	{
		key = -1;
		value = -1;
		leftChild = nullptr;
		rightChild = nullptr;
		root = nullptr;
	}
	TNode(k key, v value)
	{
		this->key = key;
		this->value = value;
		leftChild = nullptr;
		rightChild = nullptr;
		root = nullptr;
	}
	void insert(k const key, v const value)
	{
		if (root == nullptr)
		{
			root = new TNode<k, v>(key, value);
			cout << root->get_key() << "-->";
			return;
		}
		else
		{
			TNode<k, v> * prev = root;
			TNode<k, v> * next = root;

			while (key != prev->get_key() && next != nullptr)
			{
				prev = next;

				if (key < prev->get_key())
				{
					next = prev->get_leftChild();
				}
				else if (key > prev->get_key())
				{
					next = prev->get_rightChild();
				}
			}

			if (key == prev->get_key())
			{
				prev->set_value(value);
				return;
			}
			else if (key < prev->get_key() && next == nullptr)
			{
				prev->leftChild = new TNode<k, v>(key, value);
				cout << prev->leftChild->get_key() << " ";
				return;
			}
			else if (key > prev->get_key() && next == nullptr)
			{
				prev->rightChild = new TNode<k, v>(key, value);
				cout << prev->rightChild->get_key() << " ";
				return;
			}
		}
	}
	void deleteNode(k key)
	{
		int size = this->length();

		TNode<k, v> * temp = nullptr;

		TNode<k, v> * prev = root;
		TNode<k, v> * next = root;

		Stack<TNode<k, v> *> *stk = nullptr;
		stk = new Stack<TNode<k, v>*>(size);

		while (key != next->get_key())
		{
			prev = next;

			if (key < prev->get_key())
			{
				next = prev->get_leftChild();
				stk->push(prev);
			}
			else if (key > prev->get_key())
			{
				next = prev->get_rightChild();
				stk->push(prev);
			}
		}

		if (key == next->get_key() && next->leftChild == nullptr && next->rightChild == nullptr)
		{
			if (key == this->root->get_key())
			{
				temp = next;
				delete temp;
				this->root = nullptr;

				cout << "Root Node Deleted!" << endl;
				return;
			}
			else if (prev->leftChild->get_key() == key)
			{
				prev->leftChild = nullptr;
				temp = next;
				delete temp;

				this->inorderPrintKeys();
				return;
			}
			else if (prev->rightChild->get_key() == key)
			{
				prev->rightChild = nullptr;
				temp = next;
				delete temp;

				this->inorderPrintKeys();
				return;
			}
		}
		else if (key == next->get_key() && next->leftChild != nullptr && next->rightChild == nullptr)
		{
			if (key == this->root->get_key())
			{
				this->root->set_key(this->root->leftChild->get_key());
				temp = this->root->leftChild;
				delete temp;
				root->leftChild = nullptr;

				return;
			}
			else
			{
				TNode<k, v> * grandfather = stk->Top();
				stk->pop();

				if (grandfather->leftChild->get_key() == next->get_key())
				{
					if (next->leftChild != nullptr && next->rightChild == nullptr)
					{
						grandfather->set_leftChild(next->leftChild);
						temp = next;
						delete temp;
						next = nullptr;
						temp = nullptr;

						this->inorderPrintKeys();
						return;
					}
					else if (next->rightChild != nullptr && next->leftChild == nullptr)
					{
						grandfather->set_leftChild(next->rightChild);
						temp = next;
						delete temp;
						next = nullptr;
						temp = nullptr;

						this->inorderPrintKeys();
						return;
					}
				}
				else if (grandfather->rightChild->get_key() == next->get_key())
				{
					if (next->rightChild != nullptr && next->leftChild == nullptr)
					{
						grandfather->set_rightChild(next->rightChild);
						temp = next;
						delete temp;
						next = nullptr;
						temp = nullptr;

						this->inorderPrintKeys();
						return;
					}
					else if (next->leftChild != nullptr && next->rightChild == nullptr)
					{
						grandfather->set_rightChild(next->leftChild);
						temp = next;
						delete temp;
						next = nullptr;
						temp = nullptr;

						this->inorderPrintKeys();
						return;
					}
				}
			}
		}
		else if (key == next->get_key() && next->rightChild != nullptr && next->leftChild == nullptr)
		{
			if (key == this->root->get_key())
			{
				this->root->set_key(this->root->rightChild->get_key());
				temp = this->root->rightChild;
				delete temp;
				root->rightChild = nullptr;

				return;
			}
			else
			{
				TNode<k, v> * grandfather = stk->Top();
				stk->pop();

				if (grandfather->leftChild->get_key() == next->get_key())
				{
					if (next->leftChild != nullptr && next->rightChild == nullptr)
					{
						grandfather->set_leftChild(next->leftChild);
						temp = next;
						delete temp;
						next = nullptr;
						temp = nullptr;

						this->inorderPrintKeys();
						return;
					}
					else if (next->rightChild != nullptr && next->leftChild == nullptr)
					{
						grandfather->set_leftChild(next->rightChild);
						temp = next;
						delete temp;
						next = nullptr;
						temp = nullptr;

						this->inorderPrintKeys();
						return;
					}
				}
				else if (grandfather->rightChild->get_key() == next->get_key())
				{
					if (next->rightChild != nullptr && next->leftChild == nullptr)
					{
						grandfather->set_rightChild(next->rightChild);
						temp = next;
						delete temp;
						next = nullptr;
						temp = nullptr;

						this->inorderPrintKeys();
						return;
					}
					else if (next->leftChild != nullptr && next->rightChild == nullptr)
					{
						grandfather->set_rightChild(next->leftChild);
						temp = next;
						delete temp;
						next = nullptr;
						temp = nullptr;

						this->inorderPrintKeys();
						return;
					}
				}
			}
		}
		else if (key == next->get_key() && next->leftChild != nullptr && next->rightChild != nullptr)
		{
			TNode<k, v> * searchedNode = next;

			next = next->rightChild;

			if (next->leftChild == nullptr)
			{
				cout << "Can't DELETE ROOT Node due to no smallest value in Right Subtree!" << endl;
				return;
			}
			else
			{
				while (next != nullptr)
				{
					prev = next;
					stk->push(prev);
					next = next->leftChild;
				}

				if (next == nullptr && prev->rightChild != nullptr)
				{
					if (searchedNode->get_key() == this->root->get_key())
					{
						this->root->set_key(prev->get_key());
					}
					else
					{
						searchedNode->set_key(prev->get_key());
					}

					stk->pop();
					TNode<k, v> * grandfather = stk->Top();
					stk->pop();

					grandfather->set_leftChild(prev->rightChild);
					temp = prev;
					delete temp;

					this->inorderPrintKeys();
					return;
				}

				stk->pop();
				TNode<k, v> * current = stk->Top();
				stk->pop();

				if (next == nullptr && current->leftChild != nullptr)
				{
					if (searchedNode->get_key() == this->root->get_key())
					{
						this->root->set_key(prev->get_key());
					}
					else
					{
						searchedNode->set_key(prev->get_key());
					}

					temp = prev;
					delete temp;
					current->leftChild = nullptr;

					this->inorderPrintKeys();
					return;
				}
			}
		}

		delete stk;
	}
	void inorderPrintKeys()
	{
		int size = this->length();

		Stack<TNode<k, v> *> stk(size);

		TNode<k, v> * current = this->root;

		while (current != nullptr || !stk.isEmpty())
		{
			while (current != nullptr)
			{
				stk.push(current);
				current = current->get_leftChild();
			}

			current = stk.Top();
			stk.pop();

			cout << current->get_key() << "-->";

			current = current->get_rightChild();
		}
		cout << "Stack is Empty!" << endl;
	}
	int length()
	{
		int totalNodes = CalLength(root);

		return totalNodes;
	}
	void set_key(k key)
	{
		this->key = key;
	}
	k get_key()
	{
		return key;
	}
	void set_value(v value)
	{
		this->value = value;
	}
	v get_value()
	{
		return value;
	}
	void set_rightChild(TNode<k, v> *rightC)
	{
		this->rightChild = rightC;
	}
	TNode* get_rightChild()
	{
		return this->rightChild;
	}
	void set_leftChild(TNode<k, v> * leftC)
	{
		this->leftChild = leftC;
	}
	TNode* get_leftChild()
	{
		return this->leftChild;
	}
	TNode* get_root()
	{
		return this->root;
	}
};

int main()
{
	cout << "\\\\\\\\\\Tree to test DELETION/////////" << endl << endl;

	TNode<int, int> tree2;

	cout << "Inserted Values in Tree : ";
	tree2.insert(25, 25);
	tree2.insert(10, 10);
	tree2.insert(35, 35);
	tree2.insert(5, 5);
	tree2.insert(20, 20);
	tree2.insert(40, 40);
	tree2.insert(3, 3);
	tree2.insert(6, 6);
	tree2.insert(15, 15);
	tree2.insert(21, 21);
	tree2.insert(37, 37);
	tree2.insert(16, 16);
	tree2.insert(13, 13);

	/*tree2.insert(50, 50);
	tree2.insert(30, 30);
	tree2.insert(20, 20);
	tree2.insert(40, 40);
	tree2.insert(70, 70);
	tree2.insert(60, 60);
	tree2.insert(80, 80);*/

	cout << endl << endl;

	cout << "Tree InOrder Print (Ascending) : ";
	tree2.inorderPrintKeys();

	cout << endl << "After delete of Node (37) : ";
	tree2.deleteNode(37);

	TNode<int, int> * rootValue = tree2.get_root();

	//cout << endl << "After delete of Node (20) : ";
	//tree2.deleteNode(20);

	cout << "Root Value : " << rootValue->get_key();

	cout << endl << "After delete of Node (35) : ";
	tree2.deleteNode(35);

	//cout << endl << endl << "After delete of Node (30) : ";
	//tree2.deleteNode(30);

	cout << "Root Value : " << rootValue->get_key();

	cout << endl << "After delete of Node (10) : ";
	tree2.deleteNode(10);

	//cout << endl << endl << "After delete of Node (50) : ";
	//tree2.deleteNode(50);

	//TNode<int, int> * rootValue = tree2.get_root();
	cout << "Root Value : " << rootValue->get_key();
	cout << endl << endl;

	cout << endl << "After delete of Node (25) : ";
	tree2.deleteNode(25);

	//cout << endl << endl << "After delete of Node (50) : ";
	//tree2.deleteNode(50);

	cout << "Root Value : " << rootValue->get_key();
	cout << endl << endl << endl;

	cout << "Inserted (30) to show the working of Deletion of ROOT Node (if there is smallest element in Right Subtree)" << endl;
	tree2.insert(30, 30);
	cout << endl << endl;
	tree2.inorderPrintKeys();

	cout << endl << "After delete of Node (25) : ";
	tree2.deleteNode(25);

	cout << "Root Value : " << rootValue->get_key();
	cout << endl << endl;

	return 0;
}
