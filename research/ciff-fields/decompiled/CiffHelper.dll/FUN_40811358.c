// Source: CiffHelper.dll @ 40811358; FUN_40811358

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_40811358(VARIANTARG *param_1,void *param_2)

{
  VARTYPE VVar1;
  longlong lVar2;
  wchar_t wVar3;
  HRESULT HVar4;
  IID *_Memory;
  OLECHAR *pOVar5;
  int iVar6;
  wchar_t *extraout_ECX;
  wchar_t *pwVar7;
  IID *pIVar8;
  IID *local_84;
  BSTR local_80;
  wchar_t *local_7c;
  IID *local_78;
  IID *local_74 [2];
  int local_6c;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_68 [24];
  wchar_t local_50 [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x80;
  local_8 = 0x40811367;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_68,"CADOConnection::VariantToBSTR");
  VVar1 = (param_1->n1).n2.vt;
  local_8 = 0;
  if (VVar1 == 2) {
    FUN_4082cef0((uint *)local_50,0,0x1e);
    iVar6 = (int)*(short *)((int)&param_1->n1 + 8);
    pwVar7 = L"%d";
LAB_408115b8:
    _swprintf_s(local_50,0x1e,pwVar7,iVar6);
LAB_408115c6:
    pOVar5 = local_50;
  }
  else {
    if (VVar1 == 3) {
      FUN_4082cef0((uint *)local_50,0,0x1e);
      iVar6 = *(int *)((int)&param_1->n1 + 8);
      pwVar7 = L"%ld";
      goto LAB_408115b8;
    }
    if (VVar1 == 5) {
      FUN_4082cef0((uint *)local_50,0,0x1e);
      _swprintf_s(local_50,0x1e,L"%.0f",(param_1->n1).n2.n3.llVal);
      goto LAB_408115c6;
    }
    if (VVar1 == 8) {
LAB_40811546:
      pOVar5 = *(OLECHAR **)((int)&param_1->n1 + 8);
    }
    else {
      if (VVar1 != 0xb) {
        if (VVar1 != 0xe) {
          if (VVar1 == 0x2011) {
            FUN_40802e40(&local_80,L"##ASCII##");
            local_8 = CONCAT31(local_8._1_3_,1);
            HVar4 = SafeArrayAccessData(*(SAFEARRAY **)((int)&param_1->n1 + 8),local_74);
            if (-1 < HVar4) {
              pIVar8 = *(IID **)(*(int *)((int)&param_1->n1 + 8) + 0x10);
              pwVar7 = extraout_ECX;
              FUN_40802e40(&stack0xffffff5c,L"C:\\CCnvert.jpg");
              FUN_40811037(local_74[0],pIVar8,pwVar7);
              lVar2 = (ulonglong)((int)pIVar8 * 2 + 1) * 2;
              local_7c = (wchar_t *)
                         FUN_4082c99b(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
              if (local_7c != (wchar_t *)0x0) {
                local_6c = 0;
                _Memory = (IID *)FUN_4082c99b((size_t)pIVar8);
                pwVar7 = local_7c;
                if (_Memory != (IID *)0x0) {
                  local_84 = (IID *)0x0;
                  local_78 = (IID *)0x0;
                  if (pIVar8 != (IID *)0x0) {
                    do {
                      wVar3 = FUN_4080f8b2((ushort)(local_74[0]->Data4
                                                    [(int)(local_78->Data4 + -0x10)] >> 4));
                      pwVar7[local_6c] = wVar3;
                      local_6c = local_6c + 1;
                      wVar3 = FUN_4080f8b2((ushort)(local_74[0]->Data4
                                                    [(int)(local_78->Data4 + -0x10)] & 0xf));
                      pwVar7[local_6c] = wVar3;
                      local_6c = local_6c + 1;
                      _Memory->Data4[(int)(local_78->Data4 + -0x10)] =
                           local_74[0]->Data4[(int)(local_78->Data4 + -0x10)];
                      local_78 = (IID *)((int)&local_78->Data1 + 1);
                      local_84 = pIVar8;
                    } while (local_78 < pIVar8);
                  }
                  pIVar8 = local_78;
                  FUN_40802e40(&stack0xffffff64,L"C:\\CCnvert2.jpg");
                  FUN_40811037(_Memory,local_84,(wchar_t *)pIVar8);
                  FID_conflict__free(_Memory);
                }
                pwVar7 = local_7c;
                local_7c[local_6c] = L'\0';
                FUN_40803f8b(&local_80,local_7c);
                FID_conflict__free(pwVar7);
              }
              SafeArrayUnaccessData(*(SAFEARRAY **)((int)&param_1->n1 + 8));
            }
            FUN_40803e5b(param_2,(int *)&local_80);
            SysFreeString(local_80);
          }
          goto LAB_408115d1;
        }
        HVar4 = VariantChangeType(param_1,param_1,0,8);
        if (HVar4 < 0) goto LAB_408115d1;
        goto LAB_40811546;
      }
      pOVar5 = L"0";
      if (*(short *)((int)&param_1->n1 + 8) != 0) {
        pOVar5 = L"1";
      }
    }
  }
  FUN_40803e97(param_2,pOVar5);
LAB_408115d1:
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_68,true,0);
  FUN_4082d4c6();
  return;
}


