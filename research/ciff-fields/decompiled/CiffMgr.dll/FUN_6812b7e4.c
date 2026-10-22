// Source: CiffMgr.dll @ 6812b7e4; FUN_6812b7e4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_6812b7e4(void *this,int *param_1,int *param_2,BSTR param_3)

{
  BSTR pOVar1;
  int iVar2;
  UINT UVar3;
  short *psVar4;
  BSTR local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_14[0] = (BSTR)0x0;
  local_8 = 0;
  iVar2 = (**(code **)(*(int *)*param_2 + 0x70))((int *)*param_2,local_14);
  if (-1 < iVar2) {
    UVar3 = SysStringLen(local_14[0]);
    pOVar1 = param_3;
    if (UVar3 != 0) {
      iVar2 = FUN_6810226e(param_1,(undefined4 *)param_3,PTR_u_ConnStr_6815fca8,local_14[0]);
    }
    if (-1 < iVar2) {
      param_3 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar2 = (**(code **)(*(int *)*param_2 + 0x68))((int *)*param_2,&param_3);
      if (-1 < iVar2) {
        iVar2 = FUN_6810226e(param_1,(undefined4 *)pOVar1,PTR_u_SrcSQL_6815fd70,param_3);
      }
      local_8 = local_8 & 0xffffff00;
      SysFreeString(param_3);
      if ((-1 < iVar2) &&
         (iVar2 = (**(code **)(*(int *)*param_2 + 0xec))((int *)*param_2,&param_3), -1 < iVar2)) {
        if (param_3 != (BSTR)0x0) {
          psVar4 = FUN_6812f174(this,(int)param_3);
          iVar2 = FUN_6810248f(param_1,(undefined4 *)pOVar1,PTR_u_StartChar_6815fd68,psVar4);
        }
        if ((-1 < iVar2) &&
           (iVar2 = (**(code **)(*(int *)*param_2 + 0xf4))((int *)*param_2,&param_3), -1 < iVar2)) {
          if (param_3 != (BSTR)0x0) {
            psVar4 = FUN_6812f174(this,(int)param_3);
            iVar2 = FUN_6810248f(param_1,(undefined4 *)pOVar1,PTR_u_NoOfChars_6815fd6c,psVar4);
          }
          if (-1 < iVar2) {
            param_3 = (BSTR)0x0;
            CComQIPtr<>(&param_2,(undefined4 *)*param_2);
            local_8._0_1_ = 2;
            if (((param_2 != (int *)0x0) &&
                (iVar2 = (**(code **)(*param_2 + 400))(param_2,&param_3), -1 < iVar2)) &&
               (param_3 != (BSTR)0x0)) {
              psVar4 = FUN_6812f174(this,(int)param_3);
              iVar2 = FUN_6810248f(param_1,(undefined4 *)pOVar1,PTR_u_SelectMode_6815fff0,psVar4);
            }
            local_8 = (uint)local_8._1_3_ << 8;
            if (param_2 != (int *)0x0) {
              (**(code **)(*param_2 + 8))(param_2);
            }
          }
        }
      }
    }
  }
  SysFreeString(local_14[0]);
  return iVar2;
}


