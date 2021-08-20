#include<iostream>
using namespace std;
#pragma once

template<class Q>
struct Node
{
	Q info;
	Node * next;

	Node<Q>()
	{
		next = nullptr;
	}
};

template<class T>
class LinkedList
{
private:
	Node<T>*head;

public:
	LinkedList<T>()
	{
		head = nullptr;
	}
	LinkedList<T>(const LinkedList<T> & obj)
	{
		this->head = obj.head;
	}
	void InserAtEnd(T value)
	{
		Node<T>* newnode = new Node<T>;
		newnode->info = value;
		newnode->next = nullptr;

		if (head == nullptr)
		{
			head = newnode;
		}
		else
		{
			Node<T> * temp = head;

			while (temp->next != nullptr)
			{
				temp = temp->next;
			}

			temp->next = newnode;
			newnode->next = nullptr;
		}
	}
	T deleteFromHead()
	{
		Node<T> * current = head;
		T val;

		val = head->info;
		head = head->next;
		delete current;
		current = nullptr;
		
		return val;
	}
	bool isEmpty() const
	{
		if (head == nullptr)
		{
			return true;
		}
		return false;
	}
	void print() const
	{
		Node<T> * current = head;

		while (current->next != nullptr)
		{
			cout << current->info << " ";
			current = current->next;
		}
		cout << current->info << endl;
	}
	Node<T> * get_head()
	{
		return head;
	}
	void set_head(Node<T> * temp)
	{
		head = temp;
	}
	~LinkedList()
	{
		Node<T> * temp = head;

		while(temp->next != nullptr)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
		delete temp;
		head = nullptr;
		temp = nullptr;
	}
};