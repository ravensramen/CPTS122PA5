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

queueNode* queueNode::getNextNode() const
{
	return this->pNext;
}

Data* queueNode::getNodeData()
{
	return this->pData;
}
