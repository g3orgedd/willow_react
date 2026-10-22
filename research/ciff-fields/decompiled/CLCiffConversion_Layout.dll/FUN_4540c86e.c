// Source: CLCiffConversion_Layout.dll @ 4540c86e; FUN_4540c86e

void __thiscall FUN_4540c86e(void *this,LCID param_1)

{
  int iVar1;
  
  *(LCID *)((int)this + 0x11c) = param_1;
  if (*(char *)((int)this + 0x10c) == '\0') {
    iVar1 = -0x7fffbffb;
  }
  else {
    iVar1 = ScriptRecordDigitSubstitution(param_1,(int)this + 0x110);
  }
  if (iVar1 < 0) {
    FUN_45429f70((uint *)((int)this + 0x110),0,0xc);
  }
  if (*(int *)((int)this + 0x108) == 0) {
    iVar1 = FUN_4540b9a7(param_1);
    *(char *)((int)this + 0x120) = '\x01' - (iVar1 != 1);
  }
  return;
}


