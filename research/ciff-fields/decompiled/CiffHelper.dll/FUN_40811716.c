// Source: CiffHelper.dll @ 40811716; FUN_40811716

uint __thiscall FUN_40811716(void *this,wchar_t *param_1,uint param_2,uint param_3)

{
  void *pvVar1;
  int iVar2;
  wchar_t *pwVar3;
  wchar_t *_S1;
  uint uVar4;
  size_t sVar5;
  
  if ((param_3 != 0) || (*(uint *)((int)this + 0x10) < param_2)) {
    if ((param_2 < *(uint *)((int)this + 0x10)) &&
       (uVar4 = *(uint *)((int)this + 0x10) - param_2, param_3 <= uVar4)) {
      sVar5 = uVar4 + (1 - param_3);
      pvVar1 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
        pvVar1 = *(void **)this;
      }
      pwVar3 = (wchar_t *)((int)pvVar1 + param_2 * 2);
      while (_S1 = FUN_408117b0(pwVar3,sVar5,param_1), _S1 != (wchar_t *)0x0) {
        if ((param_3 == 0) || (iVar2 = _wmemcmp(_S1,param_1,param_3), iVar2 == 0)) {
          if (7 < *(uint *)((int)this + 0x14)) {
            this = *(void **)this;
          }
          return (int)_S1 - (int)this >> 1;
        }
        sVar5 = sVar5 + (-1 - ((int)_S1 - (int)pwVar3 >> 1));
        pwVar3 = _S1 + 1;
      }
    }
    param_2 = 0xffffffff;
  }
  return param_2;
}


