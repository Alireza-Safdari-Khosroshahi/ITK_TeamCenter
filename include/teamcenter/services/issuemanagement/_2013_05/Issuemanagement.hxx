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

#ifndef TEAMCENTER_SERVICES_ISSUEMANAGEMENT__2013_05_ISSUEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_ISSUEMANAGEMENT__2013_05_ISSUEMANAGEMENT_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/issuemanagement/IssueManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Issuemanagement
        {
            namespace _2013_05
            {
                class Issuemanagement;

class TCSOAISSUEMANAGEMENTSTRONGMNGD_API Issuemanagement
{
public:

    struct AdditionalFiles;
    struct GetIssueSceneFileInput;
    struct GetIssueSceneFileOutput;
    struct GetIssueSceneFileResp;

    /**
     * Structure that contains file name, FMS download ticket and type information for additional
     * files to download.
     */
    struct AdditionalFiles
    {
        /**
         * The FMS ticket to download the file.
         */
        std::string fileTicket;
        /**
         * The file name.
         */
        std::string fileName;
        /**
         * The named reference name for the file or type.
         */
        std::string fileType;
    };

    /**
     * The input to get issue scene files.
     */
    struct GetIssueSceneFileInput
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The product view dataset object that contains issue scene data files and assembly
         * configuration.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  pvDataset;
        /**
         * List of product view dataset named reference names or types to download.
         */
        std::vector< std::string > additionalFiles;
    };

    /**
     * Structure contains issue scene file names and file tickets to download.
     */
    struct GetIssueSceneFileOutput
    {
        /**
         * The unmodified value from the GetIssueSceneFileInput.clientId. This can be used by
         * the caller to indentify this data structure with the source input data.
         */
        std::string clientId;
        /**
         * The FMS ticket for the  generated issue scene PLMXML file.
         */
        std::string issuesceneFileTicket;
        /**
         * The issue scene PLMXML file name.
         */
        std::string issuesceneFileName;
        /**
         * Additional files that can be downloaded.
         */
        std::vector< Teamcenter::Services::Issuemanagement::_2013_05::Issuemanagement::AdditionalFiles > files;
    };

    /**
     * Get issue scene file response.
     */
    struct GetIssueSceneFileResp
    {
        /**
         * GetIssueSceneFileOutput structures.
         */
        std::vector< Teamcenter::Services::Issuemanagement::_2013_05::Issuemanagement::GetIssueSceneFileOutput > outputs;
        /**
         * The service data that may contain error messages or partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation builds a BOM window based on the product view dataset, traverses the
     * BOM window and outputs a BomWriterExport flavored PLMXML file that lists visible
     * BOM lines and contains view stat data. The applications (for example, NX Bookmark
     * function) that support PLMXML in BomWriterExport format can download the generated
     * PLMXML and other files from the product view dataset to launch issue scene.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * NX Issue Tracking provides the functionalities to browse, capture and launch issue
     * reports from NX environment in managed mode. NX calls this function with a product
     * view dataset which is the snapshot for the issue. A generated BomWriterExport flavored
     * PLMXML and other files can be downloaded and launch into NX to re-build issue scene.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Issue Management - Issue Management SOA service.
     *
     * @param inputs
     *        Inputs to get issue scene files.
     *
     * @return
     *         This operation returns the named reference names and FMS tickets for downloading
     *         the requested files. The following partial error may be returned: 261001 - Retrieve
     *         configuration context failed or the named reference does not exist 261002 - Rebuild
     *         BOM window from configuration context failed. 261003 - Retrieve view stat data from
     *         pv-view xml file failed. 261004 - Retrieve pv-view xml file failed or the file does
     *         not exist. 261005 - Retrieve pv-structure xml file failed or the file does not exist.
     *         261006 - Generate BomWriterExport flavored PLMXML file failed. 261007 - Download
     *         file failed.
     *
     */
    virtual Teamcenter::Services::Issuemanagement::_2013_05::Issuemanagement::GetIssueSceneFileResp getIssueSceneFiles ( const std::vector< Teamcenter::Services::Issuemanagement::_2013_05::Issuemanagement::GetIssueSceneFileInput >& inputs ) = 0;


protected:
    virtual ~Issuemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/issuemanagement/IssueManagement_undef.h>
#endif

