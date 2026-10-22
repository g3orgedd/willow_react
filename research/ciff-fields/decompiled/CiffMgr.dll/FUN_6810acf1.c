// Source: CiffMgr.dll @ 6810acf1; FUN_6810acf1

void __fastcall FUN_6810acf1(undefined4 *param_1)

{
  *param_1 = CMSXMLCiffSerialiser::vftable;
  SysFreeString((BSTR)param_1[0x2be]);
  SysFreeString((BSTR)param_1[0x2bd]);
  param_1[4] = CEncryption::vftable;
  return;
}


