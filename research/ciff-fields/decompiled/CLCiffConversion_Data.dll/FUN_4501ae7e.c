// Source: CLCiffConversion_Data.dll @ 4501ae7e; FUN_4501ae7e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_4501ae7e(void *this,int *param_1,int *param_2)

{
  int *piVar1;
  BSTR bstrString;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  HRESULT HVar5;
  int *piVar6;
  _union_2683 local_44;
  int *local_34;
  int local_30;
  int *local_2c;
  BSTR local_28;
  void *local_24;
  BSTR local_20;
  BSTR local_1c;
  BSTR local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x4501ae8a;
  if (param_1 == (int *)0x0) {
    uVar2 = 0x80070057;
  }
  else {
    FUN_4501bb15(param_1,&local_28);
    local_8 = 0;
    FUN_45001f8d((uint *)&local_44);
    local_8._0_1_ = 1;
    piVar3 = *(int **)(*(int *)(*(int *)((int)this + 4) + 4) + 0x60 + (int)this);
    (**(code **)(*piVar3 + 0x30))(piVar3,local_28,&local_44);
    if (local_44.n2.vt == 9) {
      local_14[0] = (int *)0x0;
      local_8._0_1_ = 2;
      (*(code *)**(undefined4 **)local_44._8_4_)(local_44._8_4_,&DAT_4503d688,local_14);
      if (local_14[0] != (int *)0x0) {
        local_30 = 0;
        local_34 = (int *)FUN_45013f7b((int *)0x0,(int *)0x0);
        local_8._0_1_ = 3;
        piVar3 = (int *)FUN_450213f3(8);
        if (piVar3 == (int *)0x0) {
          piVar3 = (int *)0x0;
        }
        else {
          *piVar3 = (int)TCIFFField<ICiffField>::vftable;
          piVar3[1] = 0;
          FUN_450022ba(piVar3 + 1,(int *)local_14);
        }
        if (piVar3 != (int *)0x0) {
          FUN_4500735e(piVar3,&local_34);
          FUN_45005a15(piVar3,1);
          if (local_30 != 0) {
            local_20 = (BSTR)0x0;
            local_8._0_1_ = 4;
            piVar3 = (int *)*local_34;
            piVar6 = local_34;
            if (piVar3 != local_34) {
              do {
                local_24 = (void *)piVar3[2];
                if (local_24 != (void *)0x0) {
                  piVar1 = *(int **)(*(int *)(*(int *)((int)this + 4) + 4) + 100 + (int)this);
                  local_2c = piVar1;
                  if (piVar1 != (int *)0x0) {
                    (**(code **)(*piVar1 + 4))(piVar1);
                  }
                  local_8._0_1_ = 5;
                  FUN_450022ba((void *)((int)this + *(int *)(*(int *)((int)this + 4) + 4) + 100),
                               (int *)local_14);
                  (**(code **)(*(int *)((int)this + *(int *)(*(int *)((int)this + 4) + 4) + 4) + 0xc
                              ))(local_24);
                  FUN_450022ba((void *)((int)this + *(int *)(*(int *)((int)this + 4) + 4) + 100),
                               (int *)&local_2c);
                  FUN_4501b79b(local_24,&local_18);
                  local_1c = (BSTR)0x0;
                  local_8 = CONCAT31(local_8._1_3_,7);
                  iVar4 = FUN_45003d41(param_1,(int *)&local_18,(int *)&local_1c);
                  if (-1 < iVar4) {
                    FUN_450022ea(&local_18,(int *)&local_1c);
                  }
                  if (((char)param_2 != '\0') &&
                     (HVar5 = FUN_4500263d(&local_20,local_18), HVar5 < 0)) {
                    /* WARNING: Subroutine does not return */
                    FUN_45002735(HVar5);
                  }
                  SysFreeString(local_1c);
                  SysFreeString(local_18);
                  local_8._0_1_ = 4;
                  piVar6 = local_34;
                  if (piVar1 != (int *)0x0) {
                    (**(code **)(*piVar1 + 8))(piVar1);
                    piVar6 = local_34;
                  }
                }
                piVar3 = (int *)*piVar3;
              } while (piVar3 != piVar6);
            }
            bstrString = local_20;
            if ((char)param_2 != '\0') {
              FUN_4500e3e3(param_1,&local_20);
              CComQIPtr<>(&param_2,(undefined4 *)*param_1);
              local_8._0_1_ = 8;
              if (param_2 != (int *)0x0) {
                FUN_45019d5f(this,(int *)&param_2);
                FUN_45019ea0((int *)&param_2);
                local_8._0_1_ = 9;
                (**(code **)(*param_2 + 0x16c))(param_2,0);
                local_2c = (int *)0x0;
                local_8._0_1_ = 10;
                (**(code **)(*param_2 + 0x7c))(param_2,0);
                SysFreeString((BSTR)0x0);
                SysFreeString((BSTR)0x0);
              }
              local_8._0_1_ = 4;
              if (param_2 != (int *)0x0) {
                (**(code **)(*param_2 + 8))(param_2);
              }
            }
            FUN_45004f8d((int *)&local_34);
            SysFreeString(bstrString);
          }
        }
        FUN_4501423d((int *)&local_34);
        FID_conflict__free(local_34);
      }
      local_8._0_1_ = 1;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
    }
    VariantClear((VARIANTARG *)&local_44.n2);
    SysFreeString(local_28);
    uVar2 = 0;
  }
  return uVar2;
}


