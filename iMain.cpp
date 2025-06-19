#include "iGraphics.h"
#define screenwidth 1600
#define screenHight 800
/*
function iDraw() is called again and again by the system.
*/

struct buttnCordinate
{
    int x;
    int y;

} bCordinate[3];

char homemenu[20] = {"omi\\18.jpg"};

char instructions[20] = "omi\\details.jpg";
char play[20] = "omi\\obito.jpg";
char highestScore[20] = "omi\\ok.jpg";
char button[15][30] = {"image\\01.png", "image\\02.png", "image\\03.png"};

 char stand[20]="image\\11.png";


char run[15][20] = {"image\\18.png", "image\\2.png", "image\\3.png", "image\\4.png", "image\\5.png", "image\\6.png", "image\\7.png"};

char back[20] = "image\\back.png";
int gamestate = -1;

void iDraw()
{

    iClear();

    if (gamestate == -1)
    {
        iShowImage(0, 0, homemenu);

        for (int i = 0; i < 3; i++)
        {
             
            iShowImage(bCordinate[i].x, bCordinate[i].y, button[i]);
        }
    }

    else if (gamestate == 0)
    {

        iShowImage(0, 0, play);
        iShowImage(0, 740, back);


        }
        
       
    
    else if (gamestate == 1)
    {

        iShowImage(0, 0, instructions);
        iShowImage(0, 740, back);
    }
    else if (gamestate == 2)
    {

        iShowImage(0, 0, highestScore);
        iShowImage(0, 740, back);
    }

   
}
//
/*
function iMouseMove() is called when the user moves the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    // place your codes here
}

/*
function iMouseDrag() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseDrag(int mx, int my)
{
    // place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // place your codes here
        for (int i = 0; i < 3; i++)
        {
            if (mx >= bCordinate[i].x && mx <= bCordinate[i].x + 260 && my >= bCordinate[i].y && my <= bCordinate[i].y + 55)
            {
                gamestate = i;
            }
        }
        if (mx >= 0 && mx <= 0 + 52 && my >= 740 && my <= 740 + 56)
        {
            gamestate = -1;
        }
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        // place your codes here
    }
}

/*
function iMouseWheel() is called when the user scrolls the mouse wheel.
dir = 1 for up, -1 for down.
*/
void iMouseWheel(int dir, int mx, int my)
{
    // place your code here
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    switch (key)
    {
    case 'q':
        // do something with 'q'
        break;
    // place your codes for other keys here
    default:
        break;
    }
}

/*
function iSpecialKeyboard() is called whenver user hits special keys likefunction
keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11,
GLUT_KEY_F12, GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN,
GLUT_KEY_PAGE_UP, GLUT_KEY_PAGE_DOWN, GLUT_KEY_HOME, GLUT_KEY_END,
GLUT_KEY_INSERT */
void iSpecialKeyboard(unsigned char key)
{
    switch (key)
    {

    case GLUT_KEY_UP:
        // do something

        break;

    case GLUT_KEY_HOME:
        // do something

        break;
    case GLUT_KEY_RIGHT:
    {
    }
    break;

    // place your codes for other keys here
    default:
        break;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    // place your own initialization codes here.
    int sum = 200;
    for (int i = 0; i <3; i++)
    {
        bCordinate[i].x = 60;
        bCordinate[i].y = sum;
        sum -= 70;
    }

    iInitialize(screenwidth, screenHight, "Mahidul Omi");
    return 0;
}