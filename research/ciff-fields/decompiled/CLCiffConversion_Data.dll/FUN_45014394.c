// Source: CLCiffConversion_Data.dll @ 45014394; FUN_45014394

uint __thiscall FUN_45014394(void *this,wchar_t *param_1,uint param_2,uint param_3)

{
  wchar_t wVar1;
  uint uVar2;
  int iVar3;
  wchar_t *pwVar4;
  uint uVar5;
  void *pvVar6;
  wchar_t *_S1;
  
  uVar5 = *(uint *)((int)this + 0x10);
  if (param_3 == 0) {
    if (param_2 < uVar5) {
      uVar5 = param_2;
    }
  }
  else {
    if (param_3 <= uVar5) {
      uVar2 = uVar5 - param_3;
      if (param_2 < uVar5 - param_3) {
        uVar2 = param_2;
      }
      pvVar6 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
        pvVar6 = *(void **)this;
      }
      _S1 = (wchar_t *)((int)pvVar6 + uVar2 * 2);
      wVar1 = *param_1;
      while( true ) {
        if ((*_S1 == wVar1) && (iVar3 = _wmemcmp(_S1,param_1,param_3), iVar3 == 0)) {
          if (7 < *(uint *)((int)this + 0x14)) {
            this = *(void **)this;
          }
          return (int)_S1 - (int)this >> 1;
        }
        pwVar4 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
          pwVar4 = *(wchar_t **)this;
        }
        if (_S1 == pwVar4) break;
        _S1 = _S1 + -1;
      }
    }
    uVar5 = 0xffffffff;
  }
  return uVar5;
}


