#ifndef GLOBAL_DEFINITION_H
#define GLOBAL_DEFINITION_H

#define FAILTURE	(-1)
#define SUCCESS_T 	0

/* #ifndef FALSE */
/* 	#define FALSE 	0 */
/* 	#define TRUE	1 */
/* #endif */

#ifndef DISABLE_T
	#define DISABLE_T 	0
#endif

#ifndef ENABLE_T
	#define ENABLE_T	1
#endif

typedef void (*VoidCallback)(void);
typedef void (*VICallback)(int x);
typedef void (*VUICallback)(unsigned int x);

#define WAIT_10_MS      (10)
#define WAIT_20_MS      (20)
#define WAIT_50_MS      (50)
#define WAIT_100_MS     (100)
#define WAIT_200_MS     (200)
#define WAIT_500_MS     (500)
#define WAIT_1_SEC      (1000)
#define WAIT_2_SEC      (2000)
#define WAIT_3_SEC      (3000)
#define WAIT_4_SEC      (4000)
#define WAIT_5_SEC      (5000)
#define WAIT_6_SEC      (6000)
#define WAIT_7_SEC      (7000)
#define WAIT_8_SEC      (8000)
#define WAIT_9_SEC      (9000)
#define WAIT_10_SEC     (10000)
#define WAIT_15_SEC     (15000)
#define WAIT_20_SEC     (20000)
#define WAIT_30_SEC     (30000)
#define WAIT_40_SEC     (40000)
#define WAIT_50_SEC     (50000)
#define WAIT_1_MIN      (60000)
#define WAIT_5_MIN      (300000)
#define WAIT_10_MIN     (600000)
#define WAIT_20_MIN     (1200000)
#define WAIT_30_MIN     (1800000)
#define WAIT_40_MIN     (2400000)
#define WAIT_50_MIN     (3000000)
#define WAIT_1_HOUR     (6600000)

#define TIME_OUT_10MS   (10)
#define TIME_OUT_20MS   (20)
#define TIME_OUT_50MS   (50)
#define TIME_OUT_75MS   (75)
#define TIME_OUT_100MS  (100)
#define TIME_OUT_200MS  (200)
#define TIME_OUT_500MS  (500)
#define TIME_OUT_1_SEC  (1000)
#define TIME_OUT_2_SEC  (2000)
#define TIME_OUT_3_SEC  (3000)
#define TIME_OUT_4_SEC  (4000)
#define TIME_OUT_5_SEC  (5000)

typedef signed char 		S8;
typedef unsigned char 		U8;
typedef short int			S16;
typedef unsigned short int	U16;
typedef int					S32;
typedef unsigned int		U32;
typedef long long			S64;
typedef unsigned long long	U64;
typedef float				FLOAT;
typedef double				DOUBLE;
typedef S32					RETURN_STATUS;

#endif // GLOBAL_DEFINATION_H

