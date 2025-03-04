#include "header.hpp"

class Data {
public: //member functions here
	Data() : customerNumber(0), serviceTime(0), totalTime(0) {} //default constructor with 0 initialized values

	//value constructor
	Data(int customer_number, int service_time, int total_time) : customerNumber(customer_number), serviceTime(service_time), totalTime(total_time) {} 

	//copy constructor
	
	Data(const Data& copyData)
		: customerNumber(copyData.customerNumber),
		serviceTime(copyData.serviceTime),
		totalTime(copyData.totalTime) {}

	//getters, defined in cpp file
	int getCustomerNumber();
	int getServiceTime();
	int getTotalTime();

	//setters

	void setCustomerNumber(int inputCustomerNumber);
	void setServiceTime(int inputServiceTime);
	void setTotalTime(int inputTotalTime);

private:
	int customerNumber;
	int serviceTime;
	int totalTime; //= service time + sum of service time of prior customers
	
};