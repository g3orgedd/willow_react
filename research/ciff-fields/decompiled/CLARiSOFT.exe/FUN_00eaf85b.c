// Source: CLARiSOFT.exe @ 00eaf85b; FUN_00eaf85b

undefined4 * __fastcall FUN_00eaf85b(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 1;
  *param_1 = CCIFFErrorList::vftable;
  *piVar1 = 0;
  param_1[2] = 0;
  iVar2 = FUN_00e68516((int *)0x0,(int *)0x0);
  *piVar1 = iVar2;
  FUN_00e384b8(piVar1);
  return param_1;
}


