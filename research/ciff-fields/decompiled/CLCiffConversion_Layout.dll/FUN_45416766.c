// Source: CLCiffConversion_Layout.dll @ 45416766; FUN_45416766

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_45416766(void *this,int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *local_34;
  int local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x45416772;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFConvertBase::Convert CComPtr<ICiffSubImage>");
  local_8 = 0;
  local_30 = 0;
  local_34 = (undefined4 *)FUN_454043b0((int *)0x0,(int *)0x0);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_45404ce5((void *)((int)this + 0x5c),param_1);
  if (*param_1 == 0) {
    FUN_45414e34(0x454497d0);
  }
  else {
    FUN_45406d62(param_1,&local_34);
    puVar2 = local_34;
    if (local_30 == 0) {
      FUN_45414e34(0x454497b8);
    }
    else {
      puVar4 = (undefined4 *)*local_34;
      while ((puVar4 != puVar2 &&
             (iVar3 = (**(code **)(*(int *)this + 0x10))(puVar4[2]), -1 < iVar3))) {
        puVar4 = (undefined4 *)*puVar4;
      }
    }
    FUN_454065f3((int *)&local_34);
  }
  piVar1 = *(int **)((int)this + 0x5c);
  if ((piVar1 != (int *)0x0) && (*(int *)((int)this + 0x5c) = 0, piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_454224ff((int *)&local_34);
  FID_conflict__free(local_34);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


