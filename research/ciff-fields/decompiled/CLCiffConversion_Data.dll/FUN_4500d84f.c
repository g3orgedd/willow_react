// Source: CLCiffConversion_Data.dll @ 4500d84f; FUN_4500d84f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_4500d84f(void *this,void *param_1)

{
  undefined4 *puVar1;
  void *this_00;
  bool bVar2;
  int iVar3;
  UINT UVar4;
  BSTR local_1c;
  int local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  this_00 = param_1;
  uStack_4 = 0xc;
  local_8 = 0x4500d85b;
  if ((param_1 == (void *)0x0) || (*(int *)((int)param_1 + 4) == 0)) {
    iVar3 = -0x7fffbffd;
  }
  else {
    puVar1 = (undefined4 *)((int)param_1 + 4);
    param_1 = (void *)0x0;
    iVar3 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,&param_1);
    if (((-1 < iVar3) && (param_1 != (void *)0x0)) &&
       (bVar2 = FUN_450023b0((void *)(*(int *)(*(int *)((int)this + -4) + 4) + 0xdc + (int)this),
                             L"Capi"), bVar2)) {
      local_14[0] = 0;
      local_18 = 0;
      iVar3 = (**(code **)(**(int **)((int)this_00 + 4) + 0x80))
                        (*(int **)((int)this_00 + 4),local_14);
      if (-1 < iVar3) {
        iVar3 = (**(code **)(**(int **)((int)this_00 + 4) + 0x78))
                          (*(int **)((int)this_00 + 4),&local_18);
      }
      FUN_450072f3(this_00,&local_1c);
      local_8 = 0;
      if (((-1 < iVar3) && ((local_14[0] == 0 || (local_18 == 0)))) &&
         (UVar4 = SysStringLen(local_1c), UVar4 != 0)) {
        iVar3 = (*(code *)**(undefined4 **)((int)this + -8))(this_00);
      }
      SysFreeString(local_1c);
    }
  }
  return iVar3;
}


