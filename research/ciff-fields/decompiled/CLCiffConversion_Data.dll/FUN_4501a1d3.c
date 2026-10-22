// Source: CLCiffConversion_Data.dll @ 4501a1d3; FUN_4501a1d3

int __thiscall FUN_4501a1d3(void *this,BSTR param_1)

{
  BSTR pOVar1;
  UINT UVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *this_00;
  void *local_8;
  
  local_8 = this;
  UVar2 = SysStringLen(param_1);
  uVar3 = UVar2 & 0x80000001;
  if ((int)uVar3 < 0) {
    uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;
  }
  if (uVar3 == 0) {
    UVar2 = UVar2 - 1;
  }
  iVar5 = 0;
  iVar4 = 0;
  if (0 < (int)UVar2) {
    do {
      pOVar1 = param_1 + iVar4;
      iVar4 = iVar4 + 2;
      iVar5 = iVar5 + ((ushort)*pOVar1 - 0x30) * 3;
    } while (iVar4 < (int)UVar2);
  }
  iVar4 = 1;
  if (1 < (int)UVar2) {
    do {
      pOVar1 = param_1 + iVar4;
      iVar4 = iVar4 + 2;
      iVar5 = iVar5 + -0x30 + (uint)(ushort)*pOVar1;
    } while (iVar4 < (int)UVar2);
  }
  this_00 = (undefined4 *)((int)this + 0xc);
  iVar4 = (10 - iVar5 % 10) % 10;
  SysFreeString((BSTR)*this_00);
  *this_00 = 0;
  UVar2 = SysStringLen(param_1);
  if ((UVar2 & 1) == 0) {
    UVar2 = SysStringLen(param_1);
    uVar3 = UVar2 - 1;
  }
  else {
    uVar3 = SysStringLen(param_1);
  }
  FUN_4500254b(this_00,param_1,uVar3);
  local_8 = (void *)(uint)(ushort)((short)iVar4 + 0x30);
  FUN_45002522(this_00,(wchar_t *)&local_8);
  SysFreeString(param_1);
  return iVar4;
}


