#include "cuteipc.h"
static IPC ipcObject;
// IPC模块初始化
void IPC_Init(func_modEventHandle *funcTable)
{
    if (NULL != funcTable)
    {
        ipcObject.modEventHandleTable = funcTable;
        ipcObject.modNum = sizeof(funcTable) / sizeof(func_modEventHandle);
    }
}
// IPC模块接收消息
void IPC_TransMsg(uint8_t modId, uint32_t event_id, uint32_t event_param)
{
    if (modId > ipcObject.modNum)
    {
        return;
    }
    if (MOD_ID_ALL == modId)
    {
        for (uint8_t i = 0; i < ipcObject.modNum; i++)
        {
            ipcObject.modEventHandleTable[i](event_id, event_param);
        }
    }
    else
    {
        ipcObject.modEventHandleTable[modId](event_id, event_param);
    }
}