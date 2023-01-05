#ifndef CUTE_IPC_H
#define CUTE_IPC_H
#include "stdint.h"
#define NULL (0)
#define MOD_ID_ALL 0xFF
//模块的IPC接收回调函数类型
typedef void (*func_modEventHandle)(uint32_t event,uint32_t param);
//IPC类型
typedef struct IPC_T
{
	uint8_t modNum;
	func_modEventHandle *modEventHandleTable;
}IPC;
//IPC模块初始化
void IPC_Init(func_modEventHandle *funcTable);
//IPC模块接收消息
void IPC_TransMsg(uint8_t modId,uint32_t event_id,uint32_t event_param);
#endif