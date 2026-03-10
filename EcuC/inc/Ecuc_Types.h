/*https://www.autosar.org/fileadmin/standards/R22-11/CP/AUTOSAR_TPS_ECUConfiguration.pdf*/

#ifndef ECUC_TYPES_H
#define ECUC_TYPES_H

#include "Std_Types.h"

/*[ECUC_EcuC_00076]*/
typedef enum{
	PRIORITY_8,
	SOURCE_ADDRESS_16,
	TARGET_ADDRESS_16,
	ADDRESS_EXTENSION_8,
	SOCKET_CONNECTION_ID_16,
	LIN_NAD_8,
	CAN_ID_32,
	ETHERNET_MAC_64,
	PRIORITY_16,
	VLAN_16,
	SDUTYPE_8,
	ACCEPTANCEFIELD_32
}MetaDataItemTypeType;

/*[ECUC_EcuC_00076]*/
typedef struct{
	const uint8 MetaDataItemLength;
	const MetaDataItemTypeType MetaDataItemType_Par;
}MetaDataItemType;

/*[ECUC_EcuC_00073]*/
typedef struct{
	MetaDataItemType **MetaDataItem;
}MetaDataTypeType;

/*[ECUC_EcuC_00001]*/
typedef struct{
	const MetaDataTypeType *MetaDataTypeRef;
	const uint32 PduLength;
	const boolean J1939Requestable;
	const boolean DynamicLength;
	/* 
	SysTPduToFrameTriggeringRef
	SysTPduToPduTriggeringRef
	EcucPduDefaultPartitionRef
	EcucPduDedicatedPartition
	*/
}PduType;

#endif /*ECUC_TYPES_H*/