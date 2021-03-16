// Troy Andrews

#include <iostream>
#include <vector>

class Accounting
{
private:
	std::vector<double> accData{};
public:
	void printVec();
	void insertData(double*, int);
	int qPartition(int, int, double);
	void recQuickSort(int, int);
	void quickSort();
};

void Accounting::printVec()
{
	for (double x : accData)
		std::cout << std::fixed << x << ", ";
	std::cout << std::endl;
}

void Accounting::insertData(double* arr, int arrSize)
{
	this->accData.insert(accData.begin(), arr, arr + arrSize);
}

void Accounting::quickSort()
{
	recQuickSort(0, accData.size() - 1);
}

void Accounting::recQuickSort(int left, int right)
{
	if (right - left <= 0)
	{
		return;		// nothing else to do, end the rec loop
	}
	else
	{
		double pivot = accData[right];
		int part = qPartition(left, right, pivot);
		recQuickSort(left, part - 1);
		recQuickSort(part + 1, right);
		//printVec(); // debug purposes
	}
}

int Accounting::qPartition(int left, int right, double pivot)
{
	int leftMark = left - 1;
	double temp;
	for (int i = left; i <= right - 1; ++i)
	{
		if (accData[i] <= pivot)			// find our greatest value and sort
		{
			++leftMark;
			temp = accData[leftMark];
			accData[leftMark] = accData[i];
			accData[i] = temp;
		}
	}
	temp = accData[leftMark + 1];			// found our final value, let's swap them
	accData[leftMark + 1] = accData[right];
	accData[right] = temp;
	return leftMark + 1;
}

int main()
{
	double arrData[] = { 421003, 100298, 494002, .000093, 3994, 21093, 3949500, 29100, 6493939, 202814, .0506984, 2, 665778 };
	int n = sizeof(arrData) / sizeof(double);		// Get the number of elements in our array before passing

	Accounting* Acc1 = new Accounting;

	Acc1->insertData(arrData, n);
	Acc1->printVec();
	Acc1->quickSort();
	Acc1->printVec();
}