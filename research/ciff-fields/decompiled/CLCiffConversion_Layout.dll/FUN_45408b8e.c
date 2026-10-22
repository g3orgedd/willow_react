// Source: CLCiffConversion_Layout.dll @ 45408b8e; FUN_45408b8e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_45408b8e(void *this,void *param_1)

{
  int iVar1;
  _union_2683 local_84;
  _union_2683 local_74;
  void *local_64;
  BSTR local_60;
  int *local_5c;
  int *local_58;
  int *local_54;
  int *local_50;
  int *local_4c;
  CLSID local_48;
  ulong local_38;
  ushort uStack_34;
  ushort uStack_32;
  uchar auStack_30 [4];
  uchar auStack_2c [4];
  BSTR local_28;
  ulong local_24;
  ushort uStack_20;
  ushort uStack_1e;
  uchar auStack_1c [4];
  uchar auStack_18 [16];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x74;
  local_8 = 0x45408b9a;
  local_64 = param_1;
  if (*(int *)((int)this + 8) != 0) {
    local_60 = (BSTR)0x0;
    local_8 = 0;
    FUN_4540876e(&local_60,0x454480e8);
    local_4c = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar1 = (**(code **)(**(int **)((int)this + 8) + 0x90))
                      (*(int **)((int)this + 8),local_60,&local_4c);
    if ((-1 < iVar1) && (local_4c != (int *)0x0)) {
      do {
        local_5c = (int *)0x0;
        local_8._0_1_ = 2;
        iVar1 = (**(code **)(*local_4c + 0x24))(local_4c,&local_5c);
        if ((iVar1 == 0) && (local_5c != (int *)0x0)) {
          local_54 = (int *)0x0;
          local_8._0_1_ = 3;
          iVar1 = (**(code **)(*local_5c + 0x44))(local_5c,&local_54);
          if ((-1 < iVar1) && (local_54 != (int *)0x0)) {
            local_58 = (int *)0x0;
            local_8._0_1_ = 4;
            iVar1 = (**(code **)(*local_54 + 0x1c))(local_54,L"CAPI",&local_58);
            if ((-1 < iVar1) && (local_58 != (int *)0x0)) {
              FUN_45429f70((uint *)&local_84,0,0x10);
              VariantInit((VARIANTARG *)&local_84.n2);
              local_8._0_1_ = 5;
              iVar1 = (**(code **)(*local_58 + 0x20))(local_58,&local_84);
              if ((-1 < iVar1) && (local_84.n2.vt == 8)) {
                local_50 = (int *)0x0;
                local_8._0_1_ = 6;
                iVar1 = (**(code **)(*local_54 + 0x1c))(local_54,L"CLSID",&local_50);
                if ((-1 < iVar1) && (local_50 != (int *)0x0)) {
                  FUN_45429f70((uint *)&local_74,0,0x10);
                  VariantInit((VARIANTARG *)&local_74.n2);
                  local_8._0_1_ = 7;
                  iVar1 = (**(code **)(*local_50 + 0x20))(local_50,&local_74);
                  if (((-1 < iVar1) && (local_74.n2.vt == 8)) &&
                     (iVar1 = CLSIDFromString((LPCOLESTR)local_74._8_4_,&local_48), -1 < iVar1)) {
                    local_38 = local_48.Data1;
                    uStack_34 = local_48.Data2;
                    uStack_32 = local_48.Data3;
                    auStack_30[0] = local_48.Data4[0];
                    auStack_30[1] = local_48.Data4[1];
                    auStack_30[2] = local_48.Data4[2];
                    auStack_30[3] = local_48.Data4[3];
                    auStack_2c[0] = local_48.Data4[4];
                    auStack_2c[1] = local_48.Data4[5];
                    auStack_2c[2] = local_48.Data4[6];
                    auStack_2c[3] = local_48.Data4[7];
                    FUN_454028ee(&local_28,(OLECHAR *)local_84._8_4_);
                    local_24 = local_38;
                    uStack_20 = uStack_34;
                    uStack_1e = uStack_32;
                    auStack_1c[0] = auStack_30[0];
                    auStack_1c[1] = auStack_30[1];
                    auStack_1c[2] = auStack_30[2];
                    auStack_1c[3] = auStack_30[3];
                    auStack_18[0] = auStack_2c[0];
                    auStack_18[1] = auStack_2c[1];
                    auStack_18[2] = auStack_2c[2];
                    auStack_18[3] = auStack_2c[3];
                    local_8._0_1_ = 8;
                    FUN_45409463(local_64,(int *)&local_28);
                    SysFreeString(local_28);
                  }
                  VariantClear((VARIANTARG *)&local_74.n2);
                }
                local_8._0_1_ = 5;
                if (local_50 != (int *)0x0) {
                  (**(code **)(*local_50 + 8))(local_50);
                }
              }
              VariantClear((VARIANTARG *)&local_84.n2);
            }
            local_8._0_1_ = 3;
            if (local_58 != (int *)0x0) {
              (**(code **)(*local_58 + 8))(local_58);
            }
          }
          local_8._0_1_ = 2;
          if (local_54 != (int *)0x0) {
            (**(code **)(*local_54 + 8))(local_54);
          }
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        if (local_5c != (int *)0x0) {
          (**(code **)(*local_5c + 8))(local_5c);
        }
      } while (iVar1 == 0);
    }
    local_8 = local_8 & 0xffffff00;
    if (local_4c != (int *)0x0) {
      (**(code **)(*local_4c + 8))(local_4c);
    }
    FUN_45408930((int *)&local_60);
  }
  FUN_4542a957();
  return;
}


