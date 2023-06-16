#include "stdint.h"
#define SUCCESS (0)
#define ERROR (-1)
#define INVALID_INPUT (-2)
#define NULL ((void *)0)
#ifndef TRUE 
 #define TRUE  (1u)
#endif
#ifndef FALSE 
 #define FALSE  (0u)
#endif


typedef unsigned char  boolean;
typedef unsigned	long	unit32_t;


#define GET_BIT_STATUS(reg,bit_idx) (0UL!=((reg)&(1UL<<(bit_idx))))
#define	SET_BIT(Reg,BitNo)		(Reg |= (1UL<<BitNo))
#define	CLR_BIT(Reg,BitNo)		(Reg &= (~(1UL<<BitNo)))
#define TGL_BIT(Reg,BitNo)		(Reg ^= (1UL<<BitNo))
#define GET_BIT(Reg,BitNo)		(1UL   &  (Reg>>BitNo))
