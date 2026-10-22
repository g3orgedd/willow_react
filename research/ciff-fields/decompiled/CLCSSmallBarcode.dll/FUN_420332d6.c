// Source: CLCSSmallBarcode.dll @ 420332d6; FUN_420332d6

void __thiscall FUN_420332d6(void *this,undefined2 *param_1,undefined2 *param_2,int param_3)

{
  byte bVar1;
  undefined2 uVar2;
  
  if ((param_3 == 0) ||
     (bVar1 = *(byte *)(*(int *)((int)this + 0xad0) + 0x34 + (int)this), 0x7f < bVar1)) {
    uVar2 = 0;
    *param_1 = 0;
  }
  else {
    *param_1 = *(undefined2 *)(&DAT_42096230 + (uint)bVar1 * 4);
    uVar2 = *(undefined2 *)(&DAT_42096232 + (uint)bVar1 * 4);
  }
  *param_2 = uVar2;
  return;
}


