// Source: CLCiffConversion_Data.dll @ 450106d9; FUN_450106d9

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_450106d9(int *param_1,int param_2,int param_3,int *param_4)

{
  uint _SizeInWords;
  UINT UVar1;
  uint uVar2;
  undefined4 ***pppuVar3;
  BSTR **pppOVar4;
  undefined4 ***pppuVar5;
  wchar_t *pwVar6;
  BSTR **pppOVar7;
  wchar_t *local_64;
  undefined4 local_60;
  undefined4 **local_5c [5];
  uint local_48;
  undefined4 **local_44 [5];
  uint local_30;
  BSTR *local_2c [5];
  uint local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  local_8._0_1_ = 0xe5;
  local_8._1_3_ = 0x450106;
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) goto LAB_4501083f;
  _SizeInWords = param_3 + 1;
  FUN_4500a7d8(&local_64,_SizeInWords);
  local_8 = 0;
  UVar1 = SysStringLen((BSTR)*param_4);
  local_60 = 0x20;
  (**(code **)(*(int *)*param_1 + 0xa4))((int *)*param_1,&local_60);
  basic_string<>(local_2c,param_3 - UVar1,(wchar_t)local_60);
  local_8._0_1_ = 1;
  pwVar6 = local_64;
  if (param_2 == 0) {
    pppOVar4 = local_2c;
    if (7 < local_18) {
      pppOVar4 = (BSTR **)local_2c[0];
    }
    pppOVar7 = (BSTR **)*param_4;
LAB_4501080e:
    _swprintf_s(local_64,_SizeInWords,L"%s%s",pppOVar7,pppOVar4);
  }
  else {
    pppOVar4 = (BSTR **)*param_4;
    if (param_2 == 1) {
      pppOVar7 = local_2c;
      if (7 < local_18) {
        pppOVar7 = (BSTR **)local_2c[0];
      }
      goto LAB_4501080e;
    }
    if (param_2 == 2) {
      UVar1 = SysStringLen((BSTR)pppOVar4);
      uVar2 = (int)(param_3 - UVar1) / 2;
      basic_string<>(local_44,uVar2,(wchar_t)local_60);
      local_8._0_1_ = 2;
      basic_string<>(local_5c,((param_3 - UVar1) - uVar2) - 1,(wchar_t)local_60);
      pppuVar5 = local_5c;
      if (7 < local_48) {
        pppuVar5 = (undefined4 ***)local_5c[0];
      }
      pppuVar3 = local_44;
      if (7 < local_30) {
        pppuVar3 = (undefined4 ***)local_44[0];
      }
      _swprintf_s(local_64,_SizeInWords,L"%s%s%s",pppuVar3,*param_4,pppuVar5);
      FUN_450046d9(local_5c,'\x01',0);
      local_8._0_1_ = 1;
      FUN_450046d9(local_44,'\x01',0);
      pwVar6 = local_64;
    }
    else {
      _swprintf_s(local_64,_SizeInWords,L"%s");
    }
  }
  FUN_45002326(param_4,pwVar6);
  FUN_450046d9(local_2c,'\x01',0);
  if (pwVar6 != (OLECHAR *)0x0) {
    FID_conflict__free(pwVar6);
  }
LAB_4501083f:
  FUN_45022eb8();
  return;
}


