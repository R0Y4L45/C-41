#pragma once

template<class T = Wagon>
class DLL
{
public:

	struct Node
	{
		T data;
		Node* prev;
		Node* next;

		Node(T data = "") : data(data), prev(), next() {}
	};


	// O(1)
	void push_back(T data)
	{
		push_back(new Node(data));
	}

	void push_back(Node* node)
	{
		if (_head == NULL)
		{
			_head = node;
			_tail = node;
			return;
		}

		_tail->next = node;
		node->prev = _tail;

		_tail = node;
	}



	void pop_front()
	{
		if (_head == NULL)
			return;

		if (_head->next == NULL)
		{
			delete _head;
			_head = NULL;
			_tail = NULL;
			return;
		}

		_head = _head->next;

		delete _head->prev;
		_head->prev = NULL;
	}

	void pop_back()
	{
		if (_head == NULL)
			return;

		if (_head->next == NULL)
		{
			delete _head;
			_head = NULL;
			_tail = NULL;
			return;
		}


		_tail = _tail->prev;
		delete _tail->next;
		_tail->next = NULL;
	}


	void delete_byId(int id) // id-ye gore silme aparir
	{
		Node* n = search(id);
		if (n != NULL)
		{
			if (n->prev != NULL && n->next != NULL)
			{
				n->prev->next = n->next;
				n->next->prev = n->prev;
				delete n;				
			}
			else if (n->prev == NULL && n-> next == NULL)
			{
				_head = NULL;
				_tail = NULL;
				delete n;
			}
			else if (n->prev == NULL)
			{
				n->next->prev = NULL;
				_head = n->next;
				delete n;
			}
			else if (n->next == NULL)
			{
				n->prev->next = NULL;
				_tail = n->prev;
				delete n;
			}
				
			n = NULL;
		}
		else
			cout << "There is no such id Wagon....\n";
	}



////////////////////////////////////////////////////////////////////
// O(N) // axtaris methodlari

	Node* search(T data)
	{
		auto n = _head;

		while (n != NULL)
		{
			if (n->data.id == data.id)
				return n;

			n = n->next;
		}

		return NULL;
	}


	Node* search(int id)
	{
		auto n = _head;

		while (n != NULL)
		{
			if (n->data.id == id)
				return n;

			n = n->next;
		}

		return NULL;
	}

////////////////////////////////////////////////

	const Node* head() const { return _head; }
	const Node* tail() const { return _tail; }



	int getSize() // vaqonlarin sayini qaytarir
	{
		Node* n = _head;

		while (n != NULL)
		{
			cout << n->data << endl;
			size++;
			n = n->prev;
		}
		return size;
	}



private:
	int size = 0;
	Node* _head = NULL;
	Node* _tail = NULL;
};







