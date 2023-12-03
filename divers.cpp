/*
Rubiks
Clément BRISSET et Julien CHAUMONT
Janvier 2010 - Juin 2010
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

#if !defined(__unix)
#include <windows.h>
#endif

using namespace std;

void Cube::Color(int couleurDuTexte,int couleurDeFond)  //Fonction d'affichage de couleurs
{
#if !defined(__unix)
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
#else
    if (couleurDeFond == 1 || couleurDeFond == 0)
    {
        cout << "\033[0m";
        return;
    }
    
    switch (couleurDeFond)
    {
        case 15:   //Blanc
            cout << "\033[97m\033[107m";
            break;
        case 12:   //Rouge
            cout << "\033[91m\033[101m";
            break;
        case 14:   //Jaune
            cout << "\033[33m\033[43m";
            break;
        case 13:   //Rose
            cout << "\033[95m\033[105m";
            break;
        case 9: //Bleu
            cout << "\033[94m\033[104m";
            break;
        case 10:   //Vert
            cout << "\033[92m\033[102m";
            break;
    }
#endif
}

void Cube::Color2(int numero)   //Association faces/couleurs
{
    switch(numero)
    {
        case 0:
            Color(15,15);   //Blanc
            break;

        case 1:
            Color(12,12);   //Rouge
            break;

        case 2:
            Color(14,14);   //Jaune
            break;

        case 3:
            Color(13,13);   //Rose
            break;

        case 4:
            Color(9,9); //Bleu
            break;

        case 5:
            Color(10,10);   //Vert
            break;

        case 6: //Couleur par défaut dans la console
            Color(7,1);
            break;
    }
}

void Cube::lecture_string(string combinaison)   //Exécute les chaines de caractères représentant les rotations
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
            tourner_face_plus(intTemp, affichage);
        else if (stringTemp1=="m")
            tourner_face_moins(intTemp, affichage);
        else
            affichage_erreur("Mauvaise syntaxe de string combinaison");
    }
}

void Cube::affichage_erreur(string erreur)  //Affichage d'erreur
{
    ERREUR
    system("PAUSE");
    exit(0);
}

