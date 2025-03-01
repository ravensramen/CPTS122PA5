#include "data.hpp"

class queueNode {

public:
	queueNode(); //constructor

	queueNode(Data newData); //copy constructor

	~queueNode(); //destructor

private:
	Data* pData;
	queueNode* pNext;
};

//queueNode operator=(queueNode lhs, queueNode rhs);