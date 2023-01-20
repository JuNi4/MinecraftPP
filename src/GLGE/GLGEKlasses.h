/**
 * @file GLGEKlasses.h
 * @author DM8AT
 * @brief create all needed classes for default GLGE
 * @version 0.1
 * @date 2022-12-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _GLGE_KLASSES_H_
#define _GLGE_KLASSES_H_

/**
 * @brief a Keys object stores all pressed keys
 */
class Keys
{
public:
    //create a bool for all letters in the alphabet
    bool a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    //create a bool for all special keys
    bool f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12, space, leftShift, rightShift, leftAlt, rightAlt, shift, alt, arrowRight, arrowLeft, arrowUp, arrowDown;

    /**
     * @brief Construct a new Keys 
     * default constructor
     */
    Keys();

    /**
     * @brief update a key in the keys variable
     * 
     * @param key the key to update
     * @param status the status to set the key to
     */
    void keyUpdate(unsigned char key, bool status);

    /**
     * @brief update a special key
     * 
     * @param key the key to update
     * @param status the new status for the key
     */
    void keyUpdate(int key, bool status);
};

#endif