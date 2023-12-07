#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

Node* insert(Node* root, int x)
{
	if (root == NULL)
		return new Node(x);
	if (x < root->data)
		root->left = insert(root->left, x);
	else if (x > root->data)
		root->right = insert(root->right, x);
	return root;
}

int count = 0;
Node* kthSmallest(Node* root, int& k)
{
	if (root == NULL)
		return NULL;

	Node* left = kthSmallest(root->left, k);

	if (left != NULL)
		return left;

	count++;
	if (count == k)
		return root;

	return kthSmallest(root->right, k);
}
void printKthSmallest(Node* root, int k)
{

	Node* res = kthSmallest(root, k);
	if (res == NULL)
		cout << "There are less than k nodes in the BST";
	else
		cout << "K-th Smallest Element is " << res->data;
}

int main()
{
	Node* root = NULL;
	int keys[] = { 20, 8, 22, 4, 12, 10, 14 };

	for (int x : keys)
		root = insert(root, x);

	int k = 3;
	printKthSmallest(root, k);
	return 0;
}

