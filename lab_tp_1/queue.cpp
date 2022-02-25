#include <iostream>
#include "queue.h"

using namespace std;

baseQueue::baseQueue() {size = 0;last = nullptr;}

baseQueue::~baseQueue() {
	while (size > 0) {
		ITEM* temp = last; 
		last = temp->prev;
		delete temp;
		size--;
	}
}
ITEM* baseQueue::getLast(){return last;}
int baseQueue::pop(){
	ITEM* tmp = last;
	int deldata = 0;
	
	if (tmp->prev == nullptr){
		deldata = tmp->data;
		delete last; 
		last = nullptr; 
		size--; 
	}
	else {	while (tmp->prev->prev != nullptr) {tmp = tmp->prev;}

		deldata = tmp->prev->data;
		delete tmp->prev;
		tmp->prev = nullptr;
		size--;
	}
	return deldata;
}

void baseQueue::push(int el){

	ITEM* new_ITEM = new ITEM; 
	new_ITEM->prev = last; 
	last = new_ITEM; 
	last->data = el;
	size++;
}

void baseQueue::print(){

	ITEM* tmp = last;
	while (tmp->prev != nullptr){

		cout << tmp->data << " --> "; 
		tmp = tmp->prev;
	}
	cout << tmp->data << endl; 
}
void baseQueue::copy(baseQueue& Q) {

	int* buff = new int[Q.size]; 
	ITEM* el_queue = Q.last; 

	for (int i = Q.size - 1; i >= 0; i--) {
		buff[i] = el_queue->data; 
		el_queue = el_queue->prev; 
	}

	for (int i = 0; i < Q.size; i++){this->push(buff[i]);}

	delete[] buff;
}

void baseQueue::merge(baseQueue& Q1) {

	int* buff1 = new int[Q1.size];
	ITEM* el_queue1 = Q1.last;

	for (int i = Q1.size - 1; i >= 0; i--){
		buff1[i] = el_queue1->data;
		el_queue1 = el_queue1->prev;
	}

	for (int i = 0; i < Q1.size; i++)
	{
		this->push(buff1[i]);
	}

	delete[] buff1;
	cout << "Слияние успешно завершено!" << endl;

}

bool baseQueue::isEmpty() { return (size == 0 ? true : false); }

