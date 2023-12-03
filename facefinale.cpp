/*
Rubiks
Clément BRISSET et Julien CHAUMONT
Janvier 2010 - Juin 2010
Librairies utilisées: librairies mingw32 par défaut
IDE utilisé: CodeBlocks 8.02
*/

/*
--------------------------------------------------
Fichier facefinale.cpp:
Algos de résolution à l'étape de la dernière face
--------------------------------------------------
*/

#include "Cube.h"

using namespace std;

void Cube::positionner_arretes_face_finale()      //Construit la croix sur la face inférieure du cube
{
    string combinaison="";

        for(int i=0;i<8;i++)             //Place les arrêtes chacunes à leur place
        {
            if(cube[5][1][0]==faces[1] || cube[1][1][2]==faces[1])
            {
                if(cube[5][2][1]==faces[0] || cube[2][1][2]==faces[0])
                {
                    combinaison="m5m1m0m5p0p5p1p5";
                    lecture_string(combinaison);
                }
                else if(cube[5][0][1]==faces[2] || cube[0][1][2]==faces[2])
                {
                    combinaison="m5m0m3m5p3p5p0m5";
                    lecture_string(combinaison);
                }
                else if(cube[5][1][2]==faces[0] || cube[3][1][2]==faces[0])
                {
                    combinaison="m5m3m2m5p2p5p3";
                    lecture_string(combinaison);
                }
                else if(cube[5][1][2]==faces[2] || cube[3][1][2]==faces[2])
                {
                    combinaison="m5m2m1m5p1p5p2";
                    lecture_string(combinaison);
                }
                else
                {
                }

            }
            else
            {
                combinaison="m5";
                lecture_string(combinaison);
            }
        }

            //Met les arrêtes dans la bonne orientation

    if(cube[5][0][1]==faces[5] && cube[5][1][0]==faces[5] && cube[5][2][1]==faces[5] && cube[5][1][2]==faces[5])
     {}
    else if(cube[0][1][2]==faces[5] && cube[1][1][2]==faces[5] && cube[2][1][2]==faces[5] && cube[3][1][2]==faces[5])
    {
        combinaison="m5m1m0m5p0p5p1m5m1m0m5p0p5p1m5m3m2m5p2p5p3m5m3m2m5p2p5p3";
        lecture_string(combinaison);
    }
    else if(cube[5][0][1]==faces[5] && cube[1][1][2]==faces[5] && cube[2][1][2]==faces[5] && cube[5][1][2]==faces[5])
    {
        combinaison="m5m1m0m5p0p5p1m5m1m0m5p0p5p1";
        lecture_string(combinaison);
    }
    else if(cube[0][1][2]==faces[5] && cube[5][1][0]==faces[5] && cube[5][2][1]==faces[5] && cube[3][1][2]==faces[5])
    {
        combinaison="m5m3m2m5p2p5p3m5m3m2m5p2p5p3";
        lecture_string(combinaison);
    }
    else if(cube[0][1][2]==faces[5] && cube[1][1][2]==faces[5] && cube[5][2][1]==faces[5] && cube[5][1][2]==faces[5])
    {
        combinaison="m5m0m3m5p3p5p0m5m0m3m5p3p5p0";
        lecture_string(combinaison);
    }
    else if(cube[5][0][1]==faces[5] && cube[5][1][0]==faces[5] && cube[2][1][2]==faces[5] && cube[3][1][2]==faces[5])
    {
        combinaison="m5m2m1m5p1p5p2m5m2m1m5p1p5p2";
        lecture_string(combinaison);
    }
    else if(cube[0][1][2]==faces[5] && cube[5][1][0]==faces[5] && cube[2][1][2]==faces[5] && cube[5][1][2]==faces[5])
    {
        combinaison="m5m1m0m5p0p5p1m5m1m0m5p0p5p1m5m0m3m5p3p5p0m5m0m3m5p3p5p0";
        lecture_string(combinaison);
    }
    else if(cube[5][0][1]==faces[5] && cube[1][1][2]==faces[5] && cube[5][2][1]==faces[5] && cube[3][1][2]==faces[5])
    {
        combinaison="m5m2m1m5p1p5p2m5m2m1m5p1p5p2m5m1m0m5p0p5p1m5m1m0m5p0p5p1";
        lecture_string(combinaison);
    }
}

void Cube::positionner_coins_face_finale()        //Met les coins de la face finale à leur place
{
    while(!is_bien_place(5,0,0)||!is_bien_place(5,2,0)||!is_bien_place(5,2,2)||!is_bien_place(5,0,2))
    {
        if(!(is_bien_place(5,0,0)||is_bien_place(5,2,0)||is_bien_place(5,2,2)||is_bien_place(5,0,2)))
            lecture_string("m3p1p5m1m5p3p5p1m5m1");
        else if(is_bien_place(5,0,0)&&!is_bien_place(5,2,0)&&!is_bien_place(5,2,2)&&!is_bien_place(5,0,2))
            lecture_string("m3p1p5m1m5p3p5p1m5m1");
        else if(!is_bien_place(5,0,0)&&is_bien_place(5,2,0)&&!is_bien_place(5,2,2)&&!is_bien_place(5,0,2))
            lecture_string("m0p2p5m2m5p0p5p2m5m2");
        else if(!is_bien_place(5,0,0)&&!is_bien_place(5,2,0)&&is_bien_place(5,2,2)&&!is_bien_place(5,0,2))
            lecture_string("m1p3p5m3m5p1p5p3m5m3");
        else if(!is_bien_place(5,0,0)&&!is_bien_place(5,2,0)&&!is_bien_place(5,2,2)&&is_bien_place(5,0,2))
            lecture_string("m2p0p5m0m5p2p5p0m5m0");
        else
        {
            afficher_cube();
            cout << "500 " << is_bien_place(5,0,0) << " 520 " << is_bien_place(5,2,0) << " 522 " << is_bien_place(5,2,2) << " 502 " << is_bien_place(5,0,2) << endl;
            affichage_erreur("ERREUR");
        }
    }
    return;
}

void Cube::tourner_coins_face_finale()            //Oriente les coins de la face finale pour terminer le cube
{
    string combinaison="";

    if(cube[5][0][0]==faces[5] && cube[5][0][2]==faces[5] && cube[5][2][2]==faces[5] && cube[5][2][0]==faces[5])
    {}
    else
    {
        string iS="", iS2="";

        for(int i=0;i<4;i++)
        {
            switch(i)
            {
                case 0:
					iS="0";
					iS2="2";
                    break;
                case 1:
                    iS="1";
					iS2="3";
                    break;
                case 2:
                    iS="2";
					iS2="0";
                    break;
                case 3:
                    iS="3";
					iS2="1";
                    break;
            }
            if(cube[i][0][2]==faces[5] && cube[i][2][2]==faces[5])
            {
                combinaison="m"+iS+"p5p5p"+iS+"p5m"+iS+"p5p"+iS+"p"+iS2+"m5m5m"+iS2+"m5p"+iS2+"m5m"+iS2;
                lecture_string(combinaison);
            }
            else if(cube[(i+3)%4][2][2]==faces[5] && cube[(i+1)%4][0][2]==faces[5])
            {
                combinaison="m5p"+iS+"p"+iS+"p5p"+iS+"m5p"+iS+"p5p4m"+iS+"m"+iS+"m4m"+iS+"p4m"+iS+"m4";
                lecture_string(combinaison);
            }
        }

    if(cube[5][0][0]==faces[5] && cube[5][0][2]!=faces[5] && cube[5][2][0]!=faces[5])
    {
        if(cube[1][2][2]==faces[5])
        {
            combinaison="m5p2p2p5p2m5p2p5p4m2m2m4m2p4m2m4";
            lecture_string(combinaison);
        }
        else if(cube[0][0][2]==faces[5])
        {
            combinaison="m5p3p3p5p3m5p3p5p4m3m3m4m3p4m3m4";
            lecture_string(combinaison);
        }
    }
    if(cube[5][0][0]!=faces[5] && cube[5][0][2]==faces[5] && cube[5][2][2]!=faces[5])
    {
        if(cube[0][2][2]==faces[5])
        {
            combinaison="m5p1p1p5p1m5p1p5p4m1m1m4m1p4m1m4";
            lecture_string(combinaison);
        }
        else if(cube[3][0][2]==faces[5])
        {
            combinaison="m5p2p2p5p2m5p2p5p4m2m2m4m2p4m2m4";
            lecture_string(combinaison);
        }
    }
    if(cube[5][0][2]!=faces[5] && cube[5][2][2]==faces[5] && cube[5][2][0]!=faces[5])
    {
        if(cube[3][2][2]==faces[5])
        {
            combinaison="m5p0p0p5p0m5p0p5p4m0m0m4m0p4m0m4";
            lecture_string(combinaison);
        }
        else if(cube[2][0][2]==faces[5])
        {
            combinaison="m5p1p1p5p1m5p1p5p4m1m1m4m1p4m1m4";
            lecture_string(combinaison);
        }
    }
    if(cube[5][0][0]!=faces[5] && cube[5][2][2]!=faces[5] && cube[5][2][0]==faces[5])
    {
        if(cube[2][2][2]==faces[5])
        {
            combinaison="m5p3p3p5p3m5p3p5p4m3m3m4m3p4m3m4";
            lecture_string(combinaison);
        }
        else if(cube[1][0][2]==faces[5])
        {
            combinaison="m5p0p0p5p0m5p0p5p4m0m0m4m0p4m0m4";
            lecture_string(combinaison);
        }
    }


    for(int i=0;i<4;i++)
        {
            switch(i)
            {
                case 0:
					iS="0";
					iS2="2";
                    break;
                case 1:
                    iS="1";
					iS2="3";
                    break;
                case 2:
                    iS="2";
					iS2="0";
                    break;
                case 3:
                    iS="3";
					iS2="1";
                    break;
            }
            if(cube[i][0][2]==faces[5] && cube[i][2][2]==faces[5])
            {
                combinaison="m"+iS+"p5p5p"+iS+"p5m"+iS+"p5p"+iS+"p"+iS2+"m5m5m"+iS2+"m5p"+iS2+"m5m"+iS2;
                lecture_string(combinaison);
            }
            else if(cube[(i+3)%4][2][2]==faces[5] && cube[(i+1)%4][0][2]==faces[5])
            {
                combinaison="m5p"+iS+"p"+iS+"p5p"+iS+"m5p"+iS+"p5p4m"+iS+"m"+iS+"m4m"+iS+"p4m"+iS+"m4";
                lecture_string(combinaison);
            }
        }
    }
}

bool Cube::is_bien_place(int i, int j, int k)   //Teste si les 4 coins de la face finale sont bien placés (mais pas forcément bien orientés)
{
    int defil = 0;

    switch(j+10*k)
    {
        case 0:
            defil=0;
            break;
        case 2:
            defil=1;
            break;
        case 22:
            defil=2;
            break;
        case 20:
            defil=3;
            break;
        default:
            affichage_erreur("Erreur somme j+k");
            break;
    }

   return((cube[i][j][k]==cube[5][1][1] || cube[i][j][k]==cube[defil % 4][1][1] || cube[i][j][k]==cube[(defil+1) % 4][1][1])&&
            (cube[defil % 4][2][2]==cube[5][1][1] || cube[defil % 4][2][2]==cube[defil % 4][1][1] || cube[defil % 4][2][2]==cube[(defil+1) % 4][1][1])&&
            (cube[(defil+1) % 4][0][2]==cube[5][1][1] || cube[(defil+1) % 4][0][2]==cube[defil % 4][1][1] || cube[(defil+1) % 4][0][2]==cube[(defil+1) % 4][1][1]));

}
