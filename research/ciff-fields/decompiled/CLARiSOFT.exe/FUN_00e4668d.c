// Source: CLARiSOFT.exe @ 00e4668d; FUN_00e4668d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint __cdecl FUN_00e4668d(int *param_1,undefined4 *param_2,int param_3,LPVARIANT param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  VARIANTARG local_3c;
  _union_2683 local_2c;
  int local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_18 = (int *)0x0;
  local_8 = 0;
  iVar2 = FUN_00e464e8(param_1,&DAT_00f429a4,&local_18,'\x01');
  if ((iVar2 < 0) || (local_18 == (int *)0x0)) {
    uVar3 = 0x80004005;
    goto LAB_00e467c1;
  }
  FUN_00e03b51((uint *)&local_2c);
  local_8._0_1_ = 1;
  uVar3 = (**(code **)(*local_18 + 0x30))(local_18,*param_2,&local_2c);
  if (((int)uVar3 < 0) || (local_2c.n2.vt != 9)) {
    uVar3 = (**(code **)(*local_18 + 0x28))
                      (local_18,*param_2,param_3,*(undefined4 *)&param_4->n1,
                       (param_4->n1).decVal.Hi32,*(undefined4 *)((int)&param_4->n1 + 8),
                       *(undefined4 *)((int)&param_4->n1 + 0xc),&local_2c);
  }
  else {
    CComQIPtr<>(local_14,(undefined4 *)local_2c._8_4_);
    if (local_14[0] != (int *)0x0) {
      FUN_00e03b51((uint *)&local_3c);
      local_8._0_1_ = 3;
      (**(code **)(*local_14[0] + 0x24))(local_14[0],&local_1c);
      (**(code **)(*local_14[0] + 0x2c))(local_14[0],&local_3c);
      if (local_1c == param_3) {
        bVar1 = FUN_00e0e9da(&local_3c,param_4);
        if (!bVar1) goto LAB_00e4674d;
      }
      else {
LAB_00e4674d:
        uVar3 = (**(code **)(*local_14[0] + 0x28))(local_14[0],param_3);
        uVar4 = (**(code **)(*local_14[0] + 0x30))
                          (local_14[0],*(undefined4 *)&param_4->n1,(param_4->n1).decVal.Hi32,
                           *(undefined4 *)((int)&param_4->n1 + 8),
                           *(undefined4 *)((int)&param_4->n1 + 0xc));
        uVar3 = uVar3 | uVar4;
      }
      VariantClear(&local_3c);
    }
    local_8._0_1_ = 1;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
  }
  VariantClear((VARIANTARG *)&local_2c.n2);
LAB_00e467c1:
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  return uVar3;
}


