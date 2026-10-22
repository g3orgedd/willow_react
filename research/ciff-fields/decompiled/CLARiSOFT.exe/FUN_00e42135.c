// Source: CLARiSOFT.exe @ 00e42135; FUN_00e42135

void __thiscall FUN_00e42135(void *this,int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = MulDiv(param_1,*(int *)((int)this + 0x78),*(int *)((int)this + 0x80));
  iVar2 = MulDiv(param_2,*(int *)((int)this + 0x7c),*(int *)((int)this + 0x84));
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  FUN_00e4234d((void *)((int)this + 0x24),iVar1 + 100,iVar2 + 100,1,'\x01');
  if (*(int *)((int)this + 0x68) != 0) {
    FUN_00e36a16((void *)(*(int *)((int)this + 0x68) + 4),(undefined4 *)0x0,0,0);
  }
  return;
}


