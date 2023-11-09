/*
 * Ping Pong.c
 *
 *
 * Author: AhmedKhaled
 */

#include"ping_pong_interface.h"

/*********************Global variables*************************/

/*position of player 1*/
u8 player1_x=0;
u8 player1_y=0;

/*position of player 2*/
u8 player2_x=0;
u8 player2_y=19;

/*position of the ball*/
u8 ball_x=0;
u8 ball_y=1;

/*Scores of Player 1 and player 2*/
u8 score1=0;
u8 score2=0;

/*********************Function Definitions***********************/

/****************************************************
 *
 * 				Function Left to Right
 *
 ****************************************************/
void left_To_Right(void)
{
	for(ball_y=1;ball_y<=19;ball_y++)
	{
		if(ball_y==19)
		{
			LCD_GoTo(3, 4);
			LCD_WriteNumber(score1);
			break;
		}
		LCD_Clear();

		LCD_GoTo(3, 1);
		LCD_WriteString("P1:          P2:");

		/*Printing Player 1*/
		LCD_GoTo(player1_x,0);
		LCD_WriteChar(0);

		/*Printing Player 2*/
		LCD_GoTo(player2_x,19);
		LCD_WriteChar(0);

		/*Printing score1*/
		LCD_GoTo(3, 4);
		LCD_WriteNumber(score1);

		/*Printing score2*/
		LCD_GoTo(3, 17);
		LCD_WriteNumber(score2);

		/*Checking on the scores*/
		if( (ball_y==18) && (ball_x !=player2_x ))
		{
			score1++;
		}
		else{}


		/*Printing the ball*/
		LCD_GoTo(ball_x,ball_y);
		LCD_WriteChar(1);
		_delay_ms(250);
		LCD_ClearPosition(ball_x,ball_y,1);

		/*Up player 1*/
		if(DIO_ReadPin(PIND6)==0)
		{
			LCD_GoTo(player1_x, 0);
			LCD_WriteChar(' ');
			_delay_ms(400);

			if(player1_x==0)
			{
				player1_x=3;
			}

			player1_x--;

			LCD_GoTo(player1_x, 0);
			LCD_WriteChar(0);
		}
		/*down player1*/
		else if(DIO_ReadPin(PIND7)==0)
		{
			LCD_GoTo(player1_x, 0);
			LCD_WriteChar(' ');
			_delay_ms(400);

			player1_x++;

			if(player1_x==3)
			{
				player1_x=0;
			}


			LCD_GoTo(player1_x, 0);
			LCD_WriteChar(0);
		}

		/*down player 2*/
		else if(DIO_ReadPin(PIND3)==0)
		{
			LCD_GoTo(player2_x,19);
			LCD_WriteChar(' ');
			_delay_ms(400);

			player2_x++;

			if(player2_x==3)
			{
				player2_x=0;
			}

			LCD_GoTo(player2_x, 19);
			LCD_WriteChar(0);
		}

		/*up player 2*/
		else if(DIO_ReadPin(PIND5)==0)
		{
			LCD_GoTo(player2_x,19);
			LCD_WriteChar(' ');
			_delay_ms(400);

			if(player2_x==0)
			{
				player2_x=3;
			}

			player2_x--;

			LCD_GoTo(player2_x, 19);
			LCD_WriteChar(0);
		}


		/*Down Ball*/
		else if(DIO_ReadPin(PINA3)==0)
		{
			LCD_GoTo(ball_x, ball_y);
			LCD_WriteChar(' ');
			_delay_ms(400);

			ball_x++;

			if(ball_x==3)
			{
				ball_x=0;
			}

			LCD_GoTo(ball_x,ball_y);
			LCD_WriteChar(1);
		}

		/*Up Ball*/
		else if(DIO_ReadPin(PINA2)==0)
		{
			LCD_GoTo(ball_x, ball_y);
			LCD_WriteChar(' ');
			_delay_ms(400);

			if(ball_x==0)
			{
				ball_x=3;
			}

			ball_x--;

			LCD_GoTo(ball_x,ball_y);
			LCD_WriteChar(1);
		}
		else{}

		if(score1==3 || score2==3)
		{
			_delay_ms(500);
			pingpong_end();
		}
		else{}

	}/*End of for loop 1*/

}/*End of the function*/



/****************************************************
 *
 * 				Function Right to left
 *
 ****************************************************/
void Right_To_Left(void)
{
	for(ball_y=17;ball_y>0;ball_y--)
	{
		if(ball_y==0)
		{
			LCD_GoTo(3, 17);
			LCD_WriteNumber(score2);
			break;
		}
		LCD_Clear();

		LCD_GoTo(3, 1);
		LCD_WriteString("P1:          P2:");

		/*Printing score1*/
		LCD_GoTo(3, 4);
		LCD_WriteNumber(score1);

		/*Printing score2*/
		LCD_GoTo(3, 17);
		LCD_WriteNumber(score2);

		/*Printing Player1*/
		LCD_GoTo(player1_x,0);
		LCD_WriteChar(0);
		/*Printing Player 2*/
		LCD_GoTo(player2_x,19);
		LCD_WriteChar(0);

		/*Checking on the scores*/
		if( (ball_y==1) && (ball_x !=player1_x ))
		{
			score2++;
		}
		else{}


		/*Printing the ball*/
		LCD_GoTo(ball_x,ball_y);
		LCD_WriteChar(1);
		_delay_ms(250);
		LCD_ClearPosition(ball_x,ball_y,1);

		/*Up player 1*/
		if(DIO_ReadPin(PIND6)==0)
		{
			LCD_GoTo(player1_x, 0);
			LCD_WriteChar(' ');
			_delay_ms(400);

			if(player1_x==0)
			{
				player1_x=3;
			}

			player1_x--;

			LCD_GoTo(player1_x, 0);
			LCD_WriteChar(0);
		}
		/*down player1*/
		else if(DIO_ReadPin(PIND7)==0)
		{
			LCD_GoTo(player1_x, 0);
			LCD_WriteChar(' ');
			_delay_ms(400);

			player1_x++;

			if(player1_x==3)
			{
				player1_x=0;
			}


			LCD_GoTo(player1_x, 0);
			LCD_WriteChar(0);
		}

		/*down player 2*/
		else if(DIO_ReadPin(PIND3)==0)
		{
			LCD_GoTo(player2_x,19);
			LCD_WriteChar(' ');
			_delay_ms(400);

			player2_x++;

			if(player2_x==3)
			{
				player2_x=0;
			}

			LCD_GoTo(player2_x, 19);
			LCD_WriteChar(0);
		}

		/*up player 2*/
		else if(DIO_ReadPin(PIND5)==0)
		{
			LCD_GoTo(player2_x,19);
			LCD_WriteChar(' ');
			_delay_ms(400);

			if(player2_x==0)
			{
				player2_x=3;
			}

			player2_x--;

			LCD_GoTo(player2_x, 19);
			LCD_WriteChar(0);
		}


		/*Down Ball*/
		else if(DIO_ReadPin(PINA3)==0)
		{
			LCD_GoTo(ball_x, ball_y);
			LCD_WriteChar(' ');
			_delay_ms(400);

			ball_x++;

			if(ball_x==3)
			{
				ball_x=0;
			}

			LCD_GoTo(ball_x,ball_y);
			LCD_WriteChar(1);
		}

		/*Up Ball*/
		else if(DIO_ReadPin(PINA2)==0)
		{
			LCD_GoTo(ball_x, ball_y);
			LCD_WriteChar(' ');
			_delay_ms(400);

			if(ball_x==0)
			{
				ball_x=3;
			}

			ball_x--;

			LCD_GoTo(ball_x,ball_y);
			LCD_WriteChar(1);
		}
		else{}

		if(score1==3 || score2==3)
		{
			_delay_ms(500);
			pingpong_end();
		}
		else{}
	}/*End of for loop2*/

}/*End of Function*/


/****************************************************
 *
 * 				Function pingpong_Init
 *
 ****************************************************/
void pingpong_Init()
{
	LCD_Clear();
	LCD_GoTo(1, 1);
	LCD_WriteString("Welcome to My Game");
	LCD_GoTo(2, 5);
	LCD_WriteString("Ping Pong");
	_delay_ms(1500);
	LCD_GoTo(1, 1);
	LCD_WriteString("                  ");
	LCD_GoTo(2, 1);
	LCD_WriteString("                  ");
}


/****************************************************
 *
 * 				Function pingpong_end
 *
 ****************************************************/
void pingpong_end(void)
{
	LCD_Clear();
	LCD_GoTo(1, 3);
	LCD_WriteString("Game Over!!");
	_delay_ms(1000);
	LCD_Clear();
	LCD_GoTo(1, 5);
	LCD_WriteString("The winner is");
	LCD_GoTo(2, 5);
	if(score1 > score2)
	{
		LCD_WriteString("Player 1");
	}
	else
	{
		LCD_WriteString("Player 2");
	}
	_delay_ms(1500);
	pingpong_Init();
	score1=0;
	score2=0;
	ball_x=0;
	ball_y=1;
	player1_x=0;
	player1_y=0;
	player2_x=0;
	player2_y=19;
}

/****************************************************
 *
 * 				Main Function
 *
 ****************************************************/
int main(void)
{
	DIO_Init();
	LCD_Init();
	pingpong_Init();

	/*Player*/
	u8 player[] = {0x04,0x04,0x0E,0x15,0x04,0x0A,0x11,0x00};
	LCD_CustomChar(0,player);

	/*Ball*/
	u8 ball[] = {0x0E,0x0E,0x0E,0x00,0x00,0x00,0x00,0x00};
	LCD_CustomChar(1,ball);


    while(1)
    {
    	left_To_Right();
    	Right_To_Left();
    }/*end of while loop*/

    return 0;
}

