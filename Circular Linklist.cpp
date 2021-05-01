#include <iostream>
using namespace std;

class node{
	private:
		int data;
		node* next;
		node* prev;
	public:
		void set_data(int data)
	{
		this->data = data;
	}
	void set_next(node* next)
	{
		this->next = next;
	}
	void set_prev(node* prev)
	{
		this->prev = prev;
	}
	int get_data()
	{
		return this->data;
	}
	node* get_next()
	{
		return this->next;
	}
	node* get_prev()
	{
		return this->prev;
	}
};
class Circular_linked_list{
	private:
		int size;
		node* current;
	public:
		Circular_linked_list()
		{
			this->current = nullptr;
			this->size = 0;
		}
		~Circular_linked_list()
		{
			node* temp = this->current;
			for (int i = 0; i < this->size; i++)
			{
				current = current->get_next();
				delete temp;
				temp = current;
			}
			this->current = nullptr;
			this->size = 0;
		}
		int getsize()
		{
			return this->size;
		}
		void setsize(int m)
		{
			this->size = m;
		}
		node* getcurrent()
		{
			return this->current;
		}
		void setcurrent(node* p)
		{
			this->current = p;
		}
		void push(int data)
		{
			if (size == 0)
			{
				node* newnode = new node;
				newnode->set_data(data);
				newnode->set_next(nullptr);
				newnode->set_prev(nullptr);
				current = newnode;
				size++;
				return;
			}
			if (size == 1)
			{
				node* newnode = new node;
				newnode->set_data(data);
				newnode->set_next(current);
				newnode->set_prev(current);
				current->set_next(newnode);
				current->set_prev(newnode);
				current = newnode;
				size++;
				return;
			}
			node* newnode = new node;
			newnode->set_data(data);
			newnode->set_prev(current);
			newnode->set_next(current->get_next());
			current->get_next()->set_prev(newnode);
			current->set_next(newnode);
			current = newnode;
			size++;
		}
		void pop();
		void pop(int data)
		{
			int i = 0;
			for (i = 0; i < this->size; i++)
			{
				if (current->get_data() != data)
					current = current->get_next();
				else break;
			}
			if (i == size) return;
			pop();
		}
		void push_after(int new_data, int pa_data)
		{
			int i;
			for (i = 0; i < this->size; i++)
			{
				if (current->get_data() != pa_data)
					current = current->get_next();
				else break;
			}
			if (i == size) return;
			push(new_data);
		}
		void push_before(int new_data, int pb_data)
		{
			node* newnode = new node;
			newnode->set_data(new_data);
			if (this->getsize() == 0)
			{
				push(new_data);
				return;
			}
			if ((this->size) == 1)
			{
				current->set_prev(newnode);
				newnode->set_next(current);
				newnode->set_prev(current);
				current->set_next(newnode);
				current = newnode;
				this->size++;
				return;
			}
			else
			{
				while (current)
				{
					if (current->get_data() == pb_data)
					{
						newnode->set_prev(current->get_prev());
						current->get_prev()->set_next(newnode);
						current->set_prev(newnode);
						newnode->set_next(current);
						current = newnode;
						break;
					}
					current = current->get_next();
				}
				this->size++;
			}
			return;
		}
		void print()
		{
			int i = 0;
			if ((this->size) == 1)
			{
				cout << current->get_data();
			}
			else
				while (i != (this->size))
				{
					cout << current->get_data() << " ";
					current = current->get_next();
					i++;
				}
		}
}



int main(){



}