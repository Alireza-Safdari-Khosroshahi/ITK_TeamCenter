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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2011_06_STRUCTUREMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2011_06_STRUCTUREMANAGEMENT_HXX

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
            namespace _2011_06
            {
                class Structuremanagement;

class TCSOAMANUFACTURINGSTRONGMNGD_API Structuremanagement
{
public:

    struct ContextsArray;
    struct ReferencedContexts;
    struct ReferencedContextsResponse;

    /**
     * the structure contains array of contexts
     */
    struct ContextsArray
    {
        /**
         * array of contexts ( any types)
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > contextsarray;
    };

    /**
     * the structure used for three different modes: add, set, remove
     */
    struct ReferencedContexts
    {
        /**
         * the top line of BOP window which will be referenced
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  context;
        /**
         * contexts, which will reference
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > addRefContexts;
        /**
         * contexts, which will be removed
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > removeRefContexts;
        /**
         * remove all referenced contexts
         */
        bool removeExistingRef;
    };

    /**
     * the structure contains referenced contexts and used for response.
     */
    struct ReferencedContextsResponse
    {
        /**
         * vector of vectors referenced contexts according to the order from the input vector
         */
        std::vector< Teamcenter::Services::Manufacturing::_2011_06::Structuremanagement::ContextsArray > refcontexts;
        /**
         * service data will return errors only. No data will be return via Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * return referenced contexts of input context.
     *
     * @param contexts
     *        vector of input contexts
     *
     * @return
     *         return ReferenceContextResponse structure
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2011_06::Structuremanagement::ReferencedContextsResponse getReferenceContexts ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& contexts ) = 0;

    /**
     * set Reference context according to user choice.
     *
     * @param input
     *        includes ReferencedContexts structure
     *
     * @return
     *         service data will return errors only and no data.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setReferenceContexts ( const std::vector< Teamcenter::Services::Manufacturing::_2011_06::Structuremanagement::ReferencedContexts >& input ) = 0;


protected:
    virtual ~Structuremanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

