// Source: CiffMgr.dll @ 68117e37; FUN_68117e37

void __thiscall FUN_68117e37(void *this,char param_1)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  short *psVar4;
  short *psVar5;
  uint uVar6;
  ushort *puVar7;
  short *psVar8;
  uint local_14;
  short *local_c;
  short *local_8;
  
  sVar2 = 0x10;
  if (param_1 != '\0') {
    sVar2 = 0x20;
  }
  uVar6 = 0;
  sVar1 = *(short *)((int)this + 8);
  if (*(int *)((int)this + 0x10) != 0) {
    puVar7 = (ushort *)((int)this + 0x36);
    do {
      uVar3 = FUN_681180b9((int)this);
      uVar6 = uVar6 + 1;
      *puVar7 = (ushort)uVar3 & 1;
      puVar7 = puVar7 + 1;
    } while (uVar6 < *(uint *)((int)this + 0x10));
  }
  local_14 = 0;
  if (*(int *)((int)this + 8) != 0) {
    psVar4 = (short *)((int)this + 0x8a8);
    psVar8 = psVar4;
    do {
      uVar6 = 0;
      local_c = psVar8;
      local_8 = psVar4;
      if (*(int *)((int)this + 0xc) != 0) {
LAB_68117ea6:
        do {
          uVar3 = FUN_681180b9((int)this);
          *local_8 = (short)((ulonglong)(uVar3 & 0xffff) %
                            (ulonglong)(longlong)(int)(uint)(ushort)(sVar2 + sVar1));
          uVar3 = 0;
          psVar5 = psVar4;
          if (uVar6 != 0) {
            do {
              if (*psVar5 == *local_c) goto LAB_68117ea6;
              uVar3 = uVar3 + 1;
              psVar5 = psVar5 + 1;
            } while (uVar3 < uVar6);
          }
          uVar6 = uVar6 + 1;
          local_c = local_c + 1;
          local_8 = local_8 + 1;
        } while (uVar6 < *(uint *)((int)this + 0xc));
      }
      local_14 = local_14 + 1;
      psVar8 = psVar8 + 10;
      psVar4 = psVar4 + 10;
    } while (local_14 < *(uint *)((int)this + 8));
  }
  FUN_681180d7(this);
  return;
}


