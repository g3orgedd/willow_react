// Source: CLCSSmallBarcode.dll @ 4200add1; FUN_4200add1

undefined4 * __fastcall FUN_4200add1(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  *param_1 = CTTFFontManager::vftable;
  FUN_4206ac4d(param_1 + 2,0xd8,0x18,&LAB_4200ae1e);
  param_1[0x512] = 0;
  iVar2 = 3;
  puVar1 = param_1 + 0x513;
  do {
    puVar1[2] = 0xffffffff;
    iVar2 = iVar2 + -1;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 3;
  } while (-1 < iVar2);
  param_1[0x51f] = 0;
  return param_1;
}


