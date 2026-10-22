// Source: CLCiffConversion_Layout.dll @ 4540ce9d; FUN_4540ce9d

/* WARNING: Removing unreachable block (ram,0x4540ced9) */

undefined4 __thiscall FUN_4540ce9d(void *this,uint param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    pcVar2 = std::_Allocate<char>(param_1,(char *)0x0);
    *(char **)this = pcVar2;
    *(char **)((int)this + 4) = pcVar2;
    *(char **)((int)this + 8) = pcVar2 + param_1;
    uVar1 = CONCAT31((int3)((uint)(pcVar2 + param_1) >> 8),1);
  }
  return uVar1;
}


