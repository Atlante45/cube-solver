/*
Rubiks
Clément BRISSET et Julien CHAUMONT
Janvier 2010 - Juin 2010
Librairies utilisées: librairies mingw32 par défaut
IDE utilisé: CodeBlocks 8.02
*/

/*
--------------------------------------------------
Fichier rotations.cpp:
Contient les deux fonctions qui se chargent des rotations des faces
--------------------------------------------------
*/

#include "Cube.h"

using namespace std;

void Cube::tourner_face_plus(int face, bool affichage)  //Rotation de la face face dans le sens trigonométrique
{

    int c=0, d=0, e=0, f=0, g=0, s=0;

    for(int t=0;t<2;t++)      //Tourner intérieur face
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                s=10*j+k;
                switch(s)
                {
                    case 00:
                        c=cube[face][0][0];
                        cube[face][0][0]=cube[face][1][0];
                        break;
                    case 01:
                        d=cube[face][0][1];
                        cube[face][0][1]=c;
                        break;
                    case 02:
                        c=cube[face][0][2];
                        cube[face][0][2]=d;
                        break;
                    case 10:
                        cube[face][1][0]=cube[face][2][0];
                        break;
                    case 11:
                        break;
                    case 12:
                        d=cube[face][1][2];
                        cube[face][1][2]=c;
                        break;
                    case 20:
                        cube[face][2][0]=cube[face][2][1];
                        break;
                    case 21:
                        cube[face][2][1]=cube[face][2][2];
                        break;
                    case 22:
                        cube[face][2][2]=d;
                        break;
                    default:
                        affichage_erreur("Numero de face invalide");
                        break;
                }
            }
        }
    }

    switch(face)            //Tourner exterieur face
    {
        case 0:
            e=cube[4][0][0];
            f=cube[4][0][1];
            g=cube[4][0][2];
            cube[4][0][0]=cube[1][0][0];
            cube[4][0][1]=cube[1][0][1];
            cube[4][0][2]=cube[1][0][2];
            cube[1][0][0]=cube[5][0][0];
            cube[1][0][1]=cube[5][0][1];
            cube[1][0][2]=cube[5][0][2];
            cube[5][0][0]=cube[3][2][2];
            cube[5][0][1]=cube[3][2][1];
            cube[5][0][2]=cube[3][2][0];
            cube[3][2][2]=e;
            cube[3][2][1]=f;
            cube[3][2][0]=g;
            break;
        case 1:
            e=cube[4][0][2];
            f=cube[4][1][2];
            g=cube[4][2][2];
            cube[4][0][2]=cube[2][0][0];
            cube[4][1][2]=cube[2][0][1];
            cube[4][2][2]=cube[2][0][2];
            cube[2][0][0]=cube[5][2][0];
            cube[2][0][1]=cube[5][1][0];
            cube[2][0][2]=cube[5][0][0];
            cube[5][2][0]=cube[0][2][2];
            cube[5][1][0]=cube[0][2][1];
            cube[5][0][0]=cube[0][2][0];
            cube[0][2][2]=e;
            cube[0][2][1]=f;
            cube[0][2][0]=g;
            break;
        case 2:
            e=cube[4][2][2];
            f=cube[4][2][1];
            g=cube[4][2][0];
            cube[4][2][2]=cube[3][0][0];
            cube[4][2][1]=cube[3][0][1];
            cube[4][2][0]=cube[3][0][2];
            cube[3][0][0]=cube[5][2][2];
            cube[3][0][1]=cube[5][2][1];
            cube[3][0][2]=cube[5][2][0];
            cube[5][2][2]=cube[1][2][2];
            cube[5][2][1]=cube[1][2][1];
            cube[5][2][0]=cube[1][2][0];
            cube[1][2][2]=e;
            cube[1][2][1]=f;
            cube[1][2][0]=g;
            break;
        case 3:
            e=cube[4][2][0];
            f=cube[4][1][0];
            g=cube[4][0][0];
            cube[4][2][0]=cube[0][0][0];
            cube[4][1][0]=cube[0][0][1];
            cube[4][0][0]=cube[0][0][2];
            cube[0][0][0]=cube[5][0][2];
            cube[0][0][1]=cube[5][1][2];
            cube[0][0][2]=cube[5][2][2];
            cube[5][0][2]=cube[2][2][2];
            cube[5][1][2]=cube[2][2][1];
            cube[5][2][2]=cube[2][2][0];
            cube[2][2][2]=e;
            cube[2][2][1]=f;
            cube[2][2][0]=g;
            break;
        case 4:
            e=cube[3][2][0];
            f=cube[3][1][0];
            g=cube[3][0][0];
            cube[3][2][0]=cube[2][2][0];
            cube[3][1][0]=cube[2][1][0];
            cube[3][0][0]=cube[2][0][0];
            cube[2][2][0]=cube[1][2][0];
            cube[2][1][0]=cube[1][1][0];
            cube[2][0][0]=cube[1][0][0];
            cube[1][2][0]=cube[0][2][0];
            cube[1][1][0]=cube[0][1][0];
            cube[1][0][0]=cube[0][0][0];
            cube[0][2][0]=e;
            cube[0][1][0]=f;
            cube[0][0][0]=g;
            break;
        case 5:
            e=cube[3][0][2];
            f=cube[3][1][2];
            g=cube[3][2][2];
            cube[3][0][2]=cube[0][0][2];
            cube[3][1][2]=cube[0][1][2];
            cube[3][2][2]=cube[0][2][2];
            cube[0][0][2]=cube[1][0][2];
            cube[0][1][2]=cube[1][1][2];
            cube[0][2][2]=cube[1][2][2];
            cube[1][0][2]=cube[2][0][2];
            cube[1][1][2]=cube[2][1][2];
            cube[1][2][2]=cube[2][2][2];
            cube[2][0][2]=e;
            cube[2][1][2]=f;
            cube[2][2][2]=g;
            break;
    }

    if(affichage)              //Affichage de la rotation effectuée
    {
        if(couleur)
        {
            if(court)
            {
            if(faces[face]==0)
                    cout << "blanche --> sens Positif" <<endl;
            else if(faces[face]==1)
                    cout << "rouge --> sens Positif" <<endl;
            else if(faces[face]==2)
                    cout << "jaune --> sens Positif" <<endl;
            else if(faces[face]==3)
                    cout << "rose --> sens Positif" <<endl;
            else if(faces[face]==4)
                    cout << "bleu --> sens Positif" <<endl;
            else if(faces[face]==5)
                    cout << "vert --> sens Positif" <<endl;
            else
                cout<<"ERREUR !!!!!!"<<endl;
            }
            else
            {
            if(faces[face]==0)
                    cout << "Tourner face blanche dans le sens contraire des aiguilles d'une montre." <<endl;
            else if(faces[face]==1)
                    cout << "Tourner face rouge dans le sens contraire des aiguilles d'une montre." <<endl;
            else if(faces[face]==2)
                    cout << "Tourner face jaune dans le sens contraire des aiguilles d'une montre." <<endl;
            else if(faces[face]==3)
                    cout << "Tourner face rose dans le sens contraire des aiguilles d'une montre." <<endl;
            else if(faces[face]==4)
                    cout << "Tourner face bleu dans le sens contraire des aiguilles d'une montre." <<endl;
            else if(faces[face]==5)
                    cout << "Tourner face vert dans le sens contraire des aiguilles d'une montre." <<endl;
            else
                cout<<"ERREUR !!!!!!"<<endl;
            }
        }
        else
            cout << "Tourner face " << faces[face] << " dans le sens contraire des aiguilles d'une montre." <<endl;
    }
        coups++;
}

void Cube::tourner_face_moins(int face, bool affichage) //Rotation de la face face dans le sens inverse du sens trigonométrique
{

    int c=0, d=0, e=0, f=0,g=0, s=0;

    for(int t=0;t<2;t++)  //Tourner intérieur face
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                s=10*j+k;
                switch(s)
                {
                    case 00:
                        c=cube[face][0][0];
                        cube[face][0][0]=cube[face][0][1];
                        break;
                    case 01:
                        cube[face][0][1]=cube[face][0][2];
                        break;
                    case 02:
                        cube[face][0][2]=cube[face][1][2];
                        break;
                    case 10:
                        d=cube[face][1][0];
                        cube[face][1][0]=c;
                        break;
                    case 11:
                        break;
                    case 12:
                        cube[face][1][2]=cube[face][2][2];
                        break;
                    case 20:
                        c=cube[face][2][0];
                        cube[face][2][0]=d;
                        break;
                    case 21:
                        d=cube[face][2][1];
                        cube[face][2][1]=c;
                        break;
                    case 22:
                        cube[face][2][2]=d;
                        break;
                    default:
                        affichage_erreur("Numero de face invalide");
                        break;
                }
            }
        }
    }

    switch(face)   //Tourner exterieur face
    {
        case 0:
            e=cube[4][0][0];
            f=cube[4][0][1];
            g=cube[4][0][2];
            cube[4][0][0]=cube[3][2][2];
            cube[4][0][1]=cube[3][2][1];
            cube[4][0][2]=cube[3][2][0];
            cube[3][2][2]=cube[5][0][0];
            cube[3][2][1]=cube[5][0][1];
            cube[3][2][0]=cube[5][0][2];
            cube[5][0][0]=cube[1][0][0];
            cube[5][0][1]=cube[1][0][1];
            cube[5][0][2]=cube[1][0][2];
            cube[1][0][0]=e;
            cube[1][0][1]=f;
            cube[1][0][2]=g;
            break;
        case 1:
            e=cube[4][0][2];
            f=cube[4][1][2];
            g=cube[4][2][2];
            cube[4][0][2]=cube[0][2][2];
            cube[4][1][2]=cube[0][2][1];
            cube[4][2][2]=cube[0][2][0];
            cube[0][2][2]=cube[5][2][0];
            cube[0][2][1]=cube[5][1][0];
            cube[0][2][0]=cube[5][0][0];
            cube[5][2][0]=cube[2][0][0];
            cube[5][1][0]=cube[2][0][1];
            cube[5][0][0]=cube[2][0][2];
            cube[2][0][0]=e;
            cube[2][0][1]=f;
            cube[2][0][2]=g;
            break;
        case 2:
            e=cube[4][2][2];
            f=cube[4][2][1];
            g=cube[4][2][0];
            cube[4][2][2]=cube[1][2][2];
            cube[4][2][1]=cube[1][2][1];
            cube[4][2][0]=cube[1][2][0];
            cube[1][2][2]=cube[5][2][2];
            cube[1][2][1]=cube[5][2][1];
            cube[1][2][0]=cube[5][2][0];
            cube[5][2][2]=cube[3][0][0];
            cube[5][2][1]=cube[3][0][1];
            cube[5][2][0]=cube[3][0][2];
            cube[3][0][0]=e;
            cube[3][0][1]=f;
            cube[3][0][2]=g;
            break;
        case 3:
            e=cube[4][2][0];
            f=cube[4][1][0];
            g=cube[4][0][0];
            cube[4][2][0]=cube[2][2][2];
            cube[4][1][0]=cube[2][2][1];
            cube[4][0][0]=cube[2][2][0];
            cube[2][2][2]=cube[5][0][2];
            cube[2][2][1]=cube[5][1][2];
            cube[2][2][0]=cube[5][2][2];
            cube[5][0][2]=cube[0][0][0];
            cube[5][1][2]=cube[0][0][1];
            cube[5][2][2]=cube[0][0][2];
            cube[0][0][0]=e;
            cube[0][0][1]=f;
            cube[0][0][2]=g;
            break;
        case 4:
            e=cube[3][2][0];
            f=cube[3][1][0];
            g=cube[3][0][0];
            cube[3][2][0]=cube[0][2][0];
            cube[3][1][0]=cube[0][1][0];
            cube[3][0][0]=cube[0][0][0];
            cube[0][2][0]=cube[1][2][0];
            cube[0][1][0]=cube[1][1][0];
            cube[0][0][0]=cube[1][0][0];
            cube[1][2][0]=cube[2][2][0];
            cube[1][1][0]=cube[2][1][0];
            cube[1][0][0]=cube[2][0][0];
            cube[2][2][0]=e;
            cube[2][1][0]=f;
            cube[2][0][0]=g;
            break;
        case 5:
            e=cube[3][0][2];
            f=cube[3][1][2];
            g=cube[3][2][2];
            cube[3][0][2]=cube[2][0][2];
            cube[3][1][2]=cube[2][1][2];
            cube[3][2][2]=cube[2][2][2];
            cube[2][0][2]=cube[1][0][2];
            cube[2][1][2]=cube[1][1][2];
            cube[2][2][2]=cube[1][2][2];
            cube[1][0][2]=cube[0][0][2];
            cube[1][1][2]=cube[0][1][2];
            cube[1][2][2]=cube[0][2][2];
            cube[0][0][2]=e;
            cube[0][1][2]=f;
            cube[0][2][2]=g;
            break;
    }

    if(affichage)              //Affichage de la rotation effectuée
    {
        if(couleur)
        {
            if(court)
            {
            if(faces[face]==0)
                    cout << "blanche --> sens Negatif" <<endl;
            else if(faces[face]==1)
                    cout << "rouge --> sens Negatif" <<endl;
            else if(faces[face]==2)
                    cout << "jaune --> sens Negatif" <<endl;
            else if(faces[face]==3)
                    cout << "rose --> sens Negatif" <<endl;
            else if(faces[face]==4)
                    cout << "bleu --> sens Negatif" <<endl;
            else if(faces[face]==5)
                    cout << "vert --> sens Negatif" <<endl;
            else
                cout<<"ERREUR !!!!!!"<<endl;
            }
            else
            {
            if(faces[face]==0)
                    cout << "Tourner face blanche dans le sens des aiguilles d'une montre." <<endl;
            else if(faces[face]==1)
                    cout << "Tourner face rouge dans le sens des aiguilles d'une montre." <<endl;
            else if(faces[face]==2)
                    cout << "Tourner face jaune dans le sens des aiguilles d'une montre." <<endl;
            else if(faces[face]==3)
                    cout << "Tourner face rose dans le sens des aiguilles d'une montre." <<endl;
            else if(faces[face]==4)
                    cout << "Tourner face bleu dans le sens des aiguilles d'une montre." <<endl;
            else if(faces[face]==5)
                    cout << "Tourner face vert dans le sens des aiguilles d'une montre." <<endl;
            else
                cout<<"ERREUR !!!!!!"<<endl;
            }
        }
        else
            cout << "Tourner face " << faces[face] << " dans le sens des aiguilles d'une montre." <<endl;
    }
        coups++;         //Ajoute un coup au compteur
}
