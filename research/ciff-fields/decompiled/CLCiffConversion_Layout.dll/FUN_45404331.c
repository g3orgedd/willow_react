// Source: CLCiffConversion_Layout.dll @ 45404331; FUN_45404331

void __thiscall FUN_45404331(void *this,undefined8 *param_1)

{
  if (*(uint *)((int)param_1 + 0x14) < 0x10) {
    if (*(int *)(param_1 + 2) + 1U != 0) {
      FUN_4542a090(this,param_1,*(int *)(param_1 + 2) + 1U);
    }
  }
  else {
    if (this != (void *)0x0) {
      *(undefined4 *)this = *(undefined4 *)param_1;
    }
    *(undefined4 *)param_1 = 0;
  }
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 2);
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)((int)param_1 + 0x14);
  *(undefined4 *)(param_1 + 2) = 0;
  *(undefined4 *)((int)param_1 + 0x14) = 0xf;
  *(undefined1 *)param_1 = 0;
  return;
}


