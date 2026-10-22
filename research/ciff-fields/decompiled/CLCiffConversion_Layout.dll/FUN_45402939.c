// Source: CLCiffConversion_Layout.dll @ 45402939; FUN_45402939

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_45402939(void *this,int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int local_1c;
  int local_18;
  wchar_t *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  uVar1 = FUN_454043b0((int *)0x0,(int *)0x0);
  *(undefined4 *)this = uVar1;
  local_8._0_1_ = 1;
  local_18 = 0;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x38))(param_1,&local_18);
    iVar2 = 0;
    if (0 < local_18) {
      do {
        local_14[0] = (wchar_t *)0x0;
        local_8._0_1_ = 2;
        (**(code **)(*param_1 + 0x30))(param_1,iVar2,local_14);
        FUN_45402ac2(&local_1c,local_14[0]);
        local_8._0_1_ = 3;
        FUN_454025d8(this,*(int **)this,&local_1c);
        FUN_45402c5d(&local_1c);
        local_8._0_1_ = 1;
        SysFreeString(local_14[0]);
        iVar2 = iVar2 + 1;
      } while (iVar2 < local_18);
    }
    if (local_18 != 0) goto LAB_454029f6;
  }
  FUN_45402a65(&local_1c,"en-GB");
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_454025d8(this,*(int **)this,&local_1c);
  FUN_45402c5d(&local_1c);
LAB_454029f6:
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return this;
}


