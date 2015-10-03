/*****************************************************************************
 * (C) Copyright 2000-2010, Wintegra. All rights reserved.
 * WINTEGRA CONFIDENTIAL PROPRIETARY
 * Contains Confidential Proprietary information of Wintegra.
 * Reverse engineering is prohibited.
 * The copyright notice does not imply publication.
 ****************************************************************************/

/*****************************************************************************
 *
 * File: wufei_hw_fm.h
 *
 * Purpose: the UFE Fifo Manager macro and structures
 *
 ****************************************************************************/
#ifndef WUFEI_HW_FM_H
#define WUFEI_HW_FM_H

#ifndef WUFE_SYSTEM_H
#include "wufe_system.h"
#endif

#ifndef WUFEI_HW_TYPES_H
#include "wufei_hw_types.h"
#endif

#define WUFEI_MAX_NUM_PRIORITY_TABLE 2

typedef struct
{
      WUFEI_reg_space priority_table_param_high;
      WUFEI_reg_space priority_table_param_low;
}WUFEI_hw_fifo_pt;

typedef struct
{
      WUFEI_reg_space fm_tx_vfp_rd_ptr;
      WUFEI_reg_space fm_tx_vfp_wr_ptr;
      WUFEI_reg_space fm_tx_vfp_last_counter;
      WUFEI_reg_space fm_tx_vfp_wait_counter;
      WUFEI_reg_space fm_tx_vfp_max_req_stx;
      WUFEI_reg_space fm_tx_vfp_reserved[11];
}WUFEI_hw_fifo_vfp_tx;

#define WUFEI_FM_VFP_TX_MAX_REQ_S (0)
#define WUFEI_FM_VFP_TX_MAX_REQ_W (4)
#define WUFEI_FM_VFP_TX_MAX_REQ_F(v) WUFEI_FIELD(v, WUFEI_FM_VFP_TX_MAX_REQ_S)
#define WUFEI_FM_VFP_TX_MAX_REQ_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_VFP_TX_MAX_REQ_S, WUFEI_FM_VFP_TX_MAX_REQ_W)
#define WUFEI_FM_VFP_TX_MAX_REQ_M \
        WUFEI_MASK(WUFEI_FM_VFP_TX_MAX_REQ_S, WUFEI_FM_VFP_TX_MAX_REQ_W)

#define WUFEI_FM_VFP_TX_STX_S (4)
#define WUFEI_FM_VFP_TX_STX_W (2)
#define WUFEI_FM_VFP_TX_STX_F(v) WUFEI_FIELD(v, WUFEI_FM_VFP_TX_STX_S)
#define WUFEI_FM_VFP_TX_STX_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_VFP_TX_STX_S, WUFEI_FM_VFP_TX_STX_W)
#define WUFEI_FM_VFP_TX_STX_M \
        WUFEI_MASK(WUFEI_FM_VFP_TX_STX_S, WUFEI_FM_VFP_TX_STX_W)

typedef struct
{
      WUFEI_reg_space fm_rx_vfp_rd_ptr;
      WUFEI_reg_space fm_rx_vfp_data_wr_ptr;
      WUFEI_reg_space fm_rx_vfp_bd_wr_ptr;
      WUFEI_reg_space fm_rx_vfp_fifo_mask;
      WUFEI_reg_space fm_rx_fbp_reserved[12];
}WUFEI_hw_fifo_vfp_rx;

typedef struct
{
      WUFEI_reg_space fm_ind_low; /*FM indirect address low*/
      WUFEI_reg_space fm_ind_high; /* FM indirect address high*/
      WUFEI_reg_space fm_ind_cmd; /* FM indirect cmd*/
      WUFEI_reg_space fm_ind_data; /* FM indirect data*/
      WUFEI_reg_space reserved1[4]; /*Reserved for future enhancements*/
      WUFEI_reg_space fm_int_reg; /*FM interrupt register*/
      WUFEI_reg_space fm_int_msk_reg; /*FM interrupt mask register*/
      WUFEI_reg_space fm_int_read_rx_fifo; /*FM interrupt read RX fifo*/
      WUFEI_reg_space fm_int_read_tx_fifo; /*FM interrupt read TX fifo*/
      WUFEI_reg_space reserved2[4]; /*Reserved for future enhancements*/
      WUFEI_reg_space fm_mode_reg; /*FM mode register*/
      WUFEI_hw_fifo_pt fm_rx_priority_table[WUFEI_MAX_NUM_PRIORITY_TABLE]; /*FM Rx priority table parameters*/
      WUFEI_hw_fifo_pt fm_tx_priority_table[WUFEI_MAX_NUM_PRIORITY_TABLE]; /*FM Tx priority table parameters*/
      WUFEI_reg_space reserved3[16];
      WUFEI_reg_space fm_ddr_indication; /*FM DDR indication*/
      WUFEI_reg_space fm_ddr_read_ctrl; /*FM DDR read control*/
      WUFEI_reg_space fm_ddr_read_fifo; /*FM DDR read fifo*/
      WUFEI_reg_space reserved4[212];
      WUFEI_hw_fifo_vfp_tx fm_tx_vfp[12];
      WUFEI_reg_space reserved5[64];
      WUFEI_hw_fifo_vfp_rx fm_rx_vfp[12];
      WUFEI_reg_space reserved6[48];
      WUFEI_reg_space fm_rx_vfp_int_info;
}WUFEI_hw_fm;





/*Bank Weights*/
#define WUFEI_FM_BANK_DS0_WEIGHT 64
#define WUFEI_FM_BANK_E3_WEIGHT 34368
#define WUFEI_FM_BANK_DS3_WEIGHT 44736
#define WUFEI_FM_BANK_VC11_WEIGHT 1492
#define WUFEI_FM_BANK_VC12_WEIGHT 1932
#define WUFEI_FM_BANK_VC3_WEIGHT 43008
#define WUFEI_FM_BANK_VC4_WEIGHT 133120
#define WUFEI_FM_BANK_VC44C_WEIGHT 594432

#define WUFEI_FM_NUM_OF_SLOTS_E1 32
#define WUFEI_FM_NUM_OF_SLOTS_T1 24
#define WUFEI_FM_NUM_OF_SLOTS_DCC_MS 9
#define WUFEI_FM_NUM_OF_SLOTS_DCC_RS 3

#define WUFEI_FM_PORT_CONF_PRIORITY 0
#define WUFEI_FM_PORT_HDLC_CONF_PRIORITY 1
#define WUFEI_FM_PORT_CONF_MAX_BUFFER 4
#define WUFEI_FM_PORT_HDLC_CONF_MAX_BUFFER 8
#define MAX_NUM_OF_FM_INTERRUPT_READS 10

/*Fifo Manager Mode Register*/

#define WUFEI_FM_RX_MODE_ENABLE_S (0)
#define WUFEI_FM_RX_MODE_ENABLE_W (1)
#define WUFEI_FM_RX_MODE_ENABLE_F(v) WUFEI_FIELD(v, WUFEI_FM_RX_MODE_ENABLE_S)
#define WUFEI_FM_RX_MODE_ENABLE_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_RX_MODE_ENABLE_S, WUFEI_FM_RX_MODE_ENABLE_W)
#define WUFEI_FM_RX_MODE_ENABLE_M \
        WUFEI_MASK(WUFEI_FM_RX_MODE_ENABLE_S, WUFEI_FM_RX_MODE_ENABLE_W)

#define WUFEI_FM_TX_MODE_ENABLE_S (1)
#define WUFEI_FM_TX_MODE_ENABLE_W (1)
#define WUFEI_FM_TX_MODE_ENABLE_F(v) WUFEI_FIELD(v, WUFEI_FM_TX_MODE_ENABLE_S)
#define WUFEI_FM_TX_MODE_ENABLE_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_TX_MODE_ENABLE_S, WUFEI_FM_TX_MODE_ENABLE_W)
#define WUFEI_FM_TX_MODE_ENABLE_M \
        WUFEI_MASK(WUFEI_FM_TX_MODE_ENABLE_S, WUFEI_FM_TX_MODE_ENABLE_W)

#define WUFEI_FM_LINE_LOOPBACK_S (2)
#define WUFEI_FM_LINE_LOOPBACK_W (1)
#define WUFEI_FM_LINE_LOOPBACK_F(v) WUFEI_FIELD(v, WUFEI_FM_LINE_LOOPBACK_S)
#define WUFEI_FM_LINE_LOOPBACK_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_LINE_LOOPBACK_S, WUFEI_FM_LINE_LOOPBACK_W)
#define WUFEI_FM_LINE_LOOPBACK_M \
        WUFEI_MASK(WUFEI_FM_LINE_LOOPBACK_S, WUFEI_FM_LINE_LOOPBACK_W)

/*Fifo Manager Priority Registers*/

#define WUFEI_FM_PRIORITY_FILL_LVL_0_S (0)
#define WUFEI_FM_PRIORITY_FILL_LVL_0_W (3)
#define WUFEI_FM_PRIORITY_FILL_LVL_0_F(v) WUFEI_FIELD(v, WUFEI_FM_PRIORITY_FILL_LVL_0_S)
#define WUFEI_FM_PRIORITY_FILL_LVL_0_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_PRIORITY_FILL_LVL_0_S, WUFEI_FM_PRIORITY_FILL_LVL_0_W)
#define WUFEI_FM_PRIORITY_FILL_LVL_0_M \
        WUFEI_MASK(WUFEI_FM_PRIORITY_FILL_LVL_0_S, WUFEI_FM_PRIORITY_FILL_LVL_0_W)

#define WUFEI_FM_PRIORITY_FILL_LVL_1_S (3)
#define WUFEI_FM_PRIORITY_FILL_LVL_1_W (3)
#define WUFEI_FM_PRIORITY_FILL_LVL_1_F(v) WUFEI_FIELD(v, WUFEI_FM_PRIORITY_FILL_LVL_1_S)
#define WUFEI_FM_PRIORITY_FILL_LVL_1_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_PRIORITY_FILL_LVL_1_S, WUFEI_FM_PRIORITY_FILL_LVL_1_W)
#define WUFEI_FM_PRIORITY_FILL_LVL_1_M \
        WUFEI_MASK(WUFEI_FM_PRIORITY_FILL_LVL_1_S, WUFEI_FM_PRIORITY_FILL_LVL_1_W)

#define WUFEI_FM_PRIORITY_FILL_LVL_2_S (8)
#define WUFEI_FM_PRIORITY_FILL_LVL_2_W (3)
#define WUFEI_FM_PRIORITY_FILL_LVL_2_F(v) WUFEI_FIELD(v, WUFEI_FM_PRIORITY_FILL_LVL_2_S)
#define WUFEI_FM_PRIORITY_FILL_LVL_2_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_PRIORITY_FILL_LVL_2_S, WUFEI_FM_PRIORITY_FILL_LVL_2_W)
#define WUFEI_FM_PRIORITY_FILL_LVL_2_M \
        WUFEI_MASK(WUFEI_FM_PRIORITY_FILL_LVL_2_S, WUFEI_FM_PRIORITY_FILL_LVL_2_W)

#define WUFEI_FM_PRIORITY_FILL_LVL_3_S (11)
#define WUFEI_FM_PRIORITY_FILL_LVL_3_W (3)
#define WUFEI_FM_PRIORITY_FILL_LVL_3_F(v) WUFEI_FIELD(v, WUFEI_FM_PRIORITY_FILL_LVL_3_S)
#define WUFEI_FM_PRIORITY_FILL_LVL_3_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_PRIORITY_FILL_LVL_3_S, WUFEI_FM_PRIORITY_FILL_LVL_3_W)
#define WUFEI_FM_PRIORITY_FILL_LVL_3_M \
        WUFEI_MASK(WUFEI_FM_PRIORITY_FILL_LVL_3_S, WUFEI_FM_PRIORITY_FILL_LVL_3_W)

#define WUFEI_FM_PRIORITY_FILL_LVL_4_S (0)
#define WUFEI_FM_PRIORITY_FILL_LVL_4_W (3)
#define WUFEI_FM_PRIORITY_FILL_LVL_4_F(v) WUFEI_FIELD(v, WUFEI_FM_PRIORITY_FILL_LVL_4_S)
#define WUFEI_FM_PRIORITY_FILL_LVL_4_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_PRIORITY_FILL_LVL_4_S, WUFEI_FM_PRIORITY_FILL_LVL_4_W)
#define WUFEI_FM_PRIORITY_FILL_LVL_4_M \
        WUFEI_MASK(WUFEI_FM_PRIORITY_FILL_LVL_4_S, WUFEI_FM_PRIORITY_FILL_LVL_4_W)

#define WUFEI_FM_PRIORITY_FILL_LVL_5_S (3)
#define WUFEI_FM_PRIORITY_FILL_LVL_5_W (3)
#define WUFEI_FM_PRIORITY_FILL_LVL_5_F(v) WUFEI_FIELD(v, WUFEI_FM_PRIORITY_FILL_LVL_5_S)
#define WUFEI_FM_PRIORITY_FILL_LVL_5_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_PRIORITY_FILL_LVL_5_S, WUFEI_FM_PRIORITY_FILL_LVL_5_W)
#define WUFEI_FM_PRIORITY_FILL_LVL_5_M \
        WUFEI_MASK(WUFEI_FM_PRIORITY_FILL_LVL_5_S, WUFEI_FM_PRIORITY_FILL_LVL_5_W)

#define WUFEI_FM_PRIORITY_FILL_LVL_6_S (8)
#define WUFEI_FM_PRIORITY_FILL_LVL_6_W (3)
#define WUFEI_FM_PRIORITY_FILL_LVL_6_F(v) WUFEI_FIELD(v, WUFEI_FM_PRIORITY_FILL_LVL_6_S)
#define WUFEI_FM_PRIORITY_FILL_LVL_6_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_PRIORITY_FILL_LVL_6_S, WUFEI_FM_PRIORITY_FILL_LVL_6_W)
#define WUFEI_FM_PRIORITY_FILL_LVL_6_M \
        WUFEI_MASK(WUFEI_FM_PRIORITY_FILL_LVL_6_S, WUFEI_FM_PRIORITY_FILL_LVL_6_W)

#define WUFEI_FM_PRIORITY_FILL_LVL_7_S (11)
#define WUFEI_FM_PRIORITY_FILL_LVL_7_W (3)
#define WUFEI_FM_PRIORITY_FILL_LVL_7_F(v) WUFEI_FIELD(v, WUFEI_FM_PRIORITY_FILL_LVL_7_S)
#define WUFEI_FM_PRIORITY_FILL_LVL_7_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_PRIORITY_FILL_LVL_7_S, WUFEI_FM_PRIORITY_FILL_LVL_7_W)
#define WUFEI_FM_PRIORITY_FILL_LVL_7_M \
        WUFEI_MASK(WUFEI_FM_PRIORITY_FILL_LVL_7_S, WUFEI_FM_PRIORITY_FILL_LVL_7_W)

/*Fifo Manager Interrupt Read Registers*/

#define WUFEI_FM_INT_READ_PORT_ID_S (0)
#define WUFEI_FM_INT_READ_PORT_ID_W (13)
#define WUFEI_FM_INT_READ_PORT_ID_F(v) WUFEI_FIELD(v, WUFEI_FM_INT_READ_PORT_ID_S)
#define WUFEI_FM_INT_READ_PORT_ID_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_INT_READ_PORT_ID_S, WUFEI_FM_INT_READ_PORT_ID_W)
#define WUFEI_FM_INT_READ_PORT_ID_M \
        WUFEI_MASK(WUFEI_FM_INT_READ_PORT_ID_S, WUFEI_FM_INT_READ_PORT_ID_W)

#define WUFEI_FM_INT_READ_TYPE_S (13)
#define WUFEI_FM_INT_READ_TYPE_W (2)
#define WUFEI_FM_INT_READ_TYPE_F(v) WUFEI_FIELD(v, WUFEI_FM_INT_READ_TYPE_S)
#define WUFEI_FM_INT_READ_TYPE_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_INT_READ_TYPE_S, WUFEI_FM_INT_READ_TYPE_W)
#define WUFEI_FM_INT_READ_TYPE_M \
        WUFEI_MASK(WUFEI_FM_INT_READ_TYPE_S, WUFEI_FM_INT_READ_TYPE_W)

#define WUFEI_FM_INT_READ_VALID_S (15)
#define WUFEI_FM_INT_READ_VALID_W (1)
#define WUFEI_FM_INT_READ_VALID_F(v) WUFEI_FIELD(v, WUFEI_FM_INT_READ_VALID_S)
#define WUFEI_FM_INT_READ_VALID_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_INT_READ_VALID_S, WUFEI_FM_INT_READ_VALID_W)
#define WUFEI_FM_INT_READ_VALID_M \
        WUFEI_MASK(WUFEI_FM_INT_READ_VALID_S, WUFEI_FM_INT_READ_VALID_W)

/*Fifo Manager Port Configuration Register*/

#define WUFEI_FM_RX_PORT_CONF_BANK_NUM_S (0)
#define WUFEI_FM_RX_PORT_CONF_BANK_NUM_W (3)
#define WUFEI_FM_RX_PORT_CONF_BANK_NUM_F(v) WUFEI_FIELD(v, WUFEI_FM_RX_PORT_CONF_BANK_NUM_S)
#define WUFEI_FM_RX_PORT_CONF_BANK_NUM_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_RX_PORT_CONF_BANK_NUM_S, WUFEI_FM_RX_PORT_CONF_BANK_NUM_W)
#define WUFEI_FM_RX_PORT_CONF_BANK_NUM_M \
        WUFEI_MASK(WUFEI_FM_RX_PORT_CONF_BANK_NUM_S, WUFEI_FM_RX_PORT_CONF_BANK_NUM_W)

#define WUFEI_FM_RX_PORT_CONF_PRIORITY_S (3)
#define WUFEI_FM_RX_PORT_CONF_PRIORITY_W (1)
#define WUFEI_FM_RX_PORT_CONF_PRIORITY_F(v) WUFEI_FIELD(v, WUFEI_FM_RX_PORT_CONF_PRIORITY_S)
#define WUFEI_FM_RX_PORT_CONF_PRIORITY_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_RX_PORT_CONF_PRIORITY_S, WUFEI_FM_RX_PORT_CONF_PRIORITY_W)
#define WUFEI_FM_RX_PORT_CONF_PRIORITY_M \
        WUFEI_MASK(WUFEI_FM_RX_PORT_CONF_PRIORITY_S, WUFEI_FM_RX_PORT_CONF_PRIORITY_W)

#define WUFEI_FM_RX_PORT_CONF_TRANSMIT_THRESHOLD_S (4)
#define WUFEI_FM_RX_PORT_CONF_TRANSMIT_THRESHOLD_W (2)
#define WUFEI_FM_RX_PORT_CONF_TRANSMIT_THRESHOLD_F(v) WUFEI_FIELD(v, WUFEI_FM_RX_PORT_CONF_TRANSMIT_THRESHOLD_S)
#define WUFEI_FM_RX_PORT_CONF_TRANSMIT_THRESHOLD_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_RX_PORT_CONF_TRANSMIT_THRESHOLD_S, WUFEI_FM_RX_PORT_CONF_TRANSMIT_THRESHOLD_W)
#define WUFEI_FM_RX_PORT_CONF_TRANSMIT_THRESHOLD_M \
        WUFEI_MASK(WUFEI_FM_RX_PORT_CONF_TRANSMIT_THRESHOLD_S, WUFEI_FM_RX_PORT_CONF_TRANSMIT_THRESHOLD_W)

#define WUFEI_FM_TX_PORT_CONF_BANK_NUM_S (0)
#define WUFEI_FM_TX_PORT_CONF_BANK_NUM_W (3)
#define WUFEI_FM_TX_PORT_CONF_BANK_NUM_F(v) WUFEI_FIELD(v, WUFEI_FM_TX_PORT_CONF_BANK_NUM_S)
#define WUFEI_FM_TX_PORT_CONF_BANK_NUM_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_TX_PORT_CONF_BANK_NUM_S, WUFEI_FM_TX_PORT_CONF_BANK_NUM_W)
#define WUFEI_FM_TX_PORT_CONF_BANK_NUM_M \
        WUFEI_MASK(WUFEI_FM_TX_PORT_CONF_BANK_NUM_S, WUFEI_FM_TX_PORT_CONF_BANK_NUM_W)

#define WUFEI_FM_TX_PORT_CONF_PRIORITY_S (4)
#define WUFEI_FM_TX_PORT_CONF_PRIORITY_W (1)
#define WUFEI_FM_TX_PORT_CONF_PRIORITY_F(v) WUFEI_FIELD(v, WUFEI_FM_TX_PORT_CONF_PRIORITY_S)
#define WUFEI_FM_TX_PORT_CONF_PRIORITY_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_TX_PORT_CONF_PRIORITY_S, WUFEI_FM_TX_PORT_CONF_PRIORITY_W)
#define WUFEI_FM_TX_PORT_CONF_PRIORITY_M \
        WUFEI_MASK(WUFEI_FM_TX_PORT_CONF_PRIORITY_S, WUFEI_FM_TX_PORT_CONF_PRIORITY_W)

#define WUFEI_FM_TX_PORT_CONF_TRANSMIT_THRESHOLD_S (0)
#define WUFEI_FM_TX_PORT_CONF_TRANSMIT_THRESHOLD_W (4)
#define WUFEI_FM_TX_PORT_CONF_TRANSMIT_THRESHOLD_F(v) WUFEI_FIELD(v, WUFEI_FM_TX_PORT_CONF_TRANSMIT_THRESHOLD_S)
#define WUFEI_FM_TX_PORT_CONF_TRANSMIT_THRESHOLD_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_TX_PORT_CONF_TRANSMIT_THRESHOLD_S, WUFEI_FM_TX_PORT_CONF_TRANSMIT_THRESHOLD_W)
#define WUFEI_FM_TX_PORT_CONF_TRANSMIT_THRESHOLD_M \
        WUFEI_MASK(WUFEI_FM_TX_PORT_CONF_TRANSMIT_THRESHOLD_S, WUFEI_FM_TX_PORT_CONF_TRANSMIT_THRESHOLD_W)

#define WUFEI_FM_TX_PORT_CONF_FAST_PORT_S (3)
#define WUFEI_FM_TX_PORT_CONF_FAST_PORT_W (1)
#define WUFEI_FM_TX_PORT_CONF_FAST_PORT_F(v) WUFEI_FIELD(v, WUFEI_FM_TX_PORT_CONF_FAST_PORT_S)
#define WUFEI_FM_TX_PORT_CONF_FAST_PORT_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_TX_PORT_CONF_FAST_PORT_S, WUFEI_FM_TX_PORT_CONF_FAST_PORT_W)
#define WUFEI_FM_TX_PORT_CONF_FAST_PORT_M \
        WUFEI_MASK(WUFEI_FM_TX_PORT_CONF_FAST_PORT_S, WUFEI_FM_TX_PORT_CONF_FAST_PORT_W)

#define WUFEI_FM_TX_PORT_CONF_MAX_BUF_S (4)
#define WUFEI_FM_TX_PORT_CONF_MAX_BUF_W (4)
#define WUFEI_FM_TX_PORT_CONF_MAX_BUF_F(v) WUFEI_FIELD(v, WUFEI_FM_TX_PORT_CONF_MAX_BUF_S)
#define WUFEI_FM_TX_PORT_CONF_MAX_BUF_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_TX_PORT_CONF_MAX_BUF_S, WUFEI_FM_TX_PORT_CONF_MAX_BUF_W)
#define WUFEI_FM_TX_PORT_CONF_MAX_BUF_M \
        WUFEI_MASK(WUFEI_FM_TX_PORT_CONF_MAX_BUF_S, WUFEI_FM_TX_PORT_CONF_MAX_BUF_W)

#define WUFEI_FM_TX_PORT_CONF_WAIT_TYPE_S (8)
#define WUFEI_FM_TX_PORT_CONF_WAIT_TYPE_W (2)
#define WUFEI_FM_TX_PORT_CONF_WAIT_TYPE_F(v) WUFEI_FIELD(v, WUFEI_FM_TX_PORT_CONF_WAIT_TYPE_S)
#define WUFEI_FM_TX_PORT_CONF_WAIT_TYPE_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_TX_PORT_CONF_WAIT_TYPE_S, WUFEI_FM_TX_PORT_CONF_WAIT_TYPE_W)
#define WUFEI_FM_TX_PORT_CONF_WAIT_TYPE_M \
        WUFEI_MASK(WUFEI_FM_TX_PORT_CONF_WAIT_TYPE_S, WUFEI_FM_TX_PORT_CONF_WAIT_TYPE_W)

/*Fifo Manager Indirect DDR memory parameter Register*/

#define WUFEI_FM_PORT_DDR_MEM_READ_PTR_S (0)
#define WUFEI_FM_PORT_DDR_MEM_READ_PTR_W (8)
#define WUFEI_FM_PORT_DDR_MEM_READ_PTR_F(v) WUFEI_FIELD(v, WUFEI_FM_PORT_DDR_MEM_READ_PTR_S)
#define WUFEI_FM_PORT_DDR_MEM_READ_PTR_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_PORT_DDR_MEM_READ_PTR_S, WUFEI_FM_PORT_DDR_MEM_READ_PTR_W)
#define WUFEI_FM_PORT_DDR_MEM_READ_PTR_M \
        WUFEI_MASK(WUFEI_FM_PORT_DDR_MEM_READ_PTR_S, WUFEI_FM_PORT_DDR_MEM_READ_PTR_W)

#define WUFEI_FM_PORT_DDR_MEM_WRITE_PTR_S (0)
#define WUFEI_FM_PORT_DDR_MEM_WRITE_PTR_W (8)
#define WUFEI_FM_PORT_DDR_MEM_WRITE_PTR_F(v) WUFEI_FIELD(v, WUFEI_FM_PORT_DDR_MEM_WRITE_PTR_S)
#define WUFEI_FM_PORT_DDR_MEM_WRITE_PTR_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_PORT_DDR_MEM_WRITE_PTR_S, WUFEI_FM_PORT_DDR_MEM_WRITE_PTR_W)
#define WUFEI_FM_PORT_DDR_MEM_WRITE_PTR_M \
        WUFEI_MASK(WUFEI_FM_PORT_DDR_MEM_WRITE_PTR_S, WUFEI_FM_PORT_DDR_MEM_WRITE_PTR_W)

/*Fifo Manager Indirect Burst memory parameter Register*/

#define WUFEI_FM_PORT_BURST_MEM_READ_PTR_S (0)
#define WUFEI_FM_PORT_BURST_MEM_READ_PTR_W (4)
#define WUFEI_FM_PORT_BURST_MEM_READ_PTR_F(v) WUFEI_FIELD(v, WUFEI_FM_PORT_BURST_MEM_READ_PTR_S)
#define WUFEI_FM_PORT_BURST_MEM_READ_PTR_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_PORT_BURST_MEM_READ_PTR_S, WUFEI_FM_PORT_BURST_MEM_READ_PTR_W)
#define WUFEI_FM_PORT_BURST_MEM_READ_PTR_M \
        WUFEI_MASK(WUFEI_FM_PORT_BURST_MEM_READ_PTR_S, WUFEI_FM_PORT_BURST_MEM_READ_PTR_W)

#define WUFEI_FM_PORT_BURST_MEM_WRITE_PTR_S (8)
#define WUFEI_FM_PORT_BURST_MEM_WRITE_PTR_W (4)
#define WUFEI_FM_PORT_BURST_MEM_WRITE_PTR_F(v) WUFEI_FIELD(v, WUFEI_FM_PORT_BURST_MEM_WRITE_PTR_S)
#define WUFEI_FM_PORT_BURST_MEM_WRITE_PTR_V(f) \
        WUFEI_VALUE(f, WUFEI_FM_PORT_BURST_MEM_WRITE_PTR_S, WUFEI_FM_PORT_BURST_MEM_WRITE_PTR_W)
#define WUFEI_FM_PORT_BURST_MEM_WRITE_PTR_M \
        WUFEI_MASK(WUFEI_FM_PORT_BURST_MEM_WRITE_PTR_S, WUFEI_FM_PORT_BURST_MEM_WRITE_PTR_W)


#define WUFE_FM_TX_VFP_REQ_CNT_OC12 6
#define WUFE_FM_TX_VFP_REQ_CNT_OC3  3

#endif /* WUFEI_HW_FM_H*/