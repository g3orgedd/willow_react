// Source: CLCiffConversion_Data.dll @ 450176ba; FUN_450176ba

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_450176ba(void *this,wchar_t *param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  HKEY pHVar4;
  short *local_200c;
  WCHAR local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_200c = (short *)0x0;
  iVar3 = FUN_450171d0(this,param_1,(int *)&local_200c);
  if (iVar3 < 0) {
LAB_450177e3:
    FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(short **)this = local_200c;
  sVar1 = *local_200c;
joined_r0x45017705:
  if ((((sVar1 == 0) || (iVar3 = FUN_4501703e(this,local_2008), iVar3 < 0)) ||
      (pHVar4 = (HKEY)FUN_45016aa7(local_2008), pHVar4 == (HKEY)0x0)) ||
     ((iVar3 = FUN_4501703e(this,local_2008), iVar3 < 0 || (local_2008[0] != L'{'))))
  goto LAB_450177d5;
  if (param_2 == 0) {
    iVar3 = FUN_45017a0c(this,local_2008,pHVar4,0,0);
    if (iVar3 < 0) goto LAB_450177d5;
  }
  else {
    uVar2 = *(undefined4 *)this;
    iVar3 = FUN_45017a0c(this,local_2008,pHVar4,param_2,0);
    if (iVar3 < 0) {
      *(undefined4 *)this = uVar2;
      FUN_45017a0c(this,local_2008,pHVar4,0,0);
LAB_450177d5:
      CoTaskMemFree(local_200c);
      goto LAB_450177e3;
    }
  }
  FUN_4501834e(this);
  sVar1 = **(short **)this;
  goto joined_r0x45017705;
}


