#include "queuenode.hpp" //includes header

class queue {
public://includes enqueue and dequeue functions

	queue(); //queue constructor

	bool enqueue(Data newData); //input customer/node data before adding to list

	
private:

	queueNode* pHead;
	queueNode* pTail;

	//
	int timeElapsed; //to keep track of custom generation time and line duration time
	int laneType; //either express or normal lane
};