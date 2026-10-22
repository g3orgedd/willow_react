// Source: CLCiffConversion_Layout.dll @ 4541e5de; FUN_4541e5de

undefined4 FUN_4541e5de(undefined4 param_1,int *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  while ((((*(int *)((int)&PTR_DAT_4545d940 + uVar1) != *param_2 ||
           (*(int *)((int)&PTR_s_No_Translation_Found_4545d944 + uVar1) != param_2[1])) ||
          (*(int *)((int)&DAT_4545d948 + uVar1) != param_2[2])) ||
         (*(int *)((int)&DAT_4545d94c + uVar1) != param_2[3]))) {
    uVar1 = uVar1 + 4;
    if (3 < uVar1) {
      return 1;
    }
  }
  return 0;
}


