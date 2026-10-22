// Source: CLCSGraphicBasedField.dll @ 41c0a78d; FUN_41c0a78d

undefined4 __cdecl FUN_41c0a78d(int param_1)

{
  char cVar1;
  int iVar2;
  char cVar3;
  
  cVar3 = -1;
  iVar2 = param_1 + -0x30;
  cVar1 = (char)param_1;
  if ((ushort)iVar2 < 10) {
    cVar3 = cVar1 + -0x30;
  }
  else {
    iVar2 = param_1 + -0x41;
    if ((ushort)iVar2 < 6) {
      cVar3 = cVar1 + -0x37;
    }
    else {
      iVar2 = param_1 + -0x61;
      if ((ushort)iVar2 < 6) {
        cVar3 = cVar1 + -0x57;
      }
    }
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),cVar3);
}


