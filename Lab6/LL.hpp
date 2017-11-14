/*
 * LL.hpp
 *
 *  Created on: Nov 10, 2017
 *      Author: ryan
 */

#ifndef LL_HPP_
#define LL_HPP_
#include <iostream>
#include <string>
#include "NodeL.hpp"
using namespace std;

class LL{
	NodeL *first;
	NodeL *last;
	int size;
	int score;
public:
	LL();
	void push(string s);
	void addFirst(string s);
	void printList();
	void getScore();
};



#endif /* LL_HPP_ */
