/*
 * standard_types.h
 *
 * Created: 4/5/2023 9:26:30 AM
 *  Author: Speed
*/

#ifndef STANDARD_TYPES_H
#define STANDARD_TYPES_H

#define nullPtr				((void*)0)



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef signed		char	i8;			/*-128 	to +127*/
typedef unsigned	char	u8;			/*  0 	to +255*/

typedef signed		short	i16;			/*-32768 to +32767*/
typedef unsigned	short	u16;			/*   0   to +65535*/

typedef signed		long	i32;
typedef unsigned	long	u32;

typedef	float				f32;
typedef	double				flaot64_t;


#endif // !STANDARD_TYPES_H