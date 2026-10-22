// Source: CLCiffConversion_Layout.dll @ 45405fbb; FUN_45405fbb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __cdecl FUN_45405fbb(void *param_1,int *param_2)

{
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (BSTR)0x0;
  local_8 = 0;
  FUN_45406006((int *)local_14,param_2);
  FUN_45401cab(param_1,(OLECHAR *)PTR_u_07BC1908_5C78_4028_900D_E60197D6_4545d114);
  FUN_45404d70(param_1,local_14);
  SysFreeString(local_14[0]);
  return;
}


