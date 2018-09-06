#include<conio.h>
#include<stdio.h>
int main()
{
	int j1,j2,result,j1_now=0,j2_now=0;
	printf("enter mesurement of jugs \n");		//j1 >j2
	scanf("%d  %d",&j1,&j2);
	printf("enter the amount of water to find \n");
	scanf("%d",&result);
	printf("RULES TO FOLLOW WATER JUG PROBLEM.\n");
	printf("1.\t(X,Y | X<%d)(%d,Y)		\t{Fill %d -gallon jug}\n\n",j1,j1,j1);
	printf("2.\t(X,Y |Y<%d)(X,%d) 		\t{Fill %d -gallon jug}\n\n",j2,j2,j2);
	printf("3.\t(X,Y |X>0)(0,Y)   		\t{Empty %d -gallon jug}\n\n",j1);
	printf("4.\t(X,Y | Y>0)(X,0)  		\t{Empty %d -gallon jug}\n\n",j2);
	printf("5.\t(X,Y | X+Y>=%d ^ Y>0)(%d,Y-(%d-X))  \t{Pour water from %d -gallon jug into %d -gallon jug until %d-gallon jug is full}\n\n",j1,j1,j1,j2,j1,j1);
	printf("6.\t(X,Y | X+Y>=%d ^X>0)(X-(%d-Y),%d)   \t{Pour water from %d -gallon jug into %d -gallon jug until %d-gallon jug is full}\n\n",j2,j2,j2,j1,j2,j2);
	printf("7.\t(X,Y | X+Y<=%d ^Y>0)(X+Y,0)	\t{Pour all water from %d -gallon jug into %d -gallon jug}\n\n",j1,j2,j1);
	printf("8.\t(X,Y | X+Y <=%d^ X>0)(0,X+Y)	\t{Pour all water from %d -gallon jug into %d -gallon jug}\n\n",j2,j1,j2);
	printf("9.\t(0,%d)(%d,0)			\t{Pour %d gallon water from %d gallon jug into %d gallon jug}\n\n",result,result,result,j2,j1);	
	
	printf("Gallons in 4-Gallon Jug  Gallons in 3-Gallon Jug   Rules Applied \n");
	printf(" \t %d \t \t \t %d \t \t \t -\n",j1_now,j2_now);
	while(j1_now!=result || j2_now!=result)
	{
		if(j1_now==0){
			if(j1_now!=0 && j2_now!=0){
				printf(" \t %d \t \t \t %d \t \t \t 8\n",j1_now,j2_now);
			}
			j1_now=j1;			//fill j1
			printf(" \t %d \t \t \t %d \t \t \t 1\n",j1_now,j2_now);
		}	
		if(j1_now>j2){
			j1_now=j1_now-(j2-j2_now); //fill water form j1 to j2
			j2_now=j2;
		}					
		else{
			j2_now=j1_now;
			j1_now=0;
		}
		if(j2_now==j2){
			printf(" \t %d \t \t \t %d \t \t \t 6\n",j1_now,j2_now);
			j2_now=0;
			printf(" \t %d \t \t \t %d \t \t \t 4 \n",j1_now,j2_now);
		}
		if(j1_now==result || j2_now==result)		//to break out of loop
		{
			break;
		}
	}
	printf("done");
	
	return(0);
}
