#ifndef nsdetector_H_
#define nsdetector_H_

#include "nsddefine.h"

#ifdef NSDETECTOR_EXPORTS
#define NSDETECTOR_API __declspec(dllexport)
#else
#define NSDETECTOR_API __declspec(dllimport)
#endif


#ifndef NSDAPI
#define NSDAPI __stdcall
#endif

NSDETECTOR_API int NSDAPI  NSDStartup(NSD_ON_DISCOVERY_NOTIFY callback_ptr);

NSDETECTOR_API void NSDAPI NSDSearchDevices();

NSDETECTOR_API void NSDAPI NSDModifyPortConfig(NSDDeviceInfo* info,const char* admin_pwd);

NSDETECTOR_API void NSDAPI NSDModifyNetConfig(NSDDeviceInfo* info,const char* admin_pwd);

NSDETECTOR_API void NSDAPI NSDCleanup(void);

NSDETECTOR_API void NSDAPI NSDShow(char* ip,int count,int preset);//64 * count

NSDETECTOR_API void NSDAPI NSDSetMsgCallback(NSD_ON_MSG on_msg);

NSDETECTOR_API void NSDAPI NSDResetAdminPwd(const char* serial,const char* super_pwd);

NSDETECTOR_API void NSDAPI NSDRestoreConfig(const char* serial,const char* admin_pwd,NSD_RESTORE_TYPE type);
#endif // nsdetector_H_