/******************************************************************************
  * @file           bt_smp.h
  * @author         Yu-ZhongJun(124756828@qq.com)
  * @Taobao link    https://shop220811498.taobao.com/
  * @version        V0.0.1
  * @date           2021-11-27
  * @brief          bt ble smp header file
******************************************************************************/

#ifndef BT_SMP_H_H_H
#define BT_SMP_H_H_H

#include "bt_common.h"
#include "bt_l2cap.h"

/* SMP command code */
#define SMP_OPCODE_PAIRING_REQ            0x01
#define SMP_OPCODE_PAIRING_RSP            0x02
#define SMP_OPCODE_CONFIRM                0x03
#define SMP_OPCODE_RAND                   0x04
#define SMP_OPCODE_PAIRING_FAILED         0x05
#define SMP_OPCODE_ENCRYPT_INFO           0x06
#define SMP_OPCODE_MASTER_ID              0x07
#define SMP_OPCODE_IDENTITY_INFO          0x08
#define SMP_OPCODE_ID_ADDR                0x09
#define SMP_OPCODE_SIGN_INFO              0x0A
#define SMP_OPCODE_SEC_REQ                0x0B
#define SMP_OPCODE_PAIR_PUBLIC_KEY        0x0C
#define SMP_OPCODE_PAIR_DHKEY_CHECK       0x0D
#define SMP_OPCODE_PAIR_KEYPR_NOTIF       0x0E

/* pairing failure reason code */
#define SMP_PASSKEY_ENTRY_FAIL      0x01
#define SMP_OOB_FAIL                0x02
#define SMP_PAIR_AUTH_FAIL          0x03
#define SMP_CONFIRM_VALUE_ERR       0x04
#define SMP_PAIR_NOT_SUPPORT        0x05
#define SMP_ENC_KEY_SIZE            0x06
#define SMP_INVALID_CMD             0x07
#define SMP_PAIR_FAIL_UNKNOWN       0x08
#define SMP_REPEATED_ATTEMPTS       0x09
#define SMP_INVALID_PARAMETERS      0x0A
#define SMP_DHKEY_CHK_FAIL          0x0B
#define SMP_NUMERIC_COMPAR_FAIL     0x0C
#define SMP_BR_PARING_IN_PROGR      0x0D
#define SMP_XTRANS_DERIVE_NOT_ALLOW 0x0E
#define SMP_KEY_REJECTED 0x0F

/* IO capability */
#define SMP_IO_CAP_DISPLAY_ONLY 0
#define SMP_IO_CAP_DISPLAY_YESNO  1
#define SMP_IO_CAP_KEYBORAD_ONLY 2
#define SMP_IO_CAP_NOIO 3
#define SMP_IO_CAP_KBDISP 4

/* OOB data flag */
#define SMP_OOB_NONE 0
#define SMP_OOB_PRESENT 1

/* AuthReq */
#define SMP_NO_BONDING (0 << 0)
#define SMP_BONDING (1 << 0)
#define SMP_AUTH_MIMT_BIT (1 << 2)
#define SMP_SC_SUPPORT_BIT (1 << 3)
#define SMP_KP_SUPPORT_BIT (1 << 4)
#define SMP_H7_SUPPORT_BIT (1 << 5)

#define SMP_PAIR_REQ_PACK_LEN 7
#define SMP_PAIR_RSP_PACK_LEN 7


typedef struct _smp_pcb_t
{
    struct _smp_pcb_t *next; /* For the linked list */
    struct bd_addr_t remote_addr;
    l2cap_pcb_t*l2cappcb;

    uint8_t remote_io_cap;
    uint8_t remote_oob_flag;
    uint8_t remote_auth_req;
    uint8_t remote_enc_size;
    uint8_t remote_i_key;
    uint8_t remote_r_key;

    uint8_t local_io_cap;
    uint8_t local_oob_flag;
    uint8_t local_auth_req;
    uint8_t local_enc_size;
    uint8_t local_i_key;
    uint8_t local_r_key;
} smp_pcb_t;


typedef struct
{
    void (*smp_connect_set_up)(smp_pcb_t *smp_pcb,uint8_t status);
    void (*smp_connect_realease)(smp_pcb_t *smp_pcb,uint8_t status);
} smp_cbs_t;


err_t smp_init(smp_cbs_t *cb);
err_t smp_send_pair_rsp(smp_pcb_t *smp_pcb);


#endif

