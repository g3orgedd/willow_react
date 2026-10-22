// Source: CLARiSOFT.exe @ 00e65afe; FUN_00e65afe

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall
FUN_00e65afe(void *this,uint param_1,undefined4 param_2,int *param_3,undefined4 param_4,int *param_5
            ,BSTR param_6)

{
  undefined4 uVar1;
  uint uVar2;
  
  *(undefined ***)this = CGenericFieldList::vftable;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  uVar1 = FUN_00e68516((int *)0x0,(int *)0x0);
  *(undefined4 *)((int)this + 0x10) = uVar1;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  uVar1 = FUN_00e68516((int *)0x0,(int *)0x0);
  *(undefined4 *)((int)this + 0x28) = uVar1;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined4 *)((int)this + 0x34) = param_4;
  *(uint *)((int)this + 4) = param_1;
  uVar1 = FUN_00ec8db7(-(uint)((int)((ulonglong)param_1 * 4 >> 0x20) != 0) |
                       (uint)((ulonglong)param_1 * 4));
  uVar2 = 0;
  *(undefined4 *)((int)this + 0xc) = uVar1;
  if (param_1 != 0) {
    do {
      *(uint *)(*(int *)((int)this + 0xc) + uVar2 * 4) = *(int *)((int)this + 8) * uVar2;
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_1);
  }
  FUN_00e65a53((void *)((int)this + 0x18),&param_3);
  *(undefined4 *)((int)this + 0x30) = 0;
  FUN_00e11de5((void *)((int)this + 0x38),(int *)&param_5);
  FUN_00e01fd0((void *)((int)this + 0x3c),(int *)&param_6);
  FUN_00e66867(this);
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 8))(param_3);
  }
  if (param_5 != (int *)0x0) {
    (**(code **)(*param_5 + 8))(param_5);
  }
  SysFreeString(param_6);
  return this;
}


