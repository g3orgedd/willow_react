// Source: CLCiffConversion_Layout.dll @ 4540c8d5; FUN_4540c8d5

void __thiscall FUN_4540c8d5(void *this,HDC param_1,undefined4 param_2)

{
  ushort *puVar1;
  HGDIOBJ h;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint local_38;
  int local_34;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  if ((*(int *)((int)this + 0x104) != 0) && (*(int *)this != 0)) {
    iVar4 = 0;
    local_18 = 0;
    local_38 = 0;
    if (*(int *)this != 0) {
      local_34 = 0;
      do {
        local_28 = 0;
        iVar2 = *(int *)((int)this + 0xc) + local_34;
        if (*(int *)(iVar2 + 0xc) != 0) {
          do {
            local_20 = 0;
            local_1c = (*(int *)(iVar2 + 8) + local_28) * 0x20 + *(int *)((int)this + 0x24);
            uVar5 = *(int *)((int)this + 0x34) - *(int *)((int)this + 0x30) >> 1;
            iVar4 = uVar5 - iVar4;
            local_24 = ((uint)(*(int *)(local_1c + 0xc) * 3) >> 1) + 0x10;
            if (iVar4 < local_24) {
              uVar5 = uVar5 + local_24;
              FUN_4540d52f((void *)((int)this + 0x30),uVar5);
            }
            else if (local_24 < iVar4) {
              local_24 = iVar4;
            }
            if ((uint)(*(int *)((int)this + 0x40) - *(int *)((int)this + 0x3c) >> 1) < uVar5) {
              FUN_4540d6eb((int *)((int)this + 0x3c),uVar5);
            }
            if ((uint)(*(int *)((int)this + 0x4c) - *(int *)((int)this + 0x48) >> 2) < uVar5) {
              FUN_4540d58f((int *)((int)this + 0x48),uVar5);
            }
            if ((uint)(*(int *)((int)this + 0x58) - *(int *)((int)this + 0x54) >> 2) < uVar5) {
              FUN_4540d58f((int *)((int)this + 0x54),uVar5);
            }
            if ((uint)(*(int *)((int)this + 100) - *(int *)((int)this + 0x60) >> 3) < uVar5) {
              FUN_4540d5f2((int *)((int)this + 0x60),uVar5);
            }
            iVar4 = 0;
            while( true ) {
              iVar4 = iVar4 + 1;
              if (10 < iVar4) goto LAB_4540cb74;
              puVar1 = (ushort *)(local_1c + 4);
              iVar3 = ScriptShape(param_1,param_2,*(undefined4 *)(local_1c + 8),
                                  *(undefined4 *)(local_1c + 0xc),local_24,puVar1,
                                  *(int *)((int)this + 0x30) + local_18 * 2,
                                  *(int *)((int)this + 0x90) +
                                  (*(int *)(local_1c + 8) - *(int *)((int)this + 0x100) >> 1) * 2,
                                  *(int *)((int)this + 0x3c) + local_18 * 2,&local_20);
              if (-1 < iVar3) break;
              if ((iVar3 == -0x7ff8fff2) || (iVar3 == -0x7ff8ffa9)) {
                local_24 = local_24 + *(int *)(local_1c + 0xc);
                uVar5 = local_24 + local_18;
                FUN_4540d52f((void *)((int)this + 0x30),uVar5);
                FUN_4540d6eb((void *)((int)this + 0x3c),uVar5);
                FUN_4540d58f((void *)((int)this + 0x48),uVar5);
                FUN_4540d58f((void *)((int)this + 0x54),uVar5);
                FUN_4540d5f2((void *)((int)this + 0x60),uVar5);
              }
              else {
                if (iVar3 != -0x7ffbfe00) goto LAB_4540cb74;
                if ((*puVar1 & 0x3ff) == 0) break;
                *puVar1 = *puVar1 & 0xfc00;
              }
            }
            *(int *)(local_1c + 0x14) = local_18;
            *(int *)(local_1c + 0x10) = local_20;
            if (*(char *)((int)this + 0x128) != '\0') {
              h = *(HGDIOBJ *)(local_1c + 0x1c);
              uVar5 = FUN_4540ba4b(this,(int)h);
              if ((char)uVar5 != '\0') {
                SelectObject(param_1,h);
              }
            }
            iVar4 = local_1c;
            iVar3 = ScriptPlace(param_1,param_2,*(int *)((int)this + 0x30) + local_18 * 2,local_20,
                                *(int *)((int)this + 0x3c) + local_18 * 2,local_1c + 4,
                                *(int *)((int)this + 0x48) + local_18 * 4,
                                *(int *)((int)this + 0x60) + local_18 * 8,&local_14);
            *(int *)(iVar4 + 0x18) = local_c + local_10 + local_14;
            if ((iVar3 < 0) && (iVar3 != -0x7ffbfe00)) goto LAB_4540cb74;
            iVar4 = local_18 + local_20;
            local_28 = local_28 + 1;
            local_18 = iVar4;
          } while (local_28 < *(uint *)(iVar2 + 0xc));
        }
        local_38 = local_38 + 1;
        local_34 = local_34 + 0x18;
      } while (local_38 < *(uint *)this);
    }
  }
LAB_4540cb74:
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


