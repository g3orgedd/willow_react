// Source: CLCSSmallBarcode.dll @ 42030bef; FUN_42030bef

void __thiscall
FUN_42030bef(void *this,uint param_1,undefined4 param_2,int param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint local_14c;
  int local_148;
  uint local_144;
  uint local_140;
  undefined4 local_13c;
  int local_138;
  uint *local_134;
  undefined4 local_130;
  uint local_12c [73];
  uint local_8;
  
  local_8 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  local_13c = param_2;
  local_140 = (uint)(*(char *)((int)this + 0x90) == '\x01');
  local_144 = (uint)(*(char *)((int)this + 0x90) != '\x01');
  iVar1 = FUN_42032db0((void *)((int)this + 0xe4),param_1,&local_130,&local_14c,param_5);
  if (iVar1 == 0) {
    if ((local_14c == 1) && (local_12c[0] == 0)) {
      (*(code *)(&PTR_LAB_42095254)[local_140])(local_13c,param_3,param_4);
      iVar1 = *(int *)((int)this + 0x8c);
    }
    else {
      local_138 = local_14c - 1;
      if (-1 < local_138) {
        puVar2 = local_12c + local_138 * 2;
        uVar3 = local_144;
        do {
          uVar4 = local_140;
          if ((*puVar2 & 1) != 0) {
            uVar4 = uVar3;
          }
          local_148 = 0;
          local_134 = puVar2;
          if (0 < (int)(*puVar2 * 3)) {
            do {
              iVar1 = (puVar2[-1] >> ((byte)local_148 & 0x1f) & 7) * *(int *)((int)this + 0x8c);
              if (0 < iVar1) {
                (*(code *)(&PTR_LAB_42095254)[uVar4])(local_13c,param_3,iVar1);
                param_3 = param_3 + iVar1;
                puVar2 = local_134;
              }
              local_148 = local_148 + 3;
              uVar4 = uVar4 ^ 1;
              uVar3 = local_144;
            } while (local_148 < (int)(*puVar2 * 3));
          }
          local_138 = local_138 + -1;
          puVar2 = puVar2 + -2;
          local_134 = puVar2;
        } while (-1 < local_138);
      }
      iVar1 = *(int *)((int)this + 0xc4);
    }
    *param_5 = iVar1 * *param_5;
  }
  FUN_4206a5c8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


