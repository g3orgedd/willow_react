// Source: CLCSSmallBarcode.dll @ 4200c000; FUN_4200c000

void FUN_4200c000(int *param_1,HDC param_2,int *param_3,int *param_4)

{
  int iVar1;
  UINT c;
  BOOL BVar2;
  tagSIZE local_54;
  int *local_4c;
  HDC local_48;
  tagTEXTMETRICW local_44;
  uint local_8;
  
  local_8 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  local_48 = param_2;
  local_4c = param_4;
  if ((param_3 != (int *)0x0) && (param_2 != (HDC)0x0)) {
    *param_4 = 0;
    iVar1 = (**(code **)*param_3)
                      (param_3,&local_48,param_1[0x17],param_1[0x18],param_1[0x1a],param_1[0x19],0,0
                       ,3,param_1[4],param_1[5]);
    if ((-1 < iVar1) && (iVar1 = (**(code **)(*param_1 + 0x14))(), -1 < iVar1)) {
      local_44.tmHeight = 0;
      FUN_420698e0((uint *)&local_44.tmAscent,0,0x38);
      c = SysStringLen((BSTR)param_1[0x16]);
      BVar2 = GetTextExtentPoint32W(local_48,(LPCWSTR)param_1[0x16],c,&local_54);
      if ((BVar2 != 0) && (BVar2 = GetTextMetricsW(local_48,&local_44), BVar2 != 0)) {
        *local_4c = param_1[0x3a] + param_1[0x1e] + local_54.cy;
        (**(code **)(*param_3 + 4))(param_3,&local_48);
      }
    }
  }
  FUN_4206a5c8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


