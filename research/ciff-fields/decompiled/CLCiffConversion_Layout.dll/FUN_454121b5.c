// Source: CLCiffConversion_Layout.dll @ 454121b5; _Allocate<>

/* Library Function - Multiple Matches With Same Base Name
    class std::_Func_impl<struct std::_Callable_obj<class
   <lambda_399686a4a5619bf4b18c998976ba8b81>,0>,class std::allocator<class
   std::_Func_class<void,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct
   std::_Nil,struct std::_Nil,struct std::_Nil> >,void,struct std::_Nil,struct std::_Nil,struct
   std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil> * __cdecl
   std::_Allocate<class std::_Func_impl<struct std::_Callable_obj<class
   <lambda_399686a4a5619bf4b18c998976ba8b81>,0>,class std::allocator<class
   std::_Func_class<void,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct
   std::_Nil,struct std::_Nil,struct std::_Nil> >,void,struct std::_Nil,struct std::_Nil,struct
   std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil> >(unsigned
   int,class std::_Func_impl<struct std::_Callable_obj<class
   <lambda_399686a4a5619bf4b18c998976ba8b81>,0>,class std::allocator<class
   std::_Func_class<void,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct
   std::_Nil,struct std::_Nil,struct std::_Nil> >,void,struct std::_Nil,struct std::_Nil,struct
   std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil> *)
    class std::_Func_impl<struct std::_Callable_obj<class
   <lambda_61710bb2f65fa5c843243e2ef45f5091>,0>,class std::allocator<class
   std::_Func_class<void,unsigned int const &,struct std::_Nil,struct std::_Nil,struct
   std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil> >,void,unsigned int const &,struct
   std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil> *
   __cdecl std::_Allocate<class std::_Func_impl<struct std::_Callable_obj<class
   <lambda_61710bb2f65fa5c843243e2ef45f5091>,0>,class std::allocator<class
   std::_Func_class<void,unsigned int const &,struct std::_Nil,struct std::_Nil,struct
   std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil> >,void,unsigned int const &,struct
   std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil>
   >(unsigned int,class std::_Func_impl<struct std::_Callable_obj<class
   <lambda_61710bb2f65fa5c843243e2ef45f5091>,0>,class std::allocator<class
   std::_Func_class<void,unsigned int const &,struct std::_Nil,struct std::_Nil,struct
   std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil> >,void,unsigned int const &,struct
   std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil>
   *)
    class std::_Func_impl<struct std::_Callable_obj<class
   <lambda_9ab38a79c03e1e04423ad6818173354b>,0>,class std::allocator<class
   std::_Func_class<void,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct
   std::_Nil,struct std::_Nil,struct std::_Nil> >,void,struct std::_Nil,struct std::_Nil,struct
   std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil> * __cdecl
   std::_Allocate<class std::_Func_impl<struct std::_Callable_obj<class
   <lambda_9ab38a79c03e1e04423ad6818173354b>,0>,class std::allocator<class
   std::_Func_class<void,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct
   std::_Nil,struct std::_Nil,struct std::_Nil> >,void,struct std::_Nil,struct std::_Nil,struct
   std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil> >(unsigned
   int,class std::_Func_impl<struct std::_Callable_obj<class
   <lambda_9ab38a79c03e1e04423ad6818173354b>,0>,class std::allocator<class
   std::_Func_class<void,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct
   std::_Nil,struct std::_Nil,struct std::_Nil> >,void,struct std::_Nil,struct std::_Nil,struct
   std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil,struct std::_Nil> *)
   
   Library: Visual Studio 2012 Release */

int __cdecl _Allocate<>(uint param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  if ((param_1 < 0xccccccd) && (iVar1 = FUN_454298b4(param_1 * 0x14), iVar1 != 0)) {
    return iVar1;
  }
  iVar1 = FUN_45429455();
  return iVar1;
}


