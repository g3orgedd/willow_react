// Source: CLCiffConversion_Layout.dll @ 454122f2; FUN_454122f2

int FUN_454122f2(undefined8 *param_1,int param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  
  uVar2 = param_2 - (int)param_1 & 0xfffffffc;
  puVar1 = FUN_4542a090(param_3,param_1,uVar2);
  return (int)puVar1 + uVar2;
}


