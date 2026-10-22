// Source: CiffMgr.dll @ 681122dd; FUN_681122dd

undefined4 FUN_681122dd(int *param_1,wchar_t *param_2,BSTR param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  wchar_t *pwVar1;
  BSTR pOVar2;
  BSTR pOVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  
  pOVar2 = param_3;
  pwVar1 = param_2;
  if (param_2 == (wchar_t *)0x0) {
    uVar4 = 0x80004003;
  }
  else if (param_3 == (BSTR)0x0) {
    uVar4 = 0x80004003;
  }
  else {
    iVar5 = _wcscmp(param_2,param_3);
    uVar4 = 0;
    if (iVar5 != 0) {
      SysFreeString((BSTR)0x0);
      piVar7 = param_1;
      lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x20);
      EnterCriticalSection(lpCriticalSection);
      piVar7 = piVar7 + 0x26;
      param_3 = (BSTR)FUN_68112452(piVar7,(int)pwVar1);
      if (param_3 == (BSTR)0xffffffff) {
        uVar4 = 0x80070057;
      }
      else {
        SysFreeString((BSTR)0x0);
        param_2 = pOVar2;
        uVar6 = FUN_68112452(piVar7,(int)pOVar2);
        pOVar3 = param_3;
        if (uVar6 == 0xffffffff) {
          param_3 = *(BSTR *)(param_1[0x27] + 4 + (int)param_3 * 8);
          iVar8 = (int)param_3 * 0x10;
          iVar5 = param_1[1];
          FUN_681123fe(piVar7,(uint)pOVar3);
          FUN_68112e2d(piVar7,pOVar2,(undefined8 *)&param_3,'\0','\0');
          CComQIPtr<>(&param_1,*(undefined4 **)(iVar8 + iVar5 + 8));
          if (param_1 == (int *)0x0) {
            uVar4 = 0x80004005;
          }
          else {
            uVar4 = (**(code **)(*param_1 + 0x20))(param_1,pOVar2);
          }
          param_2 = (wchar_t *)0x0;
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 8))(param_1);
          }
        }
        else {
          uVar4 = 0x80070057;
        }
        FUN_6811115c((int *)&param_2);
      }
      LeaveCriticalSection(lpCriticalSection);
      param_1 = (int *)0x0;
      FUN_6811115c((int *)&param_1);
    }
  }
  return uVar4;
}


