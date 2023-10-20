
/**********************************************
 * 
 *               Libraries
 * 
**********************************************/
#include<stdio.h>
#include<stdlib.h>


/***********************************************
 * 
 *              Global Variables
 * 
************************************************/
int engineState=0;  //0 for OFF, 1 for ON
int acState=0;      //0 for OFF, 1 for ON
int vehicleSpeed=0;
float roomTemperature=0;
int engineTempControlState=0;
float engineTemp=0;

/**********************************************
 * 
 *              Function Prototypes
 * 
**********************************************/
void displaySystemState();
void turnOnEngine();
void turnOffEngine();
void exitsystem();