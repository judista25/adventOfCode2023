//
//  main.c
//  advent_2_0
//
//  Created by Macik Mravec on 04.12.2023.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define NUM_OF_LINES 100
#define LEN_OF_ROW 100

int main(int argc, const char * argv[]) {
    FILE *f = fopen("/Users/macik/Desktop/adventOfCode/2023/advent_2_0/advent_2_0/input", "r");
    if(f == NULL)
    {
        printf("jsi kar-- not opened file\n");
        exit(99);
    }
//    fseek (f, 0, SEEK_END);
//    size_t length = ftell(f);
//    fseek (f, 0, SEEK_SET);
    // 100 lines of input rdy
   // char ** tempFile = malloc(sizeof(char*) * NUM_OF_LINES);
//    int len = 0,lineNum = 0;
//    char c;
//    while ((c=fgetc(f))!=EOF)
//    {
//        len = 0;
//        //length of line capped at 100
//        tempFile[lineNum] = malloc(LEN_OF_ROW);
//        while (c != '\n') {
//            tempFile[lineNum][len] = c;
//            len++;
//            c=fgetc(f);
//        }
//        tempFile[lineNum][len] = '\0';
//        lineNum++;
//    }
    int sum = 0;
    int power = 0;
    for (int i = 0; true; i++)
    {
        int index = 0;
        int count = 0;
        
        int blue = 0;
        int green = 0;
        int red = 0;
        
        int maxblue = 0;
        int maxgreen = 0;
        int maxred = 0;
        char * color = malloc(10);
        char * game = malloc(10);
        //printf("%s\n",tempFile[i]);
        if(fscanf(f, "%s %d:",game,&index)!= 2)
            break;
        bool notValid = true;
        bool endOfGame = false;
        while (fscanf(f, " %d %s",&count,color)==2) {
            size_t end = strlen(color) -1;
            if(color[end] == ';')
            {
                endOfGame = true;
                color[end] = '\0';
            }
            else if(color[end] == ',')
            {
                color[end] = '\0';
            }
            if(!strcmp(color,"red"))
            {
                    red +=count;
            }
            else if(!strcmp(color,"blue"))
            {
                    blue+=count;
            }
            else if(!strcmp(color,"green"))
            {
                green+=count;
            }
            if(endOfGame)
            {
                if(red >12 || green>13 || blue >14)
                    notValid = false;
                if(red > maxred)
                    maxred = red;
                if(green > maxgreen)
                    maxgreen = green;
                if(blue > maxblue)
                    maxblue = blue;
                green = blue = red = 0;
                endOfGame = false;
            }
        }
        if(red > 12 || green>13 || blue >14)
            notValid = false;
        if(red > maxred)
            maxred = red;
        if(green > maxgreen)
            maxgreen = green;
        if(blue > maxblue)
            maxblue = blue;
        green = blue = red = 0;
        endOfGame = false;
        if(notValid)
            sum+=index;
        
        power += maxred * maxblue *maxgreen;

        printf("sum = %d\n",sum);
    }
    printf("RES: %d Powwaaa : %d\n",sum,power);
    return 0;
}
