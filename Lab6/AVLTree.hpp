/*
 * AVLTree.hpp
 *
 *  Created on: Nov 10, 2017
 *      Author: ryan
 */

#ifndef AVLTREE_HPP_
#define AVLTREE_HPP_
#include <iostream>
#include <string>
#include "NodeT.hpp"
using namespace std;

class AVLTree{
	friend class Game;
	NodeT *root;
	bool AVLflag;
public:
	AVLTree(bool flag);
	bool findWord(string s,NodeT *n);
	void addNode(string s,NodeT *r);
	void printIO(NodeT *root);
	void printPre(NodeT *root);
	void printPost(NodeT *root);
	void adjustHeights(NodeT *n);
	int getMax(NodeT *n);
	NodeT *rotateRight(NodeT *n);
	NodeT *rotateLeft(NodeT *n);
	int getDiff(NodeT *n);
};



#endif /* AVLTREE_HPP_ */
