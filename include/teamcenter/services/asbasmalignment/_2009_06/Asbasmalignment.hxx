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

#ifndef TEAMCENTER_SERVICES_ASBASMALIGNMENT__2009_06_ASBASMALIGNMENT_HXX
#define TEAMCENTER_SERVICES_ASBASMALIGNMENT__2009_06_ASBASMALIGNMENT_HXX

#include <teamcenter/soa/client/model/PhysicalPartRevision.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/asbasmalignment/AsbAsmAlignment_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Asbasmalignment
        {
            namespace _2009_06
            {
                class Asbasmalignment;

class TCSOAASBASMALIGNMENTSTRONGMNGD_API Asbasmalignment
{
public:

    struct GeneratePhysicalStructInfo;
    struct GeneratePhysicalStructInputInfo;
    struct GeneratePhysicalStructOutput;
    struct GeneratePhysicalStructResponse;

    /**
     * The parameters required to generate an as-maintained structure for a given as-built
     * structure and vice versa.
     */
    struct GeneratePhysicalStructInfo
    {
        /**
         * The name of the <b>PhysicalLocation</b> object.
         */
        std::string physicalLocationName;
        /**
         * The disposition value to be assigned to newly generated <b>PhysicalPart</b> object.
         * User can define Disposition types to be assigned to the objects, for instance, <i>In-Service.</i>
         */
        std::string dispositionType;
        /**
         * The number of levels in the as-built or as-maintained structure to be traversed while
         * generating the target structure. All levels will be traversed if the value is set
         * to -1.
         */
        int numberOfLevels;
        /**
         * If true an as-built structure will  be generated from the as-maintained structure.
         */
        bool generateAsBuilt;
        /**
         * Used as the installation time on the <b>AsBuiltStructure</b> or <b>AsMaintainedStructure</b>
         * relation objects.
         */
        Teamcenter::Soa::Common::DateTime rebuildDate;
    };

    /**
     * The parameters required to generate an as-maintained structure for a given as-built
     * structure and vice versa.
     */
    struct GeneratePhysicalStructInputInfo
    {
        /**
         * The <code>clientId</code> from the input <code>GeneratePhysicalStructInputInfo</code>
         * element. This value is unchanged from the input, and can be used to identify this
         * response element with the corresponding input element.
         */
        std::string clientId;
        /**
         * The <b>PhysicalPartRevision</b> object from the source structure.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  physPartRev;
        /**
         * The structure containing parameters required to generate a <b>PhysicalPart</b> structure.
         */
        Teamcenter::Services::Asbasmalignment::_2009_06::Asbasmalignment::GeneratePhysicalStructInfo generatePhysicalStructInfo;
    };

    /**
     * Structure represents the output parameters of the generateAsMaintainedStructure operation.
     */
    struct GeneratePhysicalStructOutput
    {
        /**
         * The <code>clientId</code> from the output <code>GeneratePhysicalStructOutput</code>
         * element. This value is unchanged from the input, and can be used to identify this
         * response element with the corresponding input element.
         */
        std::string clientId;
        /**
         * The newly created top level <b>PhysicalPartRevision</b> object, either as-built or
         * as-maintained depending on the selection.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  newPhysPartRev;
    };

    /**
     * Structures containing the newly created top level <b>PhysicalPartRevision</b> object
     * and the <code>ServiceData</code>.
     */
    struct GeneratePhysicalStructResponse
    {
        /**
         * A newly created top level <b>PhysicalPartRevision</b> object.
         */
        std::vector< Teamcenter::Services::Asbasmalignment::_2009_06::Asbasmalignment::GeneratePhysicalStructOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation generates an as-maintained structure from an as-built structure. It
     * can also generate an as-built structure from an as-maintained structure. The target
     * structure will be released by applying the Status value specified for <b>PhysicalPart</b>
     * in BMIDE.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Built/MRO As-Maintained Alignment - This component provides capabilities to
     * generate As-Built structures from As-Maintained structures and vice versa.
     *
     * @param input
     *        Input
     *
     * @return
     *         A <b>PhysicalPartRevision</b> object is returned for each Item. Only the created
     *         top <b>PhysicalPartRevision</b> object is returned in the created objects list of
     *         the <code>ServiceData</code>. Any failures will be returned as a partial error, each
     *         error will include the <code>clientId</code> from the input.
     *         <br>
     *         <ul>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;243001&nbsp;&nbsp;&nbsp;&nbsp;If one tries
     *         to generate an as-built structure from an as-built revision of the <b>PhysicalPart</b>
     *         object.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;243002&nbsp;&nbsp;&nbsp;&nbsp;If one tries
     *         to generate an as-maintained structure from an as-maintained revision of the <b>PhysicalPart</b>
     *         object.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;243003&nbsp;&nbsp;&nbsp;&nbsp;If the as-maintained
     *         structure from which an as-built structure will be generated, is not released.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;243004&nbsp;&nbsp;&nbsp;&nbsp;If the as-built
     *         structure from which an as-maintained structure will be generated, is not released.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;243005&nbsp;&nbsp;&nbsp;&nbsp;If the rebuiltDate
     *         specified is earlier than the installation time of any of the <b>PhysicalPart</b>
     *         objects in the structure.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;243006&nbsp;&nbsp;&nbsp;&nbsp;If the rebuiltDate
     *         specified is a future date.
     *         </li>
     *         <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;243007&nbsp;&nbsp;&nbsp;&nbsp;If the global
     *         constant MaturityStatuses for <b>PhysicalPart</b> has no values.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asbasmalignment::_2009_06::Asbasmalignment::GeneratePhysicalStructResponse generatePhysicalStructure ( const std::vector< Teamcenter::Services::Asbasmalignment::_2009_06::Asbasmalignment::GeneratePhysicalStructInputInfo >& input ) = 0;


protected:
    virtual ~Asbasmalignment() {}
};
            }
        }
    }
}

#include <teamcenter/services/asbasmalignment/AsbAsmAlignment_undef.h>
#endif

