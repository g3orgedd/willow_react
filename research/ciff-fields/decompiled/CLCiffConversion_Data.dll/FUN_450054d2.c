// Source: CLCiffConversion_Data.dll @ 450054d2; FUN_450054d2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_450054d2(undefined4 *param_1)

{
  undefined4 uVar1;
  BSTR extraout_ECX;
  BSTR pOVar2;
  
  *param_1 = CCIFFConvertBase::vftable;
  param_1[2] = 0;
  FUN_4500548d((int)(param_1 + 3));
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  FUN_45001f5d(param_1 + 0x10,L"");
  *(undefined2 *)(param_1 + 0x11) = 0x101;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  *(undefined1 *)(param_1 + 0x14) = 0;
  FUN_45001f5d(param_1 + 0x15,L"");
  FUN_45001f5d(param_1 + 0x16,L"");
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = PTR_DAT_4505101c;
  param_1[0x1a] = PTR_DAT_4505101c;
  param_1[0x1b] = 0;
  FUN_45001eea(param_1 + 0x1c);
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  FUN_45001f8d(param_1 + 0x20);
  FUN_45001f8d(param_1 + 0x24);
  FUN_45001f8d(param_1 + 0x28);
  FUN_45001f8d(param_1 + 0x2c);
  FUN_45001f8d(param_1 + 0x30);
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  uVar1 = FUN_4500790c();
  param_1[0x35] = uVar1;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  pOVar2 = extraout_ECX;
  FUN_45001f5d(&stack0xffffffd4,L"Software\\Claricom Ltd\\CLARiNET\\VariableData");
  FUN_45020ad4(param_1 + 0x3a,0x80000001,pOVar2);
  *(undefined2 *)(param_1 + 0x30) = 3;
  *(undefined2 *)(param_1 + 0x3f) = 0;
  param_1[0x32] = 0;
  return param_1;
}


