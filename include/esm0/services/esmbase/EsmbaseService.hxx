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

#ifndef ESM0_SERVICES_ESMBASE_ESMBASESERVICE_HXX
#define ESM0_SERVICES_ESMBASE_ESMBASESERVICE_HXX

#include <esm0/services/esmbase/_2011_06/Esmbase.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <esm0/services/esmbase/ESMBase_exports.h>

namespace Esm0
{
    namespace Services
    {
        namespace Esmbase
        {
            class EsmbaseService;

/**
 * This service is used to create, delete, and query <code>Embedded</code> Software
 * Management (ESM) relationships for hardware and software item revisions.  It also
 * is used to generate formatted reports on the relationship of hardware and software
 * item revisions.  The relationships are Embedded, <code>GatewayOf</code>, and <code>UsedBy</code>.
 * <br>
 * The ESMBase service can be used for the following use cases:
 * <br>
 * <ul>
 * <li type="disc">Create an <code>Embedded</code> relation between a hardware and software
 * item revision in Structure Manager.
 * </li>
 * <li type="disc">Create a <code>GatewayOf</code> relation between hardware item revisions
 * in Structure Manager.
 * </li>
 * <li type="disc">Create a <code>UsedBy</code> relation between software item revisions
 * in Structure Manager.
 * </li>
 * <li type="disc">Find which software item revisions are embedded (is the secondary
 * in the <code>Embedded</code> relationship) in a hardware item revision.
 * </li>
 * <li type="disc">Find which software item revisions use (is the primary in the <code>UsedBy</code>
 * relationship) a software item revision.
 * </li>
 * <li type="disc">Find which software item revisions are used by (is the secondary
 * in the <code>UsedBy</code> relationship) a software item revision.
 * </li>
 * </ul>
 * <ul>
 * <li type="disc">Find which hardware item revisions are embedding (is the primary
 * in the <code>Embedded</code> relationship) a software item revision.
 * </li>
 * <li type="disc">Find which hardware item revisions are accessed by (is the secondary
 * in the <code>GatewayOf</code> relationship) a hardware item revision.
 * </li>
 * <li type="disc">Find which hardware item revisions are gateways of (is the primary
 * in the <code>GatewayOf</code> relationship) a hardware item revision.
 * </li>
 * <li type="disc">Generate an XML report dataset showing which software item revisions
 * are embedded (is the secondary in the <code>Embedded</code> relationship) in a hardware
 * item revision.
 * </li>
 * <li type="disc">Generate an XML report dataset showing which hardware item revisions
 * are embedding (is the primary in the <code>Embedded</code> relationship) a software
 * item revision.
 * </li>
 * </ul>
 * <ul>
 * <li type="disc">Delete an <code>Embedded</code> relation between a hardware and software
 * item revision in Structure Manager.
 * </li>
 * <li type="disc">Delete a <code>GatewayOf</code> relation between hardware item revisions
 * in Structure Manager.
 * </li>
 * <li type="disc">Delete a <code>UsedBy</code> relation between software item revisions
 * in Structure Manager.
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libesm0soaesmbasestrongmngd.dll
 * </li>
 * <li type="disc">libesm0soaesmbasetypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class ESM0SOAESMBASESTRONGMNGD_API EsmbaseService
    : public Esm0::Services::Esmbase::_2011_06::Esmbase
{
public:
    static EsmbaseService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation generates an ESM report which shows the software used by the indicated
     * hardware.  The report is stored in a file in either HTML or Excel format.  Optionally
     * the file can be stored as a Teamcenter Dataset.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user inputs a hardware type item revision and selects a report output format
     * (HTML or Excel).  A report showing the software items or revisions used by this hardware
     * is created in either an HTML or Excel file.  This file can be stored as a Teamcenter
     * Dataset.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Embedded Software Manager Base - Application to manage software binaries in Tc and
     * manage their relations to ECUs (electronic control units)
     *
     * @param generateReportInputs
     *        A list of requested hardware/software reports.
     *
     * @return
     *         A list of hardware software reports, one for each Hardware revision input.  If a
     *         hardware <b>ItemRevision</b> does not have a UsedBy relation with any software <b>ItemRevision</b>
     *         then the partial error 48053 is returned.  If a hardware <b>ItemRevision</b> has
     *         multiple UsedBy relations then the partial error 48161 is returned.
     *
     */
    virtual Esm0::Services::Esmbase::_2011_06::Esmbase::GenerateReportResponse generateHardwareSoftwareReport ( const std::vector< Esm0::Services::Esmbase::_2011_06::Esmbase::GenerateReportInput >& generateReportInputs ) = 0;

    /**
     * This operation generates an ESM report which shows the hardware that uses the indicated
     * software.  The report is generated in either HTML or Excel format and can optionally
     * be stored on a <b>Dataset</b>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user inputs a software type item revision and selects a report output format
     * (HTML or Excel).  A report showing the hardware items or revisions that use this
     * software is created in either an HTML or Excel dataset.  This file can be stored
     * as a Teamcenter <b>Dataset</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Embedded Software Manager Base - Application to manage software binaries in Tc and
     * manage their relations to ECUs (electronic control units)
     *
     * @param generateReportInputs
     *        A list of requested hardware/software reports.
     *
     * @return
     *         A list of hardware software reports, one for each software revision input.  If a
     *         software <b>ItemRevision</b> does not have a UsedBy relation with any hardware <b>ItemRevision</b>
     *         then the partial error 48053 is returned.  If a software <b>ItemRevision</b> has
     *         multiple UsedBy relations then the partial error 48161 is returned.
     *
     */
    virtual Esm0::Services::Esmbase::_2011_06::Esmbase::GenerateReportResponse generateSoftwareHardwareReport ( const std::vector< Esm0::Services::Esmbase::_2011_06::Esmbase::GenerateReportInput >& generateReportInputs ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EsmbaseService")

};
        }
    }
}


#pragma warning ( pop )

#include <esm0/services/esmbase/ESMBase_undef.h>
#endif

