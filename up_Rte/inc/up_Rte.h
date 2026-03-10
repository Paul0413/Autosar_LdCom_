#ifndef UP_RTE_H
#define UP_RTE_H

#include "Std_Types.h"
#include "ComStack_Types.h"

BufReq_ReturnType up_Rte_LdComCbkCopyTxData (const PduInfoType* info, RetryInfoType* retry, PduLengthType* availableDataPtr);

void up_Rte_LdComCbkTpTxConfirmation (Std_ReturnType result);

void up_Rte_LdComCbkTxConfirmation(Std_ReturnType result);

BufReq_ReturnType up_Rte_LdComCbkStartOfReception (const PduInfoType* info, PduLengthType TpSduLength, PduLengthType* bufferSizePtr);

BufReq_ReturnType up_Rte_LdComCbkCopyRxData(const PduInfoType* info, PduLengthType* bufferSizePtr);

void up_Rte_LdComCbkTpRxIndication(Std_ReturnType result);

void up_Rte_LdComCbkRxIndication(const PduInfoType* PduInfoPtr);

Std_ReturnType up_Rte_LdComTriggerTransmit(PduInfoType* PduInfoPtr);
    
#endif /*UP_RTE_H*/