#include<iostream>
using namespace std;

//Problem 1

struct Node
{
	int info;
	Node * next;

	Node()
	{
		next = nullptr;
	}
};

struct SLL
{
public:
	Node * head;
	Node * last;
	Node * newnode;

	SLL()
	{
		head = nullptr;
		last = nullptr;
	}
	~SLL()
	{
		if(head == nullptr)
		{
			head == nullptr;
			last = nullptr;
		}
		else
		{
			Node * temp = head;

			while (temp->next != nullptr)
			{
				head = head->next;
				delete temp;
				temp = head;
			}
			delete temp;

			head = nullptr;
			last = nullptr;
		}
	}
	void InsertElement(int value)
	{
		newnode = new Node();
		newnode->info = value;
		newnode->next = nullptr;

		if (head == nullptr && last == nullptr)
		{
			head = newnode;
			last = newnode;
		}
		else
		{
			last->next = newnode;
			last = newnode;
			last->next = nullptr;
		}
	}
	void Reverse(Node *temp)
	{
		if (temp->next == nullptr)
		{
			head = temp;
			return;
		}
		Reverse(temp->next);
		Node * current = temp->next;
		current->next = temp;
		temp->next = nullptr;
	}
	void Sort()
	{
		Node * current = head;

		while (current->next != nullptr)
		{
			Node * temp = current->next;

			while (temp->next != nullptr)
			{
				if (temp->info <= current->info)
				{
					int swap = current->info;
					current->info = temp->info;
					temp->info = swap;
				}
				temp = temp->next;
			}

			if (temp->info <= current->info)
			{
				int SWAP = current->info;
				current->info = temp->info;
				temp->info = SWAP;
			}

			current = current->next;
		}
	}
	Node * RemoveDuplicates(Node *current)
	{
		if (current == nullptr)
		{
			return nullptr;
		}

		current->next = RemoveDuplicates(current->next);

		if (current->next != nullptr && current->next->info == current->info)
		{
			Node * temp = current->next;
			delete current;
			return temp;
		}
		else
		{
			return current;
		}
	}
	int SizeOfLL(Node * HEAD)
	{
		Node * temp = HEAD;
		int size = 0;

		while (temp->next != nullptr)
		{
			size++;
			temp = temp->next;
		}
		size++;

		return size;
	}
	void Split_LinkedList()
	{
		Node * headLink1 = nullptr;
		Node * headLink2 = nullptr;
		Node * lastLink1 = nullptr;
		Node * lastLink2 = nullptr;

		int size = SizeOfLL(head);

		Node * traverse = head;

		for (int i = 0; i < size; i++)
		{
			if (i % 2 == 0)
			{
				newnode = new Node;
				newnode->info = traverse->info;
				newnode->next = nullptr;
				if (headLink1 == nullptr)
				{
					headLink1 = newnode;
					lastLink1 = newnode;
				}
				else
				{
					lastLink1->next = newnode;
					lastLink1 = newnode;
					lastLink1->next = nullptr;
				}
			}
			else
			{
				newnode = new Node;
				newnode->info = traverse->info;
				newnode->next = nullptr;
				if (headLink2 == nullptr)
				{
					headLink2 = newnode;
					lastLink2 = newnode;
				}
				else
				{
					lastLink2->next = newnode;
					lastLink2 = newnode;
					lastLink2->next = nullptr;
				}
			}
			traverse = traverse->next;
		}
		cout << "Original Link List : ";
		this->displayWithptr(head);
		cout << "LinkList 1 : ";
		this->displayWithptr(headLink1);
		cout << "LinkList 2 : ";
		this->displayWithptr(headLink2);
	}
	void display()
	{
		Node * current = head;

		while (current->next != nullptr)
		{
			cout << current->info << "->";
			current = current->next;
		}
		cout << current->info;
		cout << endl;
	}
	void displayWithptr(Node *start)
	{
		Node * temp = start;

		while (temp->next != nullptr)
		{
			cout << temp->info << "->";
			temp = temp->next;
		}
		cout << temp->info;
		cout << endl;
	}
};


//Problem 2

struct nodeType
{
	int info;
	nodeType * next;
	nodeType * prev;

	nodeType()
	{
		next = nullptr;
		prev = nullptr;
	}
};

struct DLL
{
public:
	nodeType * head;
	nodeType * last;
	nodeType * newnode;

	DLL()
	{
		head = nullptr;
		last = nullptr;
	}
	~DLL()
	{
		if (head == nullptr)
		{
			head == nullptr;
			last = nullptr;
		}
		else
		{
			nodeType * temp = head;

			while (temp->next != nullptr)
			{
				head = head->next;
				delete temp;
				temp = head;
			}
			delete temp;

			head = nullptr;
			last = nullptr;
		}
	}
	void InsertElement(int value)
	{
		newnode = new nodeType;
		newnode->info = value;
		newnode->prev = nullptr;
		newnode->next = nullptr;

		if (head == nullptr)
		{
			head = newnode;
			last = newnode;
		}
		else
		{
			last->next = newnode;
			newnode->prev = last;
			last = newnode;
			last->next = nullptr;
		}
	}
	void Reverse(nodeType *current)
	{
		nodeType * temp = current->next;
		current->next = current->prev;
		current->prev = temp;

		if (current->prev == nullptr)
		{
			head = current;
			return;
		}

		Reverse(current->prev);
	}
	void Sort()
	{
		nodeType * current = head;

		while (current->next != nullptr)
		{
			nodeType * temp = current->next;

			while (temp->next != nullptr)
			{
				if (temp->info <= current->info)
				{
					int swap = current->info;
					current->info = temp->info;
					temp->info = swap;
				}
				temp = temp->next;
			}

			if (temp->info <= current->info)
			{
				int SWAP = current->info;
				current->info = temp->info;
				temp->info = SWAP;
			}

			current = current->next;
		}
	}
	nodeType * RemoveDuplicates(nodeType *current)
	{
		if (current == nullptr)
		{
			return nullptr;
		}

		current->next = RemoveDuplicates(current->next);

		if (current->next != nullptr && current->next->info == current->info)
		{
			nodeType * temp = current->next;
			delete current;
			return temp;
		}
		else
		{
			return current;
		}
	}
	int SizeOfLL(nodeType * HEAD)
	{
		nodeType * temp = HEAD;
		int size = 0;

		while (temp->next != nullptr)
		{
			size++;
			temp = temp->next;
		}
		size++;

		return size;
	}
	void Split_LinkedList()
	{
		nodeType * headLink1 = nullptr;
		nodeType * headLink2 = nullptr;
		nodeType * lastLink1 = nullptr;
		nodeType * lastLink2 = nullptr;

		int size = SizeOfLL(head);

		nodeType * traverse = head;

		for (int i = 0; i < size; i++)
		{
			if (i % 2 == 0)
			{
				newnode = new nodeType;
				newnode->info = traverse->info;
				newnode->next = nullptr;
				newnode->prev = nullptr;

				if (headLink1 == nullptr)
				{
					headLink1 = newnode;
					lastLink1 = newnode;
				}
				else
				{
					lastLink1->next = newnode;
					newnode->prev = lastLink1;
					lastLink1 = newnode;
					lastLink1->next = nullptr;
				}
			}
			else
			{
				newnode = new nodeType;
				newnode->info = traverse->info;
				newnode->next = nullptr;
				newnode->prev = nullptr;

				if (headLink2 == nullptr)
				{
					headLink2 = newnode;
					lastLink2 = newnode;
				}
				else
				{
					lastLink2->next = newnode;
					newnode->prev = lastLink2;
					lastLink2 = newnode;
					lastLink2->next = nullptr;
				}
			}
			traverse = traverse->next;
		}
		cout << "Original Link List : ";
		this->DisplayWithptr(head);
		cout << "LinkList 1 : ";
		this->DisplayWithptr(headLink1);
		cout << "LinkList 2 : ";
		this->DisplayWithptr(headLink2);
	}
	void Display()
	{
		nodeType * temp = head;

		while (temp->next != nullptr)
		{
			cout << temp->info << "<->";
			temp = temp->next;
		}
		cout << temp->info;
		cout << endl;
	}
	void DisplayWithptr(nodeType *start)
	{
		nodeType * temp = start;

		while (temp->next != nullptr)
		{
			cout << temp->info << "<->";
			temp = temp->next;
		}
		cout << temp->info;
		cout << endl;
	}

};

//Selection Menu (main)

int main()
{
	int choice = 0;
	int value = 0;

	while (1)
	{
		system("cls");

		cout << "\*\*\*\* MENU \*\*\*\*" << endl;
		cout << "1. Singly Linked List" << endl;
		cout << "2. Doubly Linked List" << endl;
		cout << "3. EXIT!" << endl;
		cout << endl << "Enter your choice : ";
		cin >> choice;

		if (choice == 1)
		{
			SLL * sll;
			sll = new SLL;

			int check = 0;

			while (1)
			{
				system("cls");

				cout << "**Choose Your Operation**" << endl;
				cout << "1. Insert Data in LinkList!" << endl;
				cout << "2. Reverse Recursively!" << endl;
				cout << "3. Sort!" << endl;
				cout << "4. Remove Duplicates Recursively!" << endl;
				cout << "5. Split Linked List!" << endl;
				cout << "6. Back to MENU!" << endl;
				cout << endl << "Enter choice : ";
				cin >> choice;

				if (choice == 1)
				{
					system("cls");
					cout << "Enter value : ";
					cin >> value;

					sll->InsertElement(value);
					cout << endl << "Operation Successful!" << endl;

					sll->display();

					system("pause");
				}
				else if (choice == 2)
				{
					system("cls");
					sll->Reverse(sll->head);
					sll->display();
					system("pause");
				}
				else if (choice == 3)
				{
					system("cls");
					sll->Sort();
					sll->display();
					check = 1;
					system("pause");
				}
				else if (choice == 4)
				{
					if (check == 0)
					{
						sll->Sort();
						system("cls");
						Node * temp = sll->RemoveDuplicates(sll->head);
						sll->displayWithptr(temp);
						system("pause");
					}
					else
					{
						system("cls");
						Node * temp = sll->RemoveDuplicates(sll->head);
						sll->displayWithptr(temp);
						system("pause");
					}

				}
				else if (choice == 5)
				{
					system("cls");
					sll->Split_LinkedList();
					system("pause");
				}
				else if (choice == 6)
				{
					cout << "Opertions Reseted!" << endl;
					system("pause");
					break;
				}
			}

			delete sll;
		}
		else if (choice == 2)
		{
			DLL * dll;
			dll = new DLL;

			int check = 0;

			while (1)
			{
				system("cls");

				cout << "**Choose Your Operation**" << endl;
				cout << "1. Insert Data in LinkList!" << endl;
				cout << "2. Reverse Recursively!" << endl;
				cout << "3. Sort!" << endl;
				cout << "4. Remove Duplicates!" << endl;
				cout << "5. Split Linked List!" << endl;
				cout << "6. Back to MENU!" << endl;
				cout << endl << "Enter choice : ";
				cin >> choice;

				if (choice == 1)
				{
					system("cls");

					cout << "Enter value : ";
					cin >> value;

					dll->InsertElement(value);

					cout << endl << "Operation Successful!" << endl;
					dll->Display();

					system("pause");
				}
				else if (choice == 2)
				{
					system("cls");
					dll->Reverse(dll->head);
					dll->Display();
					system("pause");
				}
				else if (choice == 3)
				{
					system("cls");
					dll->Sort();
					dll->Display();
					check = 1;
					system("pause");
				}
				else if (choice == 4)
				{
					if (check == 0)
					{
						dll->Sort();
						system("cls");
						nodeType * temp = dll->RemoveDuplicates(dll->head);
						dll->DisplayWithptr(temp);
						system("pause");
					}
					else
					{
						system("cls");
						nodeType * temp = dll->RemoveDuplicates(dll->head);
						dll->DisplayWithptr(temp);
						system("pause");
					}
				}
				else if (choice == 5)
				{
					system("cls");
					dll->Split_LinkedList();
					system("pause");
				}
				else if (choice == 6)
				{
					cout << "Opertions Reseted!" << endl;
					system("pause");
					break;
				}
			}
			
			delete dll;
		}
		else if (choice == 3)
		{
			system("cls");
			cout << "Programme Terminated!" << endl;
			cout << "Thank You!" << endl;
			break;
			system("pause");
		}
		else
		{
			cout << "Invalid Option" << endl;
			system("pause");
		}
	}

	return 0;
}
