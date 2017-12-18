/*
 * AVLTree.cpp
 *
 *  Created on: Nov 10, 2017
 *      Author: ryan
 */

#include "AVLTree.hpp"
#include <iostream>
using namespace std;

AVLTree::AVLTree(bool flag){
	root = NULL;
	AVLflag = flag;
}

bool AVLTree::findWord(string s,NodeT *n){
	if(n==NULL){
		return false;
	}
	else if(s==n->word){
		return true;
	}
	else if(s<n->word){
		return findWord(s,n->left);
	}
	else{
		return findWord(s,n->right);
	}
}

void AVLTree::addNode(string s,NodeT *r){
	if(r==NULL){
		cout << "Made root" << endl;
		NodeT *newnode = new NodeT(s);
		root = newnode;
	}
	else if(s<r->word){
		if(r->left==NULL){
			cout << "Inserting to left of " << r->word << endl;
			NodeT *newnode = new NodeT(s);
			r->left = newnode;
			newnode->parent = r;
			adjustHeights(newnode);
			cout << endl;
		}
		else{
			cout << "Looking left of " << r->word << endl;
			addNode(s,r->left);
		}
	}
	else{
		if(r->right==NULL){
			cout << "Inserting to right of " << r->word << endl;
			NodeT *newnode = new NodeT(s);
			r->right = newnode;
			newnode->parent = r;
			adjustHeights(newnode);
			cout << endl;
		}
		else{
			cout << "Looking right of " << r->word << endl;
			addNode(s,r->right);
		}
	}
}

void AVLTree::printIO(NodeT *root){
	if(root==NULL){
		return;
	}

	printIO(root->left);

	cout << root->height << ":" << root->word << " " << endl;

	printIO(root->right);
}

void AVLTree::printPre(NodeT *root){
	if(root==NULL){
		return;
	}

	cout << root->height << ":" << root->word << " " << endl;

	printPre(root->left);

	printPre(root->right);
}

void AVLTree::printPost(NodeT *root){
	if(root==NULL){
		return;
	}

	printPost(root->left);

	printPost(root->right);

	cout << root->height << ":" << root->word << " " << endl;
}

void AVLTree::adjustHeights(NodeT *n){

	if(AVLflag){
		n->height = getMax(n);

		int balance = getDiff(n);

		if(balance==2){
			if(getDiff(n->left)==1){
				cout << "Rotating right around " << n->word << endl;
				rotateRight(n);
				adjustHeights(n);
			}
			else{
				cout << "Left-right rotation on " << n->word << endl;
				cout << "First rotating left around " << n->left->word << endl;
				rotateLeft(n->left);
				cout << "Rotating right around " << n->word << endl;
				rotateRight(n);
				adjustHeights(n);
			}
		}
		else if(balance==-2){
			if(getDiff(n->right)==-1){
				cout << "Rotating left around " << n->word << endl;
				rotateLeft(n);
				adjustHeights(n);
			}
			else{
				cout << "Right-left rotation on " << n->word << endl;
				cout << "First rotating right around " << n->right->word << endl;
				rotateRight(n->right);
				cout << "Rotating left around " << n->word << endl;
				rotateLeft(n);
				adjustHeights(n);
			}
		}
	}
	else{
		n->height = getMax(n);
	}

	if(n->parent != NULL){
		adjustHeights(n->parent);
	}
}

int AVLTree::getMax(NodeT *n){
	int lmax;
	if(n->left==NULL){
		lmax = 1;
	}
	else{
		lmax = 1 + getMax(n->left);
	}

	int rmax;
	if(n->right==NULL){
		rmax = 1;
	}
	else{
		rmax = 1 + getMax(n->right);
	}

	if(lmax>=rmax){
		return lmax;
	}
	else{
		return rmax;
	}
}

NodeT *AVLTree::rotateRight(NodeT *n){
	NodeT *x = n->left;
	NodeT *tmp = x->right;

	cout << "Height of node before: " << n->word << ":" << n->height << endl;
	cout << "Height of left child before: " << x->word << ":" << x->height << endl;

	x->right = n;
	n->left = tmp;

	n->height = getMax(n);
	x->height = getMax(x);

	cout << "Height of " << n->word << " now " << n->height << endl;
	cout << "Height of " << x->word << " now " << x->height << endl;

	if(root->word == n->word){
		root = x;
		cout << x->word << " is new root" << endl;
	}
	else if(n->parent->right != NULL && n->parent->right->word == n->word){
		cout << "Resetting " << n->parent->word << "'s right to " << x->word << endl;
		n->parent->right = x;
	}
	else{
		cout << "Resetting " << n->parent->word << "'s left to " << x->word << endl;
		n->parent->left = x;
	}

	x->parent = n->parent;
	n->parent = x;

	if(tmp!=NULL){
		tmp->parent = n;
		tmp->height = getMax(tmp);
	}

	return x;
}

NodeT *AVLTree::rotateLeft(NodeT *n){
	NodeT *x = n->right;
	NodeT *tmp = x->left;

	cout << "Height of node before: " << n->word << ":" << n->height << endl;
	cout << "Height of left child before: " << x->word << ":" << x->height << endl;

	x->left = n;
	n->right = tmp;

	n->height = getMax(n);
	x->height = getMax(x);

	cout << "Height of " << n->word << " now " << n->height << endl;
	cout << "Height of " << x->word << " now " << x->height << endl;

	if(root->word == n->word){
		root = x;
		cout << x->word << " is new root" << endl;
	}
	else if(n->parent->right != NULL && n->parent->right->word == n->word){
		cout << "Resetting " << n->parent->word << "'s right to " << x->word << endl;
		n->parent->right = x;
	}
	else{
		cout << "Resetting " << n->parent->word << "'s left to " << x->word << endl;
		n->parent->left = x;
	}

	x->parent = n->parent;
	n->parent = x;


	if(tmp!=NULL){
		tmp->parent = n;
		tmp->height = getMax(tmp);
	}

	return x;
}

int AVLTree::getDiff(NodeT *n){
	int lh,rh;

	if(n->left==NULL){
		lh = 0;
	}
	else{
		lh = n->left->height;
	}

	if(n->right==NULL){
		rh = 0;
	}
	else{
		rh = n->right->height;
	}
	return lh - rh;
}
