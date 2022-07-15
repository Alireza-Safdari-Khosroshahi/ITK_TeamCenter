/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/**
    @file

    The Preferences class wraps the the XML schema classes from the wire
    and provide convienience methods to access the data in them

*/
/*  */


#ifndef TEAMCENTER_SOA_CLIENT_PREFERENCES_HXX
#define TEAMCENTER_SOA_CLIENT_PREFERENCES_HXX

#include <string>
#include <map>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>
namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

class TCSOACLIENTMNGD_API Preferences
{
public:
    Preferences(): m_preferenceMap() {};
    ~Preferences(){};

    typedef std::map< std::string, std::vector<std::string> > PreferenceMap;

    const PreferenceMap& getPreferences() const;

    bool containsPreference( const std::string& prefName );
    const std::vector<std::string>& getPreference( const std::string& prefName );

    SOA_CLASS_NEW_OPERATORS

private:
    friend class ModelManagerImpl;
    friend class DefaultObjectFactory;

    PreferenceMap m_preferenceMap;
};
}}} //end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
