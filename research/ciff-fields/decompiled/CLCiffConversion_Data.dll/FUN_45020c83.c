// Source: CLCiffConversion_Data.dll @ 45020c83; FUN_45020c83

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * FUN_45020c83(void *param_1,BSTR param_2,BSTR param_3)

{
  UINT UVar1;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_14[0] = (BSTR)0x0;
  local_8 = 2;
  UVar1 = SysStringLen(param_2);
  if (UVar1 == 0) {
    FUN_4500a3ad(local_14,0x4504176c);
  }
  else {
    FUN_4500a3ad(local_14,0x4504174c);
  }
  FUN_45001ef3(param_1,(int *)local_14);
  FUN_4500ad83((int *)local_14);
  SysFreeString(param_2);
  SysFreeString(param_3);
  return param_1;
}


