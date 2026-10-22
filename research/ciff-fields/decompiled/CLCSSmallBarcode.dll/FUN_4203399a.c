// Source: CLCSSmallBarcode.dll @ 4203399a; FUN_4203399a

undefined4 __thiscall
FUN_4203399a(void *this,int param_1,int param_2,undefined4 param_3,int param_4)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_c;
  uint local_8;
  
  uVar2 = 0x80004005;
  if (*(int *)((int)this + 0xf0) != 0) {
    local_8 = (uint)(*(char *)((int)this + 0xd0) == '\x01');
    iVar4 = 0;
    if (*(char *)((int)this + 0xdc) == '\x01') {
      iVar4 = 4;
    }
    local_c = 0;
    iVar3 = (param_4 + 1) * *(int *)((int)this + 0xe0);
    iVar5 = param_2;
    if (0 < *(int *)((int)this + 0xe0)) {
      do {
        iVar3 = iVar3 + -1;
        bVar1 = FUN_420351a2(*(void **)((int)this + 0xf0),iVar3);
        if ((bVar1 & 1) == *(byte *)((int)this + 0xd0)) {
          if ((local_8 == 1) && (iVar4 != 0)) {
            iVar6 = *(int *)((int)this + 0x90) * iVar4;
            iVar5 = FUN_4202c062(this,iVar6);
            (*(code *)PTR_FUN_4209b334)(param_1,param_2,iVar6 - iVar5);
            iVar5 = param_2 + *(int *)((int)this + 0x90) * iVar4;
            iVar4 = 0;
            param_2 = iVar5;
          }
          local_8 = 0;
        }
        else {
          if ((local_8 == 0) && (iVar4 != 0)) {
            iVar5 = iVar5 + *(int *)((int)this + 0x90) * iVar4;
            iVar4 = 0;
            param_2 = iVar5;
          }
          local_8 = 1;
        }
        iVar4 = iVar4 + 1;
        local_c = local_c + 1;
      } while (local_c < *(int *)((int)this + 0xe0));
    }
    if (0 < iVar4) {
      iVar3 = *(int *)((int)this + 0x90) * iVar4;
      iVar5 = FUN_4202c062(this,iVar3);
      (**(code **)(&DAT_4209b330 + local_8 * 4))(param_1,param_2,iVar3 - iVar5);
      param_2 = param_2 + *(int *)((int)this + 0x90) * iVar4;
    }
    if (*(char *)((int)this + 0xdc) == '\x01') {
      (**(code **)(&DAT_4209b330 + (uint)(*(char *)((int)this + 0xd0) == '\x01') * 4))
                (param_1,param_2,*(int *)((int)this + 0x90) << 2);
    }
    uVar2 = 0;
  }
  return uVar2;
}


