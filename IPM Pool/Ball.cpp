#include "Ball.h"



Ball::~Ball()
{
}
void Ball::Draw() {
	glBegin(GL_POLYGON);
		const int NPOINTS = 30;
		const float TWOPI = M_PI * 2;
		const float STEP = TWOPI / NPOINTS;
		glColor3f(1.0f, 1.0f, 1.0f);
		for (float angle = 0; angle < TWOPI; angle += STEP)
		{
			glVertex2f(position.x + radius*cos(angle), position.y + radius*sin(angle));
		}
	glEnd();
}
void Ball::Move(glm::vec3 direction) {
	position += direction;
	//acceleration = mass / force;
	//while (acceleration!=0)
	//{
	//	if (inForce.x<0)
	//	{
	//		inForce.x -= friction;
	//	}
	//	if (inForce.x>0)
	//	{
	//		inForce.x += friction;
	//	}
	//	if (inForce.y>0)
	//	{
	//		inForce.y += friction;
	//	}
	//	if (inForce.y<0)
	//	{
	//		inForce.y -= friction;
	//	}
	//}
}