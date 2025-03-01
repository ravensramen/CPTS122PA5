
#include "queue.hpp" //includes header :)

int main() {


	int n = 0;
	int minutesElapsed = 0; //keep track of the number of minutes that have passed

	cout << "Welcome to the supermarket line simulator! How many minutes is the checkout line open for today?: ";
	cin >> n;
	cout << n << " minutes, alrighty! The customers should start rolling in any minute now..." << endl;

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

	while (minutesElapsed<n) {
		
		//ADD arrival message corresponding to line? or add to enqueue
		if (regularLaneCustomerRate == 0) { //if line just started, subsequent rates determined by customer service time (in each node)

			//generate new regular line customer
			Data newCustomer; //allocate memory for data fields
			newCustomer.setCustomerNumber(++regularCustomerID); //increment the customer number
			newCustomer.setServiceTime(rand() % 8 + 1); //generate random customer time, decrement at the end of each loop
			newCustomer.setTotalTime(regularLaneTotalTime); //starts at zero of course and increments at each loop
			
			//create actual node with data fields above
			regularLane.enqueue(newCustomer);
			
			regularLaneCustomerRate = rand() % 8 + 1; //generate time until next customer
		}
		if (expressLaneCustomerRate == 0) { 
			expressLaneCustomerRate = rand() % 5 + 1;
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
		//ADD exit message? or put in dequeue
		if (minutesElapsed % 10 == 0) { //if 10 minutes have passed
			cout << "here's the summary of the past ten minutes" << endl;
		}

	}

	cout << "the line is now closed...."; //possibly print summary?

	return 0;
}