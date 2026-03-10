/*Copy from Com/inc*/


#ifndef COMSTACK_TYPES_H
#define COMSTACK_TYPES_H

#include "Std_Types.h"
#include "ComStack_Cfg.h" 

/*[SWS_Com_00609]*/
/*[SWS_COMTYPE_00005]*/
#if(PduIdTypeEnum == UINT8)
typedef uint8 PduIdType;
#elif(PduIdTypeEnum == UINT16)
typedef uint16 PduIdType;
#endif

/*[SWS_COMTYPE_00008]*/
#if(PduLengthTypeEnum == UINT8)
typedef uint8 PduLengthType;
#elif (PduLengthTypeEnum == UINT16)
typedef uint16 PduLengthType;
#elif(PduLengthTypeEnum == UINT32)
typedef uint32 PduLengthType;
#endif

/*[SWS_COMTYPE_00011]*/
typedef struct{
	uint8 *SduDataPtr;
	uint8 *MetaDataPtr;
	PduLengthType SduLength;
}PduInfoType;

/*[SWS_COMTYPE_00012]*/
typedef enum{
	BUFREQ_OK,
	BUFREQ_E_NOT_OK,
	BUFREQ_E_BUSY,
	BUFREQ_E_OVFL
}BufReq_ReturnType;

/*[SWS_COMTYPE_00027]*/ 
typedef enum{
	TP_DATACONF,
	TP_NORETRY,
	TP_CONFPENDING,
}TpDataStateType;

typedef struct{
	TpDataStateType TpDataState;
	PduLengthType TxTpDataCnt;
}RetryInfoType;

/*[SWS_COMTYPE_91001]*/
typedef uint16 CbkHandleIdType; 

#endif /*COMSTACK_TYPES_H*/