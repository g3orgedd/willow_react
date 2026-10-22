// Source: CLCiffConversion_Layout.dll @ 4541991d; FUN_4541991d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4541991d(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  HRESULT HVar4;
  int local_40;
  BSTR local_3c;
  BSTR local_38;
  void *local_34;
  undefined4 local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x45419929;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFFontConvert::ConvertText");
  local_8 = 0;
  local_30 = 0;
  local_34 = (void *)FUN_454043b0((int *)0x0,(int *)0x0);
  local_40 = 0;
  local_8._0_1_ = 1;
  piVar1 = *(int **)(*(int *)(*(int *)((int)this + 4) + 4) + 0x3c + (int)this);
  (**(code **)(*piVar1 + 0x184))(piVar1,&local_40);
  FUN_4540303d(0x45449a88);
  if (local_40 == 0) {
    FUN_4541d072(this,&local_34);
    iVar3 = FUN_4541c176(this,(int *)&local_34,param_1);
    if (iVar3 != 0) {
      iVar2 = *(int *)(*(int *)((int)this + 4) + 4);
      piVar1 = *(int **)(iVar2 + 0x40 + (int)this);
      if (piVar1 == *(int **)(iVar2 + 0x3c + (int)this)) {
        local_38 = (BSTR)0x0;
        local_8._0_1_ = 2;
        (**(code **)(*piVar1 + 0x1c))(piVar1,&local_38);
        local_3c = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,3);
        piVar1 = *(int **)(*(int *)(*(int *)((int)this + 4) + 4) + 0x3c + (int)this);
        (**(code **)(*piVar1 + 0x1c))(piVar1,&local_3c);
        HVar4 = VarBstrCmp(local_38,local_3c,0x400,0);
        if (HVar4 == 1) {
          iVar3 = FUN_4541bb08(this,(int *)&local_34,param_1);
        }
        SysFreeString(local_3c);
        local_8._0_1_ = 1;
        SysFreeString(local_38);
      }
      if (iVar3 != 0) {
        FUN_45421676(this,(int *)&local_34,param_1);
      }
    }
    FUN_45416045((int *)&local_34);
  }
  FUN_454224ff((int *)&local_34);
  FID_conflict__free(local_34);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


