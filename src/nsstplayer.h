#ifndef nsstplayer_H_
#define nsstplayer_H_

#include "nsstplayer_define.h"

#ifndef PLAYERAPI
#define PLAYERAPI __stdcall
#endif

int PLAYERAPI NPLStartup(HWND msg_wnd);

void PLAYERAPI NPLCleanup();

bool PLAYERAPI NPLCheckD3dSupport();

NPLID PLAYERAPI NPLPlay(const char* url,DrawParams draw_param,bool open_audio,bool realtime,int transport_type);//0,udp,1,tcp

void PLAYERAPI NPLSetStreamDataCallback(NPLID id,fNPLStreamDataCallBack func,int userdata);

int PLAYERAPI NPLOpenVideo(NPLID id);

void PLAYERAPI NPLCloseVideo(NPLID id);

void PLAYERAPI NPLSetPlaySpeed(NPLID id,int speed);

void PLAYERAPI NPLStepForward(NPLID id);

NPLID PLAYERAPI NPLDownloadRecord(const char* url);

__int64 PLAYERAPI NPLGetCurrentSpeed(NPLID id);

void PLAYERAPI NPLShowCurrentSpeed(NPLID id, bool show);

void PLAYERAPI NPLZoom(NPLID id,RECT* rc);

void PLAYERAPI NPLPause(NPLID id);

void PLAYERAPI NPLResume(NPLID id);

void PLAYERAPI NPLGetPictureWH(NPLID id,int* width,int* height);

int  PLAYERAPI NPLStartEncodeAudio();

int  PLAYERAPI NPLGetEncodeAudioData(char* buffer,int bufferlen);

void PLAYERAPI NPLStopEncodeAudio();

__int64 PLAYERAPI NPLGetTotalTime(NPLID id);

__int64 PLAYERAPI NPLGetCurrentTime(NPLID id);

__int64 PLAYERAPI NPLGetTotalFrames(NPLID id);

__int64 PLAYERAPI NPLGetCurrentFrame(NPLID id);

int PLAYERAPI NPLGetCurrentFrameRate(NPLID id);

int PLAYERAPI NPLStartRecord(NPLID id,const char* utf8_full_path);

void PLAYERAPI NPLStopRecord(NPLID id);

int PLAYERAPI NPLLocalCapture(NPLID id,const char* utf8_full_path);

int PLAYERAPI NPLOpenAudio(NPLID id);

void PLAYERAPI NPLCloseAudio();

void PLAYERAPI NPLAudioDenoise(bool open);

void PLAYERAPI NPLSetAudioVolume(unsigned int volume);

void PLAYERAPI NPLStop(NPLID id);

void PLAYERAPI NPLSeekPos(NPLID id,int permillage);

void PLAYERAPI NPLSetDelayLevel(NPLID id,int level);

void PLAYERAPI NPLDrawRect(NPLID id,bool draw_rect,RECT* rc,unsigned long color);

bool PLAYERAPI NPLGetDrawRectInfo(NPLID id,RECT* rc);

int  PLAYERAPI NPLDrawText(NPLID id,int text_index,RECT* rc,const char* text,unsigned long color);

void PLAYERAPI NPLGetTextRealRect(NPLID id,int text_index,RECT* rc);

int  PLAYERAPI NPLCalcDrawRectScale(RECT* base_rect,RECT* sub_rect,RECT* scale_rect);

int  PLAYERAPI NPLCalcDrawRectBase(RECT* scale_rect,RECT* base_rect,RECT* sub_rect);

void PLAYERAPI NPLShowAlarmArea(NPLID id,bool enable);

void PLAYERAPI NPLSetAlarmArea(NPLID id,RECT* area,bool enable);

bool PLAYERAPI NPLGetAllAlarmArea(NPLID id,int* start);//NPL_MOTION_ALARM_AREA_V*int

void PLAYERAPI NPLSetAllAlarmArea(NPLID id,int* start);//NPL_MOTION_ALARM_AREA_V*int

void PLAYERAPI NPLClearAlarmArea(NPLID id);

#endif // nsstplayer_H_
