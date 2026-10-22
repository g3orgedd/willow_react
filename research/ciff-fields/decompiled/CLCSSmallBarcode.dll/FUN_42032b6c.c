// Source: CLCSSmallBarcode.dll @ 42032b6c; FUN_42032b6c

void __fastcall FUN_42032b6c(void *param_1)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  undefined2 *puVar4;
  uint uVar5;
  int iVar6;
  uint local_c;
  
  if (*(int *)((int)param_1 + 0x1a20) != *(int *)((int)param_1 + 0x28)) {
    FUN_42032ce5(param_1,*(int *)((int)param_1 + 0x28));
  }
  if (*(int *)((int)param_1 + 0x28) != 0) {
    uVar2 = *(uint *)((int)param_1 + 0x1214);
    if (uVar2 < *(int *)((int)param_1 + 0x28) + uVar2) {
      puVar4 = (undefined2 *)((int)param_1 + uVar2 * 2 + 0xad4);
      do {
        uVar2 = uVar2 + 1;
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      } while (uVar2 < (uint)(*(int *)((int)param_1 + 0x28) + *(int *)((int)param_1 + 0x1214)));
    }
    local_c = 0;
    if (*(int *)((int)param_1 + 0x1214) != 0) {
      puVar3 = (ushort *)((int)param_1 + 0xad4);
      do {
        uVar2 = ((uint)*(ushort *)((int)param_1 + *(int *)((int)param_1 + 0x1214) * 2 + 0xad4) +
                (uint)*puVar3) % 0x3a1;
        if (*(int *)((int)param_1 + 0x28) != 1) {
          uVar5 = 0;
          do {
            iVar6 = *(int *)((int)param_1 + 0x1214) + uVar5;
            iVar1 = FUN_42033440(uVar2,*(int *)((int)param_1 +
                                               (*(int *)((int)param_1 + 0x28) - uVar5) * 4 + 0x121c)
                                );
            uVar5 = uVar5 + 1;
            *(short *)((int)param_1 + iVar6 * 2 + 0xad4) =
                 (short)((int)(((uint)*(ushort *)((int)param_1 + iVar6 * 2 + 0xad6) - iVar1) + 0x3a1
                              ) % 0x3a1);
          } while (uVar5 < *(int *)((int)param_1 + 0x28) - 1U);
        }
        iVar1 = FUN_42033440(uVar2,*(int *)((int)param_1 + 0x1220));
        puVar3 = puVar3 + 1;
        local_c = local_c + 1;
        *(short *)((int)param_1 +
                  (*(int *)((int)param_1 + 0x28) + *(int *)((int)param_1 + 0x1214)) * 2 + 0xad2) =
             (short)((0x3a1 - iVar1) % 0x3a1);
      } while (local_c < *(uint *)((int)param_1 + 0x1214));
    }
    uVar2 = *(uint *)((int)param_1 + 0x1214);
    if (uVar2 < *(int *)((int)param_1 + 0x28) + uVar2) {
      puVar3 = (ushort *)((int)param_1 + uVar2 * 2 + 0xad4);
      do {
        uVar2 = uVar2 + 1;
        *puVar3 = (ushort)((int)(0x3a1 - (uint)*puVar3) % 0x3a1);
        puVar3 = puVar3 + 1;
      } while (uVar2 < (uint)(*(int *)((int)param_1 + 0x28) + *(int *)((int)param_1 + 0x1214)));
    }
  }
  *(int *)((int)param_1 + 0x1214) = *(int *)((int)param_1 + 0x1214) + *(int *)((int)param_1 + 0x28);
  return;
}


