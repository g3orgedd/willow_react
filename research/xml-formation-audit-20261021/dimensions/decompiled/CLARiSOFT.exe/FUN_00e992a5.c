// Source: CLARiSOFT.exe @ 00e992a5; Catch@00e992a5

undefined * Catch_00e992a5(void)

{
  LPCWSTR lpCaption;
  int unaff_EBP;
  
  lpCaption = (LPCWSTR)FUN_00e2e16d(*(int *)(unaff_EBP + -200));
  MessageBoxW(*(HWND *)(*(int *)(unaff_EBP + -0x54) + 4),L"CSPrintPreview::Preview",lpCaption,0x10);
  return &DAT_00e992ca;
}


