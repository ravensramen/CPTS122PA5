
#include "queue.hpp" //includes header :)

void arrivalMessage(Data newCustomer, int lineType);

int main() {


	int n = 0;
	int minutesElapsed = 0; //keep track of the number of minutes that have passed

	cout << "Welcome to the supermarket line simulator! How many minutes is the checkout line open for today?: ";
	cin >> n;
	cout << n << " minutes, alrighty! The customers should start rolling in any minute now..." << endl;
	system("pause");
	system("cls");
	//while loop to represent each minute elapsing

	//instantiate two lines (express and regular)

	queue regularLane; //should be empty at instantiation, except for type?
	queue expressLane; //^^
	
	srand(time(0)); //seed for random number generation

	
	int regularLaneCustomerRate = 0;
	int expressLaneCustomerRate = 0;

	int regularCustomerID = 0;
	int expressCustomerID = 0;

	int regularLaneTotalTime = 0;
	int expressLaneTotalTime = 0;

	int lineType = 0; //for arrival message line type

	while (minutesElapsed<n) {
		
		//ADD arrival message corresponding to line? or add to enqueue
		bool regLaneAdded = false; //for messaging 
		bool expressLaneAdded = false;



		if (regularLaneCustomerRate == 0) { //if line just started, subsequent rates determined by customer service time (in each node)

			//generate new regular line customer
			Data newRegCustomer; //allocate memory for data fields
			newRegCustomer.setCustomerNumber(++regularCustomerID); //increment the customer number
			newRegCustomer.setServiceTime(rand() % 8 + 1); //generate random customer time, decrement at the end of each loop
			newRegCustomer.setTotalTime(regularLaneTotalTime); //starts at zero of course and increments at each loop
			
			//create actual node with data fields above
			regularLane.enqueue(newRegCustomer);
			arrivalMessage(newRegCustomer, 1);
			
			regularLaneCustomerRate = rand() % 8 + 1; //generate time until next customer
			regLaneAdded = true;
		}
		if (expressLaneCustomerRate == 0) { 
			expressLaneCustomerRate = rand() % 5 + 1;

			Data newExpressCustomer;
			expressLaneAdded = true;
		}
		
		//DEQUEUE LOGIC:

		//decrement minutes of service time of head node, when reaches zero, DEQUEUE NODE

		
		
		cout << "one minute has passed" << endl;
		//print summary of actions every 10 minutes

		//for debuggin :P
		system("pause");

		minutesElapsed++; 
		regularLaneTotalTime++; //keeps track of entire time
		expressLaneTotalTime++;

		regularLaneCustomerRate--; //one minute has passed, one less minute until new customer arrives
		//need to increment all nodes total time and decrement head node service time
		

		//if service time of node reaches zero, dequeue that mf

		//ADD exit message? or put in dequeue
		if (minutesElapsed % 10 == 0) { //if 10 minutes have passed
			system("cls");
			//print queue
			cout << "Regular Line Current Summary: "<<endl;
			regularLane.print_queue();
			cout << endl;
		}

	}

	cout << "the line is now closed...."; //possibly print summary?

	return 0;
}

void arrivalMessage(Data newCustomer, int lineType){
	if (lineType == 1) {
		cout << "welcome regular customer!" << endl;
		cout << "Line: 1, ";
	}

	if (lineType == 2) {
		cout << "welcome express customer!";
		cout << "Line: 2, ";
	}
	cout << "Customer ID: " << newCustomer.getCustomerNumber();
	cout << ", Arrival Time: " << newCustomer.getTotalTime() << endl;
}