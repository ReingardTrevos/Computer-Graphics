// Template1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include "include\GL\GL.H"
#include "include\GL\GLU.H"
#include "include\GL\glut.h"

float rAngle = 0.0;
float rHeight = 0.0;
int rSwitch = 0;

void tri(float r, float g, float b, float f) {
	glBegin(GL_TRIANGLES);// OpenGL’a state
	glColor4f(r, g, b, f);
	glVertex2f(0.0f, 0.0f);
	glColor4f(r, g, b, f);
	glVertex2f(50.0f, 0.0f);
	glColor4f(r, g, b, f);
	glVertex2f(0.0f, 50.0f);

	glEnd();
}

void pos() {
	//jedna grupa sa zielony i pomaranczowy
	//a druga fioletowy niebieski  zolty i rozowy
	//czerwony
	//zielony   zolty
	//niebieski pomaranczowy rozowy
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();

	glRotatef(rAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(rHeight, 0, 0);
	glTranslatef(0, rHeight, 0);
	glTranslatef(17, 17, 0);
	glRotatef(2 * rAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(-17, -17, 0);
	tri(0.0, 0.0, 1.0, 0.0);//niebieski




	glPopMatrix();
	glRotatef(-rAngle, 0.0f, 0.0f, 1.0f);// jak sie ma obracac
	glTranslatef(0.17*rHeight, 0, 0);
	glTranslatef(0, 0.67*rHeight, 0);
	glTranslatef(50, 0, 0); //gdzie chcesz go narysowac
	glTranslatef(17, 17, 0);
	glRotatef(-2 * rAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(-17, -17, 0);
	tri(1.0, 0.5, 0.0, 0.0);//pomaranczowy



	glPopMatrix();
	glRotatef(rAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(1.17*rHeight, 0, 0);
	glTranslatef(0, 0.17*rHeight, 0);
	glTranslatef(100, 0, 0);
	glTranslatef(17, 17, 0);
	glRotatef(2 * rAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(-17, -17, 0);
	tri(1.0, 0.0, 1.0, 0.0);//fiolet

	glPopMatrix();
	glRotatef(rAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(rHeight, 0, 0);
	glTranslatef(0, rHeight, 0);
	glTranslatef(50, 50, 0);
	glTranslatef(17, 17, 0);
	glRotatef(2 * rAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(-17, -17, 0);
	tri(1.0, 1.0, 0.0, 0.0);//zolty


	glPopMatrix();
	glRotatef(-rAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.17*rHeight, 0, 0);
	glTranslatef(0, 0.67*rHeight, 0);
	glTranslatef(0, 50, 0);
	glTranslatef(17, 17, 0);
	glRotatef(-2 * rAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(-17, -17, 0);
	tri(0.0, 1.0, 0.0, 0.0);//zielony

	glPopMatrix();
	glRotatef(rAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.17*rHeight, 0, 0);
	glTranslatef(0, 1.17*rHeight, 0);
	glTranslatef(0, 100, 0);
	glTranslatef(17, 17, 0);
	glRotatef(2 * rAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(-17, -17, 0);
	tri(1.0, 0.0, 0.0, 0.0);//czerwony


	glPopMatrix();
}

void MyDisplay(void) {
	// The new scene


	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);

	pos();


	//druga cwiartka
	glRotated(90.0, 0.0, 0.0, 1.0);

	pos();


	//trzecia cwiartka
	glRotated(180.0, 0.0, 0.0, 1.0);

	pos();

	//czwarta cwiartka
	glRotated(270.0, 0.0, 0.0, 1.0);

	pos();


	glFlush();//start processing buffered OpenGL routines


}

void update(int value/*, int value1, int value2 */) {
	rAngle += 1.0f;
	if (rAngle > 360) {
		rAngle -= 360;
	}

	if (rSwitch == 0) {
		rHeight += 1.0;
	}

	else if (rSwitch == 1) {
		rHeight -= 1.0;
	}

	if (rHeight == 90) {
		rSwitch = 1;
	}

	else if (rHeight == 0) {
		rSwitch = 0;
	}
	

	glutPostRedisplay(); // Inform GLUT that the display has changed

	glutTimerFunc(25, update, 0);//Call update after each 25 millisecond
}

void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);//select clearing (background) color
									 /* initialize viewing values */
	glViewport(0, 0, 1300, 1300);//window origin and size
	glMatrixMode(GL_PROJECTION);//
	glLoadIdentity();//=1
	gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//=1
}

int main(int argc, char** argv) { //<- for normal API
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//single buffer and RGBA
	glutInitWindowSize(1500, 1500);//initial window size
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My window");//create widnow, hello title bar
	MyInit();
	glutDisplayFunc(MyDisplay);//
	glutTimerFunc(20, update, 0);
	glutMainLoop();//enter main loop and process events

	return 0;
}