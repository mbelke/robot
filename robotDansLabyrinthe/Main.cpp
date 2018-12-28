#include "terrain.h"
//#include "robot.h"

void main()
{
	terrain t;
	t.interfaceGraphique();
	glutReshapeFunc(terrain::redimensionnerCadreDeDessin);
	t.chargerLabyrinthe("murs.txt");
	glutDisplayFunc(terrain::affichageDuTerrain);
	t.labyrintheTimer(500);
	glutMainLoop();
}


