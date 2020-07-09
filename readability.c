#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main (void)
{
string text= get_string("Text: ") ;
int suma1=0 ;

for (int i=0 ; i < strlen(text) ; i++)
    {
        int skc ;
        if(text[i]<65)
        {
            skc = 0 ;
        }
        else if (text[i]>90 && text[i]<97)
        {
            skc = 0 ;
        }
        else if (text[i]>122 && text[i]<=127)
        {
            skc = 0 ;
        }
        else
        {
            skc = 1 ;
        }
    suma1 = suma1 + skc ;
    }

    //printf("Letters : %d\n", suma1) ;

int suma2=0;
int k=0 ;
while(k < strlen(text))
    {
        int zodis=0 ;
        if (text[k] == 32)
        {
            zodis = 1 ;
            k++ ;
        }
        else if ((text[k] == 46) || (text[k] == 33) || (text[k] == 63))
        {
            zodis = 1 ;
            k = k+2 ;
        }
        else
        {
            zodis = 0;
            k++ ;

        }
        suma2 = suma2 + zodis ;
    }

//printf("Words: %d\n", suma2) ;

int suma3=0;
int j=0;
while(j < strlen(text))
    {
        int sakinys=0;
        if ((text[j] == 46) || (text[j] == 33) || (text[j] == 63))
        {
            sakinys = 1 ;
            j++ ;
        }
        else
        {
            sakinys = 0 ;
            j++ ;
        }
        suma3 = suma3 + sakinys ;
    }

//printf("Sentence: %d\n", suma3) ;

double L;
L = suma1*100 /suma2 ;
double S;
S = suma3*100 / suma2 ;

int index ;
index = 0.0588 * L - 0.296 * S - 15.8 ;

printf("Grade %i\n", index );
}
