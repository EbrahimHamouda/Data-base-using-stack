/*
 * sw_stack.h
 *
 *  Created on: Jun 30, 2018
 *      Author: hossam.adel
 */

#ifndef SW_STACK_H_
#define SW_STACK_H_
#include "common.h"

typedef enum
{
	NO_ERRORS = 0,
	INVALID_PARAMTERS = 5,
	STACK_FULL=6,
	STACK_EMPTY=7,
	INTERNAL_MEM_ERROR=8,
}genum_sw_stack_error_t;

typedef struct
{
	/*USER IMP */
	char name[100];
	int salary;
	double GPA;
}gStrData_t;

typedef struct
{
	void* p_stack;
	ecore_u8 u8_max_size;
	ecore_u8 current_stack_size;
}gStrStack_t;



genum_sw_stack_error_t create_stack(gStrStack_t * p_stk , ecore_u8 max_size);

/*
 *	in[p_stack] :
 *  in[p_data]
 *
 */
genum_sw_stack_error_t sw_push(gStrStack_t * p_stk ,gStrData_t * p_data);
/*
 *	in[p_stack] :
 *  out[p_data]
 *
 */
genum_sw_stack_error_t sw_pop(gStrStack_t * p_stk ,gStrData_t * p_data);


#endif /* SW_STACK_H_ */
