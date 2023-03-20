#ifndef _ELF_STRUCTURE_H_
#define _ELF_STRUCTURE_H_

//TODO attributes

#define magic[0] (0x7F)
#define magic[1] ('E')
#define magic[2] ('L')
#define magic[3] ('F')

typedef enum {
	BITS_32	= 1,
	BITS_64 = 2
}class;

typedef enum {
	BITS_32	= 1,
	BITS_64 = 2
}endianness;

typedef enum {
	SYSTEM_V =	 	0x00,
	HP_UX = 		0x01,
	NETBSD = 		0x02,
	LINUX = 		0x03,
	GNUHURD = 		0x04,
	SOLARIS = 		0x05,
	AIX = 			0x06,
	IRIX = 			0x07,
	FREEBSD = 		0x08,
	TRU64 = 		0x0A,
	NOVELL_MODESTO= 0x0B,
	OPENBSD =		0x0C,
	OPENVMS =		0x0D,
	NONSTOP_KERNEL= 0x0E,
	AROS =			0x0F,
	FENIX_OS =		0X10,
	CLOUD_ABI =		0x11,
	SORTIX =		0x53
}os_abi;

typedef enum {
	RELOCATABLE	= 1,
	EXECUTABLE = 2,
	SHARED = 3,
	CORE = 4
}type;

typedef enum {
	NONE	= 0x00,
	SPARC = 0x02,
	X86 = 0x03,
	MIPS = 0x08,
	POWERPC = 0x14,
	ARM = 0x28,
	SUPERH = 0xA2,
	IA64 = 	0x32,
	X86_64 = 0x3E,
	AARCH64 = 0xB7,
	RISC_V = 0xF3
}machine;


#endif

