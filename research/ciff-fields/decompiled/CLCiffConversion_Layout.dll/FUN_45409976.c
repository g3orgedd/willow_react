// Source: CLCiffConversion_Layout.dll @ 45409976; CMFCRibbonInfo::XQAT::XQATItem::operator=

/* Library Function - Single Match
    public: class CMFCRibbonInfo::XQAT::XQATItem & __thiscall
   CMFCRibbonInfo::XQAT::XQATItem::operator=(class CMFCRibbonInfo::XQAT::XQATItem const &)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

XQATItem * __thiscall CMFCRibbonInfo::XQAT::XQATItem::operator=(XQATItem *this,XQATItem *param_1)

{
  FUN_4540288a(this,(int *)param_1);
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  return this;
}


