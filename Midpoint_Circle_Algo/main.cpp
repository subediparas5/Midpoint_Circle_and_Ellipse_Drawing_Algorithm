#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

int _x, _y, r;

int round_off(float a){
    return (a-int(a))>=0.5?int(a)+1:int(a);
}

void _point(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(round_off(x+_x), round_off(y+_y));
	glEnd();
}

void Init ()
{
	glClearColor(0,0,0,1);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void midPointCircleAlgo()
{
	int x = 0;
	int y = r;
	float decision = 1 - r;
	_point(x, y);

	while (y > x)
	{
		if (decision < 0)//midpoint outside circle perimeter
		{
			x++;
			decision += 2*x+1;
		}
		else//midpoint inside circle perimeter
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		_point(x, y);
		_point(x, -y);
		_point(-x, y);
		_point(-x, -y);
		_point(y, x);
		_point(-y, x);
		_point(y, -x);
		_point(-y, -x);
	}
}

void display()
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1,1,1);
	glPointSize(1.0);
	midPointCircleAlgo();
	glFlush ();
}

void Read(){
printf("Enter the value of x : ");
scanf("%i",&_x);
printf("Enter the value of y : ");
scanf("%i",&_y);
printf("Enter the radius of circle : ");
scanf("%i",&r);
}

int main(int argc, char *argv[])
{
	Read();
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Midpoint Circle Drawing Algorithm");
	Init ();
	glutDisplayFunc(display);
	glutMainLoop();
    return EXIT_SUCCESS;
}
