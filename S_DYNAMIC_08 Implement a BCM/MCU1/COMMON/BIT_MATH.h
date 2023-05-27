#ifndef _BIT_MATH_H
#define _BIT_MATH_H

// Macro for setting a specific bit in a register
#define SET_BIT(reg, bit) ((reg) |= (1 << (bit)))

// Macro for clearing a specific bit in a register
#define CLEAR_BIT(reg, bit) ((reg) &= ~(1 << (bit)))

// Macro for toggling a specific bit in a register
#define TOGGLE_BIT(reg, bit) ((reg) ^= (1 << (bit)))

// Macro for GET the value of a specific bit in a register
#define GET_BIT(Reg,BitNo)		(1   &  (Reg>>BitNo))

#endif
