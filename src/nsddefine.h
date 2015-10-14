#ifndef nsddefine_H_
#define nsddefine_H_

#include <windows.h>

#define NSD_ADDR_LEN (64)

typedef enum {
    NSDIPV6_MANUAL = 0,
    NSDIPV6_AUTO,
    NSDIPV6_ROUTER
} NSDIPV6_MODE;

typedef enum {
    NSD_MSG_ON_RESET_ADMIN = 0,
} NSD_MSG_TYPE;

typedef enum {
    NSD_RESTORE_SIMPLE = 0,
    NSD_RESTORE_FULL
} NSD_RESTORE_TYPE;

typedef struct {
    //read-only
    char serial[NSD_ADDR_LEN];
    int  device_type;
    char firmware_version[NSD_ADDR_LEN];
    char dome_version[NSD_ADDR_LEN];
    char web_version[NSD_ADDR_LEN];
    char plugin_version[NSD_ADDR_LEN];
    char reset_admin_code[NSD_ADDR_LEN];

    //read-write
    char mac_address[NSD_ADDR_LEN];
    char device_name[NSD_ADDR_LEN];

    char ipv4_address[NSD_ADDR_LEN];
    char ipv4_mask[NSD_ADDR_LEN];
    char ipv4_gateway[NSD_ADDR_LEN];
    char ipv4_dns_address[NSD_ADDR_LEN];
    int  ipv4_dhcp_enable;

    char ipv6_address[NSD_ADDR_LEN];
    char ipv6_mask[NSD_ADDR_LEN];
    char ipv6_gateway[NSD_ADDR_LEN];
    char ipv6_dns_address[NSD_ADDR_LEN];
    NSDIPV6_MODE ipv6_mode;

    unsigned short rtsp_port;
    unsigned short http_port;
    unsigned short https_port;
    unsigned short ns_port;
} NSDDeviceInfo;

typedef struct {
    int result;
    char serial[NSD_ADDR_LEN];
} NSDResetAdminInfo;

typedef void (__stdcall *NSD_ON_DISCOVERY_NOTIFY)(NSDDeviceInfo* device_info);
typedef void (__stdcall *NSD_ON_MSG)(int type,int param);

#endif // nsddefine_H_