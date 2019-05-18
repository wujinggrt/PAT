#include <cmath>
#include <queue>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct Node {
	int val;
	int height;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(int _val)
		: val(_val), height(1) {}
};

int GetHeight(Node* root);
Node* FindMin(Node* root);
void RotateLeft(Node*  & root);
void RotateRight(Node*& root);
void DoubleRotateLeft(Node* & root);
void DoubleRotateRight(Node* & root);
void Insert(Node* & root, int val);
void Balance(Node* & root);
void LevelOrder(Node* root);

static const int kAllowedImbalance = 1;

int main() {
	int n;
	cin >> n;
	Node* root = nullptr;
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		Insert(root, val);
	}
	LevelOrder(root);
	int maxn = 0;
	function<void(Node*, int)> is_complete = [&] (Node* root, int index) {
		if (root == nullptr) {
			return;
		}
		if (index > maxn) {
			maxn = index;
		}
		if (root->left != nullptr) {
			is_complete(root->left, index * 2);
		}
		if (root->right != nullptr) {
			is_complete(root->right, index * 2 + 1);
		}
	};
	is_complete(root, 1);
	cout << (maxn == n ? "\nYES\n" : "\nNO\n");
    return 0;
}

int GetHeight(Node* t) {
	return t == nullptr ? 0 : t->height;
}

Node* FindMin(Node* root) {
	Node* min_node = root;
	while (root != nullptr) {
		root = root->left;
	}

	return min_node;
}

// AVL 书的操作只有 root 和 过长而不平衡的那一端来旋转，
// 所以不用担心旋转的左右指针会有 nullptr 的情况。
void RotateLeft(Node* & root) {
	auto left = root->left;
	root->left = left->right;
	left->right = root;

	root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
	left->height = max(GetHeight(left->left), root->height) + 1;

	root = left;
}

void RotateRight(Node* & root) {
	auto right = root->right;
	root->right = right->left;
	right->left = root;

	root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
	right->height = max(GetHeight(right->right), root->height) + 1;

	root = right;
}

void DoubleRotateLeft(Node* & root) {
	RotateRight(root->left);
	RotateLeft(root);
}

void DoubleRotateRight(Node* & root) {
	RotateLeft(root->right);
	RotateRight(root);
}

// 平衡
void Balance(Node* & root) {
	int left_height = GetHeight(root->left);
	int right_height = GetHeight(root->right);
	if (abs(left_height - right_height) > kAllowedImbalance) {
		if (left_height > right_height) {
			if (GetHeight(root->left->left) > GetHeight(root->left->right)) {
				RotateLeft(root);
			} else {
				DoubleRotateLeft(root);
			}
		} else {
			if (GetHeight(root->right->right) > GetHeight(root->right->left)) {
				RotateRight(root);
			} else {
				DoubleRotateRight(root);
			}
		}
	}
	root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
}

void Insert(Node* & root, int val) {
	if (root == nullptr) {
		root = new Node{val};
	}
	if (val < root->val) {
		Insert(root->left, val);
	} else if (val > root->val) {
		Insert(root->right, val);
	} else {

	}
	Balance(root);
}

void LevelOrder(Node* root) {
	if (root == nullptr) {
		return;
	}
	queue<Node*> q;
	bool first = true;
	q.push(root);
	while (!q.empty()) {
		auto node = q.front();
		if (first) {
			first = false;
		} else {
			cout << " ";
		}
		cout << node->val;
		q.pop();
		if (node->left != nullptr) {
			q.push(node->left);
		}
		if (node->right != nullptr) {
			q.push(node->right);
		}
	}
}
