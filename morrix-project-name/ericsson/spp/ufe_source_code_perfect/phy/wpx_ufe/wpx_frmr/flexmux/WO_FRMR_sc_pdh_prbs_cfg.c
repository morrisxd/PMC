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



void OMIINO_FRAMER_SOCKET_CLIENT_PDH_Set_Diagnostic_Ingress_Term_PRBS(OMIINO_FRAMER_CONFIGURATION_SOCKET_CLIENT_PDH_DIAGNOSTIC_TYPE * pClient, U8 PRBS_Pattern)
{
	OMIINO_FRAMER_ASSERT(NULL!=pClient,0);
	OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_PRBS_PATTERN_MAX>PRBS_Pattern,PRBS_Pattern);

	pClient->Ingress_Term_PRBS_Pattern = PRBS_Pattern;
}




void OMIINO_FRAMER_SOCKET_CLIENT_PDH_Get_Diagnostic_Ingress_Term_PRBS(OMIINO_FRAMER_CONFIGURATION_SOCKET_CLIENT_PDH_DIAGNOSTIC_TYPE * pClient, U8 *pPRBS_Pattern)
{
	OMIINO_FRAMER_ASSERT(NULL!=pClient,0);
	OMIINO_FRAMER_ASSERT(NULL!=pPRBS_Pattern,0);

	*pPRBS_Pattern = pClient->Ingress_Term_PRBS_Pattern;

	OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_PRBS_PATTERN_MAX>(*pPRBS_Pattern),(*pPRBS_Pattern));
}


void OMIINO_FRAMER_SOCKET_CLIENT_PDH_Set_Diagnostic_Ingress_Gen_PRBS(OMIINO_FRAMER_CONFIGURATION_SOCKET_CLIENT_PDH_DIAGNOSTIC_TYPE * pClient, U8 PRBS_Pattern)
{
	OMIINO_FRAMER_ASSERT(NULL!=pClient,0);
	OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_PRBS_PATTERN_MAX>PRBS_Pattern,PRBS_Pattern);

	pClient->Ingress_Gen_PRBS_Pattern = PRBS_Pattern;
}




void OMIINO_FRAMER_SOCKET_CLIENT_PDH_Get_Diagnostic_Ingress_Gen_PRBS(OMIINO_FRAMER_CONFIGURATION_SOCKET_CLIENT_PDH_DIAGNOSTIC_TYPE * pClient, U8 *pPRBS_Pattern)
{
	OMIINO_FRAMER_ASSERT(NULL!=pClient,0);
	OMIINO_FRAMER_ASSERT(NULL!=pPRBS_Pattern,0);

	*pPRBS_Pattern = pClient->Ingress_Gen_PRBS_Pattern;

	OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_PRBS_PATTERN_MAX>(*pPRBS_Pattern),(*pPRBS_Pattern));
}








void OMIINO_FRAMER_SOCKET_CLIENT_PDH_Set_Diagnostic_Egress_Term_PRBS(OMIINO_FRAMER_CONFIGURATION_SOCKET_CLIENT_PDH_DIAGNOSTIC_TYPE * pClient, U8 PRBS_Pattern)
{
	OMIINO_FRAMER_ASSERT(NULL!=pClient,0);
	OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_PRBS_PATTERN_MAX>PRBS_Pattern,PRBS_Pattern);

	pClient->Egress_Term_PRBS_Pattern = PRBS_Pattern;
}




void OMIINO_FRAMER_SOCKET_CLIENT_PDH_Get_Diagnostic_Egress_Term_PRBS(OMIINO_FRAMER_CONFIGURATION_SOCKET_CLIENT_PDH_DIAGNOSTIC_TYPE * pClient, U8 *pPRBS_Pattern)
{
	OMIINO_FRAMER_ASSERT(NULL!=pClient,0);
	OMIINO_FRAMER_ASSERT(NULL!=pPRBS_Pattern,0);

	*pPRBS_Pattern = pClient->Egress_Term_PRBS_Pattern;

	OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_PRBS_PATTERN_MAX>(*pPRBS_Pattern),(*pPRBS_Pattern));
}


void OMIINO_FRAMER_SOCKET_CLIENT_PDH_Set_Diagnostic_Egress_Gen_PRBS(OMIINO_FRAMER_CONFIGURATION_SOCKET_CLIENT_PDH_DIAGNOSTIC_TYPE * pClient, U8 PRBS_Pattern)
{
	OMIINO_FRAMER_ASSERT(NULL!=pClient,0);
	OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_PRBS_PATTERN_MAX>PRBS_Pattern,PRBS_Pattern);

	pClient->Egress_Gen_PRBS_Pattern = PRBS_Pattern;
}




void OMIINO_FRAMER_SOCKET_CLIENT_PDH_Get_Diagnostic_Egress_Gen_PRBS(OMIINO_FRAMER_CONFIGURATION_SOCKET_CLIENT_PDH_DIAGNOSTIC_TYPE * pClient, U8 *pPRBS_Pattern)
{
	OMIINO_FRAMER_ASSERT(NULL!=pClient,0);
	OMIINO_FRAMER_ASSERT(NULL!=pPRBS_Pattern,0);

	*pPRBS_Pattern = pClient->Egress_Gen_PRBS_Pattern;

	OMIINO_FRAMER_ASSERT(WPX_UFE_FRAMER_PRBS_PATTERN_MAX>(*pPRBS_Pattern),(*pPRBS_Pattern));
}





