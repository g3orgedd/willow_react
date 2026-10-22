// Source: CiffMgr.dll @ 6812e6f0; FUN_6812e6f0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

ULONG __thiscall FUN_6812e6f0(void *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  ULONG UVar4;
  int iVar5;
  ULONG unaff_ESI;
  BSTR local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  puVar1 = param_3;
  uStack_4 = 0xc;
  if (param_2 == (int *)0x0) {
    return unaff_ESI;
  }
  if (param_3 == (undefined4 *)0x0) {
    return unaff_ESI;
  }
  local_14[0] = (int *)0x0;
  local_8 = 0;
  UVar4 = FUN_68102520(local_14);
  if ((int)UVar4 < 0) goto LAB_6812e763;
  if (local_14[0] == (int *)0x0) {
LAB_6812e74d:
    UVar4 = 0x80004005;
  }
  else {
    UVar4 = (**(code **)(*local_14[0] + 0x104))(local_14[0],param_2,&param_3);
    if ((short)param_3 == 0) goto LAB_6812e74d;
    if (-1 < (int)UVar4) {
      local_18 = (int *)0x0;
      local_8._0_1_ = 1;
      UVar4 = (**(code **)(*local_14[0] + 0xb4))(local_14[0],&local_18);
      if ((-1 < (int)UVar4) && (local_18 != (int *)0x0)) {
        local_1c = (BSTR)0x0;
        local_8._0_1_ = 2;
        iVar5 = (**(code **)(*local_18 + 0x1c))(local_18,&local_1c);
        if ((iVar5 < 0) ||
           (bVar3 = FUN_68119d18(&local_1c,(OLECHAR *)PTR_u_ImageDesign_6815fc3c), !bVar3)) {
          UVar4 = 0x80030104;
        }
        else {
          param_2 = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,3);
          UVar4 = (**(code **)*puVar1)(puVar1,&DAT_68148c38,&param_2);
          if (-1 < (int)UVar4) {
            if (param_2 == (int *)0x0) {
              UVar4 = 0x80004005;
            }
            else {
              UVar4 = (**(code **)(*param_2 + 0x8c))(param_2,1);
              if (-1 < (int)UVar4) {
                UVar4 = FUN_68123a44(param_1,(SAFEARRAY *)&param_2,(int *)&local_18,1);
              }
            }
          }
          local_8._0_1_ = 2;
          if (param_2 != (int *)0x0) {
            (**(code **)(*param_2 + 8))(param_2);
          }
        }
        SysFreeString(local_1c);
      }
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
    }
  }
  piVar2 = local_14[0];
  if (local_14[0] != (int *)0x0) {
    local_14[0] = (int *)0x0;
    (**(code **)(*piVar2 + 8))(piVar2);
  }
LAB_6812e763:
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return UVar4;
}


