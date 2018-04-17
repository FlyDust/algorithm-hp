#include "bst.h"

void BST::BST()
{
	root = NULL;
}

void tree_destroy(BSTNode *T)
{
	if(T != NULL){
		destroy(T->lchild);
		destroy(T->rchild);
		delete T;
	}
}

void BST::~BST()
{
	tree_destroy(root);
}

BSTNode* BST::tree_insert(int key)
{
	BSTNode *insert_node = new BSTNode;
	insert_node->key = key;
	insert_node->lchild = NULL;
	insert_node->rchild = NULL;
	if(root == NULL){
		root = insert_node;
		root->parent = NULL;
		return root;
	}
	BSTNode *tmp = root, *parent;
	while(tmp != NULL){
		parent = tmp;
		if(insert_node->key < tmp->key){
			tmp = tmp->left;
		}
		else{
			tmp = tmp->right;
		}
	}
	insert_node->parent = parent;
	if(insert_node->key < parent->key){
		parent->lchild = insert_node;
	}
	else{
		parent->rchild = insert_node;
	}
	return insert_node;
}

void transplant(BSTNode *u,BSTNode *v)
{
	if(u->parent == NULL){
		root = v;
	}
	else if(u == u->parent->lchild){
		u->parent->lchild = v;
	}
	else{
		u->parent->rchild = v;
	}
	if(v != NULL){
		v->parent = u->parent;
	}
}

void BST::tree_delete(int key)
{
	BSTNode *tmp = root;
	while(tmp != NULL && key != tmp->key){
		if(key < tmp->key)
			tmp = tmp->lchild;
		else if(key > tmp->key)
			tmp = tmp->rchild;
	}
	if(tmp == NULL)
		return;
	if(tmp->lchild == NULL){
		transplant(tmp, tmp->rchild);
	}
	else if(tmp->rchild == NULL){
		transplant(tmp, tmp->lchild):
	}
	else{
		
	}
}
