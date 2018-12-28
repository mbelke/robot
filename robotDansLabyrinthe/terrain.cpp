#include "terrain.h"

const int nombreDeLignes = 20;
const int nombreDeColonnes = 20;
char matrice[nombreDeLignes][nombreDeColonnes];
robot monRobot;
const int TIMER_MILLIS=300;

int arriveeColonne;
int arriveeLigne;

void terrain::interfaceGraphique()
{
	//Position de la fenetre 
	glutInitWindowPosition(300, 100);
	//Taille de la fenetre
	glutInitWindowSize(500, 500);
	//Mode d'affichage
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
	//Titre de la fenêtre
	glutCreateWindow("Robot dans un labyrinthe");
}

void terrain::redimensionnerCadreDeDessin(int nombreDeColonnes, int nombreDeLignes)
{
	glViewport(0.0, 0.0, nombreDeColonnes, nombreDeLignes);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 20.0, 0.0, 20.0);
}

void terrain::affichageDuTerrain()
{
	glClearColor(0.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	dessinerLabyrinthe();
	monRobot.dessinerRobot();
	glutSwapBuffers();
}

//Lecture du fichier du labyrinthe et son stockage dans une matrice
void terrain::lectureFichierDuLabyrinthe(char* monFichier)
{
	//ouvertureFichierDuLabyrinthe(monFichier);
	std::ifstream fichier;
	fichier.open(monFichier);
	if(monFichier==0)
	{
		cout << "Fichier des murs introuvable!" << endl;
		system("pause");
		exit(1);
	}
	//Initialisation de la matrice 
	for(int i=0;i<nombreDeLignes;i++)
		for(int j=0;j<nombreDeColonnes;j++)
			matrice[i][j]='0';
	//Lecture du fichier de labyrinthe et stockage dans la matrice
	for(int i=0;i<nombreDeLignes;i++)
		for(int j=0;j<nombreDeColonnes;j++)
			fichier >> matrice[i][j];
	fichier.close();
}

//Determination des points de départ et d'arrivée
void terrain::departEtArrivee()
{
	for(int i=nombreDeLignes-1,k=0;i>=0;i--, k++)
	{
		for(int j=0;j<nombreDeColonnes;j++)
		{
			switch(matrice[i][j])
			{
			case 'd':
				monRobot.setPositionLigne(k);
				monRobot.setPositionColonne(j);
				break;
			case 'a':
				arriveeColonne=j;
				arriveeLigne=k;
				break;
			}
		}
	}
}

//charger le labyrinthe à partir d'un fichier
void terrain::chargerLabyrinthe(char* monFichier)
{
	lectureFichierDuLabyrinthe(monFichier);
	departEtArrivee();
}

//Dessin des murs
void terrain::dessinerLesMursDulabyrinth()
{
	glColor3d(0.3,0.4,0.8);
	glBegin(GL_QUADS);
	for(int i=nombreDeLignes-1,k=0;i>=0;i--,k++)
		for(int j=0;j<nombreDeColonnes;j++)
			if(matrice[i][j]=='0')
			{
				glVertex2d(j, k);
				glVertex2d(j+1, k);
				glVertex2d(j+1, k+1);
				glVertex2d(j, k+1);
			}
	glEnd();
}

//Dessin du point d'arrivée
void terrain::dessinPointDarrivee()
{
	glPushMatrix();
	glTranslated(arriveeColonne+0.5, arriveeLigne+0.5, 0.0);
	glColor3d(0.1, 1.0, 0.0);
	for(double carre=0.1; carre<1.0;carre+=0.2)
		glutWireCube(carre);
	glPopMatrix();
}
void terrain::dessinerLabyrinthe()
{
	//Dessin des murs
	dessinerLesMursDulabyrinth();
	//Dessin du point d'arrivée
	dessinPointDarrivee();
}

//Test de la victoire par l'arivée du robot au point d'arrivée
void terrain::victoire()
{
	if((monRobot.positionColonne()==arriveeColonne) && (monRobot.positionLigne()==arriveeLigne))
	{
		cout << "Bravo, vous avez gagné!" << endl;
		affichageDuTerrain();
		system("pause");
		exit(1);
	}
}

//Déplacer le robot selon la main droite
void terrain::deplacerRobotSelonLaMainDroite()
{
	int hasard=rand()%2;
	
	switch(hasard)
	{
	case 0:
		monRobot.tournerADroite();
		break;
	case 1:
		monRobot.avancer();
		break;
	}
	victoire();
	glutPostRedisplay();
}

//Fonction de synchronisation de déplacement du robot
void terrain::labyrintheTimer(int value)
{
	deplacerRobotSelonLaMainDroite();
	glutPostRedisplay();
	glutTimerFunc(TIMER_MILLIS, labyrintheTimer, 0);
}

void terrain::deplacerRobotSeleonPledge()
{
	int compteur=0;
	/*while((monRobot.positionColonne()!=arriveeColonne) && (monRobot.positionLigne()!=arriveeLigne))
	{
		if(compteur==0)
			monRobot.avancer();
	}*/
}

