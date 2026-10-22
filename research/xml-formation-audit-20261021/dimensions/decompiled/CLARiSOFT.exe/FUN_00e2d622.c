// Source: CLARiSOFT.exe @ 00e2d622; FUN_00e2d622

INT_PTR __thiscall FUN_00e2d622(void *this,undefined4 param_1)

{
  int iVar1;
  INT_PTR IVar2;
  
  *(uint *)((int)this + 0x28) = *(uint *)((int)this + 0x28) & 0xfffffbff;
  if (*(int *)((int)this + 0x2c) == 0) {
    *(undefined4 *)((int)this + 0x2c) = param_1;
  }
  *(undefined4 *)((int)this + 0x44) = *(undefined4 *)((int)this + 0x58);
  *(undefined4 *)((int)this + 0x3c) = *(undefined4 *)((int)this + 0x5c);
  iVar1 = FUN_00e16126((void *)((int)this + 0x14),0,(void *)0x0);
  if (iVar1 == 0) {
    SetLastError(0xe);
    IVar2 = -1;
  }
  else {
    FUN_00e14961(0xf40c34,(undefined4 *)((int)this + 8),this);
    IVar2 = PropertySheetW((LPCPROPSHEETHEADERW)((int)this + 0x24));
    *(undefined4 *)((int)this + 0x3c) = 0;
    *(undefined4 *)((int)this + 0x44) = 0;
    ATL::CSimpleArray<HINSTANCE__*,ATL::CSimpleArrayEqualHelper<HINSTANCE__*>_>::RemoveAll
              ((CSimpleArray<HINSTANCE__*,ATL::CSimpleArrayEqualHelper<HINSTANCE__*>_> *)
               ((int)this + 0x58));
  }
  return IVar2;
}


