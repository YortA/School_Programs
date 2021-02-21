// Troy Andrews
// SDEV-240-81
// 7/12/2020
// Description: Finds the "nth" place of a fibonacci number when an integer input.
// I.E. Input = 25, return 9 (9th place in a fibonacci series)

//#include "fibonacci.h"		// pretend to link header to main.cpp
#include <iostream>
#include<vector>
using namespace std;

// fib.h
class fibonacci
{
private:
	int t1 = 0;
	int t2 = 1;
	int sum = 0;
	int counter = 0;
	int input = 0;
	vector<int> fib;
public:
	fibonacci(int userinput) : input(userinput) {}				// we need to construct with an input.

	void fibcalc();
	void fiboutput();
	int fibcheck();
};


// fib.cpp

// take our input and check it against the sum. then we populate a fibo. series with it.
void fibonacci::fibcalc()
{
	for (int i = 0; sum < input; ++i)
	{
		t1 = t2;
		t2 = sum;
		fib.push_back(sum);
		sum = t1 + t2;
		counter++;
	}

	// get our upperbound value to compare with our lowerbound and input
	fib.push_back(sum);
	counter++;
}

// check to see if our input is closer to our lowerbound or upperbound number.
int fibonacci::fibcheck()
{
	if ((fib[fib.size() - 1] - input) < (input - fib[fib.size() - 2]))
	{
		cout << input << " is closer to: " << fib[fib.size() - 1];
	}
	else
	{
		cout << input << " is closer to: " << fib[fib.size() - 2];
		counter--;			// we remove a counter because it's closer to the lowerbound.
	}
	return counter;
}

// output our fibo.
void fibonacci::fiboutput()
{
	cout << endl;
	for (int i = 0; i < counter; ++i)
	{
		cout << fib[i] << "  ";
	}
}


// main.cpp
int main()
{
	int input = 0;
	int output = 0;

	cout << "Input an integer to find the nth index of a fibo. series: ";
	cin >> input;

	fibonacci xyz(input);
	xyz.fibcalc();
	output = xyz.fibcheck();
	xyz.fiboutput();
	cout << "\nnth place is: " << output;
}