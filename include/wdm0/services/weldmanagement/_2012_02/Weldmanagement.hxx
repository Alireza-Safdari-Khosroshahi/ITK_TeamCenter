/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#ifndef WDM0_SERVICES_WELDMANAGEMENT__2012_02_WELDMANAGEMENT_HXX
#define WDM0_SERVICES_WELDMANAGEMENT__2012_02_WELDMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BOMWindow.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <wdm0/services/weldmanagement/WeldManagement_exports.h>

namespace Wdm0
{
    namespace Services
    {
        namespace Weldmanagement
        {
            namespace _2012_02
            {
                class Weldmanagement;

class WDM0SOAWELDMANAGEMENTSTRONGMNGD_API Weldmanagement
{
public:

    struct Attribute;
    struct CreateWeldInput;
    struct CreateWeldOut;
    struct CreateWeldResp;
    struct DeleteWeldInput;
    struct DeleteWeldOut;
    struct DeleteWeldResp;
    struct FindWeldInput;
    struct FindWeldOut;
    struct FindWeldResp;
    struct FormAttributes;
    struct WeldComp;
    struct WeldCompWithFeatData;
    struct WeldFeature;

    /**
     * Attribute name and values.
     */
    struct Attribute
    {
        /**
         * Attribute name.
         */
        std::string name;
        /**
         * List of values for the attribute.
         */
        std::vector< std::string > values;
    };

    /**
     * Create weld component and features input. Client application should retrieve all
     * weld components under parent node and only provide the ones that are created or modified
     * in current NX session as input. SOA call to create weld component is made only when
     * there is weld component created or updated.
     */
    struct CreateWeldInput
    {
        /**
         * Client Id.
         */
        std::string clientId;
        /**
         * Parent node BVR. Parent node must be provided so that the created bom window contains
         * weld components as well as connection parts.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parentBvr;
        /**
         * List of weld component (with feature data) to be created or updated.
         */
        std::vector< Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::WeldCompWithFeatData > weldComps;
    };

    /**
     * Create weld output. It lists weld component data.
     */
    struct CreateWeldOut
    {
        /**
         * Client Id.
         */
        std::string clientId;
        /**
         * List of weld components.
         */
        std::vector< Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::WeldComp > welds;
    };

    /**
     * Create weld response.
     */
    struct CreateWeldResp
    {
        /**
         * Service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * List of create weld outputs.
         */
        std::vector< Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::CreateWeldOut > weldouts;
    };

    /**
     * Delete weld component input.
     */
    struct DeleteWeldInput
    {
        /**
         * Client Id.
         */
        std::string clientId;
        /**
         * Parent node BVR. Parent node should be the work part that when weld component was
         * created in NX.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parentBvr;
        /**
         * List of weld components to be deleted.
         */
        std::vector< Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::WeldComp > comps;
        /**
         * Type of relation from weld feature object to connection parts. This is needed to
         * clean up those relation objects.
         */
        std::string relType;
        /**
         * True - destroy weld component and feature objects from Teamcenter completely; False
         * - remove weld component from assembly only.
         */
        bool destroy;
    };

    /**
     * Delete weld output.
     */
    struct DeleteWeldOut
    {
        /**
         * Client Id.
         */
        std::string clientId;
        /**
         * List of message show weld component id and status of deletion. Format is id - OK
         * if component is deleted successfully. Otherwise, it is id - Failed.
         */
        std::vector< std::string > message;
    };

    /**
     * Delete weld component response.
     */
    struct DeleteWeldResp
    {
        /**
         * Service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * List of delete weld outputs.
         */
        std::vector< Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::DeleteWeldOut > results;
    };

    /**
     * Find weld component input.
     */
    struct FindWeldInput
    {
        /**
         * Client Id.
         */
        std::string clientId;
        /**
         * Assembly bom window. It is not needed when parent BVR is provided. Weld components
         * are searched within the bomlines by looking at connection relationships with provided
         * connection components. Weld type may be used to further filter out unwanted weld
         * components.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  asmWindow;
        /**
         * Weld component parent BVR.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parentBvr;
        /**
         * Connection part PS Occurrences. Connection parts must fall in the bom window that
         * created by parent BVR.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > connectionParts;
        /**
         * Connection relation type. For example, weld component and features occurrence are
         * related to connection part APN by TC_CONNECT_TO relation.
         */
        std::string relation;
        /**
         * Weld component types as a filter.
         */
        std::vector< std::string > weldTypes;
        /**
         * true - return the uids for occurrence, revision and BVR only. false - return objects
         * only.
         */
        bool returnUid;
    };

    /**
     * Find weld component output.
     */
    struct FindWeldOut
    {
        /**
         * Client Id.
         */
        std::string clientId;
        /**
         * List of weld components returned.
         */
        std::vector< Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::WeldComp > welds;
    };

    /**
     * Find weld component response.
     */
    struct FindWeldResp
    {
        /**
         * Service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * List of find weld component outputs.
         */
        std::vector< Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::FindWeldOut > results;
    };

    /**
     * Data to create a form and attach the form to parent object.
     */
    struct FormAttributes
    {
        /**
         * Form type.
         */
        std::string formType;
        /**
         * Form name.
         */
        std::string formName;
        /**
         * Relation name from parent object to form.
         */
        std::string formRel;
        /**
         * List of form attribute name and values.
         */
        std::vector< Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::Attribute > attributes;
    };

    /**
     * Weld component data.
     */
    struct WeldComp
    {
        /**
         * Weld component PS occurrence.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  compOcc;
        /**
         * Weld component revision.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  compRev;
        /**
         * Weld component BVR.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  compBvr;
        /**
         * component Occurrence uid string.
         */
        std::string occUid;
        /**
         * Component revision uid.
         */
        std::string revUid;
        /**
         * Component BVR uid.
         */
        std::string bvrUid;
    };

    /**
     * Weld component with feature data. If component occurence, revision and BVR are not
     * provided, a weld component will be created. If weld component does exist, occurrence,
     * revision and BVR must be provided.
     */
    struct WeldCompWithFeatData
    {
        /**
         * Weld component (NX part that contains weld features) UG Entity Handle.
         */
        std::string ugEntHandle;
        /**
         * Weld component revision.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  compRev;
        /**
         * Weld component PS Occurrence.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  compOcc;
        /**
         * Weld component BVR.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  compBvr;
        /**
         * List of weld features that current weld component defines.
         */
        std::vector< Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::WeldFeature > features;
        /**
         * Type of relation from weld feature object to connection parts.
         */
        std::string relType;
        /**
         * True - current weld component is revised or to be revised. False - update weld component.
         */
        bool revise;
    };

    /**
     * Weld feature data. Client application must collect all features per weld component
     * in current NX session. Server implementation compares the features list from input
     * with the one retrieved from weld component occurrence in Teamcenter. The features
     * that are missing from input will be removed from weld component occurrence children.
     * The features that do not exist in weld component occurrence will be created and added
     * as children. Client application should only provide feature UG Entity Handle for
     * the features that have not been modified in current NX session. Client application
     * should mark the features that are to be revised. Rest of the features are assumed
     * to be updated.
     */
    struct WeldFeature
    {
        /**
         * Feature UG Entity Handle.
         */
        std::string ugEntHandle;
        /**
         * Feature occurrence node in PS. Optional.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  featOcc;
        /**
         * Feature revision object. Optional.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  featRev;
        /**
         * Feature revision attributes. New value overwrite existing value.
         */
        std::vector< Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::Attribute > revAttributes;
        /**
         * Forms to be created or updated and attached to feature revision. Existing form is
         * updated by overwritting attribute values.
         */
        std::vector< Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::FormAttributes > revForms;
        /**
         * List of connection parts PS occurrence for current feature.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > comps;
        /**
         * True - revise this feature; false - do not revise this feature.
         */
        bool revise;
        /**
         * Feature item type.
         */
        std::string type;
        /**
         * Feature item name.
         */
        std::string name;
        /**
         * Feature item description.
         */
        std::string desc;
        /**
         * Feature JT file name.
         */
        std::string jtFile;
        /**
         * Feature JT file ticket for uploading.
         */
        std::string jtTicket;
        /**
         * Feature NX file name.
         */
        std::string nxFile;
        /**
         * Feature NX file ticket for uploading.
         */
        std::string nxTicket;
    };




    /**
     * Creates or updates weld components.
     *
     * @param inputs
     *        List of create/update weld component inputs.
     *
     * @return
     *         List of weld components/features that created or updated.
     *
     */
    virtual Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::CreateWeldResp createUpdateWelds ( const std::vector< Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::CreateWeldInput >& inputs ) = 0;

    /**
     * Delete weld components.
     *
     * @param inputs
     *        List of delete weld component inputs.
     *
     * @return
     *         List of message on eached weld component showing whether is deleted or failed to
     *         be deleted.
     *
     */
    virtual Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::DeleteWeldResp deleteWelds ( const std::vector< Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::DeleteWeldInput >& inputs ) = 0;

    /**
     * Find weld components that connected to any of connection parts.
     *
     * @param inputs
     *        List of find weld component inputs.
     *
     * @return
     *         List of weld components.
     *
     */
    virtual Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::FindWeldResp findWelds ( const std::vector< Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::FindWeldInput >& inputs ) = 0;


protected:
    virtual ~Weldmanagement() {}
};
            }
        }
    }
}

#include <wdm0/services/weldmanagement/WeldManagement_undef.h>
#endif

