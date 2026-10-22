// Source: CLCiffConversion_Data.dll @ 45003068; Catch_All@45003068

undefined4 Catch_All_45003068(void)

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
  *(undefined1 *)(unaff_EBP + -4) = 0x25;
  GetLocalTime((LPSYSTEMTIME)(unaff_EBP + -0x108c));
  _sprintf_s((char *)(unaff_EBP + -0x54),0x1e,"%02d/%02d/%4d at %02d:%02d:%02d - ",
             (uint)*(ushort *)(unaff_EBP + -0x1086),(uint)*(ushort *)(unaff_EBP + -0x108a));
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
             (unaff_EBP + -0x107c),(char *)(unaff_EBP + -0x54));
  *(undefined1 *)(unaff_EBP + -4) = 0x26;
  sVar2 = _strlen("ATLTRACELOGALWAYS (...) Error");
  FUN_450047ff((void *)(unaff_EBP + -0x107c),"ATLTRACELOGALWAYS (...) Error",sVar2);
  FUN_45001f5d((void *)(unaff_EBP + -0x10a0),L"C://TraceErrorLog.log");
  *(undefined1 *)(unaff_EBP + -4) = 0x27;
  FUN_45001e66((void *)(unaff_EBP + -0x1090),(IID *)&DAT_4503d5b0,(LPUNKNOWN)0x0,0x17);
  *(undefined1 *)(unaff_EBP + -4) = 0x28;
  piVar5 = (int *)0x0;
  if (*(int *)(unaff_EBP + -0x1090) == 0) {
LAB_45003263:
    *(undefined1 *)(unaff_EBP + -4) = 0x27;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 8))();
    }
    SysFreeString(*(BSTR *)(unaff_EBP + -0x10a0));
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
               (unaff_EBP + -0x107c),true,0);
    if (-1 < HVar1) {
      CoUninitialize();
    }
    return 0x45002bdc;
  }
  *(undefined1 **)(unaff_EBP + -0x109c) = &stack0xfffffffc;
  piVar5 = extraout_ECX;
  FUN_450021a8(&stack0xfffffffc,*(OLECHAR **)(unaff_EBP + -0x10a0));
  *(undefined1 *)(unaff_EBP + -4) = 0x29;
  if (*(void **)(unaff_EBP + -0x1090) != (void *)0x0) {
    *(undefined1 *)(unaff_EBP + -4) = 0x28;
    iVar3 = FUN_45003795(*(void **)(unaff_EBP + -0x1090),piVar5);
    piVar5 = extraout_ECX_00;
    if ((short)iVar3 == 0) {
      ppvVar6 = (void **)0xffffffff;
      *(undefined1 **)(unaff_EBP + -0x109c) = &stack0xfffffff4;
      FUN_450021a8(&stack0xfffffff4,*(OLECHAR **)(unaff_EBP + -0x10a0));
      *(undefined1 *)(unaff_EBP + -4) = 0x2a;
      if (*(void **)(unaff_EBP + -0x1090) == (void *)0x0) goto LAB_450028a5;
      *(undefined1 *)(unaff_EBP + -4) = 0x28;
      FUN_4500370a(*(void **)(unaff_EBP + -0x1090),(undefined4 *)(unaff_EBP + -0x10a4),piVar5,
                   ppvVar6);
      piVar5 = extraout_ECX_01;
      if (*(int **)(unaff_EBP + -0x10a4) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_EBP + -0x10a4) + 8))();
        piVar5 = extraout_ECX_02;
      }
    }
    *(undefined1 **)(unaff_EBP + -0x109c) = &stack0xfffffff0;
    FUN_450021a8(&stack0xfffffff0,*(OLECHAR **)(unaff_EBP + -0x10a0));
    *(undefined1 *)(unaff_EBP + -4) = 0x2b;
    if (*(void **)(unaff_EBP + -0x1090) != (void *)0x0) {
      *(undefined1 *)(unaff_EBP + -4) = 0x28;
      FUN_450040de(*(void **)(unaff_EBP + -0x1090),(undefined4 *)(unaff_EBP + -0x1098),piVar5);
      *(undefined1 *)(unaff_EBP + -4) = 0x2c;
      piVar5 = (int *)0x0;
      if (*(int *)(unaff_EBP + -0x1098) != 0) {
        pCVar4 = (LPCSTR)(unaff_EBP + -0x107c);
        if (0xf < *(uint *)(unaff_EBP + -0x1068)) {
          pCVar4 = *(LPCSTR *)(unaff_EBP + -0x107c);
        }
        *(undefined1 **)(unaff_EBP + -0x109c) = &stack0xfffffffc;
        piVar5 = extraout_ECX_03;
        FUN_4500215e(&stack0xfffffffc,pCVar4);
        *(undefined1 *)(unaff_EBP + -4) = 0x2d;
        if (*(void **)(unaff_EBP + -0x1098) == (void *)0x0) goto LAB_450028a5;
        *(undefined1 *)(unaff_EBP + -4) = 0x2c;
        FUN_450042d1(*(void **)(unaff_EBP + -0x1098),piVar5);
        if (*(IUnknown **)(unaff_EBP + -0x1098) == (IUnknown *)0x0) goto LAB_450028a5;
        FUN_450034d3(*(IUnknown **)(unaff_EBP + -0x1098));
        piVar5 = *(int **)(unaff_EBP + -0x1098);
      }
      *(undefined1 *)(unaff_EBP + -4) = 0x28;
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 8))();
      }
      piVar5 = *(int **)(unaff_EBP + -0x1090);
      goto LAB_45003263;
    }
  }
LAB_450028a5:
                    /* WARNING: Subroutine does not return */
  _com_issue_error(-0x7fffbffd);
}


