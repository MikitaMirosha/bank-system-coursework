#pragma once
#include <iostream>
#include <iomanip>
#include "Deposit.h"
#include "MoneyTransfer.h"
using namespace std;

// узел для контейнера список
template<typename T>
struct Node
{
	T data;
	Node<T> *next;
	Node<T> *prev;
};

// класс итератора
template <typename T>
class Iterator
{
	Node<T> *current;
public:
	Iterator()
	{
		current = nullptr;
	}
	Iterator(Iterator<T> &iter)
	{
		current = iter.current;
	}
	Iterator(Node<T> *node)
	{
		current = node;
	}
	~Iterator() {}

	// получение узла из итератора
	Node<T> *get_node()
	{
		return current;
	}

	// сдвиг итератора
	bool operator++(int i)
	{
		if (current == nullptr) return false;
		current = current->next;
		return true;
	}

	bool operator--(int i)
	{
		if (current->prev == nullptr) return false;
		current = current->prev;
		return true;
	}

	// получение значения из итератора
	T &operator*()
	{
		return current->data;
	}

	// операторы сравнения для итератора
	bool operator==(Iterator &iter)
	{
		if (current == nullptr && iter.current == nullptr)
			return true;
		if (current == nullptr || iter.current == nullptr)
			return false;
		return current->data == iter.current->data && current->next == iter.current->next &&
			current->prev == iter.current->prev;
	}

	bool operator!=(Iterator &iter)
	{
		if (current == nullptr && iter.current == nullptr)
			return false;
		if ((current == nullptr && iter.current != nullptr) || (current != nullptr && iter.current == nullptr))
			return true;
		return !(current->data == iter.current->data && current->next == iter.current->next &&
			current->prev == iter.current->prev);
	}
};

// класс-контейнер cписок
template<typename T>
class List
{
protected:
	friend class Iterator<T>;
	Node<T> *head;
	Node<T> *tail;
	long amount;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
		amount = 0;
	}
	~List()
	{
		while (head)
		{
			this->pop_head();
		}
	}

	// длина списка
	long size()
	{
		return this->amount;
	}

	// добавление с головы
	void push_head(T input_object)
	{
		if (head == nullptr)
		{
			head = new Node<T>;
			head->data = input_object;
			head->next = nullptr;
			head->prev = nullptr;
			tail = head;
			amount++;
			return;
		}
		Node<T> *node = new Node<T>;
		node->data = input_object;
		node->next = head;
		node->prev = nullptr;
		head->prev = node;
		head = node;
		amount++;
		return;
	}

	// добавление в хвост
	void push_tail(T input_object)
	{
		if (head == nullptr)
		{
			head = new Node<T>;
			head->data = input_object;
			head->next = nullptr;
			head->prev = nullptr;
			tail = head;
			amount++;
			return;
		}
		else 
		{
			Node<T> *node = new Node<T>;
			node->data = input_object;
			node->next = nullptr;
			node->prev = tail;
			tail->next = node;
			tail = node;
			amount++;
			return;
		}
	}

	// удаление из головы
	T pop_head()
	{
		if (!(head)) return T();
		T data = head->data;
		Node<T> *node = head;
		head = head->next;
		if (head)
			head->prev = nullptr;
		delete node;
		amount--;
		return data;
	}

	// удаление из хвоста
	T pop_tail()
	{
		if (!(head)) return T();
		T data = tail->data;
		Node<T> *node = tail;
		if (tail != head) {
			tail = tail->prev;
			tail->next = nullptr;
		}
		else {
			head = tail = nullptr;
		}
		delete node;
		amount--;
		return data;
	}

	T pop(int num)
	{
		T data = this->operator[](num);
		Node<T> *curr = head;
		for (long i = 0; i < num; i++)
			curr = curr->next;
		Node<T> *next = curr->next;
		Node<T> *prev = curr->prev;
		next->prev = prev;
		prev->next = next;
		delete curr;
		amount--;
		return data;
	}

	// произвольный доступ к объектам
	T &operator[](long num)
	{
		Node<T> *curr = head;
		if (num < 0 || num >= amount) return curr->data;
		for (long i = 0; i < num; i++)
			curr = curr->next;
		return curr->data;
	}

	// функции для работы с итератором
	Node<T> *begin()
	{
		return head;
	}
	Node<T> *end()
	{
		if (tail != nullptr) return tail->next;
		return tail;
	}

	// вывод на экран содержимого списка
	void output()
	{
		cout << "-------------------------------" << endl;
		cout << setw(3) << "#" << setw(15) << "Аккаунт" << setw(12) << "Сумма" << endl;
		int i = 0;
		if (!head) cout << "Список пуст!";
		else
		for (Node<T> *node = head; node != nullptr; node = node->next)
		{
			cout << "-------------------------------" << endl;
			cout << setw(3) << i + 1 << node->data;
			cout << endl;
			i++;
		}
		cout << "-------------------------------" << endl;
		cout << endl;
	}

	// вывод на экран информации о займах
	void output_loans()
	{
		cout << "-------------------------------" << endl;
		cout << setw(3) << "#" << setw(12) << "Сумма" << endl;
		int i = 0;
		if (!head) cout << "Список пуст!";
		else
		for (Node<T> *node = head; node != nullptr; node = node->next)
		{
			cout << "-------------------------------" << endl;
			cout << setw(3) << i + 1 << "          " << node->data;
			cout << endl;
			i++;
		}
		cout << "-------------------------------" << endl;
		cout << endl;
	}

	// геттер на пользователя
	Account getUser(const string& username)
	{
		for (int i = 0; i < amount; i++) 
		{
			if (this->operator[](i).getUsername() == username) 
			{
				return this->operator[](i);
			}
		}
		Account user(username, 0);
		this->push_tail(user);
		string file = username + ".txt";
		ofstream of(file);
		of.close();
		return user;
	}
};