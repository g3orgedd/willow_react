// Source: CLCiffConversion_Layout.dll @ 45405911; Catch_All@45405911

undefined4 Catch_All_45405911(void)

{
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
  *(HRESULT *)(unaff_EBP + -0x10a8) = HVar1;
  *(undefined1 *)(unaff_EBP + -4) = 0x24;
  GetLocalTime((LPSYSTEMTIME)(unaff_EBP + -0x108c));
  _sprintf_s((char *)(unaff_EBP + -0x54),0x1e,"%02d/%02d/%4d at %02d:%02d:%02d - ",
             (uint)*(ushort *)(unaff_EBP + -0x1086),(uint)*(ushort *)(unaff_EBP + -0x108a));
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
             (unaff_EBP + -0x107c),(char *)(unaff_EBP + -0x54));
  *(undefined1 *)(unaff_EBP + -4) = 0x25;
  sVar2 = _strlen("ATLTRACELOGALWAYS (...) Error");
  FUN_45404764((void *)(unaff_EBP + -0x107c),"ATLTRACELOGALWAYS (...) Error",sVar2);
  FUN_454028ee((void *)(unaff_EBP + -0x10a4),L"C://TraceErrorLog.log");
  *(undefined1 *)(unaff_EBP + -4) = 0x26;
  FUN_454027ae((void *)(unaff_EBP + -0x1090),(IID *)&DAT_45447724,(LPUNKNOWN)0x0,0x17);
  *(undefined1 *)(unaff_EBP + -4) = 0x27;
  piVar5 = (int *)0x0;
  if (*(int *)(unaff_EBP + -0x1090) == 0) {
LAB_45405b0c:
    *(undefined1 *)(unaff_EBP + -4) = 0x26;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 8))();
    }
    SysFreeString(*(BSTR *)(unaff_EBP + -0x10a4));
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
               (unaff_EBP + -0x107c),true,0);
    if (-1 < HVar1) {
      CoUninitialize();
    }
    return 0x45405485;
  }
  *(undefined1 **)(unaff_EBP + -0x109c) = &stack0xfffffffc;
  piVar5 = extraout_ECX;
  FUN_45402bbb(&stack0xfffffffc,*(OLECHAR **)(unaff_EBP + -0x10a4));
  *(undefined1 *)(unaff_EBP + -4) = 0x28;
  if (*(void **)(unaff_EBP + -0x1090) != (void *)0x0) {
    *(undefined1 *)(unaff_EBP + -4) = 0x27;
    iVar3 = FUN_4540377d(*(void **)(unaff_EBP + -0x1090),piVar5);
    piVar5 = extraout_ECX_00;
    if ((short)iVar3 == 0) {
      ppvVar6 = (void **)0xffffffff;
      *(undefined1 **)(unaff_EBP + -0x109c) = &stack0xfffffff4;
      FUN_45402bbb(&stack0xfffffff4,*(OLECHAR **)(unaff_EBP + -0x10a4));
      *(undefined1 *)(unaff_EBP + -4) = 0x29;
      if (*(void **)(unaff_EBP + -0x1090) == (void *)0x0) goto LAB_4540513c;
      *(undefined1 *)(unaff_EBP + -4) = 0x27;
      FUN_4540371c(*(void **)(unaff_EBP + -0x1090),(undefined4 *)(unaff_EBP + -0x10a0),piVar5,
                   ppvVar6);
      piVar5 = extraout_ECX_01;
      if (*(int **)(unaff_EBP + -0x10a0) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_EBP + -0x10a0) + 8))();
        piVar5 = extraout_ECX_02;
      }
    }
    *(undefined1 **)(unaff_EBP + -0x109c) = &stack0xfffffff0;
    FUN_45402bbb(&stack0xfffffff0,*(OLECHAR **)(unaff_EBP + -0x10a4));
    *(undefined1 *)(unaff_EBP + -4) = 0x2a;
    if (*(void **)(unaff_EBP + -0x1090) != (void *)0x0) {
      *(undefined1 *)(unaff_EBP + -4) = 0x27;
      FUN_45403f64(*(void **)(unaff_EBP + -0x1090),(undefined4 *)(unaff_EBP + -0x1098),piVar5);
      *(undefined1 *)(unaff_EBP + -4) = 0x2b;
      piVar5 = (int *)0x0;
      if (*(int *)(unaff_EBP + -0x1098) != 0) {
        pCVar4 = (LPCSTR)(unaff_EBP + -0x107c);
        if (0xf < *(uint *)(unaff_EBP + -0x1068)) {
          pCVar4 = *(LPCSTR *)(unaff_EBP + -0x107c);
        }
        *(undefined1 **)(unaff_EBP + -0x109c) = &stack0xfffffffc;
        piVar5 = extraout_ECX_03;
        FUN_45402b71(&stack0xfffffffc,pCVar4);
        *(undefined1 *)(unaff_EBP + -4) = 0x2c;
        if (*(void **)(unaff_EBP + -0x1098) == (void *)0x0) goto LAB_4540513c;
        *(undefined1 *)(unaff_EBP + -4) = 0x2b;
        FUN_454042e6(*(void **)(unaff_EBP + -0x1098),piVar5);
        if (*(IUnknown **)(unaff_EBP + -0x1098) == (IUnknown *)0x0) goto LAB_4540513c;
        FUN_45403562(*(IUnknown **)(unaff_EBP + -0x1098));
        piVar5 = *(int **)(unaff_EBP + -0x1098);
      }
      *(undefined1 *)(unaff_EBP + -4) = 0x27;
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 8))();
      }
      piVar5 = *(int **)(unaff_EBP + -0x1090);
      goto LAB_45405b0c;
    }
  }
LAB_4540513c:
                    /* WARNING: Subroutine does not return */
  _com_issue_error(-0x7fffbffd);
}


