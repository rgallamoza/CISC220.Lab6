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

bool AVLTree::findWord(string s,NodeT *n){// Assuming you start at root
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

void AVLTree::addNode(string s,NodeT *r){// Assuming you start at root
	if(r==NULL){
		NodeT *newnode = new NodeT(s);
		root = newnode;
	}
	else if(s<r->word){
		if(r->left==NULL){
			//r->height++;
			NodeT *newnode = new NodeT(s);
			r->left = newnode;
			newnode->parent = r;
		}
		else{
			//r->height++;
			addNode(s,r->left);
		}
	}
	else{
		if(r->right==NULL){
			//r->height++;
			NodeT *newnode = new NodeT(s);
			r->right = newnode;
			newnode->parent = r;
		}
		else{
			//r->height++;
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
		int balance = getDiff(n);

		if(balance==2){
			if(getDiff(n->left)==1){
				rotateRight(n);
			}
			else{
				rotateLeft(n->left);
				rotateRight(n);
			}
		}
		else if(balance==-2){
			if(getDiff(n->right)==-1){
				rotateLeft(n);
			}
			else{
				rotateRight(n->right);
				rotateLeft(n);
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
	if(n->left==NULL && n->right==NULL){
		return 0;
	}
	else{
		int lmax;
		if(n->left==NULL){
			lmax = 0;
		}
		else{
			lmax = 1 + getMax(n->left);
		}

		int rmax;
		if(n->right==NULL){
			rmax = 0;
		}
		else{
			rmax = 1 + getMax(n->right);
		}

		if(lmax<=rmax){
			return lmax;
		}
		else{
			return rmax;
		}
	}
}

NodeT *AVLTree::rotateRight(NodeT *n){
	NodeT *x = n->left;
	NodeT *tmp = x->right;

	// Perform rotation
	x->right = n;
	n->left = tmp;

	/*
	// Update heights
	if (n->left->height > n->right->height) {
			n->height = n->left->height + 1;
	}
	else {
			n->height =n->right->height + 1;
	}
	if (x->left->height > x->right->height) {
			x->height = x->left->height + 1;
	}
	else {
			x->height = x->right->height+1;
	}
	*/

	return x; // Return new root
}

NodeT *AVLTree::rotateLeft(NodeT *n){

}

int AVLTree::getDiff(NodeT *n){
	return (getMax(n->left) - getMax(n->right));
}








