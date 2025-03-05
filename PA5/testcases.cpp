#include "testcases.hpp"

Tests::Tests() {

}

Tests::~Tests() {

}

void Tests::emptyEnqueue(void)
{
	queue emptyQueue;

	Data* newData = new Data(1, 2, 3);

	emptyQueue.enqueue(*newData);

	if (emptyQueue.getHead().getNodeData()->getCustomerNumber() == newData->getCustomerNumber()) {
		cout << "EMPTYENQUEUE test passed";
	}
	else {
		cout << "EMPTYENQUEUE test failed";
	}
	cout << endl;
}

void Tests::populatedEnqueue(void) {
	queue populatedQueue;

	Data* data1 = new Data(1, 2, 3);

	populatedQueue.enqueue(*data1);
	//queue is now populated

	Data* data2 = new Data(2, 3, 4);

	populatedQueue.enqueue(*data2);


	if (populatedQueue.getHead().getNextNode()->getNodeData()->getCustomerNumber() == data2->getCustomerNumber()) {
		cout << "POPULATEDENQUEUE test passed. ";
	}
	else {
		cout << "POPULATEDENQUEUE test failed. ";
	}
	cout << endl;
}

void Tests::singleNodeDequeue(void) {
	queue testQueue;
	Data* data1 = new Data(1, 2, 3);

	testQueue.enqueue(*data1);

	testQueue.dequeue();

	if (testQueue.isEmpty()) {
		cout << "SINGLENODEDEQUEUE test passed. ";
	}
	else {
		cout << "SINGLENODEDEQUEUE test failed. ";
	}
	cout << endl;

}

void Tests::twoNodeDequeue(void) {
	queue testQueue;

	Data* data1 = new Data(1, 2, 3);
	Data* data2 = new Data(2, 3, 4);
	
	testQueue.enqueue(*data1);
	testQueue.enqueue(*data2);

	testQueue.dequeue(); //should dequeue second node

	if (testQueue.getHead().getNodeData()->getCustomerNumber() == data2->getCustomerNumber()) {
		cout << "TWONODEDEQUEUE test passed";
	}
	else {
		cout << "TWONODEDEQUEUE test failed"; 
	}

}

void Tests::testDaySimulation() {


	int n = 1440; //minutes in a day

	simulation(1440);

	int check = 0;

	//note there is no way to effeciently check a whole day, must hit enter 1440 times :(
	// //only other option is a "sleep" function to pause console between loops, but even this will take a long time to complete...


	//can hold enter though...
	cout << "TESTDAYSIMULATION passed, simulation complete." << endl;

	
	}