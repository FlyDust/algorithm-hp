
struct BSTNode {
	int key;
	BSTNode *lchild;
	BSTNode *rchild;
	BSTBode *parent;
};

class BST {
private:
	BSTNode *root;
public:
	void BST();
	void inorder_tree_walk();	//递归中序遍历
	void iterative_inorder_tree_walk();	//迭代中序遍历
	void tree_search(int key);	//递归查找
	void iterative_tree_search(int key);	//迭代查找
	BSTNode* tree_minimum();
	BSTNode* tree_maximum();
	BSTNode* tree_successor(BSTNode *node);
	BSTNode* tree_insert(int key);
	void tree_delete(int key);

	void ~BST();
}
