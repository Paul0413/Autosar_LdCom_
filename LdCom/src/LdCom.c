#include "LdCom.h"
#include "LdCom_Types.h"
#include "up_Rte.h"

LdCom_StatusType LdComInitStatus = LDCOM_UNINIT;

const LdCom_ConfigType* LdCom_Configptr;

void LdCom_Init(const LdCom_ConfigType* config) {
    /*[SWS_LDCOM_00007]*/
    LdComInitStatus = LDCOM_INIT;
/*
    if (LdCom_Configptr == NULL || LdCom_Configptr->LdComUserModule == NULL) {
        return;
    }

    const LdCom_UserModuleCnfType* cnf = LdCom_Configptr->LdComUserModule->LdComUserModuleCfg;
    if (cnf == NULL) {
        return;
    }

    for (uint8 i = 0; i < LdCom_Configptr->LdComIPduCnt; ++i) {
        PduIdType handleId = LdCom_Configptr->LdComIPdu[i].LdComHandleId;

        for (uint8 j = 0; j < LdCom_Configptr->LdComIPduCnt; ++j) { // assume same count for simplicity
            if (cnf->LdComUserIpdu[j].LdComUserCbkHandleId == handleId) {
                const LdCom_UserCallbackType* cbk = cnf->LdComUserIpdu[j].LdComUserCallbackRef;

                if (cbk != NULL) {
                    switch (cbk->LdComUserCallbackType) {
                        case LDCOM_TP_COPY_TX_DATA:
                            if (strcmp(cbk->LdComUserCallbackName, "Rte_LdComCbkCopyTxData") == 0) {
                                LdCom_Configptr->LdComIPdu[i].LdComCopyTxDataCbk = up_Rte_LdComCbkCopyTxData;
                            }
                            break;
                        case LDCOM_TX_CONFIRMATION:
                            if (strcmp(cbk->LdComUserCallbackName, "Rte_LdComCbkTxConfirmation") == 0) {
                                LdCom_Configptr->LdComIPdu[i].LdComTxConfirmationCbk = LdCom_TxConfirmation; //would be up_Rte_LdComCbkTxConfirmation
                            }
                            break;
                        case LDCOM_RX_INDICATION:
                            if (strcmp(cbk->LdComUserCallbackName, "Rte_LdComCbkRxIndication") == 0) {
                                LdCom_Configptr->LdComIPdu[i].LdComRxIndicationCbk = LdCom_RxIndication;
                            }
                            break;
                        case LDCOM_RX_START_OF_RECEPTION:
                            if (strcmp(cbk->LdComUserCallbackName, "Rte_LdComCbkStartOfReception") == 0) {
                                LdCom_Configptr->LdComIPdu[i].LdComRxStartOfReceptionCbk = LdCom_StartOfReception;
                            }
                            break;
                        case LDCOM_TP_RX_INDICATION:
                            if (strcmp(cbk->LdComUserCallbackName, "Rte_LdComCbkTpRxIndication") == 0) {
                                LdCom_Configptr->LdComIPdu[i].LdComTpRxIndicationCbk = LdCom_TpRxIndication;
                            }
                            break;
                        case LDCOM_TP_TX_CONFIRMATION:
                            if (strcmp(cbk->LdComUserCallbackName, "Rte_LdComCbkTpTxConfirmation") == 0) {
                                LdCom_Configptr->LdComIPdu[i].LdComTpTxConfirmationCbk = LdCom_TpTxConfirmation;
                            }
                            break;
                        case LDCOM_TP_COPY_RX_DATA:
                            if (strcmp(cbk->LdComUserCallbackName, "Rte_LdComCbkCopyRxData") == 0) {
                                LdCom_Configptr->LdComIPdu[i].LdComCopyRxDataCbk = LdCom_CopyRxData;
                            }
                            break;
                        case LDCOM_TRIGGER_TRANSMIT:
                            if (strcmp(cbk->LdComUserCallbackName, "Rte_LdComCbkTriggerTransmit") == 0) {
                                LdCom_Configptr->LdComIPdu[i].LdComTxTriggerTransmitCbk = LdCom_TriggerTransmit;
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
        */
}

void LdCom_DeInit(void) {
    /*[SWS_LDCOM_00008]*/
    LdComInitStatus = LDCOM_UNINIT;
}

/*[SWS_LdCom_00026]*/
Std_ReturnType LdCom_Transmit(PduIdType Id, const PduInfoType* InfoPtr) {
    uint8 i;

    /*[SWS_LdCom_00018]*/
    if (LdComInitStatus == LDCOM_UNINIT) {
        return E_NOT_OK;
    }
    if (InfoPtr == NULL_PTR) {
        return E_NOT_OK;
    }
    if (InfoPtr->SduDataPtr == NULL_PTR) {
        return E_NOT_OK;
    }

    // handle id
    for(i = 0; i < LdCom_Configptr->LdComIPduCnt; i++){
        if (Id == LdCom_Configptr->LdComIPdu[i].LdComHandleId ) {
            break;
        }
    }
    // if id didn't match handleid
    if (i == LdCom_Configptr->LdComIPduCnt) {
        return E_NOT_OK;
    }

    /*[SWS_LdCom_00010]*/ /*[SWS_LdCom_00012]*/ /*To check if ipdu diection is correct*/
    if (LdCom_Configptr->LdComIPdu[i].LdComIPduDir == LDCOM_SEND) {
        return PduR_LdComTransmit(LdCom_Configptr->LdComIPdu[i].LdComPdurPduId, InfoPtr);
    } else {
        return E_NOT_OK;
    }
}

/*[SWS_LDCOM_00027]*/
BufReq_ReturnType LdCom_CopyTxData(PduIdType id, const PduInfoType* info, const RetryInfoType* retry, PduLengthType* availableDataPtr){
    uint8 i;

    /*[SWS_LdCom_00018]*/
    // LDCOM_DET_REPORTERROR((LDCOM_STATE_INIT == LdCom_Internal.initStatus), LDCOM_SERVICE_ID_COPY_TX_DATA, LDCOM_E_UNINIT, BUFREQ_NOT_OK);
    // LDCOM_DET_REPORTERROR((NULL_PTR != info), LDCOM_SERVICE_ID_COPY_TX_DATA, LDCOM_E_PARAM_POINTER, BUFREQ_NOT_OK);
    // LDCOM_DET_REPORTERROR((NULL_PTR != info->SduDataPtr), LDCOM_SERVICE_ID_COPY_TX_DATA, LDCOM_E_PARAM_POINTER, BUFREQ_NOT_OK);
    // LDCOM_DET_REPORTERROR((NULL_PTR != retry), LDCOM_SERVICE_ID_COPY_TX_DATA, LDCOM_E_PARAM_POINTER, BUFREQ_NOT_OK);
    // LDCOM_DET_REPORTERROR((NULL_PTR != availableDataPtr), LDCOM_SERVICE_ID_COPY_TX_DATA, LDCOM_E_PARAM_POINTER, BUFREQ_NOT_OK);
    if (LdComInitStatus == LDCOM_UNINIT) {
        return BUFREQ_E_NOT_OK;
    }
    if (info == NULL_PTR) {
        return BUFREQ_E_NOT_OK;
    }
    if (info->SduDataPtr == NULL_PTR) {
        return BUFREQ_E_NOT_OK;
    }
    if (retry == NULL_PTR) {
        return BUFREQ_E_NOT_OK;
    }
    if (*availableDataPtr == NULL_PTR) {
        return BUFREQ_E_NOT_OK;
    }

    // handle id
    for(i = 0; i < LdCom_Configptr->LdComIPduCnt; i++){
        if (id == LdCom_Configptr->LdComIPdu[i].LdComHandleId ) {
            break;
        }
    }
    // if id didn't match handleid
    if (i == LdCom_Configptr->LdComIPduCnt) {
        return BUFREQ_E_NOT_OK;
    }

    /*[SWS_LdCom_00048]*/
    if ((LdCom_Configptr->LdComIPdu[i].LdComIPduDir == LDCOM_SEND) && (LdCom_Configptr->LdComIPdu[i].LdComLowerApi == LDCOM_TP)) {
        if (LdCom_Configptr->LdComIPdu[i].LdComCopyTxDataCbk != NULL) {
            return LdCom_Configptr->LdComIPdu[i].LdComCopyTxDataCbk(info, retry, availableDataPtr);
        }
        else {
            return BUFREQ_E_NOT_OK;
        }
    }
    else {
        return BUFREQ_E_NOT_OK;
    }

}

/*[SWS_LdCom_00028]*/
void LdCom_TpTxConfirmation(PduIdType id, Std_ReturnType result){
    uint8 i;
    if (LdComInitStatus == LDCOM_UNINIT) {
        return; //Development Errors 0x02
        //result = E_NOT_OK;
    }
    // I don't know what to do with this
    //LDCOM_DET_REPORTERROR((E_OK == result),LDCOM_SERVICE_ID_TP_TX_CONFIRMATION,LDCOM_E_PARAM);
    
    // handle id
    for(i = 0; i < LdCom_Configptr->LdComIPduCnt; i++){
        if (id == LdCom_Configptr->LdComIPdu[i].LdComHandleId ) {
            break;
        }
    }
    // if id didn't match handleid
    if (i == LdCom_Configptr->LdComIPduCnt) {
        return; 
        //result = E_NOT_OK;
    }

    /*[SWS_LdCom_00048]*/
    if((LdCom_Configptr->LdComIPdu[i].LdComIPduDir == LDCOM_SEND) && (LdCom_Configptr->LdComIPdu[i].LdComLowerApi == LDCOM_TP)){
        if(LdCom_Configptr->LdComIPdu[i].LdComTpTxConfirmationCbk != NULL) {
            LdCom_Configptr->LdComIPdu[i].LdComTpTxConfirmationCbk(result);
        }
        // not sure
        else {
            return;
            //result = E_NOT_OK;
        }
    }
    else{
        return;
    }
}

/*[SWS_LdCom_00029]*/
BufReq_ReturnType LdCom_StartOfReception(PduIdType id, const PduInfoType* info, PduLengthType TpSduLength, PduLengthType* bufferSizePtr) {
    uint8 i;

    /*[SWS_LdCom_00018]*/
    // LDCOM_DET_REPORTERROR((LDCOM_STATE_INIT == LdCom_Internal.initStatus),LDCOM_SERVICE_ID_START_OF_RECEPTION, LDCOM_E_UNINIT, BUFREQ_NOT_OK);
    // LDCOM_DET_REPORTERROR((NULL != info),LDCOM_SERVICE_ID_START_OF_RECEPTION,LDCOM_E_PARAM_POINTER, BUFREQ_NOT_OK);
    // LDCOM_DET_REPORTERROR((NULL != info->SduDataPtr),LDCOM_SERVICE_ID_START_OF_RECEPTION,LDCOM_E_PARAM_POINTER, BUFREQ_NOT_OK);
    // LDCOM_DET_REPORTERROR(((PduLengthType)0 != TpSduLength ), LDCOM_SERVICE_ID_START_OF_RECEPTION,LDCOM_E_PARAM, BUFREQ_NOT_OK);
    // LDCOM_DET_REPORTERROR((NULL != bufferSizePtr),LDCOM_SERVICE_ID_START_OF_RECEPTION,LDCOM_E_PARAM_POINTER, BUFREQ_NOT_OK);
    if (LdComInitStatus == LDCOM_UNINIT) {
        return BUFREQ_E_NOT_OK;
    }
    if (info == NULL_PTR) {
        return BUFREQ_E_NOT_OK;
    }
    if (info->SduDataPtr == NULL_PTR) {
        return BUFREQ_E_NOT_OK;
    }
    if (TpSduLength == (PduLengthType)0) {
        return BUFREQ_E_NOT_OK;
    }
    if (bufferSizePtr == NULL_PTR) {
        return BUFREQ_E_NOT_OK;
    }

    // handle id
    for(i = 0; i < LdCom_Configptr->LdComIPduCnt; i++){
        if (id == LdCom_Configptr->LdComIPdu[i].LdComHandleId ) {
            break;
        }
    }
    // if id didn't match handleid
    if (i == LdCom_Configptr->LdComIPduCnt) {
        return BUFREQ_E_NOT_OK;
    }

    /*[SWS_LdCom_00049]*/
    if((LdCom_Configptr->LdComIPdu[i].LdComIPduDir == LDCOM_RECEIVE) && (LdCom_Configptr->LdComIPdu[i].LdComLowerApi ==LDCOM_TP)){
        if (LdCom_Configptr->LdComIPdu[i].LdComRxStartOfReceptionCbk != NULL) {
            return LdCom_Configptr->LdComIPdu[i].LdComRxStartOfReceptionCbk(info, TpSduLength, bufferSizePtr);
        } 
        else {
            return BUFREQ_E_NOT_OK;
        }
    } 
    else {
        return BUFREQ_E_NOT_OK;
    }
}

/*[SWS_LdCom_00030]*/
BufReq_ReturnType LdCom_CopyRxData(PduIdType id, const PduInfoType* info, PduLengthType* bufferSizePtr) {
    uint8 i;

    // handle id
    for(i = 0; i < LdCom_Configptr->LdComIPduCnt; i++){
        if (id == LdCom_Configptr->LdComIPdu[i].LdComHandleId ) {
            break;
        }
    }
    // if id didn't match handleid
    if (i == LdCom_Configptr->LdComIPduCnt) {
        return BUFREQ_E_NOT_OK;
    }

    if ((LdCom_Configptr->LdComIPdu[i].LdComIPduDir == LDCOM_RECEIVE) && (LdCom_Configptr->LdComIPdu[i].LdComLowerApi == LDCOM_TP)) {
        if (LdCom_Configptr->LdComIPdu[i].LdComCopyRxDataCbk != NULL) {
            return LdCom_Configptr->LdComIPdu[i].LdComCopyRxDataCbk(info, bufferSizePtr);
        }
        else {
            return BUFREQ_E_NOT_OK;
        }
    }
    else {
        return BUFREQ_E_NOT_OK;
    }

}

/*[SWS_LdCom_00031]*/
void LdCom_TpRxIndication(PduIdType id, Std_ReturnType result) {
    uint8 i;

    //LDCOM_DET_REPORTERROR((LDCOM_STATE_INIT == LdCom_Internal.initStatus),LDCOM_SERVICE_ID_TP_RX_INDICATION, LDCOM_E_UNINIT);
    //LDCOM_DET_REPORTERROR((E_OK == result),LDCOM_SERVICE_ID_TP_RX_INDICATION,LDCOM_E_PARAM);
    //???E_OK == result
    if (LdComInitStatus == LDCOM_UNINIT) {
        return; //Development Errors 0x02
        //result = E_NOT_OK;
    }

    // handle id
    for(i = 0; i < LdCom_Configptr->LdComIPduCnt; i++){
        if (id == LdCom_Configptr->LdComIPdu[i].LdComHandleId ) {
            break;
        }
    }
    // if id didn't match handleid
    if (i == LdCom_Configptr->LdComIPduCnt) {
        return;
        //result = E_NOT_OK;
    }
    
    /*[SWS_LdCom_00049]*/
    if((LdCom_Configptr->LdComIPdu[i].LdComIPduDir == LDCOM_RECEIVE )&&(LdCom_Configptr->LdComIPdu[i].LdComLowerApi ==LDCOM_TP)){
        if(LdCom_Configptr->LdComIPdu[i].LdComTpRxIndicationCbk != NULL){
            LdCom_Configptr->LdComIPdu[i].LdComTpRxIndicationCbk(result);
        }
        else {
            return;
            //result = E_NOT_OK;
        }
    }
    else {
        return;
        //result = E_NOT_OK;
    }
}
 
/*[SWS_LDCOM_00032]*/
void LdCom_RxIndication(PduIdType RxPduId, const PduInfoType* PduInfoPtr) {
    uint8 i;

    /*
        I don't know how to handle the error situation,
        cause "void" and there is no pointer "result".
    */
   
    //LDCOM_DET_REPORTERROR((LDCOM_STATE_INIT == LdCom_Internal.initStatus),LDCOM_SERVICE_ID_RX_INDICATION, LDCOM_E_UNINIT);
    //LDCOM_DET_REPORTERROR((NULL != PduInfoPtr),LDCOM_SERVICE_ID_RX_INDICATION,LDCOM_E_PARAM_POINTER);
    //LDCOM_DET_REPORTERROR((NULL != PduInfoPtr->SduDataPtr),LDCOM_SERVICE_ID_RX_INDICATION,LDCOM_E_PARAM_POINTER);
    if (LdComInitStatus == LDCOM_UNINIT) {
        return;
    }
    if (PduInfoPtr == NULL) {
        return;
    }
    if (PduInfoPtr->SduDataPtr == NULL) {
        return;
    }

    // handle id
    for(i = 0; i < LdCom_Configptr->LdComIPduCnt; i++){
        if (RxPduId == LdCom_Configptr->LdComIPdu[i].LdComHandleId ) {
            break;
        }
    }
    // if id didn't match handleid
    if (i == LdCom_Configptr->LdComIPduCnt) {
        return;
    }
    
    /*[SWS_LdCom_00049]*/
    if((LdCom_Configptr->LdComIPdu[i].LdComIPduDir == LDCOM_RECEIVE )&&(LdCom_Configptr->LdComIPdu[i].LdComLowerApi ==LDCOM_IF)){
        if(LdCom_Configptr->LdComIPdu[i].LdComRxIndicationCbk != NULL){
            LdCom_Configptr->LdComIPdu[i].LdComRxIndicationCbk(PduInfoPtr);
        }
        else {
            return;
        }
    }
    else {
        return;
    }
}

/*[SWS_LDCOM_00056]*/
void LdCom_TxConfirmation(PduIdType TxPduId, Std_ReturnType result) {
    uint8 i;
    
    //LDCOM_DET_REPORTERROR((LDCOM_STATE_INIT == LdCom_Internal.initStatus),LDCOM_SERVICE_ID_TX_CONFIRMATION, LDCOM_E_UNINIT);
    if (LdComInitStatus == LDCOM_UNINIT) {
        return; //Development Errors 0x02
        //result = E_NOT_OK;
    }

    // handle id
    for(i = 0; i < LdCom_Configptr->LdComIPduCnt; i++){
        if (TxPduId == LdCom_Configptr->LdComIPdu[i].LdComHandleId ) {
            break;
        }
    }
    // if id didn't match handleid
    if (i == LdCom_Configptr->LdComIPduCnt) {
        return;
        //result = E_NOT_OK;
    }

    /*[SWS_LdCom_00054]*/
    if ((LdCom_Configptr->LdComIPdu[i].LdComIPduDir == LDCOM_SEND) && (LdCom_Configptr->LdComIPdu[i].LdComLowerApi == LDCOM_IF)) {
        if (LdCom_Configptr->LdComIPdu[i].LdComTxConfirmationCbk != NULL) {
            LdCom_Configptr->LdComIPdu[i].LdComTxConfirmationCbk(result);
        }
        else {
            return;
            //result = E_NOT_OK;
        }
    }
    else{
        return;
        //result = E_NOT_OK;
    }
}

/*[SWS_LDCOM_00033]*/
Std_ReturnType LdCom_TriggerTransmit(PduIdType TxPduId, PduInfoType* PduInfoPtr) {
    uint8 i;
    //LDCOM_DET_REPORTERROR((LDCOM_STATE_INIT == LdCom_Internal.initStatus),LDCOM_SERVICE_ID_TRIGGER_TRANSMIT, LDCOM_E_UNINIT, E_NOT_OK);
    //LDCOM_DET_REPORTERROR((NULL_PTR != PduInfoPtr),LDCOM_SERVICE_ID_TRIGGER_TRANSMIT,LDCOM_E_PARAM_POINTER, E_NOT_OK);
    //LDCOM_DET_REPORTERROR((NULL_PTR != PduInfoPtr->SduDataPtr),LDCOM_SERVICE_ID_TRIGGER_TRANSMIT,LDCOM_E_PARAM_POINTER, E_NOT_OK);
    if (LdComInitStatus == LDCOM_UNINIT) {
        return E_NOT_OK;
    }
    if (PduInfoPtr == NULL_PTR){
        return E_NOT_OK;
    }
    if (PduInfoPtr->SduDataPtr == NULL_PTR){
        return E_NOT_OK;
    }

    // handle id
    for(i = 0; i < LdCom_Configptr->LdComIPduCnt; i++){
        if (TxPduId == LdCom_Configptr->LdComIPdu[i].LdComHandleId ) {
            break;
        }
    }
    // if id didn't match handleid
    if (i == LdCom_Configptr->LdComIPduCnt) {
        return E_NOT_OK;
    }

    if(LdCom_Configptr->LdComIPdu[i].LdComTxTriggerTransmitCbk != NULL){
        return LdCom_Configptr->LdComIPdu[i].LdComTxTriggerTransmitCbk(PduInfoPtr);
    }else{
        return E_NOT_OK;
    }

}