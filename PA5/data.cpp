#include "data.hpp"


int Data::getCustomerNumber() {
	return customerNumber;
}

int Data::getServiceTime(){
	return serviceTime; 
}

int Data::getTotalTime() {
	return totalTime;
}

void Data::setCustomerNumber(int inputCustomerNumber)
{
	this->customerNumber = inputCustomerNumber; 
}

void Data::setServiceTime(int inputServiceTime)
{
	this->serviceTime = inputServiceTime;
}

void Data::setTotalTime(int inputTotalTime)
{
	totalTime = inputTotalTime;
}
