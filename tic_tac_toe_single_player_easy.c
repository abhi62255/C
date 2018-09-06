#include<conio.h>
#include<stdio.h>
char matrix[3][3],first[30],second[30];
int i,j,input_val,move[10],m=0;
int check()
{
	if(matrix[0][0]==88 && matrix[0][1]==88 && matrix[0][2]==88 || matrix[0][0]==79 && matrix[0][1]==79 && matrix[0][2]==79){
		return(1);
	}
	else if(matrix[1][0]==88 && matrix[1][1]==88 && matrix[1][2]==88 || matrix[1][0]==79 && matrix[1][1]==79 && matrix[1][2]==79){
		return(1);
	}
	else if(matrix[2][0]==88 && matrix[2][1]==88 && matrix[2][2]==88 || matrix[2][0]==79 && matrix[2][1]==79 && matrix[2][2]==79){
		return(1);
	}
	else if(matrix[0][0]==88 && matrix[1][0]==88 && matrix[2][0]==88 || matrix[0][0]==79 && matrix[1][0]==79 && matrix[2][0]==79){
		return(1);
	}
	else if(matrix[0][1]==88 && matrix[1][1]==88 && matrix[2][1]==88 || matrix[0][1]==79 && matrix[1][1]==79 && matrix[2][1]==79){
		return(1);
	}
	else if(matrix[0][2]==88 && matrix[1][2]==88 && matrix[2][2]==88 || matrix[0][2]==79 && matrix[1][2]==79 && matrix[2][2]==79){
		return(1);
	}
	else if(matrix[0][0]==88 && matrix[1][1]==88 && matrix[2][2]==88 || matrix[0][0]==79 && matrix[1][1]==79 && matrix[2][2]==79){
		return(1);
	}
	else if(matrix[2][0]==88 && matrix[1][1]==88 && matrix[0][2]==88 || matrix[2][0]==79 && matrix[1][1]==79 && matrix[0][2]==79){
		return(1);
	}
	else{
		return(0);
	}
}
int display()
{
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf(" %c  ",matrix[i][j]);
			if(j!=2){printf("|");}
		}
		if(i!=2){printf("\n----|----|----\n");}
	}
	return(0);
}
int input(int val,int in)
{
	switch(val)
	{
		case 1:
			matrix[0][0]=in;
			break;
		case 2:
			matrix[0][1]=in;
			break;
		case 3:
			matrix[0][2]=in;
			break;
		case 4:
			matrix[1][0]=in;
			break;
		case 5:
			matrix[1][1]=in;
			break;
		case 6:
			matrix[1][2]=in;
			break;
		case 7:
			matrix[2][0]=in;
			break;
		case 8:
			matrix[2][1]=in;
			break;
		case 9:
			matrix[2][2]=in;
			break;
		default:
			printf("invalid input");
			break;
			
	}
}
int easy_decision()
{
	srand(time(NULL));   // should only be called once
    int val = rand() % 10;      // returns a pseudo-random integer between 0 and RAND_MAX	
	return(val);
}
int main()
{
	//matrix[0][0]=79;
	//matrix[0][2]=88;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf(" %c  ",matrix[i][j]);
			if(j!=2){printf("|");}
		}
		if(i!=2){printf("\n----|----|----\n");}
	}
	printf("\n");
	printf("Enter name of first player \n");
	scanf("%s",first);
	printf("\n ( X ) : Symbol Assigned to You \n \n");
	printf("Enter name of second player \n");
	scanf("%s",second);
	printf("\n ( O ) : Symbol Assigned to You \n \n");
	
	printf("let's Start THE GAME \n \n");
	
	while(1)
	{
		back:
		printf("\n %s Your Turn ( X )\n INPUT : ",first);
		scanf("%d",&input_val);
		if(input_val==0){
			printf("Invalid Input");
			goto back;
		}
		for(i=0;i<9;i++)
		{
			if(move[i]==input_val){
				printf("ERROR \n THIS INPUT HAS ALREADY TAKEN*****RETRY \n");
				goto back;
			}
		}
		if(!(input_val==1||input_val==2||input_val==3||input_val==4||input_val==5||input_val==6||input_val==7||input_val==8||input_val==9)){
				printf("\n Invalid Input. \n");
				goto back;
			}
		move[m]=input_val;
		m=m+1;
		input(input_val,88);
		display();
		if(check()){
			printf("\n %s ******WINNER***** \n INPUT : ",first);	
			break;
		}
		if(m==9)
		{
			printf("\n ****DRAW****");
			break;
		}
		
		
		back_1:
		printf("\n %s Your Turn ( O ) \n INPUT : ",second);
		input_val=easy_decision();
		printf("\n");
		if(input_val==0){
		//	printf("Invalid Input");
			goto back_1;
		}
		for(i=0;i<9;i++)
		{
			if(move[i]==input_val){
			//	printf("ERROR \n THIS INPUT HAS ALREADY TAKEN*****RETRY \n");
				goto back_1;
			}
		}
		if(!(input_val==1||input_val==2||input_val==3||input_val==4||input_val==5||input_val==6||input_val==7||input_val==8||input_val==9)){
			//	printf("\n Invalid Input. \n");
				goto back_1;
			}
		move[m]=input_val;
		m=m+1;
		input(input_val,79);
		display();
		if(check()){
			printf("\n %s ******WINNER***** \n INPUT : ",second);	
			break;
		}	
	}
	return(0);
}









