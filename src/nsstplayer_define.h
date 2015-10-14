#ifndef nsstplayer_define_H_
#define nsstplayer_define_H_

#include <Windows.h>

#define INVALID_NPL_ID   (-1L)

#define NPL_RECT_SCALE (1000.0f)

typedef struct {
    int width;
    int height;
    HWND draw_wnd;
} DrawParams;

typedef int NPLID;

typedef enum {
    NPL_STATUS_RTSP = WM_USER + 5555,
    NPL_STATUS_AUDIO_ENCODER_DATA
};

#define NPL_MOTION_ALARM_AREA_H (22)
#define NPL_MOTION_ALARM_AREA_V (18)

typedef struct {
    int channels;
    int freq;
    int bits_per_sample;
    __int64 timestamp;
    char* data;
    int length;
} NPL_STREAM_AUDIO;

typedef struct {
    int width;
    int height;
    int frame_rate;
    __int64 timestamp;
    char* data;
    int length;
} NPL_STREAM_VIDEO;

typedef enum {
    NPL_VSTREAM = 0,
    NPL_ASTREAM
} NPL_STREAM_TYPE;

typedef int (__stdcall *fNPLStreamDataCallBack)(NPLID player_id,
                                             int data_type,
                                             char* buffer,
                                             int buffer_size,
                                             int user_data);

#endif // nsstplayer_define_H_