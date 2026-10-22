// Source: CLPrintPreview.ocx @ 3f417268; FUN_3f417268

void FUN_3f417268(void *param_1,short param_2,undefined4 param_3,int *param_4,undefined4 param_5,
                 short param_6,undefined4 param_7,int *param_8,undefined4 param_9,short param_10,
                 undefined4 param_11,OLECHAR *param_12,undefined4 param_13,short param_14,
                 undefined4 param_15,OLECHAR *param_16,undefined4 param_17,short param_18,
                 undefined4 param_19,OLECHAR *param_20,undefined4 param_21,short param_22,
                 undefined4 param_23,OLECHAR *param_24,undefined4 param_25,undefined4 param_26,
                 undefined4 param_27,OLECHAR *param_28)

{
  int *piVar1;
  BSTR local_8;
  
  piVar1 = FUN_3f403012(&local_8,param_28);
  FUN_3f408205((void *)((int)param_1 + 300),piVar1);
  SysFreeString(local_8);
  FUN_3f4175db(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               param_11,param_12,param_13,param_14,param_15,param_16,param_17,param_18,param_19,
               param_20,param_21,param_22,param_23,param_24,param_25,1);
  return;
}


