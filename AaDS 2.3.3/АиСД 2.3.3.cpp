#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Node {
public:
	int key;
	int size;
	Node* left;
	Node* right;
	bool ltag;
	bool rtag;
	Node(int x) : key(x), size(1), left(nullptr), right(nullptr), ltag(false), rtag(false) {};
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

int calculateTreesSize(Node* v) {
	if (v == nullptr) return 0;
	v->size = 1 + calculateTreesSize(v->left) + calculateTreesSize(v->right);
	return v->size;
}

void findVershini(Node* v, vector<int>& vershForMid) {
	if (v == nullptr) return;
	int leftSize = 0;
	if (v->left != nullptr) {
		leftSize = v->left->size;
	}
	int rightSize = 0;
	if (v->right != nullptr) {
		rightSize = v->right->size;
	}
	if (abs(leftSize - rightSize) == 1) {
		vershForMid.push_back(v->key);
	}
	findVershini(v->left, vershForMid);
	findVershini(v->right, vershForMid);
}

void PreOrderTravesal(Node* v, vector<int>& fileWrite) {
	if (v == nullptr) return;
	fileWrite.push_back(v->key);
	PreOrderTravesal(v->left, fileWrite);
	PreOrderTravesal(v->right, fileWrite);
}

int main() {
	Tree tree;
	ifstream filein("in.txt");
	ofstream fileout("out.txt");
	vector<int> versh;
	vector<int> fileWrite;
	vector<int> vershForMid;
	int temp;
	while (filein >> temp) {
		versh.push_back(temp);
	}
	for (int i = 0; i < versh.size(); i++) {
		tree.root = createTree(tree.root, versh[i]);
	}
	calculateTreesSize(tree.root);
	findVershini(tree.root, vershForMid);
	if (!vershForMid.empty()) {
		sort(vershForMid.begin(), vershForMid.end());
		if (vershForMid.size() % 2 != 0) {
			int sizeV = vershForMid.size();
			int mid = vershForMid[sizeV / 2];
			tree.root = deleteElem(tree.root, mid);
		}
	}
	PreOrderTravesal(tree.root, fileWrite);
	for (int i = 0; i < fileWrite.size(); i++) {
		fileout << fileWrite[i] << endl;
	}
	filein.close();
	fileout.close();
	return 0;
}