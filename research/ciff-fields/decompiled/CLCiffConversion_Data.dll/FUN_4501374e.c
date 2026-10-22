// Source: CLCiffConversion_Data.dll @ 4501374e; FUN_4501374e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_4501374e(void *this,BSTR param_1)

{
  UINT UVar1;
  OLECHAR *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0;
  FUN_45002050(local_14,"");
  local_8 = CONCAT31(local_8._1_3_,1);
  UVar1 = SysStringLen(param_1);
  if (UVar1 != 0) {
    FUN_450037ea(local_14,L"%ls");
    if ((*local_14[0] == L'G') || (*local_14[0] == L'E')) {
      FUN_4500ecb9(local_14,0,1);
    }
  }
  FUN_45002326((void *)((int)this + 0xe4),local_14[0]);
  FUN_45002256((int *)local_14);
  SysFreeString(param_1);
  return;
}


