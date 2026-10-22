// Source: CLARiSOFT.exe @ 00e667a4; FUN_00e667a4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_00e667a4(void *this,int *param_1)

{
  undefined4 *this_00;
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_1c;
  undefined4 local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0;
  this_00 = (undefined4 *)((int)this + 0x1c);
  FUN_00e11de5(this_00,(int *)&param_1);
  (**(code **)(*(int *)*this_00 + 0x2c))((int *)*this_00,&local_18);
  *(undefined4 *)((int)this + 4) = local_18;
  (**(code **)(*(int *)*this_00 + 0x34))((int *)*this_00,&local_1c);
  *(undefined4 *)((int)this + 8) = local_1c;
  FID_conflict__free(*(void **)((int)this + 0xc));
  lVar1 = (ulonglong)*(uint *)((int)this + 4) * 4;
  uVar2 = FUN_00ec8db7(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  uVar3 = 0;
  *(undefined4 *)((int)this + 0xc) = uVar2;
  if (*(int *)((int)this + 4) != 0) {
    do {
      *(uint *)(*(int *)((int)this + 0xc) + uVar3 * 4) = *(int *)((int)this + 8) * uVar3;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)((int)this + 4));
  }
  local_14[0] = (BSTR)0x0;
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(*(int *)*this_00 + 0x1c))((int *)*this_00,local_14);
  (**(code **)(**(int **)((int)this + 0x18) + 0x50))(*(int **)((int)this + 0x18),local_14[0]);
  SysFreeString(local_14[0]);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return;
}


