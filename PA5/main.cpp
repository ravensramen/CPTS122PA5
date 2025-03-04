#include "functions.hpp"

int main() {

	int n = 0; //simulation time
	 //keep track of the number of minutes that have passed
	srand(time(0)); //seed for random number (arrival time )generation

	cout << "Welcome to the Supermarket Line Simulator! How many minutes is the checkout line open for today?: ";
	cin >> n;
	cout << n << " minutes, alrighty! The customers should start rolling in any minute now..." << endl;
	system("pause");
	system("cls");

	simulation(n);


	//simulation end
	cout << "the line is now closed....";
	return 0;
}