/*
 * mainWordHub.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: Debra
 */


//#include "AVLTree.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Game.hpp"

using namespace std;

int main() {

	srand(time(NULL));

	cout << "Test 1" << endl;
	//Game *game = new Game("testdict.txt",false);

	cout << "************************************************************" << endl;

	cout << "Test 2" << endl;
	//Game *game2 = new Game("commondict.txt", false);
	//game2->startGame();

	cout << "************************************************************" << endl;

	cout << "Test 3" << endl;
	Game *game3 = new Game("testdict.txt",true);

	cout << "************************************************************" << endl;

	cout << "Test 4" << endl;
	game3->startGame();

	return 0;
}

