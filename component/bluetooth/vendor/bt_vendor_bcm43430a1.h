#ifndef BT_VENDOR_BCM43430A1_H_H_H
#define BT_VENDOR_BCM43430A1_H_H_H
#include "bt_vendor_manager.h"

#define BCM_HCI_BB_CTL_OGF 0x03
#define BCM_HCI_VSC_OGF 0x3f

#define BCM_HCi_VSC_RESET 0x03
#define BCM_HCI_VSC_WRITE_BD_ADDR_OCF 0x01
#define BCM_HCI_VSC_WRITE_UART_CLOCK_SETTING_OCF 0x05
#define BCM_HCI_VSC_UPDATE_BAUDRATE_OCF 0x18
#define BCM_HCI_VSC_DOWNLOAD_MINIDRV_OCF 0x2e
#define BCM_HCI_VSC_WRITE_SLEEP_MODE_OCF 0x27
#define BCM_HCI_VSC_WRITE_SCO_PCM_INT_PARAM_OCF 0x1c
#define BCM_HCI_VSC_WRITE_PCM_DATA_FORMAT_PARAM_OCF 0x1e
#define BCM_HCI_VSC_WRITE_I2SPCM_INTERFACE_PARAM_OCF 0x6d
#define BCM_HCI_VSC_ENABLE_WBS_OCF 0x7e
#define BCM_HCI_VSC_LAUNCH_RAM_OCF 0x4e


chip_mgr_t * bcm43430a1_instance(void);
#endif

