// Source: CLARiSOFT.exe @ 00e2a558; FUN_00e2a558

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __cdecl FUN_00e2a558(undefined4 *param_1)

{
  ULONG UVar1;
  uint uVar2;
  IID *riid;
  int iVar3;
  VARIANTARG local_70;
  VARIANTARG local_60;
  VARIANTARG local_50;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int *local_20;
  IUnknown *local_1c;
  IUnknown *local_18;
  IUnknown *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x60;
  local_8 = 0xe2a564;
  local_38 = FUN_00e1f88d(&DAT_00f40de8);
  local_30 = FUN_00e1f80b(&DAT_00f40de8);
  local_2c = 0;
  UVar1 = (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,&local_2c);
  iVar3 = 0;
  if (0 < local_2c) {
    do {
      local_18 = (IUnknown *)0x0;
      local_8 = 0;
      FUN_00e03b51((uint *)&local_70);
      iVar3 = iVar3 + 1;
      local_8 = CONCAT31(local_8._1_3_,1);
      local_40 = iVar3;
      (**(code **)(*(int *)*param_1 + 0x24))((int *)*param_1,iVar3,&local_70);
      if (local_18 != (IUnknown *)local_70.n1._8_4_) {
        ATL::AtlComQIPtrAssign(&local_18,(IUnknown *)local_70.n1._8_4_,(_GUID *)&DAT_00efcfe8);
      }
      local_28 = 0;
      (*local_18->lpVtbl[2].AddRef)(local_18);
      riid = (IID *)0x0;
      if (0 < local_28) {
        do {
          iVar3 = 0;
          local_14[0] = (IUnknown *)0x0;
          FUN_00e03b51((uint *)&local_60);
          riid = (IID *)((int)&riid->Data1 + 1);
          local_8._0_1_ = 3;
          (*local_18->lpVtbl[3].QueryInterface)(local_18,riid,(void **)&local_60);
          if (local_14[0] != (IUnknown *)local_60.n1._8_4_) {
            ATL::AtlComQIPtrAssign(local_14,(IUnknown *)local_60.n1._8_4_,(_GUID *)&DAT_00efd008);
          }
          if ((local_30 == 0) && ((*local_14[0]->lpVtbl[8].AddRef)(local_14[0]), local_34 == 1)) {
LAB_00e2a768:
            VariantClear(&local_60);
            local_8 = CONCAT31(local_8._1_3_,1);
            if (local_14[0] != (IUnknown *)0x0) {
              (*local_14[0]->lpVtbl->Release)(local_14[0]);
            }
            VariantClear(&local_70);
            local_8 = 0xffffffff;
            uVar2 = 0;
            if (local_18 != (IUnknown *)0x0) {
              uVar2 = (*local_18->lpVtbl->Release)(local_18);
            }
            return uVar2 & 0xffffff00;
          }
          local_20 = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,4);
          (*local_14[0]->lpVtbl[7].Release)(local_14[0]);
          local_24 = 0;
          (**(code **)(*local_20 + 0x1c))(local_20,&local_24);
          if (0 < local_24) {
            do {
              local_1c = (IUnknown *)0x0;
              FUN_00e03b51((uint *)&local_50);
              iVar3 = iVar3 + 1;
              local_8 = CONCAT31(local_8._1_3_,6);
              (**(code **)(*local_20 + 0x24))(local_20,iVar3,&local_50);
              if (local_1c != (IUnknown *)local_50.n1._8_4_) {
                ATL::AtlComQIPtrAssign
                          (&local_1c,(IUnknown *)local_50.n1._8_4_,(_GUID *)&DAT_00efd144);
              }
              if ((local_38 == 0) && ((*local_1c->lpVtbl[3].AddRef)(local_1c), local_3c == 2)) {
                VariantClear(&local_50);
                local_8._0_1_ = 4;
                if (local_1c != (IUnknown *)0x0) {
                  (*local_1c->lpVtbl->Release)(local_1c);
                }
                local_8._0_1_ = 3;
                if (local_20 != (int *)0x0) {
                  (**(code **)(*local_20 + 8))(local_20);
                }
                goto LAB_00e2a768;
              }
              VariantClear(&local_50);
              local_8 = CONCAT31(local_8._1_3_,4);
              if (local_1c != (IUnknown *)0x0) {
                (*local_1c->lpVtbl->Release)(local_1c);
              }
            } while (iVar3 < local_24);
          }
          local_8._0_1_ = 3;
          if (local_20 != (int *)0x0) {
            (**(code **)(*local_20 + 8))(local_20);
          }
          VariantClear(&local_60);
          local_8 = CONCAT31(local_8._1_3_,1);
          if (local_14[0] != (IUnknown *)0x0) {
            (*local_14[0]->lpVtbl->Release)(local_14[0]);
          }
          iVar3 = local_40;
        } while ((int)riid < local_28);
      }
      VariantClear(&local_70);
      local_8 = 0xffffffff;
      UVar1 = 0;
      if (local_18 != (IUnknown *)0x0) {
        UVar1 = (*local_18->lpVtbl->Release)(local_18);
      }
    } while (iVar3 < local_2c);
  }
  return CONCAT31((int3)(UVar1 >> 8),1);
}


