#include <iostream>
#include<Windows.h> 
#include<gl/glew.h>
#include<gl/GL.h>    
#include<gl/GLU.h>    
#include<gl/glut.h> 


static int angleArm = 0, angleForearm = 0, angleHand = 0;
static int xP = 11, yP = 56;

void drawHand(void)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(56, 51);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(68, 51);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(68, 61);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(56, 61);
	glEnd();
}

void drawForearm(void)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(34, 52);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(61, 52);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(61, 60);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(34, 60);
	glEnd();

	glPushMatrix();
	glTranslatef(xP+47, yP, 0.0);
	glRotatef(angleHand, 0, 0, 1);
	glTranslatef((-(xP+47)), -yP, 0.0);
	drawHand();
	glPopMatrix();
	glFlush();
}

void drawArm(void)
{
	glBegin(GL_POLYGON);/*Arm Part*/
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(11, 51);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(41, 51);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(41, 61);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(11, 61);
	glRotatef(90.0, 0.0f, 0.0f, 1.0f);
	glEnd();

	glPushMatrix();
	glTranslatef(xP+25, yP, 0.0);
	glRotatef(angleForearm, 0, 0, 1);
	glTranslatef((-(xP+25)), -yP, 0.0);
	drawForearm();
	glPopMatrix();
	glFlush();
}



void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(xP, yP, 0.0);
	glRotatef(angleArm, 0, 0, 1);
	glTranslatef(-xP, -yP, 0.0);
	drawArm();
	glPopMatrix();
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
		case 'q':
		{
			angleArm = 15; 
			glutPostRedisplay();
			break;
		}					
		case 'a':
		{
			angleArm = -15;
			glutPostRedisplay();
			break;
		}
		case 'w':
		{
			angleForearm = 20;
			glutPostRedisplay();
			break;
		}
		case 's':
		{
			angleForearm = -20; 
			glutPostRedisplay();
			break;
		}
		case 'e':
		{
			angleHand = 20;
			glutPostRedisplay();
			break;
		}
		case 'd':
		{
			angleHand = -20;
			glutPostRedisplay();
			break;
		}
		default:
			break;
	}
}

int main(int argc, char **argv)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	std::cout << angleArm << std::endl;
	std::cout << angleForearm << std::endl;
	std::cout << angleHand << std::endl;
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
