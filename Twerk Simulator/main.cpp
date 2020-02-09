//
//  main.cpp
//  TwerkSimulator
//
//  Created by Logan Hoelscher on 9/16/19.
//  Copyright © 2019 Logan Hoelscher. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <GLUT/glut.h>
using namespace std;



/*! GLUT display callback function */
void display(void);
/*! GLUT window reshape callback function */
void reshape(int, int);

/*******************************************
 Initializing the arrays to hold the necessary
 control points of bCurve1 & bCurve2
 *******************************************/

int b1ctrl1x = 430;     //probably not necessary but i dont
int b1ctrl1y = 295;     //wanna change it back
int b1ctrl2x = 420;
int b1ctrl2y = 220;
int bCurve1[4][2]={{483,310},{b1ctrl1x,b1ctrl1y},{b1ctrl2x,b1ctrl2y},{486,212}};    //control points of left butt cheek
int array1[4];                                                  // (bCurve1)
int n = 3;

int b2ctrl1x = 460;
int b2ctrl1y = 280;
int b2ctrl2x = 455;
int b2ctrl2y = 220;
int bCurve2[4][2]={{490,302},{b2ctrl1x,b2ctrl1y},{b2ctrl2x,b2ctrl2y},{496,222}};    //control points of right butt cheek
int array2[4];                                                     // (bCurve2)
int m = 3;

/********************* End initialization **************************/

/*************************************
 This function makes the figure's butt
 bounce up and down (twerk)
 **************************************/
void processSpecialKeys(int key, int x, int y) {
    
    switch(key) {
        case GLUT_KEY_UP :          //if user presses up key
            bCurve1[1][0] = 415;    //reASSign the control points
            bCurve1[1][1] = 325;    //of bCurve1 & bCurve2
            bCurve1[2][0] = 400;
            bCurve1[2][1] = 240;
            
            bCurve2[1][0] = 445;
            bCurve2[1][1] = 300;
            bCurve2[2][0] = 435;
            bCurve2[2][1] = 240;
            break;
        case GLUT_KEY_DOWN :        // if user presses down key
            bCurve1[1][1] = 250;    //reassign the control points
            bCurve1[2][1] = 190;    // of bCurve1 & bCurve2
            
            bCurve2[1][0] = 440;
            bCurve2[1][1] = 250;
            bCurve2[2][0] = 435;
            bCurve2[2][1] = 210;
            break;
    }
    glutPostRedisplay();
}
/***************** End twerk function *************************************/




int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    
    /* set the window size */
    glutInitWindowSize(800, 600);
    
    /* set the display mode */
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    
    /* create the window */
    glutCreateWindow("Twerk Simulator");
    
    /* set the glut display callback function */
    glutDisplayFunc(display);
    
    /* set the glut reshape callback function */
    glutReshapeFunc(reshape);
    
    /* set the default background color to white */
    glClearColor(250,250,250,1);
    
    /* entry to process user input */
    glutSpecialFunc(processSpecialKeys);
    
   /*  main event loop */
    glutMainLoop();
    
    return 0;
}




/* glut display callback function */
void display()
{
    /* clear the color buffer */
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    /* This for loop computes the points of bCurve1*/
    int k,i;
    for(k=0; k<=n; k++)
    {
        array1[k] = 1;
        for(i = n; i >= k+1; i--)
            array1[k] *= i;
        for(i = n-k; i >= 2; i--)
            array1[k] /= i;
        
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    
    /*********************************
     This block of code contains the
     formula for calculating a bezier
     curve. Specifically for bCurve1
     *********************************/
    int p;
    float x,y,u,blend;
    
    for(u = 0; u < 1.0; u += 0.01)
    {
        x = 0;
        y = 0;
        for(p = 0; p < 4; p++)
        {
            blend = array1[p] * pow(u,p) * pow(1-u,n-p);
            x += bCurve1[p][0] * blend;
            y += bCurve1[p][1] * blend;
        }
        glVertex2f(x,y);
        
    }
    glEnd();
    
    /***********************End code for bCurve1*****************************/
    
    
    
    
    /* Another for loop to compute the points of bCurve2*/
    int q,j;
    for(q = 0; q <= n; q++)
    {
        array2[q] = 1;
        for(j = n; j >= q+1; j--)
            array2[q] *= j;
        for(j = n-q; j >= 2; j--)
            array2[q] /= j;
    }
    
    
    
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    
    /*********************************
     This block of code contains the
     formula for calculating a bezier
     curve. Specifically for bCurve2
     *********************************/
    int p2;
    float x2,y2,u2,blend2;
    
    for(u2 = 0; u2 < 1.0; u2 += 0.01)
    {
        x2 = 0;
        y2 = 0;
        for(p2 = 0; p2 < 4; p2++)
        {
            blend2 = array2[p2] * pow(u2,p2) * pow(1-u2,m-p2);
            x2 += bCurve2[p2][0] * blend2;
            y2 += bCurve2[p2][1] * blend2;
        }
        glVertex2f(x2,y2);
        
    }
    glEnd();
    
    /******************** End code for bCurve2 ******************************/
    
    
    
    /***************************
     
     this is where the fun begins
     
     ***************************/
    
    
    /* set color to black*/
    glColor3f(0, 0, 0);
    
    glLineWidth(3.0);
    glBegin(GL_LINES);
    
    //first quadrant of head
    glVertex2f(605, 560);
    glVertex2f(612, 558);
    
    glVertex2f(612, 558);
    glVertex2f(615, 556);
    
    glVertex2f(615, 556);
    glVertex2f(618, 554);
    
    glVertex2f(618, 554);
    glVertex2f(621, 552);
    
    glVertex2f(621, 552);
    glVertex2f(625, 548);
    
    glVertex2f(625, 548);
    glVertex2f(628, 544);
    
    glVertex2f(628, 544);
    glVertex2f(631, 540);
    
    glVertex2f(631, 540);
    glVertex2f(634, 534);
    
    glVertex2f(634, 534);
    glVertex2f(636, 530);
    
    glVertex2f(636, 530);
    glVertex2f(638, 526);
    
    glVertex2f(638, 526);
    glVertex2f(640, 518);
    
    glVertex2f(640, 518);
    glVertex2f(642, 508);
    
    glVertex2f(642, 508);
    glVertex2f(642, 496);
    
    //second quadrant of head
    glVertex2f(642, 496);
    glVertex2f(641, 490);
    
    glVertex2f(641, 490);
    glVertex2f(640, 486);
    
    glVertex2f(640, 486);
    glVertex2f(639, 480);
    
    glVertex2f(639, 480);
    glVertex2f(637, 474);
    
    glVertex2f(637, 474);
    glVertex2f(635, 470);
    
    glVertex2f(635, 470);
    glVertex2f(633, 466);
    
    glVertex2f(633, 466);
    glVertex2f(631, 462);
    
    glVertex2f(631, 462);
    glVertex2f(629, 460);
    //break for hand
    glVertex2f(610, 440);
    glVertex2f(602, 437);
    
    glVertex2f(602, 437);
    glVertex2f(596, 436);       //neck area
    
    glVertex2f(596, 436);
    glVertex2f(590, 435);
    
    glVertex2f(590, 435);
    glVertex2f(578, 435);
    
    //third quadrant of head
    glVertex2f(578, 435);
    glVertex2f(574, 437);
    
    glVertex2f(574, 437);
    glVertex2f(569, 439);
    
    glVertex2f(569, 439);
    glVertex2f(565, 442);
    
    glVertex2f(565, 442);
    glVertex2f(560, 445);       //neck area
    
    glVertex2f(560, 445);
    glVertex2f(556, 450);
    
    glVertex2f(556, 450);
    glVertex2f(552, 455);
    
    glVertex2f(552, 455);
    glVertex2f(548, 462);
    
    glVertex2f(548, 462);
    glVertex2f(544, 468);
    
    glVertex2f(544, 468);
    glVertex2f(542, 475);
    
    glVertex2f(542, 475);
    glVertex2f(540, 483);
    
    glVertex2f(540, 483);
    glVertex2f(539, 491);
    
    glVertex2f(539, 491);
    glVertex2f(539, 510);
    
    //fourth quadrant of head
    glVertex2f(539, 510);
    glVertex2f(540, 515);
    
    glVertex2f(540, 515);
    glVertex2f(542, 522);
    
    glVertex2f(542, 522);
    glVertex2f(544, 530);
    
    glVertex2f(544, 530);
    glVertex2f(547, 536);
    
    glVertex2f(547, 536);
    glVertex2f(550, 542);
    
    glVertex2f(550, 542);
    glVertex2f(553, 547);
    
    glVertex2f(553, 547);
    glVertex2f(558, 553);
    
    glVertex2f(558, 553);
    glVertex2f(567, 559);
    
    glVertex2f(567, 559);
    glVertex2f(577, 563);
    
    glVertex2f(577, 563);
    glVertex2f(588, 562);
    
    glVertex2f(588, 562);
    glVertex2f(600, 562);
    
    glVertex2f(600, 562);
    glVertex2f(605, 561);
    
    glVertex2f(605, 561);
    glVertex2f(605, 560);
    
    /* 50 segments total for head */
    
    //face segments
    //left eye
    glVertex2f(565, 530);
    glVertex2f(568, 529);
    
    glVertex2f(568, 529);
    glVertex2f(572, 531);
    
    glVertex2f(572, 531);
    glVertex2f(574, 530);
    
    glVertex2f(574, 530);
    glVertex2f(578, 529);
    
    glVertex2f(578, 529);
    glVertex2f(582, 527);
    
    glVertex2f(582, 527);
    glVertex2f(583, 522);
    
    glVertex2f(583, 522);
    glVertex2f(578, 518);
    
    glVertex2f(578, 518);
    glVertex2f(571, 516);
    
    glVertex2f(571, 516);
    glVertex2f(563, 517);
    
    glVertex2f(563, 517);
    glVertex2f(560, 518);
    
    glVertex2f(560, 518);
    glVertex2f(556, 520);
    
    glVertex2f(556, 520);
    glVertex2f(555, 523);
    
    glVertex2f(555, 523);
    glVertex2f(557, 526);
    
    glVertex2f(557, 526);
    glVertex2f(562, 528);
    
    glVertex2f(562, 528);
    glVertex2f(565, 530);
    
    //right eye
    glVertex2f(616, 530);
    glVertex2f(609, 529);
    
    glVertex2f(609, 529);
    glVertex2f(602, 528);
    
    glVertex2f(602, 528);
    glVertex2f(600, 527);
    
    glVertex2f(600, 527);
    glVertex2f(598, 525);
    
    glVertex2f(598, 525);
    glVertex2f(597, 521);
    
    glVertex2f(597, 521);
    glVertex2f(599, 519);
    
    glVertex2f(599, 519);
    glVertex2f(604, 517);
    
    glVertex2f(604, 517);
    glVertex2f(609, 516);
    
    glVertex2f(609, 516);
    glVertex2f(614, 517);
    
    glVertex2f(614, 517);
    glVertex2f(620, 519);
    
    glVertex2f(620, 519);
    glVertex2f(624, 522);
    
    glVertex2f(624, 522);
    glVertex2f(625, 527);
    
    glVertex2f(625, 527);
    glVertex2f(623, 529);
    
    glVertex2f(623, 529);
    glVertex2f(620, 530);
    
    glVertex2f(620, 530);
    glVertex2f(616, 530);
    
    //smile
    glVertex2f(576, 490);
    glVertex2f(578, 485);
    
    glVertex2f(578, 485);
    glVertex2f(581, 482);
    
    glVertex2f(581, 482);
    glVertex2f(585, 480);
    
    glVertex2f(585, 480);
    glVertex2f(589, 479);
    
    glVertex2f(589, 479);
    glVertex2f(593, 480);
    
    glVertex2f(593, 480);
    glVertex2f(599, 483);
    
    glVertex2f(599, 483);
    glVertex2f(602, 486);
    
    glVertex2f(602, 486);
    glVertex2f(604, 488);
    
    /* 38 total face segments */
    
    //body
    glVertex2f(560, 445);
    glVertex2f(563, 435);
    
    glVertex2f(563, 435);
    glVertex2f(564, 425);
    
    glVertex2f(564, 425);
    glVertex2f(564, 410);
    
    glVertex2f(564, 410);
    glVertex2f(562, 400);
    
    glVertex2f(562, 400);
    glVertex2f(561, 395);
    
    glVertex2f(561, 395);
    glVertex2f(560, 390);
    
    glVertex2f(560, 390);
    glVertex2f(556, 380);
    
    glVertex2f(556, 380);
    glVertex2f(552, 370);
    
    glVertex2f(552, 370);
    glVertex2f(546, 362);
    
    glVertex2f(546, 362);
    glVertex2f(540, 354);
    
    glVertex2f(540, 354);
    glVertex2f(532, 344);
    
    glVertex2f(532, 344);
    glVertex2f(522, 336);
    
    glVertex2f(522, 336);
    glVertex2f(512, 328);
    
    glVertex2f(512, 328);
    glVertex2f(502, 322);
    
    glVertex2f(502, 322);
    glVertex2f(494, 318);
    
    glVertex2f(494, 318);
    glVertex2f(483, 310);   //bezier curve1 start
    
    //lower left leg
    glVertex2f(486, 212);   //bezier curve1 end
    glVertex2f(492, 208);
    
    glVertex2f(492, 208);
    glVertex2f(498, 204);
    
    glVertex2f(498, 204);
    glVertex2f(506, 200);
    
    glVertex2f(506, 200);
    glVertex2f(514, 196);
    
    glVertex2f(514, 196);
    glVertex2f(520, 190);
    
    glVertex2f(520, 190);
    glVertex2f(524, 182);
    
    glVertex2f(524, 182);
    glVertex2f(528, 172);
    
    glVertex2f(528, 172);
    glVertex2f(530, 162);
    
    glVertex2f(530, 162);
    glVertex2f(531, 150);
    
    glVertex2f(531, 150);
    glVertex2f(529, 138);
    
    glVertex2f(529, 138);
    glVertex2f(527, 128);
    
    glVertex2f(527, 128);
    glVertex2f(525, 118);
    
    //right leg
    glVertex2f(496, 222);   //bezier curve2 end point
    glVertex2f(504, 218);
    
    glVertex2f(504, 218);
    glVertex2f(510, 214);
    
    glVertex2f(510, 214);
    glVertex2f(518, 208);
    
    glVertex2f(518, 208);
    glVertex2f(528, 202);
    
    glVertex2f(528, 202);
    glVertex2f(534, 194);
    
    glVertex2f(534, 194);
    glVertex2f(540, 186);
    
    glVertex2f(540, 186);
    glVertex2f(548, 176);
    
    glVertex2f(548, 176);
    glVertex2f(550, 170);
    
    glVertex2f(550, 170);
    glVertex2f(552, 162);
    
    glVertex2f(552, 162);
    glVertex2f(553, 154);
    
    glVertex2f(553, 154);
    glVertex2f(554, 144);
    
    glVertex2f(554, 144);
    glVertex2f(555, 134);
    
    glVertex2f(555, 134);
    glVertex2f(554, 124);
    
    glVertex2f(554, 124);
    glVertex2f(553, 116);
    
    //crack
    glVertex2f(490, 302);       //bezier curve2 start point
    glVertex2f(494, 304);
    
    glVertex2f(494, 304);
    glVertex2f(498, 306);
    
    glVertex2f(498, 306);
    glVertex2f(504, 308);
    
    glVertex2f(504, 308);
    glVertex2f(508, 312);
    
    //right side of neck
    glVertex2f(602, 437);
    glVertex2f(600, 433);
    
    glVertex2f(600, 433);
    glVertex2f(598, 429);
    
    glVertex2f(598, 429);
    glVertex2f(596, 415);
    
    /* 50 total leg segments */
    
    //arm
    glVertex2f(596, 415);
    glVertex2f(592, 418);
                            //
    glVertex2f(592, 418);   //  left side of right side of neck (arm)
    glVertex2f(588, 419);   //
    
    glVertex2f(596, 415);
    glVertex2f(600, 410);
    
    glVertex2f(600, 410);
    glVertex2f(603, 402);
    
    glVertex2f(603, 402);
    glVertex2f(604, 340);
    
    glVertex2f(604, 340);
    glVertex2f(607, 334);
    
    glVertex2f(607, 334);
    glVertex2f(610, 330);
    
    glVertex2f(610, 330);
    glVertex2f(618, 326);
    
    glVertex2f(618, 326);
    glVertex2f(626, 325);
    
    glVertex2f(626, 325);
    glVertex2f(630, 330);
    
    glVertex2f(630, 330);
    glVertex2f(632, 338);
    
    glVertex2f(632, 338);
    glVertex2f(634, 348);
    
    glVertex2f(634, 348);
    glVertex2f(636, 368);
    
    glVertex2f(636, 368);
    glVertex2f(638, 398);
    
    glVertex2f(638, 398);
    glVertex2f(636, 408);
    
    glVertex2f(636, 408);
    glVertex2f(632, 418);
    
    glVertex2f(632, 418);
    glVertex2f(628, 426);
    
    glVertex2f(628, 426);
    glVertex2f(626, 430);
    
    glVertex2f(626, 430);
    glVertex2f(624, 432);
    
    glVertex2f(624, 432);
    glVertex2f(620, 436);
    
    glVertex2f(620, 436);
    glVertex2f(610, 440);
    
    glVertex2f(610, 440);
    glVertex2f(602, 448);
    
    glVertex2f(602, 448);
    glVertex2f(600, 452);
    
    glVertex2f(600, 452);
    glVertex2f(599, 455);
    
    glVertex2f(599, 455);
    glVertex2f(601, 460);
    
    glVertex2f(601, 460);
    glVertex2f(606, 465);
    
    glVertex2f(606, 465);
    glVertex2f(614, 468);
    
    glVertex2f(614, 468);
    glVertex2f(622, 464);
    
    glVertex2f(622, 464);
    glVertex2f(629, 460);
    
    glVertex2f(629, 460);
    glVertex2f(632, 455);
    
    glVertex2f(632, 455);
    glVertex2f(636, 450);
    
    glVertex2f(636, 450);
    glVertex2f(644, 440);
    
    glVertex2f(644, 440);
    glVertex2f(652, 425);
    
    glVertex2f(652, 425);
    glVertex2f(658, 410);
    
    glVertex2f(658, 410);
    glVertex2f(660, 390);
    
    glVertex2f(660, 390);
    glVertex2f(661, 368);
    
    glVertex2f(661, 368);
    glVertex2f(659, 350);
    
    glVertex2f(659, 350);
    glVertex2f(657, 338);
    
    glVertex2f(657, 338);
    glVertex2f(654, 326);
    
    glVertex2f(654, 326);
    glVertex2f(648, 314);
    
    glVertex2f(648, 314);
    glVertex2f(640, 308);
    
    glVertex2f(640, 308);
    glVertex2f(632, 304);
    
    glVertex2f(632, 304);
    glVertex2f(624, 302);
    
    glVertex2f(624, 302);
    glVertex2f(614, 305);
    
    glVertex2f(614, 305);
    glVertex2f(606, 308);
    
    glVertex2f(606, 308);
    glVertex2f(600, 312);
    
    glVertex2f(600, 312);   //*********************
    glVertex2f(594, 316);   //rest of body start here
                            //***********************
    glVertex2f(594, 316);
    glVertex2f(588, 322);
    
    glVertex2f(588, 322);
    glVertex2f(585, 328);
    
    glVertex2f(585, 328);
    glVertex2f(583, 340);
    
    glVertex2f(583, 340);
    glVertex2f(581, 360);
    
    glVertex2f(581, 360);
    glVertex2f(580, 390);
    
    glVertex2f(580, 390);
    glVertex2f(578, 410);
    
    glVertex2f(578, 410);
    glVertex2f(581, 415);
    
    glVertex2f(581, 415);
    glVertex2f(583, 415);
    
    glVertex2f(583, 415);
    glVertex2f(588, 419);
    
    /* 56 total arm segments */
    
    //rest of body
    glVertex2f(594, 316);
    glVertex2f(590, 308);
    
    glVertex2f(590, 308);
    glVertex2f(584, 300);
    
    glVertex2f(584, 300);
    glVertex2f(574, 290);
    
    glVertex2f(574, 290);
    glVertex2f(564, 275);
    
    glVertex2f(564, 275);
    glVertex2f(558, 265);
    
    glVertex2f(558, 265);
    glVertex2f(552, 255);
    
    glVertex2f(552, 255);
    glVertex2f(549, 245);
    
    glVertex2f(549, 245);
    glVertex2f(548, 240);
    
    glVertex2f(548, 240);
    glVertex2f(551, 235);
    
    glVertex2f(551, 235);
    glVertex2f(556, 228);
    
    glVertex2f(556, 228);
    glVertex2f(566, 212);
    
    glVertex2f(566, 212);
    glVertex2f(578, 196);
    
    glVertex2f(578, 196);
    glVertex2f(582, 182);
    
    glVertex2f(582, 182);
    glVertex2f(584, 172);
    
    glVertex2f(584, 172);
    glVertex2f(586, 135);
    
    glVertex2f(586, 135);
    glVertex2f(584, 120);
    
    /* 16 segments for rest of body */
    
    /* 210 segements total (u can count em if u want :-) */
    glEnd();
        
    /* swap the back and front buffers */
    glutSwapBuffers();
}

/*! glut reshape callback function */
void reshape(int width, int height)
{
   /* display contents within window */
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

