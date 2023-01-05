#include "cuteipc.h"
#include "stdio.h"
typedef enum
{
    MOD_ID_TALK,
    MOD_ID_BLUETOOTH,
    MOD_ID_PMU,
    MOD_ID_AUDIO,
    MOD_ID_BUTT,
} MOD_ID;

typedef enum
{
    MSG_ID_TX_START,
    MSG_ID_TX_STOP,
    MSG_ID_LOWER_POWER,
    MSG_ID_BT_SCAN,
    MSG_ID_BT_CLOSE,
} MSG_ID;

void func_TalkEventHandle(uint32_t event_id, uint32_t event_param)
{
    switch (event_id)
    {
    case MSG_ID_TX_START:
    case MSG_ID_TX_STOP:
    case MSG_ID_LOWER_POWER:
    case MSG_ID_BT_SCAN:
    case MSG_ID_BT_CLOSE:
        printf("Talk 订阅 event:%d,param:%d\r\n", event_id, event_param);
        break;
    default:
        printf("Talk 未订阅 event:%d,param:%d\r\n", event_id, event_param);
        break;
    }
}
void func_BTEventHandle(uint32_t event_id, uint32_t event_param)
{
    switch (event_id)
    {
    case MSG_ID_BT_SCAN:
    case MSG_ID_BT_CLOSE:
        printf("BT 订阅 event:%d,param:%d\r\n", event_id, event_param);
        break;
    default:
        printf("BT 未订阅 event:%d,param:%d\r\n", event_id, event_param);
        break;
    }
}
void func_PMUEventHandle(uint32_t event_id, uint32_t event_param)
{
        switch (event_id)
    {
    case MSG_ID_TX_START:
    case MSG_ID_TX_STOP:
        printf("PMU 订阅 event:%d,param:%d\r\n", event_id, event_param);
        break;
    default:
        printf("PMU 未订阅 event:%d,param:%d\r\n", event_id, event_param);
        break;
    }
}
void func_AudioEventHandle(uint32_t event_id, uint32_t event_param)
{
    switch (event_id)
    {
    case MSG_ID_TX_START:
    case MSG_ID_TX_STOP:
    case MSG_ID_LOWER_POWER:
        printf("Audio 订阅 event:%d,param:%d\r\n", event_id, event_param);
        break;
    default:
        printf("Audio 未订阅 event:%d,param:%d\r\n", event_id, event_param);
        break;
    }
}
func_modEventHandle ipcEventTable[MOD_ID_BUTT] =
    {
        func_TalkEventHandle,
        func_BTEventHandle,
        func_PMUEventHandle,
        func_AudioEventHandle,
};

int main()
{
    IPC_Init(ipcEventTable);
    IPC_TransMsg(MOD_ID_TALK,MSG_ID_TX_START,NULL);
    IPC_TransMsg(MOD_ID_BLUETOOTH,MSG_ID_TX_STOP,1);
}