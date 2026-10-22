// Source: CLARiSOFT.exe @ 00e543a4; FUN_00e543a4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_00e543a4(void *this,int *param_1,char param_2)

{
  int *piVar1;
  undefined **local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0xe543b0;
  local_14 = this;
  FUN_00e54331(this);
  *(undefined ***)this = CLARiSOFTUtilsNamespace::CSStVersionInfoEncrypt::vftable;
  local_8 = 0;
  piVar1 = (int *)*param_1;
  *(int **)((int)this + 0x1ad0) = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  piVar1 = (int *)((int)this + 0x1ad4);
  local_8._0_1_ = 1;
  FUN_00e03ae7(piVar1,7);
  *(undefined4 *)((int)this + 0x1ad8) = 0;
  *(undefined4 *)((int)this + 0x1adc) = 0;
  local_8 = CONCAT31(local_8._1_3_,4);
  *(undefined4 *)((int)this + 0x1aec) = 0;
  *(undefined4 *)((int)this + 0x1af0) = 0;
  *(undefined4 *)((int)this + 0x1af4) = 0;
  if (*(int *)((int)this + 0x1ad0) == 0) {
    local_24 = _com_error::vftable;
    local_20 = 0x80004003;
    local_1c = 0;
    local_18 = 0;
                    /* WARNING: Subroutine does not return */
    FUN_00ec9dc5((int *)&local_24,&DAT_00f1c640);
  }
  *(undefined2 *)*piVar1 = 0x54;
  *(undefined2 *)(*piVar1 + 6) = 0x44;
  *(undefined2 *)(*piVar1 + 4) = 0x67;
  *(undefined2 *)(*piVar1 + 0xc) = 0x61;
  *(undefined2 *)(*piVar1 + 8) = 0x61;
  *(undefined2 *)(*piVar1 + 2) = 0x61;
  *(undefined2 *)(*piVar1 + 10) = 0x74;
  *(undefined4 *)((int)this + 0x1ae0) = 0xffffffff;
  *(undefined4 *)((int)this + 0x1ae4) = 0xffffffff;
  *(undefined4 *)((int)this + 0x1ae8) = 0xffffffff;
  if (param_2 != '\0') {
    FUN_00e54559(this);
    SysFreeString((BSTR)0x0);
  }
  return this;
}


