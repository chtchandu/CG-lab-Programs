#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

GLfloat house[3][9]={{100,100,200,300,300,175,125,125,175},{100,200,300,200,100,100,100,150,150},{1,1,1,1,1,1,1,1,1}};
GLfloat rot[3][3] = {{0},{0},{0}};
GLfloat res[3][9] = {{0},{0},{0}};
GLfloat h =100,k=100;
GLfloat theta,rad;
void multiply();
void drawhouse(GLfloat house[3][9])
{
	glColor3f(1,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(house[0][0],house[1][0]);
	glVertex2f(house[0][1],house[1][1]);
	glVertex2f(house[0][3],house[1][3]);
	glVertex2f(house[0][4],house[1][4]);
	glEnd();
	
	
	glBegin(GL_LINE_LOOP);
	glVertex2f(house[0][2],house[1][2]);
	glVertex2f(house[0][3],house[1][3]);
	glVertex2f(house[0][1],house[1][1]);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glVertex2f(house[0][5],house[1][5]);
	glVertex2f(house[0][6],house[1][6]);
	glVertex2f(house[0][7],house[1][7]);
	glVertex2f(house[0][8],house[1][8]);
	glEnd();
}

void rotate()
{
	float m,n;
	
	m = -h*(cos(theta)-1) + k*sin(theta);
	n = -k*(cos(theta)-1) - h*sin(theta);
	
	rot[0][0] = cos(theta);
	rot[0][1] = -sin(theta);
	rot[0][2] = m;
	rot[1][0] = sin(theta);
	rot[1][1] = cos(theta);
	rot[1][2] = n;
	rot[2][0] = 0;
	rot[2][1] = 0;
	rot[2][2] = 1;
	
	multiply();
}

void multiply()
{
	int i,j,k;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<9;j++)
		{
			res[i][j]=0;
			for(k=0;k<3;k++)
			{
				res[i][j] = res[i][j] + rot[i][k]*house[k][j];
			}
		}
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawhouse(house);
	theta =rad;
	rotate();
	drawhouse(res);
	glFlush();
}

void myinit()
{
	glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,499,0,499);
	glMatrixMode(GL_MODELVIEW);
}

int main( int argc, char **argv)
{
	glutInit(&argc,argv);
	printf("enter the rotation angle\n");
	scanf("%f",&theta);
	rad = theta *(3.14/180);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("house rotation");
	glutInitWindowPosition(50,50);
	glutInitWindowSize(500,500);
	//glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}
