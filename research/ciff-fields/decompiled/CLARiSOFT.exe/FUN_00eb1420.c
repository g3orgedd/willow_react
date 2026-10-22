// Source: CLARiSOFT.exe @ 00eb1420; FUN_00eb1420

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_00eb1420(void *this,int *param_1,int *param_2,int *param_3,BSTR param_4,BSTR param_5,
            BSTR param_6)

{
  bool bVar1;
  char cVar2;
  BSTR this_00;
  CComBSTR *pCVar3;
  int *piVar4;
  int iVar5;
  BSTR pOVar6;
  BSTR pOVar7;
  undefined **local_30;
  int *local_2c;
  BSTR local_24;
  int local_20;
  BSTR local_1c;
  undefined4 local_18;
  void *local_14;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_1c = (BSTR)0x0;
  local_8 = 3;
  local_14 = this;
  (**(code **)(*param_1 + 0x68))();
  this_00 = (BSTR)FUN_00eca369(8);
  if (this_00 == (BSTR)0x0) {
    this_00 = (BSTR)0x0;
  }
  else {
    *(undefined ***)this_00 = TCIFFField<ICiffField>::vftable;
    pOVar7 = this_00 + 2;
    pOVar7[0] = L'\0';
    pOVar7[1] = L'\0';
    FUN_00e11de5(pOVar7,(int *)&param_1);
  }
  bVar1 = FUN_00eb59a2((int)this_00);
  pOVar7 = param_6;
  if ((bVar1) || ((char)param_5 != '\0')) {
    if (*(int *)((int)this + 8) == 1) {
      pCVar3 = (CComBSTR *)FUN_00e616d4(this_00,&param_5);
      local_8._0_1_ = 4;
      piVar4 = FUN_00e4cac1(*(void **)((int)local_14 + 0xc),10);
      this = local_14;
      FUN_00eafbc7(*(void **)((int)local_14 + 0x10),pCVar3,piVar4);
      local_8 = CONCAT31(local_8._1_3_,3);
      SysFreeString(param_5);
      if (pOVar7 != (BSTR)0x0) {
        *(undefined1 *)pOVar7 = 0;
      }
    }
    (**(code **)(**(int **)(this_00 + 2) + 100))();
    if (param_5 == (BSTR)0x0) {
      pOVar6 = param_4;
      if (param_4 != (BSTR)0x0) {
        (**(code **)(*(int *)param_4 + 4))(param_4);
      }
      piVar4 = param_3;
      if (param_3 != (int *)0x0) {
        (**(code **)(*param_3 + 4))(param_3);
      }
      FUN_00eb2b4e(this,this_00,piVar4,pOVar6,(undefined1 *)pOVar7);
    }
    else if (param_5 == (BSTR)0x1) {
      FUN_00eaf837(&local_30);
      local_30 = CCIFFBarcodeField::vftable;
      local_8._0_1_ = 5;
      (**(code **)**(undefined4 **)(this_00 + 2))(*(undefined4 **)(this_00 + 2));
      (**(code **)(*local_2c + 0xa8))(local_2c,&param_5);
      if (param_5 == (BSTR)0x12) {
        local_20 = FUN_00eb59e1((int)this_00);
        param_5 = (BSTR)FUN_00eb59c2((int)this_00);
        FUN_00eae6d1(&local_18);
        param_6 = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,6);
        iVar5 = (**(code **)(*(int *)param_4 + 0x54))();
        pOVar6 = param_5;
        if ((-1 < iVar5) && (param_6 == (BSTR)0x0)) {
          piVar4 = param_3;
          if (param_3 != (int *)0x0) {
            (**(code **)(*param_3 + 4))();
          }
          pOVar6 = (BSTR)FUN_00eaeae0((int)param_5,0.0,piVar4);
        }
        piVar4 = (int *)*param_2;
        iVar5 = local_20;
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 4))(piVar4);
        }
        cVar2 = FUN_00eaebe0(piVar4,(int)pOVar6,iVar5);
        if (cVar2 == '\0') {
          pCVar3 = (CComBSTR *)FUN_00e616d4(this_00,&local_24);
          local_8 = CONCAT31(local_8._1_3_,7);
          piVar4 = FUN_00e4cac1(*(void **)((int)local_14 + 0xc),0x9a);
          FUN_00eafbc7(*(void **)((int)local_14 + 0x10),pCVar3,piVar4);
          SysFreeString(local_24);
          if (pOVar7 != (BSTR)0x0) {
            *(undefined1 *)pOVar7 = 1;
          }
        }
        local_8._0_1_ = 5;
        FUN_00eae7b2(&local_18);
      }
      pOVar6 = param_4;
      if (param_4 != (BSTR)0x0) {
        (**(code **)(*(int *)param_4 + 4))(param_4);
      }
      piVar4 = param_3;
      if (param_3 != (int *)0x0) {
        (**(code **)(*param_3 + 4))(param_3);
      }
      FUN_00eb059a(this_00,piVar4,(int *)pOVar6,(undefined1 *)pOVar7);
      local_8 = CONCAT31(local_8._1_3_,3);
      if (local_2c != (int *)0x0) {
        (**(code **)(*local_2c + 8))();
      }
    }
    else if (param_5 == (BSTR)0x2) {
      pOVar6 = param_4;
      if (param_4 != (BSTR)0x0) {
        (**(code **)(*(int *)param_4 + 4))(param_4);
      }
      piVar4 = param_3;
      if (param_3 != (int *)0x0) {
        (**(code **)(*param_3 + 4))(param_3);
      }
      FUN_00eb211e(this,this_00,piVar4,(int *)pOVar6,pOVar7);
    }
  }
  if (this_00 != (BSTR)0x0) {
    FUN_00e63686(this_00,1);
  }
  SysFreeString(local_1c);
  local_8._0_1_ = 1;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 8))();
  }
  local_8 = 0xffffffff;
  if (param_4 != (BSTR)0x0) {
    (**(code **)(*(int *)param_4 + 8))();
  }
  return 0;
}


