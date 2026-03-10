/*This file defines APIs from LdCom spec chapter 8*/

#ifndef LDCOM_H
#define LDCOM_H

#include "ComStack_Types.h"
#include "LdCom_Types.h"
#include "Ecuc_Types.h"

/*[SWS_LDCOM_00022]*/
void LdCom_Init (const LdCom_ConfigType* config);

/*[SWS_LDCOM_00023]*/
void LdCom_DeInit (void);

/*[SWS_LDCOM_00024]*/
void LdCom_GetVersionInfo (Std_VersionInfoType* versioninfo);

/*[SWS_LDCOM_00026]*/
Std_ReturnType LdCom_Transmit (PduIdType id, const PduInfoType* InfoPtr);

/*[SWS_LDCOM_00027]*/
BufReq_ReturnType LdCom_CopyTxData (PduIdType id, const PduInfoType* info, const RetryInfoType* retry, PduLengthType* availableDataPtr);

/*[SWS_LDCOM_00028]*/
void LdCom_TpTxConfirmation (PduIdType id, Std_ReturnType result);

/*[SWS_LDCOM_00029]*/
BufReq_ReturnType LdCom_StartOfReception (PduIdType id, const PduInfoType* info, PduLengthType TpSduLength, PduLengthType* bufferSizePtr);

/*[SWS_LDCOM_00030]*/
BufReq_ReturnType LdCom_CopyRxData (PduIdType id, const PduInfoType* info, PduLengthType* bufferSizePtr);

/*[SWS_LDCOM_00031]*/
void LdCom_TpRxIndication (PduIdType id, Std_ReturnType result);

/*[SWS_LDCOM_00032]*/
void LdCom_RxIndication (PduIdType RxPduId, const PduInfoType* PduInfoPtr);

/*[SWS_LDCOM_00056]*/
void LdCom_TxConfirmation (PduIdType TxPduId, Std_ReturnType result);

/*[SWS_LDCOM_00033]*/
Std_ReturnType LdCom_TriggerTransmit (PduIdType TxPduId, PduInfoType* PduInfoPtr);

extern const PduType MyIPdu[];


#endif // LDCOM_H