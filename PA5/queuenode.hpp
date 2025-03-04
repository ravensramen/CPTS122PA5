#include "data.hpp"

class queueNode {

public:
	queueNode(); //constructor

	queueNode(Data newData); //copy constructor
	

	~queueNode(); //destructor

	void setNextNode(queueNode* const nextNode);
	
	void incrementNodeData(queueNode* currentNode);
	void incrementHeadNode(queueNode* headNode);

	void setNodeData(Data newData);

	queueNode* getNextNode() const;

	Data* getNodeData();


private:
	Data* pData;
	queueNode* pNext;
};

//queueNode operator=(queueNode lhs, queueNode rhs);