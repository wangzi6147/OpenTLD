#ifndef nsst_define_H_
#define nsst_define_H_

#include <windows.h>

typedef int DEVICE_ID;

#define NSST_SHORT_LEN   (64)
#define NSST_COMMON_LEN   (320)
#define NSST_ALARM_AREA_VMAX (18)

typedef enum {
    APP_PROXY_NO = 0,
    APP_PROXY_HTTP,
    APP_PROXY_SOCKS,
    APP_PROXY_SYSTEM
} APP_PROXY_TYPE;

typedef enum {
    NS_ALARM_MOTION = 0,
    NS_ALARM_MASK,
    NS_ALARM_PORTIN,
    NS_ALARM_PORTOUT,
    NS_ALARM_TYPE_COUNT
} NS_ALARM_TYPE;

typedef enum {
    NSSTDEV_H = 0,
    NSSTDEV_K,
    NSSTDEV_A
} NSST_DEVICE_TYPE;

typedef enum {
    NSSTEV_LOGIN = 100,
    NSSTEV_MEDIA_BEGIN = 110,
    NSSTEV_MEDIA_CONNECTED,
    NSSTEV_MEDIA_ERROR,
    NSSTEV_MEDIA_RECONNECTING,
    NSSTEV_MEDIA_EOF,
    NSSTEV_MEDIA_END = 150,
    NSSTEV_JPEG_PROGRESS,
    NSSTEV_JPEG_RESULT,
    NSSTEV_TALK_CONNECTED,
    NSSTEV_TALK_NET_ERROR,
    NSSTEV_TALK_DEVICE_ERROR,
    NSSTEV_RECV_MESSAGE_ERROR,
    NSSTEV_MSG_ALARM,
    NSSTEV_CMDRV_DEAD_PIXEL,
    NSSTEV_CMDRV_CAMERA_PARAMS,
    NSSTEV_CMDRV_NET_CONFIG,
    NSSTEV_CMDRV_GET_MAC,
    NSSTEV_CMDRV_SET_MAC,
    NSSTEV_CMDRV_FRAMERATE,
    NSSTEV_CMDRV_VACONFIG,
    NSSTEV_CMDRV_BITRATECFG,
    NSSTEV_CMDRV_IFRAME_INTERVAL,
    NSSTEV_CMDRV_VIDEO_QUALITY,
    NSSTEV_CMDRV_DEVICE_DETAILS,
    NSSTEV_CMDRV_TIME_CONFIG,
    NSSTEV_CMDRV_FOCUS_CONFIG,
    NSSTEV_CMDRV_IRIS_CONFIG,
    NSSTEV_CMDRV_WHITE_BALANCE,
    NSSTEV_CMDRV_DAYNIGHT_SWITCH,
    NSSTEV_CMDRV_LOCAL_OUTPUT,
    NSSTEV_CMDRV_VIDEO_STANDARD,
    NSSTEV_CMDRV_VIDEO_MIRROR,
    NSSTEV_CMDRV_VIDEO_DENOISE,
    NSSTEV_CMDRV_WDR,
    NSSTEV_CMDRV_PTZ_SEQUENCE,
    NSSTEV_CMDRV_AUDIO_INPUT,
    NSSTEV_CMDRV_IR_LED,
    NSSTEV_CMDRV_OSD,
    NSSTEV_CMDRV_DDNS,
    NSSTEV_CMDRV_PPPOE,
    NSSTEV_CMDRV_UPNP,
    NSSTEV_CMDRV_FTP,
    NSSTEV_CMDRV_EMAIL,
    NSSTEV_CMDRV_USER_MANAGE,
    NSSTEV_CMDRV_RTSP_AUTH,
    NSSTEV_CMDRV_ANONYMOUS,
    NSSTEV_CMDRV_IP_FILTER,
    NSSTEV_CMDRV_MOTION_AREA,
    NSSTEV_CMDRV_MOTION_CONFIG,
    NSSTEV_CMDRV_ALARM_TRIGGER,
    NSSTEV_CMDRV_ALARM_SCHEDULE,
    NSSTEV_CMDRV_PORT_ALARM,
    NSSTEV_CMDRV_OUTPUT_DELAY,
    NSSTEV_CMDRV_RECORD_SCHEDULE,
    NSSTEV_CMDRV_STORAGE_DEVICES,
    NSSTEV_CMDRV_STORAGE_QUOTA,
    NSSTEV_CMDRV_CAPTURE_CONFIG,
    NSSTEV_CMDRV_SEARCH_FILE,
    NSSTEV_CMDRV_FORMAT,
    NSSTEV_CMDRV_UPGRADE_PROGRESS,
    NSSTEV_CMDRV_UPGRADE_RESULT
} NSST_EVENT;

typedef enum {
    NS_CMD_GET = 0,
    NS_CMD_SET = 1
} NS_CMD_OPERATION;

typedef enum {
    NSST_PROTOCOL_PELCO_P = 0,
    NSST_PROTOCOL_PELCO_D,
    NSST_PROTOCOL_HS,
    NSST_PROTOCOL_COUNT
} NSST_CONTROL_PROTOCOL;

typedef enum {
    NSST_MEDIA_DATA_TYPE_VIDEO = 0,
    NSST_MEDIA_DATA_TYPE_AUDIO
};

#define NSST_RECT_SCALE (1000)
#define NSST_CONTROL_BUFFER_SIZE (256)
#define NSST_IPV4_LEN (16)
#define NSS_PEER_ID_LEN   (32)
#define NSST_MAC_ADDRESS_LEN (6)

typedef struct {
    APP_PROXY_TYPE type;
    char   proxy_host[NSST_SHORT_LEN];
    USHORT proxy_port;
    char    user[NSST_SHORT_LEN];
    char    password[NSST_SHORT_LEN];
} AppProxy;

typedef struct {
    char host[NSST_SHORT_LEN];
    USHORT protocol_port;
    USHORT rtsp_port;
    char username[NSST_SHORT_LEN];
    char password[NSST_SHORT_LEN];
    NSST_DEVICE_TYPE dev_type;
} NsstDevice;

#define NS_VOD_PLAY_CHANNEL (100)
#define NS_VOD_DOWNLOAD_CHANNEL (NS_VOD_PLAY_CHANNEL + 100)
typedef struct {
    DEVICE_ID dev_id;
    int channel;
    int stream;
} NsstChannel;

typedef enum {
    NS_PTZ_MOVE_STOP = 0,
    NS_PTZ_MOVE_UP,
    NS_PTZ_MOVE_DOWN,
    NS_PTZ_MOVE_LEFT,
    NS_PTZ_MOVE_RIGHT,
    NS_PTZ_MOVE_LEFT_UP,
    NS_PTZ_MOVE_RIGHT_UP,
    NS_PTZ_MOVE_LEFT_DOWN,
    NS_PTZ_MOVE_RIGHT_DOWN,
    NS_PTZ_MOVE_ZOOM_TELE = 20,
    NS_PTZ_MOVE_ZOOM_WIDE,
    NS_PTZ_MOVE_FOCUS_NEAR,
    NS_PTZ_MOVE_FOCUS_FAR,
    NS_PTZ_MOVE_IRIS_CLOSE,
    NS_PTZ_MOVE_IRIS_OPEN,
    NS_PTZ_MOVE_RESET_CAMERA = 99
} NS_PTZ_MOVE;

typedef struct {
    int action;
    int speed;
//     int speed_p;
//     int speed_t;
//     int speed_z;
} NsstPTZParam;

typedef enum {
    NS_PTZ_PRESET_SET = 1,
    NS_PTZ_PRESET_CALL,
    NS_PTZ_PRESET_DELETE
} NS_PRESET_CMD;

typedef enum {
    NS_PTZ_SEQUENCE_DELETE = 1,
    NS_PTZ_SEQUENCE_COVER = 3,
    NS_PTZ_SEQUENCE_START,
    NS_PTZ_SEQUENCE_STOP
} NS_PTZ_SEQUENCE_TYPE;

typedef enum {
    NS_PTZ_PATTERN_SET_START = 1,
    NS_PTZ_PATTERN_SET_STOP,
    NS_PTZ_PATTERN_DELETE,
    NS_PTZ_PATTERN_START,
    NS_PTZ_PATTERN_STOP
} NS_PTZ_PATTERN_TYPE;

typedef enum {
    NS_PTZ_SCAN_SET_LEFT = 1,
    NS_PTZ_SCAN_SET_RIGHT,
    NS_PTZ_SCAN_SET_SPEED,
    NS_PTZ_SCAN_DELETE,
    NS_PTZ_SCAN_START
} NS_PTZ_SCAN_TYPE;

typedef enum {
    NS_PTZ_SWITCH_LIGHT = 0,
    NS_PTZ_SWITCH_WIPER,
    NS_PTZ_SWITCH_POWER,
    NS_PTZ_SWITCH_AUXILIARY_FOCUS,
    NS_PTZ_SWITCH_HEAT,
    NS_PTZ_SWITCH_DEFOG,
    NS_PTZ_SWITCH_FAN
} NS_PTZ_SWITCH_TYPE;

typedef enum {
    NS_OSD_DATETIME = 0,
    NS_OSD_CHANNEL_NAME,
    NS_OSD_TEXT
} NS_OSD_TYPE;

typedef enum {
    NSST_SUCCESS = 0,
    NSST_ERROR_DEFAULT = 101,
    NSST_DX_NOT_SUPPORT,
    NSST_NET_ERROR = 201,
    NSST_FILE_ERROR,
    NSST_NOT_LOGIN,
    NSST_IN_PROGRESS,
    ERR_SERVER_ERROR_START = 1000,
    ERR_USER_NOT_EXIST_ERROR,
    ERR_USER_PASSWORD_ERROR,
    ERR_USER_LENGTH_ERROR,
    ERR_SESSION_INVALID,
    ERR_GET_FAILED,
    ERR_SET_FAILED,
    ERR_UPGRADE_RECV_FILE,
    ERR_UPGRADE_START_FAILED,
    ERR_UPGRADE_BUSY,
    ERR_UPGRADE_VER,
    ERR_UPGRADE_MD5,
    ERR_UPGRADE_SYS,
    ERR_UPGRADE_NOTEXIST,
    ERR_RESTORE_DEFAULT,
    ERR_OSD_SIZE,
    ERR_SEARCH_PAGECOUNT_INVALID,
    ERR_IPFILTER_ADD_ALREADY_EXIST,
    ERR_INSUFFICIENT_PERMISSIONS,
    ERR_IP_REFUSED,
    ERR_NOT_SUPPORTED,
    ERR_USER_EXIST,
    ERR_USER_REACH_LIMIT
} NSST_ERROR_CODE;

typedef enum {
    NSSTIPV6_MANUAL = 0,
    NSSTIPV6_AUTO,
    NSSTIPV6_ROUTER
} NSSTIPV6_MODE;

typedef enum {
    NSST_UPGRADE_NOACTIVE = 0,
    NSST_UPGRADE_STARTED,
    NSST_UPGRADE_IN_PROGRESS,
    NSST_UPGRADE_UPLOADING = 999
} NSST_UPGRADE_STATUS;

typedef struct {
    char ipv4_address[NSST_SHORT_LEN];
    char ipv4_mask[NSST_SHORT_LEN];
    char ipv4_gateway[NSST_SHORT_LEN];
    char ipv4_dns_address[NSST_SHORT_LEN];
    int  ipv4_dhcp_enable;

    char ipv6_address[NSST_SHORT_LEN];
    char ipv6_mask[NSST_SHORT_LEN];
    char ipv6_gateway[NSST_SHORT_LEN];
    char ipv6_dns_address[NSST_SHORT_LEN];
    NSSTIPV6_MODE ipv6_mode;
} NsstNetConfig;

typedef struct {
    unsigned short rtsp_port;
    unsigned short http_port;
    unsigned short https_port;
    unsigned short ns_port;
} NsstServicePortConfig;

typedef struct {
    int channel;
    NS_ALARM_TYPE type;
    int status;
    void* details;
} NsstAlarmInfo;

typedef struct {
    char name[NSST_SHORT_LEN];
    int switch_channel;
    int alarm_type;
    int dev_time;
} NsstADSwitch;

typedef struct {
    int result;
    NsstChannel nsst_channel;
    char get_or_set;
    void* user_data;
    int ival[NSST_COMMON_LEN];
    char sval[NSST_COMMON_LEN];
    void* pval;
} NsstEventCommonParam;

typedef struct {
    int brightness;
    int contrast;
    int saturation;
    int sharpness;
    int hue;
} NsstCameraParams;

typedef struct {
    int stream_type;
    int resolution_w;
    int resolution_h;
    int video_encoding;
} NsstVAConfig;

typedef struct {
    int user_level;
    int channel_cnt;
    int stream_cnt;
    char model[NSST_SHORT_LEN];
    char serial[NSST_SHORT_LEN];
    char firmware_ver[NSST_SHORT_LEN];
    char software_ver[NSST_SHORT_LEN];
    char web_ver[NSST_SHORT_LEN];
    char plugin_ver[NSST_SHORT_LEN];
    int alarm_input;
    int alarm_output;
    int audio;
    int harddisk_cnt;
    int rtsp_mapping_port;
} NsstDeviceDetails;

typedef enum {
    NSST_UDP = 0,
    NSST_TCP
} NsstTransportType;

typedef struct {
    double timezone;
    int ntp_enable;
    char ntp_address[NSST_SHORT_LEN];
    int ntp_port;
    int ntp_interval;
    int sync_time;
} NsstTimeConfig;

typedef struct {
    int exposure_type;
    int iris;
    int gain;
    int gain_limit;
    int shutter;
    int shutter_limit;
} NsstIrisConfig;

typedef struct {
    int preset;
    int delay;
    int speed;
} NsstPTZSequenceItem;

typedef struct {
    int mode;
    int illuminance;
    int auto_dimming;
    int near_power;
    int far_power;
    int near_compensation;
} NsstIRConfig;

typedef struct {
    NS_OSD_TYPE osd_type; 
    int enable;
    int x;
    int y;
    int date_format;
    int time_format;
    char text[8*256];
} NsstOSD;

typedef struct {
    int enable;
    char ip[NSST_SHORT_LEN];
    char username[NSST_SHORT_LEN];
    char password[NSST_SHORT_LEN];
} NsstPPPoE;

typedef struct {
    char alias[NSST_SHORT_LEN];
    char address[NSST_SHORT_LEN];
    int port;
    char domain[NSST_SHORT_LEN];
    char username[NSST_SHORT_LEN];
    char password[NSST_SHORT_LEN];
} NsstDDNS;

typedef struct {
    char svr_address[NSST_SHORT_LEN];
    int  svr_port;
    char username[NSST_SHORT_LEN];
    char password[NSST_SHORT_LEN];
    int  dir_level_count;
    int  dir_level_1;
    int  dir_level_2;
} NsstFTP;

#define NS_MAX_MAILTO (4)

typedef struct {
    char sender_name[NSST_SHORT_LEN];
    char sender_email[NSST_SHORT_LEN];
    char smtp_server[NSST_SHORT_LEN];
    int  smtp_port;
    int  auth_enable;
    int  use_ssl;
    char username[NSST_SHORT_LEN];
    char password[NSST_SHORT_LEN];
    
    char mailto_name[NS_MAX_MAILTO][NSST_SHORT_LEN];
    char mailto_email[NS_MAX_MAILTO][NSST_SHORT_LEN];
} NsstEmail;

typedef struct {
    char old_name[NSST_SHORT_LEN];
    char new_name[NSST_SHORT_LEN];
    char password[NSST_SHORT_LEN];
    int level;
} NsstUserManage;

#define NS_IP_FILTER_MAX  (16)
typedef struct {
    int mode;
    int enable;
    unsigned int count;
    char list[NS_IP_FILTER_MAX][NSST_SHORT_LEN];
} NsstIPFilter;

typedef enum {
    ATRIGGER_MOTION = 0,
    ATRIGGER_MASK,
    ATRIGGER_PORT,
    ATRIGGER_DISK_FULL,
    ATRIGGER_DISK_ERROR,
    ATRIGGER_NET_DISCONNECTED,
    ATRIGGER_IP_CONFLICT
} NS_TRIGGER_ATYPE;

typedef struct {
    NS_TRIGGER_ATYPE  alarm_type;
    int audio;
    int broadcast;
    int snapshot;
    int snapshot_ftp;
    int snapshot_email;
    int snapshot_sdcard;
    int port;
    int record;
    int ptz_preset;
    int ptz_sequence;
    int ptz_scan;
} NsstAlarmTrigger;

#define NS_MAX_TIME_SEG  (8)
typedef struct {
    int start[NS_MAX_TIME_SEG];
    int end[NS_MAX_TIME_SEG];
} NsstDay;
typedef struct {
    NS_ALARM_TYPE alarm_type;
    NsstDay dayofweek[7];
} NsstAlarmSchedule;

typedef enum {
    NS_RECORD_SCHEDULE = 0,
    NS_RECORD_MOTION,
    NS_RECORD_ALARM,
    NS_RECORD_A_OR_M,
    NS_RECORD_A_AND_M
} NS_RECORD_TYPE;
typedef struct {
    int enable;
    NS_RECORD_TYPE record_type[7][NS_MAX_TIME_SEG];
    NsstDay dayofweek[7];
} NsstRecordSchedule;

typedef struct {
    int type;
    int enable;
    int status;
    char title[NSST_SHORT_LEN];
} NsstPortAlarm;

typedef struct {
    int enable;
    int format;
    int quality;
    int width;//read only
    int height;//read only
    int interval_value;
    int interval_unit;
    int trigger_ftp;
    int trigger_email;
    int trigger_sdcard;
} NsstCaptureConfig;

typedef enum {
    NS_SD_NOT_EXIST = 0,
    NS_SD_NOT_FORMAT,
    NS_SD_FORMATING,
    NS_SD_UNMOUNTED,
    NS_SD_MOUNTED,
    NS_SD_READY
} NS_SD_STATUS;

#define NS_MAX_STORAGE_DEVICES (8)
typedef struct {
    int index;
    int total;
    int used;
    NS_SD_STATUS status;
    int type;
    int property;
    int progress;
} NsstStorageDevice;

typedef struct {
    int channel;
    int stream;
    char path[NSST_SHORT_LEN];
    __int64 size;
    int event_type;
    int begin_time;
    int end_time;
    int total_frames;
    int width;
    int height;
} NsstMediaFileItem;

#define NS_COUNT_PER_PAGE (32)
typedef struct {
    int total;
    int current_count;
    int file_type;
    NsstMediaFileItem item[NS_COUNT_PER_PAGE];
} NsstMediaFileList;

typedef struct {
    int event_type;
    int begin_time;
    int end_time;
    int file_type;
    int begin_index;
    int page_count;
} NsstSearchFileCondition;
//////////////////////////////////////////////////////////////////////////
typedef void(CALLBACK *fNsstMessageCallBack)(int event_type,NsstEventCommonParam* event_param);
typedef int (CALLBACK *fNSSTMediaStreamCallBack)(NsstChannel* nsst_channel,
                                                 int data_type,
                                                 char* buffer,
                                                 int buffer_size,
                                                 int user_data);
#endif // nsst_define_H_