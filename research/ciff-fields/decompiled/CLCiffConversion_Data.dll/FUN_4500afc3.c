// Source: CLCiffConversion_Data.dll @ 4500afc3; FUN_4500afc3

void * __thiscall FUN_4500afc3(void *this,byte param_1)

{
  void *_Memory;
  
  _Memory = (void *)((int)this + -8);
  FUN_4500afaa((int)_Memory);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(_Memory);
  }
  return _Memory;
}


