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

#ifndef TEAMCENTER_SERVICES_CORE__2008_06_MANAGEDRELATIONS_HXX
#define TEAMCENTER_SERVICES_CORE__2008_06_MANAGEDRELATIONS_HXX

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2008_06
            {
                class Managedrelations;

class TCSOACORESTRONGMNGD_API Managedrelations
{
public:

    struct GetManagedRelationInput;
    struct GetManagedRelationResponse;

    /**
     * GetManagedRelationInput
     */
    struct GetManagedRelationInput
    {
        /**
         * List of primaryTags
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > primaryTags;
        /**
         * List of secondaryTags
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > secondaryTags;
        /**
         * // primaryType of Managed relation
         */
        std::string primaryType;
        /**
         * // subtype of primary type
         */
        std::string subtype;
    };

    /**
     * GetManagedRelation Response
     */
    struct GetManagedRelationResponse
    {
        /**
         * Tracelink relations
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  > managedRelations;
        /**
         * The successful Object ids, partial errors and failures
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation will return tracelinks between primary and secondary objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputdata
     *        information required to get tracelink relations
     *
     * @return
     *         will return tracelink relations between primary and secondary objects and error message
     *         in the ServiceData.
     *
     */
    virtual Teamcenter::Services::Core::_2008_06::Managedrelations::GetManagedRelationResponse getManagedRelations ( const Teamcenter::Services::Core::_2008_06::Managedrelations::GetManagedRelationInput&  inputdata ) = 0;


protected:
    virtual ~Managedrelations() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

