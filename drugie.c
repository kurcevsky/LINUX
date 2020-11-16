#include <stdio.h>
#include <sys/types.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
double funkcja(int n)
{
    double suma = 0;
    for(int i=1;i<=n;i++)
        {
            suma += pow(-1,i-1)/(2*i-1);

        }
return 4*suma;
}


int main()
{
    srand(time(NULL));
    int n,i,p = 2;

    for  (i=0;i<p;i++)
    {
    if (fork () != 0)
            {
                printf ("Jestem rodzicem, moj pid = %d \n",getpid() );
                n = rand()%4900+101;
                printf("Wylosowane N: %d\n",n);
                printf("Przyblizenie pi: %f\n",funkcja(n));
            }
        else
            {
                printf ("Ja potomek, moj pid = %d \n", getpid());
                printf ("Pid rodzica = %d \n",getppid());
                n = rand()%4900+101;
                printf("Wylosowane N: %d\n",n);
                printf("Przyblizenie pi: %f\n",funkcja(n));
    }
    }
return 0;
}
