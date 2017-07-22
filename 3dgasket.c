#include<GL/glut.h>
#include<stdio.h>

GLfloat v[4][3]={{0,1,-1},{-1,-1,-1},{1,-1,-1},{0,0,1}};
int n;	

void triangle(GLfloat *a,GLfloat *b,GLfloat *c)
{
	//glBegin(GL_TRIANGLE);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	//glEnd();
}

void tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d)
{
	glColor3f(0,0,0);
	triangle(a,b,c);
	glColor3f(1,0,0);
	triangle(a,b,d);
	glColor3f(0,1,0);
	triangle(b,c,d);
	glColor3f(0,0,1);
	triangle(a,c,d);
}

void divide_tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d,int m)
{
	int j;
	float mid[6][3];
	
	if(m>0)
	{
		for(j=0;j<3;j++)
		{
			mid[0][j] = (a[j] + b[j])/2;
			mid[1][j] = (b[j] + c[j])/2;
			mid[2][j] = (a[j] + c[j])/2;
			mid[3][j] = (a[j] + d[j])/2;
			mid[4][j] = (b[j] + d[j])/2;
			mid[5][j] = (c[j] + d[j])/2;
		}
		
		divide_tetra(a,mid[0],mid[2],mid[3],m-1);
		divide_tetra(b,mid[0],mid[4],mid[1],m-1);
		divide_tetra(c,mid[2],mid[1],mid[5],m-1);
		divide_tetra(d,mid[3],mid[4],mid[5],m-1);
	}
	
	else
	{
		tetra(a,b,c,d);
	}
}

void myinit()
{
	glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1,1,-1,1,-1,1);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glBegin(GL_TRIANGLES);
	divide_tetra(v[0],v[1],v[2],v[3],n);
	glEnd();
	glFlush();
}

int main( int argc, char **argv)
{
	glutInit(&argc,argv);
	printf("enter the no.of recursions\n");
	scanf("%d",&n);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutCreateWindow("3d gasket");
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1000,1000);
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}
	
		

	
