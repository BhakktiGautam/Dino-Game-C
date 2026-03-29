#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
int main()
{
srand(time(0));
while(1)
{
int dinoX=5;
int dinoY=0;
int isDucking = 0;
int obstacleH[3] = {1,1,1};
int obstacleX[3];
obstacleX[0] = 50;
obstacleX[1] = 70;
obstacleX[2] = 90;
int obstacleY=0;
int velocity =0;
int isJumping= 0;
int score =0;
int gameover=0;
	while(gameover==0)
	{

		 // INPUT
		if(kbhit())//kbhit() → checks if key is pressed
		   //igetch() → reads key instantly
		{		
		int key=getch();
		if(key == 224)
    		{
      		  key = getch();

       	        if(key == 80)   // DOWN ARROW
       	        {
           	    isDucking = 1;
       	        }
   	 }

		else if(key==' ' && dinoY==0)
		{
			isJumping=1;
			velocity=3;
		}
	}
		else
		{
   			 isDucking = 0;   // reset duck when no key
		}		

	// JUMP LOGIC
	if(isJumping==1)
	{
		dinoY=dinoY+velocity;
		velocity=velocity-1;
		if(dinoY<=0)
		{
			dinoY=0;
			isJumping=0;
		}
	}
 	//OBSTACLE MOVE 
	for(int k=0; k<3; k++)
	{
   		 obstacleX[k]--;

    	if(obstacleX[k] < 0)
	{
    		obstacleX[k] = 50 + rand()%20;
    		obstacleH[k] = 1 + rand()%2;   // height = 1 or 2
	}
}
system("cls");
printf("Dino game\n");
printf("Score : %d\n",score);
for(int i=0;i<10;i++)
{
	for(int j=0;j<60;j++)
	{
		int printed=0;
		if(i==(9-dinoY)&&j==dinoX)
		{
			printf("D");
			printed=1;
		}

		// OBSTACLES
                   for(int k=0;k<3;k++)
		   {
   			 for(int h=0; h<obstacleH[k]; h++)
   		   {
      		         if(i == 9-h && j == obstacleX[k])
        		{
            			printf("|");
           		        printed = 1;
       			 }
   		 }
	}
		// GROUND / EMPTY
                    if(!printed)
                    {
                        if(i==9)
                            printf("_");
                        else
                            printf(" ");
                    }
                }
                printf("\n");
            }
		//COLLISION CHECK
		for(int k=0;k<3;k++)
		{
   			 if(obstacleH[k] == 1)   // small obstacle
    		{
     		         if(obstacleX[k] == dinoX && dinoY == 0)
         	         gameover = 1;
  	        }
  		    	else   // tall obstacle
   	      {
      			  if(obstacleX[k] == dinoX && isDucking == 0)
           		 gameover = 1;
    		}
	}



		//SCORE
		score++;
		//SPPED INCREASE 
		int speed =50-score/10;
		if(speed<10) speed=10;
		Sleep(speed);
	

}
printf("\nGAME OVER! FINAL SCORE: %d\n", score);
printf("Press R to Restart or any key to Exit\n");

char choice = getch();
if(choice=='r' || choice=='R')
{
    continue;   // restart game
}
else
{
    break;      // exit program
}
}
return 0;
}
