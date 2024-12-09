# Queue Time Simulation Based on Available Tellers

This C++ program simulates the queue time in a customer service environment, where the number of available tellers can impact the total wait time for customers. The simulation models customer arrivals, transaction times, and processing at available tellers to estimate wait times and simulate real-world queuing scenarios.

### Features:
- **Customer Arrival Simulation**: Customers arrive at random intervals and require a specific amount of time for their transactions.
- **Multiple Tellers**: The simulation accounts for a dynamic number of available tellers, which reduces wait time as more tellers become available.
- **Queue Management**: Customers are placed in a queue and served based on availability of tellers, with the program calculating the total wait time for each customer.
- **Realistic Timing**: Simulated transaction times and customer arrivals allow the program to realistically reflect how queues form and are managed.

### How it Works:
1. The program reads customer data from a file (`customers.txt`) where each line specifies an arrival time and a transaction time.
2. The customer data is processed with the given number of tellers to determine how long each customer has to wait.
3. The simulation calculates the total wait time and output results based on teller availability.

### Usage:
1. Place a file named `customers.txt` in the same directory where each value is an unsigned integer.

2. If you wish to modify the input file, change the filename on line 77 of the code.

### Requirements:
- C++11 or higher.
- A standard C++ compiler.

### License:
This project is licensed under the MIT License - see the [LICENSE](LICENSE.txt) file for details.
