// Source: CiffMgr.dll @ 6810a9b5; FUN_6810a9b5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_6810a9b5(undefined4 *param_1)

{
  int *this;
  
  *param_1 = CMSXMLCiffSerialiser::vftable;
  param_1[2] = 1;
  *(undefined1 *)(param_1 + 3) = 0;
  FUN_6810a989(param_1 + 4);
  FUN_6810210e(param_1 + 0x2bd,L"TagData");
  this = param_1 + 0x2be;
  FUN_6810210e(this,L"spaRtNoyAK");
  param_1[0x2bf] = 0x26e20115;
  *(undefined2 *)*this = 0x54;
  *(undefined2 *)(*this + 8) = 99;
  *(undefined2 *)(*this + 0x10) = 0x65;
  *(undefined2 *)(*this + 4) = 0x79;
  *(undefined2 *)(*this + 0xc) = 0x65;
  return param_1;
}


