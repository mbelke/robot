#ifndef ROBOT_H
#define ROBOT_H

#include <cstdlib>
#include "GL\glut.h"

class robot
{
private:
	int d_positionLigne;
	int d_positionColonne;

	void dessinerCorp();
	void dessinerOeil();
public:
	int positionLigne();
	int positionColonne();
	void setPositionLigne(int positionLigne);
	void setPositionColonne(int positionColonne);
	void dessinerRobot();
	bool detecterObstacleDevant();
	bool detecterObstacleADroite();
	bool detecterObstacleAGauche();
	void avancer();
	void tournerAGauche();
	void tournerADroite();
};
#endif //ROBOT_H