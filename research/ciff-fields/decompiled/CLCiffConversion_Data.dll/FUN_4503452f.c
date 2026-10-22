// Source: CLCiffConversion_Data.dll @ 4503452f; FUN_4503452f

void __cdecl
FUN_4503452f(undefined4 param_1,undefined4 param_2,int *param_3,char *param_4,rsize_t param_5)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  errno_t eVar4;
  uint local_34;
  uint uStack_30;
  ushort uStack_2c;
  char *local_28;
  short local_24;
  char local_22;
  char local_20 [24];
  uint local_8;
  
  piVar1 = param_3;
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_28 = param_4;
  FUN_45034467(&local_34,&param_1);
  iVar3 = FUN_45036ab4(local_34,uStack_30,uStack_2c,0x11,0,&local_24);
  pcVar2 = local_28;
  piVar1[2] = iVar3;
  *piVar1 = (int)local_22;
  piVar1[1] = (int)local_24;
  eVar4 = _strcpy_s(local_28,param_5,local_20);
  if (eVar4 == 0) {
    piVar1[3] = (int)pcVar2;
    FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
}


