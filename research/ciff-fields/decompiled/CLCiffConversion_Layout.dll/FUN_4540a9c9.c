// Source: CLCiffConversion_Layout.dll @ 4540a9c9; FUN_4540a9c9

int * __thiscall FUN_4540a9c9(void *this,byte param_1)

{
  if (*(int *)this != 0) {
    ScriptFreeCache(this);
  }
  *(undefined4 *)this = 0;
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


