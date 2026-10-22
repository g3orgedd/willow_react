// Source: CLCiffConversion_Layout.dll @ 45430730; FUN_45430730

void __cdecl
FUN_45430730(_CONTEXT *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
            char *param_5,char param_6,int param_7,EHRegistrationNode *param_8)

{
  char *pcVar1;
  int *piVar2;
  byte bVar3;
  bool bVar4;
  _ptiddata p_Var5;
  undefined3 extraout_var;
  undefined4 uVar6;
  int iVar7;
  _CONTEXT *p_Var8;
  uint *puVar9;
  EHRegistrationNode *pEVar10;
  undefined **local_40 [3];
  _s_CatchableType *local_34;
  _s_TryBlockMapEntry *local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  uint local_14;
  _s_HandlerType *local_10;
  int local_c;
  char local_5;
  
  puVar9 = (uint *)param_5;
  p_Var8 = param_1;
  iVar7 = 0;
  local_28 = local_28 & 0xffffff00;
  local_5 = '\0';
  if (*(int *)(param_5 + 4) < 0x81) {
    local_c = (int)(char)param_2[8];
  }
  else {
    local_c = *(int *)(param_2 + 8);
  }
  if ((local_c < -1) || (*(int *)(param_5 + 4) <= local_c)) {
    _inconsistency();
  }
  if (param_1->ContextFlags == 0xe06d7363) {
    if (((param_1->Dr3 == 3) &&
        (((param_1->Dr6 == 0x19930520 || (param_1->Dr6 == 0x19930521)) ||
         (param_1->Dr6 == 0x19930522)))) && ((param_1->FloatSave).ControlWord == 0)) {
      p_Var5 = __getptd();
      if (p_Var5->_curexception == (void *)0x0) {
        return;
      }
      p_Var5 = __getptd();
      p_Var8 = p_Var5->_curexception;
      p_Var5 = __getptd();
      local_28 = CONCAT31(local_28._1_3_,1);
      param_1 = p_Var5->_curcontext;
      bVar3 = FUN_4543acc7((int)p_Var8);
      if (CONCAT31(extraout_var,bVar3) == 0) {
        _inconsistency();
      }
      if ((((p_Var8->ContextFlags == 0xe06d7363) && (p_Var8->Dr3 == 3)) &&
          ((p_Var8->Dr6 == 0x19930520 ||
           ((p_Var8->Dr6 == 0x19930521 || (p_Var8->Dr6 == 0x19930522)))))) &&
         ((p_Var8->FloatSave).ControlWord == 0)) {
        _inconsistency();
      }
      p_Var5 = __getptd();
      if (p_Var5->_curexcspec != (void *)0x0) {
        p_Var5 = __getptd();
        local_18 = p_Var5->_curexcspec;
        p_Var5 = __getptd();
        p_Var5->_curexcspec = (void *)0x0;
        uVar6 = FUN_45430be9((int)p_Var8,local_18);
        piVar2 = local_18;
        if ((char)uVar6 == '\0') {
          if (0 < *local_18) {
            param_5 = (char *)0x0;
            do {
              bVar4 = type_info::operator==
                                (*(type_info **)(param_5 + piVar2[1] + 4),
                                 (type_info *)&std::bad_exception::RTTI_Type_Descriptor);
              if (bVar4) goto LAB_45430a79;
              iVar7 = iVar7 + 1;
              param_5 = param_5 + 0x10;
            } while (iVar7 < *piVar2);
          }
          goto LAB_45430a74;
        }
      }
    }
    else {
      param_1 = param_3;
    }
    param_3 = param_1;
    if (((p_Var8->ContextFlags == 0xe06d7363) && (p_Var8->Dr3 == 3)) &&
       ((p_Var8->Dr6 == 0x19930520 || ((p_Var8->Dr6 == 0x19930521 || (p_Var8->Dr6 == 0x19930522)))))
       ) {
      if ((*(int *)((int)puVar9 + 0xc) != 0) &&
         (iVar7 = FUN_4542ac5b((int)puVar9,param_7,local_c,&local_14,&local_2c), local_14 < local_2c
         )) {
        local_18 = (int *)(iVar7 + 0x10);
        iVar7 = local_c;
        do {
          pcVar1 = param_5;
          local_30 = (_s_TryBlockMapEntry *)(local_18 + -4);
          if ((local_18[-4] <= iVar7) && (iVar7 <= local_18[-3])) {
            local_10 = (_s_HandlerType *)*local_18;
            for (local_24 = local_18[-1]; puVar9 = (uint *)pcVar1, 0 < local_24;
                local_24 = local_24 + -1) {
              local_20 = *(int **)((p_Var8->FloatSave).ControlWord + 0xc);
              for (local_1c = *local_20; local_20 = local_20 + 1, 0 < local_1c;
                  local_1c = local_1c + -1) {
                local_34 = (_s_CatchableType *)*local_20;
                iVar7 = FUN_454310ee((byte *)local_10,(byte *)local_34,
                                     (byte *)(p_Var8->FloatSave).ControlWord);
                if (iVar7 != 0) {
                  local_5 = '\x01';
                  CatchIt((EHExceptionRecord *)p_Var8,param_2,param_1,param_4,(_s_FuncInfo *)pcVar1,
                          local_10,local_34,local_30,param_7,param_8,(uchar)local_28);
                  iVar7 = local_c;
                  goto LAB_454309b7;
                }
              }
              local_10 = local_10 + 1;
              iVar7 = local_c;
            }
          }
LAB_454309b7:
          local_14 = local_14 + 1;
          local_18 = local_18 + 5;
        } while (local_14 < local_2c);
      }
      if (param_6 != '\0') {
        ___DestructExceptionObject((int *)p_Var8);
      }
      if ((((local_5 == '\0') && (0x19930520 < (*puVar9 & 0x1fffffff))) && (puVar9[7] != 0)) &&
         (uVar6 = FUN_45430be9((int)p_Var8,(int *)puVar9[7]), (char)uVar6 == '\0')) {
        __getptd();
        __getptd();
        p_Var5 = __getptd();
        p_Var5->_curexception = p_Var8;
        p_Var5 = __getptd();
        p_Var5->_curcontext = param_1;
        pEVar10 = param_8;
        if (param_8 == (EHRegistrationNode *)0x0) {
          pEVar10 = param_2;
        }
        _UnwindNestedFrames(pEVar10,(EHExceptionRecord *)p_Var8);
        ___FrameUnwindToState((int)param_2,param_4,(int)puVar9,-1);
                    /* WARNING: Subroutine does not return */
        FUN_45430628((void *)puVar9[7]);
      }
      goto LAB_45430a5b;
    }
  }
  if (*(int *)((int)puVar9 + 0xc) != 0) {
    if (param_6 != '\0') {
LAB_45430a74:
      terminate();
LAB_45430a79:
      ___DestructExceptionObject((int *)p_Var8);
      param_5 = "bad exception";
      std::exception::exception((exception *)local_40,&param_5);
      local_40[0] = std::bad_exception::vftable;
                    /* WARNING: Subroutine does not return */
      FUN_4542a8e0((int *)local_40,&DAT_4545af1c);
    }
    FUN_45430acd((EHExceptionRecord *)p_Var8,param_2,param_3,param_4,(_s_FuncInfo *)puVar9,local_c,
                 param_7,param_8);
  }
LAB_45430a5b:
  p_Var5 = __getptd();
  if (p_Var5->_curexcspec != (void *)0x0) {
    _inconsistency();
  }
  return;
}


