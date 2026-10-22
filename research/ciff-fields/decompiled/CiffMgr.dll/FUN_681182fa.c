// Source: CiffMgr.dll @ 681182fa; FUN_681182fa

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_681182fa(void *this,int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4,
            void *param_5)

{
  int *piVar1;
  int iVar2;
  size_t sVar3;
  UINT UVar4;
  HRESULT HVar5;
  BSTR local_640;
  void *local_63c;
  BSTR local_638;
  BSTR local_634;
  BSTR local_630;
  BSTR local_62c;
  wchar_t local_628;
  uint local_626 [127];
  wchar_t local_428;
  uint local_426 [127];
  wchar_t local_228;
  uint local_226 [127];
  wchar_t local_28 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x640;
  local_8 = 0x68118309;
  piVar1 = (int *)*param_1;
  local_63c = this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
    local_634 = (BSTR)0x0;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    iVar2 = (**(code **)(*piVar1 + 0x84))(piVar1,&local_634);
    if (-1 < iVar2) {
      local_228 = L'\0';
      FUN_68132710(local_226,0,0x1fe);
      local_428 = L'\0';
      FUN_68132710(local_426,0,0x1fe);
      FUN_68134dca(local_634,(short *)0x0,0,(short *)0x0,0,&local_228,0x100,&local_428,0x100);
      iVar2 = _wcscmp(&local_428,L".new");
      if (iVar2 == 0) {
        local_628 = L'\0';
        FUN_68132710(local_626,0,0x1fe);
        _wcscpy_s(&local_628,0x100,&local_228);
        local_228 = L'\0';
        FUN_68134dca(&local_628,(short *)0x0,0,(short *)0x0,0,&local_228,0x100,&local_428,0x100);
      }
      sVar3 = _wcslen(&local_228);
      if (DAT_6814be48 < sVar3) {
        if (0x1ff < DAT_6814be48 * 2) {
                    /* WARNING: Subroutine does not return */
          ___report_rangecheckfailure();
        }
        *(undefined2 *)((int)local_226 + (DAT_6814be48 * 2 - 2)) = 0;
      }
      local_638 = (BSTR)0x0;
      FUN_6810207e(&local_638,0x6814b870);
      local_630 = (BSTR)0x0;
      local_8._0_1_ = 3;
      iVar2 = (**(code **)(*(int *)((int)local_63c + 0x10) + 8))
                        ((int *)((int)local_63c + 0x10),local_638,
                         *(undefined4 *)((int)local_63c + 0xaf4),
                         *(undefined4 *)((int)local_63c + 0xafc),0,&local_630);
      if (-1 < iVar2) {
        UVar4 = SysStringLen(local_630);
        local_28[0] = L'\0';
        local_28[1] = L'\0';
        local_28[2] = L'\0';
        local_28[3] = L'\0';
        local_28[4] = L'\0';
        local_28[5] = L'\0';
        local_28[6] = L'\0';
        local_28[7] = L'\0';
        local_28[8] = L'\0';
        iVar2 = _swprintf_s(local_28,9,L"%08x",UVar4);
        if (iVar2 == -1) {
          SysFreeString(local_630);
          FUN_6811115c((int *)&local_638);
          SysFreeString(local_634);
          local_8 = 0xffffffff;
          (**(code **)(*piVar1 + 8))(piVar1);
          goto LAB_68118614;
        }
        FUN_6810210e(&local_640,local_28);
        local_62c = (BSTR)0x0;
        local_8._0_1_ = 5;
        iVar2 = (**(code **)(*(int *)((int)local_63c + 0x10) + 8))
                          ((int *)((int)local_63c + 0x10),local_640,*param_2,
                           *(undefined4 *)((int)local_63c + 0xafc),0,&local_62c);
        if (((-1 < iVar2) && (HVar5 = FUN_6811823c(&local_62c,local_630), -1 < HVar5)) &&
           (HVar5 = FUN_6811823c(&local_62c,(BSTR)*param_4), -1 < HVar5)) {
          FUN_68118200(param_5,(int *)&local_62c);
        }
        SysFreeString(local_62c);
        SysFreeString(local_640);
      }
      SysFreeString(local_630);
      FUN_6811115c((int *)&local_638);
    }
    SysFreeString(local_634);
    local_8 = 0xffffffff;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
LAB_68118614:
  FUN_681320d7();
  return;
}


