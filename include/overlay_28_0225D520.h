#ifndef POKEHEARTGOLD_OVERLAY_28_H
#define POKEHEARTGOLD_OVERLAY_28_H

#include "field_system.h"
#include "map_object.h"
#include "sys_task.h"
#include "systask_environment.h"
#include "touchscreen.h"
#include "unk_0203DB6C.h"

typedef struct {
    u32 unk_00[4];
    BgConfig *bgConfig;       // 0x10
    u32 unk_14;               // 0x14
    FieldSystem *fieldSystem; // 0x18
    u32 unk_1C;
    SysTask *sysTask;             // 0x20
    SpriteList *spriteList;       // 0x24
    G2dRenderer g2dRenderer;      // 0x28
    GF_2DGfxResMan *gfxResMan[4]; // 0x150
    SpriteResource *unk_160[2];
    u32 unk_168[2];
    SpriteResource *unk_170[2];
    u32 unk_178[2];
    Sprite *unk_180;
    Sprite *sprites[2]; // 0x184
    u32 unk_18C;
    Sprite *unk_190[4];
    String *strings[5]; // 0x1A0
    Window windows[5];  // 0x1B4
    u32 unk_204[18];
    u16 unk_24C_0 : 15;
    u16 unk_24C_F : 1;
    u16 unk_24E;
    u32 unk_250[57];
    u32 unk_334;
    u16 unk_338;
    u16 unk_33A;
    u32 unk_33C;
} UnkStruct_ov28_0225DC2C;

SysTask *ov28_0225D520(BgConfig *bgConfig, u32 param1, FieldSystem *fieldSystem, u32 param3);
void ov28_0225D5EC(u32 param0, SysTask *sysTask);
u32 ov28_0225D624(void);
void ov28_0225D628(void);

#endif // POKEHEARTGOLD_OVERLAY_28_H
