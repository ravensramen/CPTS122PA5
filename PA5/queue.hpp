#include "queuenode.hpp" //includes header

class queue {
public://includes enqueue and dequeue functions

	queue(); //queue constructor

	bool enqueue(Data newData); //input customer/node data before adding to list
	bool isEmpty() const; 

	void print_queue();

	queueNode getHead();

	//void incrementLane(); //subtract 1 from service time of head, add min to total time of all nodes
	
	Data dequeue();

	void incrementQueue();

	void initiateDequeue(int laneType); //check if head service time == 0, if so, dequeue head, retains data

private:

	queueNode* pHead;
	queueNode* pTail;
};