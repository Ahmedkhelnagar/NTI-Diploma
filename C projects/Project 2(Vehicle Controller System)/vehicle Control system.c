/**********************************************
 * 
 *                Libraries
 * 
**********************************************/
#include"vehicle.h"

/**********************************************
 * 
 *              Main function
 * 
**********************************************/
int main()
{
    int choice=0;
    while(choice!=3)
    {
        printf("Vehicle Control System Menu\n");
        printf("1.Turn On Vehicle Engine\n");
        printf("2.Turn Off Vehicle Engine\n");
        printf("3.Quit The System\n");
        printf("Enter Your Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                turnOnEngine();
                displaySystemState();
                break;
            case 2:
                turnOffEngine();
                displaySystemState();
                break;
            case 3:
                exitsystem();
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}


/*************************************************************
 * 
 *                 Function Definitions
 * 
**************************************************************/


/**********************************************
 * 
 *              TURN ON ENGINE 
 * 
**********************************************/
void turnOnEngine()
{
    engineState=1;

    while(engineState)
    {
        char trafficLight;
        printf("Sensors set menu\n");
        printf("a. Turn off the engine\n");
        printf("b. Set the traffic light color(G/O/R)\n");
        printf("c. Set the room temperature\n");
        printf("d. Set the engine temperature\n");

        printf("Enter the traffic light:\n");
        scanf(" %c",&trafficLight);
        printf("Enter the Room Temperature:\n");
        scanf("%f",&roomTemperature);
        printf("Enter the Engine Temperature:\n");
        scanf("%f",&engineTemp);
       

        /*Checking on Traffic light*/
        if(trafficLight=='G')
        {
            vehicleSpeed=100;
        }
        else if(trafficLight=='O')
        {
            vehicleSpeed=30;
        }
        else if(trafficLight=='R')
        {
            vehicleSpeed=0;
        }
        else
        {
            printf("Invalid Input");
        }

        /*Checking on Room Temerature*/
        if(roomTemperature <=10 || roomTemperature >30)
        {
            acState=1;
            roomTemperature=20;
        }
        else
        {
            acState=0;
        }

        /*Checking on Engine temperature*/
        if(engineTemp <=100 || engineTemp >150)
        {
            engineTempControlState=1;
            engineTemp=125;
        }
        else
        {
            engineTempControlState=0;
        }

        /*Checking if Vehicle Speed equal 30 or not*/
        if(vehicleSpeed==30)
        {   
            if(acState==0)
            {   
                acState=1;
                roomTemperature=(((float)roomTemperature*5)/4)+1.0;
            }
            if(engineTempControlState==0)
            {
                engineTempControlState=1;
                engineTemp=(((float)engineTemp*5)/4)+1.0;
            }
        }
        break;
    }
}

/**********************************************
 * 
 *               TURN OFF
 * 
**********************************************/
void turnOffEngine()
{
    engineState=0;
}

/**********************************************
 * 
 *               EXIT SYSYTEM
 * 
**********************************************/
void exitsystem()
{
    printf("Exit the system\n");
}

/**********************************************
 * 
 *            DISPLAY SYSTEM STATE
 * 
**********************************************/
void displaySystemState()
{
    printf("System State.\n");
    printf("Engine State: %s\n",engineState ? "ON":"OFF");
    printf("AC State: %s\n",acState ? "ON":"OFF");
    printf("Vehicle Speed: %d km/hr\n",vehicleSpeed);
    printf("Room Temperature: %.2f\n",roomTemperature);
    printf("Engine Temperature controller: %d\n",engineTempControlState);
    printf("Engine Temperature: %.2f\n",engineTemp);
    printf("\n");
}