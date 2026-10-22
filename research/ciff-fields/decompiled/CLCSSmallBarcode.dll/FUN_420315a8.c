// Source: CLCSSmallBarcode.dll @ 420315a8; FUN_420315a8

uint __thiscall FUN_420315a8(void *this,HDC param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  HANDLE pvVar5;
  int iVar6;
  HDC local_10;
  void *local_c;
  uint local_8;
  
  pvVar1 = (void *)((int)this + 0xe4);
  local_c = this;
  FUN_420330b9(pvVar1,*(int *)((int)this + 0x1b08) != 0x10,*(int *)((int)this + 0x1b0c) != 0,
               *(undefined4 *)((int)this + 200),*(undefined4 *)((int)this + 0xcc),
               *(undefined4 *)((int)this + 0xd8),*(undefined4 *)((int)this + 0xdc),
               *(undefined4 *)((int)this + 0xe0));
  local_8 = FUN_42032171(pvVar1,(undefined4 *)((int)this + 0x88));
  iVar6 = *(int *)((int)this + 0x8c);
  iVar3 = FUN_420313c2((int)pvVar1);
  iVar3 = iVar3 * iVar6;
  *(int *)((int)local_c + 0xd0) = iVar3;
  *(int *)((int)local_c + 0x6c) = iVar3;
  iVar4 = FUN_4203139d(pvVar1,*(int *)((int)local_c + 0xc0));
  pvVar1 = local_c;
  iVar4 = iVar4 * iVar6;
  *(int *)((int)local_c + 0xd4) = iVar4;
  *(int *)((int)local_c + 0x70) = iVar4;
  pvVar5 = (HANDLE)FUN_420276ca(param_1,iVar3,iVar4);
  FUN_4202743c(pvVar1,pvVar5,param_1,&local_10,*(LONG *)((int)pvVar1 + 0x6c),
               *(LONG *)((int)pvVar1 + 0x70));
  if ((pvVar5 != (HANDLE)0x0) &&
     (iVar6 = *(int *)((int)pvVar1 + 0x24) + 3,
     *(int *)((int)pvVar1 + 0x14) = (int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2, -1 < (int)local_8)) {
    if ((*(int *)((int)pvVar1 + 0x74) == 0x5a) || (*(int *)((int)pvVar1 + 0x74) == 0x10e)) {
      uVar2 = *(undefined4 *)((int)pvVar1 + 0x6c);
      *(undefined4 *)((int)pvVar1 + 0x6c) = *(undefined4 *)((int)pvVar1 + 0x70);
      *(undefined4 *)((int)pvVar1 + 0x70) = uVar2;
    }
    local_8 = FUN_42029e72(*(int *)((int)pvVar1 + 0x98),*(int *)((int)pvVar1 + 0x9c),
                           *(int *)((int)pvVar1 + 0x6c),*(int *)((int)pvVar1 + 0x70),
                           *(int *)((int)pvVar1 + 0xa4),*(int *)((int)pvVar1 + 0xa8),
                           (uint *)((int)pvVar1 + 0x80),(void *)((int)pvVar1 + 0x7c));
    if ((int)local_8 < 0) {
      FUN_420034ad(0x4209528c);
    }
    else {
      local_8 = FUN_42031722(pvVar1);
    }
    FUN_42027798(pvVar1,param_1,local_10,*(int *)((int)pvVar1 + 0x6c),*(int *)((int)pvVar1 + 0x70));
    FUN_42027631(pvVar1,pvVar5,param_1,local_10);
  }
  return local_8;
}


