//
//  main.c
//  advent_1_0
//
//  Created by Macik Mravec on 01.12.2023.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, const char * argv[]) {
    
    int sum = 0;
    FILE *f = fopen("/Users/macik/Desktop/adventOfCode/2023/advent_1_0/advent_1_0/input", "r");
    if(f == NULL)
    {
        printf("jsi kar-- not opened file\n");
        exit(99);
    }
    int c = '\0';
    
    char * line = malloc(100);
    
    while (1) {
        int numOfColumns = 0;
        while ((c = getc(f)) != EOF && c!= '\n' )
        {
            if(c != -1)
                line[numOfColumns] = c;
            numOfColumns++;
        }
        int foundNum = 0;
        line[numOfColumns] = '\0';
        if(c == EOF)
        {
            printf("sum %d\n",sum);
            return 0;
        }
        printf("line in %s\n",line);
        //last digit
        /**
            
            four = ruof
            seven = neves
         */
        for (int i = numOfColumns;i>=0; i--)
        {
            switch (line[i]) {
                case 'e':
                    if(line[i-1] == 'n' && line[i-2] == 'o')
                    {
                        sum +=1;
                        goto found;
                    }
                    else if (line[i-1] == 'n' && line[i-2] == 'i' && line[i-3] == 'n')
                    {
                        sum+=9;
                        goto found;
                    }
                    else if (line[i-1] == 'v' && line[i-2] == 'i' && line[i-3] == 'f')
                    {
                        sum+=5;
                        goto found;
                    }
                    else if (line[i-1] == 'e' && line[i-2] == 'r' && line[i-3] == 'h' && line[i-4] == 't')
                    {
                        sum+=3;
                        goto found;
                    }
                    break;
                case 't':
                    if (line[i-1] == 'h' && line[i-2] == 'g' && line[i-3] == 'i' && line[i-4] == 'e')
                    {
                        sum+=8;
                        goto found;
                    }
                    break;
                    
                case 'x':
                    if(line[i-1] == 'i' && line[i-2] == 's')
                    {
                        sum +=6;
                        goto found;
                    }
                    break;
                
                case 'o':
                    if(line[i-1] == 'w' && line[i-2] == 't')
                    {
                        sum +=2;
                        goto found;
                    }
                    break;
                case 'r':
                    if (line[i-1] == 'u' && line[i-2] == 'o' && line[i-3] == 'f')
                    {
                        sum+=4;
                        goto found;
                    }
                    break;
                case 'n':
                    if (line[i-1] == 'e' && line[i-2] == 'v' && line[i-3] == 'e' && line[i-4] == 's')
                    {
                        sum+=7;
                        goto found;
                    }
                    break;
                default:
                    break;
            }
            if(isdigit(line[i]))
            {
                sum += (line[i] - '0');
                break;
            }
        }
      
found:
        printf("first %d\n",sum);
        //find first num
        for (int i = 0; i < numOfColumns; i++)
        {
            switch (line[i]) {
                case 'o':
                    if (line[i+1] == 'n' && line[i+2] == 'e')
                    {
                        sum+=10;
                        foundNum++;
                        goto found2;
                    }
                break;
                case 't':
                    if (line[i+1] == 'w' && line[i+2] == 'o')
                    {
                        sum+=20;foundNum++;
                        goto found2;
                    }
                    if (line[i+1] == 'h' && line[i+2] == 'r' && line[i+3] == 'e' && line[i+4] == 'e')
                    {
                        sum+=30;
                        foundNum++;
                        goto found2;
                    }
                case 'f':
                    if (line[i+1] == 'o' && line[i+2] == 'u' && line[i+3] == 'r')
                    {
                        sum+=40;
                        foundNum++;
                        goto found2;
                    }
                    if (line[i+1] == 'i' && line[i+2] == 'v' && line[i+3] == 'e')
                    {
                        sum+=50;
                        foundNum++;
                        goto found2;
                    }
                case 's':
                    if (line[i+1] == 'i' && line[i+2] == 'x')
                    {
                        sum+=60;
                        foundNum++;
                        goto found2;
                    }
                    if (line[i+1] == 'e' && line[i+2] == 'v' && line[i+3] == 'e' && line[i+4] == 'n')
                    {
                        sum+=70;
                        foundNum++;
                        goto found2;
                    }
                case 'e':
                    if (line[i+1] == 'i' && line[i+2] == 'g' && line[i+3] == 'h' && line[i+4] == 't')
                    {
                        sum+=80;
                        foundNum++;
                        goto found2;
                    }
                case 'n':
                    if (line[i+1] == 'i' && line[i+2] == 'n' && line[i+3] == 'e')
                    {
                        sum+=90;
                        foundNum++;
                        goto found2;
                    }
            }
            if(isdigit(line[i]))
            {
                sum += (line[i] - '0')*10;

                break;
            }
        found2:
            if(foundNum >0)
                break;
        }
        printf("second %d\n",sum);
   
    }
    
    
    
    return 0;
}
