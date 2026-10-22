// Source: CLCSSmallBarcode.dll @ 4200c0e3; FUN_4200c0e3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_4200c0e3(void *this,int *param_1)

{
  int iVar1;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x4200c0ef;
  if (*param_1 != 0) {
    CComQIPtr<>(&param_1,(undefined4 *)*param_1);
    local_8 = 0;
    if (param_1 != (int *)0x0) {
      local_14[0] = 0;
      iVar1 = (**(code **)(*param_1 + 0x19c))(param_1,local_14);
      if (-1 < iVar1) {
        *(undefined4 *)((int)this + 0x108) = local_14[0];
      }
    }
    local_8 = 0xffffffff;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
  }
  return;
}


