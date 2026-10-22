// Source: CLCiffConversion_Layout.dll @ 4541ec43; FUN_4541ec43

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_4541ec43(void)

{
  int *this;
  int iVar1;
  UINT UVar2;
  HRESULT HVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 local_70 [4];
  int *local_60;
  int *local_5c;
  undefined4 local_58;
  undefined4 *local_54;
  undefined4 *local_50;
  undefined4 local_4c;
  int *local_48;
  int *local_44;
  void *local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int *local_28;
  int local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  BSTR local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x60;
  piVar6 = (int *)0x0;
  local_18 = (int *)0x0;
  local_14[0] = (BSTR)0x0;
  local_8 = 0;
  FUN_454088d1(local_70);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar1 = FUN_454089e8(local_70,local_14);
  while ((iVar1 == 0 && (UVar2 = SysStringLen(local_14[0]), UVar2 != 0))) {
    HVar3 = FUN_45408df7(local_70,(int *)local_14);
    if (-1 < HVar3) {
      local_60 = (int *)0x0;
      local_5c = (int *)0x0;
      local_58 = 0;
      local_8 = CONCAT31(local_8._1_3_,2);
      iVar1 = FUN_45408b8e(local_70,&local_60);
      piVar5 = local_60;
      if (-1 < iVar1) {
        for (; local_28 = piVar5, piVar5 != local_5c; piVar5 = piVar5 + 5) {
          local_54 = (undefined4 *)0x0;
          local_50 = (undefined4 *)0x0;
          local_4c = 0;
          local_8._0_1_ = 3;
          iVar1 = FUN_45408f32(local_70,piVar5,&local_54);
          if (-1 < iVar1) {
            FUN_45402ac2(&local_24,(wchar_t *)*piVar5);
            local_8._0_1_ = 4;
            local_18 = (int *)FUN_4541b8d6((void *)(local_3c + 0x4d0),&local_24);
            if (local_18 == (int *)0x0) {
              piVar4 = (int *)FUN_454298b4(0x18);
              local_8._0_1_ = 0xc;
              if (piVar4 == (int *)0x0) {
                local_20 = (int *)0x0;
              }
              else {
                local_48 = piVar4;
                FUN_45402ac2(&local_34,local_14[0]);
                local_8 = CONCAT31(local_8._1_3_,0xd);
                piVar6 = (int *)((uint)piVar6 | 4);
                local_18 = piVar6;
                local_20 = FUN_45412a86(piVar4,&local_24,&local_34);
              }
              piVar4 = local_20;
              local_8._0_1_ = 4;
              local_8._1_3_ = 0;
              local_48 = local_20;
              if (((uint)piVar6 & 4) != 0) {
                piVar6 = (int *)((uint)piVar6 & 0xfffffffb);
                FUN_45402c5d(&local_34);
              }
              this = local_20;
              if (piVar4 != (int *)0x0) {
                puVar7 = local_54;
                if (local_54 != local_50) {
                  do {
                    local_40 = (void *)FUN_454298b4(0x24);
                    local_8._0_1_ = 0xf;
                    if (local_40 == (void *)0x0) {
                      local_1c = (int *)0x0;
                    }
                    else {
                      FUN_45402ac2(&local_38,(wchar_t *)*puVar7);
                      local_8 = CONCAT31(local_8._1_3_,0x10);
                      local_20 = (int *)((uint)piVar6 | 8);
                      local_18 = local_20;
                      piVar6 = FUN_45415539(this,(int *)&local_44);
                      local_20 = (int *)((uint)local_20 | 0x10);
                      local_8 = 0x11;
                      local_18 = local_20;
                      piVar5 = (int *)FUN_45425d80((int)this);
                      local_1c = FUN_45412b31(local_40,&local_38,piVar6,piVar5);
                      piVar6 = local_20;
                    }
                    local_8 = 0x12;
                    if ((((uint)piVar6 & 0x10) != 0) &&
                       (piVar6 = (int *)((uint)piVar6 & 0xffffffef), local_18 = piVar6,
                       local_44 != (int *)0x0)) {
                      (**(code **)(*local_44 + 8))(local_44);
                    }
                    local_8._0_1_ = 4;
                    local_8._1_3_ = 0;
                    if (((uint)piVar6 & 8) != 0) {
                      piVar6 = (int *)((uint)piVar6 & 0xfffffff7);
                      FUN_45402c5d(&local_38);
                    }
                    FUN_45413356((int)this);
                    puVar7 = puVar7 + 1;
                    piVar5 = local_28;
                  } while (puVar7 != local_50);
                }
                FUN_4542273a((void *)(local_3c + 0x4d0),&local_48);
              }
            }
            else {
              local_20 = (int *)0x0;
              HVar3 = CoCreateInstance((IID *)&DAT_454473b8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_454494fc
                                       ,&local_20);
              if ((-1 < HVar3) && (local_20 != (int *)0x0)) {
                local_1c = (int *)0x0;
                local_8 = CONCAT31(local_8._1_3_,6);
                iVar1 = (**(code **)(*local_20 + 0x20))(local_20,local_14[0],&local_1c);
                piVar4 = local_18;
                if ((-1 < iVar1) &&
                   ((local_1c != (int *)0x0 && (puVar7 = local_54, local_54 != local_50)))) {
                  do {
                    iVar1 = FUN_4541b7e2(piVar4,puVar7);
                    if (iVar1 == 0) {
                      local_40 = (void *)FUN_454298b4(0x24);
                      local_8._0_1_ = 7;
                      if (local_40 == (void *)0x0) {
                        local_18 = (int *)0x0;
                      }
                      else {
                        FUN_45402ac2(&local_30,local_14[0]);
                        local_18 = (int *)((uint)piVar6 | 1);
                        local_8 = CONCAT31(local_8._1_3_,8);
                        FUN_45402ac2(&local_2c,(wchar_t *)*puVar7);
                        local_8._0_1_ = 9;
                        local_8._1_3_ = 0;
                        piVar6 = (int *)((uint)piVar6 | 3);
                        local_18 = piVar6;
                        local_18 = FUN_45412b31(local_40,&local_2c,(int *)&local_1c,&local_30);
                      }
                      if (((uint)piVar6 & 2) != 0) {
                        piVar6 = (int *)((uint)piVar6 & 0xfffffffd);
                        FUN_45402c5d(&local_2c);
                      }
                      local_8 = 6;
                      if (((uint)piVar6 & 1) != 0) {
                        piVar6 = (int *)((uint)piVar6 & 0xfffffffe);
                        FUN_45402c5d(&local_30);
                      }
                      FUN_45413356((int)piVar4);
                    }
                    puVar7 = puVar7 + 1;
                    piVar5 = local_28;
                  } while (puVar7 != local_50);
                }
                local_8._0_1_ = 5;
                if (local_1c != (int *)0x0) {
                  (**(code **)(*local_1c + 8))(local_1c);
                }
              }
              local_8._0_1_ = 4;
              if (local_20 != (int *)0x0) {
                (**(code **)(*local_20 + 8))(local_20);
              }
            }
            FUN_45402c5d(&local_24);
          }
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_4542244e((int *)&local_54);
        }
      }
      FUN_45409246((int)local_70);
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_45422419((int *)&local_60);
    }
    iVar1 = FUN_45408aca(local_70,local_14);
  }
  local_8 = local_8 & 0xffffff00;
  FUN_4540890a(local_70);
  SysFreeString(local_14[0]);
  return iVar1;
}


