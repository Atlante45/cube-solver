/*
Rubiks
Cl�ment BRISSET et Julien CHAUMONT
Janvier 2010 - Juin 2010
Librairies utilis�es: librairies mingw32 par d�faut
IDE utilis�: CodeBlocks 8.02
*/

/*
--------------------------------------------------
Fichier main.cpp:
Appel du constructeur
--------------------------------------------------
*/

#include "Cube.h"

using namespace std;

int main()
{

    srand(time(NULL));  //Initialisation du g�n�rateur de nombres al�atoires

    Cube(); //Appel du consructeur

    system("PAUSE");
    return EXIT_SUCCESS;
}
