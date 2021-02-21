// Troy Andrews

#include <iostream>
#include <list>
#include <iomanip>

class ListTest
{
private:
	std::list<double> accData;

public:
	void printList();
	void insertData(double*, int);
};

void ListTest::printList()
{
	for (double x : accData)
		std::cout << std::fixed << x << ", ";
}

void ListTest::insertData(double* arr, int arrSize)
{
	this->accData.insert(accData.begin(), arr, arr + arrSize);		// we could parse the extra .00000 at the end of whole numbers (i.e. 2.00000), but that's beside the point
	accData.sort();		// here we simply sort the values in our array
}



int main()
{
	double arrData[] = { 421003, 100298, 494002, .000093, 3994, 21093, 3949500, 29100, 6493939, 202814, .0506984, 2, 665778 };
	int n = sizeof(arrData) / sizeof(double);		// Get the number of elements in our array before passing
	ListTest* mylist = new ListTest;

	mylist->insertData(arrData, n);
	mylist->printList();
}
