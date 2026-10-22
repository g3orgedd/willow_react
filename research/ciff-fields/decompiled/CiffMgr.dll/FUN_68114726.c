// Source: CiffMgr.dll @ 68114726; FUN_68114726

void FUN_68114726(ushort *param_1,uint param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_2 >> 1 != 0) {
    do {
      bVar1 = FUN_681148ec(*param_1,(char *)&PTR_6814b0b8,2);
      param_1 = param_1 + 2;
      *(byte *)(uVar2 + param_3) = bVar1 << 4 | bVar1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2 >> 1);
  }
  return;
}


