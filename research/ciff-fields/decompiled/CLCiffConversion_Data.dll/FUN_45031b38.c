// Source: CLCiffConversion_Data.dll @ 45031b38; FUN_45031b38

undefined4 FUN_45031b38(void)

{
  uint _SizeInBytes;
  char cVar1;
  size_t sVar2;
  char *_Dst;
  errno_t eVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  
  if (DAT_45056f94 == 0) {
    FUN_450270a6();
  }
  iVar5 = 0;
  pcVar4 = DAT_4505535c;
  if (DAT_4505535c != (char *)0x0) {
    for (; *pcVar4 != '\0'; pcVar4 = pcVar4 + sVar2 + 1) {
      if (*pcVar4 != '=') {
        iVar5 = iVar5 + 1;
      }
      sVar2 = _strlen(pcVar4);
    }
    DAT_450553b4 = FUN_4502dee1(iVar5 + 1,4);
    if (DAT_450553b4 != (undefined4 *)0x0) {
      cVar1 = *DAT_4505535c;
      puVar6 = DAT_450553b4;
      pcVar4 = DAT_4505535c;
      do {
        if (cVar1 == '\0') {
          FID_conflict__free(DAT_4505535c);
          DAT_4505535c = (char *)0x0;
          *puVar6 = 0;
          DAT_45056f98 = 1;
          return 0;
        }
        sVar2 = _strlen(pcVar4);
        _SizeInBytes = sVar2 + 1;
        if (*pcVar4 != '=') {
          _Dst = FUN_4502dee1(_SizeInBytes,1);
          *puVar6 = _Dst;
          if (_Dst == (char *)0x0) {
            FID_conflict__free(DAT_450553b4);
            DAT_450553b4 = (undefined4 *)0x0;
            return 0xffffffff;
          }
          eVar3 = _strcpy_s(_Dst,_SizeInBytes,pcVar4);
          if (eVar3 != 0) {
                    /* WARNING: Subroutine does not return */
            __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
          }
          puVar6 = puVar6 + 1;
        }
        pcVar4 = pcVar4 + _SizeInBytes;
        cVar1 = *pcVar4;
      } while( true );
    }
  }
  return 0xffffffff;
}


