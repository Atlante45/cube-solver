/*
Rubiks
Clément BRISSET et Julien CHAUMONT
Janvier 2010
Librairies utilisées: librairies mingw32 par défaut
IDE utilisé: CodeBlocks 8.02
*/

/*
--------------------------------------------------
Fichier divers.cpp:
Fonctions diverses
--------------------------------------------------
*/

#include "Cube.h"

using namespace std;

void Cube::lecture_string(string combinaison)
{
    for(int i=0; i<combinaison.size();i=i+2)
    {
        string stringTemp1 = combinaison.substr(i,1);
        string stringTemp2 = combinaison.substr(i+1,1);
        int intTemp = 0;

        if(stringTemp2=="0")
            intTemp = 0;
        else if(stringTemp2=="1")
            intTemp = 1;
        else if(stringTemp2=="2")
            intTemp = 2;
        else if(stringTemp2=="3")
            intTemp = 3;
        else if(stringTemp2=="4")
            intTemp = 4;
        else if(stringTemp2=="5")
            intTemp = 5;
        else
            affichage_erreur("Mauvaise syntaxe de string combinaison");

        if (stringTemp1=="p")
            tourner_face_plus(intTemp);
        else if (stringTemp1=="m")
            tourner_face_moins(intTemp);
        else
            affichage_erreur("Mauvaise syntaxe de string combinaison");
    }
}

void Cube::affichage_erreur(string erreur)
{
    ERREUR
    system("PAUSE");
    exit(0);
}
