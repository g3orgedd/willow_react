// Source: CLCSBarcodeField.dll @ 41415aad; FUN_41415aad

void __thiscall FUN_41415aad(void *this,ulong param_1,void *param_2)

{
  void *pvVar1;
  
  if (*(int *)this == 0) {
    pvVar1 = __AllocStdCallThunk_cmn();
    *(void **)this = pvVar1;
    if (pvVar1 == (void *)0x0) {
      return;
    }
  }
  ATL::_stdcallthunk::Init(*(_stdcallthunk **)this,param_1,param_2);
  return;
}


