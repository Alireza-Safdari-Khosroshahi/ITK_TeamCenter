//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2013
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef INCLUDE_TEAMCENTER_SOA_SERVER_SERVICEDATA_HXX
#define INCLUDE_TEAMCENTER_SOA_SERVER_SERVICEDATA_HXX

#include <string>
#include <map>
#include <set>
#include <iostream>
#include <sstream>

#include <teamcenter/soa/server/PartialErrors.hxx>

#include <teamcenter/soa/common/PolicyType.hxx>
#include <teamcenter/soa/common/AutoPtr.hxx>
#include <teamcenter/soa/common/PolicyProperty.hxx>
#include <teamcenter/soa/common/xml/SaxToNodeParser.hxx>
#include <teamcenter/soa/common/AutoPtr.hxx>
#include <teamcenter/soa/common/xml/XmlUtils.hxx>
#include <teamcenter/soa/common/Version.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/ServiceData.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/ModelObject.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/RefId.hxx>

//#include <tc/eimobject.hxx>
//#include <pom/eim/eim.h>
//#include <pom/eim/eim_dm.h>
#include <base_utils/IFail.hxx>
#include <metaframework/BusinessObjectRef.hxx>

#include <teamcenter/soa/server/SoaServerExports.h>

using std::vector;
using std::string;

#define IS_BOMELINE( _TYPE_ )    _TYPE_ == "BOMLine" || _TYPE_ == "ACTLine"


namespace Teamcenter{ namespace Soa { namespace Core { namespace _2010_04 { class DataManagementImpl; } } } }
namespace Teamcenter{ namespace Soa { namespace Internal { namespace Server { class Utils; } } } }
class EIMObject;
class PropertyDescriptor;


namespace Teamcenter
{
    namespace Property
    {
        class BulkPropertyContext;
        class PropertyValueMatrix;
    }

    namespace Soa
    {
        namespace Server
        {
            class ServiceDataHelper;
/**
 * This is a common data strucuture used to return sets of Teamcenter Data Model
 * object from a service request. This structure holds lists Data
 * Model objects that were 'created', 'deleted', 'updated' or 'plain' in the database
 * with this service request. 'Plain' objects are simply objects that the service is
 * returning where no changes have been made to the database object, i.e. GetHomeFolder
 * returns a list of objects that are contained in the user's home folder.
 */
class TCSOASERVER_API ServiceData : public Teamcenter::Soa::Server::PartialErrors
{
public:

   /* When calling addErrorStack from DerivedClass pointer compiler cant see this
    * overload.The "problem" is called "name hiding". It can be "solved" with the help
    * of 'using' declaration in DerivedClass:
    */
    using Teamcenter::Soa::Server::PartialErrors::addErrorStack;

    static void setRefreshPOM( bool refresh );
    static bool getRefreshPOM();
    static int  getBaseSchemaVersion();
    static void setBaseSchemaVersion(int baseSchemaVersion);
    static void enablePaging( bool enable );
    static bool isPagingEnabled();
    static void combineBomProperties( bool refresh );
    static bool combineBomProperties();

    ServiceData();
    ServiceData( const ServiceData& right);
    ServiceData& operator = ( const ServiceData& right);

    ~ServiceData();

    /**
     * Add a 'created' object.
     *
     * @param obj    The object to add
     */
    void addCreatedObject ( const BusinessObjectRef<Teamcenter::BusinessObject> obj );
    /**
     * Add a set of 'created' objects.
     *
     * @param objs    The objects to add
     */
    void addCreatedObjects( const std::vector< BusinessObjectRef<Teamcenter::BusinessObject> >& objs );

   /**
     * Add a 'deleted' object.
     *
     * @param uid    The uid of the object to add
     */
    void addDeletedObject ( const std::string& uid );

    /**
     * Add a set of 'deleted' objects.
     *
     * @param uids    The uids of the objects to add
     */
    void addDeletedObjects( const std::vector<std::string>& uids );



   /**
     * Add an 'updated' object.
     *
     * @param obj    The object to add
     * @deprecated   As of 9.0, use the addUpdatedObject( obj, propNames ) method to specfiy
     *               the exact properties that have been updated.
     */
#ifdef WNT
__declspec(deprecated("As of 9.0, use the addUpdatedObject( obj, propNames ) method to specfiy the exact properties that have been updated."))
#endif
    void addUpdatedObject ( const BusinessObjectRef<Teamcenter::BusinessObject> obj );
    /**
     * Add a set of 'updated' objects.
     *
     * @param objs    The objects to add
     * @deprecated    As of 9.0, use the addUpdatedObjects( objs, propNames ) method to specfiy
     *                the exact properties that have been updated
     */
#ifdef WNT
__declspec(deprecated("As of 9.0, use the addUpdatedObjects( objs, propNames ) method to specfiy the exact properties that have been updated."))
#endif
    void addUpdatedObjects( const std::vector< BusinessObjectRef<Teamcenter::BusinessObject> >& objs );

    /**
     * Add an 'updated' objects.
     *
     * @param obj                The object to add
     * @param propNames          The names of the properties that have been updated.
     */
    void addUpdatedObject( const BusinessObjectRef<Teamcenter::BusinessObject> obj, const std::set<std::string>& propNames);



   /**
     * Add a 'plain' object.
     *
     * @param obj    The object to add
     */
    void addPlainObject   ( const BusinessObjectRef<Teamcenter::BusinessObject> obj );
    /**
     * Add a set of 'plain' objects.
     *
     * @param objs    The objects to add
     */
    void addPlainObjects  ( const std::vector< BusinessObjectRef<Teamcenter::BusinessObject> >& objs );


    /**
     * Add an object.
     * This object will not be included in the 'created', 'updated', 'deleted' or plain slots.
     * This is typically used for referenced or secondary objects.
     *
     * @param obj    The object to add
     */
    void addObject    ( const BusinessObjectRef<Teamcenter::BusinessObject> obj );


    /**
     * Add a set of objects.
     * These objects will not be included in the 'created', 'updated', 'deleted' or plain slots.
     * This is typically used for referenced or secondary objects.
     *
     * @param objs    The objects to add
     */
    void addObjects   ( const std::vector< BusinessObjectRef<Teamcenter::BusinessObject> >& objs );

    /**
     * Add value for the named property.
     * This assumes that the object has already been added (addObject, addPlainObject .etc).
     * If the Object does not exist in the ServiceData, either because it has not been previously added
     * or if there were errors in adding it ( READ permissions .etc), this method will do nothing.
     *
     * @param obj          The objects to add a property value to
     * @param propertyName The name of the property to add
     */
    void addProperty  ( const BusinessObjectRef<Teamcenter::BusinessObject> obj, const std::string& propertyName   );

    /**
     * Add values for the named properties.
     * This assumes that the object has already been added (addObject, addPlainObject .etc).
     * If the Object does not exist in the ServiceData, either because it has not been previously added
     * or if there were errors in adding it ( READ permissions .etc), this method will do nothing.
     *
     * @param obj          The objects to add a property value to
     * @param propNames    The names of the properties to add
     */
    void addProperties( const BusinessObjectRef<Teamcenter::BusinessObject> obj, const std::set<std::string>& propNames );

    /**
     * Add values for the named properties.
     * This assumes that the objects has already been added (addObject, addPlainObject .etc).
     * If the Object does not exist in the ServiceData, either because it has not been previously added
     * or if there were errors in adding it ( READ permissions .etc), this method will do nothing.
     *
     * @param objects      The collection of objects to add property values to
     * @param propNames    The names of the properties to add
     */
    void addProperties( const vector< BusinessObjectRef<Teamcenter::BusinessObject> > &objects, const std::set< std::string >& propNames );



    /**
     * Add an object to the error stack.
     *
     * @param obj The object to add
     */
      virtual  void addErrorStack  ( const BusinessObjectRef<Teamcenter::BusinessObject> obj );

    /**
     * Add a tag of  object to the service data with  given error to the store.
     * After this error is added ERROR_store_ask and ERROR_store_clear utilities
     * are used to get the full stack and clear it.
     *
     * @param obj       Object to be associated with this stack
     * @param severity  The severity of the error, must be one of
     *                  ERROR_severity_information
     *                  ERROR_severity_warning
     *                  ERROR_severity_error
     *                  ERROR_severity_user_error
     * @param ifail     Error code
     * @param s1        Substituted into the translated string,
     *                  where %n$s in the string gives the 1st argument to substitute
     *                 (XPG3 printf) if ifail is zero then the first string is
     *                  taken as the total error message.
     * @param s2        Substituted into the translated string,
     *                  where %n$s in the string gives the 2nd argument to substitute.
     * @param s3        Substituted into the translated string,
     *                  where %n$s in the string gives the 3rd argument to substitute.
     * @param s4        Substituted into the translated string,
     *                  where %n$s in the string gives the 4th argument to substitute.
     * @param s5        Substituted into the translated string,
     *                  where %n$s in the string gives the 5th argument to substitute.
     * @param s6        Substituted into the translated string,
     *                  where %n$s in the string gives the 6th argument to substitute.
     * @param s7        Substituted into the translated string,
     *                  taken as the total error message
     */
    virtual void addErrorStack( const BusinessObjectRef<Teamcenter::BusinessObject> obj, ERROR_severity_t severity, int ifail,
                const char *s1=0, const char *s2=0, const char *s3=0,
                const char *s4=0, const char *s5=0, const char *s6=0, const char *s7=0);



    /**
     * Individual service operation implemenations may override the affect of the
     * refreshPOMCachePerReqeust flag set by the Session::refreshPOMCachePerRequest
     * service operation. If the refreshPOMCachePerReqeust flag is true and this method is called,
     * the Object Property Policy Manager will revert to the default behaviour and pull
     * property values from the POM without doing a refresh. Calling this method when
     * the refreshPOMCachePerReqeust is false has no affect.
     *
     * To have an affect this method must be called before adding any objects with the
     * addPlainObject or addPlainObjects methods.
     *
     */
    void refreshPOMCacheOverride ();

    /**
     * When property values are fetched priory to enforcement of the Object Property Policy, the properties that reference
     * other objects (contents property of the Folder type) will load those referenced objects into the ServiceData and
     * in turn the Object Property Policy will be applied to those referenced objects.
     * This applies to the addUpdatedObject and addProperty methods when called from the service implemenation.
     * By setting the exclude flag to 'true', referenced objects added indirectly via the addUpdateObjects or addProperty methods
     * will be excluded from the Object Property Policy processing. The default for ServiceData is to include
     * these referenced objects in the Object Property Policy processing (exclude=false)
     *
     * This is independant of referenced objects added as a result of Object Property Policy processing, there
     * the 'withProperties' flag in the policy determines if referenced objects will be returned with property data.
     *
     * @param exclude   If set to true excluce referenced objects from the Object Property Policy proccessing
     */
    void excludeReferencedPoperties( bool exclude );

    /**
     * If set to true, the BOM Events from the PSEBulletinBoard will NOT
     * be included in the ServiceData for the current service opeation.
     * By default the BOM Events are included in the ServiceData.
     *
     * @param flag Set to true to skip the processing of the PSEBulletinBoard
     */
    void setIgnoreBOMEvents( bool flag );

    /**
     * If set to true, the Model Events from the ImanTypeImplPublic will NOT
     * be included in the ServiceData for the current service opeation.
     * By default the Model Events are included in the ServiceData.
     *
     * @param flag Set to true to skip the processing of the ImanTypeImplPublic
     */
    void setIgnoreIMANEvents( bool flag );
 
    /**
     * Returns the current state ofthe Ignore BOM Events flag.
     */
    bool isIgnoreBOMEvents() const;
    /**
     * Returns the current state ofthe Ignore IMAN Events flag.
     */
    bool isIgnoreIMANEvents() const;




    // These are public but should only be used by the Skeletons
    const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ServiceData>& getWireData();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelObject> createWireModelObect ( const BusinessObjectRef<Teamcenter::BusinessObject> obj );
    void outputXML( Teamcenter::Soa::Common::Xml::XmlStream& out);
    void parse    ( const Teamcenter::Soa::Common::Xml::XMLNode& node );
    void inflateProperties(  );
    void getNotifications ( );
    void getBOMEvents     ( );



    friend class ServiceDataHelper;

private:
    friend class Teamcenter::Soa::Core::_2010_04::DataManagementImpl; // Access to the private addUpdatedObject
    friend class Teamcenter::Soa::Internal::Server::Utils;

    static  bool        s_refreshPOM;
    static  bool        s_enablePaging;
    static  int         s_baseSchemaVersion;
    static  int         s_maxSoaProperties;
    static  int         s_maxWsdlProperties;
    static  bool        s_combineBomProperties;
    static const char * TC_SOA_MAX_PROPERTIES;
    static const char * TC_WSDL_MAX_PROPERTIES;
    static Teamcenter::Soa::Common::Version s_v1000;
    static Teamcenter::Soa::Common::Version s_v0830;
    static Teamcenter::Soa::Common::Version s_v0820;

    typedef std::map< std::string, Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelObject> >  UidObjectMap;
    typedef std::set< std::string >        UidSet;
    typedef std::map< BusinessObjectRef<Teamcenter::BusinessObject>, std::string  >  TagUidMap;
    typedef std::map< std::string, BusinessObjectRef<Teamcenter::BusinessObject>  >  UidTagMap;




    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ServiceData>        m_wireServiceData;
    TagUidMap  m_objectMap; // keep track of which objs have been added
    UidTagMap  m_UidMap;    // keep track of which objs have been added

    // Store data in Maps for random access, then move to wire ServiceData(vectors) for serialization
    // This solves a memory leak when accessing/growing the data in vectors(m_wireServiceData). Gave up
    // on finding what exactly cause the leak, but growing the data in maps vs. vectors seems to have
    // removed this leak. There are a couple of places that benifit from random access of the data,
    // service implemenations adding property values, and Child Change events
    UidSet          m_createdSet;
    UidSet          m_deletedSet;
    UidSet          m_updatedSet;
    UidSet          m_childSet;
    UidSet          m_plainSet;
    UidObjectMap    m_dataObjectMap;
    std::vector<std::string> orderedObjects;
    std::set< std::string>   excludedObjects;

    bool        m_refreshOverride;
    bool        m_trackExcludedObjs;
    bool        m_ignoreBOMEvents;
    bool        m_ignoreIMANEvents;
    Teamcenter::Soa::Common::Version m_clientVersion;

    // The number of properties is the biggest contributor to the size of the response payload
    // So we will limit the total number of properties returned and return a Partial Error when
    // this is reached. The SOA Client framework is looking for this error and will send a
    // DMService.getProperties to return data for the items missed in this call. This can
    // be a recursive process, but will slowly eat away at the original Tag list.
    int         m_totalProps;


    enum GroupType
    {
        PLAIN_GROUP,
        CREATED_GROUP,
        DELETED_GROUP,
        UPDATED_GROUP,
        CHILD_CHANGE_GROUP
    };

    enum AddPropCaller
    {
        APPLY_POLICY,
        APPLY_POLICY_REFERENCED_OBJS,
        MODEL_EVENT,
        ADD_UPDATED_OBJ,
        ADD_PROPERTY,
        ADD_PROPERTY_MIXED_TYPES
    };

    /**
     * Add an 'updated' objects.
     * This is a work-around for the DMService.setLocalizedProperties when called from RAC does not
     * need the Child Change Events
     *
     * @param obj                The object to add
     * @param propNames          The names of the properties that have been updated.
     * @param includeChildChange If set to true (default if argument is not supplied) will add the object
     *                           to the ChildChange list if othe object and modified properties qualify.
     *                           Currently the ChildChange list of objects is only returned to RAC clients.
     *                           An object is deemed to be a ChildChange if any of the input property names, 'propNames'
     *                           match the names defined in the <type>_DefaultChildProperties preference.
     */
    void addUpdatedObject( const BusinessObjectRef<Teamcenter::BusinessObject> obj, const std::set<std::string>& propNames, bool includeChildChange );

    // Methods to access to Tag/UID data 
    bool    isUidPresent     ( const std::string& uid, const GroupType group );
    bool    isObjectPresent  ( const BusinessObjectRef<Teamcenter::BusinessObject> obj ) const;
    bool    isObjectPresent  ( const std::string& uid ) const;
    std::string  getObjectUid( const BusinessObjectRef<Teamcenter::BusinessObject> obj ) const;
    const BusinessObjectRef<Teamcenter::BusinessObject>    getObjectTag( const std::string& uid ) const;

    // Get Property Name lists
    bool    hasChildProperty ( const std::string& typeName, const std::string& className,  const Teamcenter::Soa::Common::PolicyType& propsNames ) const;
    void    getUpdatePropertyNames( const BusinessObjectRef<Teamcenter::BusinessObject> obj, std::set< std::string >& names ) const;
    void    getNewProperties ( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ModelObject>& wireObj, const std::set< std::string >& propNames, Teamcenter::Soa::Common::PolicyType& dummy) const;
  
    void    aomLoadInstance  ( const std::vector<std::string>& uids, std::vector<tag_t>& justLoaded );
    void    refreshObject    ( const BusinessObjectRef<Teamcenter::BusinessObject> obj ) const;
    void    refreshObjects   ( UidSet& refreshObjSet  );

    // Low level methods to add a BO to the ServiceData
    void    addObjectWithoutPartialError( const BusinessObjectRef<Teamcenter::BusinessObject> obj );
    void    addObjectToGroup ( const BusinessObjectRef<Teamcenter::BusinessObject> obj,   const GroupType group  );
    void    addObjectsToGroup( const std::vector< BusinessObjectRef<Teamcenter::BusinessObject> >& objs, const GroupType group  ); 
    void    addUpdatedObjectsAndProperties( const std::vector< BusinessObjectRef<Teamcenter::BusinessObject> >  objs,
                                     const std::vector<  std::set<std::string> >& propNames,
                                     bool includeChildChange, AddPropCaller addPropCaller );

    void    removeObjectFromGroup( const BusinessObjectRef<Teamcenter::BusinessObject>& obj, const GroupType group  );
    void    removeObjectFromLists( const BusinessObjectRef<Teamcenter::BusinessObject>& tObj);

 


};        // End Class
}}}       // End Namespace

#include <teamcenter/soa/server/SoaServerUndef.h>
#endif

