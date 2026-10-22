// Source: CLCiffConversion_Data.dll @ 450237b5; FUN_450237b5

PVOID __cdecl FUN_450237b5(PVOID param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  SIZE_T SVar3;
  SIZE_T SVar4;
  PVOID pvVar5;
  int iVar6;
  
  puVar1 = DecodePointer(DAT_45056f90);
  puVar2 = DecodePointer(DAT_45056f8c);
  if ((puVar2 < puVar1) || (iVar6 = (int)puVar2 - (int)puVar1, iVar6 + 4U < 4)) {
    return (PVOID)0x0;
  }
  SVar3 = FUN_4502deb0(puVar1);
  if (SVar3 < iVar6 + 4U) {
    SVar4 = 0x800;
    if (SVar3 < 0x800) {
      SVar4 = SVar3;
    }
    if ((SVar4 + SVar3 < SVar3) ||
       (pvVar5 = FUN_4502df70(puVar1,SVar4 + SVar3), pvVar5 == (void *)0x0)) {
      if (SVar3 + 0x10 < SVar3) {
        return (PVOID)0x0;
      }
      pvVar5 = FUN_4502df70(puVar1,SVar3 + 0x10);
      if (pvVar5 == (void *)0x0) {
        return (PVOID)0x0;
      }
    }
    puVar2 = (undefined4 *)((int)pvVar5 + (iVar6 >> 2) * 4);
    DAT_45056f90 = EncodePointer(pvVar5);
  }
  pvVar5 = EncodePointer(param_1);
  *puVar2 = pvVar5;
  DAT_45056f8c = EncodePointer(puVar2 + 1);
  return param_1;
}


