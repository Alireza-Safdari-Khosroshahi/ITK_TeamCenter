// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_CLIENTMETAMODEL_HXX
#define TEAMCENTER_SOA_CLIENT_CLIENTMETAMODEL_HXX

#include <string>
#include <vector>
#include <map>
#include <set>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/Type.hxx>
#include <teamcenter/soa/client/LovInfo.hxx>
#include <teamcenter/soa/client/ProgressMonitor.hxx>



#include <teamcenter/soa/client/SoaClientMngdExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

            class DynamicLovInfo;
/**
 * This class is used to hold the client side version of the %Teamcenter Business Model definition (Meta Model).
 * The Meta Model information is used by the SOA Framework to properly instantiate returned
 * Business Model objects (ModelObject), and is available to the client application
 * to query for information about the Meta Model.
 *
 */
class TCSOACLIENTMNGD_API ClientMetaModel
{
public:
    virtual ~ClientMetaModel();

    /**
     * Set the formatting string for the display value of Date property values that are
     * returned from the server without a display value.
     *
     * @param format The Date format to use.
     */
    virtual void setDateDisplayFormat( const std::string& format );

   /**
     * Get the formatting string for the display value of Date property values that are
     * returned from the server without a display value.
     *
     */
    virtual std::string getDateDisplayFormat(  )const;

    /**
     * Set the precision on double property display values
     * @param precision Minimum number of places to the right of the decimal point
     */
    virtual void setDoublePrecision( int precision);

     /**
     * Get the precision on double property display values
     */
    virtual int getDoublePrecision(  ) const;
  
    /**
     * Add a ProgressMonitor to the ClientMetaModel.
     * Some tasks may take a long time. For these tasks a ProgressMonitor may be 
     * registered and the task will notify the ProgressMonitor when it starts, 
     * the progress it is making, and when it is complete.
     * 
     * 
     *
     * @param progressMonitor The ProgressMonitor for notifications to be sent to.
     */
    virtual void setProgressMonitor( Teamcenter::Soa::Client::ProgressMonitor * progressMonitor );

    /**
     * Returns true if the named type exists in the Client Meta Model
     *
     * @param typeKey  The Type key, either the name or UID
     *
     * @return  True if type is in the cache.
     *
     */
    virtual bool containsType( const std::string& typeKey )=0;


     /**
     * Returns true if the named type is valid.
     * When the Client Meta Model is in cache mode ({@link Connection#OPT_USE_CLIENT_META_MODEL_CACHE} )
     * the named type is validated in the cached files. When not in cached mode, this call will result
     * in a server trip to validate the type name.
     *
     * @param typeName  The Type name.
     *
     * @return  True if type name is valid.
     *
     */
    virtual bool isTypeValid( const std::string& typeName )=0;

    /**
     * Return the desired Client Meta Model Type.
     * Note: this may lead to a server hit, if the requested data is not currently available.
     *
     * @param typeKey       The Type key, either the name or UID
     *
     * @return  Meta Model Type
     */
    virtual Type* getType( const std::string& typeKey)=0;




    /**
     * Return the desired Client Meta Model Type
     * Note: this may lead to a server hit, if the requested data is not currently available.
     *
     * @param typeKeys      The Type keys, either the name or UID
     *
     * @return  Meta Model Type
     */
    virtual std::vector<Type*> getTypes( const std::vector<std::string>& typeKeys )=0;




    /**
     * Remove a Type from the Client Meta Model, thus forcing a reload of it when needed.
     * @param typeKey
     */
    virtual void removeType( const std::string& typeKey )=0;


 




    /**
     * Returns true if the named LOV exists in the Client Meta Model
     *
     * @param uid  The UID of the desired LOV
     *
     * @return  True if LOV is in the cache.
     *
     */
    virtual bool containsLovInfo( const std::string& uid  )=0;



    /**
     * Return the desired Client Meta Model LOV.
     * Note: this may lead to a server hit, if the requested data is not currently available.
     *
     * @param uid           The desired LOV UID
     * @param type          The Type of the desired LOV
     *
     * @return  Meta Model LovInfo
     */
    virtual LovInfo* getLovInfo( const std::string& uid, Type* type )=0;



    SOA_CLASS_NEW_OPERATORS

protected:
    friend class DynamicLovInfo;  // give access to addLovInfo

    std::string dateFormat;
    int         numberFormat;
    Teamcenter::Soa::Client::ProgressMonitor *progressMonitor;

    ClientMetaModel();


    /**
     * Load the Type data for the given set of keys.
     *
     * @param typeKeys      The Type keys, either the name or UID
     */
    virtual void loadTypes(  const std::set<std::string>&  typeKeys ) = 0;


    /**
     * Add the given Type to the cache.
     * The type will be indexed by both the name and UID.
     *
     * @param type  The Type to add.
     */
    virtual  void addType ( Type* type )=0;

        /**
     * Add the given LovInfo to the cache.
     * The LovInfo will be indexed by UID.
     *
     * @param lovInfo  The LovInfo to add.
     */
    virtual  void addLovInfo ( LovInfo* lovInfo )=0;

    /**
     * Load the LovInfo data for the given set of keys.
     *
     * @param uid           The desired LOV UID
     * @param type          The Type of the desired LOV
     */
    virtual void loadLovInfo( const std::string&  uid, Type* type )=0;


private:



};

}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif


