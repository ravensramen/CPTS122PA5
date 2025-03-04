#include "queuenode.hpp"

//constructor
queueNode::queueNode()
{
	//initalize node contents
	pData = nullptr;
	pNext = nullptr; 
}

//not working or summ idk
queueNode::queueNode(Data newData) {

	pData = new Data();

	if (pData == nullptr) {
		// Handle memory allocation failure (Optional: could throw exception or log error)
		cout << "Memory allocation for Data failed!" << endl;
		return;
	}


	pData->setCustomerNumber(newData.getCustomerNumber());
	pData->setServiceTime(newData.getServiceTime());
	pData->setTotalTime(newData.getTotalTime());

	pNext = nullptr;
	
}

//destructor
queueNode::~queueNode()
{
}

void queueNode::setNextNode(queueNode* const nextNode)
{
	this->pNext = nextNode; //sets pointer to next node
}

void queueNode::incrementNodeData(queueNode* currentNode)
{
	int updateTime = currentNode->getNodeData()->getTotalTime() + 1; 

	currentNode->pData->setTotalTime(updateTime);
}

void queueNode::incrementHeadNode(queueNode* headNode)
{
	int updateTime = headNode->getNodeData()->getTotalTime() + 1;

	headNode->pData->setTotalTime(updateTime);
	headNode->getNodeData()->getServiceTime() - 1;
	//subtract one minute from head service time (front customer is being serviced)
	//when head service time reaches zero, dequeue

}

void queueNode::setNodeData(Data newData)
{
	this->pData->setCustomerNumber(newData.getCustomerNumber());
	this->pData->setServiceTime(newData.getServiceTime());
	this->pData->setTotalTime(newData.getTotalTime());
}

queueNode* queueNode::getNextNode() const
{
	return this->pNext;
}


Data* queueNode::getNodeData()
{

	if (this == nullptr) {
		// Handle the error: pData should not be nullptr
		cout << "Error: pData is nullptr!" << endl;
		return nullptr; // Or throw an exception if preferred
	}

	return this->pData;
}
