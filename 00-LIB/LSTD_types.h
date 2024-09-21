#ifndef L
#define L
	typedef unsigned char u8;
	typedef unsigned short int u16;
	typedef unsigned int u32;
	typedef signed char s8;
	typedef signed short int s16;
	typedef signed int s32;
	typedef float f32;
	typedef double f64;

	typedef signed long long int si64;
	typedef unsigned long long int ui64;
	
	//typedef int size_t;
	
	#ifdef NULL 
	#undef NULL
	#endif
	#define NULL ((void*)0)
	
	
#endif	