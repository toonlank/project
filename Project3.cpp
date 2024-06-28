#include <iostream> 
#include <cassert>
#include <string>
#include <cctype>
using namespace std;

template <class Type>
class queueADT
{
public:
	virtual bool isEmptyQueue() const = 0;
	virtual bool isFullQueue() const = 0;
	virtual void initializeQueue() = 0;
	virtual Type front() const = 0; //Function to return the first element of the queue.
	virtual Type back() const = 0; //Function to return the last element of the queue.
	virtual void addQueue(const Type& queueElement) = 0; //Function to add queueElement to the queue.
	virtual void deleteQueue() = 0; //Function to remove the first element of the queue.
};

template <class Type>
class queueType : public queueADT<Type>
{
private:
	int maxQueueSize; //variable to store the maximum queue size
	int count;        //variable to store the number of elements in the queue
	int queueFront;   //variable to point to the first element of the queue
	int queueRear;    //variable to point to the last element of the queue
	Type* list;       //pointer to the array that holds the queue elements 

public:
	queueType(int queueSize = 100) //Constructor
	{
		if (queueSize <= 0)
		{
			cerr << "Size of the array to hold the queue must "
				<< "be positive." << endl;
			cerr << "Creating an array of size 100." << endl;

			maxQueueSize = 100;
		}
		else
			maxQueueSize = queueSize;   //set maxQueueSize to queueSize

		queueFront = 0;                 //initialize queueFront
		queueRear = maxQueueSize - 1;   //initialize queueRear
		count = 0;
		list = new Type[maxQueueSize];  //create the array to hold the queue elements
	}

	queueType(const queueType<Type>& otherQueue) //Copy constructor
	{
		maxQueueSize = otherQueue.maxQueueSize;
		queueFront = otherQueue.queueFront;
		queueRear = otherQueue.queueRear;
		count = otherQueue.count;

		list = new Type[maxQueueSize];

		//copy other queue in this queue
		for (int j = queueFront; j <= queueRear; j = (j + 1) % maxQueueSize)
			list[j] = otherQueue.list[j];
	} //end copy constructor


	~queueType() //Destructor
	{
		delete[] list;
	}

	const queueType<Type>& operator=(const queueType<Type>& otherQueue) //Overload the assignment operator.
	{
		int j;

		if (this != &otherQueue) //avoid self-copy
		{
			maxQueueSize = otherQueue.maxQueueSize;
			queueFront = otherQueue.queueFront;
			queueRear = otherQueue.queueRear;
			count = otherQueue.count;

			delete[] list;
			list = new Type[maxQueueSize];

			//copy other queue in this queue
			if (count != 0)
				for (j = queueFront; j <= queueRear; j = (j + 1) % maxQueueSize)
					list[j] = otherQueue.list[j];
		} //end if

		return *this;
	}


	bool isEmptyQueue() const //Function to determine whether the queue is empty.
	{
		return (count == 0);
	} //end isEmptyQueue


	bool isFullQueue() const //Function to determine whether the queue is full.
	{
		return (count == maxQueueSize);
	} //end isFullQueue

	void initializeQueue() //Function to initialize the queue to an empty state.
	{
		queueFront = 0;
		queueRear = maxQueueSize - 1;
		count = 0;
	}

	Type front() const //Function to return the first element of the queue.
	{
		assert(!isEmptyQueue());
		return list[queueFront];
	}

	Type back() const //Function to return the last element of the queue.
	{
		assert(!isEmptyQueue());
		return list[queueRear];
	} //end back

	void addQueue(const Type& newElement) //Function to add queueElement to the queue.
	{
		if (!isFullQueue())
		{
			queueRear = (queueRear + 1) % maxQueueSize; //use mod
			//operator to advance queueRear  
			//because the array is circular
			count++;
			list[queueRear] = newElement;
		}
		else
			cerr << "Cannot add to a full queue." << endl;
	}


	void deleteQueue()  //Function to remove the first element of the queue.
	{
		if (!isEmptyQueue())
		{
			count--;
			queueFront = (queueFront + 1) % maxQueueSize; //use the
			//mod operator to advance queueFront 
			//because the array is circular 
		}
		else
			cerr << "Cannot remove from an empty queue." << endl;
	}
};

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
	string word;
	cout << "Enter a string: ";
	getline(cin, word);
	queueType<string> queue1(word.size());
	stackType<string> stack1(word.size());
	for (char &c : word) {
		c = tolower(c); //Converts each character in the string to lowercase
	}
	for (int i = 0; i < word.size(); i++) { //adds each letter to the queue and stack
		queue1.addQueue(word.substr(i, 1));
		stack1.push(word.substr(i, 1));
	}
	bool isPalindrome = true;
	while (!stack1.isEmptyStack() && !queue1.isEmptyQueue()) {
		if (stack1.top() == " " && stack1.top() != queue1.front()) {
			stack1.pop();
		}
		if (queue1.front() == " " && stack1.top() != queue1.front()) {
			queue1.deleteQueue();
		}
		if (queue1.front() == stack1.top()) {
			stack1.pop();
			queue1.deleteQueue();
		} else {
			isPalindrome = false;
			break;
		}
	}
	if (isPalindrome) {
		cout << "The string " << word << " is a palindrome." << endl;
	}
	else {
		cout << "The string " << word << " is not a palindrome." << endl;
	}
	return 0;
}