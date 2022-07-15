// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//===============================================================================
// Copyright 2008.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//===============================================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
#ifndef TEAMCENTER_SOA_COMMON_VERSION_HXX
#define TEAMCENTER_SOA_COMMON_VERSION_HXX
    
#include <new>
#include <string>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/SoaCommonExports.h>
   
namespace Teamcenter
{
    namespace Soa
    {
        namespace Common
        {
            class Version;
        }
    }
}

class TCSOACOMMON_API Teamcenter::Soa::Common::Version 
{
public:
    static std::string    getTeamcenterVersionLabel();
    static std::string    getTeamcenterVersion();  


public:
        /**
         * Major release, 2007, 8000, etc.
         */
        int    majorRelease;
        /**
         * Minor release number
         */
        int    minorRelease;
        /**
         * Maintenance Patch number
         */
        int    maintenancePatch;


       /**
        * Construct an instance of Version with the given Major, Minor, and Maintenance values.
        *
        * @param major  Major release
        * @param minor Minor release
        * @param maintenance  Maintenance Patch
        *
        */
        Version( int major, int minor, int maintenance);

       /**
        * Construct an instance of Version with from the given string.
        *
        * @param version    String form of the version
        *
        */
        explicit Version( const std::string& version);


        bool operator ==  ( const Version& right ) const;
        bool operator !=  ( const Version& right ) const;
        bool operator >   ( const Version& right ) const;
        bool operator >=  ( const Version& right ) const;
        bool operator <   ( const Version& right ) const;
        bool operator <=  ( const Version& right ) const;

  
        SOA_CLASS_NEW_OPERATORS
private:
        Version();
};

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif

