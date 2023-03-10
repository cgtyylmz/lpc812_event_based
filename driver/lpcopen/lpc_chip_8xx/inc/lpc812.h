// lpc810.h
// LPC low level all-in-one header file for lpc810 devices
// principally targeted at lpc810 DIP8 package
// Written by Frank Duignan
// Latest version available at http://eleceng.dit.ie/frank/arm/
// Derived from UM10398 user manual from NXP semiconductors
// Naming convention: Register names are as described in UM10601
// No claims are made for the suitability, accuracy or otherwise of this file
// for any application
// Define some bitmasks
#define BIT0 (1 << 0)
#define BIT1 (1 << 1)
#define BIT2 (1 << 2)
#define BIT3 (1 << 3)
#define BIT4 (1 << 4)
#define BIT5 (1 << 5)
#define BIT6 (1 << 6)
#define BIT7 (1 << 7)
#define BIT8 (1 << 8)
#define BIT9 (1 << 9)
#define BIT10 (1 << 10)
#define BIT11 (1 << 11)
#define BIT12 (1 << 12)
#define BIT13 (1 << 13)
#define BIT14 (1 << 14)
#define BIT15 (1 << 15)
#define BIT16 (1 << 16)
#define BIT17 (1 << 17)
#define BIT18 (1 << 18)
#define BIT19 (1 << 19)
#define BIT20 (1 << 20)
#define BIT21 (1 << 21)
#define BIT22 (1 << 22)
#define BIT23 (1 << 23)
#define BIT24 (1 << 24)
#define BIT25 (1 << 25)
#define BIT26 (1 << 26)
#define BIT27 (1 << 27)
#define BIT28 (1 << 28)
#define BIT29 (1 << 29)
#define BIT30 (1 << 30)
#define BIT31 (1 << 31)

typedef unsigned char byte;
// Macros to reduce typing later on
#define  REGISTER_32(ADDRESS) (*((volatile unsigned int *)(ADDRESS)))
#define  REGISTER_16(ADDRESS) (*((volatile unsigned short *)(ADDRESS)))
#define  REGISTER_8(ADDRESS) (*((volatile unsigned char *)(ADDRESS)))
// Macros to enable/disable global interrupts
#define enable_interrupts() asm(" cpsie i ")
#define disable_interrupts() asm(" cpsid i ")

// AHB stuff
#define RAM_START			0x10000000
#define RAM_SIZE			1024
#define ROM_START			0x1fff0000

#define CRC_BASE 			0x50000000
#define SCTIMER_BASE 		0x50004000
#define GPIO_BASE			0xa0000000
#define PIN_INT_BASE		0xa0004000

#define SYS_BASE			0xe000e000


// APB stuff
#define WWDT_BASE			0x40000000
#define MRT_BASE			0x40004000
#define WAKE_UP_BASE		0x40008000
#define SWITCH_MATRIX_BASE 	0x4000c000
#define PMU_BASE			0x40020000
#define ANLG_COMP_BASE		0x40024000
#define FLASH_BASE			0x40040000
#define IOCON_BASE			0x40044000
#define SYSCON_BASE			0x40048000
#define I2C_BASE			0x40050000
#define SPI0_BASE			0x40058000
#define SPI1_BASE			0x4005c000
#define USART0_BASE			0x40064000
#define USART1_BASE			0x40068000
#define USART2_BASE			0x4006c000



// GPIO_PORT
// Symbols defined according to pin naming
#define PIO0_0				REGISTER_8(GPIO_BASE + 0)
#define PIO0_1				REGISTER_8(GPIO_BASE + 1)
#define PIO0_2				REGISTER_8(GPIO_BASE + 2)
#define PIO0_3				REGISTER_8(GPIO_BASE + 3)
#define PIO0_4				REGISTER_8(GPIO_BASE + 4)
#define PIO0_5				REGISTER_8(GPIO_BASE + 5)
#define PIO0_6				REGISTER_8(GPIO_BASE + 6)
#define PIO0_7				REGISTER_8(GPIO_BASE + 7)
#define PIO0_8				REGISTER_8(GPIO_BASE + 8)
#define PIO0_9				REGISTER_8(GPIO_BASE + 9)
#define PIO0_10				REGISTER_8(GPIO_BASE + 10)
#define PIO0_11				REGISTER_8(GPIO_BASE + 11)
#define PIO0_12				REGISTER_8(GPIO_BASE + 12)
#define PIO0_13				REGISTER_8(GPIO_BASE + 13)
#define PIO0_14				REGISTER_8(GPIO_BASE + 14)
#define PIO0_15				REGISTER_8(GPIO_BASE + 15)
#define PIO0_16				REGISTER_8(GPIO_BASE + 16)
#define PIO0_17				REGISTER_8(GPIO_BASE + 17)

// byte register access
#define GPIO_B0				REGISTER_8(GPIO_BASE + 0)
#define GPIO_B1				REGISTER_8(GPIO_BASE + 1)
#define GPIO_B2				REGISTER_8(GPIO_BASE + 2)
#define GPIO_B3				REGISTER_8(GPIO_BASE + 3)
#define GPIO_B4				REGISTER_8(GPIO_BASE + 4)
#define GPIO_B5				REGISTER_8(GPIO_BASE + 5)
#define GPIO_B6				REGISTER_8(GPIO_BASE + 6)
#define GPIO_B7				REGISTER_8(GPIO_BASE + 7)
#define GPIO_B8				REGISTER_8(GPIO_BASE + 8)
#define GPIO_B9				REGISTER_8(GPIO_BASE + 9)
#define GPIO_B10			REGISTER_8(GPIO_BASE + 10)
#define GPIO_B11			REGISTER_8(GPIO_BASE + 11)
#define GPIO_B12			REGISTER_8(GPIO_BASE + 12)
#define GPIO_B13			REGISTER_8(GPIO_BASE + 13)
#define GPIO_B14			REGISTER_8(GPIO_BASE + 14)
#define GPIO_B15			REGISTER_8(GPIO_BASE + 15)
#define GPIO_B16			REGISTER_8(GPIO_BASE + 16)
#define GPIO_B17			REGISTER_8(GPIO_BASE + 17)

#define GPIO_W0				REGISTER_32(GPIO_BASE + 0x1000)
#define GPIO_W1				REGISTER_32(GPIO_BASE + 0x1004)
#define GPIO_W2				REGISTER_32(GPIO_BASE + 0x1008)
#define GPIO_W3				REGISTER_32(GPIO_BASE + 0x100c)
#define GPIO_W4				REGISTER_32(GPIO_BASE + 0x1010)
#define GPIO_W5				REGISTER_32(GPIO_BASE + 0x1014)
#define GPIO_W6				REGISTER_32(GPIO_BASE + 0x1018)
#define GPIO_W7				REGISTER_32(GPIO_BASE + 0x101c)
#define GPIO_W8				REGISTER_32(GPIO_BASE + 0x1020)
#define GPIO_W9				REGISTER_32(GPIO_BASE + 0x1024)
#define GPIO_W10			REGISTER_32(GPIO_BASE + 0x1028)
#define GPIO_W11			REGISTER_32(GPIO_BASE + 0x102c)
#define GPIO_W12			REGISTER_32(GPIO_BASE + 0x1030)
#define GPIO_W13			REGISTER_32(GPIO_BASE + 0x1034)
#define GPIO_W14			REGISTER_32(GPIO_BASE + 0x1038)
#define GPIO_W15			REGISTER_32(GPIO_BASE + 0x103c)
#define GPIO_W16			REGISTER_32(GPIO_BASE + 0x1040)
#define GPIO_W17			REGISTER_32(GPIO_BASE + 0x1044)

#define GPIO_DIRP0			REGISTER_32(GPIO_BASE + 0x2000)
#define GPIO_MASKP0		REGISTER_32(GPIO_BASE + 0x2080)
#define GPIO_PORT0			REGISTER_32(GPIO_BASE + 0x2100)
#define GPIO_MPORTP0		REGISTER_32(GPIO_BASE + 0x2180)
#define GPIO_SETP0			REGISTER_32(GPIO_BASE + 0x2200)
#define GPIO_CLRP0			REGISTER_32(GPIO_BASE + 0x2280)
#define GPIO_NOTP0			REGISTER_32(GPIO_BASE + 0x2300)

// Switch Matrix
#define PINASSIGN0			REGISTER_32(SWITCH_MATRIX_BASE + 0x0)
#define PINASSIGN1			REGISTER_32(SWITCH_MATRIX_BASE + 0x4)
#define PINASSIGN2			REGISTER_32(SWITCH_MATRIX_BASE + 0x8)
#define PINASSIGN3			REGISTER_32(SWITCH_MATRIX_BASE + 0xc)
#define PINASSIGN4			REGISTER_32(SWITCH_MATRIX_BASE + 0x10)
#define PINASSIGN5			REGISTER_32(SWITCH_MATRIX_BASE + 0x14)
#define PINASSIGN6			REGISTER_32(SWITCH_MATRIX_BASE + 0x18)
#define PINASSIGN7			REGISTER_32(SWITCH_MATRIX_BASE + 0x1c)
#define PINASSIGN8			REGISTER_32(SWITCH_MATRIX_BASE + 0x20)
#define PINENABLE0			REGISTER_32(SWITCH_MATRIX_BASE + 0x1c0)

// USART0
#define USART0_CFG			REGISTER_32(USART0_BASE + 0x00)
#define USART0_CTL			REGISTER_32(USART0_BASE + 0x04)
#define USART0_STAT			REGISTER_32(USART0_BASE + 0x08)
#define USART0_INTENSET		REGISTER_32(USART0_BASE + 0x0c)
#define USART0_INTENCLR		REGISTER_32(USART0_BASE + 0x10)
#define USART0_RXDAT		REGISTER_32(USART0_BASE + 0x14)
#define USART0_RXDATSTAT	REGISTER_32(USART0_BASE + 0x18)
#define USART0_TXDAT		REGISTER_32(USART0_BASE + 0x1c)
#define USART0_BRG			REGISTER_32(USART0_BASE + 0x20)
#define USART0_INTSTAT		REGISTER_32(USART0_BASE + 0x24)

// USART1
#define USART1_CFG			REGISTER_32(USART1_BASE + 0x00)
#define USART1_CTL			REGISTER_32(USART1_BASE + 0x04)
#define USART1_STAT			REGISTER_32(USART1_BASE + 0x08)
#define USART1_INTENSET		REGISTER_32(USART1_BASE + 0x0c)
#define USART1_INTENCLR		REGISTER_32(USART1_BASE + 0x10)
#define USART1_RXDAT		REGISTER_32(USART1_BASE + 0x14)
#define USART1_RXDATSTAT	REGISTER_32(USART1_BASE + 0x18)
#define USART1_TXDAT		REGISTER_32(USART1_BASE + 0x1c)
#define USART1_BRG			REGISTER_32(USART1_BASE + 0x20)
#define USART1_INTSTAT		REGISTER_32(USART1_BASE + 0x24)

// USART2
#define USART2_CFG			REGISTER_32(USART2_BASE + 0x00)
#define USART2_CTL			REGISTER_32(USART2_BASE + 0x04)
#define USART2_STAT			REGISTER_32(USART2_BASE + 0x08)
#define USART2_INTENSET		REGISTER_32(USART2_BASE + 0x0c)
#define USART2_INTENCLR		REGISTER_32(USART2_BASE + 0x10)
#define USART2_RXDAT		REGISTER_32(USART2_BASE + 0x14)
#define USART2_RXDATSTAT	REGISTER_32(USART2_BASE + 0x18)
#define USART2_TXDAT		REGISTER_32(USART2_BASE + 0x1c)
#define USART2_BRG			REGISTER_32(USART2_BASE + 0x20)
#define USART2_INTSTAT		REGISTER_32(USART2_BASE + 0x24)


// SYSCON
#define SYSCON_MAP			REGISTER_32(SYSCON_BASE + 0x00)
#define SYSCON_PRESETCTRL	REGISTER_32(SYSCON_BASE + 0x04)
#define SYSCON_SYSPLLCTRL	REGISTER_32(SYSCON_BASE + 0x08)
#define SYSCON_SYSPLLSTAT	REGISTER_32(SYSCON_BASE + 0x0c)
#define SYSCON_SYSOSCCTRL	REGISTER_32(SYSCON_BASE + 0x10)
#define SYSCON_WDTOSCCTRL	REGISTER_32(SYSCON_BASE + 0x24)
#define SYSCON_SYSRSTSTAT	REGISTER_32(SYSCON_BASE + 0x30)
#define SYSCON_SYSPLLCLKSEL	REGISTER_32(SYSCON_BASE + 0x40)
#define SYSCON_SYSPLLCLKUEN	REGISTER_32(SYSCON_BASE + 0x44)
#define SYSCON_MAINCLKSEL 	REGISTER_32(SYSCON_BASE + 0x70)
#define SYSCON_MAINCLKUEN 	REGISTER_32(SYSCON_BASE + 0x74)
#define SYSCON_SYSAHBCLKDIV	REGISTER_32(SYSCON_BASE + 0x78)
#define SYSCON_SYSAHBCLKCTRL	REGISTER_32(SYSCON_BASE + 0x80)
#define SYSCON_UARTCLKDIV	REGISTER_32(SYSCON_BASE + 0x94)
#define SYSCON_CLKOUTSEL	REGISTER_32(SYSCON_BASE + 0xe0)
#define SYSCON_CLKOUTUEN	REGISTER_32(SYSCON_BASE + 0xe4)
#define SYSCON_CLKOUTDIV	REGISTER_32(SYSCON_BASE + 0xe8)
#define SYSCON_UARTFRGDIV	REGISTER_32(SYSCON_BASE + 0xf0)
#define SYSCON_UARTFRGMULT	REGISTER_32(SYSCON_BASE + 0xf4)
#define SYSCON_EXTTRACECMD	REGISTER_32(SYSCON_BASE + 0xfc)
#define SYSCON_PIOPORCAP0	REGISTER_32(SYSCON_BASE + 0x100)
#define SYSCON_IOCONCLKDIV6	REGISTER_32(SYSCON_BASE + 0x134)
#define SYSCON_IOCONCLKDIV5	REGISTER_32(SYSCON_BASE + 0x138)
#define SYSCON_IOCONCLKDIV4	REGISTER_32(SYSCON_BASE + 0x13c)
#define SYSCON_IOCONCLKDIV3	REGISTER_32(SYSCON_BASE + 0x140)
#define SYSCON_IOCONCLKDIV2	REGISTER_32(SYSCON_BASE + 0x144)
#define SYSCON_IOCONCLKDIV1	REGISTER_32(SYSCON_BASE + 0x148)
#define SYSCON_IOCONCLKDIV0	REGISTER_32(SYSCON_BASE + 0x14c)
#define SYSCON_BODCTRL		REGISTER_32(SYSCON_BASE + 0x150)
#define SYSCON_SYSTCKCAL	REGISTER_32(SYSCON_BASE + 0x154)
#define SYSCON_IRQLATENCY	REGISTER_32(SYSCON_BASE + 0x170)
#define SYSCON_NMISRC		REGISTER_32(SYSCON_BASE + 0x174)
#define SYSCON_PINTSEL0		REGISTER_32(SYSCON_BASE + 0x178)
#define SYSCON_PINTSEL1		REGISTER_32(SYSCON_BASE + 0x17c)
#define SYSCON_PINTSEL2		REGISTER_32(SYSCON_BASE + 0x180)
#define SYSCON_PINTSEL3		REGISTER_32(SYSCON_BASE + 0x184)
#define SYSCON_PINTSEL4		REGISTER_32(SYSCON_BASE + 0x188)
#define SYSCON_PINTSEL5		REGISTER_32(SYSCON_BASE + 0x18c)
#define SYSCON_PINTSEL6		REGISTER_32(SYSCON_BASE + 0x190)
#define SYSCON_PINTSEL7		REGISTER_32(SYSCON_BASE + 0x194)
#define SYSCON_STARTERP0	REGISTER_32(SYSCON_BASE + 0x204)
#define SYSCON_STARTERP1	REGISTER_32(SYSCON_BASE + 0x214)
#define SYSCON_PDSLEEPCFG	REGISTER_32(SYSCON_BASE + 0x230)
#define SYSCON_PDAWAKECFG	REGISTER_32(SYSCON_BASE + 0x234)
#define SYSCON_PDRUNCFG		REGISTER_32(SYSCON_BASE + 0x238)
#define SYSCON_DEVICE_ID	REGISTER_32(SYSCON_BASE + 0x3f8)


// NVIC 
#define NVIC_ISER0			REGISTER_32(SYS_BASE + 0x100)
#define NVIC_ICER0			REGISTER_32(SYS_BASE + 0x180)
#define NVIC_ISPR0			REGISTER_32(SYS_BASE + 0x200)
#define NVIC_ICPR0			REGISTER_32(SYS_BASE + 0x280)
#define NVIC_IABR0			REGISTER_32(SYS_BASE + 0x300)
#define NVIC_IPR0			REGISTER_32(SYS_BASE + 0x400)
#define NVIC_IPR1			REGISTER_32(SYS_BASE + 0x404)
#define NVIC_IPR2			REGISTER_32(SYS_BASE + 0x408)
#define NVIC_IPR3			REGISTER_32(SYS_BASE + 0x40c)
#define NVIC_IPR6			REGISTER_32(SYS_BASE + 0x418)
#define NVIC_IPR7			REGISTER_32(SYS_BASE + 0x41c)


// STK
#define SYST_CSR	REGISTER_32(SYS_BASE + 0x10)
#define SYST_RVR	REGISTER_32(SYS_BASE + 0x14)
#define SYST_CVR	REGISTER_32(SYS_BASE + 0x18)
#define SYST_CALIB	REGISTER_32(SYS_BASE + 0x1c)

