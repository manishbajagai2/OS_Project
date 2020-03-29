#include<stdio.h>
#include<unistd.h>
/* 
	P = Number of Resources of same type you have
	Q = Number of Processes
	sum = Addition of P and Q for Second condition
	res = Number of Resources you need
	sres= Maximum need of Resources
*/
int main(){
	int P,Q,sum=0,sres=0;
    printf("\t\t Enter the no. of Resources you have : "); 
    printf("\n");
    printf("\t\t\t\t");
    scanf("%d", &P);
    printf("\t\t Enter the number of Processes : ");
    printf("\n");
    printf("\t\t\t\t");
    scanf("%d", &Q);
    sum=P+Q;
    
	int i=0;
	while(i < Q)
    {
        int res;
        printf("\t Enter the number Resources you need : ");
    	printf("\t");
        scanf("%d", &res);
        sres=sres+res;

        if(res < 1)
        {
            printf("Since max need of resources is between 1 and P, \n");
            printf(" The system is not in a safe state \n");
            return 0;
        }

        else if((res > P) || (sres > sum)) // Due to the given Constraints
        {
            printf("\n\n Since summation of all maximum need of resources is not less than P+Q ;\n");
            printf("So, the system is not in a safe state.\n");
            printf("Deadlock occurs \n\n");
            return 0;
        }
        else
        {
            P = P - res; // Using Bankers' Algorithm 
            printf("\n Process Succesfully executed \n");
            printf("Since the system is in safe state.\n");
            printf("Available Resources remaining is %d ", P); 
            printf("\n");

            P = P + res;
            printf("Resources allocated \n\n");
        }
    ++i;
    }

    return 0;
}
