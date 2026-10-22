// Source: CLCiffConversion_Layout.dll @ 45426bee; FUN_45426bee

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_45426bee(void *this,char *param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  HKEY pv;
  int iVar3;
  HKEY local_100c;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  local_100c = (HKEY)0x0;
  iVar3 = FUN_45426892(this,param_1,(int *)&local_100c);
  pv = local_100c;
  if (iVar3 < 0) {
LAB_45426d1e:
    FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(HKEY *)this = local_100c;
  cVar1 = (char)local_100c->unused;
joined_r0x45426c38:
  if ((((cVar1 == '\0') || (iVar3 = FUN_45426781(this,local_1008), iVar3 < 0)) ||
      (local_100c = (HKEY)FUN_45426231(local_1008), local_100c == (HKEY)0x0)) ||
     ((iVar3 = FUN_45426781(this,local_1008), iVar3 < 0 || (local_1008[0] != '{'))))
  goto LAB_45426d14;
  if (param_2 == 0) {
    iVar3 = FUN_45427024(this,(LPCWSTR)local_1008,local_100c,0,0);
    if (iVar3 < 0) goto LAB_45426d14;
  }
  else {
    uVar2 = *(undefined4 *)this;
    iVar3 = FUN_45427024(this,(LPCWSTR)local_1008,local_100c,param_2,0);
    if (iVar3 < 0) {
      *(undefined4 *)this = uVar2;
      FUN_45427024(this,(LPCWSTR)local_1008,local_100c,0,0);
LAB_45426d14:
      CoTaskMemFree(pv);
      goto LAB_45426d1e;
    }
  }
  FUN_45427bf6(this);
  cVar1 = **(char **)this;
  goto joined_r0x45426c38;
}


