#include"Queue.h"

//Ignore all the Commented Codes , they were added by me while creating the solution to check the flow of the running program.

template<class T>
void reverseQueue(Queue<T> &obj)
{
	Node<T>* prev = nullptr;
	Node<T>* current = obj.get_list_head();
	Node<T>* NEXT = nullptr;

	while (current != nullptr)
	{
		NEXT = current->next;
		current->next = prev;
		prev = current;
		current = NEXT;
	}
	obj.set_list_head(prev);

	return;
}

int main()
{
	/*LinkedList<char> list;

	list.InserAtEnd('A');
	list.InserAtEnd('B');
	list.InserAtEnd('C');

	list.print();
	cout << endl;

	cout << "Delete from Front : " << list.deleteFromHead() << endl;*/

	cout << "\n\n---------- Best of Luck for the Exam ---------\n\n";
	Queue<char> q1;
	q1.enqueue('D');
	q1.enqueue('S');
	q1.enqueue('A');
	q1.enqueue(' ');
	q1.enqueue('L');
	q1.enqueue('A');
	q1.enqueue('B');
	q1.display();

	reverseQueue(q1);
	q1.display();

	cout << endl << "Size : " << q1.size() << endl;

	/*Queue<char> reverseQ1;
	reverseQ1=reverseQueue(q1);
	reverseQ1.display();*/


	return 0;
}
