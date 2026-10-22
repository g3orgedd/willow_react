// Source: CLCSSmallBarcode.dll @ 42032171; FUN_42032171

int __thiscall FUN_42032171(void *this,undefined4 *param_1)

{
  ushort uVar1;
  UINT UVar2;
  int iVar3;
  char cVar4;
  ushort *puVar5;
  undefined8 uVar6;
  uint local_c;
  int local_8;
  
  UVar2 = SysStringLen((BSTR)*param_1);
  puVar5 = (ushort *)*param_1;
  *(undefined4 *)((int)this + 0x28) = 0;
  if (UVar2 < 0xa97) {
    local_c = 0;
    *(undefined4 *)((int)this + 0xacc) = 0;
    if (UVar2 != 0) {
      do {
        uVar1 = *puVar5;
        if (uVar1 < 0x80) {
          *(char *)(*(int *)((int)this + 0xacc) + 0x34 + (int)this) = (char)*puVar5;
        }
        else {
          if (uVar1 < 0x100) {
            cVar4 = -0x80;
            param_1 = (undefined4 *)&DAT_420955b0;
            local_8 = 0x80;
          }
          else if (uVar1 < 0x2311) {
            param_1 = (undefined4 *)&DAT_420955ec;
            cVar4 = -0x62;
            local_8 = 0x62;
          }
          else {
            if (0x25ff < uVar1) goto LAB_42032275;
            param_1 = (undefined4 *)&DAT_42095610;
            cVar4 = -0x50;
            local_8 = 0x50;
          }
          iVar3 = 0;
          while (*(ushort *)((int)param_1 + iVar3 * 2) != uVar1) {
            iVar3 = iVar3 + 1;
            if (local_8 <= iVar3) goto LAB_42032275;
          }
          *(char *)(*(int *)((int)this + 0xacc) + 0x34 + (int)this) = cVar4 + (char)iVar3;
        }
        puVar5 = puVar5 + 1;
        local_c = local_c + 1;
        *(int *)((int)this + 0xacc) = *(int *)((int)this + 0xacc) + 1;
      } while (local_c < UVar2);
    }
    if (*(char *)((int)this + 8) == '\0') {
      iVar3 = FUN_420329e2(this);
    }
    else if ((*(int *)((int)this + 0x1c) == 0) ||
            (uVar6 = FUN_42030019((void *)((int)this + 0x20),(char *)((int)this + 0x34),
                                  (uint *)((int)this + 0xacc)), (int)uVar6 == 0)) {
      iVar3 = FUN_420323e9(this);
    }
    else {
LAB_42032275:
      iVar3 = 0x4022a;
    }
  }
  else {
    iVar3 = 0x4022a;
  }
  return iVar3;
}


