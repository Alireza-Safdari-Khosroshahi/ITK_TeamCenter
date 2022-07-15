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

#ifndef TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT__2008_06_DOCUMENTCONTROL_HXX
#define TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT__2008_06_DOCUMENTCONTROL_HXX

#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/documentmanagement/DocumentManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Documentmanagement
        {
            namespace _2008_06
            {
                class Documentcontrol;

class TCSOADOCUMENTMANAGEMENTSTRONGMNGD_API Documentcontrol
{
public:

    struct FileInfo;
    struct FileTicketInfo;
    struct CommitDatasetInfo;
    struct GetAdditionalFilesForCheckinInputs;
    struct GetAdditionalFilesForCheckinOutputs;
    struct GetAdditionalFilesForCheckinOutputsResponse;
    struct GetCheckinModeAndFilesOutputs;
    struct GetCheckinModeAndFilesOutputsResponse;
    struct PostCreateInfo;
    struct PostCreateInputs;
    struct PostCreateResponse;

    /**
     * File information
     */
    struct FileInfo
    {
        /**
         * The client id
         */
        std::string clientId;
        /**
         * The file name
         */
        std::string fileName;
        /**
         * The Dataset named reference information.
         */
        std::string namedReferencedName;
        /**
         * True means Text format, otherwise it is Binary format.
         */
        bool isText;
        /**
         * Allow to replace or not.
         */
        bool allowReplace;
    };

    /**
     * File ticket information structure
     */
    struct FileTicketInfo
    {
        /**
         * The file information.
         */
        Teamcenter::Services::Documentmanagement::_2008_06::Documentcontrol::FileInfo fileInfo;
        /**
         * The FMS ticket.
         */
        std::string ticket;
    };

    /**
     * Commit dataset information
     */
    struct CommitDatasetInfo
    {
        /**
         * The Dataset created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * The Dataset type name.
         */
        std::string dsTypeName;
        /**
         * The file ticket information.
         */
        Teamcenter::Services::Documentmanagement::_2008_06::Documentcontrol::FileTicketInfo fileTicketInfo;
    };

    /**
     * The structure contains the item revision and file names.
     */
    struct GetAdditionalFilesForCheckinInputs
    {
        /**
         * The item revision
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRevision;
        /**
         * The full file path and file names.
         */
        std::vector< std::string > filenames;
    };

    /**
     * The structure contains the item revision and vector of CommitDatasetInfo structure.
     */
    struct GetAdditionalFilesForCheckinOutputs
    {
        /**
         * The item revision
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRevision;
        /**
         * The dataset information.
         */
        std::vector< Teamcenter::Services::Documentmanagement::_2008_06::Documentcontrol::CommitDatasetInfo > datasetInfos;
    };

    /**
     * The structure contains vector of GetAdditionalFilesForCheckinOutputs and the serviceData.
     */
    struct GetAdditionalFilesForCheckinOutputsResponse
    {
        /**
         * The vector of GetAdditionalFilesForCheckinOutputs.
         */
        std::vector< Teamcenter::Services::Documentmanagement::_2008_06::Documentcontrol::GetAdditionalFilesForCheckinOutputs > outs;
        /**
         * The service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * The structure contains the <b>ItemRevision</b> and vector of file names and the check
     * in mode.
     */
    struct GetCheckinModeAndFilesOutputs
    {
        /**
         * The <b>ItemRevision</b> business object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRevision;
        /**
         * The list of file names that are currently downloaded locally when the <b>ItemRevision</b>
         * was checked out
         */
        std::vector< std::string > filenames;
        /**
         * The CheckIn mode
         */
        std::string mode;
    };

    /**
     * The structure contains vector of getCheckinModeAndFilesOutput structure and serviceData.
     */
    struct GetCheckinModeAndFilesOutputsResponse
    {
        /**
         * The list of Struct <code>GetCheckinModeAndFilesOutputs</code>
         */
        std::vector< Teamcenter::Services::Documentmanagement::_2008_06::Documentcontrol::GetCheckinModeAndFilesOutputs > outs;
        /**
         * The Service Data. Partial errors and failures are updated and returned through this
         * object
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Post create information
     */
    struct PostCreateInfo
    {
        /**
         * The <b>ItemRevision</b> business object that is newly created
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRevision;
        /**
         * The list of <code>CommitDatasetInfo</code> struct
         */
        std::vector< Teamcenter::Services::Documentmanagement::_2008_06::Documentcontrol::CommitDatasetInfo > commitInfos;
    };

    /**
     * Document Management Post Create Inputs
     */
    struct PostCreateInputs
    {
        /**
         * The client id
         */
        std::string clientId;
        /**
         * The newly created <b>ItemRevision</b>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRevision;
        /**
         * Attached file names
         */
        std::vector< std::string > fileNames;
    };

    /**
     * Post Create Response structure
     */
    struct PostCreateResponse
    {
        /**
         * List of <code>PostCreateInfo</code> struct
         */
        std::vector< Teamcenter::Services::Documentmanagement::_2008_06::Documentcontrol::PostCreateInfo > output;
        /**
         * The Service Data. Partial errors and failures are updated and returned through this
         * object
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation is used in conjunction with the getCheckinModeAndFiles operation during
     * the Check In process. getCheckinModeAndFiles takes a list of ItemRevision objects
     * that have been checked out, and returns the list of source files that have been downloaded
     * to the client. This operation takes the list of downloaded files returned by getCheckinModeAndFiles,
     * and returns the subset of those files that are eligible for Check In.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Check In</b>
     * <br>
     * <br>
     * This method is called after the getCheckinModeAndFiles operation, but before the
     * files are checked in.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getCheckinModeAndFiles
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Document Management - Application to manage documents in Teamcenter; including managing
     * structured documents; rendition management; and digital rights management integrations.
     *
     * @param inputs
     *        The input is vector of GetAdditionalFilesForCheckinInputs structure.
     *
     * @return
     *         A vector of the GetAdditionalFilesForCheckinOutputs structure and a ServiceData structure
     *         that contains the status of the operation, along with any errors encountered in the
     *         process.
     *         <br>
     *         <br>
     *         Following are some possible errors return in the ServiceData:
     *         <br>
     *         <ul>
     *         <li type="disc">9025&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *         Dataset type name is invalid.
     *         </li>
     *         <li type="disc">9306&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     *         Creation failed. Unable to generate a legal dataset ID.
     *         </li>
     *         <li type="disc">38022&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The
     *         Object type is invalid for property name.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Documentmanagement::_2008_06::Documentcontrol::GetAdditionalFilesForCheckinOutputsResponse getAdditionalFilesForCheckin ( const std::vector< Teamcenter::Services::Documentmanagement::_2008_06::Documentcontrol::GetAdditionalFilesForCheckinInputs >& inputs ) = 0;

    /**
     * Get the CheckIn mode and files for <b>ItemRevision</b> business objects.  This is
     * called before CheckIn to get from the server the source files that are currently
     * checked out and downloaded locally and how the system is going to search for translated
     * files locally for CheckIn. The information here is going to be used to search additional
     * files in the client.  If the <b>ItemRevision</b> business object is under Item Revision
     * Definition Configuration (<b>IRDC</b>), the CheckIn mode value is retrieved from
     * the <b>IRDC</b> object; otherwise it will be an empty string.
     * <br>
     * CheckIn mode is used to check in translated files that are already in the directory
     * with the source file or the first level subdirectory.
     * <br>
     * There are three CheckIn modes:
     * <br>
     * <ul>
     * <li type="disc">Same File Name: Attaches and checks in the derived files only if
     * they have the same name as the source dataset.
     * </li>
     * <li type="disc">Any File Name: Attaches and checks in the derived files no matter
     * what names they have.
     * </li>
     * <li type="disc">None: Does not attach and check in any derived files.
     * </li>
     * </ul>
     * <br>
     * Refers to Business Modeler IDE Guide > Creating data model objects to represent objects
     * in Teamcenter > Working with document management > Create an Item Revision definition
     * configuration (<b>IRDC</b>) for more information, the Checkin mode is defined by
     * Derived Visualization Files to Checkin from the <b>IRDC</b> Checkin Page Info tab.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Check in ItemRevision under IRDC control</b>
     * <br>
     * When a user checks out an <b>ItemRevision</b> business object under <b>IRDC</b> control,
     * the user has the option to download the source files into user local machine.  If
     * the user then checks in the <b>ItemRevision</b>, the system will search for the translated
     * files in the source file directory according to the specified CheckIn mode. This
     * functionality supports client side rendering to provide the derived datasets.
     * <br>
     * For example, there is case where some AutoCAD file cannot be converted to a certain
     * format by the server; user can find the translated files in the local directory to
     * check in instead.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Document Management - Application to manage documents in Teamcenter; including managing
     * structured documents; rendition management; and digital rights management integrations.
     *
     * @param inputs
     *        The vector of <b>ItemRevision</b>s to be checked in
     *
     * @return
     *         A list of the <code>GetCheckinModeAndFilesOutputs</code>, one for each <b>ItemRevision</b>
     *         business object, and a <code>ServiceData</code>. The <code>GetCheckinModeAndFilesOutputs</code>
     *         structure contains the <b>ItemRevision</b> business object, a list of file names
     *         and the CheckIn mode.  If there are no source files, the list of file names will
     *         be empty.  If the <b>ItemRevision</b> is not under <b>IRDC</b> control, the CheckIn
     *         mode will be empty string. If the <b>ItemRevision</b> is under <b>IRDC</b> control,
     *         the CheckIn mode string can be 1 (represents Same File Name) or 2 (represents Any
     *         File Name) or 0 (represents None).
     *         <br>
     *         Following are some possible errors return in the <code>ServiceData</code>:
     *         <br>
     *         <ul>
     *         <li type="disc">38022&nbsp;&nbsp;&nbsp;&nbsp;The Object type is invalid for property
     *         name
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Documentmanagement::_2008_06::Documentcontrol::GetCheckinModeAndFilesOutputsResponse getCheckinModeAndFiles ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  >& inputs ) = 0;

    /**
     * This operation is to be called by the client after the creation of the <b>ItemRevision</b>
     * business object, if there are local files to be attached to the newly created <b>ItemRevision</b>.
     * For <b>ItemRevision</b> under Item Revision Definition Control (<b>IRDC</b>) it will
     * replace any datasets copied from a template with new datasets for the local files.
     * The client will then need to import the local files in the volume based on the return
     * information from the SOA.  For <b>ItemRevision</b> not under <b>IRDC</b> control,
     * the commitInfos list field from the return <code>PostCreateInfo</code> structure
     * for this <b>ItemRevision</b> will be empty.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Create new item from the RAC</b>
     * <br>
     * During the new item create on RAC, if the <b>ItemRevision</b> business object is
     * under <b>IRDC</b> control,  the Attach Files panel will be enabled in the create
     * wizard dialog,  if user choose to attach local files in the Attach Files panel, the
     * template files for the IRDC will be replaced for the newly created <b>ItemRevision</b>
     * business object, and instead the new datasets will be created for the local files;
     * if user choose not to attach any local files in the Attach Files panel, then the
     * template files for the IRDC will be used for the newly created <b>ItemRevision</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Document Management - Application to manage documents in Teamcenter; including managing
     * structured documents; rendition management; and digital rights management integrations.
     *
     * @param input
     *        input is the list of <code>PostCreateInput</code> structure, which contains client
     *        id, <b>ItemRevision</b> business object and list of file names
     *
     * @return
     *         A list of <code>PostCreateInfo</code> and a <code>ServiceData</code>. <code>PostCreateInfo</code>
     *         contains a list of <b>ItemRevision</b> business objects and a list of <code>CommitDatasetInfo</code>
     *         structure. <code>ServiceData</code> element containing status of operation and any
     *         errors encountered in the process.
     *         <br>
     *         Following are some possible errors return in the <code>ServiceData</code>:
     *         <br>
     *         <ul>
     *         <li type="disc">9025&nbsp;&nbsp;&nbsp;&nbsp;Dataset type name is invalid
     *         </li>
     *         <li type="disc">9306&nbsp;&nbsp;&nbsp;&nbsp;Creation failed. Unable to generate a
     *         legal dataset ID.
     *         </li>
     *         <li type="disc">38022&nbsp;&nbsp;&nbsp;&nbsp;The Object type is invalid for property
     *         name
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Documentmanagement::_2008_06::Documentcontrol::PostCreateResponse postCreate ( const std::vector< Teamcenter::Services::Documentmanagement::_2008_06::Documentcontrol::PostCreateInputs >& input ) = 0;


protected:
    virtual ~Documentcontrol() {}
};
            }
        }
    }
}

#include <teamcenter/services/documentmanagement/DocumentManagement_undef.h>
#endif

