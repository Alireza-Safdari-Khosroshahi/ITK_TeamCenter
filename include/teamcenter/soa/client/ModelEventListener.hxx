// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef  TEAMCENTER_SOA_CLIENT_MODELEVENTLISTENER_HXX
#define  TEAMCENTER_SOA_CLIENT_MODELEVENTLISTENER_HXX
#include <string>
#include <new>
#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/SoaClientMngdExports.h>
namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
/**
 * The ModelEventListener is used by the ModelManager to notify the client application
 * of model objects changes that are returned from the server.
 * Clients should extend it and override the desired methods to change the default behavior.
 *
 */
class TCSOACLIENTMNGD_API ModelEventListener
{
public:

    ModelEventListener();
    virtual ~ModelEventListener();

    /**
     * This method is called by the ModelManager to notify the client application
     * when an object in the Client Data Model has been created as the result of
     * a service call that <b>this</b> client made.  The objects were returned to
     * this client in the ServiceData in the response to the current service request.
     * There is no guarantee that the Client Data Model will reflect all objects
     * created on the server,it will only reflect those the service returned.
     *
     * @param createdObjs
     */
    virtual void localObjectCreate( const ModelObjectVector& createdObjs );
    

    /**
     * This method is called by the ModelManager to notify the client application
     * when an object in %Teamcenter has been changed as the result of
     * a service call that <b>this</b> client made.  The objects were returned to
     * this client in the ServiceData in the response to the current service request.
     * There is no guarantee that the Client Data Model will reflect all objects
     * changed on the server,it will only reflect those the service returned.
     *
     * @param changedObjs
     */
    virtual void localObjectChange( const ModelObjectVector& changedObjs );
    

    /**
     * This method is called by the ModelManager to notify the client application
     * when an object in %Teamcenter has been deleted as the result of
     * a service call that <b>this</b> client made.  The objects were returned to
     * this client in the ServiceData in the response to the current service request.
     * There is no guarantee that this notification includes all objects
     * deleted from the server,it will only reflect those the service returned.
     *
     * @param deletedUids
     */
    virtual void localObjectDelete( const StringVector& deletedUids );
    


    /**
     * This method is called by the ModelManager to notify the client application
     * when an object in the Client Data Model has been created as the result of
     * a service call that <b>another</b> client made.  The objects were returned to
     * this client when it contacted the shared event process.
     * There is no guarantee that the Client Data Model will reflect all objects
     * created on the server,it will only reflect those a service returned.
     *
     * @param createdObjs
     */
    virtual void sharedObjectCreate( const ModelObjectVector& createdObjs );
    

    /**
     * This method is called by the ModelManager to notify the client application
     * when an object in %Teamcenter has been changed as the result of
     * a service call that <b>another</b> client made.  The objects were returned to
     * this client when it contacted the shared event process.
     * There is no guarantee that the Client Data Model will reflect all objects
     * changed on the server,it will only reflect those the service returned.
     *
     * @param changedObjs
     */
    virtual void sharedObjectChange( const ModelObjectVector& changedObjs );
    

    /**
     * This method is called by the ModelManager to notify the client application
     * when an object in %Teamcenter has been deleted as the result of
     * a service call that <b>another</b> client made.  The objects were returned to
     * this client when it contacted the shared event process.
     * There is no guarantee that this notification includes all objects
     * deleted from the server,it will only reflect those the service returned.
     *
     * @param deletedUids
     */
    virtual void sharedObjectDelete( const StringVector& deletedUids );
    




    SOA_CLASS_NEW_OPERATORS    

};
}}} //end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
