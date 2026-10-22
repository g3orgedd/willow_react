// Source: CLCiffConversion_Data.dll @ 4502efdf; FID_conflict:wide_character_to_digit

/* Library Function - Multiple Matches With Different Base Names
    int __cdecl __crt_strtox::wide_character_to_digit(wchar_t)
    __wchartodigit
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Debug, Visual Studio 2015 Release,
   Visual Studio 2019 Release */

int __cdecl FID_conflict_wide_character_to_digit(ushort param_1)

{
  ushort uVar1;
  int iVar2;
  
  if (0x2f < param_1) {
    if (param_1 < 0x3a) {
      return param_1 - 0x30;
    }
    iVar2 = 0xff10;
    if (param_1 < 0xff10) {
      iVar2 = 0x660;
      if (param_1 < 0x660) {
        return -1;
      }
      if (param_1 < 0x66a) goto LAB_4502f023;
      iVar2 = 0x6f0;
      if (param_1 < 0x6f0) {
        return -1;
      }
      if (param_1 < 0x6fa) goto LAB_4502f023;
      iVar2 = 0x966;
      if (param_1 < 0x966) {
        return -1;
      }
      if (param_1 < 0x970) goto LAB_4502f023;
      iVar2 = 0x9e6;
      if (param_1 < 0x9e6) {
        return -1;
      }
      if (param_1 < 0x9f0) goto LAB_4502f023;
      iVar2 = 0xa66;
      if (param_1 < 0xa66) {
        return -1;
      }
      if (param_1 < 0xa70) goto LAB_4502f023;
      iVar2 = 0xae6;
      if (param_1 < 0xae6) {
        return -1;
      }
      if (param_1 < 0xaf0) goto LAB_4502f023;
      iVar2 = 0xb66;
      if (param_1 < 0xb66) {
        return -1;
      }
      if (param_1 < 0xb70) goto LAB_4502f023;
      iVar2 = 0xc66;
      if (param_1 < 0xc66) {
        return -1;
      }
      if (param_1 < 0xc70) goto LAB_4502f023;
      iVar2 = 0xce6;
      if (param_1 < 0xce6) {
        return -1;
      }
      if (param_1 < 0xcf0) goto LAB_4502f023;
      iVar2 = 0xd66;
      if (param_1 < 0xd66) {
        return -1;
      }
      if (param_1 < 0xd70) goto LAB_4502f023;
      iVar2 = 0xe50;
      if (param_1 < 0xe50) {
        return -1;
      }
      if (param_1 < 0xe5a) goto LAB_4502f023;
      iVar2 = 0xed0;
      if (param_1 < 0xed0) {
        return -1;
      }
      if (param_1 < 0xeda) goto LAB_4502f023;
      iVar2 = 0xf20;
      if (param_1 < 0xf20) {
        return -1;
      }
      if (param_1 < 0xf2a) goto LAB_4502f023;
      iVar2 = 0x1040;
      if (param_1 < 0x1040) {
        return -1;
      }
      if (param_1 < 0x104a) goto LAB_4502f023;
      iVar2 = 0x17e0;
      if (param_1 < 0x17e0) {
        return -1;
      }
      if (param_1 < 0x17ea) goto LAB_4502f023;
      iVar2 = 0x1810;
      if (param_1 < 0x1810) {
        return -1;
      }
      uVar1 = 0x181a;
    }
    else {
      uVar1 = 0xff1a;
    }
    if (param_1 < uVar1) {
LAB_4502f023:
      return (uint)param_1 - iVar2;
    }
  }
  return -1;
}


