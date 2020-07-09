#include <cs50.h>
#include <stdio.h>

int main(void)
{
       int height ;
   
    do
    {
    printf ("What's the height: \n") ;
    scanf ("%d", &height) ;
    }
    while (height<1 || height>8) ;
    
    for (int i=1; i<=height; i++)
    {
        for (int m=height; m>i; m--)
        {
            printf(" ");
        }
        for (int z=1; z<=i; z++)
        {
            printf("#");
            
         }
        printf ("\n") ;        
        
    }
    
    return 0 ;
  
}
