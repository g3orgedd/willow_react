// Source: CLCiffConversion_Layout.dll @ 4541e049; FUN_4541e049

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_4541e049(short param_1,undefined4 param_2,wchar_t *param_3)

{
  bool bVar1;
  void *pvVar2;
  void *this;
  int *piVar3;
  uint uVar4;
  int *local_48;
  void *local_44;
  undefined4 *local_40;
  uint local_3c;
  int local_38;
  int *local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x50;
  local_8 = 0x4541e055;
  local_3c = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCiffConversion_Layout::InitialiseCapiList");
  local_8 = 1;
  if (param_1 == 8) {
    FUN_45407800((void *)(local_38 + 0x4e0),param_3);
  }
  for (uVar4 = 0; uVar4 < (uint)(*(int *)(local_38 + 0x4d4) - *(int *)(local_38 + 0x4d0) >> 2);
      uVar4 = uVar4 + 1) {
    local_34 = *(int **)(*(int *)(local_38 + 0x4d0) + uVar4 * 4);
    if (local_34 != (int *)0x0) {
      FUN_45412f6f(local_34);
      FID_conflict__free(local_34);
    }
  }
  local_40 = (undefined4 *)(local_38 + 0x4d0);
  *(undefined4 *)(local_38 + 0x4d4) = *local_40;
  FUN_45402a2f(&local_38,(int *)(local_38 + 0x4e0));
  local_8._0_1_ = 2;
  FUN_45404db2(&local_38,"CLGeneric_Capabilities.XML");
  pvVar2 = (void *)FUN_454298b4(0x18);
  local_8._0_1_ = 3;
  if (pvVar2 == (void *)0x0) {
    this = (void *)0x0;
  }
  else {
    local_44 = pvVar2;
    FUN_45402a65(&local_34,"Generic");
    local_8 = CONCAT31(local_8._1_3_,4);
    local_3c = 1;
    this = FUN_45412a86(pvVar2,(int *)&local_34,&local_38);
  }
  bVar1 = pvVar2 != (void *)0x0;
  uVar4 = (uint)bVar1;
  local_8 = 2;
  local_44 = this;
  if (bVar1) {
    uVar4 = 0;
    FUN_45402c5d((int *)&local_34);
  }
  pvVar2 = (void *)FUN_454298b4(0x24);
  local_8._0_1_ = 6;
  if (pvVar2 != (void *)0x0) {
    FUN_45402a65(&local_34,"Generic");
    local_8 = CONCAT31(local_8._1_3_,7);
    local_3c = uVar4 | 2;
    piVar3 = FUN_45415539(this,(int *)&local_48);
    local_8 = 8;
    uVar4 = uVar4 | 6;
    local_3c = uVar4;
    FUN_45412b31(pvVar2,(int *)&local_34,piVar3,&local_38);
  }
  local_8 = 9;
  if (((uVar4 & 4) != 0) && (uVar4 = uVar4 & 0xfffffffb, local_3c = uVar4, local_48 != (int *)0x0))
  {
    (**(code **)(*local_48 + 8))(local_48);
  }
  local_8 = 2;
  if ((uVar4 & 2) != 0) {
    FUN_45402c5d((int *)&local_34);
  }
  FUN_45413356((int)this);
  FUN_4542273a(local_40,&local_44);
  FUN_45402c5d(&local_38);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  FUN_4541e261();
  return;
}


