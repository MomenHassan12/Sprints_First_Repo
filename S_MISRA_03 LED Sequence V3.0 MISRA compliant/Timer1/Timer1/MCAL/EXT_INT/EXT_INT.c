/*
 * CFile1.c
 *
 * Created: 4/6/2023 6:28:59 AM
 *  Author: Speed
 */ 
#include "EXT_INT.h"
INTERRUPT_ERROR_TYPE EXT_INT_Enable(EXInterruptSource_type interrupt)
{
	INTERRUPT_ERROR_TYPE error;
	if (interrupt > 2)
	{
		error = INVALID_INTERRUPT;
	}
	else
	{
		if (interrupt == EX_INT0)
		{
			SET_BIT(GICR, INT0);
			error = VALID_INTERRUPT;
		}
		else if (interrupt == EX_INT1)
		{
			SET_BIT(GICR, INT1);
			error = VALID_INTERRUPT;
		}
		else if (interrupt == EX_INT2)
		{
			SET_BIT(GICR, INT2);
			error = VALID_INTERRUPT;
		}
		else
		{
			error = INVALID_INTERRUPT;
		}
	}
	return error;
}

INTERRUPT_ERROR_TYPE EXT_INT_Disable(EXInterruptSource_type interrupt)
{
	INTERRUPT_ERROR_TYPE error;
	if (interrupt > 3)
	{
		error = INVALID_INTERRUPT;
	}
	else
	{
		if (interrupt == EX_INT0)
		{
			CLR_BIT(GICR, INT0);
			error = VALID_INTERRUPT;
		}
		else if (interrupt == EX_INT1)
		{
			CLR_BIT(GICR, INT1);
			error = VALID_INTERRUPT;
		}
		else if (interrupt == EX_INT2)
		{
			CLR_BIT(GICR, INT2);
			error = VALID_INTERRUPT;
		}
		else
		{
			error = INVALID_INTERRUPT;
		}
	}
	return error;
}

INTERRUPT_ERROR_TYPE EXT_INT_TriggerEdge(EXInterruptSource_type interrupt, TriggerEdge_type edge)
{
	INTERRUPT_ERROR_TYPE error = INVALID_INTERRUPT;

	if (interrupt > 3)
	{
		error = INVALID_INTERRUPT;
	}
	else
	{
		if (interrupt == EX_INT0)
		{
			if (edge > 4)
			{
				error = INVALID_TRIGGER_STATE;
			}
			else
			{
				if (edge == LOW_LEVEL)
				{
					CLR_BIT(MCUCR, ISC00);
					CLR_BIT(MCUCR, ISC01);
					error = VALID_TRIGGER_STATE;
				}
				else if (edge == ANY_LOGIC_CHANGE)
				{
					SET_BIT(MCUCR, ISC00);
					CLR_BIT(MCUCR, ISC01);
					error = VALID_TRIGGER_STATE;
				}
				else if (edge == FALLING_EDGE)
				{
					CLR_BIT(MCUCR, ISC00);
					SET_BIT(MCUCR, ISC01);
					error = VALID_TRIGGER_STATE;
				}
				else if (edge == RISING_EDGE)
				{
					SET_BIT(MCUCR, ISC00);
					SET_BIT(MCUCR, ISC01);
					error = VALID_TRIGGER_STATE;
				}
				else
				{
					error = INVALID_TRIGGER_STATE;
				}
			}
		}
		else if (interrupt == EX_INT1)
		{
			if (edge > 4)
			{
				error = INVALID_TRIGGER_STATE;
			}
			else
			{
				if (edge == LOW_LEVEL)
				{
					CLR_BIT(MCUCR, ISC10);
					CLR_BIT(MCUCR, ISC11);
					error = VALID_TRIGGER_STATE;
				}
				else if (edge == ANY_LOGIC_CHANGE)
				{
					SET_BIT(MCUCR, ISC10);
					CLR_BIT(MCUCR, ISC11);
					error = VALID_TRIGGER_STATE;
				}
				else if (edge == FALLING_EDGE)
				{
					CLR_BIT(MCUCR, ISC10);
					SET_BIT(MCUCR, ISC11);
					error = VALID_TRIGGER_STATE;
				}
				else if (edge == RISING_EDGE)
				{
					SET_BIT(MCUCR, ISC10);
					SET_BIT(MCUCR, ISC11);
					error = VALID_TRIGGER_STATE;
				}
				else
				{
					error = INVALID_TRIGGER_STATE;
				}
			}
		}
		else if (interrupt == EX_INT2)
		{
			if (edge > 4)
			{
				error = INVALID_TRIGGER_STATE;
			}
			else
			{
				if (edge == FALLING_EDGE)
				{
					CLR_BIT(MCUCSR, ISC2);
					error = VALID_TRIGGER_STATE;
				}
				else if (edge == RISING_EDGE)
				{
					SET_BIT(MCUCSR, ISC2);
					error = VALID_TRIGGER_STATE;
				}
				else
				{
					error = INVALID_TRIGGER_STATE;
				}
			}
		}
	}

	return error;
}

/*
	INTERRUPT_ERROR_TYPE EXT_INT_SetCallBack(EXInterruptSource_type interrupt, void (*pf_local)(void))
	{
		
		
		switch(interrupt)
		{
			case EX_INT0:
			ISR(EXT_INT_0)
			{
				pf_local();
			}
			break;
			
			case EX_INT1:
			ISR(EXT_INT_1)
			{
				pf_local();
			}
			break;
			
			case EX_INT2:
			ISR(EXT_INT_2)
			{
				pf_local();
			}
			break;
			
			default:
			error =INVALID_INTERRUPT;
			break;
		}
	}
		
		

*/