#include <iostream>
#include <queue>
using namespace std;

struct node{
    node( int, node*, node*);
	int c;
	node* left;
	node* right;
	
	//bool operator<(conc node &rhs) conc{
	//	return ( c < rhs.c );
	//}
};

node::node(int x, node* l=0, node* r=0){
    c=x;
    left=l;
    right=r;
}

void prewalk(node* nd){
	if (nd==0) return;
	cout<<(nd->c)<<" ";
	prewalk(nd->left);
	prewalk(nd->right);
}

void postwalk(node* nd){
	if (nd==0) return;
	postwalk(nd->left);
	postwalk(nd->right);
	cout<<(nd->c)<<" ";
}

void inwalk(node* nd){
	if (nd==0) return;
	inwalk(nd->left);
	cout<<(nd->c)<<" ";
	inwalk(nd->right);
}

void breadthwalk(node* nd){
	queue <node*> q;
	q.push(nd);
	while (!q.empty()){
		cout<<(q.front()->c)<<" ";
		if (q.front()->left != 0) q.push(q.front()->left);
		if (q.front()->right != 0) q.push(q.front()->right);
		q.pop();
	}
}

/* must pass nd by ref since we may need to insert at the
root node and hence change the root addr */
void insert(node* &nd, int c){  // inserts with order
	if (nd==0) nd=new node(c,nd,nd);
	else if (nd->c < c) insert(nd->right, c);
	else insert(nd->left,c);
}


	
void btfree(node* root){ //which order should deleting be: (pre, in, post ) only one of them will work ONLY POST ORDER WORKS
	if (root==0) return;
	btfree(root->left);
	btfree(root->right);
	delete root;
}



int main(){
	
	const int iarray[7] = {4,2,6,1,3,5,7};
	node* root=0;
	
	int x;
	for (x=0; x < 7 ; x++)
	{
		insert(root, iarray[x]);
		//walk(root);
		//cout<<endl;
	}

	prewalk(root);
	cout<<endl;
	
	postwalk(root);
	cout<<endl;
	
	inwalk(root);
	cout<<endl;
	
    breadthwalk(root);
    cout<<endl;
	
	btfree(root);
    
	return (0);
}

