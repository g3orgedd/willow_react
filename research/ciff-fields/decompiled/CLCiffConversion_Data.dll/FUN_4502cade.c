// Source: CLCiffConversion_Data.dll @ 4502cade; FUN_4502cade

undefined4 __cdecl FUN_4502cade(byte *param_1,byte *param_2,byte *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if (((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) ||
     (((*param_1 & 0x80) != 0 && ((*param_2 & 0x10) != 0)))) {
LAB_4502cb3e:
    uVar2 = 1;
  }
  else {
    if (iVar1 == *(int *)(param_2 + 4)) {
LAB_4502cb1d:
      if ((((*param_2 & 2) == 0) || ((*param_1 & 8) != 0)) &&
         ((((*param_3 & 1) == 0 || ((*param_1 & 1) != 0)) &&
          (((*param_3 & 2) == 0 || ((*param_1 & 2) != 0)))))) goto LAB_4502cb3e;
    }
    else {
      iVar1 = _strcmp((char *)(iVar1 + 8),(char *)(*(int *)(param_2 + 4) + 8));
      if (iVar1 == 0) goto LAB_4502cb1d;
    }
    uVar2 = 0;
  }
  return uVar2;
}


