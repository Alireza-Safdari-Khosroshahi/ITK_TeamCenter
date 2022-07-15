/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/*  */
#ifndef INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_UTILS_HXX
#define INCLUDE_TEAMCENTER_SOA_INTERNAL_SERVER_UTILS_HXX

#include <string>
#include <map>

#include <teamcenter/schemas/soa/_2006_03/base/Property.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/PropertyValue.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/DisplayProperty.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/ModelObject.hxx>
#include <teamcenter/soa/server/ServiceData.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/common/PolicyProperty.hxx>
#include <teamcenter/soa/common/Version.hxx>

#include <tc/preferences.h>
#include <base_utils/DateTime.hxx>
#include <metaframework/BusinessObjectRef.hxx>

#include <teamcenter/soa/server/SoaServerExports.h>

class ImanProperty;
class PropertyDescriptor;

namespace Teamcenter
{

    namespace Soa
    {
        namespace Internal
        {
            namespace Server
            {


class  TCSOASERVER_API Utils
{
public:
    static std::string scopeToString( TC_preference_search_scope_t scope );
    static std::string tagToUid     ( tag_t tag );
    static tag_t       uidToTag     ( const std::string& uid );
    static void checkReadPermissions( BusinessObjectRef<Teamcenter::BusinessObject> object  );
    static Teamcenter::Soa::Common::DateTime createSoaDate   ( const Teamcenter::DateTime& serverDate);
    static std::vector<Teamcenter::Soa::Common::DateTime> createSoaDate( const std::vector<Teamcenter::DateTime>& serverDates );
    static Teamcenter::DateTime                              createServerDate( const Teamcenter::Soa::Common::DateTime& soaDate);
    static std::vector<Teamcenter::DateTime> createServerDate( const std::vector<Teamcenter::Soa::Common::DateTime>& soaDates );
    static void createWireModelObect ( const BusinessObjectRef<Teamcenter::BusinessObject> obj, const std::string& uid, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelObject>& wireObj );
    static void createWireModelObect ( const std::string& uid, const char* typeName, const char* className, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelObject>& wireObj  );
    static void clearImanFileStubsCache();
    


    
private:
   static Teamcenter::BusinessObjectRegistryImpl& busReg;
   static logical isRecoverableTag( tag_t aTag, bool &isPersistedRecipe );


};        // End Class
}}}}      // End Namespace

#include <teamcenter/soa/server/SoaServerUndef.h>
#endif
