#ifndef H_binaryTree
#define H_binaryTree
#include <iostream>

using namespace std;

//Definition of the Node
template <class elemType>
struct nodeType
{
	elemType info;
	nodeType<elemType>* lLink;
	nodeType<elemType>* rLink;
};

//Definition of the class
template <class elemType>
class binaryTreeType
{
public:
	//Overload the assignment operator.
	const binaryTreeType<elemType>& operator=(const binaryTreeType<elemType>& otherTree)
	{
		if (this != &otherTree) //avoid self-copy
		{
			if (root != nullptr)   //if the binary tree is not empty,
				//destroy the binary tree
				destroy(root);

			if (otherTree.root == nullptr) //otherTree is empty
				root = nullptr;
			else
				copyTree(root, otherTree.root);
		}//end else

		return *this;
	}

	//Function to determine whether the binary tree is empty.
	//Postcondition: Returns true if the binary tree is empty;
	//               otherwise, returns false.
	bool isEmpty() const
	{
		return (root == nullptr);
	}

	//Function to do an inorder traversal of the binary tree.
	//Postcondition: Nodes are printed in inorder sequence.
	void inorderTraversal() const
	{
		inorder(root);
	}

	//Function to do a preorder traversal of the binary tree.
	//Postcondition: Nodes are printed in preorder sequence.
	void preorderTraversal() const
	{
		preorder(root);
	}

	//Function to do a postorder traversal of the binary tree.
	//Postcondition: Nodes are printed in postorder sequence.
	void postorderTraversal() const
	{
		postorder(root);
	}

	//Function to determine the height of a binary tree.
	//Postcondition: Returns the height of the binary tree.
	int treeHeight() const
	{
		return height(root);
	}

	//Function to determine the number of nodes in a 
	//binary tree.
	//Postcondition: Returns the number of nodes in the 
	//               binary tree.
	int treeNodeCount() const
	{
		return nodeCount(root);
	}

	//Function to determine the number of leaves in a 
	//binary tree.
	//Postcondition: Returns the number of leaves in the 
	//               binary tree.
	int treeLeavesCount() const
	{
		return leavesCount(root);
	}

	//Function to destroy the binary tree.
	//Postcondition: Memory space occupied by each node 
	//               is deallocated.
	//               root = nullptr;
	void destroyTree()
	{
		destroy(root);
	}

	//Function to determine if searchItem is in the binary 
	//tree.
	//Postcondition: Returns true if searchItem is found in 
	//               the binary tree; otherwise, returns 
	//               false.
	bool search(const elemType& searchItem) const
	{
		nodeType<elemType>* current;
		bool found = false;

		if (root == nullptr)
			cout << "Cannot search an empty tree." << endl;
		else
		{
			current = root;

			while (current != nullptr && !found)
			{
				if (current->info == searchItem)
					found = true;
				else if (current->info > searchItem)
					current = current->lLink;
				else
					current = current->rLink;
			}//end while
		}//end else

		return found;
	}//end search



	 //Function to insert insertItem in the binary tree.
	 //Postcondition: If there is no node in the binary tree
	 //               that has the same info as insertItem, a
	 //               node with the info insertItem is created
	 //               and inserted in the binary search tree.
	void insert(const elemType& insertItem)
	{
		nodeType<elemType>* current; //pointer to traverse the tree
		nodeType<elemType>* trailCurrent; //pointer behind current
		nodeType<elemType>* newNode;  //pointer to create the node

		trailCurrent = NULL;

		newNode = new nodeType<elemType>;
		newNode->info = insertItem;
		newNode->lLink = nullptr;
		newNode->rLink = nullptr;

		if (root == nullptr)
			root = newNode;
		else
		{
			current = root;

			while (current != nullptr)
			{
				trailCurrent = current;

				if (current->info == insertItem)
				{
					cout << "The item to be inserted is already ";
					cout << "in the tree -- duplicates are not "
						<< "allowed." << endl;
					return;
				}
				else if (current->info > insertItem)
					current = current->lLink;
				else
					current = current->rLink;
			}//end while

			if (trailCurrent->info > insertItem)
				trailCurrent->lLink = newNode;
			else
				trailCurrent->rLink = newNode;
		}
	}//end insert



	 //Function to delete deleteItem from the binary tree 
	 //Postcondition: If a node with the same info as 
	 //               deleteItem is found, it is deleted from
	 //               the binary tree.
	 //               If the binary tree is empty or 
	 //               deleteItem is not in the binary tree, 
	 //               an appropriate message is printed.
	void deleteNode(const elemType& deleteItem)
	{
		nodeType<elemType>* current; //pointer to traverse the tree
		nodeType<elemType>* trailCurrent; //pointer behind current
		bool found = false;

		if (root == nullptr)
			cout << "Cannot delete from an empty tree."
			<< endl;
		else
		{
			current = root;
			trailCurrent = root;

			while (current != nullptr && !found)
			{
				if (current->info == deleteItem)
					found = true;
				else
				{
					trailCurrent = current;

					if (current->info > deleteItem)
						current = current->lLink;
					else
						current = current->rLink;
				}
			}//end while

			if (current == nullptr)
				cout << "The item to be deleted is not in the tree."
				<< endl;
			else if (found)
			{
				if (current == root)
					deleteFromTree(root);
				else if (trailCurrent->info > deleteItem)
					deleteFromTree(trailCurrent->lLink);
				else
					deleteFromTree(trailCurrent->rLink);
			}
			else
				cout << "The item to be deleted is not in the tree."
				<< endl;
		}
	} //end deleteNode

	  //Function to delete the node to which p points is 
	  //deleted from the binary search tree.
	  //Postcondition: The node to which p points is deleted
	  //               from the binary search tree.
	void deleteFromTree(nodeType<elemType>*& p)
	{
		nodeType<elemType>* current; //pointer to traverse the tree
		nodeType<elemType>* trailCurrent;  //pointer behind current
		nodeType<elemType>* temp;      //pointer to delete the node

		if (p == nullptr)
			cout << "Error: The node to be deleted does not exist."
			<< endl;
		else if (p->lLink == nullptr && p->rLink == nullptr)
		{
			temp = p;
			p = nullptr;
			delete temp;
		}
		else if (p->lLink == nullptr)
		{
			temp = p;
			p = temp->rLink;
			delete temp;
		}
		else if (p->rLink == nullptr)
		{
			temp = p;
			p = temp->lLink;
			delete temp;
		}
		else
		{
			current = p->lLink;
			trailCurrent = nullptr;

			while (current->rLink != nullptr)
			{
				trailCurrent = current;
				current = current->rLink;
			}//end while

			p->info = current->info;

			if (trailCurrent == nullptr) //current did not move; 
				//current == p->lLink; adjust p
				p->lLink = current->lLink;
			else
				trailCurrent->rLink = current->lLink;

			delete current;
		}//end else
	} //end deleteFromTree


	  //Copy constructor
	binaryTreeType(const binaryTreeType<elemType>& otherTree)
	{
		if (otherTree.root == nullptr) //otherTree is empty
			root = nullptr;
		else
			copyTree(root, otherTree.root);
	}


	//Default constructor
	binaryTreeType()
	{
		root = nullptr;
	}


	//Destructor
	~binaryTreeType()
	{
		destroy(root);
	}

	void displayRoot()
	{
		cout << "Root value is: " << root->info << endl;
	}

	void displayL2()
	{
		cout << "2nd Level - Left Tree: " << root->lLink->info;
		cout << "\t\t2nd Level - Right Tree: " << root->rLink->info << endl;
	}

	void displayL3()
	{
		cout << "3rd Level - Left Tree: " << root->lLink->lLink->info << endl;
		cout << "3rd Level - Left-Right Tree: " << root->lLink->rLink->info;
		cout << "\t\t3rd Level - Right-Left Tree: " << root->rLink->lLink->info << endl;
	}

	void displayL4()
	{
		cout << "4th Level - Left Tree: " << root->lLink->lLink->lLink->info << endl;
		cout << "4th Level - Left-Left-Right Tree: " << root->lLink->lLink->rLink->info << endl;
	}

	void displayL5()
	{
		cout << "5th Level - Left Tree: " << root->lLink->lLink->lLink->lLink->info << endl;
		cout << "5th Level - Left-Left-Rright-Right Tree: " << root->lLink->lLink->rLink->rLink->info << endl;
	}

	int singleParent() {
		int count = 0;
		if (root == nullptr) {
			return -1;
		}
		else {
			postorderCompare(root, count);
			return count;
		}
	}

protected:
	nodeType<elemType>* root;

private:
	//Makes a copy of the binary tree to which 
	//otherTreeRoot points. 
	//Postcondition: The pointer copiedTreeRoot points to
	//               the root of the copied binary tree.
	void copyTree(nodeType<elemType>*& copiedTreeRoot, nodeType<elemType>* otherTreeRoot)
	{
		if (otherTreeRoot == nullptr)
			copiedTreeRoot = nullptr;
		else
		{
			copiedTreeRoot = new nodeType<elemType>;
			copiedTreeRoot->info = otherTreeRoot->info;
			copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
			copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
		}
	} //end copyTree


	  //Function to destroy the binary tree to which p points. 
	  //Postcondition: Memory space occupied by each node, in 
	  //               the binary tree to which p points, is 
	  //               deallocated.
	  //               p = nullptr;
	void destroy(nodeType<elemType>*& p)
	{
		if (p != nullptr)
		{
			destroy(p->lLink);
			destroy(p->rLink);
			delete p;
			p = nullptr;
		}
	}

	//Function to do an inorder traversal of the binary
	//tree to which p points.  
	//Postcondition: Nodes of the binary tree, to which p
	//               points, are printed in inorder sequence.
	void inorder(nodeType<elemType>* p) const
	{
		if (p != nullptr)
		{
			inorder(p->lLink);
			cout << p->info << " ";
			inorder(p->rLink);
		}
	}


	//Function to do a preorder traversal of the binary
	//tree to which p points.  
	//Postcondition: Nodes of the binary tree, to which p
	//               points, are printed in preorder 
	//               sequence.
	void preorder(nodeType<elemType>* p) const
	{
		if (p != nullptr)
		{
			cout << p->info << " ";
			preorder(p->lLink);
			preorder(p->rLink);
		}
	}

	//Function to do a postorder traversal of the binary
	//tree to which p points.  
	//Postcondition: Nodes of the binary tree, to which p
	//               points, are printed in postorder 
	//               sequence.
	void postorder(nodeType<elemType>* p) const
	{
		if (p != nullptr)
		{
			postorder(p->lLink);
			postorder(p->rLink);
			cout << p->info << " ";
		}
	}

	void postorderCompare(nodeType<elemType>* p, int &c) const
	{
		if (p != nullptr)
		{
			//Checks to see if the node has only one child
			if ((p->lLink == nullptr && p->rLink != nullptr) || (p->lLink != nullptr && p->rLink == nullptr)) {
				c++;
			}
			postorderCompare(p->lLink, c);
			postorderCompare(p->rLink, c);
		}
	}


	//Function to determine the height of the binary tree
	//to which p points. 
	//Postcondition: Height of the binary tree to which 
	//               p points is returned.
	int height(nodeType<elemType>* p) const
	{
		if (p == nullptr)
			return 0;
		else
			return 1 + max(height(p->lLink), height(p->rLink));
	}

	//Function to determine the larger of x and y.
	//Postcondition: Returns the larger of x and y.
	int max(int x, int y) const
	{
		if (x >= y)
			return x;
		else
			return y;
	}

	//Function to determine the number of nodes in 
	//the binary tree to which p points. 
	//Postcondition: The number of nodes in the binary 
	//               tree to which p points is returned.
	int nodeCount(nodeType<elemType>* p) const
	{
		if (p == nullptr)
			return 0;
		else
			return 1 + nodeCount(p->lLink) + nodeCount(p->rLink);
	}

	//Function to determine the number of leaves in  
	//the binary tree to which p points 
	//Postcondition: The number of leaves in the binary 
	//               tree to which p points is returned.
	int leavesCount(nodeType<elemType>* p) const
	{
		cout << "Write the definition of the function leavesCount." << endl;
		return 0;
	}

};

template <class elemType>
class bSearchTreeType : public binaryTreeType<elemType>
{
public:
	bool search(const elemType& searchItem) const
	{
		nodeType<elemType>* current;
		bool found = false;
		if (root == nullptr)
			cout << "Cannot search an empty tree." << endl;
		else
		{
			current = root;
			while (current != nullptr && !found)
			{
				if (current->info == searchItem)
					found = true;
				else if (current->info > searchItem)
					current = current->lLink;
				else
					current = current->rLink;
			}//end while
		}//end else
		return found;
	}//end search
	void insert(const elemType& insertItem)
	{
		nodeType<elemType>* current; //pointer to traverse the tree
		nodeType<elemType>* trailCurrent; //pointer behind current
		nodeType<elemType>* newNode; //pointer to create the node
		newNode = new nodeType<elemType>;
		newNode->info = insertItem;
		newNode->lLink = nullptr;
		newNode->rLink = nullptr;
		trailCurrent = NULL;
		if (root == nullptr)
			root = newNode;
		else
		{
			current = root;
			while (current != nullptr)
			{
				trailCurrent = current;
				if (current->info == insertItem)
				{
					cout << "The item to be inserted is already ";
					cout << "in the tree -- duplicates are not "
						<< "allowed." << endl;
					return;
				}
				else if (current->info > insertItem)
					current = current->lLink;
				else
					current = current->rLink;
			}//end while
			if (trailCurrent->info > insertItem) {
				trailCurrent->lLink = newNode;
			}
			else {
				trailCurrent->rLink = newNode;
			}
		}
	}//end insert
	void deleteNode(const elemType& deleteItem)
	{
		nodeType<elemType>* current; //pointer to traverse the tree
		nodeType<elemType>* trailCurrent; //pointer behind current
		bool found = false;
		if (root == nullptr)
			cout << "Cannot delete from an empty tree."
			<< endl;
		else
		{
			current = root;
			trailCurrent = root;
			while (current != nullptr && !found)
			{
				if (current->info == deleteItem)
					found = true;
				else
				{
					trailCurrent = current;
					if (current->info > deleteItem)
						current = current->lLink;
					else
						current = current->rLink;
				}
			}//end while
			if (current == nullptr)
				cout << "The item to be deleted is not in the tree."
				<< endl;
			else if (found)
			{
				if (current == root)
					deleteFromTree(root);
				else if (trailCurrent->info > deleteItem)
					deleteFromTree(trailCurrent->lLink);
				else
					deleteFromTree(trailCurrent->rLink);
			}
			else
				cout << "The item to be deleted is not in the tree."
				<< endl;
		}
	} //end deleteNode
protected:
	nodeType<elemType>* root;
private:
	void deleteFromTree(nodeType<elemType>*& p)
	{
		nodeType<elemType>* current; //pointer to traverse the tree
		nodeType<elemType>* trailCurrent; //pointer behind current
		nodeType<elemType>* temp; //pointer to delete the node
		if (p == nullptr)
			cout << "Error: The node to be deleted does not exist."
			<< endl;
		else if (p->lLink == nullptr && p->rLink == nullptr)
		{
			temp = p;
			p = nullptr;
			delete temp;
		}
		else if (p->lLink == nullptr)
		{
			temp = p;
			p = temp->rLink;
			delete temp;
		}
		else if (p->rLink == nullptr)
		{
			temp = p;
			p = temp->lLink;
			delete temp;
		}
		else
		{
			current = p->lLink;
			trailCurrent = nullptr;
			while (current->rLink != nullptr)
			{
				trailCurrent = current;
				current = current->rLink;
			}//end while
			p->info = current->info;
			if (trailCurrent == nullptr) //current did not move;
				//current == p->lLink; adjust p
				p->lLink = current->lLink;
			else
				trailCurrent->rLink = current->lLink;
			delete current;
		}//end else
	} //end deleteFromTree
};
#endif
