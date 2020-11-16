#include <stdio.h>
#include <sys/types.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

double funkcja(int x){
	
	return 4*x*x-6*x+5;
	
}

int main(){
	

	int p=3,pid,r,i;	//p - Potega liczby dwa, 2^3 

	float a,b,suma,srodek,wysokosc;
	float pom_przedzial, pom_a, pom_b;
	
	for(i = 0; i<p; i++){fork();} 
	

	
	srand(time(NULL) ^ getpid());
	r = rand()%8+2;
	i=0;
	a = rand()%5+1;
	b = rand()%10+10;
	pom_a = a;
	suma = 0;

	if(fork() == 0){ }
	
	else{
		
		pom_przedzial = (b-a)/r;
		pom_b = pom_a + pom_przedzial;
		for(i = 0; i<r; i++)
		{

			srodek = (pom_b + pom_a)/2;
			wysokosc = funkcja(srodek);
			suma = suma + wysokosc*pom_przedzial;

		}
				
		printf("Wynik calki to: %f, pid procesu: %d \n", suma, getpid() );

	}
	
	
	return 0;
}
