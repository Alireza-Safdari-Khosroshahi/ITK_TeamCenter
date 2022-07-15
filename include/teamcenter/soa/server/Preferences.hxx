/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */
#ifndef INCLUDE_TEAMCENTER_SOA_SERVER_PREFERENCES_HXX
#define INCLUDE_TEAMCENTER_SOA_SERVER_PREFERENCES_HXX

#include <string>
#include <map>
#include <tc/preferences.h>

#include <teamcenter/schemas/soa/_2006_03/base/Preferences.hxx>
#include <teamcenter/soa/common/xml/SaxToNodeParser.hxx>
#include <teamcenter/soa/common/xml/XmlUtils.hxx>
#include <teamcenter/soa/common/AutoPtr.hxx>
#include <teamcenter/soa/server/SoaServerExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Server
        {

/**
 * The Preferences type is used to return preferences from a service.
 */
class  TCSOASERVER_API Preferences
{
public:

    Preferences():m_wirePreferences( new Teamcenter::Schemas::Soa::_2006_03::Base::Preferences() ){};


   /**
     * Constructor for a single preference entry.
     * Uses the PREF_ask_char_values function to retrieve the
     * preferences from the database.
     *
     * @param name    Preference name
     * @param scope   Search scope

     * @throws ServiceException    If the PREF_ask_char_values funtion throws
     *                            an IFail exception for any other reason than PF_NOTFOUND
     */
    Preferences  ( const std::string& name, TC_preference_search_scope_t scope );
    Preferences( const Preferences& right);
    Preferences& operator = ( const Preferences& right);
   ~Preferences();

   /**
     * Constructor for a multiple preference entries.
     * Uses the PREF_ask_char_values function to retrieve the
     * preferences from the database.
     *
     * @param names    Preference names
     * @param scope   Search scope

     * @throws ServiceException   If the PREF_ask_char_values funtion throws
     *                            an IFail exception for any other reason than PF_NOTFOUND
     */
    Preferences  (const std::vector<std::string>& names, TC_preference_search_scope_t scope);



    void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out ) const;
    void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Preferences>& getWireData()const { return m_wirePreferences;}

    void        addPreference ( const std::string& name, TC_preference_search_scope_t scope );

private:

    bool        doesExist     ( const std::string& name)const ;

    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::Preferences>        m_wirePreferences;
};        // End Class


}}}     // End Namespace

#include <teamcenter/soa/server/SoaServerUndef.h>
#endif
