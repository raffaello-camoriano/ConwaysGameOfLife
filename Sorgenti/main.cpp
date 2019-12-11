
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "life.h"

using namespace std;

int main(int argc, char* argv[])	{

	life simulation;			//Genera una nuova simulazione
	long unsigned int iter = 1;
	int matCase = 0;
	char quit = '0';



	switch (argc) {

		case (1):		

			while ( quit != 'Q' ) {

				system ("cls");

				cout  <<"***LIFE SIMULATOR***" << endl << endl;
				simulation.menuMat(matCase);
				if (matCase == 0) break;
				simulation.enterMat(matCase);

				//Acquisizione numero iterazioni

				do {
					system ("cls");
					if ( iter < 1 || iter > 1000000 ) cout << "Numero di iterazioni non valido!" << endl;
					cout << "Insert the number of iterations needed (max 1000000):  ";
					cin >> iter;
				}	while ( iter < 1 || iter > 1000000 );

				system ("cls");

				//Visualizzazione simulazione

				for (unsigned int i=0; i < iter ; ++i) {
					
					
					simulation.viewMat( i );
					Sleep(600);					//Intervallo fra uno stato e il successivo
					simulation.nxtState();

				}

				cout << "Q to exit: ";
				cin >> quit;
			}
			break;	//End of Case 1

	case (2):

		system ("cls");
		cout  <<"***LIFE SIMULATOR***" << endl << "____Parsing Mode____"<< endl << endl;


		simulation.parseMat( argv[1] );		//Parser called with the .csv file as its argument

		//Number of iterations

		do {
			system ("cls");
			if ( iter < 1 || iter > 1000000 ) cout << "Numero di iterazioni non valido!" << endl;
			cout << "Insert the number of iterations needed (max 1000000):  ";
			cin >> iter;
		}	while ( iter < 1 || iter > 1000000 );

		system ("cls");

		for (unsigned int i=0; i < iter ; ++i) {
						
			simulation.viewMat( i );
			Sleep(400);
			simulation.nxtState();

		}

		system ("pause");

		break;
	}

	system ("cls");

}

