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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2008_12_STRUCTUREVERIFICATION_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2008_12_STRUCTUREVERIFICATION_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/structuremanagement/StructureManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Structuremanagement
        {
            namespace _2008_12
            {
                class Structureverification;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Structureverification
{
public:

    struct AccCheckInput;
    struct AccountabilityCheckResponse;
    struct AccountabilityCheckResult;

    /**
     * This structure provides a set of input values for accountabilityCheck operation.
     */
    struct AccCheckInput
    {
        /**
         * the source BOM lines
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > sourceTags;
        /**
         * the target BOM lines
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > targetTags;
        /**
         * options of search
         */
        int option;
        /**
         * the possible source context line
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  srcCtxtLineTag;
        /**
         * the possible target context line
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  tarCtxtLineTag;
        /**
         * represents user choice in the color display
         */
        int matchType;
    };

    /**
     * This structure provides response of the call
     */
    struct AccountabilityCheckResponse
    {
        /**
         * Accountabilty Check result
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2008_12::Structureverification::AccountabilityCheckResult > resultSourceTarget;
        /**
         * Partial errors
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The structure characterizes compare result for each source line
     */
    struct AccountabilityCheckResult
    {
        /**
         * the sourse BOM line
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  source;
        /**
         * the target BOM lines
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > targets;
        /**
         * characterized check result
         */
        int checkResult;
    };




    /**
     * The operation will call the existing accountability check functions,  which will
     * generate a check result for report in the colored display.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Accountability Check - Advanced comparison of two structures
     *
     * @param input
     *        a set of input values
     *
     * @return
     *         return AccountabilityCheckResponse including lines from source and target windows
     *         and check result
     *
     * @deprecated
     *         As of Teamcenter 8.3, use the accountabilityCheck operation from the _2010_09 namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 8.3, use the accountabilityCheck operation from the _2010_09 namespace."))
#endif
    virtual Teamcenter::Services::Structuremanagement::_2008_12::Structureverification::AccountabilityCheckResponse accountabilityCheck ( const Teamcenter::Services::Structuremanagement::_2008_12::Structureverification::AccCheckInput&  input ) = 0;


protected:
    virtual ~Structureverification() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

