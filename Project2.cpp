#include <iostream>
#include <cassert>
#include <string>
#include <cmath>
using namespace std;

template <class Type>
class stackADT
{
public:
	virtual void initializeStack() = 0;
	virtual bool isEmptyStack() const = 0;
	virtual bool isFullStack() const = 0;
	virtual void push(const Type& newItem) = 0;
	virtual Type top() const = 0;
	virtual void pop() = 0;
};

template <class Type>
class stackType : public stackADT<Type>
{
private:
	int maxStackSize;
	int stackTop;
	Type* list;
public:
	void initializeStack()
	{
		stackTop = 0;
		cout << "stackTop " << stackTop << endl;
	}

	void print()
	{
		for (int i = 0; i < stackTop; i++)
		{
			cout << list[i] << endl;
		}
	}

	bool isEmptyStack() const
	{
		return(stackTop == 0);
	}

	bool isFullStack() const
	{
		return(stackTop == maxStackSize);
	}

	void push(const Type& newItem)
	{
		if (!isFullStack())
		{
			list[stackTop] = newItem;
			stackTop++;
		}
		else
		{
			cout << "Cannot add to a full stack." << endl;
		}
	}

	Type top() const
	{
		assert(stackTop != 0); //if stack is empty, terminate the program.                            
		return list[stackTop - 1];
	}

	void pop()
	{
		if (!isEmptyStack())
			stackTop--;
		else
			cout << "Cannot remove from an empty stack." << endl;
	}

	stackType(int stackSize = 100)
	{
		if (stackSize <= 0)
		{
			cout << "Size of the array to hold the stack must be positive." << endl;
			cout << "Creating an array of size 100." << endl;
			maxStackSize = 100;
		}
		else
		{
			maxStackSize = stackSize;
		}

		stackTop = 0;
		list = new Type[maxStackSize];
	}

	stackType(const stackType<Type>& otherStack)
	{
		list = NULL;
		copyStack(otherStack);
	}

	~stackType()
	{
		delete[] list;
	}

	const stackType<Type>& operator=(const stackType<Type>& otherStack)
	{
		if (this != &otherStack)
		{
			copyStack(otherStack);
		}
		return *this;
	}

	bool operator==(const stackType<Type>& otherStack) const
	{
		if (this == &otherStack)
		{
			return true;
		}
		else
		{
			if (stackTop != otherStack.stackTop)
			{
				return false;
			}
			else
			{
				for (int i = 0; i < stackTop; i++)
				{
					if (list[i] != otherStack.list[i])
					{
						return false;
					}
					return true;
				}
			}
		}
	}

	void copyStack(const stackType<Type>& otherStack)
	{
		delete[] list;
		maxStackSize = otherStack.maxStackSize;
		stackTop = otherStack.stackTop;

		list = new Type[maxStackSize];

		//copy otherStack into this stack. 
		for (int j = 0; j < stackTop; j++)
		{
			list[j] = otherStack.list[j];
		}
	}
};

int main()
{
	string number;
	bool isValidNumber = true;
	cout << "Enter a positive integer value or a positive decimal value: ";
	cin >> number;
	cin.ignore(100, '\n');
	cin.clear();
	int numPeriods = 0;
	//Checks to see if the number inputed is actually a number.
	for (int i = 0; i < number.size(); i++) {
		string s = number.substr(i, 1);
		if (s == "1" || s == "2" || s == "3" || s == "4" || s == "5" || s == "6" || s == "7" || s == "8" || s == "9" || s == "0" || s == ".") {
			if (s == ".") {
				numPeriods++;
			}
			if (numPeriods > 1) {
				isValidNumber = false;
			}
		} else {
			isValidNumber = false;
		}
	}
	if (isValidNumber) {
		stackType<string> numstack(number.size());
		//if the number contains a period, it is evaluated as a decimal (double). Else, it is evaluated as an integer.
		if (number.find('.') < number.size()) {
			double num = 0.0;
			//Adds each number of the number one by one into the stack
			for (int i = 0; i < number.size(); i++) {
				numstack.push(number.substr(i, 1));
			}
			int divide = 0;
			for (int i = 0; i < number.size(); i++) {
				string n = numstack.top();
				if (n == "1") {
					num += 1 * (pow(10.0, i - (divide + 1)));
				}
				else if (n == "2") {
					num += 2 * (pow(10.0, i - (divide + 1)));
				}
				else if (n == "3") {
					num += 3 * (pow(10.0, i - (divide + 1)));
				}
				else if (n == "4") {
					num += 4 * (pow(10.0, i - (divide + 1)));
				}
				else if (n == "5") {
					num += 5 * (pow(10.0, i - (divide + 1)));
				}
				else if (n == "6") {
					num += 6 * (pow(10.0, i - (divide + 1)));
				}
				else if (n == "7") {
					num += 7 * (pow(10.0, i - (divide + 1)));
				}
				else if (n == "8") {
					num += 8 * (pow(10.0, i - (divide + 1)));
				}
				else if (n == "9") {
					num += 9 * (pow(10.0, i - (divide + 1)));
				}
				else if (n == ".") {
					divide = i;
					num /= pow(10.0, (divide - 1));
				}
				numstack.pop();
			}
			cout << "Successfully converted the string " << number << " to the double " << num << endl;
		}
		else {
			int num = 0;
			//Adds each number of the number one by one into the stack
			for (int i = 0; i < number.size(); i++) {
				numstack.push(number.substr(i, 1));
			}
			for (int i = 0; i < number.size(); i++) {
				string n = numstack.top();
				if (n == "1") {
					num += 1 * (pow(10,i));
				}
				else if (n == "2") {
					num += 2 * (pow(10, i));
				}
				else if (n == "3") {
					num += 3 * (pow(10, i));
				}
				else if (n == "4") {
					num += 4 * (pow(10, i));
				}
				else if (n == "5") {
					num += 5 * (pow(10, i));
				}
				else if (n == "6") {
					num += 6 * (pow(10, i));
				}
				else if (n == "7") {
					num += 7 * (pow(10, i));
				}
				else if (n == "8") {
					num += 8 * (pow(10, i));
				}
				else if (n == "9") {
					num += 9 * (pow(10, i));
				}
				numstack.pop();
			}
			cout << "Successfully converted the string " << number << " to the integer " << num << endl;
		}
	} else {
		cout << "Invalid Number." << endl;
	}
	return 0;
}