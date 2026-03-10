#ifndef LDCOM_CBK_H_
#define LDCOM_CBK_H_

#include "ComStack_Types.h"
#include "LdCom_Types.h"

/*[SWS_LdCom_91001]*/
BufReq_ReturnType LdCom_CbkCopyTxData(CbkHandleIdType LdComUserCbkHandleId, const PduInfoType* info, const RetryInfoType* retry, PduLengthType* availableDataPtr );
/*[SWS_LdCom_91002]*/
void LdCom_CbkTpTxConfirmation(CbkHandleIdType LdComUserCbkHandleId, Std_ReturnType result );
/*[SWS_LdCom_91003]*/
BufReq_ReturnType LdCom_CbkStartOfReception(CbkHandleIdType LdComUserCbkHandleId, const PduInfoType* info, PduLengthType TpSduLength, PduLengthType* bufferSizePtr );
/*[SWS_LdCom_91004]*/
BufReq_ReturnType LdCom_CbkCopyRxData(CbkHandleIdType LdComUserCbkHandleId, const PduInfoType* info, PduLengthType* bufferSizePtr );
/*[SWS_LdCom_91005]*/
void LdCom_CbkTpRxIndication(CbkHandleIdType LdComUserCbkHandleId, Std_ReturnType result );
/*[SWS_LdCom_91006]*/
void LdCom_CbkRxIndication(CbkHandleIdType LdComUserCbkHandleId, const PduInfoType* PduInfoPtr );
/*[SWS_LdCom_91007]*/
Std_ReturnType LdCom_CbkTriggerTransmit(CbkHandleIdType LdComUserCbkHandleId, PduInfoType* PduInfoPtr );
/*[SWS_LdCom_91008]*/
void LdCom_CbkTxConfirmation(CbkHandleIdType LdComUserCbkHandleId, Std_ReturnType result );

#endif /* LDCOM_CBK_H_ */