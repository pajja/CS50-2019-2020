#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv [])
{
    if (argc != 2)
    {
        printf ("Usage: ./caesar key\n") ;

        return 1 ;
    }
    int aa = atoi(argv[1]) ;
    if (aa<0)
    {
        printf ("Usage: ./caesar key\n") ;

        return 1 ;
    }

    string sentence = get_string ("Text: ") ;
    char letter ;


     for (int i=0 ; i<strlen(sentence) ; i++)
     {

        letter =  sentence[i] + atoi (argv[1]) ;
        if (sentence[i]<=122 && sentence[i]>=97 && letter>122)
        {
            letter =letter-26 ;
        }
        if (sentence[i]<=90 && sentence[i]>=65 && letter>90)
        {
            letter =letter-26 ;
        }
        if (sentence[i]<65 || sentence[i]>122)
        {
            letter = sentence[i] ;
        }
        if (sentence[i]>90 && sentence[i]<97)
        {
            letter = sentence[i] ;
        }
        printf ("%c" , letter );
    }
    printf ("\n");

    return 0 ;
}
