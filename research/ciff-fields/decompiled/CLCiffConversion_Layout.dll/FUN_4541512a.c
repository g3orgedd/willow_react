// Source: CLCiffConversion_Layout.dll @ 4541512a; Catch_All@4541512a

undefined4 Catch_All_4541512a(void)

{
  OLECHAR *bstrString;
  HRESULT HVar1;
  size_t sVar2;
  int iVar3;
  LPCSTR pCVar4;
  int *piVar5;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int unaff_EBP;
  void **ppvVar6;
  
  HVar1 = CoInitialize((LPVOID)0x0);
  *(HRESULT *)(unaff_EBP + -0x1074) = HVar1;
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  GetLocalTime((LPSYSTEMTIME)(unaff_EBP + -0x1044));
  _sprintf_s((char *)(unaff_EBP + -0x34),0x1e,"%02d/%02d/%4d at %02d:%02d:%02d - ",
             (uint)*(ushort *)(unaff_EBP + -0x103e),(uint)*(ushort *)(unaff_EBP + -0x1042));
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
             (unaff_EBP + -0x105c),(char *)(unaff_EBP + -0x34));
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  sVar2 = _strlen("ATLTRACELOG (...) Error");
  FUN_45404764((void *)(unaff_EBP + -0x105c),"ATLTRACELOG (...) Error",sVar2);
  FUN_454028ee((void *)(unaff_EBP + -0x1068),L"C://TraceErrorLog.log");
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FUN_454027ae((void *)(unaff_EBP + -0x1060),(IID *)&DAT_45447724,(LPUNKNOWN)0x0,0x17);
  bstrString = *(OLECHAR **)(unaff_EBP + -0x1068);
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  piVar5 = (int *)0x0;
  if (*(int *)(unaff_EBP + -0x1060) == 0) {
LAB_4541531c:
    *(undefined1 *)(unaff_EBP + -4) = 0xe;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 8))();
    }
    SysFreeString(bstrString);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
               (unaff_EBP + -0x105c),true,0);
    if (-1 < HVar1) {
      CoUninitialize();
    }
    return 0x45414ee6;
  }
  *(undefined1 **)(unaff_EBP + -0x1070) = &stack0xfffffffc;
  piVar5 = extraout_ECX;
  FUN_45402bbb(&stack0xfffffffc,bstrString);
  *(undefined1 *)(unaff_EBP + -4) = 0x10;
  if (*(void **)(unaff_EBP + -0x1060) != (void *)0x0) {
    *(undefined1 *)(unaff_EBP + -4) = 0xf;
    iVar3 = FUN_4540377d(*(void **)(unaff_EBP + -0x1060),piVar5);
    piVar5 = extraout_ECX_00;
    if ((short)iVar3 == 0) {
      ppvVar6 = (void **)0xffffffff;
      *(undefined1 **)(unaff_EBP + -0x1070) = &stack0xfffffff4;
      FUN_45402bbb(&stack0xfffffff4,bstrString);
      *(undefined1 *)(unaff_EBP + -4) = 0x11;
      if (*(void **)(unaff_EBP + -0x1060) == (void *)0x0) goto LAB_45414fef;
      *(undefined1 *)(unaff_EBP + -4) = 0xf;
      FUN_4540371c(*(void **)(unaff_EBP + -0x1060),(undefined4 *)(unaff_EBP + -0x106c),piVar5,
                   ppvVar6);
      piVar5 = extraout_ECX_01;
      if (*(int **)(unaff_EBP + -0x106c) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_EBP + -0x106c) + 8))();
        piVar5 = extraout_ECX_02;
      }
    }
    *(undefined1 **)(unaff_EBP + -0x1070) = &stack0xfffffff0;
    FUN_45402bbb(&stack0xfffffff0,bstrString);
    *(undefined1 *)(unaff_EBP + -4) = 0x12;
    if (*(void **)(unaff_EBP + -0x1060) != (void *)0x0) {
      *(undefined1 *)(unaff_EBP + -4) = 0xf;
      FUN_45403f64(*(void **)(unaff_EBP + -0x1060),(undefined4 *)(unaff_EBP + -0x1064),piVar5);
      *(undefined1 *)(unaff_EBP + -4) = 0x13;
      piVar5 = (int *)0x0;
      if (*(int *)(unaff_EBP + -0x1064) != 0) {
        pCVar4 = (LPCSTR)(unaff_EBP + -0x105c);
        if (0xf < *(uint *)(unaff_EBP + -0x1048)) {
          pCVar4 = *(LPCSTR *)(unaff_EBP + -0x105c);
        }
        *(undefined1 **)(unaff_EBP + -0x1070) = &stack0xfffffffc;
        piVar5 = extraout_ECX_03;
        FUN_45402b71(&stack0xfffffffc,pCVar4);
        *(undefined1 *)(unaff_EBP + -4) = 0x14;
        if (*(void **)(unaff_EBP + -0x1064) == (void *)0x0) goto LAB_45414fef;
        *(undefined1 *)(unaff_EBP + -4) = 0x13;
        FUN_454042e6(*(void **)(unaff_EBP + -0x1064),piVar5);
        if (*(IUnknown **)(unaff_EBP + -0x1064) == (IUnknown *)0x0) goto LAB_45414fef;
        FUN_45403562(*(IUnknown **)(unaff_EBP + -0x1064));
        piVar5 = *(int **)(unaff_EBP + -0x1064);
      }
      *(undefined1 *)(unaff_EBP + -4) = 0xf;
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 8))();
      }
      piVar5 = *(int **)(unaff_EBP + -0x1060);
      goto LAB_4541531c;
    }
  }
LAB_45414fef:
                    /* WARNING: Subroutine does not return */
  _com_issue_error(-0x7fffbffd);
}


