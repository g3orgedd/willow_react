// Source: CiffMgr.dll @ 6812a184; FUN_6812a184

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6812a184(int *param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined *puVar4;
  int local_1c;
  int local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar2 = param_2;
  uStack_4 = 0xc;
  local_8 = 0x6812a190;
  iVar3 = (**(code **)(*(int *)*param_2 + 0xc0))((int *)*param_2,local_18);
  piVar1 = param_1;
  if (-1 < iVar3) {
    if (local_18[0] != 0) {
      puVar4 = FUN_6812e9d1(local_18[0]);
      iVar3 = FUN_6810248f(piVar1,param_3,PTR_u_HRDisplayed_6815fe50,puVar4);
    }
    if ((-1 < iVar3) &&
       (iVar3 = (**(code **)(*(int *)*piVar2 + 200))((int *)*piVar2,&param_2), -1 < iVar3)) {
      if (param_2 != (int *)0x0) {
        puVar4 = FUN_6812f091((int)param_2);
        iVar3 = FUN_6810248f(piVar1,param_3,PTR_u_HRPos_6815fe54,puVar4);
      }
      if (-1 < iVar3) {
        param_2 = (int *)0x0;
        local_8 = 0;
        iVar3 = FUN_68124179(piVar1,param_3,PTR_u_HRFont_6815fe58,(int *)&param_2);
        if (-1 < iVar3) {
          iVar3 = FUN_681299bb(piVar1,piVar2,&param_2);
        }
        local_8 = 0xffffffff;
        if (param_2 != (int *)0x0) {
          (**(code **)(*param_2 + 8))(param_2);
        }
        if (-1 < iVar3) {
          CComQIPtr<>(&param_1,(undefined4 *)*piVar2);
          local_8 = 1;
          if (((param_1 != (int *)0x0) &&
              (iVar3 = (**(code **)(*param_1 + 0x214))(param_1,&local_1c), -1 < iVar3)) &&
             (local_1c != 1)) {
            puVar4 = FUN_6812e9d1(local_1c);
            iVar3 = FUN_6810248f(piVar1,param_3,PTR_u_HRPrintCheckDigit_6815ffd8,puVar4);
          }
          local_8 = 0xffffffff;
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 8))(param_1);
          }
        }
      }
    }
  }
  return iVar3;
}


