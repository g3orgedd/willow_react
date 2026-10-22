// Source: CLCiffConversion_Data.dll @ 450104b7; FUN_450104b7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_450104b7(void *this,BSTR param_1)

{
  UINT UVar1;
  int iVar2;
  char *pcVar3;
  undefined *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0;
  UVar1 = SysStringLen(param_1);
  if (UVar1 == 0) {
    FUN_450137d5((int)this);
    FUN_4500274d(0x4503e998);
    iVar2 = -0x7ff8ffa9;
    goto LAB_4501055a;
  }
  local_14[0] = PTR_DAT_4505101c;
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar2 = FUN_4500f8d6(this,local_14);
  if (iVar2 < 0) {
    FUN_450137d5((int)this);
    pcVar3 = "ADO Error: SQL[%ls]. Failed to retrieve errors.";
LAB_45010532:
    FUN_4500274d((int)pcVar3);
  }
  else {
    if (*(int *)(local_14[0] + -8) < 1) {
      FUN_450137d5((int)this);
      pcVar3 = "ADO Error: SQL[%ls]. Blank Errors";
      goto LAB_45010532;
    }
    FUN_450137d5((int)this);
    FUN_4500274d(0x4503e928);
  }
  FUN_45002256((int *)local_14);
LAB_4501055a:
  SysFreeString(param_1);
  return iVar2;
}


