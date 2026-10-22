// Source: CLCiffConversion_Layout.dll @ 4540678d; FUN_4540678d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 __fastcall FUN_4540678d(int param_1)

{
  int *piVar1;
  UINT UVar2;
  undefined1 uVar3;
  BSTR local_1c;
  int local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x45406799;
  local_14[0] = (int *)0x0;
  FUN_45404ce5(local_14,(int *)(param_1 + 0x6c));
  local_8 = 0;
  FUN_4541db3e(local_14,&local_1c);
  piVar1 = *(int **)(param_1 + 0x6c);
  local_18 = 0;
  uVar3 = 1;
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(*piVar1 + 0x2c))(piVar1,&local_18);
  UVar2 = SysStringLen(local_1c);
  if ((UVar2 == 0) || (local_18 < 1)) {
    uVar3 = 0;
  }
  SysFreeString(local_1c);
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return uVar3;
}


