/*
Rubiks
Clément BRISSET et Julien CHAUMONT
Janvier 2010
Librairies utilisées: librairies mingw32 par défaut
IDE utilisé: CodeBlocks 8.02
*/

/*
--------------------------------------------------
Fichier Cube.h:
Header de la classe Cube
--------------------------------------------------
*/

#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>

#define ERREUR cout << "Error line " << __LINE__ << "\nFile " << __FILE__ << "\nDate " << __DATE__ << "\nTime " << __TIME__ << "\nErreur: " << erreur << endl;


class Cube
{
    public:
        Cube();
        //Fichier divers.cpp
        void lecture_string(std::string combinaison);
        void affichage_erreur(std::string erreur);

    private:
        //Fichier Cube.cpp
        void initialiser_cube();
        void afficher_cube();
        void melanger_cube();
        //Fichier rotations.cpp
        void tourner_face_plus(int face, bool affichage=true);
        void tourner_face_moins(int face, bool affichae=true);
        //Fichier faceinitiale.cpp
        void positionner_arrete_face_initiale(int face);
        void faire_croix_face_initiale();
        void positioner_coin_face_initiale(int face_gauche,int face_droite);
        //Fichier couronne.cpp
        bool positionner_arretes();
        bool is_couronne_terminee();

        //Variables
        int cube[6][3][3];
};


#endif // CUBE_H_INCLUDED
