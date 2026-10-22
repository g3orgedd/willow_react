// Source: CLCiffConversion_Layout.dll @ 4541c176; FUN_4541c176

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4541c176(void *this,int *param_1,void *param_2)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  HRESULT HVar5;
  int *piVar6;
  int *piVar7;
  void *pvVar8;
  int *piVar9;
  int *local_48;
  void *local_44;
  int *local_40;
  undefined4 local_3c;
  BSTR local_38;
  BSTR local_34;
  int *local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_8 = 0x4541c182;
  local_44 = param_2;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFFontConvert::FindMatchingFont");
  local_8 = 0;
  FUN_4541cdb6(param_2,&local_34);
  local_8 = CONCAT31(local_8._1_3_,1);
  uVar4 = FUN_4541cded((int)param_2);
  piVar6 = *(int **)*param_1;
  if (piVar6 != (int *)*param_1) {
    do {
      piVar1 = (int *)piVar6[2];
      local_30 = piVar1;
      FUN_4541db3e(piVar1,&local_38);
      piVar1 = (int *)*piVar1;
      local_8._0_1_ = 2;
      local_48 = piVar1;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))();
      }
      local_40 = (int *)0x0;
      local_8._0_1_ = 4;
      FUN_4541a358(&local_48,(int *)&local_40);
      FUN_45402881(&local_3c);
      piVar2 = local_40;
      local_8._0_1_ = 5;
      piVar9 = local_40;
      if (local_40 != (int *)0x0) {
        (**(code **)(*local_40 + 4))();
      }
      local_8._0_1_ = 6;
      piVar7 = this;
      pvVar8 = this;
      (*(code *)**(undefined4 **)this)(&stack0xffffff8c,local_44);
      local_8._0_1_ = 5;
      cVar3 = FUN_45403c0e(piVar7,pvVar8,piVar9);
      if ((cVar3 != '\0') && (HVar5 = VarBstrCmp(local_34,local_38,0x400,0), HVar5 == 1)) {
        FUN_454214b0(local_44,local_30,uVar4);
        FUN_45402ac2(&local_30,local_34);
        local_8._0_1_ = 7;
        FUN_4540303d(0x45449ba4);
        FUN_45402c5d((int *)&local_30);
        local_8._0_1_ = 4;
        FUN_45402c42(&local_3c);
        local_8._0_1_ = 3;
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 8))();
        }
        local_8 = CONCAT31(local_8._1_3_,2);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))();
        }
        SysFreeString(local_38);
        goto LAB_4541c2d4;
      }
      local_8._0_1_ = 4;
      FUN_45402c42(&local_3c);
      local_8._0_1_ = 3;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))();
      }
      local_8._0_1_ = 2;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))();
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      SysFreeString(local_38);
      piVar6 = (int *)*piVar6;
    } while (piVar6 != (int *)*param_1);
  }
  FUN_45402ac2(&local_30,local_34);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_4540303d(0x45449bb8);
  FUN_45402c5d((int *)&local_30);
LAB_4541c2d4:
  SysFreeString(local_34);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


