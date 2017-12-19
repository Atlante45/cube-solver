/*
Rubiks
Clément BRISSET et Julien CHAUMONT
Janvier 2010
Librairies utilisées: librairies mingw32 par défaut
IDE utilisé: CodeBlocks 8.02
*/

/*
--------------------------------------------------
Fichier couronne.cpp:
Algo de résolution à l'étape de la 2e couronne
--------------------------------------------------
*/

#include "Cube.h"

using namespace std;

bool Cube::positionner_arretes()	//Mise en place de la 2e couronne
{
	int face_avant=0, face_apres=0, faceint=0;	//Faces latérales
	int face_associee=0;	//Facette inférieure
	string face_avantString = "", face_apresString = "", face_actuelle = "", combinaison = "";
	int compteur_tours = 0;
	int coups_dans_le_vide = 0;

	while(!is_couronne_terminee())
	{
		for(int i=0; i<4; i++)
		{
			if(cube[i][1][2]==cube[i][1][1])
			{
			    switch(i)	//Définition de la variable face_associee (facette sur la face 5 associée à la face cube[i][1][2])
                {
                    case 0:
						face_avant=3;
						face_apres=1;
						face_avantString="3";
						face_apresString="1";
						face_actuelle="0";
                        face_associee=cube[5][0][1];
                        break;
                    case 1:
	                    face_avant=0;
						face_apres=2;
						face_avantString="0";
						face_apresString="2";
						face_actuelle="1";
                        face_associee=cube[5][1][0];
                        break;
                    case 2:
						face_avant=1;
						face_apres=3;
						face_avantString="1";
						face_apresString="3";
						face_actuelle="2";
                        face_associee=cube[5][2][1];
                        break;
                    case 3:
						face_avant=2;
						face_apres=0;
						face_avantString="2";
						face_apresString="0";
						face_actuelle="3";
                        face_associee=cube[5][1][2];
                        break;
                    default:
                        affichage_erreur("Valeur de int i non comprise entre 0 et 3");
                        break;
                }
				if(cube[face_avant][1][1]==face_associee || cube[face_apres][1][1]==face_associee)
				{
					if(cube[face_avant][1][1]==face_associee)
					{
						combinaison="m5m"+face_avantString+"p5p"+face_avantString+"p5p"+face_actuelle+"m5m"+face_actuelle;
						lecture_string(combinaison);
					}
					else if(face_associee == cube[face_apres][1][1])
					{
						combinaison="p5p"+face_apresString+"m5m"+face_apresString+"m5m"+face_actuelle+"p5p"+face_actuelle;
						lecture_string(combinaison);
					}
					else
						affichage_erreur("Erreur etrange...");
					coups_dans_le_vide = 0;
					afficher_cube();
				}
                if(is_couronne_terminee())
					return true;
			}
			else
                coups_dans_le_vide++;
		}
		if(is_couronne_terminee())
            break;
        tourner_face_moins(5);
        compteur_tours++;
		if(compteur_tours>100)
			break;
		if(coups_dans_le_vide>=16)
		{
			for(int i=0;i<4;i++)
			{
				if(cube[i][0][1]!=cube[i][1][1]||cube[i][2][1]!=cube[i][1][1])
				{
					faceint=i-1;
					if(faceint==-1)
						faceint=3;

					switch(faceint)	//Définition de la variable face_associee (facette sur la face 5 associée à la face cube[i][1][2])
					{
						case 0:
							face_avant=3;
							face_apres=1;
							face_avantString="3";
							face_apresString="1";
							face_actuelle="0";
							face_associee=cube[5][0][1];
							break;
						case 1:
							face_avant=0;
							face_apres=2;
							face_avantString="0";
							face_apresString="2";
							face_actuelle="1";
							face_associee=cube[5][1][0];
							break;
						case 2:
							face_avant=1;
							face_apres=3;
							face_avantString="1";
							face_apresString="3";
							face_actuelle="2";
							face_associee=cube[5][2][1];
							break;
						case 3:
							face_avant=2;
							face_apres=0;
							face_avantString="2";
							face_apresString="0";
							face_actuelle="3";
							face_associee=cube[5][1][2];
							break;
						default:
							affichage_erreur("Valeur de int i non comprise entre 0 et 3");
							break;
					}
					if(cube[i][0][1]!=cube[i][1][1])
					{
						combinaison="m5m"+face_avantString+"p5p"+face_avantString+"p5p"+face_actuelle+"m5m"+face_actuelle;
						lecture_string(combinaison);
					}
					else if(cube[i][2][1]!=cube[i][1][1])
					{
						combinaison="p5p"+face_apresString+"m5m"+face_apresString+"m5m"+face_actuelle+"p5p"+face_actuelle;
						lecture_string(combinaison);
					}
					else
						affichage_erreur("Erreur etrange...");
                    afficher_cube();
				}
			}
			coups_dans_le_vide = 0;
		}
	}
	if(is_couronne_terminee())
        return true;
    else
        return false;
}

bool Cube::is_couronne_terminee()
{
    bool couronne_terminee = false;

	for(int j=0; j<4; j++)	//Vérification de la couronne
    {
        if(cube[j][0][1]==cube[j][1][1] && cube[j][2][1]==cube[j][1][1])	//Si deux cases adjacente de la même face ont la même couleur...
            couronne_terminee = true;
        else	//Sinon, c'est que la couronne n'est pas finie
        {
            couronne_terminee = false;	//On (re)met le bool à false
            break;	//Et on sort de la boucle
        }
    }
    return couronne_terminee;
}
