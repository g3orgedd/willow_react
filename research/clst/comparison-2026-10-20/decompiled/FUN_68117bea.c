// CiffMgr.dll entry=68117bea

ushort __thiscall FUN_68117bea(void *this,ushort param_1)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)((int)this + 0xace) ^ param_1;
  FUN_68117f62(this,uVar1);
  return uVar1;
}


