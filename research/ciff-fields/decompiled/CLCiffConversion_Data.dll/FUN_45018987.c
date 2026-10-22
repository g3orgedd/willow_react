// Source: CLCiffConversion_Data.dll @ 45018987; FUN_45018987

undefined4 FUN_45018987(int param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004002;
  puVar1 = *(undefined4 **)(param_1 + param_4);
  *param_3 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    uVar2 = (**(code **)*puVar1)(puVar1,param_2,param_3);
  }
  return uVar2;
}


