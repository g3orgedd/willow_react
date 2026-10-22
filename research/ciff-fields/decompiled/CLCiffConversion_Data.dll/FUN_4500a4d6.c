// Source: CLCiffConversion_Data.dll @ 4500a4d6; FUN_4500a4d6

void __cdecl FUN_4500a4d6(int param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  BSTR pOVar3;
  BSTR local_8;
  
  puVar2 = param_3;
  if (param_1 != param_2) {
    do {
      local_8 = (OLECHAR *)0x0;
      FUN_4500a3ad(&local_8,0x4503f8f8);
      pOVar3 = SysAllocString(local_8);
      **(undefined4 **)*puVar2 = pOVar3;
      piVar1 = (int *)*puVar2;
      *piVar1 = *piVar1 + 4;
      FUN_4500ad83((int *)&local_8);
      FUN_45005947(&param_1);
    } while (param_1 != param_2);
  }
  return;
}


