#include <stdio.h>
#include<math.h>
#include <cs50.h>
int main()
{
    float money ;
    money = get_float("Chage owned: ") ;
      
    int cents = round(money*100) ;
         
    if (cents/25>0)
    {
        int m25=cents/25.00 ;
        int m_liekana1=cents%25 ;
            printf ("number of $0.25 coins: %d", m25);
            printf("\n");
        if (m_liekana1>0)
            {int m10=m_liekana1/10;
             int m_liekana2=m_liekana1%10;
                printf ("number of $0.10 coins: %d", m10);
                printf("\n");
            if (m_liekana2>0)
               {int m5=m_liekana2/5;
                int m_liekana3=m_liekana2%5;
                    printf ("number of $0.05 coins: %d", m5);
                    printf ("\n");
                if (m_liekana3>0)
                    {int m1=m_liekana3/1;
                        printf ("number of $0.01 coins: %d", m1);
                        printf ("\n");
                    }
                }
            }
        }
        
    
    
    return 0 ;    
}
