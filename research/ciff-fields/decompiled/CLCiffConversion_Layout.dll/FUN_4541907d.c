// Source: CLCiffConversion_Layout.dll @ 4541907d; FUN_4541907d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4541907d(void *this,undefined4 *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float local_3c;
  int local_38;
  undefined4 *local_34;
  char local_2d;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x45419089;
  local_34 = param_1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFFontConvert::ConvertBarcode");
  local_8 = 0;
  iVar3 = 1;
  local_2d = '\0';
  piVar1 = *(int **)(*(int *)(*(int *)((int)this + 4) + 4) + 0x3c + (int)this);
  (**(code **)(*piVar1 + 0x2c))(piVar1,&local_3c);
  local_38 = 0;
  (**(code **)(*(int *)*local_34 + 0xb0))((int *)*local_34,&local_38);
  iVar5 = 0;
  cVar2 = local_2d;
  while( true ) {
    iVar4 = (int)(((double)iVar3 / (double)local_3c) * DAT_45449248);
    if (0x32 < iVar3) {
      FUN_4540500e(0x45449b58);
      cVar2 = '\x01';
    }
    if (local_38 < iVar4) break;
    iVar3 = iVar3 + 1;
    iVar5 = iVar4;
    if (cVar2 != '\0') {
LAB_4541913a:
      iVar5 = iVar4;
      if (iVar4 != 0) {
LAB_4541913e:
        (**(code **)(*(int *)*local_34 + 0xb4))((int *)*local_34,iVar5);
      }
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
      FUN_4542a957();
      return;
    }
  }
  if (iVar5 != 0) goto LAB_4541913e;
  goto LAB_4541913a;
}


