// Source: CLCiffConversion_Data.dll @ 450060cb; Catch@450060cb

undefined * Catch_450060cb(void)

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
  *(HRESULT *)(unaff_EBP + -0x1070) = HVar1;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  GetLocalTime((LPSYSTEMTIME)(unaff_EBP + -0x1044));
  _sprintf_s((char *)(unaff_EBP + -0x34),0x1e,"%02d/%02d/%4d at %02d:%02d:%02d - ",
             (uint)*(ushort *)(unaff_EBP + -0x103e),(uint)*(ushort *)(unaff_EBP + -0x1042));
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
             (unaff_EBP + -0x105c),(char *)(unaff_EBP + -0x34));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  sVar2 = _strlen("ATLTRACELOG _com_error");
  FUN_450047ff((void *)(unaff_EBP + -0x105c),"ATLTRACELOG _com_error",sVar2);
  FUN_45001f5d((void *)(unaff_EBP + -0x1068),L"C://TraceErrorLog.log");
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_45001e66((void *)(unaff_EBP + -0x1060),(IID *)&DAT_4503d5b0,(LPUNKNOWN)0x0,0x17);
  bstrString = *(OLECHAR **)(unaff_EBP + -0x1068);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  piVar5 = (int *)0x0;
  if (*(int *)(unaff_EBP + -0x1060) == 0) {
LAB_450062bb:
    *(undefined1 *)(unaff_EBP + -4) = 6;
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
    return &DAT_450062ee;
  }
  *(undefined1 **)(unaff_EBP + -0x106c) = &stack0xfffffffc;
  piVar5 = extraout_ECX;
  FUN_450021a8(&stack0xfffffffc,bstrString);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  if (*(void **)(unaff_EBP + -0x1060) != (void *)0x0) {
    *(undefined1 *)(unaff_EBP + -4) = 7;
    iVar3 = FUN_45003795(*(void **)(unaff_EBP + -0x1060),piVar5);
    piVar5 = extraout_ECX_00;
    if ((short)iVar3 == 0) {
      ppvVar6 = (void **)0xffffffff;
      *(undefined1 **)(unaff_EBP + -0x1074) = &stack0xfffffff4;
      FUN_450021a8(&stack0xfffffff4,bstrString);
      *(undefined1 *)(unaff_EBP + -4) = 9;
      if (*(void **)(unaff_EBP + -0x1060) == (void *)0x0) goto LAB_450061b8;
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_4500370a(*(void **)(unaff_EBP + -0x1060),(undefined4 *)(unaff_EBP + -0x106c),piVar5,
                   ppvVar6);
      piVar5 = extraout_ECX_01;
      if (*(int **)(unaff_EBP + -0x106c) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_EBP + -0x106c) + 8))();
        piVar5 = extraout_ECX_02;
      }
    }
    *(undefined1 **)(unaff_EBP + -0x1074) = &stack0xfffffff0;
    FUN_450021a8(&stack0xfffffff0,bstrString);
    *(undefined1 *)(unaff_EBP + -4) = 10;
    if (*(void **)(unaff_EBP + -0x1060) != (void *)0x0) {
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_450040de(*(void **)(unaff_EBP + -0x1060),(undefined4 *)(unaff_EBP + -0x1064),piVar5);
      *(undefined1 *)(unaff_EBP + -4) = 0xb;
      piVar5 = (int *)0x0;
      if (*(int *)(unaff_EBP + -0x1064) != 0) {
        pCVar4 = (LPCSTR)(unaff_EBP + -0x105c);
        if (0xf < *(uint *)(unaff_EBP + -0x1048)) {
          pCVar4 = *(LPCSTR *)(unaff_EBP + -0x105c);
        }
        *(undefined1 **)(unaff_EBP + -0x1074) = &stack0xfffffffc;
        piVar5 = extraout_ECX_03;
        FUN_4500215e(&stack0xfffffffc,pCVar4);
        *(undefined1 *)(unaff_EBP + -4) = 0xc;
        if (*(void **)(unaff_EBP + -0x1064) == (void *)0x0) goto LAB_450061b8;
        *(undefined1 *)(unaff_EBP + -4) = 0xb;
        FUN_450042d1(*(void **)(unaff_EBP + -0x1064),piVar5);
        if (*(IUnknown **)(unaff_EBP + -0x1064) == (IUnknown *)0x0) goto LAB_450061b8;
        FUN_450034d3(*(IUnknown **)(unaff_EBP + -0x1064));
        piVar5 = *(int **)(unaff_EBP + -0x1064);
      }
      *(undefined1 *)(unaff_EBP + -4) = 7;
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 8))();
      }
      piVar5 = *(int **)(unaff_EBP + -0x1060);
      goto LAB_450062bb;
    }
  }
LAB_450061b8:
                    /* WARNING: Subroutine does not return */
  _com_issue_error(-0x7fffbffd);
}


