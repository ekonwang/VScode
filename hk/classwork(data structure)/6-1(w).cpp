#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
 struct TreeNode {
	int value;
	struct TreeNode *leftchild;
	struct TreeNode *rightchild;
	explicit TreeNode(int x) : value(x), leftchild(NULL), rightchild(NULL) {}
};
TreeNode* buildTree(vector<int> arr) {
	if(arr.size() == 0)
		return NULL;
	TreeNode *root = new TreeNode(arr[0]);
	queue<TreeNode*> q;
	q.push(root);
	int i = 1;
	while(i < arr.size()) {
		TreeNode *node = q.front();
		q.pop();
		if(node != NULL) {
			TreeNode *l = (arr[i] != -1)? new TreeNode(arr[i]) : NULL;
			TreeNode *r = ((i + 1) < arr.size() && arr[i + 1] != -1)? new TreeNode(arr[i + 1]) : NULL;
			node->leftchild = l;
			node->rightchild = r;
			q.push(l);
			q.push(r);
			i += 2;
		}
	}
	return root;
}
void  pre_traversal(TreeNode *root)
{
	stack<TreeNode *>s;
	TreeNode *temp=root;
	while(temp!=NULL)
	{
		cout<<temp->value<<" ";
		if(temp->rightchild !=NULL)s.push(temp->rightchild );
		if(temp->leftchild !=NULL)temp=temp->leftchild ;
		else if(!s.empty ()){temp=s.top();s.pop();}
		else temp=NULL;
	}
}
bool addtree(TreeNode *root,int sum1)
{
	stack<TreeNode *>s;
	vector<int>a;
	vector <int>::iterator out;
	int i=0;
	TreeNode *temp=root;
	int sum=root->value ;
	while(temp!=NULL)
	{
		if(temp->rightchild !=NULL){s.push(temp->rightchild );};
		if(temp->leftchild !=NULL){temp=temp->leftchild;sum+=temp->value ;if(temp->leftchild ==NULL&&temp->rightchild==NULL ){a.push_back (sum);sum-=temp->value ;}}
		else if(!s.empty ()){temp=s.top();s.pop();sum+=temp->value ;if(temp->leftchild ==NULL&&temp->rightchild==NULL ){a.push_back (sum);sum-=temp->value ;}}
		else temp=NULL;
	}
	for(out=a.begin ();out!=a.end();out++)
	{
		if(*out==sum1)return true;
	}
	return false;
}
//
int main()  
{
    int v,sum;
	vector<int> b;
	//cout <<"enter the values one by one(must be >= 0):"<<endl;
	while(cin >> v) {
		b.push_back(v);
		if (cin.get() == '\n')
        break;
	}
	cin>>sum;
    TreeNode *root = buildTree(b);
	//cout<<endl;
	cout<< boolalpha << addtree (root,sum);
	//system("pause");
	return 0;
}

