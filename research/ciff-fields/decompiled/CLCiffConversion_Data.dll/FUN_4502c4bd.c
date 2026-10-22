// Source: CLCiffConversion_Data.dll @ 4502c4bd; FUN_4502c4bd

void __cdecl
FUN_4502c4bd(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
            _s_FuncInfo *param_5,int param_6,int param_7,EHRegistrationNode *param_8)

{
  _ptiddata p_Var1;
  PVOID pvVar2;
  int iVar3;
  _s_HandlerType *p_Var4;
  uint uVar5;
  int *piVar6;
  uint local_c;
  uint local_8;
  
  if (*(int *)param_1 != -0x7ffffffd) {
    p_Var1 = __getptd();
    if (p_Var1->_translator != (void *)0x0) {
      pvVar2 = EncodePointer((PVOID)0x0);
      p_Var1 = __getptd();
      if ((((p_Var1->_translator != pvVar2) && (*(int *)param_1 != -0x1fbcb0b3)) &&
          (*(int *)param_1 != -0x1fbcbcae)) &&
         (iVar3 = FUN_450230e5((undefined4 *)param_1,(undefined4 *)param_2,param_3,param_4,param_5,
                               param_7,param_8), iVar3 != 0)) {
        return;
      }
    }
    if (param_5->nTryBlocks == 0) {
      _inconsistency();
    }
    iVar3 = FUN_450231bc((int)param_5,param_7,param_6,&local_c,&local_8);
    if (local_c < local_8) {
      piVar6 = (int *)(iVar3 + 0xc);
      uVar5 = local_8;
      do {
        if ((((piVar6[-3] <= param_6) && (param_6 <= piVar6[-2])) &&
            ((iVar3 = *piVar6 * 0x10, *(int *)(piVar6[1] + -0xc + iVar3) == 0 ||
             (uVar5 = local_8, *(char *)(*(int *)(piVar6[1] + -0xc + iVar3) + 8) == '\0')))) &&
           (p_Var4 = (_s_HandlerType *)(iVar3 + piVar6[1] + -0x10), (p_Var4->adjectives & 0x40) == 0
           )) {
          CatchIt(param_1,param_2,param_3,param_4,param_5,p_Var4,(_s_CatchableType *)0x0,
                  (_s_TryBlockMapEntry *)(piVar6 + -3),param_7,param_8,'\x01');
          uVar5 = local_8;
        }
        local_c = local_c + 1;
        piVar6 = piVar6 + 5;
      } while (local_c < uVar5);
    }
  }
  return;
}


