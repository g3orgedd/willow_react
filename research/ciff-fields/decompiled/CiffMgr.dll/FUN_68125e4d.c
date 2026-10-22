// Source: CiffMgr.dll @ 68125e4d; FUN_68125e4d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_68125e4d(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  OLECHAR *pOVar2;
  _union_2683 local_24;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  iVar1 = (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,local_14);
  if ((-1 < iVar1) && (local_14[0] != (int *)0x0)) {
    FUN_68132710((uint *)&local_24,0,0x10);
    VariantInit((VARIANTARG *)&local_24.n2);
    local_24._8_4_ = (BSTR)0x0;
    local_24.n2.vt = 8;
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar1 = (**(code **)(*(int *)*param_2 + 0x1c))((int *)*param_2,&param_3);
    if (-1 < iVar1) {
      pOVar2 = FUN_6812f174(this,(int)param_3);
      local_24._8_4_ = SysAllocString(pOVar2);
      iVar1 = FUN_681021f5(param_1,local_14,PTR_u_Left_68160070,(undefined4 *)&local_24);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&param_3);
        if (-1 < iVar1) {
          SysFreeString((BSTR)local_24._8_4_);
          pOVar2 = FUN_6812f174(this,(int)param_3);
          local_24._8_4_ = SysAllocString(pOVar2);
          iVar1 = FUN_681021f5(param_1,local_14,PTR_DAT_68160074,(undefined4 *)&local_24);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*(int *)*param_2 + 0x2c))((int *)*param_2,&param_3);
            if (-1 < iVar1) {
              SysFreeString((BSTR)local_24._8_4_);
              pOVar2 = FUN_6812f174(this,(int)param_3);
              local_24._8_4_ = SysAllocString(pOVar2);
              iVar1 = FUN_681021f5(param_1,local_14,PTR_u_Right_68160078,(undefined4 *)&local_24);
              if (-1 < iVar1) {
                iVar1 = (**(code **)(*(int *)*param_2 + 0x34))((int *)*param_2,&param_3);
                if (-1 < iVar1) {
                  SysFreeString((BSTR)local_24._8_4_);
                  pOVar2 = FUN_6812f174(this,(int)param_3);
                  local_24._8_4_ = SysAllocString(pOVar2);
                  iVar1 = FUN_681021f5(param_1,local_14,PTR_u_Bottom_6816007c,
                                       (undefined4 *)&local_24);
                }
              }
            }
          }
        }
      }
    }
    VariantClear((VARIANTARG *)&local_24.n2);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar1;
}


