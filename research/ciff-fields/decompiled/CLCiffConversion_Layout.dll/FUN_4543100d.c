// Source: CLCiffConversion_Layout.dll @ 4543100d; FUN_4543100d

undefined4 __cdecl
FUN_4543100d(_CONTEXT *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
            uint *param_5,int param_6,EHRegistrationNode *param_7,char param_8)

{
  code *pcVar1;
  _ptiddata p_Var2;
  undefined4 uVar3;
  
  p_Var2 = __getptd();
  if ((((p_Var2->_cxxReThrow != 0) || (param_1->ContextFlags == 0xe06d7363)) ||
      (param_1->ContextFlags == 0x80000026)) ||
     (((*param_5 & 0x1fffffff) < 0x19930522 || ((param_5[8] & 1) == 0)))) {
    if ((param_1->Dr0 & 0x66) == 0) {
      if ((param_5[3] != 0) || ((0x19930520 < (*param_5 & 0x1fffffff) && (param_5[7] != 0)))) {
        if ((param_1->ContextFlags == 0xe06d7363) &&
           (((2 < param_1->Dr3 && (0x19930522 < param_1->Dr6)) &&
            (pcVar1 = *(code **)((param_1->FloatSave).ControlWord + 8), pcVar1 != (code *)0x0)))) {
          uVar3 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
          return uVar3;
        }
        FUN_45430730(param_1,param_2,param_3,param_4,(char *)param_5,param_8,param_6,param_7);
      }
    }
    else if ((param_5[1] != 0) && (param_6 == 0)) {
      ___FrameUnwindToState((int)param_2,param_4,(int)param_5,-1);
    }
  }
  return 1;
}


