#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Node {
public:
	int key;
	Node* left;
	Node* right;
	bool ltag;
	bool rtag;
	Node(int x) : key(x), left(nullptr), right(nullptr), ltag(false), rtag(false) {};
};

class Tree {
public:
	Node* root;
	Tree() : root(nullptr) {};

};

Node* createTree(Node* v, int elem) {
	if (v == nullptr) {
		return new Node(elem);
	}
	if (elem < v->key) {
		v->left = createTree(v->left, elem);
	}
	else if (elem > v->key) {
		v->right = createTree(v->right, elem);
	}
	return v;
}

Node* minElem(Node* v) {
	if (v->left != nullptr) {
		return minElem(v->left);
	}
	else return v;
}

Node* deleteElem(Node* v, int elem) {
	if (v == nullptr) {
		return nullptr;
	}
	if (elem < v->key) {
		v->left = deleteElem(v->left, elem);
	}
	else if (elem > v->key) {
		v->right = deleteElem(v->right, elem);
	}
	else {
		if (v->left == nullptr) {
			return v->right;
		}
		else if (v->right == nullptr) {
			return v->left;
		}
		else {
			Node* minEl = minElem(v->right);
			v->key = minEl->key;
			v->right = deleteElem(v->right, minEl->key);
		}
	}
	return v;
}

void preOrderTraversal(Node* v, vector<int>& fileWrite) {
	if (v == nullptr) {
		return;
	}
	fileWrite.push_back(v->key);
	preOrderTraversal(v->left, fileWrite);
	preOrderTraversal(v->right, fileWrite);

}

int main() {
	Tree tree;
	ifstream filein("input.txt");
	ofstream fileout("output.txt");
	vector<int> readFile;
	vector<int> fileWrite;
	int temp;
	int elemForDel;
	filein >> elemForDel;
	while (filein >> temp) {
		readFile.push_back(temp);
	}
	int size = readFile.size();
	for (int i = 0; i < size; i++) {
		tree.root = createTree(tree.root, readFile[i]);
	}
	tree.root = deleteElem(tree.root, elemForDel);
	preOrderTraversal(tree.root, fileWrite);
	for (int i = 0; i < fileWrite.size(); i++) {
		fileout << fileWrite[i] << endl;
	}
	return 0;
}