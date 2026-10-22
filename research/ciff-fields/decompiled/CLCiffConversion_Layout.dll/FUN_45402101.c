// Source: CLCiffConversion_Layout.dll @ 45402101; FUN_45402101

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_45402101(void *this,uint param_1)

{
  uint uVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 | 0xf;
  if (uVar4 != 0xffffffff) {
    uVar1 = *(uint *)((int)this + 0x14);
    uVar3 = uVar1 >> 1;
    param_1 = uVar4;
    if (uVar4 / 3 < uVar3) {
      if (-uVar3 - 2 < uVar1) {
        param_1 = 0xfffffffe;
      }
      else {
        param_1 = uVar3 + uVar1;
      }
    }
  }
  pcVar2 = std::_Allocate<char>(param_1 + 1,(char *)0x0);
  FUN_45402193((undefined8 *)pcVar2);
  return;
}


