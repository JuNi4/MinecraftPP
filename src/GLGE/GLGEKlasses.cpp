#include "GLGEKlasses.h"

//include freeglut
#include <GL/freeglut.h>

/////////////
//KEY CLASS//
/////////////

Keys::Keys()
{
    //intialise the object
    //set all keys to false
    this->a = false;
    this->b = false;
    this->c = false;
    this->d = false;
    this->e = false;
    this->f = false;
    this->g = false;
    this->h = false;
    this->i = false;
    this->j = false;
    this->k = false;
    this->l = false;
    this->m = false;
    this->n = false;
    this->o = false;
    this->p = false;
    this->q = false;
    this->r = false;
    this->s = false;
    this->t = false;
    this->u = false;
    this->v = false;
    this->w = false;
    this->x = false;
    this->y = false;
    this->z = false;
}

//update a key
void Keys::keyUpdate(unsigned char key, bool status)
{
    //check if a should be updated
    if (key == (unsigned char)'a' || key == (unsigned char)'A')
    {
        this->a = status;
    }
    //check if b should be updated
    else if (key == (unsigned char)'b' || key == (unsigned char)'B')
    {
        this->b = status;
    }
    //check if c should be updated
    else if (key == (unsigned char)'c' || key == (unsigned char)'C')
    {
        this->c = status;
    }
    //check if d should be updated
    else if (key == (unsigned char)'d' || key == (unsigned char)'D')
    {
        this->d = status;
    }
    //check if e should be updated
    else if (key == (unsigned char)'e' || key == (unsigned char)'E')
    {
        this->e = status;
    }
    //check if f should be updated
    else if (key == (unsigned char)'f' || key == (unsigned char)'F')
    {
        this->f = status;
    }
    //check if g should be updated
    else if (key == (unsigned char)'g' || key == (unsigned char)'G')
    {
        this->g = status;
    }
    //check if h should be updated
    else if (key == (unsigned char)'h' || key == (unsigned char)'H')
    {
        this->h = status;
    }
    //check if i should be updated
    else if (key == (unsigned char)'i' || key == (unsigned char)'I')
    {
        this->i = status;
    }
    //check if j should be updated
    else if (key == (unsigned char)'j' || key == (unsigned char)'J')
    {
        this->j = status;
    }
    //check if k should be updated
    else if (key == (unsigned char)'k' || key == (unsigned char)'K')
    {
        this->k = status;
    }
    //check if l should be updated
    else if (key == (unsigned char)'l' || key == (unsigned char)'L')
    {
        this->l = status;
    }
    //check if m should be updated
    else if (key == (unsigned char)'m' || key == (unsigned char)'M')
    {
        this->m = status;
    }
    //check if n should be updated
    else if (key == (unsigned char)'n' || key == (unsigned char)'N')
    {
        this->n = status;
    }
    //check if o should be updated
    else if (key == (unsigned char)'o' || key == (unsigned char)'O')
    {
        this->o = status;
    }
    //check if p should be updated
    else if (key == (unsigned char)'p' || key == (unsigned char)'P')
    {
        this->p = status;
    }
    //check if q should be updated
    else if (key == (unsigned char)'q' || key == (unsigned char)'Q')
    {
        this->q = status;
    }
    //check if r should be updated
    else if (key == (unsigned char)'r' || key == (unsigned char)'R')
    {
        this->r = status;
    }
    //check if s should be updated
    else if (key == (unsigned char)'s' || key == (unsigned char)'S')
    {
        this->s = status;
    }
    //check if t should be updated
    else if (key == (unsigned char)'t' || key == (unsigned char)'T')
    {
        this->t = status;
    }
    //check if u should be updated
    else if (key == (unsigned char)'u' || key == (unsigned char)'U')
    {
        this->u = status;
    }
    //check if v should be updated
    else if (key == (unsigned char)'v' || key == (unsigned char)'V')
    {
        this->v = status;
    }
    //check if w should be updated
    else if (key == (unsigned char)'w' || key == (unsigned char)'W')
    {
        this->w = status;
    }
    //check if x should be updated
    else if (key == (unsigned char)'x' || key == (unsigned char)'X')
    {
        this->x = status;
    }
    //check if y should be updated
    else if (key == (unsigned char)'y' || key == (unsigned char)'Y')
    {
        this->y = status;
    }
    //check if z should be updated
    else if (key == (unsigned char)'z' || key == (unsigned char)'Z')
    {
        this->z = status;
    }
    //check if space should be updated
    else if (key == (unsigned char)' ')
    {
        this->space = status;
    }
}

//update a special key
void Keys::keyUpdate(int key, bool status)
{
    //check for the function keys
    //check for F1
    if (key == GLUT_KEY_F1)
    {
        this->f1 = status;
    }
    //check for F2
    else if (key == GLUT_KEY_F2)
    {
        this->f2 = status;
    }
    //check for F3
    else if (key == GLUT_KEY_F3)
    {
        this->f3 = status;
    }
    //check for F4
    else if (key == GLUT_KEY_F4)
    {
        this->f4 = status;
    }
    //check for F5
    else if (key == GLUT_KEY_F5)
    {
        this->f5 = status;
    }
    //check for F6
    else if (key == GLUT_KEY_F6)
    {
        this->f6 = status;
    }
    //check for F7
    else if (key == GLUT_KEY_F7)
    {
        this->f7 = status;
    }
    //check for F8
    else if (key == GLUT_KEY_F8)
    {
        this->f8 = status;
    }
    //check for F9
    else if (key == GLUT_KEY_F9)
    {
        this->f9 = status;
    }
    //check for F10
    else if (key == GLUT_KEY_F10)
    {
        this->f10 = status;
    }
    //check for F11
    else if (key == GLUT_KEY_F11)
    {
        this->f11 = status;
    }
    //check for F12
    else if (key == GLUT_KEY_F12)
    {
        this->f12 = status;
    } 
    //check for shift keys
    else if (key == GLUT_KEY_SHIFT_L)
    {
        this->leftShift = status;
        //check if the other shift key is pressed
        if (!this->rightShift)
        {
            this->shift = status;
        }
    }
    else if (key == GLUT_KEY_SHIFT_R)
    {
        this->rightShift = status;
        //check if the other shift key is pressed
        if (!this->leftShift)
        {
            this->shift = status;
        }
    }
    //check for arrow keys
    else if (key == GLUT_KEY_RIGHT)
    {
        this->arrowRight = status;
    }
    else if (key == GLUT_KEY_LEFT)
    {
        this->arrowLeft = status;
    }
    else if (key == GLUT_KEY_UP)
    {
        this->arrowUp = status;
    }
    else if (key == GLUT_KEY_DOWN)
    {
        this->arrowDown =status;
    }
}