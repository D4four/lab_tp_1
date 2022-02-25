#pragma once

using namespace std;

typedef struct tagITEM {
	int data = 0;
	tagITEM* prev = nullptr;
} ITEM;
class baseQueue {

private:

	ITEM* last = 0;

protected:

	int size;

public:

	baseQueue();
	~baseQueue();
	ITEM* getLast();
	int pop();
	void push(int el);
	void print();
	void merge(baseQueue& Q1);
	void copy(baseQueue& Q);
	bool isEmpty();
};