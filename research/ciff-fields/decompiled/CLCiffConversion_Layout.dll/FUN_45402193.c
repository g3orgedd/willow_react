// Source: CLCiffConversion_Layout.dll @ 45402193; FUN_45402193

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_45402193(undefined8 *param_1)

{
  uint uVar1;
  int iVar2;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbVar3;
  uint unaff_EBX;
  int unaff_EBP;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *unaff_ESI;
  uint unaff_EDI;
  
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  if (uVar1 != 0) {
    pbVar3 = unaff_ESI;
    if (0xf < *(uint *)(unaff_ESI + 0x14)) {
      pbVar3 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)unaff_ESI;
    }
    if (uVar1 != 0) {
      FUN_45429920(param_1,(undefined8 *)pbVar3,uVar1);
    }
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
            (unaff_ESI,true,unaff_EBX);
  if (unaff_ESI != (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x0) {
    *(undefined4 *)unaff_ESI = *(undefined4 *)(unaff_EBP + -0x14);
  }
  iVar2 = *(int *)(unaff_EBP + 0xc);
  *(uint *)(unaff_ESI + 0x14) = unaff_EDI;
  *(int *)(unaff_ESI + 0x10) = iVar2;
  if (0xf < unaff_EDI) {
    unaff_ESI = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)unaff_ESI;
  }
  unaff_ESI[iVar2] = SUB41(unaff_EBX,0);
  return;
}


