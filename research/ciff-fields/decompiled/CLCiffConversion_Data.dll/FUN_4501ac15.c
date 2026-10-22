// Source: CLCiffConversion_Data.dll @ 4501ac15; FUN_4501ac15

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_4501ac15(void *this,int *param_1)

{
  int iVar1;
  int *this_00;
  UINT UVar2;
  undefined4 uVar3;
  BSTR local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  this_00 = param_1;
  uStack_4 = 8;
  local_8 = 0x4501ac21;
  iVar1 = *(int *)(*(int *)((int)this + 4) + 4);
  if (((*(char *)(iVar1 + 0x100 + (int)this) != '\0') || (*(int *)(iVar1 + 0xcc + (int)this) != 0))
     && (*(char *)(iVar1 + 0x101 + (int)this) == '\0')) {
    return 0;
  }
  local_14[0] = 0;
  CComQIPtr<>(&param_1,(undefined4 *)*param_1);
  local_8 = 0;
  if (param_1 == (int *)0x0) {
    return 0x80004005;
  }
  (**(code **)(*param_1 + 0x48))(param_1,local_14);
  if (local_14[0] == 1) {
    iVar1 = *(int *)(*(int *)((int)this + 4) + 4);
    if (*(short *)(iVar1 + 0x84 + (int)this) != 8) goto LAB_4501ae5c;
    UVar2 = SysStringLen(*(BSTR *)(iVar1 + 0x8c + (int)this));
    if (UVar2 != 0) {
      (**(code **)(*(int *)*this_00 + 100))
                ((int *)*this_00,
                 *(undefined4 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x8c + (int)this));
      uVar3 = *(undefined4 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x8c + (int)this);
LAB_4501ae18:
      (**(code **)(*(int *)*this_00 + 0x5c))((int *)*this_00,uVar3);
      (**(code **)(*param_1 + 0x4c))(param_1,0);
      (**(code **)(*(int *)*this_00 + 0x2c))((int *)*this_00,0);
LAB_4501ae33:
      *(undefined1 *)((int)this + 8) = 1;
      goto LAB_4501ae5c;
    }
    FUN_4500fe88(this_00,&local_18);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  else if (local_14[0] == 2) {
    iVar1 = *(int *)(*(int *)((int)this + 4) + 4);
    if (*(short *)(iVar1 + 0x94 + (int)this) != 8) goto LAB_4501ae5c;
    UVar2 = SysStringLen(*(BSTR *)(iVar1 + 0x9c + (int)this));
    if (UVar2 != 0) {
      (**(code **)(*(int *)*this_00 + 100))
                ((int *)*this_00,
                 *(undefined4 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x9c + (int)this));
      uVar3 = *(undefined4 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x9c + (int)this);
      goto LAB_4501ae18;
    }
    FUN_4500fe88(this_00,&local_18);
    local_8 = CONCAT31(local_8._1_3_,2);
  }
  else if (local_14[0] == 3) {
    iVar1 = *(int *)(*(int *)((int)this + 4) + 4);
    if (*(short *)(iVar1 + 0xa4 + (int)this) != 8) goto LAB_4501ae5c;
    UVar2 = SysStringLen(*(BSTR *)(iVar1 + 0xac + (int)this));
    if (UVar2 != 0) {
      (**(code **)(*(int *)*this_00 + 100))
                ((int *)*this_00,
                 *(undefined4 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xac + (int)this));
      uVar3 = *(undefined4 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xac + (int)this);
      goto LAB_4501ae18;
    }
    FUN_4500fe88(this_00,&local_18);
    local_8 = CONCAT31(local_8._1_3_,3);
  }
  else {
    if ((local_14[0] != 6) ||
       (iVar1 = *(int *)(*(int *)((int)this + 4) + 4), *(short *)(iVar1 + 0xb4 + (int)this) != 8))
    goto LAB_4501ae5c;
    UVar2 = SysStringLen(*(BSTR *)(iVar1 + 0xbc + (int)this));
    if (UVar2 != 0) {
      (**(code **)(*(int *)*this_00 + 100))
                ((int *)*this_00,
                 *(undefined4 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xbc + (int)this));
      (**(code **)(*(int *)*this_00 + 0x5c))
                ((int *)*this_00,
                 *(undefined4 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xbc + (int)this));
      (**(code **)(*param_1 + 0x4c))(param_1,0);
      (**(code **)(*(int *)*this_00 + 0x2c))((int *)*this_00,0);
      (**(code **)(*(int *)*this_00 + 0x54))((int *)*this_00,0);
      goto LAB_4501ae33;
    }
    FUN_4500fe88(this_00,&local_18);
    local_8 = CONCAT31(local_8._1_3_,4);
  }
  (**(code **)(*(int *)*this_00 + 100))((int *)*this_00,local_18);
  SysFreeString(local_18);
LAB_4501ae5c:
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return 0;
}


