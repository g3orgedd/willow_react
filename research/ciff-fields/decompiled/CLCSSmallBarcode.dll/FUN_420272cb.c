// Source: CLCSSmallBarcode.dll @ 420272cb; FUN_420272cb

int __thiscall
FUN_420272cb(void *this,int *param_1,int *param_2,int *param_3,undefined4 *param_4,BSTR param_5)

{
  int iVar1;
  
  iVar1 = FUN_4205a688(this,param_1,param_2,param_3,param_4,param_5);
  if (iVar1 == 0) {
    (**(code **)(*(int *)*param_3 + 0xcc))((int *)*param_3,1);
    iVar1 = 0;
  }
  return iVar1;
}


