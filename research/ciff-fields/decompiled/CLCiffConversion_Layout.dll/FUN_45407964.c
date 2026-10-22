// Source: CLCiffConversion_Layout.dll @ 45407964; FUN_45407964

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_45407964(void *param_1)

{
  LSTATUS LVar1;
  undefined *puVar2;
  DWORD local_88 [2];
  HKEY local_80;
  undefined *local_7c;
  BYTE local_78;
  uint local_77 [27];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar2 = PTR_DAT_4545d110;
  uStack_4 = 0x7c;
  local_7c = PTR_DAT_4545d110;
  local_8 = 0;
  LVar1 = RegOpenKeyExA((HKEY)0x80000001,"Software\\Claricom Ltd\\LanguageName",0,0x20019,&local_80)
  ;
  if (LVar1 == 0) {
    local_78 = '\0';
    FUN_45429f70(local_77,0,99);
    local_88[0] = 100;
    local_88[1] = 1;
    LVar1 = RegQueryValueExA(local_80,"LanguageName",(LPDWORD)0x0,local_88 + 1,&local_78,local_88);
    if (LVar1 == 0) {
      FUN_45402cd0(&local_7c,(LPCSTR)&local_78);
      puVar2 = local_7c;
    }
  }
  else {
    LVar1 = RegCreateKeyExA((HKEY)0x80000001,"Software\\Claricom Ltd\\LanguageName",0,(LPSTR)0x0,0,
                            0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_80,local_88 + 1);
    if (LVar1 != 0) goto LAB_45407a29;
  }
  RegCloseKey(local_80);
LAB_45407a29:
  if (*(int *)(puVar2 + -8) == 0) {
    FUN_4540791f(param_1);
  }
  else {
    FUN_45402a2f(param_1,(int *)&local_7c);
  }
  FUN_45402c5d((int *)&local_7c);
  FUN_4542a957();
  return;
}


