#include <stdlib.h>
#include <ctime>
#include <vector>
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <sstream>


using namespace std;
static const int MSIZE = 30;

class life {


	public:
	//Data

	string buffer;		//Used in matrix printing
	bool flag;			//Stable-state flag

	int matrix [MSIZE][MSIZE];
	int newMat [MSIZE][MSIZE];

	//Matrix configurations

	void kiteMat();
	void loopMat();
	void randMat();
	void parseMat(const char* input);

	void draw1( int x, int y );		//Support function



	unsigned int population;

	//Metodi

	life();								//Base constructor (empty matrix)
	int nxtState();						//Next state calculus
	void viewMat( int i );				//Page refresh
	void menuMat(int &x);				//Predefined initial-state matrix menu
	void enterMat(int &x);				//New matrix instance 


};