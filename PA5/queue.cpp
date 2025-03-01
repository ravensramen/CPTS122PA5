#include "queue.hpp"

queue::queue() {
	//initialize head and tail to nullptr
	pHead = nullptr;
	pTail = nullptr;
}

bool queue::enqueue(Data newData) {
	bool success = false;
	//bool return to determine if enqueue was successful 

	Data *pData = new Data(newData); //creates new node with inserted data
	
	if (pData != nullptr) {
		success = true;

		queueNode newCustomer(newData); //new node coresponding to newest customer
		//queueNode newCustomer = queueNode(pData);

		if (pHead == nullptr) {
			//assign newly created node to be the head
			pHead = pTail = &newCustomer; //if queue is empty, newly made customer node becomes both head and tail
		}
		else {
			
		}
		

	}
	else {
		return false; //denotes that new node wasnt created successfully
	}

	//function to return welcome message?

	return success;
}