/******************************************************************************
  文 件 名   : vofa_plus.h
  版 本 号   : 初稿
  作    者   : sgeeood
  生成日期   : 2022年8月30日
  最近修改   :
  功能描述   : vofa_plus.c 的头文件
  
  修改历史   :
  1.日    期   : 2022年8月30日
    作    者   : sgeeood
    修改内容   : 创建文件

******************************************************************************/

#ifndef __VOFA_PLUS_H__
#define __VOFA_PLUS_H__

#include "rtconfig.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


#ifdef PKG_USING_VOFA_PLUS

#define VOFA_PLUS_NUMBER_OF_CHANNELS 1
#define VOFA_PLUS_UNIT_BYTES 4
#define VOFA_PLUS_BUFSZ ((VOFA_PLUS_NUMBER_OF_CHANNELS+1)*VOFA_PLUS_UNIT_BYTES)


struct vofa_plus_dev_s
{
    //const char *name;
	unsigned char tx_buff[VOFA_PLUS_BUFSZ];
	float tx_con_buff[VOFA_PLUS_NUMBER_OF_CHANNELS];

};
typedef struct vofa_plus_dev_s vofa_plus_dev_struct_t;
typedef struct vofa_plus_dev_s * vofa_plus_dev_struct_t_p;


extern char vofa_plus_transmit(vofa_plus_dev_struct_t_p dev,unsigned int number_of_channels,...);
extern void vofa_plus_init(void);

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __VOFA_PLUS_H__ */
