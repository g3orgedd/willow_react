// Source: CLCSSmallBarcode.dll @ 42034eaa; FUN_42034eaa

/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_42034eaa(void *this,int *param_1,byte *param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  UINT UVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint local_b9c;
  char local_b94 [2956];
  uint local_8;
  
  local_8 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  UVar4 = SysStringLen((BSTR)*param_1);
  uVar8 = UVar4 >> 1;
  if ((UVar4 < 2) || (bVar2 = true, (UVar4 & 1) != 0)) {
    bVar2 = false;
  }
  uVar9 = 0;
  bVar3 = bVar2;
  if (UVar4 != 0) {
    do {
      if (!bVar2) goto LAB_42035036;
      uVar5 = FUN_420351f2(*(ushort *)(*param_1 + uVar9 * 2));
      bVar3 = false;
    } while (((char)uVar5 != '\0') && (uVar9 = uVar9 + 1, bVar3 = bVar2, uVar9 < UVar4));
  }
  if (bVar3) {
    local_b94[0] = '\0';
    FUN_420698e0((uint *)((int)local_b94 + 1),0,0xb88);
    if (uVar8 < 0xb89) {
      local_b9c = 0;
      if (uVar8 != 0) {
        iVar1 = *param_1;
        do {
          iVar6 = FUN_420351c8(*(ushort *)(iVar1 + 2 + local_b9c * 4));
          iVar7 = FUN_420351c8(*(ushort *)(iVar1 + local_b9c * 4));
          local_b94[local_b9c] = (char)iVar6 + (char)iVar7 * '\x10';
          local_b9c = local_b9c + 1;
        } while (local_b9c < uVar8);
      }
      if (*(void **)((int)this + 8) != (void *)0x0) {
        FUN_42034e64(*(void **)((int)this + 8),1);
        *(undefined4 *)((int)this + 8) = 0;
      }
      uVar5 = FUN_42034b8c((undefined8 *)local_b94,uVar8,param_2,param_3);
      *(undefined4 *)((int)this + 8) = uVar5;
    }
  }
LAB_42035036:
  FUN_4206a5c8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


