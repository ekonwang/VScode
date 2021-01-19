#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
class TreeNode {
public:
	TreeNode() {
		value = 0; leftchild = NULL; rightchild = NULL;
	}
	TreeNode(int& x) {
		value = x;
		leftchild = NULL;
		rightchild = NULL;
	}
	TreeNode* leftchild;
	TreeNode* rightchild;
	int value;
};
TreeNode* buildTree(vector<int> arr) {
	if (arr.size() == 0)
		return NULL;
	TreeNode* root = new TreeNode(arr[0]);
	queue<TreeNode*> q;
	q.push(root);
	int i = 1;
	while (i < arr.size()) {
		TreeNode* node = q.front();
		q.pop();
		if (node != NULL) {
			TreeNode* l = (arr[i] != -1) ? new TreeNode(arr[i]) : NULL;
			TreeNode* r = ((i + 1) < arr.size() && arr[i + 1] != -1) ? new TreeNode(arr[i + 1]) : NULL;
			node->leftchild = l;
			node->rightchild = r;
			q.push(l);
			q.push(r);
			i += 2;
		}
	}
	return root;
}
bool GetPath(TreeNode* root, int n) {
	bool flag = false;
	if (root == NULL) return false;
	if (root->value == n) return true;
	if (GetPath(root->leftchild, n - root->value))
		return GetPath(root->leftchild, n - root->value);
	else if (GetPath(root->rightchild, n - root->value))
		return GetPath(root->rightchild, n - root->value);
	else return false;
}
void pre_traversal(TreeNode* root) {
	stack<TreeNode*> st;
	TreeNode* p = root;
	while (p || !st.empty()) {
		if (p) {
			st.push(p);
			cout << p->value << " ";
			p = p->leftchild;
		}
		else {
			p = st.top();
			st.pop();
			p = p->rightchild;
		}
	}
	cout << endl;
}
int main() {
	int v, n;
	vector<int> a;
	//cout << "enter the values one by one(must be >= 0):" << endl;
	while (cin >> v) {
		a.push_back(v);
		if (cin.get() == '\n')
			break;
	}
	TreeNode* root = buildTree(a);
	//pre_traversal(root);
	cin >> n;
	if (GetPath(root, n)) cout << "true";
	else cout << "false";
	//system("pause");
	return 0;
}
