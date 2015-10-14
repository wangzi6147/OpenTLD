#ifndef nss_toolkit_H_
#define nss_toolkit_H_

#include "nsst_define.h"
#include "nsddefine.h"
#include "nsstplayer_define.h"

#ifdef NSS_TOOLKIT_EXPORTS
#define NSST_API __declspec(dllexport)
#else
#define NSST_API __declspec(dllimport)
#endif

#ifndef APICALL
#define APICALL __stdcall
#endif

NSST_API int APICALL NSSTStartup();
NSST_API void APICALL NSSTCleanup();

NSST_API void APICALL NSSTSetUserCallback(fNsstMessageCallBack msgcallback,void* user_data);

NSST_API DEVICE_ID APICALL NSSTCreateDevice(NsstDevice* device,AppProxy* proxy);
NSST_API void APICALL NSSTReleaseDevice(DEVICE_ID device_id);

NSST_API void APICALL NSSTLogin(DEVICE_ID device_id);
NSST_API void APICALL NSSTLogout(DEVICE_ID device_id);

NSST_API void APICALL NSSTGetDeviceDetails(DEVICE_ID device_id);

NSST_API bool APICALL NSSTIsRealtimeChannel(NsstChannel* nsst_channel);

NSST_API int APICALL NSSTStartTransport(
                                        NsstChannel* nsst_channel,
                                        NsstTransportType ttype,
                                        DrawParams* draw_param,
                                        int delay_level
                                        );

NSST_API int APICALL NSSTStartRecordTransport(
    NsstChannel* nsst_channel,
    DrawParams* draw_param,
    char* path
    );

NSST_API int APICALL NSSTStartRecordDownload(
    NsstChannel* nsst_channel,
    char* path
    );

NSST_API int APICALL NSSTStartPictureDownload(
    NsstChannel* nsst_channel,
    char* path,
    char* local_path,
    int filesize
    );

NSST_API void APICALL NSSTStopPictureDownload(NsstChannel* nsst_channel);

NSST_API int APICALL NSSTStopTransport(NsstChannel* nsst_channel);

NSST_API void APICALL NSSTPlayAudio(NsstChannel* nsst_channel);
NSST_API void APICALL NSSTCloseAudio(NsstChannel* nsst_channel);

NSST_API int APICALL NSSTDrawRect(NsstChannel* nsst_channel,RECT* rc,int color);
NSST_API void APICALL NSSTClearDrawRect(NsstChannel* nsst_channel);

NSST_API int APICALL NSSTStartPlay(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTStopPlay(NsstChannel* nsst_channel);

NSST_API int APICALL NSSTStartRecord( NsstChannel* nsst_channel,char* file_path );
NSST_API int APICALL NSSTStopRecord( NsstChannel* nsst_channel );

NSST_API void APICALL NSSTMediaPause( NsstChannel* nsst_channel );
NSST_API void APICALL NSSTMediaResume( NsstChannel* nsst_channel );
NSST_API void APICALL NSSTMediaSetSpeed( NsstChannel* nsst_channel,int speed );
NSST_API void APICALL NSSTMediaZoom( NsstChannel* nsst_channel,RECT* rc );
NSST_API void APICALL NSSTMediaStep( NsstChannel* nsst_channel );
NSST_API __int64 APICALL NSSTMediaGetTotalTime( NsstChannel* nsst_channel );
NSST_API __int64 APICALL NSSTMediaGetCurrentTime( NsstChannel* nsst_channel );
NSST_API void APICALL NSSTMediaSetVolume( int volume );
NSST_API void APICALL NSSTMediaSeekPos( NsstChannel* nsst_channel,int permillage );

NSST_API int APICALL NSSTGetVAConfig(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetVAConfig(NsstChannel* nsst_channel,NsstVAConfig* vaconfig);

NSST_API int APICALL NSSTGetBitrateConfig(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetBitrateConfig(NsstChannel* nsst_channel,
                                          int bitrate_type,
                                          int max_bitrate);

NSST_API int APICALL NSSTGetIFrameInterval(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetIFrameInterval(NsstChannel* nsst_channel,int interval);

NSST_API int APICALL NSSTGetVideoQuality(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetVideoQuality(NsstChannel* nsst_channel,int quality);

NSST_API int APICALL NSSTLocalCapture( NsstChannel* nsst_channel,char* file_path );

NSST_API int APICALL NSSTPTZControl(NsstChannel* nsst_channel,NsstPTZParam* param);

NSST_API int APICALL NSSTPTZPreset(
    NsstChannel* nsst_channel,
    NS_PRESET_CMD cmd,
    int preset_index,
    char* title
);

NSST_API int APICALL NSSTPTZSwitch( NsstChannel* nsst_channel,NS_PTZ_SWITCH_TYPE type,int status );

NSST_API int APICALL NSSTDeadPixelCorrection(NsstChannel* nsst_channel);

NSST_API void APICALL NSSTShowFPSOverlay(NsstChannel* nsst_channel,bool show);

NSST_API int APICALL NSSTGetFrameRate(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetFrameRate(NsstChannel* nsst_channel,int frame_rate);

NSST_API int APICALL NSSTCommonCalcRectScale(RECT* base_rect,RECT* sub_rect,RECT* scale_rect);
NSST_API int APICALL NSSTCommonCalcRectBase(RECT* scale_rect,RECT* base_rect,RECT* sub_rect);

NSST_API int APICALL NSSTGetCameraParams(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetCameraParams(NsstChannel* nsst_channel,NsstCameraParams* camera_params);

NSST_API void APICALL NSSTGetNetConfig(DEVICE_ID device_id);
NSST_API int  APICALL NSSTSetNetConfig(DEVICE_ID device_id,NsstNetConfig* net_config);

NSST_API void APICALL NSSTGetMacAddress(DEVICE_ID device_id);
NSST_API void APICALL NSSTSetMacAddress(DEVICE_ID device_id,const char* mac_address);

NSST_API void APICALL NSSTGetTimeConfig(DEVICE_ID device_id );
NSST_API void APICALL NSSTSetTimeConfig(DEVICE_ID device_id ,NsstTimeConfig* config);

NSST_API int APICALL NSSTGetFocusConfig(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetFocusConfig(NsstChannel* nsst_channel,int mode,int min_distance);

NSST_API int APICALL NSSTGetIrisConfig(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetIrisConfig(NsstChannel* nsst_channel, NsstIrisConfig* config);

NSST_API int APICALL NSSTGetWBConfig(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetWBConfig(NsstChannel* nsst_channel,
                                     int mode,
                                     int gain_r,
                                     int gain_b);

NSST_API int APICALL NSSTGetDayNightSwitch(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetDayNightSwitch(NsstChannel* nsst_channel,
                                           int type,
                                           int sensitivity);

NSST_API int APICALL NSSTGetLocalOutput(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetLocalOutput(NsstChannel* nsst_channel,int enable);

NSST_API int APICALL NSSTGetVideoStandard(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetVideoStandard(NsstChannel* nsst_channel,int standard);

NSST_API int APICALL NSSTGetVideoMirror(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetVideoMirror(NsstChannel* nsst_channel,int mode);

NSST_API int APICALL NSSTGetVideoDenoise(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetVideoDenoise(NsstChannel* nsst_channel,int enable,int level_2d,int level_3d);

NSST_API int APICALL NSSTGetWDR(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetWDR(NsstChannel* nsst_channel,int enable,int level);

NSST_API void APICALL NSSTStartRecvDevMessage(DEVICE_ID device_id);
NSST_API void APICALL NSSTStopRecvDevMessage(DEVICE_ID device_id);

NSST_API void APICALL NSSTStartTalk(DEVICE_ID device_id);
NSST_API void APICALL NSSTStopTalk(DEVICE_ID device_id);

NSST_API int APICALL NSSTSetPTZSequence( NsstChannel* nsst_channel,
                                         int index,
                                         int control,
                                         NsstPTZSequenceItem* item,
                                         int item_count);
NSST_API int APICALL NSSTGetPTZSequence( NsstChannel* nsst_channel,int index );

NSST_API int APICALL NSSTPTZPattern( NsstChannel* nsst_channel,int index,int control );
NSST_API int APICALL NSSTPTZScan( NsstChannel* nsst_channel,int index,int control,int speed );

NSST_API int APICALL NSSTGetAudioInput(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetAudioInput(NsstChannel* nsst_channel,int mode,int volume);

NSST_API int APICALL NSSTGetIRLed(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetIRLed(NsstChannel* nsst_channel,NsstIRConfig* config);

NSST_API int APICALL NSSTGetOSD(NsstChannel* nsst_channel,NS_OSD_TYPE osd_type);
NSST_API int APICALL NSSTSetOSD(NsstChannel* nsst_channel,NsstOSD* config);

NSST_API int APICALL NSSTGetMotionAlarmArea(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetMotionAlarmArea(NsstChannel* nsst_channel,int* area);

NSST_API int APICALL NSSTGetMotionAlarmConfig(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetMotionAlarmConfig(NsstChannel* nsst_channel,int enable,int sensitivity);

NSST_API void APICALL NSSTGetDDNS(DEVICE_ID device_id);
NSST_API void APICALL NSSTSetDDNS(DEVICE_ID device_id,int enable,NsstDDNS* config);

NSST_API void APICALL NSSTGetPPPoE(DEVICE_ID device_id);
NSST_API void APICALL NSSTSetPPPoE(DEVICE_ID device_id,NsstPPPoE* config);

NSST_API void APICALL NSSTGetUPnP(DEVICE_ID device_id);
NSST_API void APICALL NSSTSetUPnP(DEVICE_ID device_id,int enable,const char* alias);

NSST_API void APICALL NSSTGetFTP(DEVICE_ID device_id);
NSST_API void APICALL NSSTSetFTP(DEVICE_ID device_id,NsstFTP* config);

NSST_API void APICALL NSSTGetEmail(DEVICE_ID device_id);
NSST_API void APICALL NSSTSetEmail(DEVICE_ID device_id,NsstEmail* config);

NSST_API void APICALL NSSTGetUsers(DEVICE_ID device_id);
NSST_API void APICALL NSSTSetUsers(DEVICE_ID device_id,int control,NsstUserManage* config);

NSST_API void APICALL NSSTGetIPFilter(DEVICE_ID device_id);
NSST_API void APICALL NSSTSetIPFilter(DEVICE_ID device_id,NsstIPFilter* config);

NSST_API void APICALL NSSTGetRTSPAuth(DEVICE_ID device_id);
NSST_API void APICALL NSSTSetRTSPAuth(DEVICE_ID device_id,int auth_type);

NSST_API void APICALL NSSTGetAnonymous(DEVICE_ID device_id);
NSST_API void APICALL NSSTSetAnonymous(DEVICE_ID device_id,int anonymous);

NSST_API int APICALL NSSTGetAlarmTrigger(NsstChannel* nsst_channel,NS_TRIGGER_ATYPE type);
NSST_API int APICALL NSSTSetAlarmTrigger(NsstChannel* nsst_channel,NsstAlarmTrigger* config);

NSST_API int APICALL NSSTGetAlarmSchedule(NsstChannel* nsst_channel,NS_ALARM_TYPE type);
NSST_API int APICALL NSSTSetAlarmSchedule(NsstChannel* nsst_channel,NsstAlarmSchedule* config);

NSST_API int APICALL NSSTGetPortAlarm(NsstChannel* nsst_channel,int type);
NSST_API int APICALL NSSTSetPortAlarm(NsstChannel* nsst_channel,NsstPortAlarm* config);

NSST_API int APICALL NSSTGetOutputDelay(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetOutputDelay(NsstChannel* nsst_channel,int delay);


NSST_API int APICALL NSSTDrawText(NsstChannel* nsst_channel,
                                  int index,
                                  const char* text,
                                  POINT pos,
                                  unsigned long color);

NSST_API int APICALL NSSTGetTextRealRect(NsstChannel* nsst_channel,int index,RECT* rc);

NSST_API int APICALL NSSTShowDrawAlarmArea(NsstChannel* nsst_channel,bool enable);
NSST_API int APICALL NSSTSetDrawAlarmArea(NsstChannel* nsst_channel,RECT* area,bool enable);
NSST_API int APICALL NSSTGetAllDrawAlarmArea(NsstChannel* nsst_channel,int* area);
NSST_API int APICALL NSSTSetAllDrawAlarmArea(NsstChannel* nsst_channel,int* area);
NSST_API int APICALL NSSTClearDrawAlarmArea(NsstChannel* nsst_channel);

NSST_API void APICALL NSSTRebootDevice(DEVICE_ID device_id);
NSST_API void APICALL NSSTRestoreDevice(DEVICE_ID device_id,int restore_type);

NSST_API void APICALL NSSTSetMediaStreamCallback(NsstChannel* nsst_channel,
                                                 fNSSTMediaStreamCallBack func,
                                                 int userdata);

NSST_API int APICALL NSSTGetRecordSchedule(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetRecordSchedule(NsstChannel* nsst_channel,NsstRecordSchedule* config);

NSST_API void APICALL NSSTGetStorageDevices(DEVICE_ID device_id);
NSST_API void APICALL NSSTFormatStorageDevice(DEVICE_ID device_id,int index);

NSST_API int APICALL NSSTGetStorageQuota(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetStorageQuota(NsstChannel* nsst_channel,int record_quota);

NSST_API int APICALL NSSTGetCaptureConfig(NsstChannel* nsst_channel);
NSST_API int APICALL NSSTSetCaptureConfig(NsstChannel* nsst_channel,NsstCaptureConfig* config);

NSST_API int APICALL NSSTSearchFile(NsstChannel* nsst_channel,NsstSearchFileCondition* condition);

NSST_API void APICALL NSSTUpgrade(DEVICE_ID device_id,char* file_path);
NSST_API void APICALL NSSTStopUpgrade(DEVICE_ID device_id);

#endif // nss_toolkit_H_