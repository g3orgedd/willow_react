// Source: CLCiffConversion_Layout.dll @ 4540ee71; FUN_4540ee71

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_4540ee71(void *this,DOUBLE param_1)

{
  wchar_t *pwVar1;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xa8) = 0;
  *(DOUBLE *)((int)this + 0xb0) = param_1;
  *(undefined4 *)((int)this + 0xb8) = 0;
  FUN_4542cebb((int)this + 0x15c,0x18,0xc,&LAB_45407598);
  FUN_4542cebb((int)this + 0x27c,0x18,0x18,&LAB_45407598);
  FUN_4542cebb((int)this + 0x4bc,0x18,7,&LAB_45407598);
  FUN_4542cebb((int)this + 0x564,0x18,0x1f,&LAB_45407598);
  FUN_4542cebb((int)this + 0x84c,0x18,0x35,&LAB_45407598);
  FUN_4542cebb((int)this + 0xd44,0x18,10,&LAB_45407598);
  pwVar1 = L"䗆ৼＳ캋뺉Ꮤ";
  FUN_4542cebb((int)this + 0xe34,0x18,0x3c,&LAB_45407598);
  *(undefined4 *)((int)this + 0x13d4) = 0;
  FUN_45410c3f((int)this);
  *(undefined4 *)((int)this + 0x150) = 0;
  basic_string<>(&stack0xffffffc0,(undefined8 *)&stack0x0000000c);
  FUN_45409e22(this,pwVar1);
  FUN_4540f611(this,param_1);
  FUN_45411100(this);
  FUN_4540460c(&stack0x0000000c,'\x01',0);
  return this;
}


