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

#ifndef TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT_DOCUMENTCONTROLSERVICE_HXX
#define TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT_DOCUMENTCONTROLSERVICE_HXX

#include <teamcenter/services/documentmanagement/_2008_06/Documentcontrol.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/documentmanagement/DocumentManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Documentmanagement
        {
            class DocumentcontrolService;

/**
 * This service provides operations that are designed to carry out necessary DocumentManagement
 * functions for ItemRevision objects that are under Item Revision Definition Configuration
 * (IRDC) control.
 * <br>
 * <br>
 * The postCreate operation is called after a new ItemRevision has been created, and
 * it notifies the server to remove the template files attached to the ItemRevision
 * and to attach user selected datasets to the newly created object.
 * <br>
 * <br>
 * The getCheckinModeAndFiles operation is used prior to performing a Check In operation.
 * It determines what files have been checked out and downloaded to the client machine,
 * and what the Check In mode is for searching for additional files for the checked
 * out files.
 * <br>
 * <br>
 * The getAdditionalFilesForCheckin operation is used when performing a Check In operation,
 * after calling the getCheckinModeAndFiles operation. The client searches for local
 * files and sends the list of files to the server using this operation. The server
 * returns the subset of those files that need to be checked in.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoadocumentmanagementstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoadocumentmanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOADOCUMENTMANAGEMENTSTRONGMNGD_API DocumentcontrolService
    : public Teamcenter::Services::Documentmanagement::_2008_06::Documentcontrol
{
public:
    static DocumentcontrolService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DocumentcontrolService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/documentmanagement/DocumentManagement_undef.h>
#endif

