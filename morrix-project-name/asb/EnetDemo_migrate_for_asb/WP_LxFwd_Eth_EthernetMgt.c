/************************************************************************
**                                                                     **
**                         ALCATEL-LUCENT TELECOM                      **
**                                                                     **
************************************************************************/

/*************************** IDENTIFICATION *****************************
**
** Project          : MDU R2.2 
**
** Module           : NPU::LxFwd[::Eth Interfaces]
**
** File name        : WP_LxFwd_Eth_EthernetMgt.c
**
** Description      : Eth interfaces in the  LxFwd module 
**                    for the WP3 .
**                    From R2.1,transfer function from:
**                    WP_LxFwd_itfwrap_RM/WP_LxFwd_Rm_EthernetMgt.c
** Reference        : 
** 
** Contact          : 
**
** Creation date    :
**
************************************************************************/
                                                                      
/*#######################################################################
 #                                                                      #
 #  COMPILER OPTIONS                                                    #
 #                                                                      #
 ######################################################################*/
                                                                                                                                                
/*#######################################################################
 #                                                                      #
 #  INCLUDES                                                            #
 #                                                                      #
 ######################################################################*/
#ifdef __cplusplus
extern "C"{
#endif

#include <types/basic_types.h>
#include <api/wp_wddi.h>
#include <error/error.h>
#include <debug/trace.h>
#include <debug/dispatch.h> 
#include <xapi/xapi.h>
#include <BspExport/pic.h>
#include <BspExport/board.h>
#include <stdlib.h>
#include <assert/AsamAssert.h>
#include <Winpath_Startup/common.h>

#include <WP_LxFwd_itfwrap_ETH/WP_LxFwd_ETH.h>
#include <include/WP_LxFwd_Eth_Internal.h>
#include <WP_LxFwd_itfwrap_RM/WP_LxFwd_Rm.h>

#ifdef __cplusplus
}
#endif
   
static T_bool SgmiiAn_State = FALSE;

T_bool g_eth_dbg_flag = FALSE ;

#define  WPETH_ASSERT_RET(a,s,b,c)              \
  do {                                      \
       if (!(a))                             \
          {                                 \
              err_printf(ERR_COM_INV_PARAM,                                             \
                        ((g_eth_dbg_flag)?ERR_CLASS_NOTIFY_ONLY:ERR_CLASS_NON_RECOV),   \
                        "WTETH",                                                        \
                        __FILE__,                                                       \
                        __LINE__,                                                       \
                        s,b);                                                           \
              return c ;                                                                \
          }                                                                             \
     } while(0)                                                                         

#define  WPETH_ASSERT(a,s,b)              \
  do {                                      \
       if (!(a))                             \
          {                                 \
              err_printf(ERR_COM_INV_PARAM,                                             \
                        ((g_eth_dbg_flag)?ERR_CLASS_NOTIFY_ONLY:ERR_CLASS_NON_RECOV),   \
                        "WTETH",                                                        \
                        __FILE__,                                                       \
                        __LINE__,                                                       \
                        s,b);                                                           \
              return ;                                                                \
          }                                                                             \
     } while(0)

WT_ETHERNETMGT_INTERFACE_MODE  ethernetmgt_interface[WP_ENET_INTERFACE_TYPE_LAST]=
                               {
                                 WT_ETHERNETMGT_MII,           
                                 WT_ETHERNETMGT_RMII,              
                                 WT_ETHERNETMGT_GMII,              
                                 WT_ETHERNETMGT_TBI,               
                                 WT_ETHERNETMGT_SMII,              
                                 WT_ETHERNETMGT_SS_SMII,           
                                 WT_ETHERNETMGT_RGMII_10_100,      
                                 WT_ETHERNETMGT_RGMII_1000,        
                                 WT_ETHERNETMGT_RTBI,              
                                 WT_ETHERNETMGT_TBI_AN,            
                                 WT_ETHERNETMGT_SGMII_10,          
                                 WT_ETHERNETMGT_SGMII_100,         
                                 WT_ETHERNETMGT_SGMII_1000,        
                                 WT_ETHERNETMGT_SGMII_2500,        
                                 WT_ETHERNETMGT_SGMII_AN,          
                                 WT_ETHERNETMGT_1000_BASE_X,       
                                 WT_ETHERNETMGT_1000_BASE_X_AN,    
                                 WT_ETHERNETMGT_XAUI
                               };     

enum WP_ENET_INTERFACE_TYPE enet_interface[WT_ETHERNETMGT_INTERFACE_MODE_LAST]=
                               {
                                 WP_ENET_MII,                                                 
                                 WP_ENET_RMII,              
                                 WP_ENET_GMII,              
                                 WP_ENET_TBI,               
                                 WP_ENET_SMII,              
                                 WP_ENET_SS_SMII,           
                                 WP_ENET_RGMII_10_100,      
                                 WP_ENET_RGMII_1000,        
                                 WP_ENET_RTBI,              
                                 WP_ENET_TBI_AN,            
                                 WP_ENET_SGMII_10,          
                                 WP_ENET_SGMII_100,         
                                 WP_ENET_SGMII_1000,        
                                 WP_ENET_SGMII_2500,        
                                 WP_ENET_SGMII_AN,          
                                 WP_ENET_1000_BASE_X,       
                                 WP_ENET_1000_BASE_X_AN,    
                                 WP_ENET_XAUI
                               };   

static void WT_lxFwd_SetDeviceFlowControl(port_device_number deviceIdx,enum WP_ENET_FLOW_CONTROL isEnable)
{
    WP_status status;
    WP_U32 tmp_cmd;
    WP_device_enet* enet_device_params;
    WP_handle        devHandle;
    WT_Device_Info* p_device_info = 0;
        
    p_device_info = WT_lxFwd_GetDeviceInfo(deviceIdx);
    assert_r(p_device_info != NULL);
        
    WPETH_PRINTF("device_info[%d].dev_name=%s, isEnable_i=%d.\r\n", deviceIdx, p_device_info->dev_name,isEnable);
    
    WT_lxFwd_GetDevEnet(deviceIdx,&enet_device_params);
  
    enet_device_params->extended_params->rx_flowcontrol = isEnable;
    enet_device_params->extended_params->tx_flowcontrol = isEnable;
    
    tmp_cmd = WP_DEV_MOD_ENET_RX_FLOWCONTROL | WP_DEV_MOD_ENET_TX_FLOWCONTROL;

    devHandle = WT_lxFwd_GetDevHandle(deviceIdx, WT_ENET);
    assert_r ( devHandle );
    
    status = WP_DeviceDisable(devHandle, WP_DIRECTION_DUPLEX);
    terminate_on_error(devHandle, "WP_DeviceDisable", __LINE__);       

    status = WP_DeviceModify(devHandle, 
                             tmp_cmd, 
                             enet_device_params);
    terminate_on_error(devHandle, "WP_DeviceModify", __LINE__); 
    
    status = WP_DeviceEnable(devHandle, WP_DIRECTION_DUPLEX);
    terminate_on_error(devHandle, "WP_DeviceEnable", __LINE__);       
}

void WT_lxFwd_SetNniFlowControl(WT_ETHERNETMGT_PORT_DEVICE_NUMBER devNum_i, WT_ETHERNETMGT_FLOW_CONTROL isEnable_i)
{
    port_device_number deviceIdx;
    enum WP_ENET_FLOW_CONTROL isEnable;
     
    WPETH_PRINTF("Enter %s.\r\n", __FUNCTION__);
    
    WPETH_ASSERT(((devNum_i==WT_ETHERNETMGT_PORT_DEVICE_NTIO)||
                  (devNum_i==WT_ETHERNETMGT_PORT_DEVICE_NTIO_B)|| 
                  (devNum_i==WT_ETHERNETMGT_PORT_DEVICE_SUBTENDING)),
                  "WT_lxFwd_SetNniFlowControl does not support PORT_DEVICE_NUMBER %d\r\n",devNum_i);
        
    deviceIdx = (port_device_number)devNum_i ;   
                     
    isEnable = (isEnable_i == WT_ETHERNETMGT_FLOW_DISABLE ? WP_ENET_FLOW_DISABLE : WP_ENET_FLOW_ENABLE);

    WT_lxFwd_SetDeviceFlowControl(deviceIdx,isEnable);

    WPETH_PRINTF("Exit %s: Success.\r\n", __FUNCTION__);
} 

void WT_lxFwd_SetUniFlowControl(u_int16 slot, u_int16 port, WT_ETHERNETMGT_FLOW_CONTROL isEnable_i)
{
    u_int16 deviceIdx;
    enum WP_ENET_FLOW_CONTROL isEnable;

    WPETH_PRINTF("Enter %s. slot=0x%x, port=0x%x\r\n", __FUNCTION__,slot,port);
    
    deviceIdx = WT_lxFwd_GetDeviceIndexForLt(slot, port); //port is from 0
           
    isEnable = (isEnable_i == WT_ETHERNETMGT_FLOW_DISABLE ? WP_ENET_FLOW_DISABLE : WP_ENET_FLOW_ENABLE);

    WT_lxFwd_SetDeviceFlowControl(deviceIdx,isEnable);
    
    WPETH_PRINTF("Exit %s: Success.\r\n", __FUNCTION__);
} 

static void WT_lxFwd_GetDeviceFlowControl(port_device_number deviceIdx,WT_ETHERNETMGT_FLOW_CONTROL* isEnable_o)
{
    enum WP_ENET_FLOW_CONTROL isEnable;
    WP_device_enet_ex* enet_ex_params;
    WT_Device_Info* p_device_info = 0;
    
    p_device_info = WT_lxFwd_GetDeviceInfo(deviceIdx);
    assert_r(p_device_info != NULL);
    
    WT_lxFwd_GetDevEnetEx(deviceIdx,&enet_ex_params);

    assert_r(enet_ex_params->rx_flowcontrol == 
             enet_ex_params->tx_flowcontrol);
    isEnable = enet_ex_params->rx_flowcontrol;
    *isEnable_o = (isEnable == WP_ENET_FLOW_DISABLE ? WT_ETHERNETMGT_FLOW_DISABLE : WT_ETHERNETMGT_FLOW_ENABLE);
       
    WPETH_PRINTF("device_info[%d].dev_name=%s, isEnable_i=%d.\r\n", deviceIdx, p_device_info->dev_name,*isEnable_o);    
}

void WT_lxFwd_GetNniFlowControl(WT_ETHERNETMGT_PORT_DEVICE_NUMBER devNum_i, WT_ETHERNETMGT_FLOW_CONTROL* isEnable_o)
{
    port_device_number deviceIdx;

    WPETH_PRINTF("Enter %s.\r\n", __FUNCTION__);
    
    WPETH_ASSERT(((devNum_i==WT_ETHERNETMGT_PORT_DEVICE_NTIO)||
                  (devNum_i==WT_ETHERNETMGT_PORT_DEVICE_NTIO_B)|| 
(devNum_i==WT_ETHERNETMGT_PORT_DEVICE_SUBTENDING)),
                  "WT_lxFwd_GetNniFlowControl does not support PORT_DEVICE_NUMBER %d\r\n",devNum_i); 
                   
    deviceIdx = (port_device_number)devNum_i ;    

    WT_lxFwd_GetDeviceFlowControl(deviceIdx,isEnable_o);
    
    WPETH_PRINTF("Exit %s: Success.\r\n", __FUNCTION__);
} 

void WT_lxFwd_GetUniFlowControl(u_int16 slot, u_int16 port, WT_ETHERNETMGT_FLOW_CONTROL* isEnable_o)
{
    u_int16 deviceIdx;

    WPETH_PRINTF("Enter %s. slot=0x%x , port = 0x%x \r\n", __FUNCTION__,slot,port);
           
    deviceIdx = WT_lxFwd_GetDeviceIndexForLt(slot, port); //port is from 0

    WT_lxFwd_GetDeviceFlowControl(deviceIdx,isEnable_o);
   
    WPETH_PRINTF("Exit %s: Success.\r\n", __FUNCTION__);
} 

static void WT_lxFwd_GetDevicePauseCounter(port_device_number deviceIdx,u_int64* rxPause_o, u_int64* txPause_o)
{
    WP_stats_enet deviceStatics = {0};
    WP_status status;
    WP_handle        devHandle;
    WT_Device_Info* p_device_info = 0;
    
    p_device_info = WT_lxFwd_GetDeviceInfo(deviceIdx);
    assert_r(p_device_info != NULL);
        
    WPETH_PRINTF("device_info[%d].dev_name=%s \r\n", deviceIdx, p_device_info->dev_name);
         
    devHandle = WT_lxFwd_GetDevHandle(deviceIdx, WT_ENET);
    assert_r ( devHandle );

    status = WP_DeviceStatistics(devHandle, &deviceStatics);
    assert_r(!WP_ERROR_P(status));
   
    *rxPause_o = deviceStatics.rx_mac_pause;
    *txPause_o = deviceStatics.tx_mac_pause;

    WPETH_PRINTF("rxPause = %d, txPause = %d \r\n",*rxPause_o, *txPause_o);    
}

void WT_lxFwd_GetNniPauseCounter(WT_ETHERNETMGT_PORT_DEVICE_NUMBER devNum_i, u_int64* rxPause_o, u_int64* txPause_o)
{
    port_device_number deviceIdx;

    WPETH_PRINTF("Enter %s.\r\n", __FUNCTION__);
    
    WPETH_ASSERT(((devNum_i==WT_ETHERNETMGT_PORT_DEVICE_NTIO)||(devNum_i==WT_ETHERNETMGT_PORT_DEVICE_NTIO_B)||
(devNum_i==WT_ETHERNETMGT_PORT_DEVICE_SUBTENDING)),
                  "WT_lxFwd_GetNniPauseCounter does not support PORT_DEVICE_NUMBER %d\r\n",devNum_i); 
                  
    deviceIdx = (port_device_number)devNum_i ;

    WT_lxFwd_GetDevicePauseCounter(deviceIdx,rxPause_o,txPause_o);    
    
    WPETH_PRINTF("Exit %s: Success.\r\n", __FUNCTION__);
}

void WT_lxFwd_GetUniPauseCounter(u_int16 slot, u_int16 port, u_int64* rxPause_o, u_int64* txPause_o)
{
    u_int16 deviceIdx;

    WPETH_PRINTF("Enter %s. slot=0x%x , port = 0x%x \r\n", __FUNCTION__,slot,port);
           
    deviceIdx = WT_lxFwd_GetDeviceIndexForLt(slot, port); //port is from 0

    WT_lxFwd_GetDevicePauseCounter(deviceIdx,rxPause_o,txPause_o); 
   
    WPETH_PRINTF("Exit %s: Success.\r\n", __FUNCTION__);    
}

WT_ETHERNETMGT_LINK_STATUS WT_lxFwd_GetLinkStatus(WT_ETHERNETMGT_PORT_DEVICE_NUMBER devNum_i)
{
    u_int32 addr = 0;
    u_int32 tstat = 0;
    port_device_number deviceIdx;
    WT_interface *winnet = NULL;
    WINNET_NUMBER  win_number;
    WINNET_GROUP   win_group;
     
    WPETH_PRINTF("Enter %s.\r\n", __FUNCTION__);

    deviceIdx = (port_device_number)devNum_i ;
          
    winnet = WT_lxFwd_GetWinnet(WT_lxFwd_GetPortIdx(deviceIdx));
    assert_r(winnet != NULL);      
    win_number = winnet->win_info.win_number;
    win_group  = winnet->win_info.win_group;  

    if((win_number==WINNET_NOT_USE)||(win_group==GROUP_NOT_USE))
    {
       return WT_ETHERNETMGT_LINK_DOWN;
    } 
                  
    WPETH_PRINTF("available_wnets[%d].port_name=%s win_number=%d,win_group=%d\r\n",
                  WT_lxFwd_GetPortIdx(deviceIdx), winnet->port_name,win_number,win_group);                

    addr = WINNET_TSTAT_OFFSET(win_number, win_group);
    
    WT_lxFwd_Wp3RegRead(addr, &tstat);

    WPETH_PRINTF("Exit %s.\r\n", __FUNCTION__);

    if((tstat & WPI_WINNET_TSTAT_LINK_STATUS_F(1)) != 0)
    {
        WPETH_PRINTF("link up  \r\n");
        return WT_ETHERNETMGT_LINK_UP;
    }    
    else 
    {   WPETH_PRINTF("link down  \r\n");    
        return WT_ETHERNETMGT_LINK_DOWN;
    }
}

static void WT_lxFwd_Mac1Rx(WT_ETHERNETMGT_PORT_DEVICE_NUMBER devNum_i, T_bool isEnabled_i)
{
    port_device_number deviceIdx;
    u_int32 mac1Addr = 0;
    u_int32 mac1 = 0;
    WINNET_NUMBER  win_number;
    WINNET_GROUP   win_group;
    WINNET_INTERFACE_NUMBER  win_interface;
    WT_interface *winnet = NULL;
        
    WPETH_PRINTF("Enter %s.\r\n", __FUNCTION__);

    switch(devNum_i)
    {
   case WT_ETHERNETMGT_PORT_DEVICE_NTIO:
   case WT_ETHERNETMGT_PORT_DEVICE_NTIO_B:
   case WT_ETHERNETMGT_PORT_DEVICE_SUBTENDING: 
        {
            deviceIdx = (port_device_number)devNum_i ;           
           
            winnet = WT_lxFwd_GetWinnet(WT_lxFwd_GetPortIdx(deviceIdx));
            assert_r(winnet != NULL);      
            win_number = winnet->win_info.win_number;
            win_group  = winnet->win_info.win_group;  

            WPETH_ASSERT(((win_number!=WINNET_NOT_USE)&&(win_group!=GROUP_NOT_USE)),
                          "Not suppport to get port %s  Mac1 ,winnet is not used.\r\n",
                           winnet->port_name);

            WPETH_PRINTF("available_wnets[%d].port_name=%s win_number=%d,win_group=%d\r\n",
                          WT_lxFwd_GetPortIdx(deviceIdx), winnet->port_name,win_number,win_group);                
            
            if(win_group==G0)
            {
                win_interface = WINNET_INTERFACE_0;
            }
            else
            {
                win_interface = WINNET_INTERFACE_4;
            }
            mac1Addr = WINNET_MAC1_OFFSET(win_number, win_interface);  
            break;         
        }       
    default:
        err_printf(E_lxFwd_Err_InternalError, ERR_CLASS_RECOV, 
                   "WTETH", __FILE__, __LINE__, 
                   "Not suppport to reset port_device_number=%d's winnet interface.\r\n", 
                   devNum_i);
        return;
    }

    WT_lxFwd_Wp3RegRead(mac1Addr, &mac1);
    
    if(isEnabled_i == TRUE)
    {
        mac1 = mac1 | WPI_WINNET_MAC1_RECEIVE_ENABLE_F(1);
        mac1 = mac1 | WPI_WINNET_MAC1_TRANSMIT_ENABLE_F(1);
        
    }
    else
    {
        mac1 = mac1 & (~WPI_WINNET_MAC1_RECEIVE_ENABLE_F(1));
        mac1 = mac1 & (~WPI_WINNET_MAC1_TRANSMIT_ENABLE_F(1));
    }

    WT_lxFwd_Wp3RegWrite(mac1Addr, mac1);

    WPETH_PRINTF("Exit %s.\r\n", __FUNCTION__);
}

void WT_lxFwd_ModifyPortInterfaceMode(u_int16 devNum_i, WT_ETHERNETMGT_INTERFACE_MODE interfaceMode_i)
{
    WP_status status;
    enum WP_ENET_INTERFACE_TYPE mode;
    WP_port_enet* enet_port_params;
    T_bool isEnet;
    WP_handle portHandle;
    port_device_number deviceIdx;
    port_number portIdx ;
    static u_int32 flag = 1;

    WPETH_PRINTF("Enter %s, devNum_i = %d\r\n", __FUNCTION__, devNum_i);
    SgmiiAn_State  = 0;
    deviceIdx = (port_device_number)devNum_i ;            
    portIdx = WT_lxFwd_GetPortIdx(deviceIdx);
    WT_lxFwd_GetPortEnet(portIdx,&enet_port_params,&isEnet);   

    WPETH_ASSERT((isEnet==TRUE),"WT_lxFwd_ModifyPortInterfaceMode deviceIdx=%d is not WT_ENET\r\n",deviceIdx);

    if((interfaceMode_i<WT_ETHERNETMGT_INTERFACE_MODE_LAST)&&(interfaceMode_i>=WT_ETHERNETMGT_MII))
    {
        mode= enet_interface[interfaceMode_i];   
    }    
    else
    {
        mode= WP_ENET_INTERFACE_TYPE_LAST;
    }

    WPETH_PRINTF("previous mode=%d\r\n  current mode=%d\r\n", 
                  enet_port_params->interface_mode,
                  mode);
	if (flag)
	{
            board_set_intr_handler(
                PIC_INTR53, 
                (void (*)(u_int32 dev_num))WPI_HwWinnetSgmiiAnProceed, 
                0); //45+8
		flag = 0; 
	}


    if(enet_port_params->interface_mode!= mode)
    {
        if(((devNum_i == WT_ETHERNETMGT_PORT_DEVICE_NTIO)||
           (devNum_i == WT_ETHERNETMGT_PORT_DEVICE_NTIO_B)) 
             && (mode != WP_ENET_SGMII_AN))
        {
            board_mask_intr(PIC_INTR53);
            xtm_wkafter(5);
        }

        WT_lxFwd_DisableDevice(deviceIdx, WT_ENET);
        xtm_wkafter(5);
  

        portHandle = WT_lxFwd_GetPortHandle(portIdx);
        status = WP_PortDisable(portHandle, WP_DIRECTION_DUPLEX);
        terminate_on_error(status, "WP_PortDisable()", __LINE__);

        xtm_wkafter(5);

        enet_port_params->interface_mode = mode;
        status = WP_PortModify(portHandle, 
                               WP_PORT_MOD_ENET_INTERFACE_MODE, 
                               enet_port_params);
        terminate_on_error(status, "WP_PortModify()", __LINE__);
        
        xtm_wkafter(5);


        if((devNum_i == WT_ETHERNETMGT_PORT_DEVICE_NTIO)&& (mode != WP_ENET_SGMII_AN))
            WT_lxFwd_Mac1Rx(WT_ETHERNETMGT_PORT_DEVICE_NTIO, TRUE);

        if((devNum_i == WT_ETHERNETMGT_PORT_DEVICE_NTIO_B)&& (mode != WP_ENET_SGMII_AN))
            WT_lxFwd_Mac1Rx(WT_ETHERNETMGT_PORT_DEVICE_NTIO_B, TRUE);

        status = WP_PortEnable(portHandle, WP_DIRECTION_DUPLEX);

        terminate_on_error(status, "WP_PortEnable()", __LINE__);


        xtm_wkafter(5);
        WT_lxFwd_EnableDevice(deviceIdx, WT_ENET);

        if(((devNum_i == WT_ETHERNETMGT_PORT_DEVICE_NTIO)||
           (devNum_i == WT_ETHERNETMGT_PORT_DEVICE_NTIO_B)) && (mode == WP_ENET_SGMII_AN))
        {
            board_unmask_intr(PIC_INTR53);
            xtm_wkafter(5);
        }
    }

    WPETH_PRINTF("Exit %s\r\n", __FUNCTION__);
}

WT_ETHERNETMGT_INTERFACE_MODE WT_lxFwd_GetPortInterfaceMode(u_int16 devNum_i)
{
    WT_ETHERNETMGT_INTERFACE_MODE mode;
    WP_port_enet* enet_port_params;
    T_bool isEnet;
    port_device_number deviceIdx;
    WP_U8 enet_port_interface;
    
    WPETH_PRINTF("Enter %s, devNum_i = %d\r\n", __FUNCTION__, devNum_i);

    deviceIdx = (port_device_number)devNum_i ;           

    WT_lxFwd_GetPortEnet(WT_lxFwd_GetPortIdx(deviceIdx),&enet_port_params,&isEnet);   
    if(isEnet == FALSE )
    {
      return WT_ETHERNETMGT_INTERFACE_MODE_LAST;
    }
      
    enet_port_interface = enet_port_params->interface_mode;
    if((enet_port_interface<WP_ENET_INTERFACE_TYPE_LAST)&&(enet_port_interface>=WP_ENET_MII))
    {
        mode= ethernetmgt_interface[enet_port_interface];   
    }    
    else
    {
        mode= WT_ETHERNETMGT_INTERFACE_MODE_LAST;
    }

    WPETH_PRINTF("Exit %s mode=%d.\r\n", __FUNCTION__,mode);
    return mode;
}

static T_lxFwd_Error WT_lxFwd_GetDeviceCounter(port_device_number deviceIdx,Wt_EthernetMgt_Counter* counter_o)
{
    WP_status          status;
    WP_stats_enet      deviceStatics;
    WP_handle          enetDevHandle;
    WT_Device_Info* p_device_info = 0;
    
    p_device_info = WT_lxFwd_GetDeviceInfo(deviceIdx);
    assert_r(p_device_info != NULL);
           
    memset(&deviceStatics, 0, sizeof(deviceStatics));
    enetDevHandle = WT_lxFwd_GetDevHandle(deviceIdx, WT_ENET);
    if ( enetDevHandle == 0 )
    {
        err_printf(E_lxFwd_Err_IndexNotExist, ERR_CLASS_RECOV, 
                   "WTETH", __FILE__, __LINE__, 
                   "DEVICE %s return error handle 0x%x: \r\n", 
                   p_device_info->dev_name, enetDevHandle);
        return E_lxFwd_Err_IndexNotExist;
    }

    status = WP_DeviceStatistics(enetDevHandle, &deviceStatics);
    if (WP_ERROR_P(status))
    {
        err_printf(E_lxFwd_Err_InternalError, ERR_CLASS_RECOV, 
                   "WTETH", __FILE__, __LINE__, 
                   "Can not get device %s's statistics.\r\n", 
                   p_device_info->dev_name);
        return E_lxFwd_Err_InternalError;        
    }

    counter_o->rx_bytes             = deviceStatics.rx_bytes;
    counter_o->rx_packets           = deviceStatics.rx_packets;
    counter_o->rx_err_fcs           = deviceStatics.rx_err_fcs;
    counter_o->rx_multicast         = deviceStatics.rx_multicast;
    counter_o->rx_broadcast         = deviceStatics.rx_broadcast;
    counter_o->rx_mac_control       = deviceStatics.rx_mac_control;
    counter_o->rx_mac_pause         = deviceStatics.rx_mac_pause;
    counter_o->rx_mac_unknown       = deviceStatics.rx_mac_unknown;
    counter_o->rx_err_alignment     = deviceStatics.rx_err_alignment;
    counter_o->rx_err_length        = deviceStatics.rx_err_length;
    counter_o->rx_err_code          = deviceStatics.rx_err_code;
    counter_o->rx_false_carrier     = deviceStatics.rx_false_carrier;
    counter_o->rx_undersize         = deviceStatics.rx_undersize;
    counter_o->rx_oversize          = deviceStatics.rx_oversize;
    counter_o->rx_fragments         = deviceStatics.rx_fragments;
    counter_o->rx_jabber            = deviceStatics.rx_jabber;
    counter_o->rx_dropped           = deviceStatics.rx_dropped;
    counter_o->rx_err_host_full     = deviceStatics.rx_err_host_full;
    counter_o->rx_err_fbp_underrun  = deviceStatics.rx_err_fbp_underrun;
    counter_o->rx_err_nonvalid_mac  = deviceStatics.rx_err_nonvalid_mac;
    counter_o->rx_err_mru           = deviceStatics.rx_err_mru;
    counter_o->rx_err_sw_state_machine = deviceStatics.rx_err_sw_state_machine;
    counter_o->rx_err_sdu           = deviceStatics.rx_err_sdu;
    counter_o->rx_err_overrun       = deviceStatics.rx_err_overrun;
    counter_o->tx_bytes             = deviceStatics.tx_bytes;
    counter_o->tx_packets           = deviceStatics.tx_packets;
    counter_o->tx_multicast         = deviceStatics.tx_multicast;
    counter_o->tx_broadcast         = deviceStatics.tx_broadcast;
    counter_o->tx_mac_pause         = deviceStatics.tx_mac_pause;
    counter_o->tx_defer             = deviceStatics.tx_defer;
    counter_o->tx_excess_defer      = deviceStatics.tx_excess_defer;
    counter_o->tx_single_collision  = deviceStatics.tx_single_collision;
    counter_o->tx_multi_collision   = deviceStatics.tx_multi_collision;
    counter_o->tx_late_collision    = deviceStatics.tx_late_collision;
    counter_o->tx_excess_collision  = deviceStatics.tx_excess_collision;
    counter_o->tx_no_collision      = deviceStatics.tx_no_collision;
    counter_o->tx_mac_pause_honored = deviceStatics.tx_mac_pause_honored;
    counter_o->tx_dropped           = deviceStatics.tx_dropped;
    counter_o->tx_jabber            = deviceStatics.tx_jabber;
    counter_o->tx_err_fcs           = deviceStatics.tx_err_fcs;
    counter_o->tx_control           = deviceStatics.tx_control;
    counter_o->tx_oversize          = deviceStatics.tx_oversize;
    counter_o->tx_undersize         = deviceStatics.tx_undersize;
    counter_o->tx_fragments         = deviceStatics.tx_fragments;   
    counter_o->tx_err_underrun      = deviceStatics.tx_err_underrun ; 
    return E_lxFwd_Err_NoError; 
}

T_lxFwd_Error WT_lxFwd_GetNniCounter(WT_ETHERNETMGT_PORT_DEVICE_NUMBER devNum_i, 
                                     Wt_EthernetMgt_Counter* counter_o)
{
    port_device_number deviceIdx;
    u_int32 ret;

    WPETH_PRINTF("Enter %s.\r\n", __FUNCTION__);
    
    WPETH_ASSERT_RET(((devNum_i==WT_ETHERNETMGT_PORT_DEVICE_NTIO)||
(devNum_i==WT_ETHERNETMGT_PORT_DEVICE_NTIO_B)||
(devNum_i==WT_ETHERNETMGT_PORT_DEVICE_SUBTENDING)||
                  (devNum_i==WT_ETHERNETMGT_PORT_DEVICE_GPON0)),
                  "WT_lxFwd_GetNniCounter does not support PORT_DEVICE_NUMBER %d\r\n",
                  devNum_i,E_lxFwd_Err_IndexNotExist);

    deviceIdx = (port_device_number)devNum_i;           
    
    WPETH_PRINTF("deviceIdx = %d \r\n", deviceIdx);      

    ret=WT_lxFwd_GetDeviceCounter(deviceIdx,counter_o);

    WPETH_PRINTF("Exit %s, ret=%d \r\n", __FUNCTION__,ret);

    return ret;
}

T_lxFwd_Error WT_lxFwd_GetUniCounter(u_int16 slot, u_int16 port, Wt_EthernetMgt_Counter* counter_o)
{
    port_device_number   deviceIdx;
    u_int32 ret;

    WPETH_PRINTF("Enter %s. slot=0x%x, port=0x%x \r\n", __FUNCTION__,slot,port);
    
    deviceIdx = WT_lxFwd_GetDeviceIndexForLt(slot, port); //port is from 0
               
    WPETH_PRINTF("deviceIdx = %d \r\n", deviceIdx);      

    ret=WT_lxFwd_GetDeviceCounter(deviceIdx,counter_o);

    WPETH_PRINTF("Exit %s, ret=%d \r\n", __FUNCTION__,ret);

    return ret;

}

WT_ETHERNETMGT_LINK_STATUS WT_lxFwd_GetSfpLinkStatus(u_int8 SfpNo)  
{
    if ( SfpNo==0 )
    {
        return WT_lxFwd_GetLinkStatus(WT_ETHERNETMGT_PORT_DEVICE_NTIO);
    }
    else if ( SfpNo==1 )
    {
        return WT_lxFwd_GetLinkStatus(WT_ETHERNETMGT_PORT_DEVICE_NTIO_B);
    }
    else
    {
        err_printf(E_lxFwd_Err_NotValidInput, ERR_CLASS_RECOV, 
           "WTETH", __FILE__, __LINE__, 
           "SfpNo=%d error\r\n",SfpNo); 
        return WT_ETHERNETMGT_LINK_DOWN;
    }    
}
