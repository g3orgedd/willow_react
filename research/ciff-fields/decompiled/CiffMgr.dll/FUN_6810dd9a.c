// Source: CiffMgr.dll @ 6810dd9a; FUN_6810dd9a

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_6810dd9a(void *this,wchar_t *param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  HKEY pHVar4;
  short *local_200c;
  WCHAR local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_68160490 ^ (uint)&stack0xfffffffc;
  local_200c = (short *)0x0;
  iVar3 = FUN_6810d8cc(this,param_1,(int *)&local_200c);
  if (iVar3 < 0) {
LAB_6810dec3:
    FUN_68132051(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(short **)this = local_200c;
  sVar1 = *local_200c;
joined_r0x6810dde5:
  if ((((sVar1 == 0) || (iVar3 = FUN_6810d73a(this,local_2008), iVar3 < 0)) ||
      (pHVar4 = (HKEY)FUN_6810d5c5(local_2008), pHVar4 == (HKEY)0x0)) ||
     ((iVar3 = FUN_6810d73a(this,local_2008), iVar3 < 0 || (local_2008[0] != L'{'))))
  goto LAB_6810deb5;
  if (param_2 == 0) {
    iVar3 = FUN_6810e0ec(this,local_2008,pHVar4,0,0);
    if (iVar3 < 0) goto LAB_6810deb5;
  }
  else {
    uVar2 = *(undefined4 *)this;
    iVar3 = FUN_6810e0ec(this,local_2008,pHVar4,param_2,0);
    if (iVar3 < 0) {
      *(undefined4 *)this = uVar2;
      FUN_6810e0ec(this,local_2008,pHVar4,0,0);
LAB_6810deb5:
      CoTaskMemFree(local_200c);
      goto LAB_6810dec3;
    }
  }
  FUN_6810e9ac(this);
  sVar1 = **(short **)this;
  goto joined_r0x6810dde5;
}


