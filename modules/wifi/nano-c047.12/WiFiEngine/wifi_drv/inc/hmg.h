
#ifndef HMG_H
#define HMG_H

#include "ucos.h"
typedef enum
{
 /* If you update this, please also update HMG_Signal_toToName() */
   INTSIG_MLME_RESET_REQ          =  1,
   INTSIG_MLME_RESET_CFM          =  2,
   INTSIG_MLME_SCAN_REQ           =  3,
   INTSIG_MLME_SCAN_CFM           =  4,
   INTSIG_MLME_POWER_MGMT_REQ     =  5,
   INTSIG_MLME_POWER_MGMT_CFM     =  6,
   INTSIG_MLME_JOIN_REQ           =  7,
   INTSIG_MLME_JOIN_CFM           =  8,
   INTSIG_MLME_AUTHENTICATE_REQ   =  9,
   INTSIG_MLME_AUTHENTICATE_CFM   =  10,
   INTSIG_MLME_AUTHENTICATE_IND   =  11,
   INTSIG_MLME_DEAUTHENTICATE_REQ =  12,
   INTSIG_MLME_DEAUTHENTICATE_CFM =  13,
   INTSIG_MLME_DEAUTHENTICATE_IND =  14,
   INTSIG_MLME_ASSOCIATE_REQ      =  15,
   INTSIG_MLME_ASSOCIATE_CFM      =  16,
   INTSIG_MLME_ASSOCIATE_IND      =  17,
   INTSIG_MLME_REASSOCIATE_REQ    =  18,
   INTSIG_MLME_REASSOCIATE_CFM    =  19,
   INTSIG_MLME_REASSOCIATE_IND    =  20,
   INTSIG_MLME_DISASSOCIATE_REQ   =  21,
   INTSIG_MLME_DISASSOCIATE_CFM   =  22,
   INTSIG_MLME_DISASSOCIATE_IND   =  23,
   INTSIG_MLME_START_REQ          =  24,
   INTSIG_MLME_START_CFM          =  25,
   INTSIG_MLME_SET_KEY_REQ        =  26,
   INTSIG_MLME_SET_KEY_CFM        =  27,
   INTSIG_MLME_DELETE_KEY_REQ     =  28,
   INTSIG_MLME_DELETE_KEY_CFM     =  29,
   INTSIG_MLME_SET_PROTECTION_REQ =  30,
   INTSIG_MLME_SET_PROTECTION_CFM =  31,
   INTSIG_MLME_MICHAEL_MIC_FAILURE_IND = 37,

   INTSIG_NRP_MLME_BSS_LEAVE_REQ    = 66,
   INTSIG_NRP_MLME_BSS_LEAVE_CFM    = 67,
   INTSIG_NRP_MLME_IBSS_LEAVE_REQ   = 68,
   INTSIG_NRP_MLME_IBSS_LEAVE_CFM   = 69,
   INTSIG_NRP_MLME_PEER_STATUS_IND  = 70,
   INTSIG_NRP_MLME_RSSI_THRESHOLD_IND = 71,

/* Allocate signals from 0x80 and onwards for the Host Manager. */
   INTSIG_INIT = 0x80,
   INTSIG_EXIT,
   INTSIG_NET_IDLE,
   INTSIG_NET_LOST,
   INTSIG_NET_LIST,
   INTSIG_NET_RESELECT,
   INTSIG_NET_SELECTION,
   INTSIG_NET_START,
   INTSIG_NET_AUTHENTICATE,
   INTSIG_NET_DEAUTHENTICATE,

   INTSIG_NET_LEAVE_IBSS, /* 138 */
   INTSIG_NET_ASSOCIATE,
   INTSIG_NET_REASSOCIATE,
   INTSIG_NET_DISASSOCIATE, 
   INTSIG_NET_POWER_DOWN_DISASSOCIATE,
   INTSIG_NET_POWER_DOWN_LEAVE_STA,
   INTSIG_NET_BSS_ACTIVE,
   INTSIG_NET_BSS_SLEEP,
   INTSIG_POWER_UP,
   INTSIG_UNPLUG,

   INTSIG_DEVICE_POWER_SLEEP, /* 148 */
   INTSIG_DEVICE_POWER_WAKE,
   INTSIG_DEVICE_POWER_WAKE_IN_POWER_ACTIVE,
   INTSIG_DEVICE_RESTART_TIMER,
   INTSIG_DEVICE_END_OF_SERVICE, 

   INTSIG_TRANSIT_TO_CLOSED,
   INTSIG_HIC_CTRL_WAKEUP_IND,
   INTSIG_HIC_CTRL_NO_MORE_TRAFFIC_IND,   
   INTSIG_HIC_CTRL_WAKEUP_RSP,
   INTSIG_HIC_CTRL_SET_ALIGNMENT_REQ,
   INTSIG_HIC_CTRL_SET_ALIGNMENT_CFM,
   INTSIG_HIC_CTRL_LOCAL_WMM_PS_REQ,
   INTSIG_HIC_CTRL_WMM_PS_CFM,
   INTSIG_HIC_CTRL_MONITOR_TRAFFIC_REQ,
   INTSIG_HIC_CTRL_MONITOR_TRAFFIC_CFM,  
   INTSIG_MLME_TRANSFER_DATA,
   INTSIG_HIC_CTRL_HOST_EOSP_CFM,
   INTSIG_HIC_CTRL_SLEEP_FOREVER_CFM, 
   INTSIG_HIC_CTRL_WMM_PS_SET_PERIOD_REQ,
   INTSIG_HIC_CTRL_WMM_PS_SET_PERIOD_CFM, 
   INTSIG_HIC_CTRL_WMM_PS_PERIOD_START_REQ,
   INTSIG_HIC_CTRL_WMM_PS_PERIOD_START_CFM,
   INTSIG_HIC_CTRL_PS_IDLE_REQ,
   INTSIG_HIC_CTRL_PS_IDLE_CFM,
   INTSIG_HIC_CTRL_PS_CHECK_QUEUES,   
   INTSIG_HIC_CTRL_IBSS_TX_REQ,
   INTSIG_HIC_CTRL_IBSS_TX_CFM /* 174 */
   
} HMG_Signals_e;

void HMG_init(void);
void HMG_startUp(void);
void HMG_resume(void);
void HMG_Unplug(void);
void HMG_entry(ucos_msg_id_t msg, ucos_msg_param_t param);

int  HMG_GetState(void);
int  HMG_GetSubState(void);
BOOLEAN HMG_isDeepSleep(void);
#endif /* HMG_H */