#include "up_Rte.h"

BufReq_ReturnType up_Rte_LdComCbkCopyTxData (const PduInfoType* info, RetryInfoType* retry, PduLengthType* availableDataPtr) {
    return BUFREQ_OK;
}

void up_Rte_LdComCbkTpTxConfirmation (Std_ReturnType result) {
    return;
}

void up_Rte_LdComCbkTxConfirmation(Std_ReturnType result){
    return;
}

BufReq_ReturnType up_Rte_LdComCbkStartOfReception (const PduInfoType* info, PduLengthType TpSduLength, PduLengthType* bufferSizePtr){
    return BUFREQ_OK;
}

BufReq_ReturnType up_Rte_LdComCbkCopyRxData(const PduInfoType* info, PduLengthType* bufferSizePtr){
    return BUFREQ_OK;   
}

void up_Rte_LdComCbkTpRxIndication(Std_ReturnType result){
    return;
}

void up_Rte_LdComCbkRxIndication(const PduInfoType* PduInfoPtr){
    return;
}

Std_ReturnType up_Rte_LdComTriggerTransmit(PduInfoType* PduInfoPtr){
    return E_OK;
}