// CiffMgr.dll entry=68117f62

void __thiscall FUN_68117f62(void *this,ushort param_1)

{
  byte bVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  short *psVar7;
  ushort *puVar8;
  uint local_8;
  
  uVar5 = 0;
  if (*(int *)((int)this + 8) != 0) {
    puVar3 = (undefined2 *)((int)this + 0x836);
    do {
      uVar5 = uVar5 + 1;
      *puVar3 = puVar3[0x133];
      puVar3 = puVar3 + 1;
    } while (uVar5 < *(uint *)((int)this + 8));
  }
  uVar5 = 0;
  if (*(int *)((int)this + 0x14) != 0) {
    do {
      bVar1 = (byte)uVar5;
      iVar2 = *(int *)((int)this + 8) + uVar5;
      uVar5 = uVar5 + 1;
      *(ushort *)((int)this + iVar2 * 2 + 0x836) = param_1 >> (bVar1 & 0x1f) & 1;
    } while (uVar5 < *(uint *)((int)this + 0x14));
  }
  uVar5 = 0;
  if (*(int *)((int)this + 0x14) != 0) {
    do {
      bVar1 = (byte)uVar5;
      iVar2 = *(int *)((int)this + 0x14) + uVar5;
      uVar5 = uVar5 + 1;
      *(ushort *)((int)this + (iVar2 + *(int *)((int)this + 8)) * 2 + 0x836) =
           *(ushort *)((int)this + (uint)*(ushort *)((int)this + 0xad8) * 2 + 0x18) >>
           (bVar1 & 0x1f) & 1;
    } while (uVar5 < *(uint *)((int)this + 0x14));
  }
  local_8 = 0;
  *(short *)((int)this + 0xad8) =
       (short)((ulonglong)(*(ushort *)((int)this + 0xad8) + 1) %
              (ulonglong)(longlong)(int)(uint)*(ushort *)((int)this + 0xae0));
  if (*(int *)((int)this + 8) != 0) {
    puVar3 = (undefined2 *)((int)this + 0xa9c);
    puVar8 = (ushort *)((int)this + 0x8a8);
    do {
      uVar4 = 0;
      _param_1 = 0;
      uVar5 = 0;
      puVar6 = puVar8;
      if (*(int *)((int)this + 0xc) != 0) {
        do {
          if (*(short *)((int)this + (uint)*puVar6 * 2 + 0x836) != 0) {
            _param_1 = _param_1 | 1 << ((byte)uVar4 & 0x1f);
          }
          uVar4 = uVar4 + 1;
          uVar5 = _param_1;
          puVar6 = puVar6 + 1;
        } while (uVar4 < *(uint *)((int)this + 0xc));
      }
      puVar8 = puVar8 + 10;
      *puVar3 = *(undefined2 *)((int)this + uVar5 * 2 + 0x36);
      puVar3 = puVar3 + 1;
      local_8 = local_8 + 1;
    } while (local_8 < *(uint *)((int)this + 8));
  }
  uVar5 = 0;
  *(undefined2 *)((int)this + 0xace) = 0;
  if (*(int *)((int)this + 0x14) != 0) {
    psVar7 = (short *)((int)this + 0xa9c);
    do {
      if (*psVar7 != 0) {
        *(ushort *)((int)this + 0xace) = *(ushort *)((int)this + 0xace) | 1 << ((byte)uVar5 & 0x1f);
      }
      uVar5 = uVar5 + 1;
      psVar7 = psVar7 + 1;
    } while (uVar5 < *(uint *)((int)this + 0x14));
  }
  return;
}


