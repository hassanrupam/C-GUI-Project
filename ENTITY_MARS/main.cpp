#include<windows.h>
#include<GL/glut.h>
#include <math.h>
#include <GL/gl.h>
#include <stdio.h>
#define PI 3.1415927

GLfloat spin = 0.0;
GLfloat spin1 = 0.0;
void stars();
void extra_stars1();
void sphere_Earth();
void sphere_Mars();
void  galaxy();
void rocket();
void comet();
void display_blinking_star1();
void init()
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glOrtho(-600,600,-600,600,-600,600);

}





void resize(int width, int height) {

    glutReshapeWindow( 1000, 800);
    glutPostRedisplay();
}



void display_blinking_star1()
{

 glPushMatrix();
 glTranslatef(-550,550,0);
 glScalef(.8,.8,.8);
 glColor3f(1,1,1);

extra_stars1();

glPopMatrix();

glPushMatrix();
 glTranslatef(-450,-200,0);
glColor3f(1,.2,.2);
extra_stars1();

glPopMatrix();

glPushMatrix();
 glTranslatef(100,450,0);
 glScalef(1,1.5,1.4);
 glColor3f(.6,1,.6);
extra_stars1();

glPopMatrix();

glPushMatrix();

 glTranslatef(500,-350,0);
glScalef(.7,.7,.7);
 glColor3f(1,1,0);
extra_stars1();

glPopMatrix();


glPushMatrix();
glScalef(1.2,1.2,1.2);
 glTranslatef(000,-455,0);
 glColor3f(1,1,1);
extra_stars1();

glPopMatrix();

}



void rocket()
{

glPushMatrix();    // left side thrusters
glColor3f(1,1,1);
glTranslatef(-40,-200,0);
glRotatef(-90,1,0,0);
glutSolidCone(100,300,50,50);
glPopMatrix();

glPushMatrix();
//glColor3f(.6,.6,1);    // Right side thrusters
glTranslatef(40,-200,0);
glRotatef(-90,1,0,0);
glutSolidCone(100,300,50,50);
glPopMatrix();

glPushMatrix();    //main thruster
glColor3f(1,1,1);
glTranslatef(0,-260,0);
glRotatef(-90,1,0,0);
glutSolidCone(50,200,50,50);
glPopMatrix();

glPushMatrix();    // main Thruster first ring
glColor3f(0,0,0);
glTranslatef(0,-220,0);
glRotatef(-90,1,0,0);
glutSolidTorus(2,37,20,20);
glPopMatrix();

glPushMatrix();    // main Thruster second ring
glTranslatef(0,-240,0);
glRotatef(-90,1,0,0);
glutSolidTorus(2,43,20,20);
glPopMatrix();

glPushMatrix();
glColor3f(0.6,.6,.5);   // main body
glTranslatef(0,-200,0);
glRotatef(-90,1,0,0);
glutSolidCone(75,700,100,100);
glPopMatrix();

glPushMatrix();    // top ring
glColor3f(0,0,0);
glTranslatef(0,275,0);
glRotatef(-90,1,0,0);
glutSolidTorus(7,23,20,20);
glPopMatrix();

glPushMatrix();    // Top cone
glColor3f(1,1,1);
glTranslatef(0,275,0);
glRotatef(-90,1,0,0);
glutSolidCone(25,230,20,30);
glPopMatrix();

glPushMatrix();    //Flame
glColor3f(1,0,0);
glTranslatef(0,-260,0);
glRotatef(90,1,0,0);
glutSolidCone(37,320,50,50);
glPopMatrix();

glPushMatrix();
glColor3f(1,.6,0);
glTranslatef(0,-260,0);
glRotatef(90,1,0,0);
glutSolidCone(27,270,50,50);
glPopMatrix();

glPushMatrix();
glColor3f(1,1,0);
glTranslatef(0,-260,0);
glRotatef(90,1,0,0);
glutSolidCone(18,200,50,50);
glPopMatrix();


glPushMatrix();
glColor3f(1,.2,.2);
glTranslatef(0,-260,0);
glRotatef(90,1,0,0);
glutSolidCone(10,50,50,50);
glPopMatrix();


glPushMatrix();   // body window1
glColor3f(0,0,0);
glTranslatef(0,220,0);
glRotatef(90,1,0,0);
glutSolidSphere(7,50,50);
glPopMatrix();

glPushMatrix();    // body window ring1
glColor3f(1,1,1);
glTranslatef(0,220,0);
glutSolidTorus(2,10,20,20);
glPopMatrix();

glPushMatrix();   //body window2
glColor3f(0,0,0);
glTranslatef(0,170,0);
glRotatef(90,1,0,0);
glutSolidSphere(12,50,50);
glPopMatrix();

glPushMatrix();    // body window ring2
glColor3f(1,1,1);
glTranslatef(0,170,0);
glutSolidTorus(2,15,20,20);
glPopMatrix();


glPushMatrix();    // body window 3
glColor3f(0,0,0);
glTranslatef(0,110,0);
glRotatef(90,1,0,0);
glutSolidSphere(15,50,50);
glPopMatrix();

glPushMatrix();    // body window ring3
glColor3f(1,1,1);
glTranslatef(0,110,0);
glutSolidTorus(2,18,20,20);
glPopMatrix();

glPushMatrix();  // body window4
glColor3f(0,0,0);
glTranslatef(0,40,0);
glRotatef(90,1,0,0);
glutSolidSphere(20,50,50);
glPopMatrix();

glPushMatrix();    // body window ring3
glColor3f(1,1,1);
glTranslatef(0,40,0);
glutSolidTorus(3,22,20,20);
glPopMatrix();



}


void stars()
{


glRotatef(spin, 0.0, 0.0, 1.0);

    int i;
   glBegin(GL_POLYGON);
   glColor3f(.04,.04,.09);
   glVertex3f(-800,-800,-600);
   glVertex3f(-800,800,-600);
   glVertex3f(800,800,-600);
   glVertex3f(800,-800,-600);
   glEnd();


 glPointSize(1);
   glBegin(GL_POINTS);
   glColor3f(1,1,0);        // yellow stars
   for(i=-600;i<=600;i++)
   {

      glVertex3f(i+rand()%600,i-rand()%1000,i+rand()%600);
      glVertex3f(i-500-rand()%1000,i+10+rand()%1000,i-rand()%600);
   }
   glEnd();




 glPointSize(1.4);
   glBegin(GL_POINTS);
   glColor3f(1,1,1);                     // White stars
   for(i=-600;i<=600;i++)
   {
      glVertex3f(i+rand()%400,i+rand()%500,i+rand()%400);
      //glVertex3f(i-rand()%1000,i-rand()%100,i-rand()%1000);
      glVertex3f(i+rand()%2000,i-rand()%2000,i+rand()%2000);
      glVertex3f(i-500-rand()%500,i+10+rand()%100,i-rand()%600);
   }
   glEnd();
glPointSize(1.5);
  glBegin(GL_POINTS);
   glColor3f(.3,.3,.3);
   for(i=-1000;i<=1000;i++)
   {
      glVertex3f(i+rand()%1000,i+rand()%1000,i+rand()%600);
      //glVertex3f(i-rand()%600,i-rand()%100,i-rand()%600);

      //glVertex3f(i+rand()%1000,i-rand()%1000,i+rand()%600);
      //glVertex3f(i-500-rand()%500,i+10+rand()%100,i-rand()%600);
   }
   glEnd();



 glPointSize(1.2);

   glColor3f(.8,.4,.4);          // Red stars
    glBegin(GL_POINTS);
   for(i=-1000;i<=1000;i++)
   {
      //glVertex3f(i+rand()%600,i+rand()%500,i+rand()%600);
      glVertex3f(i-rand()%1000,i-rand()%1000,i-rand()%1000);
      //glVertex3f(i+rand()%600,i-rand()%500,i+rand()%600);
     // glVertex3f(i-500-rand()%500,i+10+rand()%100,i-rand()%600);
   }
   glEnd();
   glBegin(GL_POINTS);


 glPointSize(1);

   glColor3f(.3,.2,1);
   for(i=-600;i<=600;i++)                    // Blue stars
   {
      glVertex3f(i-rand()%1000,i-rand()%500,i-rand()%600);
     // glVertex3f(i+rand()%1000,i-rand()%1000,i+rand()%600);
     // glVertex3f(i-500-rand()%500,i+10+rand()%500,i-rand()%600);
   }
   glEnd();

   glPointSize(1);
glBegin(GL_POINTS);
   glColor3f(.5,.5,1);                    //// Blue stars

   for(i=-600;i<=600;i++)
   {
      //glVertex3f(i-rand()%1000,i-rand()%1000,i-rand()%1000);
      glVertex3f(i+rand()%1000,i-rand()%1000,i+rand()%1000);
      //glVertex3f(i-500-rand()%500,i+10+rand()%100,i-rand()%600);
   }
   glEnd();



glFlush();
}







void extra_stars1()
{



glPushMatrix();
    //glTranslatef(-350,100,0);
    glRotatef(90,1,0,0);
       glutSolidSphere(5,10,10);
       glPopMatrix();

glLineWidth(1);
       glBegin(GL_LINES);
       glVertex2f(-10,0);
       glVertex2f(10,0);
       glVertex2f(0,10);
       glVertex2f(0,-10);
       glEnd();
       glFlush();

}




void galaxy()
{

    glPushMatrix();
    glColor3f(0,1,0);
glTranslatef(-350,350,-200);
glRotatef(-65,1,0,0);
glRotatef(-25,0,1,0);
glColor3f(0,1,0);
 glutWireTorus(15,75,10,30);
     glPopMatrix();


}
void sphere_Earth()
{
    glColor3f(.3,.3,1);
    glPushMatrix();
    glTranslatef(-500,-500,0);
    glRotatef(90,1,0,0);
     glRotatef(-45,0,1,0);
    glutWireSphere( 200.0, 300.0, 100.0);
    glPopMatrix();
    glFlush();

}


void sphere_Mars()
{
    glColor3f(1,.3,.2);
    glPushMatrix();
    glTranslatef(475,410,0);
    glRotatef(90,1,0,0);
    glRotatef(45,0,1,0);
    glutWireSphere( 300.0, 400.0, 100.0);
    glPopMatrix();

}

void comet()
{


glPushMatrix();    //main tail
glColor3f(1,1,1);
glTranslatef(0,275,0);
glRotatef(90,1,0,0);
glutSolidCone(50,900,50,50);
glPopMatrix();

glPushMatrix();    //head   main
glColor3f(1,1,1);
glTranslatef(0,275,0);
glRotatef(90,1,0,0);
glutSolidSphere(50,100,100);
glPopMatrix();


glPushMatrix();   // secondary two
glColor3f(.7,.7,.7);
glTranslatef(0,275,0);
glRotatef(90,1,0,0);
glutSolidCone(25,600,50,50);
glPopMatrix();

glPushMatrix();    //head   secondary
glColor3f(.7,.7,.7);
glTranslatef(0,275,0);
glRotatef(90,1,0,0);
glutSolidSphere(25,100,100);
glPopMatrix();

glPushMatrix();   // secondary one
glColor3f(.4,.4,.4);
glTranslatef(0,275,0);
glRotatef(90,1,0,0);
glutSolidCone(20,200,50,50);
glPopMatrix();


glPushMatrix();    //head   core
glColor3f(.4,.4,.4);
glTranslatef(0,275,0);
glRotatef(90,1,0,0);
glutSolidSphere(20,100,100);
glPopMatrix();




}


void display()
{

    glClear(GL_COLOR_BUFFER_BIT);


stars();

   sphere_Earth();
   sphere_Mars();

galaxy();


    glPushMatrix();
    glTranslatef(-300,-150,0);
    glScalef(.28,.28,.28);
    glRotatef(-40,0,0,1);
    glRotatef(25,0,1,0);
    rocket();
    glPopMatrix();


    glPushMatrix();
glTranslatef(400,-400,0);
    glScalef(.4,.4,.4);
    glRotatef(45,0,0,1);
    comet();
    glPopMatrix();
display_blinking_star1();



    glFlush();


}


int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,800);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Journey To Mars");
    init();
    glutDisplayFunc(display);

    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}
