// Source: CLCiffConversion_Layout.dll @ 45419a75; FUN_45419a75

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_45419a75(void *this,int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  uchar uVar3;
  int iVar4;
  HRESULT HVar5;
  BSTR extraout_ECX;
  int iVar6;
  undefined4 *puVar7;
  BSTR pOVar8;
  BSTR local_44;
  BSTR local_40;
  BSTR local_3c;
  int *local_38;
  undefined4 *local_34;
  undefined4 local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x45419a81;
  local_38 = param_1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFFontConvert::ConvertTextRaster");
  local_8 = 0;
  iVar6 = 0;
  local_30 = 0;
  local_34 = (undefined4 *)FUN_454043b0((int *)0x0,(int *)0x0);
  local_8._0_1_ = 1;
  FUN_4541d072(this,&local_34);
  FUN_4541cdb6(param_1,&local_44);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar4 = FUN_4541d01d((int)param_1);
  if (iVar4 != 2) {
    pOVar8 = extraout_ECX;
    FUN_4540288a(&stack0xffffffa8,(int *)&local_44);
    uVar3 = FUN_4541e92d(this,pOVar8);
    if (uVar3 == '\0') {
      iVar6 = FUN_4541c36b((int *)&local_34,param_1);
      goto LAB_45419b16;
    }
  }
  FUN_4540303d(0x45449ac8);
LAB_45419b16:
  if (iVar6 != 0) {
    iVar4 = *(int *)(*(int *)((int)this + 4) + 4);
    piVar1 = *(int **)(iVar4 + 0x40 + (int)this);
    if (piVar1 == *(int **)(iVar4 + 0x3c + (int)this)) {
      local_3c = (BSTR)0x0;
      local_8._0_1_ = 3;
      (**(code **)(*piVar1 + 0x1c))(piVar1);
      local_40 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,4);
      piVar1 = *(int **)(*(int *)(*(int *)((int)this + 4) + 4) + 0x3c + (int)this);
      (**(code **)(*piVar1 + 0x1c))(piVar1,&local_40);
      HVar5 = VarBstrCmp(local_3c,local_40,0x400,0);
      if (HVar5 == 1) {
        iVar6 = FUN_4541bb08(this,(int *)&local_34,local_38);
      }
      SysFreeString(local_40);
      local_8 = CONCAT31(local_8._1_3_,2);
      SysFreeString(local_3c);
    }
    if (iVar6 != 0) {
      FUN_45421676(this,(int *)&local_34,local_38);
    }
  }
  puVar2 = local_34;
  for (puVar7 = (undefined4 *)*local_34; puVar7 != puVar2; puVar7 = (undefined4 *)*puVar7) {
    local_38 = (int *)puVar7[2];
    if (local_38 != (int *)0x0) {
      FUN_45412f4b(local_38);
      FID_conflict__free(local_38);
    }
  }
  FUN_454224ff((int *)&local_34);
  SysFreeString(local_44);
  FUN_454224ff((int *)&local_34);
  FID_conflict__free(local_34);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


