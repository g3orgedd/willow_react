// Source: CLCiffConversion_Layout.dll @ 4541c36b; FUN_4541c36b

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_4541c36b(int *param_1,void *param_2)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  HRESULT HVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int *local_50;
  int *local_4c;
  int *local_48;
  int *local_44;
  void *local_40;
  BSTR local_3c;
  int local_38;
  undefined4 local_34;
  BSTR local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_8 = 0x4541c377;
  local_40 = param_2;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFFontConvert::FindMatchingFontRaster");
  local_8 = 0;
  FUN_4541cdb6(param_2,&local_3c);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar4 = FUN_4541cded((int)param_2);
  piVar7 = *(int **)*param_1;
  local_38 = iVar4;
  if (piVar7 != (int *)*param_1) {
    do {
      piVar1 = (int *)piVar7[2];
      local_48 = piVar1;
      FUN_4541db3e(piVar1,&local_30);
      local_8._0_1_ = 2;
      iVar5 = FUN_4541d9ab(piVar1);
      if (iVar4 == iVar5) {
        piVar1 = (int *)*piVar1;
        local_50 = piVar1;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))();
        }
        local_44 = (int *)0x0;
        local_8._0_1_ = 4;
        FUN_4541a358(&local_50,(int *)&local_44);
        FUN_45402881(&local_34);
        piVar2 = local_44;
        local_8._0_1_ = 5;
        piVar10 = local_44;
        if (local_44 != (int *)0x0) {
          (**(code **)(*local_44 + 4))();
        }
        local_8._0_1_ = 6;
        piVar8 = local_4c;
        piVar9 = local_4c;
        (**(code **)*local_4c)(&stack0xffffff8c,local_40);
        local_8._0_1_ = 5;
        cVar3 = FUN_45403c0e(piVar8,piVar9,piVar10);
        if ((cVar3 != '\0') && (HVar6 = VarBstrCmp(local_3c,local_30,0x400,0), HVar6 == 1)) {
          FUN_454214b0(local_40,local_48,local_38);
          local_8._0_1_ = 4;
          FUN_45402c42(&local_34);
          local_8._0_1_ = 3;
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 8))();
          }
          local_8 = CONCAT31(local_8._1_3_,2);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))();
          }
          SysFreeString(local_30);
          break;
        }
        local_8._0_1_ = 4;
        FUN_45402c42(&local_34);
        local_8._0_1_ = 3;
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 8))();
        }
        local_8._0_1_ = 2;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))();
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        SysFreeString(local_30);
        iVar4 = local_38;
      }
      else {
        local_8 = CONCAT31(local_8._1_3_,1);
        SysFreeString(local_30);
      }
      piVar7 = (int *)*piVar7;
    } while (piVar7 != (int *)*param_1);
  }
  SysFreeString(local_3c);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


