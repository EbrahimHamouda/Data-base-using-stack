/*
 ============================================================================
 Name        : software_stack.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "sw_stack.h"
#include "test_cases.h"


#define MAX_STACK 6
#define MAX_DATA 6
#define N_PUSH 6
#define N_POP  1

gStrStack_t g_my_stk1;
gStrData_t BUFFER;

gStrData_t myData[MAX_DATA]= { // user input
{"mohamed",1,3.1},
{"ahmed",2,3.2},
{"mostafa",3,3.3},
{"khaled",4,3.4},
{"gamal",5,3.5},
{"ebrahim",6,3.6}
};

int main(void)
{
    create_stack(&g_my_stk1,MAX_STACK);
    test_push(N_PUSH,&g_my_stk1,myData);
    test_pop(N_POP,&g_my_stk1,&BUFFER);
    print_buffer(&BUFFER);
    return 0;
}
