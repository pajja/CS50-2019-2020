#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image \n") ;
        return 1 ;
    }

    FILE *fr = fopen(argv[1], "r") ;
    FILE *fw = NULL ;

    if (!fr)
    {
        printf("Error: files are not in JPEG format \n") ;
        return 1 ;
    }

    int count = 0 ;

    char filename[MAX];
    unsigned char number[MAX] ;

    bool start = false ;

    while (fread(number, MAX, 1, fr) == 1)
    {
        if (number[0] == 0xff && number[1] == 0xd8 && number[2] == 0xff
        && (number[3] &0xf0) == 0xe0)
        {

            if (start == true)
            {
                fclose(fw) ;
            }

            start = true ;

            sprintf(filename, "%03i.jpg", count) ;
            fw = fopen (filename, "w") ;

            count++ ;
        }

        if (start == true)
        {
            fwrite(&number, MAX, 1, fw) ;
        }
    }

    fclose(fr) ;
    fclose(fw) ;

    return 0 ;
}
