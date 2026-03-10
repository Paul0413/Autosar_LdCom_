#include "LdCom.h"
#include "LdCom_Types.h"
#include "LdCom_PbCfg.h"
#include "up_Rte.h"

LdCom_IPduType LdComIPdu[] = {
    {
        .LdComCopyTxDataCbk = up_Rte_LdComCbkCopyRxData,
        .LdComTpTxConfirmationCbk = up_Rte_LdComCbkTpTxConfirmation,
        .LdComTxConfirmationCbk = NULL,
        .LdComRxStartOfReceptionCbk = NULL,
        .LdComCopyRxDataCbk = NULL,
        .LdComTpRxIndicationCbk = NULL,
        .LdComRxIndicationCbk = NULL,
        .LdComTxTriggerTransmitCbk = NULL,
        .LdComPdurPduId = 28, //would been change when testing, PDUr would told us
        .LdComHandleId = 0,
        .LdComLowerApi = LDCOM_TP,
        .LdComIPduDir = LDCOM_SEND,
        .LdComPduRef = &MyIPdu[0],
    },
    {
        .LdComCopyTxDataCbk = NULL,
        .LdComTpTxConfirmationCbk = NULL,
        .LdComTxConfirmationCbk = NULL,
        .LdComRxStartOfReceptionCbk = up_Rte_LdComCbkStartOfReception,
        .LdComCopyRxDataCbk = up_Rte_LdComCbkCopyRxData,
        .LdComTpRxIndicationCbk = up_Rte_LdComCbkTpRxIndication,
        .LdComRxIndicationCbk = NULL,
        .LdComTxTriggerTransmitCbk = NULL,
        .LdComHandleId = 1,
        .LdComLowerApi = LDCOM_TP,
        .LdComIPduDir = LDCOM_RECEIVE,
        .LdComPduRef = &MyIPdu[0],
    },
    {
        .LdComCopyTxDataCbk = NULL,
        .LdComTpTxConfirmationCbk = NULL,
        .LdComTxConfirmationCbk = up_Rte_LdComCbkTxConfirmation,
        .LdComRxStartOfReceptionCbk = NULL,
        .LdComCopyRxDataCbk = NULL,
        .LdComTpRxIndicationCbk = NULL,
        .LdComRxIndicationCbk = NULL,
        .LdComTxTriggerTransmitCbk = up_Rte_LdComTriggerTransmit,
        .LdComPdurPduId = 30, //would been change when testing, PDUr would told us
        .LdComHandleId = 2,
        .LdComLowerApi = LDCOM_IF,
        .LdComIPduDir = LDCOM_SEND,
        .LdComPduRef = &MyIPdu[0],
    },
    {
        .LdComCopyTxDataCbk = NULL,
        .LdComTpTxConfirmationCbk = NULL,
        .LdComTxConfirmationCbk = NULL,
        .LdComRxStartOfReceptionCbk = NULL,
        .LdComCopyRxDataCbk = NULL,
        .LdComTpRxIndicationCbk = NULL,
        .LdComRxIndicationCbk = up_Rte_LdComCbkRxIndication,
        .LdComTxTriggerTransmitCbk = NULL,
        .LdComHandleId = 3,
        .LdComLowerApi = LDCOM_IF,
        .LdComIPduDir = LDCOM_RECEIVE,
        .LdComPduRef = &MyIPdu[0],
    },
};

/* ------------------- Callback Table ------------------- */
//LdCom_UserCallbackType LdCom_UserCallbacks[] = {
//    { 
//        .LdComUserCallbackName = up_Rte_LdComCbkCopyTxData,       
//        .LdComUserCallbackType = LDCOM_TP_COPY_TX_DATA 
//    },
//    {  
//        .LdComUserCallbackName = up_Rte_LdComCbkTxConfirmation,   
//        .LdComUserCallbackType = LDCOM_TX_CONFIRMATION 
//    },
//    { 
//        .LdComUserCallbackName = up_Rte_LdComCbkTpRxIndication,
//        .LdComUserCallbackType = LDCOM_TP_RX_INDICATION 
//    },
//    {
//        .LdComUserCallbackName = up_Rte_LdComCbkStartOfReception, 
//        .LdComUserCallbackType = LDCOM_RX_START_OF_RECEPTION 
//    },
//    { 
//        .LdComUserCallbackName = up_Rte_LdComCbkRxIndication,     
//        .LdComUserCallbackType = LDCOM_RX_INDICATION 
//    },
//    {
//        .LdComUserCallbackName = up_Rte_LdComCbkTpTxConfirmation, 
//        .LdComUserCallbackType = LDCOM_TP_TX_CONFIRMATION 
//    },
//    {
//        .LdComUserCallbackName = up_Rte_LdComCbkCopyRxData,       
//        .LdComUserCallbackType = LDCOM_TP_COPY_RX_DATA 
//    },
//    {
//        .LdComUserCallbackName = up_Rte_LdComTriggerTransmit,  
//        .LdComUserCallbackType = LDCOM_TRIGGER_TRANSMIT  
//    }
//};

/* ------------------- User IPDU to Callback Mapping ------------------- */
//LdCom_UserIpduType LdCom_UserIpdus[] = {
//    { 
//        .LdComUserCbkHandleId = 0, //LDCOM_TP_COPY_TX_DATA
//        .LdComUserCallbackRef = &LdCom_UserCallbacks[0] 
//    }, 
//    { 
//        .LdComUserCbkHandleId = 1, //LDCOM_TX_CONFIRMATION
//        .LdComUserCallbackRef = &LdCom_UserCallbacks[1] 
//    }, 
//    { 
//        .LdComUserCbkHandleId = 2, //LDCOM_TP_RX_INDICATION 
//        .LdComUserCallbackRef = &LdCom_UserCallbacks[2] 
//    }, 
//    { 
//        .LdComUserCbkHandleId = 2, //LDCOM_RX_START_OF_RECEPTION
//        .LdComUserCallbackRef = &LdCom_UserCallbacks[3] 
//    },  
//    { 
//        .LdComUserCbkHandleId = 3, //LDCOM_RX_INDICATION 
//        .LdComUserCallbackRef = &LdCom_UserCallbacks[4] 
//    }, 
//    { 
//        .LdComUserCbkHandleId = 0, //LDCOM_TP_TX_CONFIRMATION 
//        .LdComUserCallbackRef = &LdCom_UserCallbacks[5] 
//    }, 
//    { 
//        .LdComUserCbkHandleId = 2, //LDCOM_TP_COPY_RX_DATA 
//        .LdComUserCallbackRef = &LdCom_UserCallbacks[6] 
//    }, 
//    { 
//        .LdComUserCbkHandleId = 0, //LDCOM_TRIGGER_TRANSMIT 
//        .LdComUserCallbackRef = &LdCom_UserCallbacks[7] 
//    } 
//};

/* ------------------- User Module Configuration ------------------- */
//static const LdCom_UserModuleCnfType LdCom_UserModuleCfg = {
//    .LdComUserCallback = (LdCom_UserCallbackType*)LdCom_UserCallbacks,
//    .LdComUserIpdu = (LdCom_UserIpduType*)LdCom_UserIpdus
//};

/* ------------------- Top-Level User Module ------------------- */
//static const LdCom_UserModuleType LdCom_UserModule = {
//    .LdComUserModuleCfg = &LdCom_UserModuleCfg
//};

LdCom_ConfigType LdCom_Config = {
    .LdComIPdu = LdComIPdu,
    //.LdComUserModule = &LdCom_UserModule,
    .LdComIPduCnt = sizeof(LdComIPdu) / sizeof(LdCom_IPduType),
};
