
#include <Gl/glut.h>

static GLfloat viteza = 0.0f;
static GLfloat dim = 700;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
}

//Syrup pump
void displayPump(void) 
{
	glPushMatrix();
	glTranslatef(-0.7, -0.8, 0.1);
	glRotatef(1000 * viteza, 0.0, 0.0, -1.0);
	glTranslatef(-0.1, 0.1, 0.0);

	//pump
	glBegin(GL_TRIANGLES);
	glColor3f(0.2, 0.0, 0.5); //red
	glVertex3f(0.2, -0.15, 0.0);
	glColor3f(0.2, 0.0, 0.2);
	glVertex3f(0.0, -0.15, 0.0);
	glColor3f(0.2, 0.0, 0.2);
	glVertex3f(0.1, 0.0, 0.0);
	glEnd();

	glPopMatrix();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//syrup line 1
	glColor3f(0.6, 0.6, 0.6); //light gray
	glRectf(-0.7, -0.75, -1.0, -0.80); 

	// liquid -> pump
	glPushMatrix();
	glTranslatef(0.8*viteza, 0.0, 0.0);
	glColor3f(0.6, 0.4, 0.7); //pinkish
	glRectf(-1.0, -0.80, -0.95, -0.75);
	glPopMatrix();

	//syrup line 2
	glColor3f(0.6, 0.6, 0.6); //light gray
	glRectf(-0.65, -0.8, -0.7, -0.5); //pump-HE

	//pump-HE.1
	glPushMatrix();
	glTranslatef(0.0, viteza, 0.0);
	glColor3f(0.6, 0.4, 0.7); //pinkish
	glRectf(-0.65, -0.85, -0.70, -0.80); 
	glPopMatrix();

	//heat exchanger
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0); //blue
	glVertex3f(-0.8, -0.6, 0.0);
	glColor3f(1.0, 0.0, 0.0); //red
	glVertex3f(-0.8, -0.1, 0.0);
	glColor3f(1.0, 0.5, 0.0); //orange
	glVertex3f(-0.55, -0.1, 0.0);
	glColor3f(1.0, 1.0, 0.0); //yellow
	glVertex3f(-0.55, -0.6, 0.0);
	glEnd();

	//heat ex - out
	glColor3f(0.6, 0.6, 0.6); //light gray
	glRectf(-0.55, -0.5, -0.4, -0.45);

	//heat ex - out
	glPushMatrix();
	glTranslatef(0.3* viteza, 0.0, 0.0);
	glColor3f(0.25, 0.25, 0.25); //dark gray
	glRectf(-0.55, -0.5, -0.50, -0.45);
	glPopMatrix();

	//steam supply-HE.1
	glColor3f(0.6, 0.6, 0.6); //light gray
	glRectf(-0.72, -0.1, -0.77, 0.98);

	//steam-HE
	glPushMatrix();
	glTranslatef(0.0, -3* viteza, 0.0);
	glColor3f(0.25, 0.25, 0.25); //dark gray
	glRectf(-0.72, 0.92, -0.77, 0.98);
	glPopMatrix();

	//HE-evaporator
	glColor3f(0.6, 0.6, 0.6); //light gray
	glRectf(-0.3, -0.15, -0.55, -0.2);

	//HE-evaporator
	glPushMatrix();
	glTranslatef(0.6* viteza, 0.0, 0.0);
	glColor3f(0.8, 0.4, 0.4); //pinkish
	glRectf(-0.5, -0.15, -0.55, -0.2);
	glPopMatrix();

	//evaporator
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.0, 0.2); //purplish
	glVertex3f(-0.3, -0.25, 0.0);
	glColor3f(0.0, 0.0, 1.0); //blue (water)
	glVertex3f(-0.3, 0.6, 0.0);
	glColor3f(0.0, 0.0, 1.0); //blue (water)
	glVertex3f(-0.1, 0.6, 0.0);
	glColor3f(0.2, 0.0, 0.2); //purplish
	glVertex3f(-0.1, -0.25, 0.0);
	glEnd();

	//evap-compressor
	glColor3f(0.6, 0.6, 0.6); //light gray
	glRectf(-0.1, 0.55, 0.3, 0.6);

	//evap-compressor
	glPushMatrix();
	glTranslatef(0.95* viteza, 0.0, 0.0);
	glColor3f(0.25, 0.25, 0.25); //dark gray
	glRectf(-0.1, 0.55, -0.05, 0.6);
	glPopMatrix();

	//compressor patrat
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.3, 0.0); //green
	glVertex3f(0.3, 0.6, 0.0);
	glColor3f(0.0, 0.3, 0.0);
	glVertex3f(0.3, 0.3, 0.0);
	glColor3f(0.0, 0.3, 0.0);
	glVertex3f(0.6, 0.3, 0.0);
	glColor3f(0.0, 0.3, 0.0); 
	glVertex3f(0.6, 0.6, 0.0);
	glEnd();

	//water vapor - out
	glColor3f(0.6, 0.6, 0.6); //light gray
	glRectf(0.55, 0.3, 0.6, 0.2);

	//water vapor - out
	glPushMatrix();
	glTranslatef(0.0, 0.2*-viteza, 0.0);
	glColor3f(0.25, 0.25, 0.25); //dark gray
	glRectf(0.55, 0.3, 0.6, 0.25);
	glPopMatrix();

	//evap-final
	glColor3f(0.6, 0.6, 0.6); //light gray
	glRectf(-0.1, -0.25, 0.2, -0.20);

	//evap-final
	glPushMatrix();
	glTranslatef(0.80 * viteza, 0.0, 0.0);
	glColor3f(0.2, 0.0, 0.2); //purplish
	glRectf(-0.1, -0.25, -0.05, -0.20);
	glPopMatrix();

	//robinet
	glColor3f(0.0, 1.0, 0.0); //white
	glRectf(0.3, -0.18, 0.15, -0.15);
	glColor3f(1.0, 1.0, 1.0); //white
	glRectf(0.2, -0.18, 0.25, -0.23);
	glColor3f(1.0, 1.0, 1.0); //white
	glRectf(0.3, -0.20, 0.15, -0.25);
	glColor3f(1.0, 1.0, 1.0); //white
	glRectf(0.3, -0.25, 0.25, -0.30);

	//sirop final
	glPushMatrix();
	glTranslatef(0.0, -viteza, 0.0);
	glColor3f(0.6, 0.4, 0.7); //pinkish
	glRectf(0.3, -0.25, 0.25, -0.30); 
	glPopMatrix();

	displayPump(); 
	glutReshapeWindow(dim, dim); 
	glutSwapBuffers();
	
	glFlush();
}

void move(void) 
{
	if (viteza < 0.35) 
	{
		viteza += 0.005f; 
	}
	if (viteza >= 0.35) 
	{ 
		viteza = 0.0f; 
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	switch (button) 
	{ 
	case GLUT_LEFT_BUTTON: 
		if (state == GLUT_DOWN)
		{ 
			glutIdleFunc(move); 
		}
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(dim, dim);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Syrup installation");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}