#pragma once
#include <glut.h>
#include <glm.hpp>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>

class Ball
{
public:
	Ball(glm::vec3 iposition, int iradius, int imass) { position.x = iposition.x; position.y = iposition.y; position.z = iposition.z; radius = iradius;	mass = imass; }
	virtual ~Ball();
	void Draw();
	void Move(glm::vec3 direction);
private:
	int radius;
	float mass;
	glm::vec3 force;
	float acceleration;
	glm::vec3 position;
	float friction = 5;//temporary, will need an actual equation at some point

	
};

