#ifndef LDCOM_TYPES_H
#define LDCOM_TYPES_H

#include "Ecuc_Types.h"

typedef enum{
    LDCOM_UNINIT,
    LDCOM_INIT,
}LdCom_StatusType;

/*[ECUC_LdCom_00002]*/
typedef enum{
    LDCOM_IF,
    LDCOM_TP
}LdComApiType;

/*[ECUC_LdCom_00007]*/
typedef enum{
    LDCOM_RECEIVE,
    LDCOM_SEND
}LdComIPduDirection;


typedef BufReq_ReturnType (*LdComCopyTxData)(const PduInfoType* info, RetryInfoType* retry, PduLengthType* availableDataPtr);
typedef void (*LdComTpTxConfirmation)(Std_ReturnType result);
typedef void (*LdComTxConfirmation)(Std_ReturnType result);
typedef BufReq_ReturnType (*LdComStartOfReception)(const PduInfoType* info, PduLengthType TpSduLength, PduLengthType* bufferSizePtr);
typedef BufReq_ReturnType (*LdComCopyRxData)(const PduInfoType* info, PduLengthType* bufferSizePtr);
typedef void (*LdComTpRxIndication)(Std_ReturnType result);
typedef void (*LdComRxIndication)(const PduInfoType* PduInfoPtr);
typedef Std_ReturnType (*LdComTriggerTransmit)(PduInfoType* PduInfoPtr);

/*[ECUC_LdCom_00006]*/
typedef struct {
    LdComCopyTxData         LdComCopyTxDataCbk; /* Callback for LdCom_CopyTxData */
    LdComTpTxConfirmation   LdComTpTxConfirmationCbk; /* Callback for LdCom_TpTxConfirmation */
    LdComTxConfirmation     LdComTxConfirmationCbk; /* Callback for LdCom_TxConfirmation */
    LdComStartOfReception   LdComRxStartOfReceptionCbk; /* Callback for LdCom_StartOfReception */
    LdComCopyRxData         LdComCopyRxDataCbk; /* Callback for LdCom_CopyRxData */
    LdComTpRxIndication     LdComTpRxIndicationCbk; /* Callback for LdCom_TpRxIndication */
    LdComRxIndication       LdComRxIndicationCbk; /* Callback for LdCom_RxIndication */
    LdComTriggerTransmit    LdComTxTriggerTransmitCbk; /* Callback for LdCom_TriggerTransmit */
    
    PduIdType               LdComPdurPduId ; /* PduR Pdu Id for transmit 往下傳所需的ID*/
    PduIdType               LdComHandleId; /* Handle Id 本層所需要的ID*/
    LdComApiType       LdComLowerApi; /* Type of lower api */
    LdComIPduDirection  LdComIPduDir; /* Direction of IPdu */
    PduType const *LdComPduRef; /*Global Pdu*/
    /*[ECUC_LdCom_00011] LdComSystemTemplateSignalRef先不處理*/ 
}LdCom_IPduType;

/* R22-11 DRAFT */
////////////////////////////////////////////////
    /*[ECUC_LdCom_00025]*/
/*    typedef enum {
        LDCOM_RX_INDICATION, 
        LDCOM_RX_START_OF_RECEPTION,
        LDCOM_TP_COPY_RX_DATA,
        LDCOM_TP_COPY_TX_DATA,
        LDCOM_TP_RX_INDICATION,
        LDCOM_TP_TX_CONFIRMATION,
        LDCOM_TX_CONFIRMATION,
        LDCOM_TRIGGER_TRANSMIT
    }LdCom_UserCallbackTypeType;*/

    /*[ECUC_LdCom_00022]*/
/*    typedef struct {             
        void *LdComUserCallbackName;
        LdCom_UserCallbackTypeType LdComUserCallbackType;
    }LdCom_UserCallbackType;
    */


    /*[ECUC_LdCom_00028]*/
/*    typedef struct {
        uint16 LdComUserCbkHandleId;
        LdCom_UserCallbackType *LdComUserCallbackRef;
        /*[ECUC_LdCom_00033]LdComUserSystemTemplateSignalRef先不處理
    }LdCom_UserIpduType;
*/

    /*[ECUC_LdCom_00030]*/
/*    typedef struct {
        LdCom_UserCallbackType *LdComUserCallback; 
        LdCom_UserIpduType *LdComUserIpdu;
        uint8 *LdComUserHeaderInclude; //EcucStringParameter
    }LdCom_UserModuleCnfType;
*/

    /*[ECUC_LdCom_00029]*/
/*    typedef struct {
        LdCom_UserModuleCnfType *LdComUserModuleCfg;
    }LdCom_UserModuleType;
    */
/////////////////////////////////////////////


/*[ECUC_LdCom_00003]*/
typedef struct {
    LdCom_IPduType *LdComIPdu;
    //LdCom_UserModuleType *LdComUserModule;
    uint8 LdComIPduCnt;
}LdCom_ConfigType;


#endif LDCOM_TYPES_H