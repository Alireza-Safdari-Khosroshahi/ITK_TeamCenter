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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2008_05_STRUCTUREVERIFICATION_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2008_05_STRUCTUREVERIFICATION_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>


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
            namespace _2008_05
            {
                class Structureverification;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Structureverification
{
public:

    struct AlignmentCheckResponse;
    struct BOMLinePair;
    struct AlignmentCheckResult;
    struct AlignmentMismatches;

    /**
     * This structure provides response of the call.
     */
    struct AlignmentCheckResponse
    {
        /**
         * the property list used in this alignment check
         */
        std::vector< std::string > propertyList;
        /**
         * the mismatched BOM lines
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2008_05::Structureverification::AlignmentCheckResult > results;
        /**
         * Partial errors
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * This structure provides a pair of BOM lines.
     */
    struct BOMLinePair
    {
        /**
         * the source BOM line
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  source;
        /**
         * the target BOM line
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  target;
    };

    /**
     * This structure provides information about the alignment check in a given scope.
     */
    struct AlignmentCheckResult
    {
        /**
         * the pair of scope BOM lines
         */
        Teamcenter::Services::Structuremanagement::_2008_05::Structureverification::BOMLinePair scope;
        /**
         * the mismatched BOM lines
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2008_05::Structureverification::AlignmentMismatches > mismatches;
    };

    /**
     * This structure provides information about a pair of mismatched lines.
     */
    struct AlignmentMismatches
    {
        /**
         * the pair of mismatched BOM lines
         */
        Teamcenter::Services::Structuremanagement::_2008_05::Structureverification::BOMLinePair mismatchedAlignment;
        /**
         * the indices of mismatched properties
         */
        std::vector< int > mismatchedproperties;
    };




    /**
     * An alignment connects two occurrences that are to be considered equivalent. They
     * are referred to as source and target. An alignment can connect one source to multiple
     * targets. Alignment can be used to transfer data from source to target. An alignment
     * check is used to determine if the source and target of an alignment have matching
     * data.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Accountability Check - Advanced comparison of two structures
     *
     * @param input
     *        The source ebom and the target mbom structures.
     *
     * @return
     *         contains ServiceData along with vector of AlignmentCheckResponse
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2008_05::Structureverification::AlignmentCheckResponse checkAlignment ( const std::vector< Teamcenter::Services::Structuremanagement::_2008_05::Structureverification::BOMLinePair >& input ) = 0;


protected:
    virtual ~Structureverification() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

