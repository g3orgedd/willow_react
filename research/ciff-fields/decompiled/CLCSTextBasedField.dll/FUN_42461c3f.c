// Source: CLCSTextBasedField.dll @ 42461c3f; FUN_42461c3f

void __thiscall FUN_42461c3f(void *this,LCID param_1)

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
    FUN_4246d990((uint *)((int)this + 0x110),0,0xc);
  }
  if (*(int *)((int)this + 0x108) == 0) {
    iVar1 = FUN_42460d78(param_1);
    *(char *)((int)this + 0x120) = '\x01' - (iVar1 != 1);
  }
  return;
}


