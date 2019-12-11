#include "life.h"


using namespace std;

life::life()	{

	population = 0;

	//matrix initialization
	
	for (unsigned int i=0; i<MSIZE; ++i ){
		for (unsigned int j=0; j<MSIZE; ++j ){

			matrix[i][j] = 0;
		}
	}

	//newMat initialization

	for (unsigned int i=0; i<MSIZE; ++i ){
		for (unsigned int j=0; j<MSIZE; ++j ){

			newMat[i][j] = 0;
		}
	}

}

int life::nxtState() {

	flag = 0;
	int alive;


	//This procedure calculates the number of alive neighbor cells

	for (int i=0; i<MSIZE; ++i){
		for (int j=0; j<MSIZE; ++j){

			alive=0;

			for ( int a=-1 ; a<2 ; ++a )	{
				for ( int b=-1 ; b<2 ; ++b )	{

					if ( a==0 && b==0 ) {}

					else {
						if ( matrix [( (i + a + MSIZE) % MSIZE )] [( (j + b + MSIZE) % MSIZE )] == 1 ) {++alive;}
					}
				}
			}



			//Conway's Game of Life rules implementation

			if ( alive < 2 || alive > 3 )	{
				newMat[i][j] = 0;						//Under and over-population cause cell death
				if (matrix[i][j] == 1) population--;
			}

			else if ( alive == 3 ) {
				newMat[i][j] = 1;						//Reproduction of the cell
				if (matrix[i][j] == 0) population++;
			}
			else if ( alive == 2 ) newMat[i][j] = matrix[i][j];		//Cell stays alive or dead

			if ( matrix[i][j] != newMat[i][j] ) {flag = 1;}
		}
	}

	if ( flag = 0 ) return 0;	//Stable equilibrium


	else	{

		// Update matrix

		for (int i=0; i<MSIZE; ++i){
			for (int j=0; j<MSIZE; ++j){
		
				matrix[i][j] = newMat[i][j];

			}
		}
	

		return 1;

		}
	}

void life::viewMat( int i ) {

	//ASCII borders codes

	char topleft = 201;
	char topright = 187;
	char botleft = 200;
	char botright = 188;
	char horizontal = 205;
	char vertical = 186;

	//Begin

	system ("cls");

	//Draw top margin

	cout << topleft;
	for (unsigned int k = 0 ; k < MSIZE ; ++k) cout << horizontal;
	cout << topright << endl;
	
	//Draw lines

	for (unsigned int p=0; p<MSIZE; ++p)	//2 nested loops to stamp Matrix
		{
			buffer.clear();
			cout << vertical;

			for (unsigned int q=0; q<MSIZE; ++q)
			{
				if (matrix[p][q] == 1) buffer += "O";
				else buffer += " ";
			}
			cout << buffer;
			cout << vertical << endl;
	}

	//Draw bottom margin

	cout << botleft;
	for (unsigned int j = 0 ; j < MSIZE ; ++j) cout << horizontal;
	cout << botright << endl;

	//Print statistics

	cout << "Population: " << population << endl;
	cout << "Iteration number: " << i + 1 << endl;


}

void life::menuMat(int &x)	{

	cout << endl << " 0_ Quit " << endl;
	cout << " 1_ Flying Kite" << endl;
	cout << " 2_ DRH Oscillator" << endl;
	cout << " 3_ Random matrix" << endl << endl;


	cout << "Select: ";
	cin >> x;
}

void life::enterMat(int &x)	{

	switch	( x )	{

		case 1:

			(*this).kiteMat();
			break;

		case 2:

			(*this).loopMat();
			break;

		case 3:

			(*this).randMat();
			break;

		default:
			(*this).randMat();


	}
}

void life::kiteMat()	{

		

	//matrix initialization

	
	for (unsigned int i=0; i<MSIZE; ++i ){
		for (unsigned int j=0; j<MSIZE; ++j ){

			matrix[i][j] = 0;
		}
	}

		
	//Flying kite:
	//	   O
	//	     O
	//	 O O O

	matrix[5][5] = 1;
	matrix[5][6] = 1;
	matrix[5][7] = 1;
	matrix[4][7] = 1;
	matrix[3][6] = 1;

	//Population  counter reset

	population = 0;

	for (unsigned int i=0; i<MSIZE; ++i ){
		for (unsigned int j=0; j<MSIZE; ++j ){

			if (matrix[i][j] == 1) population++;
		}
	}
}

void life::loopMat()	{

		//matrix initialization

	
	for (unsigned int i=0; i<MSIZE; ++i ){
		for (unsigned int j=0; j<MSIZE; ++j ){

			matrix[i][j] = 0;
		}
	}

		
	// Oscillator example
	//	  O  O
	//	 O OO O
	//	  O  O
	//	  O  O
	//	 O OO O
	//	  O  O

	int k = 12, h = 12;
	(*this).draw1( k, h );

	k = 15;
	(*this).draw1( k, h );

	(*this).draw1( h, k );

	h = 15;
	(*this).draw1( k, h );

	//Population  counter reset

	population = 0;

	for (unsigned int i=0; i<MSIZE; ++i ){
		for (unsigned int j=0; j<MSIZE; ++j ){

			if (matrix[i][j] == 1) population++;
		}
	}
}

void life::draw1(int x, int y)	{

	matrix[x-1][y] = 1;
	matrix[x+1][y] = 1;
	matrix[x][y-1] = 1;
	matrix[x][y+1] = 1;

}


void life::randMat()	{

	int iRand = 0;
	population = 0;

	/* initialize random seed: */
	srand ( time(NULL) );

	//matrix initialization
	
	for (unsigned int i=0; i<MSIZE; ++i ){
		for (unsigned int j=0; j<MSIZE; ++j ){



				/* generate secret number: */
				iRand = (rand() % 2 );
				matrix[i][j] = iRand;
				if (iRand == 1) population++;
		}
	}

	//newMat initialization

	for (unsigned int i=0; i<MSIZE; ++i ){
		for (unsigned int j=0; j<MSIZE; ++j ){

			newMat[i][j] = 0;
		}
	}



}
void life::parseMat(const char *input)	{

	population = 0;		//Population will be avaluated properly after the .csv file is parsed

	//declaration of useful variables while parsing the file

	int x;
	istringstream a;
	string s;
	string line;
	vector<int> v;

	ifstream file_in(input);

	//read and stamp the first line. It generally contains the names of the colons. In this case our csv file contains the coordinates (2D) of the lighted points. Once read and transformed into integers, the coordinates are temporarily stored in v: the asciss in v[0] and the ordinate in v[1]
	getline(file_in, line);
	cout << "File: " << input << endl << endl;
	cout << line << endl;

	while(file_in.peek()!= EOF)		//loop on the csv file
		{
			v.clear();
			line.clear();
			getline(file_in, line);	//read one line at a time
			
			
			for (unsigned int i=0;i<line.length();++i)//search numbers reppresenting the coordinates contained in the line
			 { 
				 while (line[i]!=',' && i!=line.length())	//stop if a comma or EOL encountered
				 {
					 s+=line[i];
					 ++i;
				 }
				 a.str(s);		//convert the string into a stream
				 a>>x;		//stream into x
				 v.push_back(x);	//store in v
				 cout << x << "\t";
				 
				 s.clear();
				 a.clear();
			 }

			cout << endl;

			(*this).matrix[v[0]-1][v[1]-1]=1;	//once the coordinates are read, set the corresponding point into the matrix

		}

	for (unsigned int i=0; i<MSIZE; ++i ){
		for (unsigned int j=0; j<MSIZE; ++j ){

			if (matrix[i][j] == 1) population++;
		}
	}

	cout << endl;
	system ("pause");
}