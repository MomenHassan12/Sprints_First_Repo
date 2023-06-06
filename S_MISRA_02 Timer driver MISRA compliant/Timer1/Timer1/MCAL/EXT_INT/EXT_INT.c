/*
 * CFile1.c
 *
 * Created: 4/6/2023 6:28:59 AM
 *  Author: Speed
 */ 
#include "EXT_INT.h"
INTERRUPT_ERROR_TYPE EXT_INT_Enable(EXInterruptSource_type interrupt)
{
	if (interrupt>2)
	{
		return INVALID_INTERRUPT;
	}
	else
	{
		switch (interrupt)
		{
		case EX_INT0 :
			SET_BIT(GICR,INT0);
			return VALID_INTERRUPT;
			break;
			case EX_INT1:
			SET_BIT(GICR,INT1);
			return VALID_INTERRUPT;
			break;
			case EX_INT2:
			SET_BIT(GICR,INT2);
			return VALID_INTERRUPT;
			break;
		}
	
	}
	
}
INTERRUPT_ERROR_TYPE EXT_INT_Disable (EXInterruptSource_type interrupt)
{
		if (interrupt>3)
		{
			return INVALID_INTERRUPT;
		}
		else
		{
			switch (interrupt)
			{
				case EX_INT0:
				CLR_BIT(GICR,INT0);
				return VALID_INTERRUPT;
				break;
				case EX_INT1:
				CLR_BIT(GICR,INT1);
				return VALID_INTERRUPT;
				break;
				case EX_INT2:
				CLR_BIT(GICR,INT2);
				return VALID_INTERRUPT;
				break;
			}
			
		}
		

}
INTERRUPT_ERROR_TYPE EXT_INT_TriggerEdge (EXInterruptSource_type interrupt, TriggerEdge_type edge )
{
	if (interrupt>3)
	{
		return INVALID_INTERRUPT;
	}
	else
	{
		switch (interrupt)
		{
			case EX_INT0:
			if (edge>4)
			{
				return INVALID_TRIGGER_STATE;
			}
			else
			{
				switch (edge)
				{
			
				case LOW_LEVEL:
				CLR_BIT(MCUCR,ISC00);
				CLR_BIT(MCUCR,ISC01);
				return VALID_TRIGGER_STATE;
				break;
				case ANY_LOGIC_CHANGE:
				SET_BIT(MCUCR,ISC00);
				CLR_BIT(MCUCR,ISC01);
				return VALID_TRIGGER_STATE;
				break;
				case FALLING_EDGE:
				CLR_BIT(MCUCR,ISC00);
				SET_BIT(MCUCR,ISC01);
				return VALID_TRIGGER_STATE;
				break;
				case RISING_EDGE:
				SET_BIT(MCUCR,ISC00);
				SET_BIT(MCUCR,ISC01);
				return VALID_TRIGGER_STATE;
				break;
				}
			}
			
			
			case EX_INT1:
			if (edge>4)
			{
				return INVALID_TRIGGER_STATE;
			}
			else
			{
				switch (edge)
				{
					
					case LOW_LEVEL:
					CLR_BIT(MCUCR,ISC10);
					CLR_BIT(MCUCR,ISC11);
					return VALID_TRIGGER_STATE;
					break;
					case ANY_LOGIC_CHANGE:
					SET_BIT(MCUCR,ISC10);
					CLR_BIT(MCUCR,ISC11);
					return VALID_TRIGGER_STATE;
					break;
					case FALLING_EDGE:
					CLR_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
					return VALID_TRIGGER_STATE;
					break;
					case RISING_EDGE:
					SET_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
					return VALID_TRIGGER_STATE;
					break;
				}
			}
		
		
		

			case EX_INT2:
			if (edge>4)
			{
				
				return INVALID_TRIGGER_STATE;
			}
			else
			{
				switch (edge)
				{
					
					case LOW_LEVEL:
					/*DO nothing OR set default */
					break;
					case  ANY_LOGIC_CHANGE:
					/*DO nothing OR set default */
					break;
					case FALLING_EDGE:
					CLR_BIT(MCUCSR,ISC2);
					break;
					case RISING_EDGE:
					SET_BIT(MCUCSR,ISC2);
					break;
				}
				break;
			}
		}
		
			
		
	}
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
			return INVALID_INTERRUPT;
			break;
		}
	}
		
		

*/