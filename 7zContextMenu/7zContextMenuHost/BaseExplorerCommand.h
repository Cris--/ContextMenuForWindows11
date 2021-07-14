#pragma once
#include <wrl/module.h>
#include <wrl/implements.h>
#include <wrl/client.h>
#include <shobjidl_core.h>
#include <wil\resource.h>
#include <string>
#include <vector>
#include <sstream>
#include <shellapi.h>
#include <filesystem>
using namespace Microsoft::WRL;
class BaseExplorerCommand : public RuntimeClass<RuntimeClassFlags<ClassicCom>, IExplorerCommand, IObjectWithSite>
{
public:
     const virtual wchar_t* Title() =0;
     const virtual EXPCMDFLAGS Flags();
     const virtual EXPCMDSTATE State(_In_opt_ IShellItemArray* selection);

     IFACEMETHODIMP GetTitle(_In_opt_ IShellItemArray* items, _Outptr_result_nullonfailure_ PWSTR* name);
  
     IFACEMETHODIMP GetIcon(_In_opt_ IShellItemArray*, _Outptr_result_nullonfailure_ PWSTR* icon);
     IFACEMETHODIMP GetToolTip(_In_opt_ IShellItemArray*, _Outptr_result_nullonfailure_ PWSTR* infoTip);
     IFACEMETHODIMP GetCanonicalName(_Out_ GUID* guidCommandName);
     IFACEMETHODIMP GetState(_In_opt_ IShellItemArray* selection, _In_ BOOL okToBeSlow, _Out_ EXPCMDSTATE* cmdState);
    
     IFACEMETHODIMP Invoke(_In_opt_ IShellItemArray* selection, _In_opt_ IBindCtx*) noexcept = 0;
    
     IFACEMETHODIMP GetFlags(_Out_ EXPCMDFLAGS* flags);
     IFACEMETHODIMP EnumSubCommands(_COM_Outptr_ IEnumExplorerCommand** enumCommands);

 
     IFACEMETHODIMP SetSite(_In_ IUnknown* site) noexcept;
     IFACEMETHODIMP GetSite(_In_ REFIID riid, _COM_Outptr_ void** site) noexcept;
protected:
    ComPtr<IUnknown> m_site;
};