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

	if (pMem == nullptr) {
		cout << "This line is empty...";
		return; //early return
	}

	while (pMem!=nullptr) { //while not at the end of queue list
		cout << "Customer Number: ";
		cout<< pMem->getNodeData()->getCustomerNumber();
		cout << " ,Customer Service Time: ";
		cout << pMem->getNodeData()->getServiceTime();
		cout << " ,Total Time: ";
		cout << pMem->getNodeData()->getTotalTime() << endl;

		pMem = pMem->getNextNode();
	} 
}

queueNode queue::getHead() {
	return *(this->pHead);
}

//fix
Data queue::dequeue() {
	// If the queue is empty, return a default-constructed Data object (or handle error).
	if (this->isEmpty()) {
		cout << "Queue is empty!" << endl;
		return Data(); // Returning a default-constructed Data object.
	}

	// Get the data from the front of the queue (pHead)
	Data dequeuedData = *(this->pHead->getNodeData());

	// Create a temporary node to hold the dequeued data (optional, but can help for clarity)
	queueNode* dequeuedTemp = this->pHead;

	// Move pHead to the next node
	this->pHead = this->pHead->getNextNode();

	// If the queue is now empty, set pTail to nullptr
	if (this->pHead == nullptr) {
		this->pTail = nullptr;
	}

	// Delete the old head node to free the memory (important to avoid memory leak)
	delete dequeuedTemp;

	// Return the dequeued data
	return dequeuedData;
}

void queue::incrementQueue() {
	if (this->pHead == nullptr) return; //dont update if line is empty of course

	queueNode* pMem = this->pHead;

	int newServiceTime = this->pHead->getNodeData()->getServiceTime() - 1;
	this->pHead->getNodeData()->setServiceTime(newServiceTime);

	while (pMem != nullptr) {
		pMem->getNodeData()->setTotalTime(pMem->getNodeData()->getTotalTime() + 1); //increment total time by 1
		pMem = pMem->getNextNode(); //onto the next node
	}
}

void queue::initiateDequeue(int laneType)
{
	if (this->pHead->getNodeData()->getServiceTime() == 0) {

		cout << endl;
		cout << "A customer is leaving the line..." << endl;
		cout << "Visit Summary: ";
		cout << "Line: ";
		if (laneType == 1) {
			cout << "Regular Line";
		}
		if (laneType == 2) {
			cout << "Express Line";
		}

		cout << ", Customer ID: " << this->pHead->getNodeData()->getCustomerNumber();
		cout << ", Total Time: " << this->pHead->getNodeData()->getTotalTime() << endl; 
		cout << endl; 
		this->dequeue();

	}
	return;
}

