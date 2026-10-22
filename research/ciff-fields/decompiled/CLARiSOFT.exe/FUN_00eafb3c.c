// Source: CLARiSOFT.exe @ 00eafb3c; FUN_00eafb3c

int * __thiscall FUN_00eafb3c(void *this,byte param_1)

{
  FUN_00ea8a0d(this);
  FID_conflict__free(*(void **)this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


