/*
Rubiks
Clément BRISSET et Julien CHAUMONT
Janvier 2010
Librairies utilisées: librairies mingw32 par défaut
IDE utilisé: CodeBlocks 8.02
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
    srand(time(NULL));  //Initialisation du générateur de nombres aléatoires
    Cube(); //Appel du consructeur

    system("PAUSE");
    return EXIT_SUCCESS;
}
