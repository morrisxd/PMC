/*--------------------------------------------------------------------------*/
/*                                                                          */
/*        Copyright (c) 2010  Omiino Ltd                                    */
/*                                                                          */
/*        All rights reserved.                                              */
/*        This code is provided under license and or Non-disclosure         */
/*        Agreement and must be used solely for the purpose for which it    */
/*        was provided. It must not be passed to any third party without    */
/*        the written permission of Omiino Ltd.                             */
/*                                                                          */
/*--------------------------------------------------------------------------*/



#include "WO_FRMR_private.h"



void OMIINO_FRAMER_DISCRETE_CLIENT_Facility_Create(OMIINO_FRAMER_CONFIGURATION_DISCRETE_CLIENT_TYPE *pClient, U8 AnyClientType)
{
	OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_FACILITY_STATE_DOES_NOT_EXIST==pClient->FacilityState,pClient->FacilityState);
    OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_CLIENT_MAX_BANDIWDTH_TYPES>AnyClientType,AnyClientType);
    OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_CLIENT_NULL==pClient->ClientType,pClient->ClientType);
    OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_CLIENT_FRAMING_NULL==pClient->Framing,pClient->Framing);
    OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_CLIENT_MAPPING_BULK_FILL==pClient->Mapping,pClient->Mapping);

    pClient->FacilityState=WPX_UFE_FRAMER_FACILITY_STATE_CREATED_FREE;
    pClient->ClientType=AnyClientType;
	pClient->Framing=WPX_UFE_FRAMER_CLIENT_UNFRAMED;
	pClient->Mapping=WPX_UFE_FRAMER_CLIENT_MAPPING_BIT_ASYNC;
}


void OMIINO_FRAMER_DISCRETE_CLIENT_Facility_Delete(OMIINO_FRAMER_CONFIGURATION_DISCRETE_CLIENT_TYPE *pClient)
{
    OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_FACILITY_STATE_CREATED_FREE==pClient->FacilityState,pClient->FacilityState);
    OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_CLIENT_NULL!=pClient->ClientType,pClient->ClientType);
    
    pClient->FacilityState=WPX_UFE_FRAMER_FACILITY_STATE_DOES_NOT_EXIST;
    pClient->ClientType=WPX_UFE_FRAMER_CLIENT_NULL;
    pClient->Framing=WPX_UFE_FRAMER_CLIENT_FRAMING_NULL;
    pClient->Mapping=WPX_UFE_FRAMER_CLIENT_MAPPING_BULK_FILL;
}


void OMIINO_FRAMER_DISCRETE_CLIENT_Facility_MakeConnected(OMIINO_FRAMER_CONFIGURATION_DISCRETE_CLIENT_TYPE *pClient)
{
    OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_FACILITY_STATE_CREATED_FREE==pClient->FacilityState,pClient->FacilityState);
    OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_CLIENT_NULL!=pClient->ClientType,pClient->ClientType);

    pClient->FacilityState=WPX_UFE_FRAMER_FACILITY_STATE_CONNECTED;
}


void OMIINO_FRAMER_DISCRETE_CLIENT_Facility_MakeUnConnected(OMIINO_FRAMER_CONFIGURATION_DISCRETE_CLIENT_TYPE *pClient)
{
    OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_FACILITY_STATE_CONNECTED==pClient->FacilityState,pClient->FacilityState);
    OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_CLIENT_NULL!=pClient->ClientType,pClient->ClientType);

    pClient->FacilityState=WPX_UFE_FRAMER_FACILITY_STATE_CREATED_FREE;
}


U8 OMIINO_FRAMER_DISCRETE_CLIENT_Facility_GetState(OMIINO_FRAMER_CONFIGURATION_DISCRETE_CLIENT_TYPE *pClient)
{
    return (pClient->FacilityState);
}


U8 OMIINO_FRAMER_DISCRETE_CLIENT_Facility_IsConnected(OMIINO_FRAMER_CONFIGURATION_DISCRETE_CLIENT_TYPE *pClient)
{
    return(WPX_UFE_FRAMER_FACILITY_STATE_CONNECTED==pClient->FacilityState);
}


U8 OMIINO_FRAMER_DISCRETE_CLIENT_Facility_IsFree(OMIINO_FRAMER_CONFIGURATION_DISCRETE_CLIENT_TYPE *pClient)
{
    return(WPX_UFE_FRAMER_FACILITY_STATE_CREATED_FREE==pClient->FacilityState);
}


U8 OMIINO_FRAMER_DISCRETE_CLIENT_Facility_Exists(OMIINO_FRAMER_CONFIGURATION_DISCRETE_CLIENT_TYPE *pClient)
{
    return(WPX_UFE_FRAMER_FACILITY_STATE_DOES_NOT_EXIST!=pClient->FacilityState);
}






