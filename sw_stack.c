/*
 * sw_stack.c
 *
 *  Created on: Jun 30, 2018
 *      Author: hossam.adel
 */
#include "common.h"
#include "sw_stack.h"
#include <stdlib.h>

typedef struct node
{
	gStrData_t node_data;
	struct node * next;
}str_node_t;


static bool_t ecore_mem_copy(ecore_u8*des, ecore_u8*src, ecore_u16 size)
{
    bool_t b_ret_val = E_TRUE;

    if((des != NULL) && (src != NULL) && (size != 0))
    {
        while(size--)
        {
            *des = *src;
            des++;
            src++;
        }
    }
    else
    {
        b_ret_val =  E_FALSE;
    }
    return b_ret_val;
}

genum_sw_stack_error_t create_stack(gStrStack_t * p_stk, ecore_u8 max_size)
{
    genum_sw_stack_error_t b_ret_val = NO_ERRORS;

    if((p_stk != NULL) && (max_size != 0) )
    {
        p_stk->p_stack = NULL;
        p_stk->current_stack_size = 0;
        p_stk->u8_max_size = max_size;
    }
    else
    {
        b_ret_val = INVALID_PARAMTERS;
    }

    return b_ret_val;
}


/*
 *	in[p_stack] :
 *  in[p_data]
 *
 */
genum_sw_stack_error_t sw_push(gStrStack_t * p_stk,gStrData_t * p_data)
{
    genum_sw_stack_error_t b_ret_val = NO_ERRORS;


    if((p_stk != NULL) && (p_data != NULL) )
    {
        if(p_stk->current_stack_size < p_stk->u8_max_size)
        {
            str_node_t * pn = (str_node_t*)malloc(sizeof(str_node_t));
            bool_t ret = ecore_mem_copy((ecore_u8*)&pn->node_data, (ecore_u8*)p_data, sizeof(gStrData_t));
#ifdef DEBUG
            int test_v =pn->node_data.x;
            printf("size of sizeof(gStrData_t) :%d",sizeof(gStrData_t));
#endif // DEBUG

            if(ret == E_TRUE)
            {
                pn->next = (str_node_t*)p_stk->p_stack;
                p_stk->p_stack = (void*)pn;
                p_stk->current_stack_size++;
            }
            else
            {
                b_ret_val = INTERNAL_MEM_ERROR;
            }
        }
        else
        {
            b_ret_val = STACK_FULL;
        }

    }
    else
    {
        b_ret_val = INVALID_PARAMTERS;
    }

    return b_ret_val;
}

/*
 *	in[p_stack] :
 *  out[p_data]
 *
 */
genum_sw_stack_error_t sw_pop(gStrStack_t * p_stk,gStrData_t * p_data)
{
    genum_sw_stack_error_t b_ret_val = NO_ERRORS;

    if((p_stk != NULL) && (p_data != NULL))
    {
        if(p_stk->current_stack_size > 0 )
        {
            bool_t ret = ecore_mem_copy((ecore_u8*)p_data,(ecore_u8*)&(((str_node_t*)p_stk->p_stack)->node_data), sizeof(gStrData_t));
            if(ret == E_TRUE)
            {
                str_node_t *pn = (str_node_t*)p_stk->p_stack;
                p_stk->p_stack = (void*)pn->next;
                free(pn);
                p_stk->current_stack_size--;
            }
            else
            {
                b_ret_val = INTERNAL_MEM_ERROR;
            }
        }
        else
        {
            b_ret_val = STACK_EMPTY;
        }
    }
    else
    {
        b_ret_val = INVALID_PARAMTERS;
    }

    return b_ret_val;
}
