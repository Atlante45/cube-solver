/*
Rubiks
Cl�ment BRISSET et Julien CHAUMONT
Janvier 2010
Librairies utilis�es: librairies mingw32 par d�faut
IDE utilis�: CodeBlocks 8.02
*/

/*
--------------------------------------------------
Fichier Cube.cpp:
Contient les fonctions relatives � l'initialisation du cube
--------------------------------------------------
*/

#include "Cube.h"

using namespace std;

Cube::Cube()    //Constructeur
{
    initialiser_cube(); //D�finition de chaque facette
    melanger_cube();    //M�lange al�atoire du cube
    afficher_cube();    //Affichage du cube m�lang�
    faire_croix_face_initiale();    //D�but de la r�solution
    if(positionner_arretes())
    {
        //FAIRE LA SUITE...
    }
    else
    {
        //ERREUR A CORRIGER :p
    }
}

void Cube::initialiser_cube()   //Remplissage du tableau par des nombres rang�s
{

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                switch(i)
                {
                    case 0:
                        cube[i][j][k]=0;
                        break;
                    case 1:
                        cube[i][j][k]=1;
                        break;
                    case 2:
                        cube[i][j][k]=2;
                        break;
                    case 3:
                        cube[i][j][k]=3;
                        break;
                    case 4:
                        cube[i][j][k]=4;
                        break;
                    case 5:
                        cube[i][j][k]=5;
                        break;
                    default:
                        affichage_erreur("Valeur de int i invalide");
                        break;

                }
            }
        }
    }
}

void Cube::afficher_cube()  //Affichage des donn�es du tableau dans la console
{

    cout << endl << "          -------" << endl;
    for(int k=0;k<3;k++)
    {
        cout << "         | ";
        for(int j=0;j<3;j++)
        {
            cout << cube[4][j][k] << " " ;
        }
        cout << "| " << endl;
    }
    cout << "  -------------------------------" << endl;

    for(int k=0;k<3;k++)
    {
        cout<< " ";
        for(int i=0;i<4;i++)
        {
            cout << "| ";
            for(int j=0;j<3;j++)
            {
                cout << cube[i][j][k] << " " ;

            }
        }
    cout << "|" << endl;
    }
    cout << "  -------------------------------" << endl ;

    for(int k=0;k<3;k++)
    {
        cout << "         | ";

        for(int j=0;j<3;j++)
        {
            cout << cube[5][j][k] << " " ;
        }
        cout << "| " << endl;
    }
    cout << "          -------\n\n";
}

void Cube::melanger_cube()  //M�lange du cube de fa�on al�atoire
{

    int face=6, sens=0;

    for(int i=0;i<1000;i++)
    {
        face = (rand() % (5 - 0 + 1)) + 0;
        sens = (rand() % (2 - 1+ 1)) + 1;

        if(sens==1)
            tourner_face_plus(face, false);
        else if(sens==2)
            tourner_face_moins(face, false);
        else
            affichage_erreur("Valeur de int sens invalide");
    }
}



