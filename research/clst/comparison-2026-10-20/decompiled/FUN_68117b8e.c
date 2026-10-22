// CiffMgr.dll entry=68117b8e

undefined2 * __thiscall FUN_68117b8e(void *this,uint param_1)

{
  undefined2 uVar1;
  
  *(undefined2 *)((int)this + 0xad0) =
       *(undefined2 *)(*(int *)((int)this + 4) + ((param_1 & 0xffff) >> 0xb) * 2);
  *(undefined2 *)((int)this + 0xad2) =
       *(undefined2 *)(*(int *)((int)this + 4) + ((param_1 & 0xffff) >> 5 & 0x3f) * 2);
  uVar1 = *(undefined2 *)(*(int *)((int)this + 4) + (param_1 & 0x1f) * 2);
  *(undefined2 *)((int)this + 0xad6) = 0;
  *(undefined2 *)((int)this + 0xad4) = uVar1;
  return (undefined2 *)((int)this + 0xad0);
}


