// Source: CLARiSOFT.exe @ 00e3e1d0; FUN_00e3e1d0

int __thiscall FUN_00e3e1d0(void *this,undefined4 param_1)

{
  int iVar1;
  BOOL BVar2;
  errno_t eVar3;
  
  if (*(int *)((int)this + 0x28) == 0) {
    *(undefined4 *)((int)this + 0x28) = param_1;
  }
  iVar1 = FUN_00e16126((void *)((int)this + 0x14),0,(void *)0x0);
  if (iVar1 == 0) {
    SetLastError(0xe);
    iVar1 = -1;
  }
  else {
    FUN_00e14961(0xf40c34,(undefined4 *)((int)this + 8),this);
    BVar2 = ChooseFontW((LPCHOOSEFONTW)((int)this + 0x24));
    *(undefined4 *)((int)this + 4) = 0;
    if (BVar2 != 0) {
      eVar3 = _memcpy_s((void *)((int)this + 0xe0),0x5c,*(void **)((int)this + 0x30),0x5c);
      FUN_00e0423b(eVar3);
    }
    iVar1 = (BVar2 == 0) + 1;
  }
  return iVar1;
}


