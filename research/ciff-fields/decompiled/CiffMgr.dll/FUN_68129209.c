// Source: CiffMgr.dll @ 68129209; FUN_68129209

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_68129209(SAFEARRAY *param_1,SAFEARRAY *param_2,int param_3,int *param_4)

{
  SAFEARRAY *pSVar1;
  int iVar2;
  wchar_t *pwVar3;
  BSTR local_1c;
  int *local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_18 = (int *)0x0;
  local_8 = 0;
  FUN_6810210e(&local_1c,(OLECHAR *)PTR_DAT_68160004);
  local_8._0_1_ = 1;
  FUN_6810210e(local_14,(OLECHAR *)PTR_u_version__1_0__68160008);
  local_8 = CONCAT31(local_8._1_3_,2);
  pwVar3 = (wchar_t *)PTR_u_encoding__UTF_8__6816000c;
  if (param_3 == 1) {
    pwVar3 = (wchar_t *)PTR_u_encoding__UTF_16__68160010;
  }
  FUN_68124404(local_14,pwVar3);
  pSVar1 = param_1;
  iVar2 = (**(code **)(**(int **)param_1 + 0xd0))(*(int **)param_1,local_1c,local_14[0],&local_18);
  if ((-1 < iVar2) && (local_18 != (int *)0x0)) {
    iVar2 = (**(code **)(**(int **)pSVar1 + 0x54))(*(int **)pSVar1,local_18,0);
  }
  SysFreeString(local_14[0]);
  SysFreeString(local_1c);
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  if (-1 < iVar2) {
    param_1 = (SAFEARRAY *)0x0;
    local_8 = 3;
    iVar2 = (**(code **)(**(int **)pSVar1 + 0xbc))
                      (*(int **)pSVar1,PTR_u_ImageDesign_6815fc3c,&param_1);
    if (-1 < iVar2) {
      if (param_1 != (SAFEARRAY *)0x0) {
        iVar2 = (**(code **)(**(int **)pSVar1 + 0x54))(*(int **)pSVar1,param_1,0);
      }
      if ((-1 < iVar2) && (param_1 != (SAFEARRAY *)0x0)) {
        iVar2 = FUN_6812dc1c(pSVar1,param_2,&param_1,param_3,param_4);
      }
    }
    local_8 = 0xffffffff;
    if (param_1 != (SAFEARRAY *)0x0) {
      (**(code **)(*(int *)param_1 + 8))(param_1);
    }
  }
  return iVar2;
}


