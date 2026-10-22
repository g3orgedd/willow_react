// Source: CiffHelper.dll @ 4080ebfe; FUN_4080ebfe

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_4080ebfe(void *this,DOUBLE param_1)

{
  LPCWSTR pWVar1;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xa8) = 0;
  *(DOUBLE *)((int)this + 0xb0) = param_1;
  *(undefined4 *)((int)this + 0xb8) = 0;
  FUN_4082db06((int)this + 0x15c,0x18,0xc,&LAB_408086b7);
  FUN_4082db06((int)this + 0x27c,0x18,0x18,&LAB_408086b7);
  FUN_4082db06((int)this + 0x4bc,0x18,7,&LAB_408086b7);
  FUN_4082db06((int)this + 0x564,0x18,0x1f,&LAB_408086b7);
  FUN_4082db06((int)this + 0x84c,0x18,0x35,&LAB_408086b7);
  FUN_4082db06((int)this + 0xd44,0x18,10,&LAB_408086b7);
  pWVar1 = L"䗆ৼＳ캋뺉Ꮤ";
  FUN_4082db06((int)this + 0xe34,0x18,0x3c,&LAB_408086b7);
  *(undefined4 *)((int)this + 0x13d4) = 0;
  FUN_4082b8e2((int)this);
  *(undefined4 *)((int)this + 0x150) = 0;
  basic_string<>(&stack0xffffffc0,(undefined8 *)&stack0x0000000c);
  FUN_4082921e(this,pWVar1);
  FUN_408112da(this,param_1);
  FUN_4082bda3(this);
  FUN_4080653d(&stack0x0000000c,'\x01',0);
  return this;
}


