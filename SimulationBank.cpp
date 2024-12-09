#include <iostream>
#include <vector>
#include <fstream>
#include <deque>

/*
 * Note to Users:
 *
 * 1. Before running the program, place a file named "customers.txt" in the same directory.
 * 2. The file should contain customer data in the following format:
 *
 *    [arrival time] [transaction time]
 *    [arrival time] [transaction time]
 *    [arrival time] [transaction time]
 *    [arrival time] [transaction time]
 *
 * 3. Both arrival time and transaction time should be unsigned integers (values between 1 and 9).
 *    - No negative numbers allowed!
 * 4. If you wish to change the filename:
 *    - Modify line 77, where the file is opened, from:
 *        std::ifstream inputFile("customers.txt");
 *      to your desired filename.
 */

class customers
{
public:
	int arrivalTime;
	int transactionTime;

	// Constructor to initialize customer with arrival and transaction times
	customers(int arrivalTime, int transactionTime)
	{
		this->arrivalTime = arrivalTime;
		this->transactionTime = transactionTime;
	}
};

std::vector<customers> customer;

// Calculates the average wait time for a given number of tellers
double avgWaitTime(int tellers)
{
	std::deque<int> tellerAvailability(tellers, 0);  // Tracks each teller's next available time
	double totalWaitTime = 0;

	// Iterate through each customer to calculate wait time and update teller availability
	for (const auto& customer : customer)
	{
		// Find the earliest available teller
		int earliestAvailableTime = tellerAvailability[0];
		int earliestTellerIndex = 0;
		for (int i = 1; i < tellers; ++i)
		{
			if (tellerAvailability[i] < earliestAvailableTime)
			{
				earliestAvailableTime = tellerAvailability[i];
				earliestTellerIndex = i;
			}
		}

		// Customer is served when they arrive or when the teller is free, whichever is later
		int startTime = std::max(earliestAvailableTime, customer.arrivalTime);
		double waitTime = startTime - customer.arrivalTime;
		totalWaitTime += waitTime;

		// Update teller availability after serving the customer
		tellerAvailability[earliestTellerIndex] = startTime + customer.transactionTime;
	}

	// Return the average wait time
	return (customer.size() > 0) ? (totalWaitTime / customer.size()) : 0;
}

int main()
{
	std::ifstream inputFile("customers.txt");

	// Exit if file can't be opened
	if (!inputFile)
	{
		std::cout << "Error reading file" << std::endl;
		return 1;
	}

	int arrivalTime{}, transactionTime{};

	// Read customer data from file
	while (inputFile >> arrivalTime >> transactionTime)
	{
		customer.push_back(customers(arrivalTime, transactionTime));
	}

	inputFile.close();

	// Calculate and display average wait time for 1 to 8 tellers
	for (int tellers = 1; tellers <= 8; ++tellers)
	{
		std::cout << "With " << tellers << " tellers it takes " << avgWaitTime(tellers) << " seconds." << std::endl;
	}

	return 0;
}