// Source: CLCiffConversion_Data.dll @ 4502be52; CallCatchBlock

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void * __cdecl CallCatchBlock(struct EHExceptionRecord *,struct EHRegistrationNode *,struct
   _CONTEXT *,struct _s_FuncInfo const *,void *,int,unsigned long)
   
   Library: Visual Studio 2012 Release */

void * __cdecl
CallCatchBlock(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,
              _s_FuncInfo *param_4,void *param_5,int param_6,ulong param_7)

{
  _ptiddata p_Var1;
  undefined4 local_44 [2];
  undefined4 local_3c;
  void *local_38;
  void *local_34;
  undefined4 *local_30;
  undefined4 local_2c;
  void *local_20;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_4504fbe0;
  uStack_c = 0x4502be5e;
  local_20 = param_5;
  local_3c = 0;
  local_2c = *(undefined4 *)(param_2 + -4);
  local_30 = __CreateFrameInfo(local_44,*(undefined4 *)(param_1 + 0x18));
  p_Var1 = __getptd();
  local_34 = p_Var1->_curexception;
  p_Var1 = __getptd();
  local_38 = p_Var1->_curcontext;
  p_Var1 = __getptd();
  p_Var1->_curexception = param_1;
  p_Var1 = __getptd();
  p_Var1->_curcontext = param_3;
  local_8 = (undefined *)0x1;
  local_20 = _CallCatchBlock2(param_2,param_4,param_5,param_6,param_7);
  local_8 = (undefined *)0xfffffffe;
  FUN_4502bf99();
  return param_2;
}


