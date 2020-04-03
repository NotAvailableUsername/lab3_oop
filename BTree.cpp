// Lab3.cpp : Defines the entry point for the application.
//

#include "iostream"
#include "string"
#include "BTree.h"

using namespace std;

class Node {
public:
	int key;
	Node* x;
	Node* y;
};

class Tree {
public:
	Node* root;
	//contructor
	Tree init_Tree() {
		root = NULL;
	}
	//insert
	void insert(int v, Node* n) {

		if (v < n->key) {
			if (n->x != NULL) {
				insert(v, n->x);
			}
			else {
				n->x = new Node;
				n->x->key = v;
				n->x->x = NULL;
				n->x->y = NULL;
			}
		}
		else if (v >= n->key) {
			if (n->y != NULL) {
				insert(v, n->y);
			}
			else {
				n->y = new Node;
				n->y->key = v;
				n->y->y = NULL;
				n->y->x = NULL;
			}
		}
	}

	void delete_(int key, Node* n) {
		if (n == NULL)
			return;

		if (key < n->key)
			delete_(key, n->x);

		else
			if (key > n->key)
				delete_(key, n->x);
			else {

				if (n->x == NULL && n->y == NULL) {
					delete(n);
					n = NULL;
				}

				else
					if (n->x == NULL) {
						Node* m = n;
						n = n->y;
						delete m;
					}
					else
						if (n->y == NULL) {
							Node* m = n;
							n = n->x;
							delete m;
						}
			}
	}

	string inorder(Node* n) {
		string rightS, leftS;
		if (n->x != NULL)
			leftS = inorder(n->x);
		else leftS = "";

		if (n->y != NULL)
			rightS = inorder(n->y);
		else rightS = "";

		return leftS + " " + to_string(n->key) + " " + rightS;
		
	}

	string preorder(Node* n) {
		string rightS, leftS;
		if (n->x != NULL)
			leftS = preorder(n->x);
		else leftS = "";

		if (n->y != NULL)
			rightS = preorder(n->y);
		else rightS = "";

		return to_string(n->key) + " " + rightS + " " + leftS;
	}
	
	string postorder(Node* n) {
		string rightS, leftS;
		if (n->x != NULL)
			leftS = postorder(n->x);
		else leftS = "";

		if (n->y != NULL)
			rightS = postorder(n->y);
		else rightS = "";

		return rightS + " " + to_string(n->key) + " " + leftS;
	}

	int countNodes(Node* n) {
		int k = 0;
		if (n == NULL)
			return k;
		else
			if (n->x != NULL)
				k = 1 + countNodes(n->x);
			else
				if (n->y != NULL)
					k = 1 + countNodes(n->y);
		return k;
	}

	int countEdges(Node* n) {
		return countNodes(n) - 1;
	}

	int height(Node* n) {
		if (n == NULL)
			return 0;
		int l = height(n->x);
		int r = height(n->y);

		if (l > r)
			return(l + 1);
		else 
			return(r + 1);
	}
};


int main()
{
	Tree* BTree = new Tree;
	Node* n = new Node;

	n->key = 20;
	n->x = NULL;
	n->y = NULL;

	BTree->insert(1, n);
	BTree->insert(2, n);
	BTree->insert(3, n);
	BTree->insert(4, n);
	BTree->insert(5, n);
	BTree->insert(6, n);
	BTree->insert(7, n);
	BTree->insert(8, n);

	cout << BTree->countNodes(n);
	cout << "\n";
	cout << BTree->countEdges(n);
	cout << "\n";
	cout << BTree->height(n);

	delete BTree;
	delete n;

	return 0;
}
