#include <iostream>
#include<GL/gl.h>
#include <windows.h>
#include<cstdio>
#include <GL/glut.h>
#include<math.h>>
# define PI           3.14159265358979323846

using namespace std;

GLfloat position = 0.0f;
GLfloat position2 = 0.0f;
GLfloat speed = 0.02f;
GLfloat z = 0.0f;
float _move = 0.0f;
void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}
void update(int value) {

    _move += .02;
    if(_move-1.3 > 1.0)
    {
        _move = -1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(100, update, 0); //Notify GLUT to call update again in 20 milliseconds
}
void update2(int value) {


if(position2 > 1.0)
        position2 = -1.0f;
position2 += speed;
	glutPostRedisplay();
		glutTimerFunc(100, update2, 0);
}
void update3(int value) {
    if(position <- 1.0)
        position =  1.0f;

    position = position - speed;
    glutPostRedisplay();
    glutTimerFunc(100, update3, 0);
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'd':
    speed = 0.0f;
    break;
case 'p':
    speed = 0.1f;
    break;
case 'b': //night view
    glClearColor(0.0,0.0,0.0,0.0);
    glutPostRedisplay();
break;
case 'n': //day view
    glClearColor(0.79,0.97,0.99,0.0);
    glutPostRedisplay();
break;

	}
	//glutPostRedisplay();
}
void initGL() {
	// Set "clearing" or background color
	glClearColor(0.79,0.97,0.99,0.0);

}


void drawScene() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(0.0,0.0,0.9);
	glLoadIdentity(); //Reset the drawing perspective
	//glMatrixMode(GL_MODELVIEW);
    glBegin(GL_QUADS);//3rd
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
        glVertex3f(1.0f, 0.1f, 0.0f);
        glVertex3f(-1.0f, 0.1f, 0.0f);
	glEnd();

	glPushMatrix();
        glColor3f(1.0f,0.0f,0.0f); //sun
         glTranslatef(-.85,.85,0);
        glutSolidSphere(0.1,50,50);
    glPopMatrix();


	glColor3d(0.3,0,0);
    glPushMatrix();
	glTranslatef(position2, 0.0f, 0.0f);
    glBegin(GL_QUADS); // black boat
        glVertex3f(-.85f, 0.0f, 0.0f);
        glVertex3f(-.45f, 0.0f, 0.0f);
        glVertex3f(-.30f, 0.3f, 0.0f);
        glVertex3f(-1.0f, 0.3f, 0.0f);
        glVertex3f(-.85f, 0.0f, 0.0f);
        glVertex3f(-.45f, 0.0f, 0.0f);
        glVertex3f(0.3f, 0.2f, 0.0f);
        glVertex3f(-1.5f, 0.2f, 0.0f);
	glEnd();
	glColor3d(0.1,0.0,0.0);
	glBegin(GL_QUADS); //1st
        glVertex3f(-.9f, 0.3f, 0.0f);
        glVertex3f(-.8f, 0.3f, 0.0f);
        glVertex3f(-.8f, 0.6f, 0.0f);
        glVertex3f(-.9f, 0.6f, 0.0f);
	glEnd();
	glBegin(GL_QUADS);//2nd
        glVertex3f(-.7f, 0.3f, 0.0f);
        glVertex3f(-.6f, 0.3f, 0.0f);
        glVertex3f(-.6f, 0.7f, 0.0f);
        glVertex3f(-.7f, 0.7f, 0.0f);
	glEnd();
	glBegin(GL_QUADS);//3rd
        glVertex3f(-.5f, 0.3f, 0.0f);
        glVertex3f(-.4f, 0.3f, 0.0f);
        glVertex3f(-.4f, 0.6f, 0.0f);
        glVertex3f(-.5f, 0.6f, 0.0f);
	glEnd();
	glPopMatrix();
	glPushMatrix();
        glColor3f(0.76,0.76,0.76);
        glTranslatef(-.9+_move,.65,0);
        glutSolidSphere(0.02,50,50);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-.94+_move,.75,0);
        glutSolidSphere(0.03,50,50);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-.99+_move,.85,0);
        glutSolidSphere(0.04,50,50);
    glPopMatrix();
    glPushMatrix();//2nd
         glTranslatef(-.79+_move,.88,0);
        glutSolidSphere(0.04,50,50);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-.73+_move,.82,0);
        glutSolidSphere(0.03,50,50);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-.7+_move,.75,0);
        glutSolidSphere(0.02,50,50);
    glPopMatrix();
    glPushMatrix();//3rd
         glTranslatef(-.5+_move,.85,0);
        glutSolidSphere(0.04,50,50);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-.48+_move,.75,0);
        glutSolidSphere(0.03,50,50);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-.45+_move,.65,0);
        glutSolidSphere(0.02,50,50);
    glPopMatrix();
glEnd();

    glColor3f(0.0f,0.0f,1.0f);
	GLfloat x=0.6f;
	GLfloat y=0.8f;
	GLfloat radius =.1f;
	int i;
	int lineAmount = 100;
    GLfloat twicePi = 2.0f * PI;

    glEnable(GL_LIGHTING);//Enable Light Effect

   GLfloat global_ambient[] = {5.0,5.3,5.0,0};//ambient RGBA intensity of light
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//A lighting model parameter.
   glPushMatrix();
  // glColor3f(0.0f, 0.0f, 1.0f);
   glTranslatef(position,0.0f, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
		for(i = 0 ; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}

	glEnd();
	glPopMatrix();
	glPushMatrix();
	//glColor3f(0.0f, 0.0f, 1.0f);
	//glEnable(GL_LIGHTING);//Enable Light Effect
    //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//A lighting model parameter.
	glTranslatef(position,0.0f, 0.0f);
    glBegin(GL_POLYGON);
   // glColor3f(0.0f, 0.0f, 1.0f);
    float theta5;
    for (int i=0;i<360;i++)
    {
        theta5=i*3.1416/180;
        glVertex2f(0.7+0.1*cos(theta5),0.8+0.1*sin(theta5));
    }
    glEnd();
    glPopMatrix();
    glDisable(GL_LIGHTING);

	//glFlush();        //Works only on single buffer
	glutSwapBuffers();
}
void sound()
{

    PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Moving ship");
	glutDisplayFunc(drawScene);
	initGL() ;
	glutTimerFunc(20, update, 0); //Add a timer
	glutTimerFunc(100, update2, 0);
	glutTimerFunc(100, update3, 0);
    glutKeyboardFunc(handleKeypress);
	//glutMainLoop();
	sound();
   glutMainLoop();
	return 0;
}
