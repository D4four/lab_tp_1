#include <iostream>
#include "queue1.h"

int childQueuePrivate::pop() { return baseQueue::pop(); }
void childQueuePrivate::push(int el) { return baseQueue::push(el); }
void childQueuePrivate::print() { return baseQueue::print(); }
void childQueuePrivate::merge(childQueuePrivate& mergeQueue) { return baseQueue::merge(mergeQueue);}
void childQueuePrivate::copy(childQueuePrivate& mergeQueue) { return baseQueue::copy(mergeQueue); }
bool childQueuePrivate::isEmpty() { return baseQueue::isEmpty(); }
int childQueuePrivate::fun() { 
	ITEM* last = this->getLast();
	int min = last->data;
	int result = 0;
	int sum = 0;

	if (size == 0)
	{
		cout << "Очередь пуста!" << endl;
	}
	else
	{
		while (last->prev != nullptr) {
			sum += last->data;
			last = last->prev;
		}

		sum /= size;
		last = this->getLast();

		while (last->prev != nullptr) {
			if (last->data < sum) {
				result = last->data;
				break;
			}
			else {
				last = last->prev;
			}


		}
	}
	return result;
}

int childQueueProtected::pop() { return baseQueue::pop(); }
void childQueueProtected::push(int el) { return baseQueue::push(el); }
void childQueueProtected::print() { return baseQueue::print(); }
void childQueueProtected::merge(childQueueProtected& mergeQueue) { return baseQueue::merge(mergeQueue); }
void childQueueProtected::copy(childQueueProtected& mergeQueue) { return baseQueue::copy(mergeQueue); }
bool childQueueProtected::isEmpty() { return baseQueue::isEmpty(); }
int childQueueProtected::fun() {
	ITEM* last = this->getLast();
	int min = last->data;
	int result = 0;
	int sum = 0;

	if (size == 0)
	{
		cout << "Очередь пуста!" << endl;
	}
	else
	{
		while (last->prev != nullptr) {
			sum += last->data;
			last = last->prev;
		}

		sum /= size;
		last = this->getLast();

		while (last->prev != nullptr) {
			if (last->data < sum) {
				result = last->data;
				break;
			}
			else {
				last = last->prev;
			}


		}
	}
	return result;
}

int childQueuePublic::fun() {
	ITEM* last = this->getLast();
	int min = last->data;
	int result = 0;
	int sum = 0;

	if (size == 0)
	{
		cout << "Очередь пуста!" << endl;
	}
	else
	{
		while (last->prev != nullptr) {
			sum += last->data;
			last = last->prev;
		}

		sum /= size;
		last = this->getLast();

		while (last->prev != nullptr) {
			if (last->data < sum) {
				result = last->data;
				break;
			}
			else {
				last = last->prev;
			}


		}
	}
	return result;
}