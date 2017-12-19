/*
Rubiks
Clément BRISSET et Julien CHAUMONT
Janvier 2010
Librairies utilisées: librairies mingw32 par défaut
IDE utilisé: CodeBlocks 8.02
*/

/*
--------------------------------------------------
Fichier faceinitiale.cpp:
Algos de résolution à l'étape de la 1ère face
--------------------------------------------------
*/

#include "Cube.h"

using namespace std;

void Cube::positionner_arrete_face_initiale(int face)
{
    string combinaison="";
    // Cas sur la couronne du bas à l'endroit
    if(cube[1][1][2]==4 && cube[5][1][0]==face)
        combinaison="p5p0m2m1m0p2";
    else if(cube[2][1][2]==4 && cube[5][2][1]==face)
        combinaison="p0m2p1m0p2";
    else if(cube[0][1][2]==4 && cube[5][0][1]==face)
        combinaison="p0m2m1m0p2";
    else if(cube[3][1][2]==4 && cube[5][1][2]==face)
        combinaison="m5p0m2m1m0p2";

    // Cas sur la couronne du bas à l'envers
    else if(cube[1][1][2]==face && cube[5][1][0]==4)
        combinaison="p0m2m1m1m0p2";
    else if(cube[2][1][2]==face && cube[5][2][1]==4)
        combinaison="p5p0m2m1m1m0p2";
    else if(cube[0][1][2]==face && cube[5][0][1]==4)
        combinaison="m5p0m2m1m1m0p2";
    else if(cube[3][1][2]==face && cube[5][1][2]==4)
        combinaison="m5m5p0m2m1m1m0p2";

    // Cas sur la couronne centrale sens 1
    else if(cube[1][2][1]==4 && cube[2][0][1]==face)
        combinaison="p4p4p3m4p5m2m4";
    else if(cube[2][2][1]==4 && cube[3][0][1]==face)
        combinaison="p1m4m4p5p5m3p4p4";
    else if(cube[0][2][1]==4 && cube[1][0][1]==face)
        combinaison="p4p2m4p5m1";
    else if(cube[3][2][1]==4 && cube[0][0][1]==face)
        combinaison="p1m4p5m0p4";

    // Cas sur la couronne centrale sens 2
    else if(cube[1][2][1]==face && cube[2][0][1]==4)
        combinaison="m4m0p4m5p1";
    else if(cube[2][2][1]==face && cube[3][0][1]==4)
        combinaison="m1p4m5p2m4";
    else if(cube[0][2][1]==face && cube[1][0][1]==4)
        combinaison="m4m4m3p4m5p0p4";
    else if(cube[3][2][1]==face && cube[0][0][1]==4)
        combinaison="m1m4m4p5p5p3p4p4";

    // Cas de la couronne du haut à l'endroit
    else if(cube[4][1][2]==4 && cube[1][1][0]==face)
    { }
    else if(cube[4][2][1]==4 && cube[2][1][0]==face)
        combinaison="p1m3p5m4p1m5p4m1p3";
    else if(cube[4][1][0]==4 && cube[3][1][0]==face)
        combinaison="p2m0p3m2p0m2p0p1p2m0";
    else if(cube[4][0][1]==4 && cube[0][1][0]==face)
        combinaison="m1p3p4m5m1m4p5m3p1";

    // Cas de la couronne du haut à l'envers
    else if(cube[4][1][2]==face && cube[1][1][0]==4)
        combinaison="m1p4m5p2m4p5p0m2m1m1m0p2";
    else if(cube[4][2][1]==face && cube[2][1][0]==4)
        combinaison="p1m3p2m1p3p0m2m1m1m0p2";
    else if(cube[4][1][0]==face && cube[3][1][0]==4)
        combinaison="p2m0p3m2p0p5p0m2m1m1m0p2";
    else if(cube[4][0][1]==face && cube[0][1][0]==4)
        combinaison="m1p3p0p1m3p5p5p0m2m1m1m0p2";
    else { }
    lecture_string(combinaison);
}

void Cube::positioner_coin_face_initiale(int face_gauche,int face_droite)
{
    string combinaison="";
    // Cas coin en bas sens 1
    if(cube[1][2][2]==4 && cube[2][0][2]==face_droite)
        combinaison="p5p2m5m2";
    else if(cube[2][2][2]==4 && cube[3][0][2]==face_droite)
        combinaison="m5p2m5m5m2";
    else if(cube[3][2][2]==4 && cube[0][0][2]==face_droite)
        combinaison="p2m5m5m2";
    else if(cube[0][2][2]==4 && cube[1][0][2]==face_droite)
        combinaison="p2m5m2";

    // Cas coin en bas sens 1
    else if(cube[1][2][2]==face_gauche && cube[2][0][2]==4)
        combinaison="m5m1p5p1";
    else if(cube[2][2][2]==face_gauche && cube[3][0][2]==4)
        combinaison="m1p5p1";
    else if(cube[3][2][2]==face_gauche && cube[0][0][2]==4)
        combinaison="m1p5p5p1";
    else if(cube[0][2][2]==face_gauche && cube[1][0][2]==4)
        combinaison="p5m1p5p5p1";

    // Cas coin en bas à l'envers
    else if(cube[1][2][2]==face_droite && cube[2][0][2]==face_gauche)
        combinaison="p2m5m2m1p5p5p1";
    else if(cube[2][2][2]==face_droite && cube[3][0][2]==face_gauche)
        combinaison="p5p2m5m2m1p5p5p1";
    else if(cube[3][2][2]==face_droite && cube[0][0][2]==face_gauche)
        combinaison="p5p5p2m5m2m1p5p5p1";
    else if(cube[0][2][2]==face_droite && cube[1][0][2]==face_gauche)
        combinaison="m5p2m5m2m1p5p5p1";

    // Cas coin en haut à l'endroit
    else if(cube[1][2][0]==face_gauche && cube[2][0][0]==face_droite)
    { }
    else if(cube[2][2][0]==face_gauche && cube[3][0][0]==face_droite)
        combinaison="p3p5m3p5p2m5m2";
    else if(cube[3][2][0]==face_gauche && cube[0][0][0]==face_droite)
        combinaison="p0p5p5m0p5p2m5m2";
    else if(cube[0][2][0]==face_gauche && cube[1][0][0]==face_droite)
        combinaison="p1p5m1m5p2m5m2";

    // Cas coin en haut sens 1
    else if(cube[1][2][0]==4 && cube[2][0][0]==face_gauche)
        combinaison="p2p5m2m5p2m5m2m1p5p5p1";
    else if(cube[2][2][0]==4 && cube[3][0][0]==face_gauche)
        combinaison="p3p5m3p2m5m2m1p5p5p1";
    else if(cube[3][2][0]==4 && cube[0][0][0]==face_gauche)
        combinaison="p0p5m0p5p2m5m2m1p5p5p1";
    else if(cube[0][2][0]==4 && cube[1][0][0]==face_gauche)
        combinaison="p1p5m1m5m5p2m5m2m1p5p5p1";

    // Cas coin en haut sens 2
    else if(cube[3][2][0]==face_droite && cube[0][0][0]==4)
        combinaison="m3m5p3m5p2m5m2m1p5p5p1";
    else if(cube[0][2][0]==face_droite && cube[1][0][0]==4)
        combinaison="m0m5p0p2m5m2m1p5p5p1";
    else if(cube[1][2][0]==face_droite && cube[2][0][0]==4)
        combinaison="m1m5p1p5p2m5m2m1p5p5p1";
    else if(cube[2][2][0]==face_droite && cube[3][0][0]==4)
        combinaison="m2m5p2p5p5p2m5m2m1p5p5p1";

    lecture_string(combinaison);
}

void Cube::faire_croix_face_initiale()
{

    positionner_arrete_face_initiale(1);
    positioner_coin_face_initiale(1, 2);
    tourner_face_plus(4);
    positionner_arrete_face_initiale(0);
    positioner_coin_face_initiale( 0, 1);
    tourner_face_plus(4);
    positionner_arrete_face_initiale(3);
    positioner_coin_face_initiale(3, 0);
    tourner_face_plus(4);
    positionner_arrete_face_initiale(2);
    positioner_coin_face_initiale(2, 3);
    tourner_face_plus(4);
    afficher_cube();
}

