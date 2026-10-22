// Source: CLARiSOFT.exe @ 00eb211e; FUN_00eb211e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_00eb211e(void *this,BSTR param_1,int *param_2,int *param_3,BSTR param_4)

{
  bool bVar1;
  char cVar2;
  undefined1 *this_00;
  int iVar3;
  CComBSTR *pCVar4;
  undefined4 uVar5;
  BSTR pOVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  BSTR local_2c;
  undefined4 local_28;
  int local_24;
  int *local_20;
  void *local_1c;
  BSTR local_18;
  char local_11;
  int local_8;
  undefined4 uStack_4;
  
  pOVar6 = param_1;
  uStack_4 = 0x24;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_1c = this;
  if ((param_1 == (BSTR)0x0) || (param_2 == (int *)0x0)) goto LAB_00eb245c;
  this_00 = (undefined1 *)FUN_00eca369(8);
  if (this_00 == (undefined1 *)0x0) {
    this_00 = (undefined1 *)0x0;
  }
  else {
    *(undefined4 *)(this_00 + 4) = 0;
    FUN_00e11de5(this_00 + 4,(int *)&param_2);
    *this_00 = 1;
  }
  local_8._0_1_ = 2;
  iVar3 = FUN_00eb5fa6((int)pOVar6);
  if (iVar3 == 1) {
    bVar1 = FUN_00eb6ec6((int)this_00);
    if (bVar1) {
      uVar5 = FUN_00eb5a00((int)pOVar6);
      cVar2 = FUN_00eb6e75(this_00,uVar5);
      if (cVar2 == '\0') {
        pCVar4 = (CComBSTR *)FUN_00e616d4(pOVar6,&local_2c);
        local_8._0_1_ = 4;
        piVar8 = FUN_00e4cac1(*(void **)((int)this + 0xc),0x52);
        FUN_00eafbc7(*(void **)((int)this + 0x10),pCVar4,piVar8);
        local_8._0_1_ = 2;
        SysFreeString(local_2c);
        if (param_4 == (BSTR)0x0) {
          if (param_3 != (int *)0x0) {
            FUN_00e0e8d9(&local_20);
            local_8._0_1_ = 5;
            bVar1 = FUN_00e10298((int *)&param_3,(int *)&param_2);
            if (bVar1) {
              pCVar4 = (CComBSTR *)FUN_00e616d4(param_1,&local_2c);
              local_8._0_1_ = 6;
              piVar8 = FUN_00e4cac1(*(void **)((int)this + 0xc),0x96);
              FUN_00eafbc7(*(void **)((int)this + 0x10),pCVar4,piVar8);
              SysFreeString(local_2c);
            }
            local_8._0_1_ = 2;
            FUN_00e0e9b5(&local_20);
          }
        }
        else {
          *(undefined1 *)param_4 = 0;
        }
      }
      piVar8 = (int *)0x0;
      local_20 = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,7);
      piVar7 = param_2;
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 4))(param_2);
      }
      pOVar6 = (BSTR)FUN_00eb5f25(piVar7);
      local_2c = pOVar6;
      if (pOVar6 != (BSTR)0x0) {
        (**(code **)(*(int *)pOVar6 + 4))(pOVar6);
      }
      local_8._0_1_ = 8;
      if (((pOVar6 != (BSTR)0x0) &&
          (iVar3 = FUN_00e2f762((int *)&local_2c,(undefined4 *)((int)local_1c + 0x20),&local_20),
          piVar8 = local_20, -1 < iVar3)) && (local_20 != (int *)0x0)) {
        local_18 = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,9);
        iVar3 = (**(code **)(*local_20 + 0x44))(local_20,&local_18);
        if (iVar3 < 0) {
LAB_00eb22f0:
          local_11 = '\0';
        }
        else {
          bVar1 = FUN_00e03edc(&local_18,L"Line");
          local_11 = '\x01';
          if (!bVar1) goto LAB_00eb22f0;
        }
        local_8._0_1_ = 8;
        SysFreeString(local_18);
        if ((local_11 != '\0') && (iVar3 = FUN_00eb6560((int)this_00), iVar3 == 0)) {
          local_18 = (BSTR)FUN_00eb59c2((int)param_1);
          local_24 = 0;
          piVar7 = &local_24;
          piVar10 = param_3;
          iVar3 = (**(code **)(*param_3 + 0x54))();
          FUN_00eae6d1(&local_28);
          local_8._0_1_ = 10;
          pOVar6 = local_18;
          if ((-1 < iVar3) && (local_24 == 0)) {
            piVar9 = param_2;
            if (param_2 != (int *)0x0) {
              (**(code **)(*param_2 + 4))(param_2);
            }
            pOVar6 = (BSTR)FUN_00eaeae0((int)local_18,0.0,piVar9);
          }
          (**(code **)(*piVar8 + 4))(piVar8,piVar8,pOVar6);
          bVar1 = FUN_00eaed3b(piVar10,piVar7);
          if (!bVar1) {
            if (param_4 != (BSTR)0x0) {
              *(undefined1 *)param_4 = 0;
            }
            pCVar4 = (CComBSTR *)FUN_00e616d4(param_1,&param_4);
            local_8._0_1_ = 0xb;
            piVar7 = FUN_00e4cac1(*(void **)((int)local_1c + 0xc),0x9b);
            FUN_00eafbc7(*(void **)((int)local_1c + 0x10),pCVar4,piVar7);
            SysFreeString(param_4);
          }
          local_8._0_1_ = 8;
          FUN_00eae7b2(&local_28);
          pOVar6 = local_2c;
        }
      }
      local_8._0_1_ = 7;
      if (pOVar6 != (BSTR)0x0) {
        (**(code **)(*(int *)pOVar6 + 8))(pOVar6);
      }
      local_8._0_1_ = 2;
      if (piVar8 != (int *)0x0) {
        (**(code **)(*piVar8 + 8))(piVar8);
      }
    }
    else {
      pCVar4 = (CComBSTR *)FUN_00e616d4(pOVar6,&param_1);
      local_8._0_1_ = 3;
      iVar3 = 6;
LAB_00eb2427:
      piVar8 = FUN_00e4cac1(*(void **)((int)this + 0xc),iVar3);
      FUN_00eafbc7(*(void **)((int)this + 0x10),pCVar4,piVar8);
      SysFreeString(param_1);
      if (param_4 != (BSTR)0x0) {
        *(undefined1 *)param_4 = 0;
      }
    }
  }
  else if (iVar3 == 0) {
    iVar3 = FUN_00eb679a((int)pOVar6);
    bVar1 = FUN_00eb7449(this_00,iVar3);
    if (!bVar1) {
      pCVar4 = (CComBSTR *)FUN_00e616d4(pOVar6,&param_1);
      local_8._0_1_ = 0xc;
      iVar3 = 0x90;
      goto LAB_00eb2427;
    }
  }
  if (this_00 != (undefined1 *)0x0) {
    FUN_00e63686(this_00,1);
  }
LAB_00eb245c:
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  local_8 = 0xffffffff;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 8))(param_3);
  }
  return 0;
}


