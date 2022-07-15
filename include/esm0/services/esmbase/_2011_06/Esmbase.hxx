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

#ifndef ESM0_SERVICES_ESMBASE__2011_06_ESMBASE_HXX
#define ESM0_SERVICES_ESMBASE__2011_06_ESMBASE_HXX

#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/RevisionRule.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <esm0/services/esmbase/ESMBase_exports.h>

namespace Esm0
{
    namespace Services
    {
        namespace Esmbase
        {
            namespace _2011_06
            {
                class Esmbase;

class ESM0SOAESMBASESTRONGMNGD_API Esmbase
{
public:

    struct GenerateReportInput;
    struct GenerateReportOutput;
    struct GenerateReportResponse;

    /**
     * Input structure for ESM Report Generation.
     */
    struct GenerateReportInput
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * Hardware/software <b>ItemRevision</b> for which a report is to be generated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRevision;
        /**
         * The configuration revision rule that supplies which revision of an <b>Item</b> is
         * the parent of the hardware <b>ItemRevision</b>. If null, the default configuration
         * rule will be used.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::RevisionRule>  configRule;
        /**
         * Desired format of the generated report, 0 for HTML, 1 for Microsoft Excel.
         */
        int reportFormatType;
        /**
         * If true a Dataset is created with the report attached to it.
         */
        bool createDataset;
        /**
         * The name of the <b>Dataset</b> of the generated report. This value is ignored if
         * <code>createDataset</code> is false.
         */
        std::string datasetName;
    };

    /**
     * Report Generation Output.
     */
    struct GenerateReportOutput
    {
        /**
         * The unmodified value from the <code>GenerateReportInput.clientId</code>. This can
         * be used by the caller to identify this data structure with the source input data.
         */
        std::string clientId;
        /**
         * The <b>Dataset</b> created for the generated report. This will be null if the <code>createDataset</code>
         * flag was set to false.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  datasetObject;
        /**
         * The full local path name of the generated HTML or Excel report in the FMS transient
         * volume.
         */
        std::string fileName;
    };

    /**
     * GenerateReport Response for Report generation.
     */
    struct GenerateReportResponse
    {
        /**
         * A list of generated reports.
         */
        std::vector< Esm0::Services::Esmbase::_2011_06::Esmbase::GenerateReportOutput > reportOutputs;
        /**
         * The newly created <b>Datasets</b> are returned in the Created list.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




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


protected:
    virtual ~Esmbase() {}
};
            }
        }
    }
}

#include <esm0/services/esmbase/ESMBase_undef.h>
#endif

