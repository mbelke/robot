#include "robot.h"	

extern const int nombreDeLignes=20;
extern const int nombreDeColonnes=20;
extern char matrice[nombreDeLignes][nombreDeColonnes];

int robot::positionLigne()
{
	return d_positionLigne;
}

int robot::positionColonne()
{
	return d_positionColonne;
}

void robot::setPositionLigne(int positionLigne)
{
	d_positionLigne=positionLigne;
}

void robot::setPositionColonne(int positionColonne)
{
	d_positionColonne=positionColonne;
}

void robot::dessinerCorp()
{
	glColor3d(0.0, 0.0, 0.0);
	glutSolidSphere(0.45, 16.0, 16.0);
}

void robot::dessinerOeil()
{
	glutSolidSphere(0.07, 16.0, 16.0);
}

void robot::dessinerRobot()
{
	glPushMatrix();
	glTranslated(d_positionColonne+0.5, d_positionLigne+0.5, 0.0);
	dessinerCorp();
	glColor3d(1.0, 1.0, 0.0);
	glTranslated(0.2, 0.2, 0.0);
	dessinerOeil();
	glTranslated(-0.4, 0.0, 0.0);
	dessinerOeil();
	glPopMatrix();
}

bool robot::detecterObstacleDevant()
{
	return ((d_positionLigne<nombreDeLignes-1) && (matrice[nombreDeLignes-2-d_positionLigne][d_positionColonne])!='0') ;
}

void robot::avancer()
{
	if(detecterObstacleDevant())
		d_positionLigne++;
}

bool robot::detecterObstacleADroite()
{
	return (d_positionColonne<nombreDeColonnes-1 && (matrice[nombreDeLignes-1-d_positionLigne][d_positionColonne+1])!='0');
}

void robot::tournerADroite()
{
	if(detecterObstacleADroite())
	d_positionColonne++;		
}

bool robot::detecterObstacleAGauche()
{
	return (d_positionColonne>0 && (matrice[nombreDeLignes-1-d_positionLigne][d_positionColonne-1])!='0' && (matrice[nombreDeLignes-1-d_positionLigne][d_positionColonne+1])!='1');
}

void robot::tournerAGauche()
{
	if(detecterObstacleAGauche())
		d_positionColonne--; 	
}


void robot::pledgeAlgorithme()
{
	
	
	
	
	
	
}


