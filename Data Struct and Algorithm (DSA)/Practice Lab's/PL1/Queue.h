#include"LinkedList.h"
#pragma once

template<class T>
class Queue
{
private:
	LinkedList<T> list;
	int currentsize;

public:
	Queue<T>()
	{
		currentsize = 0;
	}
	Queue<T>(const Queue<T> & obj)
	{
		this->list = obj.list;
		this->currentsize = obj.currentsize;
	}
	void enqueue(T value)
	{
		list.InserAtEnd(value);
		currentsize++;
	}
	T dequeue()
	{
		T var;
		var = list.deleteFromHead();
		currentsize--;
		
		return var;
	}
	void display()const
	{
		list.print();
	}
	int size()const
	{
		int temp = currentsize;
		return temp;
	}
	Node<T>* get_list_head()
	{
		Node<T>* temphead = list.get_head();
		return temphead;
	}
	void set_list_head(Node<T> * start)
	{
		this->list.set_head(start);
		return;
	}
	/*Queue<T> operator = (Queue<T> &obj)
	{
		Queue<T> newObj;
		newObj.list.set_head(obj.get_list_head());
		
		return newObj;
	}*/
	~Queue()
	{
		currentsize = 0;
	}
};