#include <iostream>
#include<Windows.h> 
#include<gl/glew.h>
#include<gl/GL.h>    
#include<gl/GLU.h>    
#include<gl/glut.h> 

void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINES);
	glVertex2f(10, 10);
	glVertex2f(10, 40);
	glEnd();

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

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("OpenGLIntro.cpp");

	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);

	setup();

	glutMainLoop();
}
