#include "queue.hpp"

queue::queue() {
	//initialize head and tail to nullptr
	pHead = nullptr;
	pTail = nullptr;
}

bool queue::enqueue(Data newData) {
	bool success = false;
	//bool return to determine if enqueue was successful 
	
	queueNode* newCustomer = new queueNode(newData);

	if (newCustomer != nullptr) {

		//case 1: empty queue
		if (this->pHead == nullptr) {
			this->pHead = this-> pTail = newCustomer;
		}

		else {
			//add next value in empty queue
			this->pTail->setNextNode(newCustomer);
			this->pTail = newCustomer;
		}

		success = true; 
		
	}
	return success;
}

bool queue::isEmpty() const {
	return this->pHead == nullptr && this->pTail == nullptr; //if queue is empty, return true
}

void queue::print_queue() {

	queueNode *pMem = this->pHead;

	while (pMem->getNextNode() != nullptr) { //while not at the end of queue list
		cout << "Customer Number: ";
		cout<< pMem->getNodeData()->getCustomerNumber();
		cout << " ,Customer Service Time: ";
		cout << pMem->getNodeData()->getServiceTime();
		cout << " ,Total Time: ";
		cout << pMem->getNodeData()->getTotalTime() << endl;

		pMem = pMem->getNextNode(); //onto next node
	}
}

