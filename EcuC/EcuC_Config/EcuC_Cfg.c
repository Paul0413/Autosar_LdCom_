#include "EcuC_Cfg.h"

const MetaDataItemType MetaDataItem[] = {
	{
		//offset test
		.MetaDataItemLength=2,
		.MetaDataItemType_Par=SOCKET_CONNECTION_ID_16,
	},
	{
		.MetaDataItemLength=4,
		.MetaDataItemType_Par=CAN_ID_32,
	},
	// {
		
	// },
	// {
		
	// },
};

const MetaDataItemType *MetaDataItems[] = {
	&MetaDataItem[0],
	&MetaDataItem[1],	
	// &MetaDataItem[2],
	NULL,
};

const MetaDataTypeType MetaDataTypes[] = {
	{
		.MetaDataItem = MetaDataItems,
	},
};


const PduType MyIPdu[] = {
	{ //Normal pdu
		.PduLength = 12,
		.MetaDataTypeRef = &MetaDataTypes[0],
	},
	{ // For CanTp test
		.PduLength = 60,
	},
	{ //Classic Can
		.PduLength = 8,
		.MetaDataTypeRef = &MetaDataTypes[0],		
	},
};