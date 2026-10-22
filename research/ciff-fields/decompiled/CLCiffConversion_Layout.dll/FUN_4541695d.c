// Source: CLCiffConversion_Layout.dll @ 4541695d; FUN_4541695d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4541695d(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *local_34;
  undefined4 local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x45416969;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFCull::Convert(CCIFFField*)");
  local_8 = 0;
  FUN_4540303d(0x454491ec);
  local_30 = 0;
  local_34 = (undefined4 *)FUN_454043b0((int *)0x0,(int *)0x0);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_45404ce5((void *)((int)this + *(int *)(*(int *)((int)this + -8) + 4) + 0x58),param_1 + 1);
  FUN_4541c9f1(param_1,&local_34);
  puVar3 = local_34;
  for (puVar4 = (undefined4 *)*local_34; puVar4 != puVar3; puVar4 = (undefined4 *)*puVar4) {
    (**(code **)(*(int *)((int)this + *(int *)(*(int *)((int)this + -8) + 4) + -8) + 0xc))
              (puVar4[2]);
  }
  FUN_454120f3((int *)&local_34);
  iVar1 = *(int *)(*(int *)((int)this + -8) + 4);
  piVar2 = *(int **)(iVar1 + 0x58 + (int)this);
  if ((piVar2 != (int *)0x0) &&
     (*(undefined4 *)(iVar1 + 0x58 + (int)this) = 0, piVar2 != (int *)0x0)) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  FUN_454224ff((int *)&local_34);
  FID_conflict__free(local_34);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


