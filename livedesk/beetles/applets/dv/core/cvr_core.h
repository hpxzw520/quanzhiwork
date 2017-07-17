/*
*********************************************************************************************************
*											        ePDK
*						            the Easy Portable/Player Develop Kits
*									           home app sample
*
*						        	(c) Copyright 2006-2009, LYN, China
*											 All Rights Reserved
*
* File    : cvr_core.h
* By      : lyn
* Version : V1.00
*********************************************************************************************************
*/

#ifndef __CVR_CORE_H__
#define __CVR_CORE_H__

#include "..\\dv_i.h"
//\xE5\x85\xA8\xE5\xBF\x97 全志
//#define FILE_PATH        "F:\\\xE5\x85\xA8\xE5\xBF\x97"
//#define RECORD_PATHA     "F:\\\xE5\x85\xA8\xE5\xBF\x97\\DCIMA"
//#define RECORD_PATHB     "F:\\\xE5\x85\xA8\xE5\xBF\x97\\DCIMB"

#define FILE_PATH        "F:\\DCIM"
#define FILE_VIDEO_PATH  "F:\\DCIM\\VIDEO"
#define FILE_PHOTO_PATH  "F:\\DCIM\\PHOTO"

#define MAX_PREFIX       16

#define FRONT_SENSOR_INDEX              (0) //主摄像头选择，0:前镜头对应csi0,后镜头对应csi1; 1:前镜头对应csi1,后镜头对应csi0
#define ANALOG_SENSOR_INDEX             (1) //模拟摄像头对应的index, 0:前镜头是模拟摄像头; 1:后镜头是模拟摄像头。

#define ANALOG_SENSOR_PAL               (0) // 输出PAL
#define ANALOG_SENSOR_NTSC              (1) // 输出NTSC
#define ANALOG_SENSOR_TYPE              (ANALOG_SENSOR_NTSC)

typedef enum tag_WORK_MODE
{
    WORK_MODE_REC,
    WORK_MODE_CAM,
    WORK_MODE_ERR = 0xff,
} __work_mode_e;

typedef enum tag_RECORD_STATE
{
    RECORD_STOP,
    RECORD_START,
    RECORD_HALT,
} __record_state_e;

typedef enum tag_REC_VIEW_MODE
{
    SHOW_HOST,
    SHOW_GUEST,
} __rec_view_mode_e;

typedef enum tag_RECORD_QUALITY
{
    RECORD_QUALITY_640_480,
    RECORD_QUALITY_1280_720,
    RECORD_QUALITY_1920_1080,
} __record_quality_e;

typedef enum tag_CAMERA_QUALITY
{
    CAMERA_QUALITY_100,
    CAMERA_QUALITY_200,
    CAMERA_QUALITY_300,
    CAMERA_QUALITY_500,
    CAMERA_QUALITY_800,
} __camera_quality_e;

typedef enum tag_SENSOR_MODE
{
    FRONT_SENSOR_MODE,
    BACK_SENSOR_MODE,
    FRONT_AND_BACK_SENSOR_MODE,
} __sensor_mode_e;

typedef struct tag_DV_CONFIG
{
    __work_mode_e           work_mode;          // 工作模式(录像、拍照)

    __s32                   record_mute;        // 录像静音模式是否打开(0:无声  1:有声)
    __record_quality_e      rec_quality;        // 录像质量
    __camera_quality_e      cam_quality;        // 拍照质量

} __dv_config_t;


/*
**********************************************************************************************************************
*                                               Cvr_DvOpen
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvOpen(void);

/*
**********************************************************************************************************************
*                                               Cvr_DvConfigPara
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvConfigPara(__dv_config_t *para);

/*
**********************************************************************************************************************
*                                               Cvr_DvSetThumbSize
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/


__s32	__dv_get_last_file(char *dir);

void    Cvr_DvSetThumbSize(__u32 width, __u32 height);

/*
**********************************************************************************************************************
*                                               Cvr_DvSetWorkMode
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvSetWorkMode(__work_mode_e mode);

/*
**********************************************************************************************************************
*                                               Cvr_DvStartRecord
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvStartRecord(void);

/*
**********************************************************************************************************************
*                                               DV_FuncStopRecord
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvStopRecord(void);

/*
**********************************************************************************************************************
*                                               Cvr_DvHaltRecord
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvHaltRecord(void);

/*
**********************************************************************************************************************
*                                               Cvr_DvGetRecState
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__record_state_e    Cvr_DvGetRecState(void);

/*
**********************************************************************************************************************
*                                               Cvr_DvTakeImage
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvTakeImage(__u32 cnt);

/*
**********************************************************************************************************************
*                                               Cvr_DvGetWorkMode
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__work_mode_e   Cvr_DvGetWorkMode(void);

/*
**********************************************************************************************************************
*                                               Cvr_DvGetCurRecTime
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvGetCurRecTime(void);

/*
**********************************************************************************************************************
*                                               Cvr_DvGetThumb
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
FB     *Cvr_DvGetThumb(void);

/*
**********************************************************************************************************************
*                                               Cvr_DvGetFileName
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvGetFileName(char *name, __u32 sensorID);

/*
**********************************************************************************************************************
*                                               Cvr_DvSetRecQuality
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvSetRecQuality(__record_quality_e mode);

/*
**********************************************************************************************************************
*                                               Cvr_DvSetCamQuality
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvSetCamQuality(__camera_quality_e mode);

/*
**********************************************************************************************************************
*                                               Cvr_DvSetColorEffect
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvSetColorEffect(__csi_color_effect_t effect);

/*
**********************************************************************************************************************
*                                               Cvr_DvSetAWB
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvSetAWB(__csi_awb_t awb);

/*
**********************************************************************************************************************
*                                               Cvr_DvSetAE
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvSetAE(__csi_ae_t ae);

/*
**********************************************************************************************************************
*                                               Cvr_DvSetBAND
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvSetBAND(__csi_band_t band);

/*
**********************************************************************************************************************
*                                               Cvr_SetMDSwitch
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_SetMDSwitch(__s32 state);

/*
**********************************************************************************************************************
*                                               Cvr_SetMDPara
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_SetMDPara(__lotus_motion_dectect_para_t *para);

/*
**********************************************************************************************************************
*                                               Cvr_GetMDDetect
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_GetMDDetect(void);

/*
**********************************************************************************************************************
*                                               Cvr_GetRecordBps
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_GetRecordBps(void);

/*
**********************************************************************************************************************
*                                               Cvr_GetPhotoSize
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_GetPhotoSize(void);

/*
**********************************************************************************************************************
*                                               Cvr_SetSensorMode
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
void    Cvr_SetSensorMode(__sensor_mode_e mode);

/*
**********************************************************************************************************************
*                                               Cvr_GetSensorMode
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__sensor_mode_e Cvr_GetSensorMode(void);

/*
**********************************************************************************************************************
*                                               Cvr_SetFrameRate
*
* Description: 设置当前录像帧率（需要sensor支持）
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
void    Cvr_SetFrameRate(__s32 enable);

/*
**********************************************************************************************************************
*                                               Cvr_SetPipViewMode
*
* Description: 画中画打开开关
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
void    Cvr_SetPipViewMode(__s32 enable, RECT rect);

/*
**********************************************************************************************************************
*                                               Cvr_GetPipViewMode
*
* Description: 获取当前画中画打开状态
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_GetPipViewMode(void);

/*
**********************************************************************************************************************
*                                               Cvr_SetRecViewMode
*
* Description: 设置预览图像，如果画中画打开，则为画中画切换，如果画中画关闭，则切换前后镜头。
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
void    Cvr_SetRecViewMode(__rec_view_mode_e mode);

/*
**********************************************************************************************************************
*                                               Cvr_GetRecViewMode
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__rec_view_mode_e   Cvr_GetRecViewMode(void);

/*
**********************************************************************************************************************
*                                               Cvr_DvSetOverlaySrc
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvSetOverlaySrc(__lotus_overlay_src_init_t *src, __u32 sensorID);

/*
**********************************************************************************************************************
*                                               Cvr_DvShowOverlay
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvShowOverlay(__lotus_overlay_dis_par_t *para, __u32 sensorID);

/*
**********************************************************************************************************************
*                                               Cvr_DvRecordMute
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvRecordMute(__u32 enable, __u32 sensorID);

/*
**********************************************************************************************************************
*                                               Cvr_DvSetShowRect
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvSetShowRect(RECT rect, __u32 sensorID);

/*
**********************************************************************************************************************
*                                               Cvr_DvSetHitSaveTime
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvSetHitSaveTime(__s32 time, __u32 sensorID);

/*
**********************************************************************************************************************
*                                               Cvr_DvSeekHitStartTime
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvSeekHitStartTime(__s32 time, __u32 sensorID);

/*
**********************************************************************************************************************
*                                               Cvr_DvChangeNamePrefix
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
void    Cvr_DvChangeNamePrefix(char *prix_name);

/*
**********************************************************************************************************************
*                                               Cvr_DvClose
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/
__s32   Cvr_DvClose(void);

/*
**********************************************************************************************************************
*                                               Cvr_DVStopPreview
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/

void   Cvr_DVStopPreview(void);

/*
**********************************************************************************************************************
*                                               Cvr_DVResumePreview
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/

void   Cvr_DVResumePreview(void);

/*
**********************************************************************************************************************
*                                               Cvr_DVSetSyncCallbackByID
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/

__s32   Cvr_DVSetSyncCallbackByID(__lotus_sync_callback_t  *sync_callback, __u32 sensorID);

/*
**********************************************************************************************************************
*                                               Cvr_DVGetPreviewLayer
*
* Description:
*
* Arguments  :
*
* Returns    :

* Notes      :
*
**********************************************************************************************************************
*/

__s32   Cvr_DVGetPreviewLayer(void);


#endif  /* __CVR_CORE_H__ */

