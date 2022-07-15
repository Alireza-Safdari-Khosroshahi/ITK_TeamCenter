// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_CLIENT_CLIENTDATAMODEL_HXX
#define TEAMCENTER_SOA_CLIENT_CLIENTDATAMODEL_HXX

#include <string>
#include <vector>
#include <map>
#include <new>
#include <iostream>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/Type.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>



#include <teamcenter/soa/client/SoaClientMngdExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {

/**
 * This class is used to hold all of the %Teamcenter Business Model objects (ModelObject) that
 * are returned by the different service requests.
 * This store of data is cumulative of all data returned by the service operations.
 * As different service operations return copies of the same object instance, as identified by
 * UID, the single instance of that object in this store will be updated.
 * Objects are only removed from this store if the client application makes explicit calls to remove
 * the data or the server has marked the object with a DeleteObject event.
 *
 */
class TCSOACLIENTMNGD_API ClientDataModel
{
public:

    virtual ~ClientDataModel();

    /**
     * Returns an instance of the Model Object referenced by the UID.
     *
     * Unless this object happens to be already loaded, this method
     * will construct an empty object of the specified Type.
     *
     * @param type     Type of the desired object
     * @param uid      UID of the desired object
     *
     * @return Client Data Model object
     */
    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> constructObject( Teamcenter::Soa::Client::Type* type, const std::string& uid )=0;




    /**
     * Returns an instance of the Model Object referenced by the UID.
     *
     * Unless this object happens to be already loaded, this method
     * will construct an empty object of unknown Type.
     * The Type of the object can be updated at a later time with a call
     * to  {@link #constructObject(Teamcenter::Soa::Client::Type* type, const std::string& uid )}, or automatically if the object
     * is returned from a service operation.
     *
     * @param uid      UID of the desired object
     *
     * @return Client Data Model object
     */
    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> constructObject( const std::string& uid )=0;


    /**
     * Checks for the existence of an object in the Client Data Model
     * @param uid   UID of the desired object
     * @return  True if an object for the given UID exists in the Client Data Model
     */
    virtual bool containsObject( const std::string& uid )=0;




    /**
     * Gets the desired ModelObject from the Client Data Model.
     *
     * @param uid   UID of the desired object
     * @return The ModelObject
     *
     * @throws    RuntimeException  if the desired objects does not exist in the Client Data Model
     */
    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> getObject( const std::string& uid )=0;

    /**
     * Gets all the ModelObject from the Client Data Model.
     *
     * @param modelObjects
     *
     */
    virtual void getObjectsFromStore( std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> >& modelObjects )=0;


    /**
     * Removes a ModelObject from the Client Data Model
     *
     * @param uid   UID of the object to remove
     */
    virtual void removeObject( const std::string& uid )=0;


    /**
     * Remove the list of ModelObjects form the local store
     * managed by the Model Manager.
     *
     * @param objects   ModelObjects to remove.
     */
    virtual void removeObjects( const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> >& objects )=0;


    /**
     * Remove the list of ModelObjects form the local store
     * managed by the Model Manager.
     *
     * @param uids   UIDs of ModelObjects to remove.
     */
    virtual void removeObjects( const std::vector<std::string>& uids)=0;


    /**
     * Remove *all* ModelObjects form the local store
     * managed by the Model Manager.  Assuming there are no other references
     * to them, his will allow them to be released, freeing their memory.
     */
    virtual void removeAllObjects( )=0;


    /**
     * Remove all ModelObjects form the local store
     * managed by the Model Manager.  Assuming there are no other references
     * to them, this will allow them to be released, freeing their memory.
     * @param objects Vector of ModelObjects to delete.
     */
    virtual void removeObjectsRecursivelyFromStore(const std::vector<Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> >& objects )=0;

    /**
     * Force an empty of the ModelObject gargbage.
     * The removeObjectsFromStore method will move the ModelObjects from the active
     * cache to the 'garbage'. The 'garbage' is periodically checked for ModleObject whose
     * reference count (not used anywhere else) has gone to zero. When the count is zero those objects
     * are removed from the 'garbage' and from the system entirely. This method forces an
     * emediate checking of ModelObject to remove from the garbage.
     *
     */
    virtual void emptyGarbage() = 0;

    /**
     * Returns the number of ModelObjects currently in the garbage.
     *
     */
    virtual int  sizeOfGarbage() = 0;

    /**
     * Display the contents of the Client Data Model, and a list of
     * of object in the garbage that are pending removal.
     *
     * @param outStream  The stream the serialized data is written to.
     */
    virtual void dumpCache ( std::ostream& outStream  ) = 0;





    SOA_CLASS_NEW_OPERATORS



protected:
    ClientDataModel();

    /**
     * Returns an instance of the Model Object referenced by the UID.
     *
     * Unless this object happens to be already loaded, this method
     * will construct an empty object of the specified Type.
     *
     * @param type     Type of the desired object
     * @param uid      UID of the desired object
     *
     * @return Client Data Model object
     */
    virtual Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> loadObject( Teamcenter::Soa::Client::Type* type, const std::string& uid) =0;

    /**
     * Update the Object with new type information. This will only be called
     * when the object was created without type information.
     *
     * @param obj   The object to update.
     * @param type  The new Type of the object
     */
    virtual void  refineType( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> obj, Teamcenter::Soa::Client::Type *type ) = 0;



private:



};

}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif

