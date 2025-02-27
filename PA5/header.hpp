//main header, include libraries, macros and preprocessor directives

//includes definition for basic structure of each grocery line queue

#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;


class Data
{
public: 
	Data(); //constructor
	~Data(); //destructor
	//setters + getters?

private:

	int customerNumber;
	int serviceTime;
	int totalTime;
};

Data::Data() {
	//constructor def
}
Data::~Data() {
	//destructor def
}

class QueueNode {
public:
	QueueNode();
	~QueueNode();
private:
	Data* pData;
	QueueNode* pNext;

};

QueueNode::QueueNode(){
	//constructor
}

QueueNode::~QueueNode() {
	//destructor
}

class Queue {

public:
	Queue();
	~Queue();

private: 
	QueueNode* pHead;
	QueueNode* pTail;

};

Queue::Queue(){
	//constructor
}
Queue::~Queue() {
	//destructor
}

#endif