ENTRY(Reset_Handler)

MEMORY
{
	FLASH         :ORIGIN = 0x00000000, len = 16k
	RAM           :ORIGIN = 0x10000000, len = 4k
}

SECTIONS
{
	.isr_vector :
	{
		. = ALIGN(4);
		KEEP(*(.isr_vector))
		. = ALIGN(4);
	}> FLASH
	.text :
	{
		*(.text)
		*(.text*.)
		*(.rodata)
		*(.rodata.*)
		. = ALIGN(4);
		_etext = .;
	}>FLASH

	_lo_data = LOADADDR(.data);
	.data :
	{
		_sdata = .;
		*(.data)
		*(.data.*)
		. = ALIGN(4);
		_edata = .;
	}>RAM AT> FLASH

	.bss :
	{
		_sbss = .;
		*(.bss)
		*(.bss.*)
		. = ALIGN(4);
		_ebss = .;
	}>RAM
}
