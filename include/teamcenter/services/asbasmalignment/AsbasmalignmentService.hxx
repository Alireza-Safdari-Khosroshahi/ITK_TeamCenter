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

#ifndef TEAMCENTER_SERVICES_ASBASMALIGNMENT_ASBASMALIGNMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_ASBASMALIGNMENT_ASBASMALIGNMENTSERVICE_HXX

#include <teamcenter/services/asbasmalignment/_2009_06/Asbasmalignment.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/asbasmalignment/AsbAsmAlignment_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Asbasmalignment
        {
            class AsbasmalignmentService;

/**
 * The MRO As-Built / As-Maintained Alignment service provides operations to generate
 * As-Built structures from As-Maintained structures and vice versa.
 * <br>
 * The alignment service can be used to support the following:
 * <br>
 * <ul>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Generate an As-Maintained structure from
 * an As-Built structure
 * </li>
 * <li type="disc">&nbsp;&nbsp;&nbsp;&nbsp;Generate an As-Built structure from an As-Maintained
 * structure
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaasbasmalignmentstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaasbasmalignmenttypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAASBASMALIGNMENTSTRONGMNGD_API AsbasmalignmentService
    : public Teamcenter::Services::Asbasmalignment::_2009_06::Asbasmalignment
{
public:
    static AsbasmalignmentService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AsbasmalignmentService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/asbasmalignment/AsbAsmAlignment_undef.h>
#endif

