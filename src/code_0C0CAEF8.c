typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern volatile s32 DAT_0c0caef8;

void FUN_0c020ac0(void)
{
    while (DAT_0c0caef8 == 0)
        ;
    DAT_0c0caef8 = 0;
}

extern u32 DAT_0c223604;

struct Struct_0c233d04
{
    u8 filler0[4];
    u32 unk4;
    u32 unk8;
};

extern struct Struct_0c233d04 DAT_0c233d04;
extern void FUN_0c08bfc8(void);

int FUN_0c020b00(void)
{
    FUN_0c08bfc8();
    DAT_0c223604++;
    if (DAT_0c233d04.unk8 != 0)
        DAT_0c233d04.unk4++;
    return 0;
}

#ifdef NONMATCHING
int FUN_0c020b40(void)
{
    DAT_0c0caef8 = 1;
    return 0;
}
#else
asm("
    .balign 0x10
.global _FUN_0c020b40
_FUN_0c020b40:
/* C020B40 E6 2F */	mov.l r14, @-r15  ;# @-r15=>local_4
/* C020B42 04 D2 */	mov.l PTR_DAT_0c020b54, r2  ;# PTR_DAT_0c020b54
/* C020B44 01 E1 */	mov #0x1, r1
/* C020B46 00 E0 */	mov #0x0, r0
/* C020B48 F3 6E */	mov r15, r14
/* C020B4A 12 22 */	mov.l r1, @r2  ;# @r2=>DAT_0c0caef8
/* C020B4C E3 6F */	mov r14, r15
/* C020B4E 0B 00 */	rts 
/* C020B50 F6 6E */	 mov.l @r15+, r14
/* C020B52 09 */	.byte 0x09
/* C020B53 00 */	.byte 0x00
PTR_DAT_0c020b54:
/* C020B54 F8 AE 0C 0C */	.4byte DAT_0c0caef8
");
#endif
