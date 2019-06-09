#include <stdio.h>
#include <stdlib.h>
#include "sw_stack.h"
#include "test_cases.h"



void test_push(int n_push,gStrStack_t* p_stk,gStrData_t* p_data)
{
    int i;

    for(i=0; i<n_push; i++)
    {
        int test_var = sw_push(p_stk,&p_data[i]);

        switch(test_var)
        {
        case 0 :
        {
            printf("push [%d] :NO_ERRORS \n",i+1);
            break;
        }
        case 5:
        {
            printf("push [%d] :INVALID_PARAMTERS\n",i+1);
            break;
        }
        case 6:
        {
            printf("push [%d] :STACK_FULL\n",i+1);
            break;
        }
        case 7:
        {
            printf("push [%d] :STACK_EMPTY\n",i+1);
            break;
        }
        case 8:
        {
            printf("push [%d] :INTERNAL_MEM_ERROR\n",i+1);
            break;
        }
        default:
        {
            printf("push [%d] :UNKNOWN_ERROR\n",i+1);
            break;
        }
        }
    }
}

void test_pop(int n_pop,gStrStack_t* p_stk,gStrData_t* p_data)
{
    int i;

    for(i=0; i<n_pop; i++)
    {
        int test_var = sw_pop(p_stk,p_data);

        switch(test_var)
        {
        case 0 :
        {
            printf("pop  [%d] :NO_ERRORS \n",i+1);
            break;
        }
        case 5:
        {
            printf("pop  [%d] :INVALID_PARAMTERS\n",i+1);
            break;
        }
        case 6:
        {
            printf("pop  [%d] :STACK_FULL\n",i+1);
            break;
        }
        case 7:
        {
            printf("pop  [%d] :STACK_EMPTY\n",i+1);
            break;
        }
        case 8:
        {
            printf("pop  [%d] :INTERNAL_MEM_ERROR\n",i+1);
            break;
        }
        default:
        {
            printf("pop  [%d] :UNKNOWN_ERROR\n",i+1);
            break;
        }
        }
    }
}

void print_buffer(gStrData_t* p_buffer)
{
    printf("name:%s\n",p_buffer->name);
    printf("salary:%d\n",p_buffer->salary);
    printf("GPA:%0.2f\n",p_buffer->GPA);
    printf("\n");
}
