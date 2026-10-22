// Source: CLARiSOFT.exe @ 00e3d825; FUN_00e3d825

int __thiscall
FUN_00e3d825(void *this,undefined4 *param_1,uint param_2,int param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  
  pcVar1 = DefWindowProcW_exref;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(code **)((int)this + 0x20) = pcVar1;
  FUN_00ecc450((uint *)((int)this + 0x24),0,0x3c);
  FUN_00ecc450((uint *)((int)this + 0xe0),0,0x5c);
  FUN_00ecc450((uint *)((int)this + 0x60),0,0x80);
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x28) = param_4;
  *(uint **)((int)this + 0x50) = (uint *)((int)this + 0x60);
  *(uint *)((int)this + 0x24) = 0x3c;
  *(uint *)((int)this + 0x38) = param_2 | 8;
  *(code **)((int)this + 0x44) = FUN_00e3e972;
  if (param_1 == (undefined4 *)0x0) {
    *(int *)((int)this + 0x30) = (int)this + 0xe0;
  }
  else {
    *(undefined4 **)((int)this + 0x30) = param_1;
    *(uint *)((int)this + 0x38) = param_2 | 0x48;
    puVar3 = (undefined4 *)((int)this + 0xe0);
    for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *param_1;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  if (param_3 != 0) {
    *(uint *)((int)this + 0x38) = *(uint *)((int)this + 0x38) | 2;
    *(int *)((int)this + 0x2c) = param_3;
  }
  return (int)this;
}


