// Source: CLCSSmallBarcode.dll @ 4200d047; FUN_4200d047

void FUN_4200d047(int param_1,int *param_2,short *param_3,undefined4 param_4,int param_5,
                 undefined4 param_6,int param_7,uint param_8,undefined4 param_9,int param_10,
                 int param_11)

{
  HDC hdc;
  char cVar1;
  int iVar2;
  COLORREF color;
  COLORREF color_00;
  int iVar3;
  ushort local_64 [46];
  uint local_8;
  
  local_8 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  iVar2 = param_7 / 0x2d;
  iVar3 = param_10;
  if ((0 < iVar2) && ((iVar2 < 3 || (iVar2 - 5U < 2)))) {
    iVar3 = param_11;
    param_11 = param_10;
  }
  iVar2 = MulDiv(param_5,param_11 * 1000,0xb13);
  FUN_4200ae4e(local_64,param_3,param_4,-iVar2,param_6,param_7,param_8,iVar3,param_11);
  cVar1 = FUN_4200ce9a((void *)(param_1 + 0x50),*param_2,local_64);
  if ((cVar1 != '\0') && (*(uint *)(param_1 + 0x2c) = param_8 & 4, (param_8 & 4) != 0)) {
    hdc = (HDC)*param_2;
    color = GetTextColor(hdc);
    color_00 = GetBkColor(hdc);
    SetTextColor(hdc,color_00);
    SetBkColor(hdc,color);
  }
  FUN_4206a5c8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


