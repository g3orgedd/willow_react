// Source: CLCiffConversion_Data.dll @ 45016c5d; FUN_45016c5d

undefined4 FUN_45016c5d(undefined4 param_1,int *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  while ((((*(int *)((int)&PTR_DAT_450510a8 + uVar1) != *param_2 ||
           (*(int *)((int)&PTR_u_No_Translation_Found_450510ac + uVar1) != param_2[1])) ||
          (*(int *)((int)&PTR_u_No_Translation_Found_450510b0 + uVar1) != param_2[2])) ||
         (*(int *)((int)&PTR_u_No_Translation_Found_450510b4 + uVar1) != param_2[3]))) {
    uVar1 = uVar1 + 4;
    if (3 < uVar1) {
      return 1;
    }
  }
  return 0;
}


