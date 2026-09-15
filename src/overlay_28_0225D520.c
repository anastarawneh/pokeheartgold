#include "overlay_28_0225D520.h"

#include "global.h"

extern u32 ov01_021E7F54(FieldSystem *);
extern u32 ov01_021F6BB0(u32);
extern u32 ov01_021F6BD0(u32);
extern void ov28_0225D650(BgConfig *);
extern void ov28_0225D6E0(BgConfig *);
extern void ov28_0225D6FC(UnkStruct_ov28_0225DC2C *, NARC *);
extern void ov28_0225D764(UnkStruct_ov28_0225DC2C *);
extern void ov28_0225D7C4(UnkStruct_ov28_0225DC2C *);
extern void ov28_0225D7E0(UnkStruct_ov28_0225DC2C *);
extern void ov28_0225D878(UnkStruct_ov28_0225DC2C *);
extern void ov28_0225D898(UnkStruct_ov28_0225DC2C *, NARC *);
extern void ov28_0225D8D0(UnkStruct_ov28_0225DC2C *);
extern void ov28_0225DC2C(SysTask *, void *);
extern void DowsingMchn_FreeHiddenItemLocs(void);

SysTask *ov28_0225D520(BgConfig *bgConfig, u32 param1, FieldSystem *fieldSystem, u32 param3) {
    LocalMapObject *mapObj;

    Heap_Create(HEAP_ID_3, HEAP_ID_8, 0x18000);
    reg_G2S_DB_BLDCNT = 0;
    SysTask *sysTask = CreateSysTaskAndEnvironment(ov28_0225DC2C, sizeof(UnkStruct_ov28_0225DC2C), 0xA, HEAP_ID_8); // r6
    UnkStruct_ov28_0225DC2C *data = SysTask_GetData(sysTask);                                                       // r4
    data->bgConfig = bgConfig;
    data->unk_14 = param1;
    data->fieldSystem = fieldSystem;
    data->unk_1C = param3;
    data->sysTask = sysTask;
    data->unk_33C = 0;
    data->unk_334 = ov01_021E7F54(data->fieldSystem);
    if (data->unk_334 == 1) {
        FieldSystem_GetFacingObject(data->fieldSystem, &mapObj);
        if (ov01_021F6BD0(MapObject_GetScriptID(mapObj)) == 1 || ov01_021F6BB0(MapObject_GetSpriteID(mapObj)) == 1) {
            data->unk_334 = 0;
        }
    }
    NARC *narc = NARC_New(NARC_a_2_5_1, HEAP_ID_8); // r7
    ov28_0225D628();
    ov28_0225D650(bgConfig);
    ov28_0225D6FC(data, narc);
    ov28_0225D764(data);
    ov28_0225D7E0(data);
    ov28_0225D898(data, narc);
    NARC_Delete(narc);
    return sysTask;
}

void ov28_0225D5EC(u32 param0, SysTask *sysTask) {
    UnkStruct_ov28_0225DC2C *data = SysTask_GetData(sysTask); // r4
    DowsingMchn_FreeHiddenItemLocs();
    ov28_0225D8D0(data);
    ov28_0225D878(data);
    ov28_0225D7C4(data);
    ov28_0225D6E0(data->bgConfig);
    DestroySysTaskAndEnvironment(sysTask);
    Heap_Destroy(HEAP_ID_8);
}

u32 ov28_0225D624(void) {
    return 1;
}

void ov28_0225D628(void) {
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_32_H);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_16_I);
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xFFCFFFEF | (1 << 4);
}
