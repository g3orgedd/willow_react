// Source: CLCiffConversion_Layout.dll @ 4543fcd3; flsall

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _flsall
   
   Library: Visual Studio 2012 Release */

int __cdecl flsall(int param_1)

{
  void *_File;
  FILE *pFVar1;
  int iVar2;
  int _Index;
  int iVar3;
  int local_28;
  
  iVar3 = 0;
  local_28 = 0;
  __lock(1);
  for (_Index = 0; _Index < DAT_454626e4; _Index = _Index + 1) {
    _File = *(void **)(DAT_454626e0 + _Index * 4);
    if ((_File != (void *)0x0) && ((*(byte *)((int)_File + 0xc) & 0x83) != 0)) {
      __lock_file2(_Index,_File);
      pFVar1 = *(FILE **)(DAT_454626e0 + _Index * 4);
      if ((pFVar1->_flag & 0x83) != 0) {
        if (param_1 == 1) {
          iVar2 = FUN_4543fc20(pFVar1);
          if (iVar2 != -1) {
            iVar3 = iVar3 + 1;
          }
        }
        else if ((param_1 == 0) && ((pFVar1->_flag & 2) != 0)) {
          iVar2 = FUN_4543fc20(pFVar1);
          if (iVar2 == -1) {
            local_28 = -1;
          }
        }
      }
      FUN_4543fd7b();
    }
  }
  FUN_4543fdae();
  if (param_1 != 1) {
    iVar3 = local_28;
  }
  return iVar3;
}


