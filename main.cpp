#include <GL/glut.h>

#include<math.h>

#include<string.h>

#include<stdlib.h>

struct philosophers {
  int state;
};
static int flag = 1;
struct philosophers p1 = {
  0
};
struct philosophers p2 = {
  0
};
struct philosophers p3 = {
  0
};
struct philosophers p4 = {
  0
};
struct philosophers p5 = {
  0
};
void topview();
void chop1();
void chop2();
void chop3();
void chop4();
void chop5();

float tx, ty, tz;
int to, tooo;
int tchop1;

void Write(double x, double y, double z, double scale, char * s) {
  int i, l = strlen(s);

  glRasterPos3f(x, y, z);
  for (i = 0; i < l; i++) {
    glColor3f(0.0, 0.0, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
  }
  glPopMatrix();
}

void keyboard(unsigned char key, int x, int y) {
  if (flag == 1) {
    if (key == 'c') {
      flag = 2;
      glutPostRedisplay();
    }
  } else if (flag == 2) {
    switch (key) {
    case '1':
      flag = 3;
      glutPostRedisplay();
      break;
    case '2':
      flag = 4;
      glutPostRedisplay();
      break;
    case '3':
      exit(0);
    case 'b':
      flag -= 1;
      glutPostRedisplay();
      break;
    case 'e':
      exit(0);
    }
  } else if (flag == 3) {
    switch (key) {
    case 'b':
      flag = 2;
      glutPostRedisplay();
      break;

    case 27:
      exit(0);
    }
  } else if (flag == 4) {
    switch (key) {
    case 'b':
      flag = 2;
      glutPostRedisplay();
      break;
    case 'p':
      flag = 6;
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 440, 0.0, 0.4, "-->PHILOSOPHER 1 PICKS Rc");
      glPushMatrix();
      glTranslatef(30, 10, 0);
      chop1();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 1
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(175, 330);
      glVertex2i(195, 310);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(1000);
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 340, 0.0, 0.4, "-->PHILOSOPHER 2 PICKS Rc");
      // 2nd chop
      //
      //
      glPushMatrix();
      glTranslatef(0, 50, 0);
      chop2();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 2
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(151, 215);
      glVertex2i(178, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(1000);
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 240, 0.0, 0.4, "-->PHILOSOPHER 3 PICKS Rc");

      // 3rd chop
      //
      //
      glPushMatrix();
      glTranslatef(-35, 20, 0);
      chop3();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 3
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(220, 180);
      glVertex2i(225, 145);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(1000);
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 140, 0.0, 0.4, "-->PHILOSOPHER 4 PICKS Rc");

      // 4th chop
      //
      //
      glPushMatrix();
      glTranslatef(-10, -35, 0);
      chop4();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 4
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(265, 225);
      glVertex2i(290, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(1000);

      // 5th chop
      //
      //
      glPushMatrix();
      glTranslatef(10, -38, 0);
      chop5();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 5
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(250, 315);
      glVertex2i(277, 320);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 40, 0.0, 0.4, "-->PHILOSOPHER 5 PICKS Rc");
      glLineWidth(3.0);
      glColor3f(1.0, 0.8, 0.5);
      Write(485, 20, 0.0, 0.4, "   DEAD LOCK OCCORS !!!");
      glFlush();
      //glutPostRedisplay();
      break;
    case 'P':
      flag = 6;
      glPushMatrix();
      glTranslatef(30, 10, 0);
      chop1();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 1
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(175, 330);
      glVertex2i(195, 310);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(1000);
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 340, 0.0, 0.4, "-->PHILOSOPHER 2 PICKS Rc");
      // 2nd chop
      //
      //
      glPushMatrix();
      glTranslatef(0, 50, 0);
      chop2();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 2
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(151, 215);
      glVertex2i(178, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(1000);
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 240, 0.0, 0.4, "-->PHILOSOPHER 3 PICKS Rc");

      // 3rd chop
      //
      //
      glPushMatrix();
      glTranslatef(-35, 20, 0);
      chop3();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 3
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(220, 180);
      glVertex2i(225, 145);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(1000);
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 140, 0.0, 0.4, "-->PHILOSOPHER 4 PICKS Rc");

      // 4th chop
      //
      //
      glPushMatrix();
      glTranslatef(-10, -35, 0);
      chop4();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 4
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(265, 225);
      glVertex2i(290, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(1000);

      // 5th chop
      //
      //
      glPushMatrix();
      glTranslatef(10, -38, 0);
      chop5();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 5
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(250, 315);
      glVertex2i(277, 320);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 40, 0.0, 0.4, "-->PHILOSOPHER 5 PICKS Rc");
      glLineWidth(3.0);
      glColor3f(1.0, 0.8, 0.5);
      Write(485, 20, 0.0, 0.4, "   DEAD LOCK OCCORS !!!");
      glFlush();
      //glutPostRedisplay();
      break;
    case 'S':
      flag = 6;
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(490, 455, 0.0, 0.6, " PHILOSOPHER 1 EATING");

      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 440, 0.0, 0.4, "-->PHILOSOPHER 1 PICKS Rc");
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 430, 0.0, 0.4, "-->PHILOSOPHER 1 PICKS Lc");
      glPushMatrix();
      glTranslatef(30, 10, 0);
      chop1();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 1
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(175, 330);
      glVertex2i(195, 310);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(300);

      glPushMatrix();
      glTranslatef(-40, 18, 0);
      chop5();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 5
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(250, 315);
      glVertex2i(277, 320);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(500);

      glPushMatrix();
      glTranslatef(0, 50, 0);
      chop2();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 2
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(151, 215);
      glVertex2i(178, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(500);

      // 3rd chop
      //
      //
      glPushMatrix();
      glTranslatef(-35, 20, 0);
      chop3();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 3
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(220, 180);
      glVertex2i(225, 145);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(500);

      // 4th chop
      //
      //
      glPushMatrix();
      glTranslatef(-10, -35, 0);
      chop4();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 4
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(265, 225);
      glVertex2i(290, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      //--------------------------------------------//
      //--------------------------------------------//
      //--------------------------------------------//
      //redraw1.3
      Sleep(3000);
      glBegin(GL_POLYGON); //plate 1
      glColor3f(1.0, 1.0, 0.80);
      for (to = 0; to <= 360; to++) {
        tx = 14 * sin(to);
        ty = 16 * cos(to);
        tz = 0;
        glVertex3f(222 + tx, 338 + ty, tz);
      }
      glEnd();

      //redraw 1
      glPushMatrix();
      glTranslatef(195, 780, 0);
      glRotatef(-150.0, 0, 0, 1.0);
      glBegin(GL_POLYGON); //

      glColor3f(1, 1, 0);
      for (to = 0; to <= 360; to++) {
        tx = 4 * sin(to);
        ty = 16 * cos(to);
        tz = 0;
        glVertex3f(210 + tx, 380 + ty, tz);
      }
      glEnd();
      glPopMatrix();

      //redraw 1.1

      glPushMatrix();
      glTranslatef(-165, 192, 0);
      glRotatef(-40.0, 0, 0, 1.0);
      glBegin(GL_POLYGON); // Phil body 1

      glColor3f(1, 1, 0);
      for (to = 0; to <= 360; to++) {
        tx = 4 * sin(to);
        ty = 15 * cos(to);
        tz = 0;
        glVertex3f(210 + tx, 380 + ty, tz);
      }
      glEnd();
      glPopMatrix();

      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(490, 365, 0.0, 0.6, "PHILOSOPHER 2 EATING");

      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 340, 0.0, 0.4, "-->PHILOSOPHER 2 PICKS Rc");
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 325, 0.0, 0.4, "-->PHILOSOPHER 2 PICKS Lc");
      p2.state = '1';
      glPushMatrix();
      glTranslatef(0, 50, 0);
      chop2();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 2
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(151, 215);
      glVertex2i(178, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      // 3rd chop
      //
      //
      glPushMatrix();
      glTranslatef(-35, 20, 0);
      chop3();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 3
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(220, 180);
      glVertex2i(225, 145);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      // 4th chop
      //
      //
      glPushMatrix();
      glTranslatef(-10, -35, 0);
      chop4();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 4
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(265, 225);
      glVertex2i(290, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      // 5th chop
      //
      //
      glPushMatrix();
      glTranslatef(10, -38, 0);
      chop5();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 5
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(250, 315);
      glVertex2i(277, 320);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      chop1();
      glFlush();
      //____________________________________________//
      //--------------------------------------------//
      glPushMatrix();
      glTranslatef(-11, -40, 0);
      chop1();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 1
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(175, 330);
      glVertex2i(195, 310);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(3000);
      //--------------------------------------------//
      //--------------------------------------------//
      //redraw2.3

      glBegin(GL_POLYGON); //plate 2
      glColor3f(1.0, 1.0, 0.80);
      for (to = 0; to <= 360; to++) {
        tx = 14 * sin(to);
        ty = 16 * cos(to);
        tz = 0;
        glVertex3f(170 + tx, 270 + ty, tz);
      }
      glEnd();
      //redraw2.1
      glPushMatrix();
      glTranslatef(232, 725, 0);
      glRotatef(-160.0, 0, 0, 1.0);
      glBegin(GL_POLYGON); //

      glColor3f(1, 1, 0);
      for (to = 0; to <= 360; to++) {
        tx = 4 * sin(to);
        ty = 16 * cos(to);
        tz = 0;
        glVertex3f(210 + tx, 380 + ty, tz);
      }
      glEnd();
      glPopMatrix();

      //redraw2.2
      glPushMatrix();
      glTranslatef(-252, 102, 0);
      glRotatef(-40.0, 0, 0, 1.0);
      glBegin(GL_POLYGON); // Phil body 1

      glColor3f(1, 1, 0);
      for (to = 0; to <= 360; to++) {
        tx = 4 * sin(to);
        ty = 15 * cos(to);
        tz = 0;
        glVertex3f(210 + tx, 380 + ty, tz);
      }
      glEnd();
      glPopMatrix();
      glFlush();
      chop1();
      glFlush();

      //---------------------------------------
      //----------------3rd----------------------
      //--------------------------------------
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(490, 265, 0.0, 0.6, "PHILOSOPHER 3 EATING");

      glLineWidth(3.0);
      glColor3f(1.0, 0.0, 1.0);
      Write(485, 240, 0.0, 0.4, "-->PHILOSOPHER 3 PICKS Rc");
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 225, 0.0, 0.4, "-->PHILOSOPHER 3 PICKS Lc");
      p3.state = '1';
      glPushMatrix();
      glTranslatef(8, -30, 0);
      chop2();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 2
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(151, 215);
      glVertex2i(178, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      // 3rd chop
      //
      //
      glPushMatrix();
      glTranslatef(-35, 20, 0);
      chop3();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 3
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(220, 180);
      glVertex2i(225, 145);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      // 4th chop
      //
      //
      glPushMatrix();
      glTranslatef(-10, -35, 0);
      chop4();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 4
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(265, 225);
      glVertex2i(290, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      // 5th chop
      //
      //
      glPushMatrix();
      glTranslatef(10, -38, 0);
      chop5();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 5
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(250, 315);
      glVertex2i(277, 320);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      Sleep(3000);

      //redraw3.3

      glBegin(GL_POLYGON); //plate 3
      glColor3f(1.0, 1.0, 0.80);
      for (to = 0; to <= 360; to++) {
        tx = 14 * sin(to);
        ty = 16 * cos(to);
        tz = 0;
        glVertex3f(180 + tx, 190 + ty, tz);
      }
      glEnd();

      //redraw3.1
      glPushMatrix();
      glTranslatef(-213, 398, 0);
      glRotatef(-90.0, 0, 0, 1.0);
      glBegin(GL_POLYGON); // Phil body 1

      glColor3f(1, 1, 0);
      for (to = 0; to <= 360; to++) {
        tx = 4 * sin(to);
        ty = 13 * cos(to);
        tz = 0;
        glVertex3f(210 + tx, 380 + ty, tz);
      }
      glEnd();
      glPopMatrix();

      //redraw3.2

      glPushMatrix();
      glTranslatef(332, 576, 0);
      glRotatef(-170.0, 0, 0, 1.0);
      glBegin(GL_POLYGON); // Phil body 1

      glColor3f(1, 1, 0);
      for (to = 0; to <= 360; to++) {
        tx = 4 * sin(to);
        ty = 16 * cos(to);
        tz = 0;
        glVertex3f(210 + tx, 380 + ty, tz);
      }
      glEnd();
      glPopMatrix();

      chop2();
      glFlush();

      //---------------------------------------
      //----------------4th----------------------
      //--------------------------------------

      // 3rd chop
      //
      //
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(490, 165, 0.0, 0.6, "PHILOSOPHER 4 EATING");

      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 140, 0.0, 0.4, "-->PHILOSOPHER 4 PICKS Rc");
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 125, 0.0, 0.4, "-->PHILOSOPHER 4 PICKS Lc");
      p4.state = '1';
      glPushMatrix();
      glTranslatef(30, 18, 0);
      chop3();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 3
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(220, 180);
      glVertex2i(225, 145);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      // 4th chop
      //
      //
      glPushMatrix();
      glTranslatef(-10, -35, 0);
      chop4();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 4
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(265, 225);
      glVertex2i(290, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      // 5th chop
      //
      //
      glPushMatrix();
      glTranslatef(10, -38, 0);
      chop5();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 5
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(250, 315);
      glVertex2i(277, 320);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      Sleep(3000);
      chop3();
      glFlush();

      //redraw4.3(plate)
      glBegin(GL_POLYGON); //plate 4
      glColor3f(1.0, 1.0, 0.80);
      for (to = 0; to <= 360; to++) {
        tx = 14 * sin(to);
        ty = 16 * cos(to);
        tz = 0;
        glVertex3f(260 + tx, 185 + ty, tz);
      }
      glEnd();

      //redraw4.1
      glPushMatrix();
      glTranslatef(-70, -110, 0);
      glRotatef(-20.0, 0, 0, 1.0);
      glBegin(GL_POLYGON); // Phil body 1

      glColor3f(1, 1, 0);
      for (to = 0; to <= 360; to++) {
        tx = 4 * sin(to);
        ty = 15 * cos(to);
        tz = 0;
        glVertex3f(210 + tx, 380 + ty, tz);
      }
      glEnd();
      glPopMatrix();

      //redraw4.2
      glPushMatrix();
      glTranslatef(-105, 402, 0);
      glRotatef(-90.0, 0, 0, 1.0);
      glBegin(GL_POLYGON); // Phil body 1

      glColor3f(1, 1, 0);
      for (to = 0; to <= 360; to++) {
        tx = 4 * sin(to);
        ty = 13 * cos(to);
        tz = 0;
        glVertex3f(210 + tx, 380 + ty, tz);
      }
      glEnd();
      glPopMatrix();
      glFlush();

      //----------------------
      //===========5th==========//

      // 4th chop
      //
      //
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(490, 65, 0.0, 0.6, "PHILOSOPHER 5 EATING");
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 40, 0.0, 0.4, "-->PHILOSOPHER 5 PICKS Rc");
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 28, 0.0, 0.4, "-->PHILOSOPHER 5 PICKS Lc");
      p5.state = '1';
      glPushMatrix();
      glTranslatef(-5, 40, 0);
      chop4();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 4
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(265, 225);
      glVertex2i(290, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glLineWidth(3.0);
      glColor3f(0.0, 1.0, 1.0);
      Write(485, 18, 0.0, 0.4, "   Problem solved !!!");
      glFlush();
      Sleep(3000);
      glutPostRedisplay();

      //glutPostRedisplay();
      break;
    case 's':
      flag = 6;
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(490, 455, 0.0, 0.6, " PHILOSOPHER 1 EATING");

      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 440, 0.0, 0.4, "-->PHILOSOPHER 1 PICKS Rc");
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 425, 0.0, 0.4, "-->PHILOSOPHER 1 PICKS Lc");
      glPushMatrix();
      glTranslatef(30, 10, 0);
      chop1();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 1
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(175, 330);
      glVertex2i(195, 310);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(300);

      glPushMatrix();
      glTranslatef(-40, 18, 0);
      chop5();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 5
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(250, 315);
      glVertex2i(277, 320);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(500);

      glPushMatrix();
      glTranslatef(0, 50, 0);
      chop2();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 2
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(151, 215);
      glVertex2i(178, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(500);

      // 3rd chop
      //
      //
      glPushMatrix();
      glTranslatef(-35, 20, 0);
      chop3();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 3
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(220, 180);
      glVertex2i(225, 145);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(500);

      // 4th chop
      //
      //
      glPushMatrix();
      glTranslatef(-10, -35, 0);
      chop4();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 4
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(265, 225);
      glVertex2i(290, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      //--------------------------------------------//
      //--------------------------------------------//
      //--------------------------------------------//
      //redraw1.3
      Sleep(3000);
      glBegin(GL_POLYGON); //plate 1
      glColor3f(1.0, 1.0, 0.80);
      for (to = 0; to <= 360; to++) {
        tx = 14 * sin(to);
        ty = 16 * cos(to);
        tz = 0;
        glVertex3f(222 + tx, 338 + ty, tz);
      }
      glEnd();

      //redraw 1
      glPushMatrix();
      glTranslatef(195, 780, 0);
      glRotatef(-150.0, 0, 0, 1.0);
      glBegin(GL_POLYGON); //

      glColor3f(1, 1, 0);
      for (to = 0; to <= 360; to++) {
        tx = 4 * sin(to);
        ty = 16 * cos(to);
        tz = 0;
        glVertex3f(210 + tx, 380 + ty, tz);
      }
      glEnd();
      glPopMatrix();

      //redraw 1.1

      glPushMatrix();
      glTranslatef(-165, 192, 0);
      glRotatef(-40.0, 0, 0, 1.0);
      glBegin(GL_POLYGON); // Phil body 1

      glColor3f(1, 1, 0);
      for (to = 0; to <= 360; to++) {
        tx = 4 * sin(to);
        ty = 15 * cos(to);
        tz = 0;
        glVertex3f(210 + tx, 380 + ty, tz);
      }
      glEnd();
      glPopMatrix();

      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(490, 365, 0.0, 0.6, "PHILOSOPHER 2 EATING");

      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 340, 0.0, 0.4, "-->PHILOSOPHER 2 PICKS Rc");
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 325, 0.0, 0.4, "-->PHILOSOPHER 2 PICKS Lc");
      p2.state = '1';
      glPushMatrix();
      glTranslatef(0, 50, 0);
      chop2();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 2
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(151, 215);
      glVertex2i(178, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      // 3rd chop
      //
      //
      glPushMatrix();
      glTranslatef(-35, 20, 0);
      chop3();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 3
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(220, 180);
      glVertex2i(225, 145);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      // 4th chop
      //
      //
      glPushMatrix();
      glTranslatef(-10, -35, 0);
      chop4();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 4
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(265, 225);
      glVertex2i(290, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      // 5th chop
      //
      //
      glPushMatrix();
      glTranslatef(10, -38, 0);
      chop5();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 5
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(250, 315);
      glVertex2i(277, 320);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      chop1();
      glFlush();
      //____________________________________________//
      //--------------------------------------------//
      glPushMatrix();
      glTranslatef(-11, -40, 0);
      chop1();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 1
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(175, 330);
      glVertex2i(195, 310);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(3000);
      //--------------------------------------------//
      //--------------------------------------------//
      //redraw2.3

      glBegin(GL_POLYGON); //plate 2
      glColor3f(1.0, 1.0, 0.80);
      for (to = 0; to <= 360; to++) {
        tx = 14 * sin(to);
        ty = 16 * cos(to);
        tz = 0;
        glVertex3f(170 + tx, 270 + ty, tz);
      }
      glEnd();
      //redraw2.1
      glPushMatrix();
      glTranslatef(232, 725, 0);
      glRotatef(-160.0, 0, 0, 1.0);
      glBegin(GL_POLYGON); //

      glColor3f(1, 1, 0);
      for (to = 0; to <= 360; to++) {
        tx = 4 * sin(to);
        ty = 16 * cos(to);
        tz = 0;
        glVertex3f(210 + tx, 380 + ty, tz);
      }
      glEnd();
      glPopMatrix();

      //redraw2.2
      glPushMatrix();
      glTranslatef(-252, 102, 0);
      glRotatef(-40.0, 0, 0, 1.0);
      glBegin(GL_POLYGON); // Phil body 1

      glColor3f(1, 1, 0);
      for (to = 0; to <= 360; to++) {
        tx = 4 * sin(to);
        ty = 15 * cos(to);
        tz = 0;
        glVertex3f(210 + tx, 380 + ty, tz);
      }
      glEnd();
      glPopMatrix();
      glFlush();
      chop1();
      glFlush();

      //---------------------------------------
      //----------------3rd----------------------
      //--------------------------------------
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(490, 265, 0.0, 0.6, "PHILOSOPHER 3 EATING");

      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 240, 0.0, 0.4, "-->PHILOSOPHER 3 PICKS Rc");
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 225, 0.0, 0.4, "-->PHILOSOPHER 3 PICKS Lc");
      p3.state = '1';
      glPushMatrix();
      glTranslatef(8, -30, 0);
      chop2();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 2
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(151, 215);
      glVertex2i(178, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      // 3rd chop
      //
      //
      glPushMatrix();
      glTranslatef(-35, 20, 0);
      chop3();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 3
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(220, 180);
      glVertex2i(225, 145);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      // 4th chop
      //
      //
      glPushMatrix();
      glTranslatef(-10, -35, 0);
      chop4();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 4
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(265, 225);
      glVertex2i(290, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      // 5th chop
      //
      //
      glPushMatrix();
      glTranslatef(10, -38, 0);
      chop5();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 5
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(250, 315);
      glVertex2i(277, 320);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      Sleep(3000);

      //redraw3.3

      glBegin(GL_POLYGON); //plate 3
      glColor3f(1.0, 1.0, 0.80);
      for (to = 0; to <= 360; to++) {
        tx = 14 * sin(to);
        ty = 16 * cos(to);
        tz = 0;
        glVertex3f(180 + tx, 190 + ty, tz);
      }
      glEnd();

      //redraw3.1
      glPushMatrix();
      glTranslatef(-213, 398, 0);
      glRotatef(-90.0, 0, 0, 1.0);
      glBegin(GL_POLYGON); // Phil body 1

      glColor3f(1, 1, 0);
      for (to = 0; to <= 360; to++) {
        tx = 4 * sin(to);
        ty = 13 * cos(to);
        tz = 0;
        glVertex3f(210 + tx, 380 + ty, tz);
      }
      glEnd();
      glPopMatrix();

      //redraw3.2

      glPushMatrix();
      glTranslatef(332, 576, 0);
      glRotatef(-170.0, 0, 0, 1.0);
      glBegin(GL_POLYGON); // Phil body 1

      glColor3f(1, 1, 0);
      for (to = 0; to <= 360; to++) {
        tx = 4 * sin(to);
        ty = 16 * cos(to);
        tz = 0;
        glVertex3f(210 + tx, 380 + ty, tz);
      }
      glEnd();
      glPopMatrix();

      chop2();
      glFlush();

      //---------------------------------------
      //----------------4th----------------------
      //--------------------------------------

      // 3rd chop
      //
      //
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(490, 165, 0.0, 0.6, "PHILOSOPHER 4 EATING");

      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 140, 0.0, 0.4, "-->PHILOSOPHER 4 PICKS Rc");
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 125, 0.0, 0.4, "-->PHILOSOPHER 4 PICKS Lc");
      p4.state = '1';
      glPushMatrix();
      glTranslatef(30, 18, 0);
      chop3();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 3
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(220, 180);
      glVertex2i(225, 145);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      // 4th chop
      //
      //
      glPushMatrix();
      glTranslatef(-10, -35, 0);
      chop4();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 4
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(265, 225);
      glVertex2i(290, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      // 5th chop
      //
      //
      glPushMatrix();
      glTranslatef(10, -38, 0);
      chop5();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 5
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(250, 315);
      glVertex2i(277, 320);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();

      Sleep(3000);
      chop3();
      glFlush();

      //redraw4.3(plate)
      glBegin(GL_POLYGON); //plate 4
      glColor3f(1.0, 1.0, 0.80);
      for (to = 0; to <= 360; to++) {
        tx = 14 * sin(to);
        ty = 16 * cos(to);
        tz = 0;
        glVertex3f(260 + tx, 185 + ty, tz);
      }
      glEnd();

      //redraw4.1
      glPushMatrix();
      glTranslatef(-70, -110, 0);
      glRotatef(-20.0, 0, 0, 1.0);
      glBegin(GL_POLYGON); // Phil body 1

      glColor3f(1, 1, 0);
      for (to = 0; to <= 360; to++) {
        tx = 4 * sin(to);
        ty = 15 * cos(to);
        tz = 0;
        glVertex3f(210 + tx, 380 + ty, tz);
      }
      glEnd();
      glPopMatrix();

      //redraw4.2
      glPushMatrix();
      glTranslatef(-105, 402, 0);
      glRotatef(-90.0, 0, 0, 1.0);
      glBegin(GL_POLYGON); // Phil body 1

      glColor3f(1, 1, 0);
      for (to = 0; to <= 360; to++) {
        tx = 4 * sin(to);
        ty = 13 * cos(to);
        tz = 0;
        glVertex3f(210 + tx, 380 + ty, tz);
      }
      glEnd();
      glPopMatrix();
      glFlush();

      //----------------------
      //===========5th==========//

      // 4th chop
      //
      //
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(490, 65, 0.0, 0.6, "PHILOSOPHER 5 EATING");
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 40, 0.0, 0.4, "-->PHILOSOPHER 5 PICKS Rc");
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(485, 25, 0.0, 0.4, "-->PHILOSOPHER 5 PICKS Lc");
      glLineWidth(3.0);
      glColor3f(1.0, 1.0, 1.0);
      Write(498, 8, 0.0, 0.4, "PROBLEM SOLVED!!!");
      p5.state = '1';
      glPushMatrix();
      glTranslatef(-5, 40, 0);
      chop4();
      glPopMatrix();
      glPushMatrix();
      glLineWidth(5.0);
      glBegin(GL_LINES); // chop 4
      glColor3f(0.3, 0.4, 0.90);
      glVertex2i(265, 225);
      glVertex2i(290, 220);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
      glFlush();
      Sleep(3000);
      glutPostRedisplay();

      //glutPostRedisplay();
      break;
    case 27:
      exit(0);
    }
  } else if (flag == 6) {
    switch (key) {
    case 'b':
      flag = 4;
      glutPostRedisplay();
      break;

    case 27:
      exit(0);
    }
  }

  //handle --> press any key to continue.............//////////////////////////..............
  glLineWidth(3.0);
  glColor3f(1.0, 1.0, 1.0);
  Write(485, 440, 0.0, 0.4, "-->PHILOSOPHER 1 PICKS Rc");
}

void chop1() {
  glLineWidth(5.0);

  glBegin(GL_LINES); // chop 1
  glColor3f(0.0, 0.0, 0.0);
  glVertex2i(175, 330);
  glVertex2i(195, 310);
  glEnd();
  glLineWidth(1.0);
}
void chop2() {
  glLineWidth(5.0);
  glBegin(GL_LINES); // chop 2
  glColor3f(0.0, 0.0, 0.0);
  glVertex2i(151, 215);
  glVertex2i(178, 220);
  glEnd();
  glLineWidth(1.0);
}

void chop3() {
  glLineWidth(5.0);
  glBegin(GL_LINES); // chop 3
  glColor3f(0.0, 0.0, 0.0);
  glVertex2i(220, 180);
  glVertex2i(225, 145);
  glEnd();
  glLineWidth(1.0);
}
void chop4() {
  glLineWidth(5.0);
  glBegin(GL_LINES); // chop 4
  glColor3f(0.0, 0.0, 0.0);
  glVertex2i(265, 225);
  glVertex2i(290, 220);
  glEnd();
  glLineWidth(1.0);
}
void chop5() {
  glLineWidth(5.0);
  glBegin(GL_LINES); // chop 5
  glColor3f(0.0, 0.0, 0.0);
  glVertex2i(250, 315);
  glVertex2i(277, 320);
  glEnd();
  glLineWidth(1.0);
}

void myInit(void)

{

  glClearColor(0.0, 0.0, 0.0, 0.0); // sets background color to white

  // sets a point to be 4x4 pixels

  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();

  gluOrtho2D(0.0, 640.0, 0.0, 480.0); // the display area in world coordinates.

}
void Phil1() {
  glBegin(GL_LINE_LOOP); //chair back
  glColor3f(0.0, 0.0, 0.0);
  glVertex3i(200, 410, 0);
  glVertex3i(200, 416, 0);
  glVertex3i(245, 416, 0);
  glVertex3i(245, 410, 0);
  glEnd();

  glBegin(GL_LINE_LOOP); //chair back 1
  glColor3f(0.8, 0, 0.1);
  glVertex2i(206, 410);
  glVertex2i(209, 410);
  glVertex2i(209, 374);
  glVertex2i(206, 374);
  glEnd();
  glBegin(GL_LINE_LOOP); //chair back 1
  glColor3f(0.8, 0, 0.1);
  glVertex2i(237, 410);
  glVertex2i(240, 410);
  glVertex2i(240, 374);
  glVertex2i(237, 374);
  glEnd();

  glBegin(GL_POLYGON); //leg
  glColor3f(0.8, 0, 0.1);
  glVertex2i(207, 369);
  glVertex2i(203, 339);
  glVertex2i(245, 339);
  glVertex2i(240, 370);
  glEnd();

  glBegin(GL_POLYGON); // Phil body 1
  glColor3f(0.3, 0.7, 0.1);
  for (to = 0; to <= 360; to++) {
    tx = 22 * sin(to);
    ty = 15 * cos(to);
    tz = 0;
    glVertex3f(223 + tx, 380 + ty, tz);
  }
  glEnd();

  glBegin(GL_POLYGON); // Phil head 1
  glColor3f(0, 0, 0);
  for (to = 0; to <= 360; to++) {
    tx = 11 * sin(to);
    ty = 16 * cos(to);
    tz = 0;
    glVertex3f(223 + tx, 399 + ty, tz);
  }
  glEnd();

}

void page1() {
  glClearColor(1.0, 1.0, 1.0, 1.0);
  //  glClearColor(0.75, 0.87, 0.85, 1.0);

  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.4, 0.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(0, 0);
  glVertex2f(150, 0);
  glVertex2f(150, 1000);
  glVertex2f(0, 1000);
  glEnd();

  glLineWidth(3.0);

  glColor3f(1.0, 0.0, 0.0);

  Write(250, 450, 0.0, 0.006, "    SDM INSTITUTE OF TECHNOLOGY");


  glLineWidth(2.0);
  Write(210, 430, 0.1, 0.008,  "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");

  glColor3f(0.71, 0.41, 0.41);
  glPushMatrix();
  glTranslatef(-105.0, 95.0, 0.0);
  glColor3f(0.4, 0.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(250, 250);
  glVertex2f(325, 250);
  glVertex2f(250, 175);
  glVertex2f(325, 175);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(150.0, 0.0, 0.0);
  glColor3f(0.4, 0.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(350, 350);
  glVertex2f(275, 350);
  glVertex2f(350, 275);
  glVertex2f(275, 275);
  glEnd();
  glPopMatrix();

  glColor3f(0.23, 0.23, 0.21);
  glLineWidth(2.0);
  Write(210, 410, -0.6, 0.002, "COMPUTER GRAPHICS LABORATORY WITH MINI PROJECT ");

  Write(320, 390, -0.6, 0.002, "ON");
  glColor3f(0.71, 0.41, 0.41);
  glLineWidth(2.0);
  Write(260, 370, -0.6, 0.002, "*DINING PHILOSOPHER PROBLEM*");

  glColor3f(0.0, 0.0, 0.0);

  glLineWidth(2.0);

  Write(265, 300, 0.0, 0.0015, "            Submitted By:        ");

  glColor3f(0.71, 0.41, 0.41);

  glLineWidth(2.3);

  Write(200, 245, 0.0, 0.0015, " DHANUSH                                                               DEV DUTT GOWDA M J");

  glColor3f(0.71, 0.41, 0.41);
  glLineWidth(2.3);

  Write(200, 225, 0.0, 0.0014, " 4SU19CS026                                                          4SU19CS024");
   glColor3f(0.71, 0.41, 0.41);

  glLineWidth(2.3);

  Write(200, 200, 0.0, 0.0015, " DEEPTI P NAIK                                                        KAVYA H M");

  glColor3f(0.71, 0.41, 0.41);
  glLineWidth(2.3);

  Write(200, 180, 0.0, 0.0014, " 4SU19CS023                                                           4SU19CS039");

  glColor3f(0.0, 0.0, 0.0);

  glLineWidth(2.0);

  Write(265, 145, 0.0, 0.0015, "     Under The Guidance Of:    ");

  glColor3f(0.0, 0.0, 0.0);

  Write(260, 125, 0.0, 0.008, "     PROF.PRADEEP RAO K.B      ");

  glColor3f(0.0, 0.0, 0.0);

  Write(265, 105, 0.0, 0.0015, "     Lecturer,Dept. of CSE      ");
  glColor3f(0.4, 0.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(500, 0);
  glVertex2f(650, 0);
  glVertex2f(650, 1000);
  glVertex2f(500, 1000);
  glEnd();

  glColor3f(0.0, 1.0, 1.0);

  Write(510, 73, 0.0, 0.0014, "       Press 'c' to continue...");
  glFlush();
}

void page2() {
  // glClearColor(0.75, 0.87, 0.85, 1.0);
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  glTranslatef(-125.0, 75.0, 0.0);
  glColor3f(0.4, 0.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(350, 350);
  glVertex2f(550, 350);
  glVertex2f(550, 375);
  glVertex2f(350, 375);
  glEnd();
  glPopMatrix();
  glColor3f(1.0, 1.0, 0.0);
  Write(256, 434, -0.6, 0.002, "DINING PHILOSOPHERS PROBLEM");
  Write(225, 365, 0, 0.002, "---------------------------------------");
  Write(310, 345, 0, 0.002, "M...E...N...U");
  Write(225, 325, 0, 0.002, "---------------------------------------");
  Write(275, 300, 0, 0.002, "1 -->  Introduction");
  Write(275, 255, 0, 0.002, "2 -->  Dining Philosopher Solution");
  Write(275, 210, 0, 0.002, "3 -->   Exit");
  glColor3f(0.4, 0.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(0, 0);
  glVertex2f(150, 0);
  glVertex2f(150, 1000);
  glVertex2f(0, 1000);
  glEnd();

  glColor3f(0.4, 0.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(500, 0);
  glVertex2f(650, 0);
  glVertex2f(650, 1000);
  glVertex2f(500, 1000);
  glEnd();
  Write(500, 365, 0, 0.002, "---------------------------------------");
  Write(540, 345, 0, 0.002, "SUBMENU");
  Write(500, 330, 0, 0.002, "---------------------------------------");
  Write(510, 300, 0, 0.002, "c-->   Continue");
  Write(510, 270, 0, 0.002, "1 -->  Introduction");
  Write(510, 240, 0, 0.002, "2 -->  Execute");
  Write(510, 210, 0, 0.002, "3 -->  Exit");
  Write(510, 180, 0, 0.002, "4 -->  Main menu");
  glFlush();
}

void page5() {

  //glClearColor(0.75, 0.87, 0.85, 1.0);
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glPushMatrix();
  glTranslatef(-125.0, 75.0, 0.0);
  glColor3f(0.4, 0.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(350, 350);
  glVertex2f(550, 350);
  glVertex2f(550, 375);
  glVertex2f(350, 375);
  glEnd();
  glPopMatrix();
  glColor3f(1.0, 1.0, 0.0);
  Write(256, 434, -0.6, 0.002, "DINING PHILOSOPHERS PROBLEM");
  glPushMatrix();
  glColor3f(0.4, 0.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(0, 0);
  glVertex2f(150, 0);
  glVertex2f(150, 1000);
  glVertex2f(0, 1000);
  glEnd();
  glPopMatrix();

  glLineWidth(2.0);
  Write(220, 380, 0.1, 0.008, " The dining philosopher is a classic synchronization problem !");
  Write(155, 338, 0.1, 0.008, "-> There are some Philosophers whose work is just thinking and eating(Say 5 philosophers).");
  Write(155, 326, 0.1, 0.008, "-> But there are only 5 Forks available (Forks always equal to no. of Philosophers) on table. ");
  Write(155, 314, 0.1, 0.008, "-> They take in such a manner that, first take left Fork and next right Fork.");
  Write(155, 302, 0.1, 0.008, "-> But problem is they try to take at same time. Since they are trying at same time.");
  Write(155, 290, 0.1, 0.008, "-> And each one tries to take right side Fork. But no one can find the available Fork. ");
  Write(155, 278, 0.1, 0.008, "-> And also that each one thinks that someone will release the Fork and then I can eat.");
  Write(155, 266, 0.1, 0.008, "-> This continuous waiting leads to Dead Lock situation.");
  Write(155, 254, 0.1, 0.008, "-> A SOLUTION of the Dining Philosophers Problem is to use a SEMAPHORE to represent a chopstick.");
  Write(155, 242, 0.1, 0.008, "-> A chopstick can be picked up by executing a wait operation on the semaphore ");
  Write(175, 230, 0.1, 0.008, "and released by executing a signal semaphore.");
  Write(155, 218, 0.1, 0.008, "-> Some of the ways to avoid deadlock are as follows:");
  Write(185, 202, 0.1, 0.008, " * There should be at most four philosophers on the table.");
  Write(185, 190, 0.1, 0.008, " * An even philosopher should pick the right chopstick and then the left chopstick while an odd");
  Write(195, 178, 0.1, 0.008, " philosopher should pick the left chopstick and then the right chopstick.");
  Write(185, 166, 0.1, 0.008, " * A philosopher should only be allowed to pick their chopstick if both are available at the same time.");

  glFlush();

}
void page6() {

  //glClearColor(0.75, 0.87, 0.85, 1.0);
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glPushMatrix();
  glTranslatef(-125.0, 75.0, 0.0);
  glColor3f(0.4, 0.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(350, 350);
  glVertex2f(550, 350);
  glVertex2f(550, 375);
  glVertex2f(350, 375);
  glEnd();
  glPopMatrix();
  glColor3f(1.0, 1.0, 0.0);
  Write(256, 434, -0.6, 0.002, "DINING PHILOSOPHERS PROBLEM");
  glPushMatrix();
  glColor3f(0.4, 0.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(0, 0);
  glVertex2f(150, 0);
  glVertex2f(150, 1000);
  glVertex2f(0, 1000);
  glEnd();
  glPopMatrix();

  glLineWidth(2.0);
  Write(220, 380, 0.1, 0.008, " The dining philosopher is a classic synchronization problem !");
  Write(155, 338, 0.1, 0.008, "-> There are some Philosophers whose work is just thinking and eating(Say 5 philosophers).");
  Write(155, 326, 0.1, 0.008, "-> But there are only 5 Forks available (Forks always equal to no. of Philosophers) on table. ");
  Write(155, 314, 0.1, 0.008, "-> They take in such a manner that, first take left Fork and next right Fork.");
  Write(155, 302, 0.1, 0.008, "-> But problem is they try to take at same time. Since they are trying at same time.");
  Write(155, 290, 0.1, 0.008, "-> And each one tries to take right side Fork. But no one can find the available Fork. ");
  Write(155, 278, 0.1, 0.008, "-> And also that each one thinks that someone will release the Fork and then I can eat.");
  Write(155, 266, 0.1, 0.008, "-> This continuous waiting leads to Dead Lock situation.");
  Write(155, 254, 0.1, 0.008, "-> A SOLUTION of the Dining Philosophers Problem is to use a SEMAPHORE to represent a chopstick.");
  Write(155, 242, 0.1, 0.008, "-> A chopstick can be picked up by executing a wait operation on the semaphore ");
  Write(175, 230, 0.1, 0.008, "and released by executing a signal semaphore.");
  Write(155, 218, 0.1, 0.008, "-> Some of the ways to avoid deadlock are as follows:");
  Write(185, 202, 0.1, 0.008, " * There should be at most four philosophers on the table.");
  Write(185, 190, 0.1, 0.008, " * An even philosopher should pick the right chopstick and then the left chopstick while an odd");
  Write(195, 178, 0.1, 0.008, " philosopher should pick the left chopstick and then the right chopstick.");
  Write(185, 166, 0.1, 0.008, " * A philosopher should only be allowed to pick their chopstick if both are available at the same time.");

  glFlush();

}

void phil1_righthand() {
  glPushMatrix();
  glTranslatef(311, 803, 0);
  glRotatef(-160.0, 0, 0, 1.0);
  glBegin(GL_POLYGON); // Phil body 1

  glColor3f(0, 0, 0);
  for (to = 0; to <= 360; to++) {
    tx = 4 * sin(to);
    ty = 16 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();

  // hand down part
  glPushMatrix();
  glTranslatef(-165, 192, 0);
  glRotatef(-40.0, 0, 0, 1.0);
  glBegin(GL_POLYGON); // Phil body 1

  glColor3f(1, 1, 0);
  for (to = 0; to <= 360; to++) {
    tx = 4 * sin(to);
    ty = 15 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();

}

void phil2_righthand() {
  glPushMatrix();
  glTranslatef(-230, 515, 0);
  glRotatef(-90.0, 0, 0, 1.0);
  glBegin(GL_POLYGON); // Phil body 1

  glColor3f(0, 0, 0);
  for (to = 0; to <= 360; to++) {
    tx = 5 * sin(to);
    ty = 15 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();

  // down part of hand
  glPushMatrix();
  glTranslatef(232, 725, 0);
  glRotatef(-160.0, 0, 0, 1.0);
  glBegin(GL_POLYGON); //

  glColor3f(1, 1, 0);
  for (to = 0; to <= 360; to++) {
    tx = 4 * sin(to);
    ty = 16 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();

}

void phil3_righthand() {
  glPushMatrix();
  glTranslatef(-218, -50, 0);
  glRotatef(-30.0, 0, 0, 1.0);
  glBegin(GL_POLYGON);
  glColor3f(0, 0, 0);
  for (to = 0; to <= 360; to++) {
    tx = 4 * sin(to);
    ty = 20 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();
  //down part

  glPushMatrix();
  glTranslatef(-213, 398, 0);
  glRotatef(-90.0, 0, 0, 1.0);
  glBegin(GL_POLYGON); // Phil body 1

  glColor3f(1, 1, 0);
  for (to = 0; to <= 360; to++) {
    tx = 4 * sin(to);
    ty = 13 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();

}

void phil4_righthand() {
  glPushMatrix();
  glTranslatef(254, 584, 0);
  glRotatef(-150.0, 0, 0, 1.0);
  glBegin(GL_POLYGON); // Phil body 1

  glColor3f(0, 0, 0);
  for (to = 0; to <= 360; to++) {
    tx = 4 * sin(to);
    ty = 16 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();

  // hand down part
  glPushMatrix();
  glTranslatef(-70, -110, 0);
  glRotatef(-20.0, 0, 0, 1.0);
  glBegin(GL_POLYGON); // Phil body 1

  glColor3f(1, 1, 0);
  for (to = 0; to <= 360; to++) {
    tx = 4 * sin(to);
    ty = 15 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();

}

void phil5_righthand() {
  glPushMatrix();
  glTranslatef(-115, 175, 0);
  glRotatef(-50.0, 0, 0, 1.0);
  glBegin(GL_POLYGON); // Phil body 1

  glColor3f(0, 0, 0);
  for (to = 0; to <= 360; to++) {
    tx = 5 * sin(to);
    ty = 15 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();
  //down part
  glPushMatrix();
  glTranslatef(5, 581, 0);
  glRotatef(-110.0, 0, 0, 1.0);
  glBegin(GL_POLYGON); // Phil body 1

  glColor3f(1, 1, 0);
  for (to = 0; to <= 360; to++) {
    tx = 4 * sin(to);
    ty = 13 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();

}
void phil1_hand() //hand
{
  glPushMatrix();
  glTranslatef(-71, 30, 0);
  glRotatef(-10.0, 0, 0, 1.0);
  glBegin(GL_POLYGON);
  glColor3f(0, 0, 0);
  for (to = 0; to <= 360; to++) {
    tx = 4 * sin(to);
    ty = 20 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();

  // down part of hand
  glPushMatrix();
  glTranslatef(195, 780, 0);
  glRotatef(-150.0, 0, 0, 1.0);
  glBegin(GL_POLYGON); //

  glColor3f(1, 1, 0);
  for (to = 0; to <= 360; to++) {
    tx = 4 * sin(to);
    ty = 16 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();

}

void phil2_hand() //hand 2
{
  glPushMatrix();
  glTranslatef(-120, 100, 0);
  glRotatef(-30.0, 0, 0, 1.0);
  glBegin(GL_POLYGON); // Phil body 1

  glColor3f(0, 0, 0);
  for (to = 0; to <= 360; to++) {
    tx = 15 * sin(to);
    ty = 5 * cos(to);
    tz = 0;
    glVertex3f(144 + tx, 262 + ty, tz);
  }
  glEnd();
  glPopMatrix();

  // hand down part
  glPushMatrix();
  glTranslatef(-252, 102, 0);
  glRotatef(-40.0, 0, 0, 1.0);
  glBegin(GL_POLYGON); // Phil body 1

  glColor3f(1, 1, 0);
  for (to = 0; to <= 360; to++) {
    tx = 4 * sin(to);
    ty = 15 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();

}

void phil3_hand() //hand 3
{
  glPushMatrix();
  glTranslatef(-220, -11, 0);
  glRotatef(-40.0, 0, 0, 1.0);
  glBegin(GL_POLYGON); // Phil body 1

  glColor3f(0, 0, 0);
  for (to = 0; to <= 360; to++) {
    tx = 4 * sin(to);
    ty = 15 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();

  //down part

  glPushMatrix();
  glTranslatef(332, 576, 0);
  glRotatef(-170.0, 0, 0, 1.0);
  glBegin(GL_POLYGON); // Phil body 1

  glColor3f(1, 1, 0);
  for (to = 0; to <= 360; to++) {
    tx = 4 * sin(to);
    ty = 16 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();

}

void phil4_hand() //hand 4
{
  glPushMatrix();
  glTranslatef(281, 616, 0);
  glRotatef(-150.0, 0, 0, 1.0);
  glBegin(GL_POLYGON); // Phil body 1

  glColor3f(0, 0, 0);
  for (to = 0; to <= 360; to++) {
    tx = 4 * sin(to);
    ty = 16 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();

  // down part
  glPushMatrix();
  glTranslatef(-105, 402, 0);
  glRotatef(-90.0, 0, 0, 1.0);
  glBegin(GL_POLYGON); // Phil body 1

  glColor3f(1, 1, 0);
  for (to = 0; to <= 360; to++) {
    tx = 4 * sin(to);
    ty = 13 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();

}

void phil5_hand() //hand 5
{
  glPushMatrix();
  glTranslatef(-85, 520, 0);
  glRotatef(-90.0, 0, 0, 1.0);
  glBegin(GL_POLYGON); // Phil body 1

  glColor3f(0, 0, 0);
  for (to = 0; to <= 360; to++) {
    tx = 5 * sin(to);
    ty = 15 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();
  //down part
  glPushMatrix();
  glTranslatef(7, -42, 0);
  glRotatef(-10.0, 0, 0, 1.0);
  glBegin(GL_POLYGON); // Phil body 1

  glColor3f(1, 1, 0);
  for (to = 0; to <= 360; to++) {
    tx = 4 * sin(to);
    ty = 18 * cos(to);
    tz = 0;
    glVertex3f(210 + tx, 380 + ty, tz);
  }
  glEnd();
  glPopMatrix();

}

void topview() {

  glBegin(GL_POLYGON); //background
  glColor3f(1.0, 1.0, 1.0);
  glVertex2i(0, 0);
  glVertex2i(700, 0);
  glVertex2i(700, 600);
  glVertex2i(0, 600);
  glEnd();
  Phil1();
  glMatrixMode(GL_MODELVIEW); // 2nd phil
  glLoadIdentity();
  glPushMatrix();
  glScaled(0.8, 1.1, 0);
  glTranslatef(448, -82, 0);
  glRotatef(10, 0.0, 0.0, 1.0);
  glRotatef(60, 0.0, 0.0, 1.0);
  Phil1();
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW); //3rd phil
  glLoadIdentity();
  glPushMatrix();
  glScaled(0.8, 1.1, 0);
  glTranslatef(-45, 341, 0);
  glRotatef(10, 0.0, 0.0, -1.0);
  glRotatef(60, 0.0, 0.0, -1.0);
  Phil1();
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW); //5th phil
  glLoadIdentity();
  glPushMatrix();
  glScaled(0.8, 1.0, 0);
  glTranslatef(243, 580, 0);
  glRotatef(10, 0.0, 0.0, -1.0);
  glRotatef(10, 0.0, 0.0, -1.0);
  glRotatef(25, 0.0, 0.0, -1.0);
  glRotatef(90, 0.0, 0.0, -1.0);
  Phil1();
  glPopMatrix();
  /*
   */
  glMatrixMode(GL_MODELVIEW); //4th phil
  glLoadIdentity();
  glPushMatrix();
  glScaled(0.8, 1.0, 0);
  glTranslatef(630, 262, 0);
  glRotatef(30, 0.0, 0.0, 1.0);
  glRotatef(105, 0.0, 0.0, 1.0);
  Phil1();
  glPopMatrix();

  glBegin(GL_POLYGON); //table
  glColor3f(0.3, 0.4, 0.90);
  for (to = 0; to <= 360; to++) {
    tx = 75 * sin(to);
    ty = 105 * cos(to);
    tz = 0;
    glVertex3f(222 + tx, 249 + ty, tz);
  }
  glEnd();
  glFlush();

  glBegin(GL_POLYGON); //plate 1
  glColor3f(1.0, 1.0, 0.80);
  for (to = 0; to <= 360; to++) {
    tx = 14 * sin(to);
    ty = 16 * cos(to);
    tz = 0;
    glVertex3f(222 + tx, 338 + ty, tz);
  }
  glEnd();

  glBegin(GL_POLYGON); //plate 2
  glColor3f(1.0, 1.0, 0.80);
  for (to = 0; to <= 360; to++) {
    tx = 14 * sin(to);
    ty = 16 * cos(to);
    tz = 0;
    glVertex3f(170 + tx, 270 + ty, tz);
  }
  glEnd();

  glBegin(GL_POLYGON); //plate 3
  glColor3f(1.0, 1.0, 0.80);
  for (to = 0; to <= 360; to++) {
    tx = 14 * sin(to);
    ty = 16 * cos(to);
    tz = 0;
    glVertex3f(180 + tx, 190 + ty, tz);
  }
  glEnd();

  glBegin(GL_POLYGON); //plate 4
  glColor3f(1.0, 1.0, 0.80);
  for (to = 0; to <= 360; to++) {
    tx = 14 * sin(to);
    ty = 16 * cos(to);
    tz = 0;
    glVertex3f(260 + tx, 185 + ty, tz);
  }
  glEnd();

  glBegin(GL_POLYGON); //plate 5
  glColor3f(1.0, 1.0, 0.80);
  for (to = 0; to <= 360; to++) {
    tx = 14 * sin(to);
    ty = 16 * cos(to);
    tz = 0;
    glVertex3f(275 + tx, 270 + ty, tz);
  }
  glEnd();

  glLineWidth(5.0);
  glLineWidth(3.0);
  glColor3f(1.0, 0.0, 1.0);
  Write(150, 40, 0.0, 0.4, "*** PRESS 'p' or 'P' to start process ***");
  glLineWidth(3.0);
  glColor3f(1.0, 0.0, 1.0);
  Write(150, 25, 0.0, 0.4, "*** PRESS 's' or 'S' to start process ***");
  //philosopher names
  glLineWidth(3.0);
  glColor3f(0.4, 0.0, 1.0);
  Write(190, 470, 0.0, 0.6, "PHILOSOPHER 1");

  glLineWidth(3.0);
  glColor3f(0.4, 0.0, 1.0);
  Write(60, 390, 0.0, 0.6, "PHILOSOPHER 2");

  glLineWidth(3.0);
  glColor3f(0.4, 0.0, 1.0);
  Write(60, 190, 0.0, 0.6, "PHILOSOPHER 3");

  glLineWidth(3.0);
  glColor3f(0.4, 0.0, 1.0);
  Write(365, 190, 0.0, 0.6, "PHILOSOPHER 4");

  glLineWidth(3.0);
  glColor3f(0.4, 0.0, 1.0);
  Write(365, 390, 0.0, 0.6, "PHILOSOPHER 5");

  //rhs
  glBegin(GL_POLYGON);
  glColor3f(0.4, 0.0, 1.0);
  glVertex3i(470, 1000, 0);
  glVertex3i(470, 0, 0);
  glVertex3i(1000, 0, 0);
  glVertex3i(1000, 1000, 0);
  glEnd();

  chop1();
  chop2();
  chop3();
  chop4();
  chop5();
  phil1_righthand();
  phil2_righthand();
  phil3_righthand();
  phil4_righthand();
  phil5_righthand();
  phil1_hand();
  phil2_hand();
  phil3_hand();
  phil4_hand();
  phil5_hand();
  glLineWidth(1.0);

}

void myDisplay(void) {
  //glClearColor(1.0, 1.0, 1.0, 1.0);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glShadeModel(GL_FLAT);
  if (flag == 1) {
    page1(); //spash screen
  } else if (flag == 2) {
    page2(); //menu
  } else if (flag == 3) {
    page5(); //intro

  } else if (flag == 4) {
    topview();

    // finish = 0;
  }
  glFlush();
  //glutSwapBuffers();

}

int main(int argc, char ** argv) {

  glutInit( & argc, argv); // to initialize the toolkit;

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // sets the display mode

  glutInitWindowSize(1500, 1200); // sets the window size

  glutInitWindowPosition(20, 10); // sets the starting position for the window

  glutCreateWindow("Dining Philosophers Problem"); // creates the window and sets the title

  glutDisplayFunc(myDisplay);
  glutKeyboardFunc(keyboard);
  myInit(); // additional initializations as necessary
  glutMainLoop(); // go into a loop until event occurs
  return 0;
}
