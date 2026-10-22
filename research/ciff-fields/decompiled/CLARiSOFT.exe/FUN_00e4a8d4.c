// Source: CLARiSOFT.exe @ 00e4a8d4; FUN_00e4a8d4

uint __thiscall
FUN_00e4a8d4(void *this,char param_1,int param_2,int param_3,DWORD param_4,int param_5,int param_6,
            int param_7,char param_8,wchar_t *param_9)

{
  DWORD DVar1;
  uint in_EAX;
  wchar_t *pwVar2;
  undefined4 uVar3;
  HANDLE hObject;
  BOOL BVar4;
  
  DVar1 = param_4;
  if (param_4 != 0) {
    FUN_00ecc450((uint *)((int)this + 0xc),0,0x14);
    *(int *)((int)this + 0x10) = param_5;
    *(int *)((int)this + 0x28) = param_6;
    *(uint *)((int)this + 0xc) = 0x14;
    *(DWORD *)((int)this + 4) = DVar1;
    *(int *)((int)this + 0x2c) = param_7;
    if (*(int *)this != 0) {
      *(undefined4 *)this = 0;
    }
    *(int *)this = param_2;
    *(int *)((int)this + 8) = param_3;
    *(undefined1 *)((int)this + 0x25) = 0;
    if (param_8 != '\0') {
      pwVar2 = L"FILE:";
      if (param_9 != (wchar_t *)0x0) {
        pwVar2 = param_9;
      }
      *(wchar_t **)((int)this + 0x14) = pwVar2;
    }
    if (param_1 == '\0') {
      *(undefined1 *)((int)this + 0x25) = 1;
      uVar3 = FUN_00e4a7de(this);
      return uVar3;
    }
    param_4 = 0;
    hObject = FUN_00ece914((LPSECURITY_ATTRIBUTES)0x0,0,0xe4a981,this,0,&param_4);
    in_EAX = 0;
    if (hObject != (HANDLE)0x0) {
      BVar4 = CloseHandle(hObject);
      return CONCAT31((int3)((uint)BVar4 >> 8),1);
    }
  }
  return in_EAX & 0xffffff00;
}


