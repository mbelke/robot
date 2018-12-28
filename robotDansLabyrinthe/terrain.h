#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include <fstream>
#include "GL\glut.h"
//#include "robot.h"

using std::fstream;
using std::cout;
using std::endl;

class terrain
{
private:
	//Lecture du fichier du labyrinthe et son stockage dans une matrice
	static void lectureFichierDuLabyrinthe(char* monFichier);
	//Determination des points de depart et d'arrivée
	static void departEtArrivee();
	static void dessinerLesMursDulabyrinth();
	static void dessinPointDarrivee();

public:
	void interfaceGraphique();
	static void redimensionnerCadreDeDessin(int nombreDeColonnes, int nombreDeLignes);
	//affichage du terrain, composé d'un labyrinthe et d'un robot
	static void affichageDuTerrain();
	//charger le labyrinthe à partir d'un fichier
	static void chargerLabyrinthe(char* monFichier);
	static void dessinerLabyrinthe();
	static void deplacerRobotSelonLaMainDroite();
	//Gestion de déplacements du robot 
	static void labyrintheTimer(int value);
	//Test de la victoire par l'arrivée du robot au point d'arrivée
	static void victoire();
	static void deplacerRobotSeleonPledge();
};

#endif










