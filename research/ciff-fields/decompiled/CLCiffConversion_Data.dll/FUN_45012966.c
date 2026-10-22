// Source: CLCiffConversion_Data.dll @ 45012966; FUN_45012966

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_45012966(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  LPCWSTR pWVar3;
  int iVar4;
  VARIANTARG *pvarg;
  int *piVar5;
  _union_2683 local_2cc;
  BSTR local_2bc;
  BSTR local_2b8;
  int local_2b4;
  int local_2b0;
  int *local_2ac;
  int local_2a8;
  undefined *local_2a4;
  LPCWSTR local_2a0;
  uint local_29c;
  BSTR local_298;
  OLECHAR *local_294;
  int local_290;
  BSTR local_28c;
  uint local_288;
  int *local_284;
  int *local_280;
  BSTR local_27c;
  int *local_278;
  LPCWSTR local_274;
  LPCWSTR local_270;
  VARIANTARG local_26c [5];
  WCHAR local_21c [266];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 700;
  local_284 = (int *)0x0;
  local_8 = 0;
  FUN_45001f5d(&local_27c,L"Claricom");
  local_8._0_1_ = 1;
  iVar2 = FUN_45003ba3((int *)(*(int *)(*param_1 + 4) + 0x34 + (int)param_1),&local_27c,&local_284,
                       '\0');
  SysFreeString(local_27c);
  if ((iVar2 < 0) || (local_284 == (int *)0x0)) goto LAB_45012f43;
  local_27c = (BSTR)0x0;
  local_8._0_1_ = 2;
  iVar2 = (**(code **)(*local_284 + 0x20))(local_284,&local_27c);
  if (-1 < iVar2) {
    CComQIPtr<>(&local_280,(undefined4 *)local_27c);
    if (local_280 != (int *)0x0) {
      local_278 = (int *)0x0;
      local_8._0_1_ = 4;
      FUN_450212c4(local_26c,0x10,5,FUN_45001f8d);
      local_288 = 5;
      local_8._0_1_ = 5;
      (**(code **)(*local_280 + 0x14))(local_280);
      FUN_45002050(&local_294,"Table Containing Index Fields");
      local_8._0_1_ = 6;
      FUN_4500b491(&local_2a0,(int *)&local_294);
      local_8._0_1_ = 7;
      pWVar3 = FUN_4501ca38();
      GetPrivateProfileStringW(local_2a0,L"Table",L"",local_21c,0x104,pWVar3);
      FUN_450020a5(&local_2a8,local_21c);
      local_8._0_1_ = 8;
      pWVar3 = FUN_4501ca38();
      GetPrivateProfileStringW(local_2a0,L"IndexField",L"",local_21c,0x104,pWVar3);
      FUN_450020a5(&local_290,local_21c);
      local_8._0_1_ = 9;
      FUN_45002050(&local_2b4,"SELECT [%s] FROM [%s] WHERE [%s] = \'%s\';");
      local_8._0_1_ = 10;
      FUN_45001f5d(&local_298,local_294);
      local_2ac = (int *)0x0;
      local_8._0_1_ = 0xc;
      iVar2 = FUN_4500fc88(param_1,&local_298,&local_2ac);
      piVar5 = local_2ac;
      if ((-1 < iVar2) && (local_2ac != (int *)0x0)) {
        local_274 = (LPCWSTR)0x0;
        local_270 = (LPCWSTR)0x0;
        local_8._0_1_ = 0xe;
        (**(code **)(*local_2ac + 0x2c))(local_2ac,&local_274);
        FUN_45002365(&local_290,local_274);
        iVar2 = (**(code **)(*piVar5 + 0x24))(piVar5,&local_270);
        FUN_45002365(&local_2a8,local_270);
        SysFreeString(local_270);
        local_8._0_1_ = 0xc;
        SysFreeString(local_274);
      }
      do {
        if ((local_288 != 5) || (piVar5 = local_2ac, iVar2 < 0)) goto LAB_45012e97;
        iVar2 = (**(code **)(*local_280 + 0xc))(local_280,5,local_26c,&local_288);
        local_29c = 0;
        piVar5 = local_2ac;
        if (local_288 != 0) {
          pvarg = local_26c;
          do {
            piVar5 = local_2ac;
            if (iVar2 < 0) break;
            if (((pvarg->n1).n2.vt == 9) &&
               (puVar1 = *(undefined4 **)((int)&pvarg->n1 + 8), puVar1 != (undefined4 *)0x0)) {
              iVar2 = (**(code **)*puVar1)(puVar1,&DAT_4503d970,&local_278);
            }
            local_2b0 = 0;
            if (iVar2 < 0) {
LAB_45012e4f:
              piVar5 = local_278;
              if (local_278 != (int *)0x0) {
                local_278 = (int *)0x0;
                (**(code **)(*piVar5 + 8))(piVar5);
              }
            }
            else if (local_278 != (int *)0x0) {
              iVar2 = (**(code **)(*local_278 + 0x34))(local_278,&local_2b0);
              if ((-1 < iVar2) && (local_2b0 == 1)) {
                local_270 = (BSTR)0x0;
                local_8._0_1_ = 0xf;
                iVar2 = (**(code **)(*local_278 + 0x1c))(local_278,&local_270);
                if (-1 < iVar2) {
                  FUN_45001ef3(&local_2b8,(int *)&local_270);
                  local_8._0_1_ = 0x10;
                  FUN_4500201a(&local_274,&local_2b4);
                  local_8._0_1_ = 0x11;
                  iVar4 = FUN_450037ea(&local_274,local_274);
                  if (iVar4 != 0) {
                    iVar2 = FUN_4500b5ff((void *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc),
                                         &local_298,0);
                    local_2a4 = PTR_DAT_4505101c;
                    local_8._0_1_ = 0x12;
                    if (iVar2 < 0) {
                      iVar2 = FUN_4500f8d6((void *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc),
                                           &local_2a4);
                    }
                    else {
                      FUN_45001f5d(&local_2bc,local_274);
                      local_28c = (BSTR)0x0;
                      local_8._0_1_ = 0x14;
                      iVar2 = FUN_4500ef54((void *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc),
                                           (BSTR)&local_2bc,&local_28c);
                      if ((iVar2 < 0) || (iVar2 == 1)) {
                        iVar2 = FUN_4500f8d6((void *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc),
                                             &local_2a4);
                      }
                      else {
                        FUN_45013800(&local_28c);
                        local_2cc.n2.vt = 0;
                        FUN_4500aea9(&local_2cc,(int *)&local_28c);
                        local_8._0_1_ = 0x15;
                        iVar2 = FUN_45012f59(param_1,(int *)&local_278,(CComBSTR *)&local_270,
                                             &local_2cc);
                        VariantClear((VARIANTARG *)&local_2cc.n2);
                      }
                      SysFreeString(local_28c);
                      SysFreeString(local_2bc);
                    }
                    FUN_45002256((int *)&local_2a4);
                  }
                  FUN_45002256((int *)&local_274);
                  SysFreeString(local_2b8);
                }
                local_8._0_1_ = 0xc;
                SysFreeString(local_270);
              }
              goto LAB_45012e4f;
            }
            local_29c = local_29c + 1;
            VariantClear(pvarg);
            pvarg = pvarg + 1;
            piVar5 = local_2ac;
          } while (local_29c < local_288);
        }
      } while( true );
    }
    goto LAB_45012f1b;
  }
  goto LAB_45012f29;
LAB_45012e97:
  local_8._0_1_ = 0xb;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 8))(piVar5);
  }
  SysFreeString(local_298);
  FUN_45002256(&local_2b4);
  FUN_45002256(&local_290);
  FUN_45002256(&local_2a8);
  FUN_45002256((int *)&local_2a0);
  FUN_45002256((int *)&local_294);
  local_8._0_1_ = 4;
  _eh_vector_destructor_iterator_(local_26c,0x10,5,FUN_4500224e);
  local_8._0_1_ = 3;
  if (local_278 != (int *)0x0) {
    (**(code **)(*local_278 + 8))(local_278);
  }
LAB_45012f1b:
  local_8._0_1_ = 2;
  if (local_280 != (int *)0x0) {
    (**(code **)(*local_280 + 8))(local_280);
  }
LAB_45012f29:
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_27c != (BSTR)0x0) {
    (**(code **)(*(int *)local_27c + 8))(local_27c);
  }
LAB_45012f43:
  local_8 = 0xffffffff;
  if (local_284 != (int *)0x0) {
    (**(code **)(*local_284 + 8))(local_284);
  }
  FUN_45022eb8();
  return;
}


