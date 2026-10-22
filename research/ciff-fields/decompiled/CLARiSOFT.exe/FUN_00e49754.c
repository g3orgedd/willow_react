// Source: CLARiSOFT.exe @ 00e49754; FUN_00e49754

bool __thiscall FUN_00e49754(void *this,LPWSTR param_1,LPDEVMODEW param_2)

{
  LPPRINTER_DEFAULTSW pDefault;
  _PRINTER_DEFAULTSW local_10;
  
  if (*(int *)this != 0) {
    ClosePrinter(*(HANDLE *)this);
    *(undefined4 *)this = 0;
  }
  pDefault = &local_10;
  local_10.pDatatype = (LPWSTR)0x0;
  local_10.pDevMode = param_2;
  local_10.DesiredAccess = 8;
  if (param_2 == (LPDEVMODEW)0x0) {
    pDefault = (LPPRINTER_DEFAULTSW)0x0;
  }
  OpenPrinterW(param_1,this,pDefault);
  return *(int *)this != 0;
}


