/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/


#ifndef TEAMCENTER_SOA_CLIENT_LOCALE_HXX
#define TEAMCENTER_SOA_CLIENT_LOCALE_HXX

#include <string>
#include <vector>
#include <map>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {


class TCSOACLIENTMNGD_API LocaleMapper
{
public:

    LocaleMapper();
    std::string processLocale(const std::string& name);

    SOA_CLASS_NEW_OPERATORS
    
private:
    std::vector< std::string > localeUnix;
    std::map< std::string, std::string >  localeWindows;
    static std::string LOCALE_C;
    static std::string LOCALE_US;

    void initialize();
    std::string stringToLower(std::string curStr) const;

};

}}} //end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif


