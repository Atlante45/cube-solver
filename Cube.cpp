/*
Rubiks
Clément BRISSET et Julien CHAUMONT
Janvier 2010 - Juin 2010
Librairies utilisées: librairies mingw32 par défaut
IDE utilisé: CodeBlocks 8.02
*/

/*
--------------------------------------------------
Fichier Cube.cpp:
Contient les fonctions relatives à l'initialisation du cube
--------------------------------------------------
*/

#include "Cube.h"

using namespace std;

Cube::Cube()    //Constructeur
{
    int nb_echec = 0, nb_coups_moyen = 0, nb_coups_total = 0;   //Initialisation variables
    int cube_le_plus_rapide = 0, nb_coups_min = 0;
    coups = 0;
    nb_jets = 1;
    affichage = true;
    couleur = true;
    optimiser_algo = true;
    court = true;

    cout<<"        ..:: Rubik's Cube ::.."<<endl<<endl; //Affichage d'accueil
    cout<<"Afficher l'algorithme de resolution ?"<<endl;
    cout<<"0. Non"<<endl<<"1. Oui"<<endl<<"         ";  //Choix utilisateur: afficher ou non les combinaisons à suivre (si oui, une seule résolution)
    cin>>affichage;
    if(affichage)
    {
        cout<<endl<<"Version courte ?"<<endl;
        cout<<"0. Non"<<endl<<"1. Oui"<<endl<<"         ";   //Choix utilisateur: type d'affichage des combinaisons
        cin>>court;
        cout<<endl<<"Afficher le cube en couleur ?"<<endl;  //Choix utilisateur: affichage du cube en coulour ou non
        cout<<"0. Non"<<endl<<"1. Oui"<<endl<<"         ";
        cin>>couleur;
    }
    else
    {
        cout<<endl<<"Effectuer combien de jets ?"<<endl<<"         ";   //Choix utilisateur: nombre de résolutions à effectuer (but statistique)
        cin>>nb_jets;
    }
    cout<<endl<<"Utiliser l'algorithme optimise ?"<<endl;   //Choix utilisateur: utilisation ou non de l'algorithme optimisé (plus lent mais plus efficace)
    cout<<"0. Non"<<endl<<"1. Oui"<<endl<<"         ";
    cin>>optimiser_algo;

    if(affichage)   //Si on affiche le cube, on ne fait qu'une seule résolution
        nb_jets = 1;

    for(int i=0;i<nb_jets;i++)
    {
        coups=0;                    //On initialise le nombre de coups à 0
        initialiser_cube();         //Définition de chaque facette en fonction de la face sur laquelle elle est
        melanger_cube();            //Mélange aléatoire du cube

        if(optimiser_algo)  //Avec l'algorithme optimisé, on teste la résolution du cube sous différents points de vue
        {
            initialiser_autres_cubes(); //Initialisation des différents cubes à tester

            for(int autre_cube=0;autre_cube<24 ;autre_cube++)    //On regarde sous quel angle le cube se résoud le plus rapidement
            {
                initialiser_faces(autre_cube);

                for(int i=0;i<6;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cube[i][j][k] = cubes[autre_cube][i][j][k];
                        }
                    }
                }

                resoudre_cube(false);

                if(coups < nb_coups_min || autre_cube == 0)
                {
                    nb_coups_min = coups;
                    cube_le_plus_rapide = autre_cube;
                }
            }

            for(int i=0;i<6;i++)
            {
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cube[i][j][k]=cubes[cube_le_plus_rapide][i][j][k];
                    }
                }
            }
        }

        initialiser_faces(cube_le_plus_rapide); //On refait la résolution sur le cube donnant le moins de coups à effectuer
        resoudre_cube(affichage);


        if(!verifier_cube())      //Si le cube est réelement fini
        {
            if(affichage)
                cout<<endl<<"Vous avez resolu le Rubik's Cube en "<<coups<<" coups."<<endl;   //On affiche le nombre de coups nécéssaire à la résolution
        }
        else
        {
            nb_echec++;       //Sinon on ajoute 1 echec
        }

        nb_coups_total += coups;      //Calcul du nombre de coups total
    }

    nb_coups_moyen = nb_coups_total / nb_jets;    //Calcul de la moyenne

    if(!affichage)  //Affichage des statistiques si c'est le mode qui a été choisi
    {
        cout<<endl<<"Le cube a ete resolu "<< nb_jets - nb_echec <<" fois sur "<< nb_jets <<endl;
        cout<<"Taux de reussite : "<< 100*(nb_jets - nb_echec)/nb_jets <<" %"<<endl;
        cout<<"Le cube a ete resolu avec une moyenne de "<< nb_coups_moyen <<" coups."<<endl;
    }

    cout<<endl<<endl<<endl;
}

void Cube::initialiser_faces(int cube)  //Initialise la variable contenant la modélisation du cube
{
    switch(cube)    //On associe à une couleur un numéro à partir d'un numéro en entrée. Pour un cube de base, on définit 24 variables cubes qui lui sont en réalité identiques (tout ce qui change, c'est le point de vue que l'utilisateur a sur le cube, la position de celui-ci dans sa main)
    {
        case 0:
            faces[0]=0;
            faces[1]=1;
            faces[2]=2;
            faces[3]=3;
            faces[4]=4;
            faces[5]=5;
            break;
        case 1:
            faces[0]=3;
            faces[1]=0;
            faces[2]=1;
            faces[3]=2;
            faces[4]=4;
            faces[5]=5;
            break;
        case 2:
            faces[0]=2;
            faces[1]=3;
            faces[2]=0;
            faces[3]=1;
            faces[4]=4;
            faces[5]=5;
            break;
        case 3:
            faces[0]=1;
            faces[1]=2;
            faces[2]=3;
            faces[3]=0;
            faces[4]=4;
            faces[5]=5;
            break;
        case 4:
            faces[0]=0;
            faces[1]=3;
            faces[2]=2;
            faces[3]=1;
            faces[4]=5;
            faces[5]=4;
            break;
        case 5:
            faces[0]=3;
            faces[1]=2;
            faces[2]=1;
            faces[3]=0;
            faces[4]=5;
            faces[5]=4;
            break;
        case 6:
            faces[0]=2;
            faces[1]=1;
            faces[2]=0;
            faces[3]=3;
            faces[4]=5;
            faces[5]=4;
            break;
        case 7:
            faces[0]=1;
            faces[1]=0;
            faces[2]=3;
            faces[3]=2;
            faces[4]=5;
            faces[5]=4;
            break;
        case 8:
            faces[0]=0;
            faces[1]=5;
            faces[2]=2;
            faces[3]=4;
            faces[4]=1;
            faces[5]=3;
            break;
        case 9:
            faces[0]=5;
            faces[1]=2;
            faces[2]=4;
            faces[3]=0;
            faces[4]=1;
            faces[5]=3;
            break;
        case 10:
            faces[0]=2;
            faces[1]=4;
            faces[2]=0;
            faces[3]=5;
            faces[4]=1;
            faces[5]=3;
            break;
        case 11:
            faces[0]=4;
            faces[1]=0;
            faces[2]=5;
            faces[3]=2;
            faces[4]=1;
            faces[5]=3;
            break;
        case 12:
            faces[0]=0;
            faces[1]=4;
            faces[2]=2;
            faces[3]=5;
            faces[4]=3;
            faces[5]=1;
            break;
        case 13:
            faces[0]=4;
            faces[1]=2;
            faces[2]=5;
            faces[3]=0;
            faces[4]=3;
            faces[5]=1;
            break;
        case 14:
            faces[0]=2;
            faces[1]=5;
            faces[2]=0;
            faces[3]=4;
            faces[4]=3;
            faces[5]=1;
            break;
        case 15:
            faces[0]=5;
            faces[1]=0;
            faces[2]=4;
            faces[3]=2;
            faces[4]=3;
            faces[5]=1;
            break;
        case 16:
            faces[0]=4;
            faces[1]=1;
            faces[2]=5;
            faces[3]=3;
            faces[4]=2;
            faces[5]=0;
            break;
        case 17:
            faces[0]=1;
            faces[1]=5;
            faces[2]=3;
            faces[3]=4;
            faces[4]=2;
            faces[5]=0;
            break;
        case 18:
            faces[0]=5;
            faces[1]=3;
            faces[2]=4;
            faces[3]=1;
            faces[4]=2;
            faces[5]=0;
            break;
        case 19:
            faces[0]=3;
            faces[1]=4;
            faces[2]=1;
            faces[3]=5;
            faces[4]=2;
            faces[5]=0;
            break;
        case 20:
            faces[0]=5;
            faces[1]=1;
            faces[2]=4;
            faces[3]=3;
            faces[4]=0;
            faces[5]=2;
            break;
        case 21:
            faces[0]=1;
            faces[1]=4;
            faces[2]=3;
            faces[3]=5;
            faces[4]=0;
            faces[5]=2;
            break;
        case 22:
            faces[0]=4;
            faces[1]=3;
            faces[2]=5;
            faces[3]=1;
            faces[4]=0;
            faces[5]=2;
            break;
        case 23:
            faces[0]=3;
            faces[1]=5;
            faces[2]=1;
            faces[3]=4;
            faces[4]=0;
            faces[5]=2;
            break;
        }
}

void Cube::initialiser_autres_cubes()   //Complémentaire de la fonction précédente
{
  for(int autres_cubes=0;autres_cubes<24;autres_cubes++)
    {
        switch(autres_cubes)
        {
            case 0:
                for(int i=0;i<6;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cube[i][j][k];
                        }
                    }
                }
                break;
            case 1:
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cubes[autres_cubes][4][j][k]=cube[4][2-k][j];
                        cubes[autres_cubes][5][j][k]=cube[5][k][2-j];
                    }
                }
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cube[(i+3)%4][j][k];
                        }
                    }
                }
                break;
            case 2:
                for(int i=4;i<6;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cube[i][2-j][2-k];
                        }
                    }
                }
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cube[(i+2)%4][j][k];
                        }
                    }
                }
                break;
            case 3:
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cubes[autres_cubes][4][j][k]=cube[4][k][2-j];
                        cubes[autres_cubes][5][j][k]=cube[5][2-k][j];
                    }
                }
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cube[(i+1)%4][j][k];
                        }
                    }
                }
                break;
            case 4:
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cubes[autres_cubes][4][j][k]=cube[5][j][k];
                        cubes[autres_cubes][5][j][k]=cube[4][j][k];
                        cubes[autres_cubes][0][j][k]=cube[0][2-j][2-k];
                        cubes[autres_cubes][2][j][k]=cube[2][2-j][2-k];
                        cubes[autres_cubes][1][j][k]=cube[3][2-j][2-k];
                        cubes[autres_cubes][3][j][k]=cube[1][2-j][2-k];
                    }
                }
                break;
            case 5:
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cubes[autres_cubes][5][j][k]=cubes[4][5][2-k][j];
                        cubes[autres_cubes][4][j][k]=cubes[4][4][k][2-j];
                    }
                }
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[4][(i+1)%4][j][k];
                        }
                    }
                }
                break;
            case 6:
                for(int i=4;i<6;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[4][i][2-j][2-k];
                        }
                    }
                }
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[4][(i+2)%4][j][k];
                        }
                    }
                }
                break;
            case 7:
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cubes[autres_cubes][4][j][k]=cubes[4][4][2-k][j];
                        cubes[autres_cubes][5][j][k]=cubes[4][5][k][2-j];
                    }
                }
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[4][(i+3)%4][j][k];
                        }
                    }
                }
                break;
            case 8:
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cubes[autres_cubes][0][j][k]=cube[0][2-k][j];
                        cubes[autres_cubes][2][j][k]=cube[2][k][2-j];
                        cubes[autres_cubes][4][j][k]=cube[1][j][k];
                        cubes[autres_cubes][1][j][k]=cube[5][j][k];
                        cubes[autres_cubes][5][j][k]=cube[3][2-j][2-k];
                        cubes[autres_cubes][3][j][k]=cube[4][2-j][2-k];
                    }
                }
                break;
            case 9:
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cubes[autres_cubes][5][j][k]=cubes[8][5][2-k][j];
                        cubes[autres_cubes][4][j][k]=cubes[8][4][k][2-j];
                    }
                }
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[8][(i+1)%4][j][k];
                        }
                    }
                }
                break;
            case 10:
                for(int i=4;i<6;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[8][i][2-j][2-k];
                        }
                    }
                }
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[8][(i+2)%4][j][k];
                        }
                    }
                }
                break;
            case 11:
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cubes[autres_cubes][4][j][k]=cubes[8][4][2-k][j];
                        cubes[autres_cubes][5][j][k]=cubes[8][5][k][2-j];
                    }
                }
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[8][(i+3)%4][j][k];
                        }
                    }
                }
                break;
            case 12:
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cubes[autres_cubes][0][j][k]=cube[0][k][2-j];
                        cubes[autres_cubes][2][j][k]=cube[2][2-k][j];
                        cubes[autres_cubes][4][j][k]=cube[3][2-j][2-k];
                        cubes[autres_cubes][1][j][k]=cube[4][j][k];
                        cubes[autres_cubes][5][j][k]=cube[1][j][k];
                        cubes[autres_cubes][3][j][k]=cube[5][2-j][2-k];
                    }
                }
                break;
            case 13:
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cubes[autres_cubes][5][j][k]=cubes[12][5][2-k][j];
                        cubes[autres_cubes][4][j][k]=cubes[12][4][k][2-j];
                    }
                }
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[12][(i+1)%4][j][k];
                        }
                    }
                }
                break;
            case 14:
                for(int i=4;i<6;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[12][i][2-j][2-k];
                        }
                    }
                }
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[12][(i+2)%4][j][k];
                        }
                    }
                }
                break;
            case 15:
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cubes[autres_cubes][4][j][k]=cubes[12][4][2-k][j];
                        cubes[autres_cubes][5][j][k]=cubes[12][5][k][2-j];
                    }
                }
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[12][(i+3)%4][j][k];
                        }
                    }
                }
                break;
            case 16:
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cubes[autres_cubes][1][j][k]=cube[1][2-k][j];
                        cubes[autres_cubes][3][j][k]=cube[3][k][2-j];
                        cubes[autres_cubes][0][j][k]=cube[4][2-k][j];
                        cubes[autres_cubes][2][j][k]=cube[5][2-k][j];
                        cubes[autres_cubes][4][j][k]=cube[2][2-k][j];
                        cubes[autres_cubes][5][j][k]=cube[0][2-k][j];
                    }
                }
                break;
            case 17:
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cubes[autres_cubes][5][j][k]=cubes[16][5][2-k][j];
                        cubes[autres_cubes][4][j][k]=cubes[16][4][k][2-j];
                    }
                }
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[16][(i+1)%4][j][k];
                        }
                    }
                }
                break;
            case 18:
                for(int i=4;i<6;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[16][i][2-j][2-k];
                        }
                    }
                }
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[16][(i+2)%4][j][k];
                        }
                    }
                }
                break;
            case 19:
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cubes[autres_cubes][4][j][k]=cubes[16][4][2-k][j];
                        cubes[autres_cubes][5][j][k]=cubes[16][5][k][2-j];
                    }
                }
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[16][(i+3)%4][j][k];
                        }
                    }
                }
                break;
            case 20:
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cubes[autres_cubes][1][j][k]=cube[1][k][2-j];
                        cubes[autres_cubes][3][j][k]=cube[3][2-k][j];
                        cubes[autres_cubes][0][j][k]=cube[5][k][2-j];
                        cubes[autres_cubes][2][j][k]=cube[4][k][2-j];
                        cubes[autres_cubes][4][j][k]=cube[0][k][2-j];
                        cubes[autres_cubes][5][j][k]=cube[2][k][2-j];
                    }
                }
                break;
            case 21:
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cubes[autres_cubes][5][j][k]=cubes[20][5][2-k][j];
                        cubes[autres_cubes][4][j][k]=cubes[20][4][k][2-j];
                    }
                }
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[20][(i+1)%4][j][k];
                        }
                    }
                }
                break;
            case 22:
                for(int i=4;i<6;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[20][i][2-j][2-k];
                        }
                    }
                }
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[20][(i+2)%4][j][k];
                        }
                    }
                }
                break;
            case 23:
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cubes[autres_cubes][4][j][k]=cubes[20][4][2-k][j];
                        cubes[autres_cubes][5][j][k]=cubes[20][5][k][2-j];
                    }
                }
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            cubes[autres_cubes][i][j][k]=cubes[20][(i+3)%4][j][k];
                        }
                    }
                }
                break;
        }
    }
}

void Cube::resoudre_cube(bool affichages)      //Fonction se chargeant d'éxécuter les autres fonctions pour résoudre le cube
{
    coups = 0;      //On remet le nombre de coups à zéro avant chaque résolution
    bool k = affichage;    //On stocke la valeur de affichage
    affichage = affichages;

    if(affichage)
        afficher_cube();    //On affiche le cube
    faire_face_initiale();   //Début de la résolution
    if(affichage)
        afficher_cube();
    positionner_arretes();
    if(affichage)
        afficher_cube();
    positionner_arretes_face_finale();
    if(affichage)
        afficher_cube();
    positionner_coins_face_finale();
    if(affichage)
        afficher_cube();
    tourner_coins_face_finale();    //Fin de la résolution
    if(affichage)
        afficher_cube();

    affichage = k;  //On redonne à affichage sa valeur
}

void Cube::initialiser_cube()   //Remplissage du cube ainsi que d'un cube de référence par les valeurs des faces
{
    for(int i=0;i<6;i++)
    {
        faces[i]=i;
    }

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                switch(i)
                {
                    case 0:
                        cube[i][j][k]=faces[0];
                        break;
                    case 1:
                        cube[i][j][k]=faces[1];
                        break;
                    case 2:
                        cube[i][j][k]=faces[2];
                        break;
                    case 3:
                        cube[i][j][k]=faces[3];
                        break;
                    case 4:
                        cube[i][j][k]=faces[4];
                        break;
                    case 5:
                        cube[i][j][k]=faces[5];
                        break;
                    default:
                        affichage_erreur("Valeur de int i invalide");
                        break;

                }
            }
        }
    }
}

void Cube::afficher_cube()      //Affichage du cube
{
    if(couleur)
    {
        Color(15,0);
        cout << endl << "         ------" << endl;
    }
    else
        cout << endl << "          -------" << endl;

    for(int k=0;k<3;k++)
    {
        if(couleur)
            cout << "        |";
        else
            cout << "         | ";

        for(int j=0;j<3;j++)
        {
            if(couleur){Color2(cube[4][j][k]);}
            cout << cube[4][j][k] << " " ;
            if(couleur){Color(15,0);}
        }
        cout << "| " << endl;
    }

    if(couleur)
        cout << "  ---------------------------" << endl;
    else
        cout << "  -------------------------------" << endl;

    for(int k=0;k<3;k++)
    {
        cout<< " ";
        for(int i=0;i<4;i++)
        {
            if(couleur)
                cout << "|";
            else
                cout << "| ";

            for(int j=0;j<3;j++)
            {
                if(couleur){Color2(cube[i][j][k]);}
                cout << cube[i][j][k] << " " ;
                if(couleur){Color(15,0);}
            }
        }
    cout << "|" << endl;
    }

    if(couleur)
        cout << "  ---------------------------" << endl;
    else
        cout << "  -------------------------------" << endl;


    for(int k=0;k<3;k++)
    {

        if(couleur)
            cout << "        |";
        else
            cout << "         | ";

        for(int j=0;j<3;j++)
        {
            if(couleur){Color2(cube[5][j][k]);}
            cout << cube[5][j][k] << " " ;
            if(couleur){Color(15,0);}
        }
        cout << "| " << endl;
    }

    if(couleur)
    {
        cout << "         ------" << endl;
    }
    else
        cout << "          -------" << endl;

}

void Cube::melanger_cube()      //Mélange du cube de façon aléatoire
{

    int face=6, sens=0;

    for(int i=0;i<1000;i++) //On réalise 1000 rotations aléatoires du cube
    {
        face = (rand() % (5 - 0 + 1)) + 0;
        sens = (rand() % (2 - 1 + 1)) + 1;

        if(sens==1)
            tourner_face_plus(face, false);
        else if(sens==2)
            tourner_face_moins(face, false);
        else
            affichage_erreur("Valeur de int sens invalide");
    }
}

int Cube::verifier_cube()       //Vérification de la valeur de chaque case du tableau par rapport à un cube initialisé
{
    int l=0;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                if(faces[i]!=cube[i][j][k])
                {l=1;}
            }
        }
    }

    return l;
}


