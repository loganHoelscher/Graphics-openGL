//
//  main.cpp
//  2Dgraphics
//
//  Created by Logan Hoelscher on 9/11/19.
//  Copyright © 2019 Logan Hoelscher. All rights reserved.
//

#include <iostream>
#include <GLUT/glut.h>
using namespace std;

/*! GLUT display callback function */
void display(void);
/*! GLUT window reshape callback function */
void reshape(int, int);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    
    /* set the window size */
    glutInitWindowSize(800, 600);
    
    /* set the display mode */
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    
    /* create the window */
    glutCreateWindow("Palm Tree");
    
    /* set the glut display callback function */
    glutDisplayFunc(display);
    
    /* set the glut reshape callback function */
    glutReshapeFunc(reshape);
    
    /* set the default background color to white */
    glClearColor(250,250,250,1);
    
    /* main event loop */
    glutMainLoop();
    
    return 0;
}

/*! glut display callback function */
void display()
{
    /* clear the color buffer */
    glClear(GL_COLOR_BUFFER_BIT);
    
    /* Background Color */
    //ground
    glColor3f(0.847059, 0.847059, 0.74902); // wheat
    glBegin(GL_TRIANGLES);
    
    glVertex2d(0, 0);
    glVertex2d(0, 300);
    glVertex2d(800, 0);
    
    glColor3f(0.30, 0.44, 0.60);  // dark blue
    
    glVertex2d(0, 300);
    glVertex2d(0, 600);
    glVertex2d(800, 0);
    
    
    glColor3f(0.360784, 0.490784, 0.637255);  //darkest light blue blue

    glVertex2d(0, 600);
    glVertex2d(300, 600);
    glVertex2d(800, 0);
    
    
    glColor3f(0.490784, 0.530784, 0.767255);  // darker light steel blue
    
    glVertex2d(300, 600);
    glVertex2d(800, 0);
    glVertex2d(550, 600);
    
    glColor3f(0.560784, 0.560784, 0.737255);  // light steel blue
    
    glVertex2d(550, 600);
    glVertex2d(800, 0);
    glVertex2d(800, 600);
    
    glEnd();
    
    /* set the current drawing color to brown */
    glColor3f(0.65, 0.50, 0.39);
    glBegin(GL_TRIANGLES);
    
    /* Triangles for the palm tree's trunk */
    glVertex2f(345, 0);
    glVertex2f(345, 300);
    glVertex2f(425, 0);
    
    glVertex2f(425, 0);
    glVertex2f(425, 300);
    glVertex2f(345, 300);
    
    glVertex2f(335, 0);
    glVertex2f(335, 100);
    glVertex2f(435, 0);
    
    glVertex2f(435, 100);
    glVertex2f(435, 0);
    glVertex2f(335, 100);
    
    /* trunk detail */
    glVertex2f(335, 100);
    glVertex2f(345, 150);
    glVertex2f(345, 100);
    
    glVertex2f(435, 100);
    glVertex2f(425, 100);
    glVertex2f(425, 150);
    
    glVertex2f(345, 150);
    glVertex2f(335, 190);
    glVertex2f(345, 240);
    
    glVertex2f(425, 150);
    glVertex2f(435, 190);
    glVertex2f(425, 240);
    
    glVertex2f(325, 280);
    glVertex2f(325, 300);
    glVertex2f(445, 280);
    
    glVertex2f(445, 280);
    glVertex2f(445, 300);
    glVertex2f(325, 300);
    
    glVertex2f(345, 240);
    glVertex2f(325, 280);
    glVertex2f(345, 280);
    
    glVertex2f(425, 240);
    glVertex2f(445, 280);
    glVertex2f(425, 280);
    
    //trunk detail
    glColor3f(0.847059, 0.847059, 0.74902); // wheat
    
    glVertex2f(325, 300);
    glVertex2f(354, 300);
    glVertex2f(354, 240);
    
    glVertex2f(373, 300);
    glVertex2f(354, 240);
    glVertex2f(373, 240);
    
    glVertex2f(373, 240);
    glVertex2f(393, 240);
    glVertex2f(393, 300);
    
    glVertex2f(413, 300);
    glVertex2f(413, 240);
    glVertex2f(393, 240);
    
    glColor3f(0.91, 0.76, 0.65); //light wood
    
    glVertex2f(354, 240);
    glVertex2f(373, 300);
    glVertex2f(354, 300);
    
    glVertex2f(373, 300);
    glVertex2f(373, 240);
    glVertex2f(393, 300);
    
    glVertex2f(393, 240);
    glVertex2f(393, 300);
    glVertex2f(413, 300);
    
    glVertex2f(413, 300);
    glVertex2f(413, 240);
    glVertex2f(443, 300);

    /* triangles for the palm leaves */
    glColor3f(0.560784, 0.737255, 0.560784); //pale green color for primary palm color
    
    // lower right hand palm
    glVertex2f(395, 300);
    glVertex2f(500, 370);
    glVertex2f(480, 285);
    
    glVertex2f(480, 285);
    glVertex2f(530, 240);
    glVertex2f(500, 370);
    
    glVertex2f(525, 260);
    glVertex2f(500, 360);
    glVertex2f(570, 300);
    
    glVertex2f(560, 295);
    glVertex2f(520, 255);
    glVertex2f(620, 200);
    
    //lower left hand palm
    glVertex2f(385, 300);
    glVertex2f(280, 370);
    glVertex2f(290, 280);
    
    glVertex2f(280, 370);
    glVertex2f(290, 280);
    glVertex2f(240, 240);
    
    glVertex2f(280, 360);
    glVertex2f(210, 300);
    glVertex2f(250, 260);
    
    glVertex2f(225, 290);
    glVertex2f(250, 260);
    glVertex2f(150, 200);
    
    //upper right hand palm
    glVertex2f(380, 300);
    glVertex2f(425, 300);
    glVertex2f(455, 410);
    
    glVertex2f(385, 305);
    glVertex2f(455, 400);
    glVertex2f(395, 420);
    
    glVertex2f(395, 420);
    glVertex2f(445, 400);
    glVertex2f(510, 460);
    
    glVertex2f(510, 460);
    glVertex2f(420, 380);
    glVertex2f(540, 410);
    
    glVertex2f(510, 455);
    glVertex2f(540, 410);
    glVertex2f(600, 430);
    
    glVertex2f(585, 430);
    glVertex2f(500, 410);
    glVertex2f(610, 390);
    
    // upper left hand palm
    glVertex2f(400, 300);
    glVertex2f(340, 300);
    glVertex2f(325, 400);
    
    glVertex2f(385, 305);
    glVertex2f(325, 400);
    glVertex2f(375, 420);
    
    glVertex2f(325, 400);
    glVertex2f(375, 420);
    glVertex2f(240, 460);
    
    glVertex2f(250, 455);
    glVertex2f(325, 410);
    glVertex2f(190, 420);
    
    glVertex2f(245, 415);
    glVertex2f(335, 370);
    glVertex2f(330, 415);
    
    glVertex2f(215, 420);
    glVertex2f(180, 390);
    glVertex2f(315, 415);
    
    //middle palm leaves
    glVertex2f(300, 520);
    glVertex2f(390, 435);
    glVertex2f(400, 320);
    
    glVertex2f(455, 520);
    glVertex2f(380, 445);
    glVertex2f(380, 300);
    
    glVertex2f(300, 520);
    glVertex2f(255, 500);
    glVertex2f(350, 460);
    
    glVertex2f(300, 515);
    glVertex2f(255, 490);
    glVertex2f(220, 500);
    
    glVertex2f(455, 520);
    glVertex2f(505, 500);
    glVertex2f(425, 460);
    
    glVertex2f(455, 517);
    glVertex2f(540, 500);
    glVertex2f(460, 480);
    
    glVertex2f(535, 500);
    glVertex2f(550, 470);
    glVertex2f(505, 500);
    
    // palm leaf detail
     glColor3f(0.32, 0.49, 0.46);// set color to dark green
    
    //lower left palm
    glVertex2f(345, 310);
    glVertex2f(285, 350);
    glVertex2f(290, 325);
    
    glVertex2f(285, 350);
    glVertex2f(290, 325);
    glVertex2f(220, 260);
    
    
    glColor3f(0.137255, 0.556863, 0.419608); // less dark green for detail
    
    glVertex2f(345, 310);
    glVertex2f(290, 325);
    glVertex2f(295, 310);
    
    glVertex2f(290, 325);
    glVertex2f(295, 310);
    glVertex2f(215, 256);
    
    
    //lower right palm
    glColor3f(0.32, 0.49, 0.46); // dark green
    
    glVertex2f(420, 310);
    glVertex2f(488, 348);
    glVertex2f(482, 325);
    
    glVertex2f(488, 348);
    glVertex2f(482, 325);
    glVertex2f(553, 260);
    
    glColor3f(0.137255, 0.556863, 0.419608); // less dark green
    
    glVertex2f(420, 310);
    glVertex2f(482, 325);
    glVertex2f(477, 310);
    
    glVertex2f(482, 325);
    glVertex2f(477, 310);
    glVertex2f(560, 255);
    
    //middle left palm
    
    glVertex2f(385, 350);
    glVertex2f(275, 420);
    glVertex2f(365, 400);
    
    glColor3f(0.32, 0.49, 0.46); // dark green
    
    glVertex2f(275, 420);
    glVertex2f(260, 440);
    glVertex2f(365, 400);
    
    glColor3f(0.137255, 0.556863, 0.419608); // less dark green
    
    glVertex2f(275, 420);
    glVertex2f(260, 440);
    glVertex2f(225, 412);
    
    // middle right palm
    glVertex2f(385, 350);
    glVertex2f(495, 420);
    glVertex2f(405, 400);
    
    glColor3f(0.32, 0.49, 0.46); // dark green
    
    glVertex2f(495, 420);
    glVertex2f(405, 400);
    glVertex2f(505, 445);
    
    glColor3f(0.137255, 0.556863, 0.419608); // less dark green
    
    glVertex2f(505, 445);
    glVertex2f(495, 420);
    glVertex2f(550, 420);
    
    //top left palm
    glColor3f(0.32, 0.49, 0.46); // dark green
    
    glVertex2f(365, 430);
    glVertex2f(330, 485);
    glVertex2f(329, 470);
    
    glColor3f(0.137255, 0.556863, 0.419608); // less dark green
    
    glVertex2f(330, 485);
    glVertex2f(329, 470);
    glVertex2f(280, 500);
    
    //top right palm
    glColor3f(0.32, 0.49, 0.46); // dark green
    
    glVertex2f(390, 430);
    glVertex2f(450, 500);
    glVertex2f(434, 475);
    
    glVertex2f(390, 430);
    glVertex2f(450, 500);
    glVertex2f(410, 465);
    
    glColor3f(0.137255, 0.556863, 0.419608); // less dark green
    
    glVertex2f(450, 500);
    glVertex2f(434, 475);
    glVertex2f(500, 498);
    
    /* tell OpenGL we're done drawing triangles */
    glEnd();
    
    // lines for the seagulls
    glColor3f(0, 0, 0); //set color to black
    glLineWidth(2.0);
    glBegin(GL_LINES);
    
    //seagull number one
    glVertex2f(630, 500);
    glVertex2f(635, 510);
    
    glVertex2f(630, 500);
    glVertex2f(625, 510);
    
    glVertex2f(635, 510);
    glVertex2f(665, 510);
    
    glVertex2f(665, 510);
    glVertex2f(670, 505);
    
    glVertex2f(625, 510);
    glVertex2f(595, 510);
    
    glVertex2f(595, 510);
    glVertex2f(590, 505);
    
    //seagull number two
    glVertex2f(660, 470);
    glVertex2f(665, 480);
    
    glVertex2f(660, 470);
    glVertex2f(655, 480);
    
    glVertex2f(665, 480);
    glVertex2f(695, 480);
    
    glVertex2f(695, 480);
    glVertex2f(700, 475);
    
    glVertex2f(655, 480);
    glVertex2f(625, 480);
    
    glVertex2f(625, 480);
    glVertex2f(620, 475);
    
    //seagull number three
    glVertex2f(700, 520);
    glVertex2f(705, 530);
    
    glVertex2f(705, 530);
    glVertex2f(735, 530);
    
    glVertex2f(735, 530);
    glVertex2f(740, 525);
    
    glVertex2f(700 ,520);
    glVertex2f(695, 530);
    
    glVertex2f(695, 530);
    glVertex2f(665, 530);
    
    glVertex2f(665, 530);
    glVertex2f(660, 525);

    glEnd();
    
    /* swap the back and front buffers */
    glutSwapBuffers();
}

/*! glut reshape callback function */
void reshape(int width, int height)
{
    /* display content in the window */
    glViewport(0,0,width,height);
    
    /* switch to the projection matrix */
    glMatrixMode(GL_PROJECTION);
    
    /* clear the projection matrix */
    glLoadIdentity();
    
    /* set the camera view, orthographic projection in 2D */
    gluOrtho2D(0,width,0,height);
    
    /* switch back to the model view matrix */
    glMatrixMode(GL_MODELVIEW);
}

