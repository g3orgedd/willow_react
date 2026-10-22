// Source: CLCSSmallBarcode.dll @ 42030a6a; FUN_42030a6a

void __thiscall
FUN_42030a6a(void *this,uint param_1,undefined4 param_2,int param_3,undefined4 param_4,int *param_5)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint local_13c;
  uint local_138;
  uint *local_134;
  uint local_130;
  int local_12c;
  uint local_8;
  
  local_8 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  cVar1 = *(char *)((int)this + 0x90);
  local_13c = 0;
  local_138 = 0;
  local_134 = (uint *)(uint)(cVar1 == '\x01');
  iVar2 = FUN_42032db0((void *)((int)this + 0xe4),param_1,&local_130,&local_138,param_5);
  if (iVar2 == 0) {
    if ((local_138 == 1) && (local_12c == 0)) {
      (*(code *)(&PTR_LAB_42095254)[(int)local_134])(param_2,param_3,param_4);
      iVar2 = *(int *)((int)this + 0x8c);
    }
    else {
      if (local_138 != 0) {
        local_134 = &local_130;
        uVar3 = local_138;
        do {
          iVar2 = local_134[1] * 3;
          uVar5 = (uint)(cVar1 != '\x01');
          puVar4 = local_134;
          while (iVar2 = iVar2 + -3, -1 < iVar2) {
            iVar6 = (*puVar4 >> ((byte)iVar2 & 0x1f) & 7) * *(int *)((int)this + 0x8c);
            if (0 < iVar6) {
              (*(code *)(&PTR_LAB_42095254)[uVar5])(param_2,param_3,iVar6);
              param_3 = param_3 + iVar6;
              puVar4 = local_134;
            }
            uVar5 = uVar5 ^ 1;
            uVar3 = local_138;
          }
          local_13c = local_13c + 1;
          local_134 = puVar4 + 2;
        } while (local_13c < uVar3);
      }
      iVar2 = *(int *)((int)this + 0xc4);
    }
    *param_5 = iVar2 * *param_5;
  }
  FUN_4206a5c8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


