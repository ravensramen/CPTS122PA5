#include "functions.hpp"

void arrivalMessage(Data newCustomer, int lineType) {
	if (lineType == 1) {
		cout << "Welcome regular customer!" << endl;
		cout << "Line: 1, ";
	}

	if (lineType == 2) {
		cout << "Welcome express customer!" << endl;
		cout << "Line: 2, ";
	}
	cout << "Customer ID: " << newCustomer.getCustomerNumber();
	cout << ", Arrival Time: " << newCustomer.getTotalTime() << endl;
}

void dequeueMessage(bool dequeueStatus, int laneType, Data outputData) {

	if (dequeueStatus == true) { //if an item was dequeued, print message

		cout << "A customer finished checking out... " << endl;
		cout << "Exit Summary: " << endl;
		if (laneType == 1) {
			//output message for regular lane
			cout << "Lane Type: Regular, ";
		}
		if (laneType == 2) {
			cout << "Lane Type: Express, ";
		}
		cout << "Customer Number: " << outputData.getCustomerNumber();
		cout << ", Total Time (Minutes): " << outputData.getTotalTime() << endl;
	}
}



void simulation(int n){

	int minutesElapsed = 0;
//instantiate two queues (express and regular)
	queue regularLane; 
	queue expressLane;

	int regularLaneCustomerRate = rand() % 8 + 3;  //randomly generated each iteration
	int expressLaneCustomerRate = rand() % 5 + 1;

	int regularCustomerID = 0; //increments each iteration
	int expressCustomerID = 0;

	int lineType = 0; //for console messaging

	while (minutesElapsed < n) {

	//bool regLaneAdded = false; //for messaging 
	//bool expressLaneAdded = false;

	if (regularLaneCustomerRate == 0) { //if randomly generated rate reaches 0 min, generate new customer

		//generate data fields for regular line customer
		Data newRegCustomer; //allocate memory for data fields
		newRegCustomer.setCustomerNumber(++regularCustomerID); //increment the customer id
		newRegCustomer.setServiceTime(rand() % 8 + 3); //random service time, decrement at the end of each loop
		newRegCustomer.setTotalTime(minutesElapsed);

		//add customer node to queue
		regularLane.enqueue(newRegCustomer);
		arrivalMessage(newRegCustomer, 1);

		regularLaneCustomerRate = rand() % 8 + 3; //generate time until next customer

	}
	if (expressLaneCustomerRate == 0) {
		expressLaneCustomerRate = rand() % 5 + 1;

		Data newExpressCustomer;
		newExpressCustomer.setCustomerNumber(++expressCustomerID);
		newExpressCustomer.setServiceTime(rand() % 5 + 1);
		newExpressCustomer.setTotalTime(minutesElapsed);

		expressLane.enqueue(newExpressCustomer);
		arrivalMessage(newExpressCustomer, 2);
	}

	//check if dequeue constraints are met
	if (!regularLane.isEmpty()) {
		regularLane.initiateDequeue(1);
		regularLane.incrementQueue(); //subtract from service time of head, add one minute to total of ALL nodes
	}


	if (!expressLane.isEmpty()) {
		expressLane.initiateDequeue(2);
		expressLane.incrementQueue();
	}

	//data updates for each iteration
	minutesElapsed++;

	//one less minute until next customer arrives
	regularLaneCustomerRate--;
	expressLaneCustomerRate--;

	//print message every 10 min
	if (minutesElapsed % 10 == 0) {
		system("cls");
		cout << "Regular Line Current Summary: " << endl;
		regularLane.print_queue();
		cout << endl;

		cout << "Express Line Current Summary: " << endl;
		expressLane.print_queue();
		cout << endl;

		system("pause");
		system("cls");
	}

	cout << "one minute has passed" << endl;

	system("pause");
	system("cls");
}
}
