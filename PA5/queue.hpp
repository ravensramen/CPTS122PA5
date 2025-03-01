#include "queuenode.hpp" //includes header

class queue {
public://includes enqueue and dequeue functions

	queue(); //queue constructor

	bool enqueue(Data newData); //input customer/node data before adding to list
	bool isEmpty() const; 

	void print_queue();

	
private:

	queueNode* pHead;
	queueNode* pTail;
};