// Source: CiffHelper.dll @ 40831840; FUN_40831840

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_40831840(double param_1,undefined2 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ushort in_FPUControlWord;
  float10 fVar4;
  double dVar5;
  longlong lVar6;
  double dVar7;
  
  if ((DAT_4086858c != 0) && ((MXCSR & 0x7f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    uVar2 = (uint)((ulonglong)param_1 >> 0x20);
    uVar1 = uVar2 >> 0x14;
    lVar6 = CONCAT44(_UNK_40851a74,_DAT_40851a70 - (uVar2 >> 0x14 & _DAT_40851a90));
    if ((uVar1 & 0x800) == 0) {
      dVar5 = (double)(((ulonglong)param_1 >> lVar6) << lVar6);
      if (uVar1 < 0x3ff) {
        return (float10)(double)(-(ulonglong)(_DAT_40851a80 < param_1) & _DAT_40851a60);
      }
      if (uVar1 < 0x433) {
        return (float10)(dVar5 + (double)(-(ulonglong)(dVar5 < param_1) & _DAT_40851a60));
      }
    }
    else {
      if (uVar1 < 0xbff) {
        return (float10)_DAT_40851aa0;
      }
      if (uVar1 < 0xc33) {
        return (float10)(double)(((ulonglong)param_1 >> lVar6) << lVar6);
      }
    }
    if (NAN(param_1)) {
      FUN_4083a2d7(&param_1,&param_1,&param_1,0x3ec);
    }
    return (float10)(double)CONCAT26(param_1._6_2_,param_1._0_6_);
  }
  uVar2 = __ctrlfp();
  uVar1 = (uint)(CONCAT26(param_1._6_2_,param_1._0_6_) >> 0x20);
  if ((param_1._6_2_ & 0x7ff0) == 0x7ff0) {
    iVar3 = __sptype((int)param_1._0_6_,uVar1);
    if (0 < iVar3) {
      if (iVar3 < 3) {
        __ctrlfp();
        return (float10)(double)CONCAT26(param_1._6_2_,param_1._0_6_);
      }
      if (iVar3 == 3) {
        fVar4 = __handle_qnan1(0xc,(double)CONCAT44((int)(CONCAT26(param_1._6_2_,param_1._0_6_) >>
                                                         0x20),(int)param_1._0_6_));
        return fVar4;
      }
    }
    dVar7 = (double)CONCAT26(param_1._6_2_,param_1._0_6_);
    dVar5 = _DAT_40851a50 + dVar7;
    uVar1 = 8;
  }
  else {
    fVar4 = FUN_408400a9((double)CONCAT44(uVar1,(int)param_1._0_6_));
    dVar5 = (double)fVar4;
    dVar7 = (double)CONCAT26(param_1._6_2_,param_1._0_6_);
    if (((float10)dVar7 == fVar4) || ((uVar2 & 0x20) != 0)) {
      __ctrlfp();
      return (float10)dVar5;
    }
    dVar5 = (double)fVar4;
    uVar1 = 0x10;
  }
  fVar4 = (float10)__except1(uVar1,0xc,dVar7,dVar5,uVar2);
  return fVar4;
}


