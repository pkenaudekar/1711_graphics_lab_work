#include <iostream>
#include<Windows.h> 
#include<gl/glew.h>
#include<gl/GL.h>    
#include<gl/GLU.h>    
#include<gl/glut.h> 

#define PI 3.14159265
static float xV = 1.0, yV = 1.0;
static float xC = 1.0, yC = 1.0;
static float direction = 1;
static int N = 10000;

void drawCar(void)
{
	double th = 0.0;
	int i = 0;
	glBegin(GL_POLYGON);/*glBegin and glEnd delimit the vertices that define a primitive or a group of like primitives.
						  glBegin accepts a single argument that specifies in which of ten ways the vertices are interpreted
						  Taking n as an integer count starting at one, and N as the total number of vertices specified
						  GL_LINE_LOOP
						  Draws a connected group of line segments from the first vertex to the last,
						  then back to the first. Vertices n and n+1 define line n. The last line, however, is defined by vertices
						  N and 1. N lines are drawn.*/
	glColor3f(0.0, 0.0, 0.0);

	for (i = 0; i < N; i++)
	{
		glVertex2d((17.0 +xC) + 2.0 * cos(th), 23.0 + 2.0 * sin(th));
		th += 2 * PI / N;
	}
	glEnd();

	glBegin(GL_POLYGON);/*glBegin and glEnd delimit the vertices that define a primitive or a group of like primitives.
						  glBegin accepts a single argument that specifies in which of ten ways the vertices are interpreted
						  Taking n as an integer count starting at one, and N as the total number of vertices specified
						  GL_LINE_LOOP
						  Draws a connected group of line segments from the first vertex to the last,
						  then back to the first. Vertices n and n+1 define line n. The last line, however, is defined by vertices
						  N and 1. N lines are drawn.*/
	glColor3f(0.0, 0.0, 0.0);

	for (i = 0; i < N; i++)
	{
		glVertex2d((26.0 + xC)+ 2.0 * cos(th), 23.0 + 2.0 * sin(th));
		th += 2 * PI / N;
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(xC + 13, yC + 22);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(xC + 30, yC + 22);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(xC + 30, yC + 25);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(xC + 13, yC + 25);
	glEnd();
	
}

void drawRoad(void)
{
	glBegin(GL_POLYGON);/*Left piller*/
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(xV + 10, yV + 10);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(xV + 13, yV + 10);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(xV + 13, yV + 30);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(xV + 10, yV + 30);
	glEnd();

	glBegin(GL_POLYGON);/*Right piller*/
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(xV + 87, yV + 10);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(xV + 90, yV + 10);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(xV + 90, yV + 30);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(xV + 87, yV + 30);
	glEnd();

	glBegin(GL_POLYGON);/*Road Code*/
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(xV + 10, yV + 10);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(xV + 90, yV + 10);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(xV + 90, yV + 20);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(xV + 10, yV + 20);
	glEnd();
}

void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	drawRoad();
	drawCar();
	glFlush();
}

void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 97:
			if (xC < 56 && direction == 1)
			{
				xC += 7.0;
			}
			else if(xC > 1 && direction == 0)
			{
				xC -= 7.0;
			}
			else if (xC <= 1 && direction == 0)
			{
				direction = 1;
			}
			else if (xC >= 56 && direction == 1)
			{
				direction = 0;
			}
		
		glutPostRedisplay();
		break;

		default:
			break;
	}
}


int main(int argc, char **argv)
{
	glClear(GL_COLOR_BUFFER_BIT);
	std::cout << xV << std::endl;
	std::cout << yV << std::endl;
	std::cout << xC << std::endl;
	std::cout << yC << std::endl;
	glutInit(&argc, argv);/*is used to initialize the GLUT library
						  argcp - A pointer to the program's unmodified argc variable from main.
						  Upon return, the value pointed to by argcp will be updated, because glutInit
						  extracts any command line options intended for the GLUT library.
						  argv - The program's unmodified argv variable from main. Like argcp,
						  the data for argv will be updated because glutInit extracts any command
						  line options understood by the GLUT library.*/

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);/*Display mode, normally the bitwise OR-ing of GLUT display mode bit masks
												  GLUT_SINGLE - Bit mask to select a single buffered window. This is the default
												  if neither GLUT_DOUBLE or GLUT_SINGLE are specified.
												  GLUT_RGBA - Bit mask to select an RGBA mode window. This is the default if neither
												  GLUT_RGBA nor GLUT_INDEX are specified. */

	glutInitWindowSize(500, 500);/*set the initial window size*/
	glutInitWindowPosition(100, 100);/*set the initial window position*/

	glutCreateWindow("OpenGLIntro.cpp");/*creates a top-level window.*/

	glutDisplayFunc(drawScene);/* sets the display callback for the current window.
							   void glutDisplayFunc(void (*func)(void));
							   func - The new display callback function. */
	glutReshapeFunc(resize); /*sets the reshape callback for the current window.
							 void glutReshapeFunc(void (*func)(int width, int height));
							 func - The new reshape callback function. */
	glutKeyboardFunc(keyInput);/*sets the keyboard callback for the current window
							   void glutKeyboardFunc(void (*func)(unsigned char key,int x, int y));
							   func - The new keyboard callback function. */

	setup();

	glutMainLoop();/*glutMainLoop - enters the GLUT event processing loop. This routine should be called
				   at most once in a GLUT program. Once called, this routine will never return. It will
				   call as necessary any callbacks that have been registered.*/
}
