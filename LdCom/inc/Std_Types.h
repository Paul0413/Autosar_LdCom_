/*Copy from Com/inc*/

#ifndef STD_TYPES_H
#define STD_TYPES_H

#include "Platform_Types.h"

/*[SWS_Com_00609]*/
typedef uint8 Std_ReturnType;

/*[SWS_Com_00865] [SWS_Std_00005]*/
#define E_OK 					(Std_ReturnType)0
#define E_NOT_OK 				(Std_ReturnType)1

/*[SWS_Std_00031]*/
#define NULL_PTR ((void *)0)
#define NULL ((void *)0)

/*[SWS_Std_00015]*/
typedef struct{
	uint16 vendorID;
	uint16 moduleID;
	uint8 sw_major_version;
	uint8 sw_minor_version;
	uint8 sw_patch_version;
}Std_VersionInfoType;

#endif /*STD_TYPES_H*/