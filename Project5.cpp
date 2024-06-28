#include <iostream>
#include "binaryTree.h"
using namespace std;


int main()
{
	binaryTreeType<int>  treeRoot;

	int num;

	cout << "Enter integers ending with -999" << endl;
	cin >> num;
	while (num != -999)
	{
		treeRoot.insert(num);
		cin >> num;
	}

	cout << endl << "Tree nodes in postorder: ";
	treeRoot.postorderTraversal();
	cout << endl;

	cout << "Tree Height: " << treeRoot.treeHeight() << endl;
	cout << "Number of Nodes: " << treeRoot.treeNodeCount() << endl;
	cout << endl;
	
	cout << "Number of single parent nodes: " << treeRoot.singleParent() << endl;
	return 0;
}
