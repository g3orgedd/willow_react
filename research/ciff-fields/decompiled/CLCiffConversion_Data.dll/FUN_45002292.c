// Source: CLCiffConversion_Data.dll @ 45002292; _com_error::~_com_error

/* Library Function - Single Match
    public: virtual __thiscall _com_error::~_com_error(void)
   
   Library: Visual Studio 2012 Release */

void __thiscall _com_error::~_com_error(_com_error *this)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 8);
  *(undefined ***)this = vftable;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if (*(int *)(this + 0xc) != 0) {
    LocalFree(*(HLOCAL *)(this + 0xc));
  }
  return;
}


