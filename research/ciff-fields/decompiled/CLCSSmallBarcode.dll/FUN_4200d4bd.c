// Source: CLCSSmallBarcode.dll @ 4200d4bd; FUN_4200d4bd

undefined4 __thiscall
FUN_4200d4bd(void *this,int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else if (*(int *)((int)this + 0xc) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    *param_1 = *(int *)((int)this + 0xc);
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)((int)this + 0x10);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)((int)this + 0x18);
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)((int)this + 0x14);
    }
    uVar1 = 0;
    *(undefined4 *)((int)this + 0xc) = 0;
    *(undefined4 *)((int)this + 0x10) = 0;
    *(undefined4 *)((int)this + 0x14) = 0;
    *(undefined4 *)((int)this + 0x18) = 0;
  }
  return uVar1;
}


