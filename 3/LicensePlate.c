/*
This program finds the pattern of license plate that gives the least excess plates made. This assumes that the location of the digit and letters are held constant for all the licenses made, like in license plates made in California.
*/
#include <stdio.h>

int pop; // population inputted by user
int totalplates=1; // number of total plates with pattern
int excessplates=0; // total plates less population
int number=0; // number of digits in pattern
int letter=0; // number of letters in pattern
int realtotalplates=1;
int realexcessplates=0;
int realnumber=0;
int realletter=0;

void addnum(){
        number = number + 1;
        totalplates = totalplates*10;
        excessplates = totalplates - pop;
        }
void removenum(){
        number = number - 1;
        totalplates = totalplates/10;
        excessplates = totalplates - pop;
        }

void addletter(){
        letter = letter + 1;
        totalplates = totalplates*26;
        excessplates = totalplates - pop;
        }
void assign(){
        realtotalplates = totalplates;
        realexcessplates = excessplates;
        realnumber = number;
        realletter = letter;
        }

void output(){
        printf("\nPopulation:\t %d\n", pop);
        printf("Pattern:\t %d letter(s) %d number(s)\n", realletter, realnumber);
        printf("Total Plates:\t %d\n", realtotalplates);
        printf("Excess Plates:\t %d\n", realexcessplates);
        }

int main(){
        // ask user how many in population
        printf("How many people in population? ");
        scanf("%d",&pop);

        while(pop > totalplates){
        //do this if there are not enough plates with pattern
        addnum();
        assign();
        }

        //take away 2 numbers and replace by letter
        while(number > 1){
        removenum();
        removenum();
        addletter();
        if(excessplates < realexcessplates && excessplates >= 0)
        //assign new best possible
        assign();
        }

        //add number if totalplates goes under population
        while(totalplates < pop){
        addnum();
        if(excessplates < realexcessplates && excessplates >= 0)
        //assign new best possible
        assign();
        }

        output();

return 0;
}
