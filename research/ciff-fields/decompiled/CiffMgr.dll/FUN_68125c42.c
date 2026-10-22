// Source: CiffMgr.dll @ 68125c42; FUN_68125c42

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_68125c42(void *this,int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  OLECHAR *psz;
  short *psVar3;
  undefined *puVar4;
  _union_2683 local_2c;
  int local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x68125c4e;
  CComQIPtr<>(&local_18,(undefined4 *)*param_2);
  puVar1 = param_3;
  local_14[0] = (int *)0x0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  iVar2 = (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,local_14);
  if ((-1 < iVar2) && (local_14[0] != (int *)0x0)) {
    FUN_68132710((uint *)&local_2c,0,0x10);
    VariantInit((VARIANTARG *)&local_2c.n2);
    local_2c._8_4_ = (BSTR)0x0;
    local_2c.n2.vt = 8;
    local_8._0_1_ = 2;
    iVar2 = (**(code **)(*local_18 + 300))(local_18,&param_3);
    if ((-1 < iVar2) && (param_3 != (undefined4 *)0x1)) {
      psz = (OLECHAR *)FUN_6812e9d1((int)param_3);
      local_2c._8_4_ = SysAllocString(psz);
      FUN_681021f5(param_1,local_14,PTR_u_Compatibility_68160084,(undefined4 *)&local_2c);
    }
    VariantClear((VARIANTARG *)&local_2c.n2);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  iVar2 = (**(code **)(*(int *)*param_2 + 0xd4))((int *)*param_2,&local_1c);
  if (-1 < iVar2) {
    psVar3 = FUN_6812f174(this,local_1c);
    iVar2 = FUN_6810248f(param_1,puVar1,PTR_u_BlkW_6815fde8,psVar3);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*(int *)*param_2 + 0xdc))((int *)*param_2,&param_3);
      if (-1 < iVar2) {
        psVar3 = FUN_6812f174(this,(int)param_3);
        iVar2 = FUN_6810248f(param_1,puVar1,PTR_u_BlkH_6815fdec,psVar3);
        if (-1 < iVar2) {
          iVar2 = (**(code **)(*(int *)*param_2 + 0xec))((int *)*param_2,&param_3);
          if (-1 < iVar2) {
            psVar3 = FUN_6812f174(this,(int)param_3);
            iVar2 = FUN_6810248f(param_1,puVar1,PTR_u_MinFontSize_6815fdf0,psVar3);
            if (-1 < iVar2) {
              iVar2 = (**(code **)(*(int *)*param_2 + 0xf4))((int *)*param_2,&param_3);
              if (-1 < iVar2) {
                if (param_3 != (undefined4 *)0x0) {
                  puVar4 = FUN_6812e977((int)param_3);
                  iVar2 = FUN_6810248f(param_1,puVar1,PTR_u_BlkJustify_6815fdf4,puVar4);
                }
                if (-1 < iVar2) {
                  iVar2 = (**(code **)(*(int *)*param_2 + 0x114))((int *)*param_2,&param_2);
                  if ((-1 < iVar2) && (param_2 != (undefined4 *)0x0)) {
                    puVar4 = FUN_6812e9d1((int)param_2);
                    FUN_6810248f(param_1,puVar1,PTR_u_Hyphenation_6815fdf8,puVar4);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}


