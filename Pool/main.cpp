#include <glut.h>
#include "Ball.h"

const int WINDOWWIDTH = 350, WINDOWHEIGHT = 700;
bool playing = true;
glm::vec3 startPos = glm::vec3(float(WINDOWWIDTH / 2), float(WINDOWHEIGHT / 4),1.0f);
int startRadius = 15;
Ball cueball(startPos, startRadius, 170);//mass is given in grams. cueball is 170, other balls are 160
glm::vec3 forceIntoBall;//temporary variable to check if movement is working

void keyPress(unsigned char key, int x, int y) {
	switch (key)
	{
		case 'w':
			forceIntoBall += glm::vec3(0.0, 2.0, 1.0);
			break;
		default:
			break;
	}
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	if (playing)
	{
		cueball.Draw();
		cueball.Move(forceIntoBall);
	}
	glutSwapBuffers();
	glFlush();
}

void timer(int value) {
	display();

	glutTimerFunc(60, timer, 0);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WINDOWWIDTH, WINDOWHEIGHT);
	glutCreateWindow("Pool");
	gluOrtho2D(0, WINDOWWIDTH, 0, WINDOWHEIGHT);
	glClearColor(0.2 ,1.0, 0.4, 1.0);
	glutDisplayFunc(display);
	glutTimerFunc(60, timer, 0);
	glutIdleFunc(display);
	glutKeyboardFunc(keyPress);
	glutMainLoop();
	return 0;
}