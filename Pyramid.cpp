// OpenGLTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"glut32.lib")
#include<Windows.h>
#include<gl/gl.h>
#include<gl/glu.h>
#include<gl/glut.h>
#include<math.h>
#include <iostream>

using namespace std;

/**
Creates the main window, registers event handlers, and
initializes OpenGL stuff.
*/
void InitGraphics(int argc, char* argv[]);

/**
Sets the logical coordinate system we will use to specify
our drawings.
*/
void SetTransformations();

/**
Handles the paint event. This event is triggered whenever
our displayed graphics are lost or out-of-date.
ALL rendering code should be written here.
*/
void OnDisplay();

void DrawCircle(float x, float y, float radius);

void DrawEllipse(float x, float y, float XRadius, float YRadius);

int main(int argc, char* argv[]) {
	InitGraphics(argc, argv);
	return 0;
}


/**
Creates the main window, registers event handlers, and
initializes OpenGL stuff.
Initialization is done once at the start of the program.
Rendering is done each time the window needs redrawing
*/

void InitGraphics(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	//Create an 800x600 window with its top-left corner at pixel (100, 100)
	glutInitWindowPosition(100, 100); //pass (-1, -1) for Window-Manager defaults  glutInitWindowPosition(X, Y);
	glutInitWindowSize(800, 600);  //glutInitWindowSize(width, hight);
	glutCreateWindow("Test");
	//OnDisplay will handle the paint event
	glutDisplayFunc(OnDisplay);

	glutMainLoop();//Well glutMainLoop is the main function the keeps calling and calling the displaying functions and which also keeps your window actually opened
}
/**
}
Sets the logical coordinate system we will use to specify
our drawings.
*/
void SetTransformations()
{
	//set up the logical coordinate system of the window: [-100, 100] x [-100, 100]
	glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();

//define a 2-D orthographic projection matrix
//parameters: left, right, bottom, top
	gluOrtho2D(-150, 150, -150, 150); //gluOrtho2f(GLdouble left,GLdouble right,GLdouble bottom,GLdouble top)
}
/**
Handles the paint event. This event is triggered whenever
our displayed graphics are lost or out-of-date.
ALL rendering code should be written here.
*/
void OnDisplay() {
	//set the background color to white
	glClearColor(0, 0, 0.243137254901961,0);
	//fill the whole color buffer with the clear color
	glClear(GL_COLOR_BUFFER_BIT);
	SetTransformations();

	//ALL drawing code goes here

	
	// BACK-GROUNG 

	glColor3f(0, 0, 0.250980392156863);
	glBegin(GL_QUADS);
	glVertex3f(150, 30, 0);
	glVertex3f(150, 150, 0);
	glVertex3f(-150, 150, 0);
	glVertex3f(-150, 30, 0);
	glEnd();

	glColor3f(1, 1, 1);
	DrawCircle(70, 100, 50);
	glColor3f(0, 0, 0.243137254901961);
	DrawCircle(60, 103, 50);
	
	glPointSize(7);
	glColor3f(1, 1, 1);
	glBegin(GL_POINTS);
	glVertex3f(-60, 90, 0);
	glVertex3f(-90, 70, 0);
	glVertex3f(-100, 100, 0);
	glVertex3f(-120, 110, 0);
	glVertex3f(-1500, 130, 0);
	glEnd();

	
	// PYRAMID

	glColor3f(0.925490196078431, 0.925490196078431, 0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-25, 100, 0);
	glVertex3f(-130, -130, 0);
	glVertex3f(50, -130, 0);
	glEnd();

	// stones

	for (int i = -107; i < 30; i +=26)
	{
		glColor3f(0.643137254901961, 0.643137254901961, 0);
		glBegin(GL_QUADS);
		glVertex3f(i, -100, 0);
		glVertex3f(i, -80, 0);
		glVertex3f(i+26, -80, 0);
		glVertex3f(i+26, -100, 0);
		glEnd();
	}
	for (int i = -120; i < 40; i += 24)
	{
		glColor3f(0.643137254901961, 0.643137254901961, 0);
		glBegin(GL_QUADS);
		glVertex3f(i, -130, 0);
		glVertex3f(i, -110, 0);
		glVertex3f(i + 26, -110, 0);
		glVertex3f(i + 26, -130, 0);
		glEnd();
	}
	for (int i = -91; i < 20; i += 26)
	{
		glColor3f(0.643137254901961, 0.643137254901961, 0);
		glBegin(GL_QUADS);
		glVertex3f(i, -70, 0);
		glVertex3f(i, -50, 0);
		glVertex3f(i + 26, -50, 0);
		glVertex3f(i + 26, -70, 0);
		glEnd();
	}
	for (int i = -80; i < 0; i += 26)
	{
		glColor3f(0.643137254901961, 0.643137254901961, 0);
		glBegin(GL_QUADS);
		glVertex3f(i, -40, 0);
		glVertex3f(i, -20, 0);
		glVertex3f(i + 26, -20, 0);
		glVertex3f(i + 26, -40, 0);
		glEnd();
	}
	for (int i = -65; i < 0; i += 26)
	{
		glColor3f(0.643137254901961, 0.643137254901961, 0);
		glBegin(GL_QUADS);
		glVertex3f(i, -10, 0);
		glVertex3f(i, 10, 0);
		glVertex3f(i + 26, 10, 0);
		glVertex3f(i + 26, -10, 0);
		glEnd();
	}
	for (int i = -52; i < 0; i += 26)
	{
		glColor3f(0.643137254901961, 0.643137254901961, 0);
		glBegin(GL_QUADS);
		glVertex3f(i, 20, 0);
		glVertex3f(i, 40, 0);
		glVertex3f(i + 26, 40, 0);
		glVertex3f(i + 26, 20, 0);
		glEnd();
	}

	//
	glColor3f(0.843137254901961, 0.843137254901961, 0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(50, -130, 0);
	glVertex3f(80, -90, 0);
	glVertex3f(-25, 100, 0);
	glEnd();


	
	//glBegin(GL_)
	//force previously issued OpenGL commands to begin execution
	glFlush();
}
void DrawCircle(float xc, float yc, float radius)
{

	float PI = 3.14;
	int triangleAmount = 36; //# of triangles used to draw circle

	GLfloat twicePi = 2.0 * PI;

	glBegin(GL_POLYGON);
	//glVertex2f(a, b); // center of circle
	for (int i = 0; i <= triangleAmount; i++) {

		float theta = i * twicePi / triangleAmount;  //get the current angle
		glVertex2f(xc + (radius * cos(theta)),yc + (radius * sin(theta))
		);
	}
	glEnd();
}

