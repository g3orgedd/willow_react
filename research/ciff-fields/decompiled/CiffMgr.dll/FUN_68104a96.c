// Source: CiffMgr.dll @ 68104a96; _Allocate<>

/* Library Function - Multiple Matches With Same Base Name
    struct std::_Container_proxy * __cdecl std::_Allocate<struct std::_Container_proxy>(unsigned
   int,struct std::_Container_proxy *)
    class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > * __cdecl
   std::_Allocate<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> >
   >(unsigned int,class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *)
    class std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned
   char,class Concurrency::details::_CancellationTokenState *> > > * __cdecl std::_Allocate<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > >(unsigned int,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *)
   
   Library: Visual Studio 2012 Release */

int __cdecl _Allocate<>(uint param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  if ((param_1 < 0x8000000) && (iVar1 = FUN_68130f46(param_1 << 5), iVar1 != 0)) {
    return iVar1;
  }
  iVar1 = FUN_68130e35();
  return iVar1;
}


