#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define WIDTH 50
#define HEIGHT 10
#define OBSTACLES 3
int main()
{
srand(time(0));
while(1)
{
int dinoX=5;
int dinoY=0;
int isDucking = 0;
int isJumping= 0;
int velocity=0;
int score =0;
int gameover=0;
 int obstacleX[OBSTACLES];
        int obstacleH[OBSTACLES];
        for(int k = 0; k < OBSTACLES; k++) {
            obstacleX[k] = WIDTH + k * 20;
            obstacleH[k] = 1 + rand() % 2;
        }
	while(!gameover)
	{

		 // INPUT
		if(kbhit())           //kbhit() → checks if key is pressed
		   		      //igetch() → reads key instantly
		{		
		int key=getch();
			// JUMP LOGIC
 if(key == 224) { // Arrow keys
        key = getch();
        if(key == 80) { 
              isDucking = 1;
                    }
                }
 else if(key == ' ' && dinoY == 0) {  // SPACE to jump
                    isJumping = 1;
                    velocity = 3;
                }
            } else {
                isDucking = 0;
            }

       
	if(isJumping)
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
	for(int k=0; k<OBSTACLES; k++)
	{ 
   		 obstacleX[k]--;

    	if(obstacleX[k] < 0)
	{
    		obstacleX[k] = WIDTH + rand()%20;
    		obstacleH[k] = 1 + rand()%2;   // height = 1 or 2
	}
}
system("cls");
printf("Dino game|Score:%d\n",score);
printf("Score : %d\n",score);
for(int i=0;i<HEIGHT;i++)
{
	for(int j=0;j<WIDTH;j++)
	{
		int printed=0;
		if(i==(HEIGHT-1-dinoY)&&j==dinoX)
		{
			printf("D");
			printed=1;
		}

		// OBSTACLES
                   for(int k=0;k<OBSTACLES;k++)
		   {
   			 for(int h=0; h<obstacleH[k]; h++)
   		   {
      		         if(i ==HEIGHT-1-h && j == obstacleX[k])
        		{
            			printf("|");
           		        printed = 1;
       			 }
   		 }
	}
		// GROUND / EMPTY
                    if(!printed)
                    {
                        if(i==HEIGHT-1)
                            printf("_");
                        else
                            printf(" ");
                    }
                }
                printf("\n");
            }
		//COLLISION CHECK
		for(int k=0;k<OBSTACLES;k++)
		{
   			 if(obstacleX[k] == dinoX)   
    		{
     		         if(obstacleH[k] == 1 && dinoY == 0)
         	         gameover = 1;
  	      
      			  if(obstacleH[k] == 2&& !isDucking)
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
if(choice!='r' && choice!='R')
{
    break;
}
return 0;
}
}


       
	
	
