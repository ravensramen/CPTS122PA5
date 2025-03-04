
#include "queue.hpp" //includes header :)

void arrivalMessage(Data newCustomer, int lineType);
void dequeueMessage(bool dequeueStatus, int laneType, Data outputData);


int main() {

	int n = 0; //simulation time
	int minutesElapsed = 0; //keep track of the number of minutes that have passed
	srand(time(0)); //seed for random number (arrival time )generation

	cout << "Welcome to the Supermarket Line Simulator! How many minutes is the checkout line open for today?: ";
	cin >> n;
	cout << n << " minutes, alrighty! The customers should start rolling in any minute now..." << endl;
	system("pause");
	system("cls");

	//instantiate two queues (express and regular)
	queue regularLane;
	queue expressLane; 
	
	int regularLaneCustomerRate = 0; //randomly generated each iteration
	int expressLaneCustomerRate = 0;

	int regularCustomerID = 0; //increments each iteration
	int expressCustomerID = 0;

	int lineType = 0; //for console messaging

	while (minutesElapsed<n) {
		
		//bool regLaneAdded = false; //for messaging 
		//bool expressLaneAdded = false;

		if (regularLaneCustomerRate == 0) { //if randomly generated rate reaches 0 min, generate new customer

			//generate data fields for regular line customer
			Data newRegCustomer; //allocate memory for data fields
			newRegCustomer.setCustomerNumber(++regularCustomerID); //increment the customer id
			newRegCustomer.setServiceTime(rand() % 8 + 1); //random service time, decrement at the end of each loop
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
		

		cout << "one minute has passed" << endl;

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
			cout << "Regular Line Current Summary: "<<endl;
			regularLane.print_queue();
			cout << endl;

			cout << "Express Line Current Summary: " << endl;
			expressLane.print_queue();
			cout << endl;

			system("pause");
			system("cls");
		}

		system("pause");
		system("cls");
	}

	//simulation end
	cout << "the line is now closed....";
	return 0;
}

void arrivalMessage(Data newCustomer, int lineType){
	if (lineType == 1) {
		cout << "welcome regular customer!" << endl;
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

		cout << "A customer finished checking out! " << endl;
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