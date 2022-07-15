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

#ifndef TEAMCENTER_SERVICES_CORE__2006_03_FILEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CORE__2006_03_FILEMANAGEMENT_HXX

#include <teamcenter/soa/client/model/Dataset.hxx>
#include <teamcenter/soa/client/model/ImanFile.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2006_03
            {
                class Filemanagement;

class TCSOACLIENTMNGD_API Filemanagement
{
public:

    struct CommitDatasetFileInfo;
    struct DatasetFileInfo;
    struct DatasetFileTicketInfo;
    struct FileTicketsResponse;
    struct GetDatasetWriteTicketsInputData;
    struct GetDatasetWriteTicketsResponse;

    /**
     * A map of the input <b>ImanFile</b> objects to FMS read tickets used to read the file
     * from the Teamcenter volume.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanFile> , std::string > TicketMap;

    /**
     * Used in the <code>commitDatasetFiles</code> operation to pass information for committing
     * <b>ImanFile</b> instances uploaded to a Teamcenter volume with the associated <b>Dataset</b>
     * instances.
     */
    struct CommitDatasetFileInfo
    {
        /**
         * The <b>Dataset</b> object to which the <b>ImanFile</b> object(s) representing the
         * data files uploaded to the Teamcenter volume.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * If this flag is true, a new <b>DatasetRevision</b> will be created to reference the
         * new set of files uploaded to the Teamcenter volume.  Any existing <b>DatasetRevision</b>
         * will be unaltered, but the new <b>DatasetRevision</b> will have the files attached
         * as named references.
         * <br>
         * If this flag is false, the uploaded files are attached to the current most recent
         * <b>DatasetRevision</b> of this <b>Dataset</b> as named references.
         * <br>
         */
        bool createNewVersion;
        /**
         * A vector of <b>DatasetFileTicketInfo</b> objects representing each <b>ImanFile</b>
         * object attached to the given <b>Dataset</b> as a named reference.
         */
        std::vector< Teamcenter::Services::Core::_2006_03::Filemanagement::DatasetFileTicketInfo > datasetFileTicketInfos;
    };

    /**
     * The structure defining the basic information for a file to be uploaded to a <b>Dataset</b>.
     */
    struct DatasetFileInfo
    {
        /**
         * An identifier defined by the caller to track the related object.
         * <br>
         */
        std::string clientId;
        /**
         * The name of the file to be uploaded.  This is the filename only and should not contain
         * the path to the filename.
         */
        std::string fileName;
        /**
         * The named reference relation to the file.
         */
        std::string namedReferencedName;
        /**
         * A flag to indicate if the file is text (TRUE) or binary (FALSE).
         */
        bool isText;
        /**
         * A flag to indicate if the file may be overwritten (TRUE) or not (FALSE).
         */
        bool allowReplace;
    };

    /**
     * A structure representing an <b>ImanFile</b> object attached to a given <b>Dataset</b>
     * as a named reference.
     */
    struct DatasetFileTicketInfo
    {
        /**
         * The structure defining the basic information for a file to be uploaded to a <b>Dataset</b>.
         */
        Teamcenter::Services::Core::_2006_03::Filemanagement::DatasetFileInfo datasetFileInfo;
        /**
         * The FMS write ticket used to transfer the file to the appropriate Teamcenter volume.
         */
        std::string ticket;
    };

    /**
     * Holds a <code>ServiceData</code> object and a map (<b>ImanFile</b>, string) of read
     * tickets.  If the request completes successfully, each input <b>ImanFile</b> object
     * will appear as a key in the output map
     * <br>
     * and the string value associated with each entry will be a valid FMS ticket associated
     * with that <b>ImanFile</b>.  Returned from the <code>getFileReadTickets</code> operation.
     */
    struct FileTicketsResponse
    {
        /**
         * A map of the input <b>ImanFile</b> objects to FMS tickets used to access files in
         * the Teamcenter volume.
         */
        TicketMap tickets;
        /**
         * The Teamcenter Services structure used to return status of the operation.  Any errors
         * that occurred during the operation are returned here.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * A vector of <code>GetDatasetWriteTicketsInputData</code> structures which holds the
     * <b>Dataset</b> objects and related <code>DatasetFileTicketInfo</code>.  The calling
     * client must construct this input.
     */
    struct GetDatasetWriteTicketsInputData
    {
        /**
         * The <b>Dataset</b> object to which the <b>ImanFile</b> object(s) representing the
         * data files uploaded to the Teamcenter volume are associated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  dataset;
        /**
         * If this flag is true, a new <b>DatasetRevision</b> will be created to reference the
         * new set of files uploaded to the Teamcenter volume.  Any existing <b>DatasetRevision</b>
         * will be unaltered, but the new <b>DatasetRevision</b> will have the files attached
         * as named references.
         * <br>
         * If this flag is false, the uploaded files are attached to the current most recent
         * <b>DatasetRevision</b> of this <b>Dataset</b> as named references.
         * <br>
         */
        bool createNewVersion;
        /**
         * A vector of <code>DatasetFileInfo</code> structures where each contains information
         * specific to each <b>Dataset</b> to be created.
         */
        std::vector< Teamcenter::Services::Core::_2006_03::Filemanagement::DatasetFileInfo > datasetFileInfos;
    };

    /**
     * Holds a <code>ServiceData</code> object and a vector of dataset commit information.
     * If the request completes successfully, the information in the vector can be used
     * to commit the <b>Dataset</b> to the database.
     */
    struct GetDatasetWriteTicketsResponse
    {
        /**
         * A vector of <code>CommitDatasetFileInfo</code> structures.
         */
        std::vector< Teamcenter::Services::Core::_2006_03::Filemanagement::CommitDatasetFileInfo > commitInfo;
        /**
         * The Teamcenter Services structure used to return status of the operation.  Any errors
         * that occurred during the operation are returned here.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation is invoked after successfully uploading a file to a Teamcenter volume
     * with a File Management System (FMS) client API.  The set of FMS client APIs includes
     * various forms and implementations of the FMS Client Cache (FCC) Client Proxy and
     * the FMS Server Cache (FSC) Client Proxy.  You only need to use one of the available
     * APIs to upload the file to the Teamcenter volume.
     * <br>
     * <br>
     * This operation supports the upload (addition) of files to a Teamcenter volume.  The
     * mechanism for a client application adding files to a Teamcenter volume contains several
     * steps.  This mechanism is implemented in the <code>com.teamcenter.soa.client.FileManagementUtility</code>
     * class, which provides this functionality to clients in a consistent, reusable package.
     * <br>
     * 1.&nbsp;&nbsp;&nbsp;&nbsp;Construct <b>ImanFile</b> objects in the Teamcenter database,
     * in a manner that will make the <b>ImanFile</b> objects visible and accessible to
     * clients.  This is typically accomplished by attaching the <b>ImanFile</b> objects
     * to one or more <b>Dataset</b> objects as a named reference, but this is not a requirement.
     * You will need one <b>ImanFile</b> object for each data file that you upload to the
     * Teamcenter volume.  (This needs to be done by the calling application prior to calling
     * the FileManagementUtility methods, which will perform the remaining steps.)
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;Invoke the <code>FileManagementService::getDatasetWriteTickets</code>
     * operation to obtain an FMS write ticket for each file / <b>ImanFile</b> object.
     * <br>
     * 3.&nbsp;&nbsp;&nbsp;&nbsp;Use a File Management System (FMS) Application Programmatic
     * Interface (API) to upload the files to the Teamcenter volume.  (A list of methods
     * which perform this upload is provided below.)
     * <br>
     * The client application is responsible for making sure that the FMS API method used
     * to upload the files indicates that the file uploads were successful.
     * <br>
     * Check the documentation for each API to determine how it reacts to upload failures.
     * <br>
     * Some upload APIs are defined in such a way that a single result code is returned
     * to the caller, or a single Exception thrown, to indicate that the bulk file upload
     * was entirely unsuccessful.  These APIs typically roll back all the successfully uploaded
     * files before returning to the caller.
     * <br>
     * Some APIs may accept a flag indicating whether uploads should continue when an error
     * is encountered.
     * <br>
     * Other APIs return a separate result code for each file, indicating which files were
     * successfully uploaded to a Teamcenter volume and which uploads failed.
     * <br>
     * It is the responsibility of the client application to either commit or rollback all
     * successfully uploaded files.  Files that failed to upload need not be rolled back.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;a.&nbsp;&nbsp;&nbsp;&nbsp;Client applications must not invoke
     * the <code>commitDatasetFiles</code> operation on files that did not successfully
     * upload to the Teamcenter volume.  This causes file access errors downstream, when
     * clients attempt to reference (or download) the file data, which will be missing from
     * the Teamcenter volume.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;b.&nbsp;&nbsp;&nbsp;&nbsp;In the event of a partial upload
     * success (some files uploaded successfully, but others did not), it is the responsibility
     * of the client application to determine whether it is acceptable in context to commit
     * the successfully uploaded files to the Teamcenter database.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;i.&nbsp;&nbsp;&nbsp;&nbsp;If not,
     * then there is a companion FMS API method to rollback the successfully uploaded files.
     * The rollback method removes the files from the Teamcenter volume.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ii.&nbsp;&nbsp;&nbsp;&nbsp;If so,
     * then it is the responsibility of the client application to remove the<code> CommitDatasetFileInfo</code>
     * structures corresponding to the files that did not successfully upload to the Teamcenter
     * volume from the input list passed to the <code>FileManagementService::commitDatasetFiles</code>
     * operation.
     * <br>
     * 4.&nbsp;&nbsp;&nbsp;&nbsp;The client invokes the <code>FileManagementService::commitDatasetFiles</code>
     * operation on the successfully uploaded files.  This step makes the data associated
     * with the <b>ImanFile</b> objects and the FMS write tickets accessible to other authorized
     * clients through Teamcenter.
     * <br>
     * <br>
     * File Management System (FMS) methods for uploading the file to the Teamcenter volume:
     * <br>
     * 1.&nbsp;&nbsp;&nbsp;&nbsp;FCCClientProxy.lib (C binding):
     * <br>
     * <ul>
     * <li type="disc"><code>FCC_UploadFileToPLM</code>() uploads a file to a Teamcenter
     * volume.
     * </li>
     * <li type="disc"><code>FCC_UploadFilesToPLM</code>() uploads multiple files to a Teamcenter
     * volume.
     * </li>
     * <li type="disc"><code>FCC_RollbackFile</code>() removes a file from a Teamcenter
     * volume.
     * </li>
     * <li type="disc"><code>FCC_RollbackFiles</code>() removes multiple files from a Teamcenter
     * volume.
     * </li>
     * </ul>
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;fccjavaclientproxy.jar (Java binding):
     * <br>
     * <ul>
     * <li type="disc"><code>FileCacheProxy.UploadFileToPLM</code>() uploads a file to a
     * Teamcenter volume.
     * </li>
     * <li type="disc"><code>FileCacheProxy.UploadFilesToPLM</code>() uploads multiple files
     * to a Teamcenter volume.
     * </li>
     * <li type="disc"><code>FileCacheProxy.RollbackFile</code>() removes a file from a
     * Teamcenter volume.
     * </li>
     * <li type="disc"><code>FileCacheProxy.RollbackFiles</code>() removes multiple files
     * from a Teamcenter volume.
     * </li>
     * </ul>
     * <br>
     * 3.&nbsp;&nbsp;&nbsp;&nbsp;FSCClientProxy.dll or FSCNativeClientProxy.dll (C binding):
     * <br>
     * <ul>
     * <li type="disc"><code>FSC_Upload</code>() uploads a file to a Teamcenter volume.
     * </li>
     * <li type="disc"><code>FSC_UploadMultiple</code>() uploads multiple files to a Teamcenter
     * volume.
     * </li>
     * <li type="disc"><code>FSC_Rollback</code>() removes a file from a Teamcenter volume.
     * </li>
     * <li type="disc"><code>FSC_RollbackMultiple</code>() removes multiple files from a
     * Teamcenter volume.
     * </li>
     * </ul>
     * <br>
     * 4.&nbsp;&nbsp;&nbsp;&nbsp;fscjavaclientproxy.jar (Java binding)
     * <br>
     * <ul>
     * <li type="disc"><code>CommonsFSCWholeFileIOImpl.upload</code>() (NOTE: Two overloads)
     * uploads one or more files to a Teamcenter volume.
     * </li>
     * <li type="disc"><code>CommonsFSCWholeFileIOImpl.rollback</code>() (NOTE: Two overloads)
     * removes one or more files from a Teamcenter volume.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation supports the upload (addition) of files representing named references
     * of a <b>Dataset</b> object to a Teamcenter volume.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * getDatasetWriteTickets
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param commitInput
     *        The vector of <code>CommitDatasetFileInfo</code> structures returned in the commitInfo
     *        element of the <code>GetDatasetWriteTicketsResponse</code> structure returned by
     *        the <code>FileManagementService::getDatasetWriteTickets</code> operation.  In the
     *        event of partial upload success, it is the responsibility of the client caller to
     *        remove all of the <code>CommitDatasetFileInfo</code> structures representing the
     *        files that failed to upload to the Teamcenter volume from this vector, before invoking
     *        the <code>FileManagementService::commitDatasetFiles</code> operation.
     *
     * @return
     *         This operation returns only a <code>Teamcenter::Soa::Server::ServiceData</code> object.
     *         This Teamcenter Services structure is used to return status of the operation.  Any
     *         errors that occurred during the operation are returned here.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData commitDatasetFiles ( const std::vector< Teamcenter::Services::Core::_2006_03::Filemanagement::CommitDatasetFileInfo >& commitInput ) = 0;

    /**
     * This operation obtains File Management System (FMS) write tickets and file storage
     * information for a set of supplied <b>Dataset</b> objects. The write tickets are used
     * to transfer files from a local storage to Teamcenter volume, and the file storage
     * information can be used to commit <b>Dataset</b> objects referencing those transferred
     * files.
     * <br>
     * The caller will provide a vector of <code>GetDatasetWriteTicketsInputData</code>
     * objects that contains one or more <b>Dataset</b> objects and information about each
     * associated file (e.g., filename, text/binary flag, etc.).  Upon return, the <code>GetDatasetWriteTicketsResponse</code>
     * object will contain FMS write tickets that can be used to upload the file to the
     * Teamcenter volume, and <b>Dataset</b> information that can be used to commit the
     * changes to the database by using the <code>FileManagementService</code> <code>commitDatasetFiles</code>()
     * operation.
     * <br>
     * This operation supports the upload (addition) of files representing named references
     * of a <b>Dataset</b> object to a Teamcenter volume.  The mechanism for a client application
     * adding files to a Teamcenter volume contains several steps.  This mechanism is implemented
     * in the <code>com.teamcenter.soa.client.FileManagementUtility</code> class, which
     * provides this functionality to clients in a consistent, reusable package.
     * <br>
     * 1.&nbsp;&nbsp;&nbsp;&nbsp;Create <b>Dataset</b> objects that reference the data files
     * being imported into Teamcenter.  (This needs to be done by the calling application
     * prior to calling the <code>FileManagementUtility</code> methods, which will perform
     * the remaining steps.)
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;Invoke the <code>FileManagementService::getDatasetWriteTickets</code>()
     * operation to obtain an FMS write ticket for each file / ImanFile object.
     * <br>
     * 3.&nbsp;&nbsp;&nbsp;&nbsp;Use a File Management System (FMS) Application Programmatic
     * Interface (API) to upload the files to the Teamcenter volume.  (A list of methods
     * which perform this upload is provided below.)
     * <br>
     * The client application is responsible for making sure that the FMS API method used
     * to upload the files indicates that the file uploads were successful.
     * <br>
     * Check the documentation for each API to determine how it reacts to upload failures.
     * <br>
     * Some upload APIs are defined in such a way that a single result code is returned
     * to the caller, or a single Exception thrown, to indicate that the bulk file upload
     * was entirely unsuccessful.  These APIs typically roll back all the successfully uploaded
     * files before returning to the caller.
     * <br>
     * Some APIs may accept a flag indicating whether uploads should continue when an error
     * is encountered.
     * <br>
     * Other APIs return a separate result code for each file, indicating which files were
     * successfully uploaded to a Teamcenter volume and which uploads failed.
     * <br>
     * It is the responsibility of the client application to either commit or rollback all
     * successfully uploaded files.  Files that failed to upload need not be rolled back.
     * <br>
     * a.&nbsp;&nbsp;&nbsp;&nbsp;Client applications must not invoke the <code>FileManagementService::commitDatasetFiles</code>()
     * operation on files that did not successfully upload to the Teamcenter volume.  This
     * ca uses file access errors downstream, when clients attempt to reference (or download)
     * the file data, which will be missing from the Teamcenter volume.
     * <br>
     * b.&nbsp;&nbsp;&nbsp;&nbsp;In the event of a partial upload success (some files uploaded
     * successfully, but others did not), it is the responsibility of the client application
     * to determine whether it is acceptable in context to commit the successfully uploaded
     * files to the Teamcenter system.
     * <br>
     * i.&nbsp;&nbsp;&nbsp;&nbsp;If not, then there is a companion FMS API method to rollback
     * the successfully uploaded files.  The rollback method removes the files from the
     * Teamcenter volume.
     * <br>
     * ii.&nbsp;&nbsp;&nbsp;&nbsp;If so, then it is the responsibility of the client application
     * to avoid including a <code>CommitDatasetFileInfo</code> structure corresponding to
     * the files that did not successfully upload to the Teamcenter volume in the input
     * list passed to the <code>FileManagementService::commitDatasetFiles</code>() operation.
     * <br>
     * 4.&nbsp;&nbsp;&nbsp;&nbsp;The client invokes the <code>FileManagementService::commitDatasetFiles</code>()
     * operation on the successfully uploaded files.  This step makes the data associated
     * with the Dataset and ImanFile objects accessible to other authorized clients through
     * the Teamcenter system.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;
     * <br>
     * File Management System (FMS) methods for uploading the file to the PLM volume:
     * <br>
     * 1.&nbsp;&nbsp;&nbsp;&nbsp;FCCClientProxy.lib (C binding):
     * <br>
     * <ul>
     * <li type="disc"><code>FCC_UploadFileToPLM</code>() uploads a file to a Teamcenter
     * volume.
     * </li>
     * <li type="disc"><code>FCC_UploadFilesToPLM</code>() uploads multiple files to a Teamcenter
     * volume.
     * </li>
     * <li type="disc"><code>FCC_RollbackFile</code>() removes a file from a Teamcenter
     * volume.
     * </li>
     * <li type="disc"><code>FCC_RollbackFiles</code>() removes multiple files from a Teamcenter
     * volume.
     * </li>
     * </ul>
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;fccjavaclientproxy.jar (Java binding):
     * <br>
     * <ul>
     * <li type="disc"><code>FileCacheProxy.UploadFileToPLM</code>() uploads a file to a
     * Teamcenter volume.
     * </li>
     * <li type="disc"><code>FileCacheProxy.UploadFilesToPLM</code>() uploads multiple files
     * to a Teamcenter volume.
     * </li>
     * <li type="disc"><code>FileCacheProxy.RollbackFile</code>() removes a file from a
     * Teamcenter volume.
     * </li>
     * <li type="disc"><code>FileCacheProxy.RollbackFiles</code>() removes multiple files
     * from a Teamcenter volume.
     * </li>
     * </ul>
     * <br>
     * 3.&nbsp;&nbsp;&nbsp;&nbsp;FSCClientProxy.dll or FSCNativeClientProxy.dll (C binding):
     * <br>
     * <ul>
     * <li type="disc"><code>FSC_Upload</code>() uploads a file to a Teamcenter volume.
     * </li>
     * <li type="disc"><code>FSC_UploadMultiple</code>()  uploads multiple files to a Teamcenter
     * volume.
     * </li>
     * <li type="disc"><code>FSC_Rollback</code>() removes a file from a Teamcenter volume.
     * </li>
     * <li type="disc"><code>FSC_RollbackMultiple</code>() removes multiple files from a
     * Teamcenter volume.
     * </li>
     * </ul>
     * <br>
     * 4.&nbsp;&nbsp;&nbsp;&nbsp;fscjavaclientproxy.jar (Java binding)
     * <br>
     * <ul>
     * <li type="disc"><code>CommonsFSCWholeFileIOImpl.upload</code>() (NOTE: Two overloads)
     * uploads one or more files to a Teamcenter volume.
     * </li>
     * <li type="disc"><code>CommonsFSCWholeFileIOImpl.rollback</code>() (NOTE: Two overloads)
     * removes one or more files from a Teamcenter volume.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation supports the upload (addition) of files representing named references
     * of a <b>Dataset</b> object to a Teamcenter volume.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param inputs
     *        A vector of <code>GetDatasetWriteTicketsInputData</code> structures which holds the
     *        <b>Dataset</b> objects and related <code>DatasetFileTicketInfo</code>.  The calling
     *        client must construct this input.
     *
     * @return
     *         This operation returns a <code>GetDatasetWriteTicketsResponse</code> object.  The
     *         returned object contains a vector of information used to commit the <b>Dataset</b>
     *         to the database by way of a followup call to <code>commitDatasetFiles</code>().
     *
     */
    virtual Teamcenter::Services::Core::_2006_03::Filemanagement::GetDatasetWriteTicketsResponse getDatasetWriteTickets ( const std::vector< Teamcenter::Services::Core::_2006_03::Filemanagement::GetDatasetWriteTicketsInputData >& inputs ) = 0;

    /**
     * This operation obtains File Management System (FMS) read tickets for a set of supplied
     * <br>
     * <b>ImanFile</b> objects.  The supplied tickets are used to transfer files from a
     * Teamcenter volume
     * <br>
     * to local storage.  The <code>files</code> input parameter contains a list of the
     * <b>ImanFile</b> objects to be read
     * <br>
     * from the Teamcenter volume and transferred to local storage.
     * <br>
     * FMS requires tickets for all file transfers to and from Teamcenter volumes.  An FMS
     * read ticket is
     * <br>
     * required to obtain a file from a Teamcenter volume, while an FMS write ticket is
     * needed to place a file in the Teamcenter volume.  It is often times more expedient
     * to request several tickets at one time, especially if it is known ahead of time that
     * many files will need to be moved.  For this reason, the caller may supply multiple
     * <b>ImanFile</b> objects, for which FMS tickets are desired, in the input vector.
     * <br>
     * The mechanism for a client application downloading files from a Teamcenter volume
     * contains only a few steps.  This mechanism is implemented in the <code>com.teamcenter.soa.client.FileManagementUtility</code>
     * class, which provides this functionality to clients in a consistent, reusable package.
     * <br>
     * 1.&nbsp;&nbsp;&nbsp;&nbsp;Obtain a reference to the <b>ImanFile</b> object in the
     * Teamcenter database.  (This needs to be done by the calling application prior to
     * calling the <code>FileManagementUtility</code> methods, which will perform the remaining
     * steps.)
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;Invoke the <code>FileManagementService::getDatasetWriteTickets</code>()
     * operation to obtain an FMS read ticket for each file / <b>ImanFile</b> object.
     * <br>
     * 3.&nbsp;&nbsp;&nbsp;&nbsp;Use a File Management System (FMS) Application Programmatic
     * Interface (API) to download the files from the Teamcenter volume to local storage.
     * (A list of methods which perform this upload is provided below.)
     * <br>
     * File Management System (FMS) methods for downloading the file from the Teamcenter
     * volume to local storage:
     * <br>
     * 1.&nbsp;&nbsp;&nbsp;&nbsp;FCCClientProxy.lib (C binding):
     * <br>
     * <ul>
     * <li type="disc">FCC_DownloadFileFromPLM() downloads a file from a Teamcenter  volume
     * into the FCC cache, and returns a read only cache filename.
     * </li>
     * <li type="disc">FCC_DownloadFilesFromPLM() downloads multiple files from a Teamcenter
     * volume into the FCC cache, and returns read only cache filenames.
     * </li>
     * <li type="disc">FCC_DownloadFileToLocation() downloads a file from a Teamcenter
     * volume into a local filename specified by the caller.
     * </li>
     * <li type="disc">FCC_DownloadFilesToLocation() downloads multiple files from a Teamcenter
     * volume into local filenames specified by the caller.
     * </li>
     * </ul>
     * <br>
     * 2.&nbsp;&nbsp;&nbsp;&nbsp;fccjavaclientproxy.jar (Java binding):
     * <br>
     * <ul>
     * <li type="disc">FileCacheProxy.DownloadFileFromPLM()  downloads a file from a Teamcenter
     * volume into a local filename specified by the caller.
     * </li>
     * <li type="disc">FileCacheProxy.DownloadFilesFromPLM() downloads multiple files from
     * a Teamcenter  volume into the FCC cache, and returns read only cache filenames.
     * </li>
     * <li type="disc">FileCacheProxy.DownloadFileToLocation() downloads a file from a Teamcenter
     * volume into a local filename specified by the caller.
     * </li>
     * <li type="disc">FileCacheProxy.DownloadFilesToLocation() down loads multiple files
     * from a Teamcenter  volume into local filenames specified by the caller.
     * </li>
     * </ul>
     * <br>
     * 3.&nbsp;&nbsp;&nbsp;&nbsp;FSCClientProxy.dll or FSCNativeClientProxy.dll (C binding):
     * <br>
     * <ul>
     * <li type="disc">FSC_Download() downloads a file from a Teamcenter  volume into a
     * local filename specified by the caller.
     * </li>
     * <li type="disc">FSC_DownloadMultiple() downloads multiple files from a Teamcenter
     * volume into local filenames specified by the caller.
     * </li>
     * </ul>
     * <br>
     * 4.&nbsp;&nbsp;&nbsp;&nbsp;fscjavaclientproxy.jar (Java binding)
     * <br>
     * <ul>
     * <li type="disc"><code>CommonsFSCWholeFileIOImpl.download() (NOTE: Two overloads)
     * downloads one or more files from a Teamcenter  volume into local filenames specified
     * by the caller.</code>
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation supports the download of data files represented by <b>ImanFile</b>
     * objects from a Teamcenter volume into a local client environment.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param files
     *        A vector of <b>ImanFile</b> objects to be transferred from a
     *        <br>
     *        Teamcenter volume to local storage.  The calling client must construct this input.
     *        <br>
     *
     * @return
     *         This operation returns a <code>FileTicketsResponse</code> object, containing a map
     *         (<b>ImanFile</b>, string) of read tickets.
     *
     */
    virtual Teamcenter::Services::Core::_2006_03::Filemanagement::FileTicketsResponse getFileReadTickets ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ImanFile>  >& files ) = 0;


protected:
    virtual ~Filemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif

