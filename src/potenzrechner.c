#include <stdlib.h> 
#include <stdio.h>  


int calculatePotenz (int Zahl1, int Zahl2);                                                                

int main(void) {
    
int Zahl1;
int Zahl2;
int Resultat;

  printf ("*****Powerfunktion*****\n\n");
   
  printf("Geben Sie die Basis ein:");
  scanf("%d", &Zahl1 );
  printf("\nGeben Sie das Exponent ein:");
  scanf("%d", &Zahl2 );
  Resultat = calculatePotenz(Zahl1, Zahl2);
  printf("\nResultat: %d\n\n", Resultat);
  system ("PAUSE"); 
  return (0);
}

int calculatePotenz (int Zahl1, int Zahl2){
 int Res=1;
     int i;
     int x;

  if (Zahl2 >= 0)
    {
     
        for(i=0; i<Zahl2; i++){
          Res=Res*Zahl1;}
    }
    else 
    {
    for(x=0; x>Zahl2; x--);{
        Res=Res/Zahl1;}
    }
    return(Res);
}