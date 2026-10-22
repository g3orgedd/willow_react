// Source: CLARiSOFT.exe @ 00e7d086; Catch@00e7d086

void Catch_00e7d086(void)

{
  LPCWSTR lpText;
  int unaff_EBP;
  
  lpText = (LPCWSTR)FUN_00e2e16d(*(int *)(unaff_EBP + -0x98));
  MessageBoxW(*(HWND *)(*(int *)(unaff_EBP + -0x84) + 4),lpText,
              L"CMainFrm::InitialiseFieldComponents",0x10);
                    /* WARNING: Subroutine does not return */
  _exit(1);
}


