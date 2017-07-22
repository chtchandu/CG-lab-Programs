#include<stdio.h>
#include<GL/glut.h>

#define maxx 20
#define maxy 20
#define dx 10
#define dy 15

GLint x[50],y[50];
int i,j;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	for(i=0;i<maxx;i++)
	{
		x[i]= 50+(i*dx);
	}
	for(j=0;j<maxy;j++)
	{
		y[j]= 50+(j*dy);
	}
	
	for(i=0;i<maxx-1;i++)
	{
		for(j=0;j<maxy-1;j++)
		{
			glBegin(GL_LINE_LOOP);
			glVertex2i(x[i],y[j]);
			glVertex2i(x[i+1],y[j]);
			glVertex2i(x[i+1],y[j+1]);
			glVertex2i(x[i],y[j+1]);
			glEnd();
		}
		glFlush();
	}
	
	glFlush();
}

void myinit()
{
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-1,1,-1,1,-1,1);
	//glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(0,499,0,499);
	glutPostRedisplay();
}

int main( int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("mesh");
	glutInitWindowPosition(50,50);
	glutInitWindowSize(500,500);
	//glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}

	
