// Source: CLCSSmallBarcode.dll @ 42034dac; FUN_42034dac

void __cdecl FUN_42034dac(byte *param_1,void *param_2,int param_3,int param_4)

{
  byte bVar1;
  size_t sVar2;
  int iVar3;
  
  sVar2 = 0xffffffff;
  bVar1 = *param_1;
  while ((bVar1 != 0 && (sVar2 != 0))) {
    iVar3 = FUN_42036032(param_1);
    if (iVar3 == 0) {
      sVar2 = FUN_42034aaf(param_1,param_2,param_3,param_4);
    }
    else if (iVar3 == 1) {
      sVar2 = FUN_420348fb(param_1,param_2,param_3,param_4);
    }
    else if ((iVar3 == 3) && (param_4 == 3)) {
      sVar2 = FUN_420349f2(param_1,param_2);
    }
    else {
      sVar2 = FUN_420347e1(param_1,param_2,param_3,param_4);
    }
    param_1 = param_1 + sVar2;
    bVar1 = *param_1;
  }
  return;
}


