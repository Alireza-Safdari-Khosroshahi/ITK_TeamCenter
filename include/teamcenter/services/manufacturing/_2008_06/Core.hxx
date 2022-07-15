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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2008_06_CORE_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2008_06_CORE_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/manufacturing/Manufacturing_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Manufacturing
        {
            namespace _2008_06
            {
                class Core;

class TCSOAMANUFACTURINGSTRONGMNGD_API Core
{
public:

    struct FindCheckedOutsInStructureResponse;

    /**
     * Return structure for findCheckedOutsInStructure operation
     */
    struct FindCheckedOutsInStructureResponse
    {
        /**
         * This is the structure contains the Tags of all the checked outs objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > checkedOutList;
        /**
         * This is a common data strucuture used to return sets of Teamcenter Data Model object
         * from a service request. This also holds services exceptions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Finds all the checked out items in the objects.
     *
     * @param searchScope
     *        Vector of lines, that we would like to get all the checked out objects from.
     *
     * @return
     *         Structure that contains a vector of all the checked out objects in search scope,
     *         also holds services exceptions.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2008_06::Core::FindCheckedOutsInStructureResponse findCheckedOutsInStructure ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& searchScope ) = 0;


protected:
    virtual ~Core() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

