// Source: CLARiSOFT.exe @ 00e0e9da; FUN_00e0e9da

bool __thiscall FUN_00e0e9da(void *this,LPVARIANT param_1)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = true;
  if ((*(VARTYPE *)this != 1) || ((param_1->n1).n2.vt != 1)) {
    if (*(VARTYPE *)this == (param_1->n1).n2.vt) {
      uVar1 = FUN_00e11044(this,this,param_1,0x400,0);
      bVar2 = uVar1 == 1;
    }
    else {
      bVar2 = false;
    }
  }
  return bVar2;
}


