// Source: CLARiSOFT.exe @ 00e464e8; FUN_00e464e8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __cdecl FUN_00e464e8(int *param_1,undefined4 *param_2,undefined4 param_3,char param_4)

{
  undefined4 *puVar1;
  int iVar2;
  _union_2683 local_44;
  _union_2683 local_34;
  _union_2683 local_24;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0xe464f4;
  FUN_00e03b51((uint *)&local_44);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  iVar2 = (**(code **)(*(int *)*param_1 + 0x80))((int *)*param_1,&local_44);
  if (iVar2 < 0) goto LAB_00e4660e;
  if (local_44.n2.vt != 9) goto LAB_00e4660e;
  CComQIPtr<>(local_14,(undefined4 *)local_44._8_4_);
  if (local_14[0] != (int *)0x0) {
    FUN_00e03b51((uint *)&local_34);
    local_8._0_1_ = 2;
    iVar2 = (**(code **)(*local_14[0] + 0x4c))(local_14[0],&local_34);
    if ((-1 < iVar2) && (local_34.n2.vt == 9)) {
      CComQIPtr<>(&param_1,(undefined4 *)local_34._8_4_);
      if (param_1 != (int *)0x0) {
        FUN_00e03b51((uint *)&local_24);
        puVar1 = param_2;
        local_8._0_1_ = 4;
        iVar2 = (**(code **)(*param_1 + 0x30))(param_1,*param_2,&local_24);
        if (iVar2 == -0x7ff8ffa9) {
          if (param_4 != '\0') {
            iVar2 = (**(code **)(*param_1 + 0x28))(param_1,*puVar1,&local_24);
            goto LAB_00e465c3;
          }
        }
        else {
LAB_00e465c3:
          if ((-1 < iVar2) && (local_24.n2.vt == 9)) {
            (*(code *)**(undefined4 **)local_24._8_4_)(local_24._8_4_,&DAT_00efd4e4,param_3);
          }
        }
        VariantClear((VARIANTARG *)&local_24.n2);
      }
      local_8._0_1_ = 2;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
    }
    VariantClear((VARIANTARG *)&local_34.n2);
  }
  local_8._0_1_ = 0;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
LAB_00e4660e:
  VariantClear((VARIANTARG *)&local_44.n2);
  return iVar2;
}


