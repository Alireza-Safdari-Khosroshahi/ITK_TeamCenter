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

#ifndef TEAMCENTER_SERVICES_CORE_FILEMANAGEMENTSERVICE_HXX
#define TEAMCENTER_SERVICES_CORE_FILEMANAGEMENTSERVICE_HXX

#include <teamcenter/services/core/_2006_03/Filemanagement.hxx>
#include <teamcenter/services/core/_2007_01/Filemanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            class FilemanagementService;

/**
 * This service implements operations which support the File Management System (FMS).
 * This service contains operations that run in the Teamcenter Server context to supply
 * business logic functionality which controls the flow of user data.  The data being
 * controlled by this service exists within files, as represented by <b>ImanFile</b>
 * objects within the Teamcenter Product Lifecycle Management (PLM) system.
 * <br>
 * This service provides the following file management use cases:
 * <br>
 * <ul>
 * <li type="disc">Manage PLM file downloads (reading a file from a Teamcenter volume).
 * </li>
 * <li type="disc">Manage PLM file uploads (adding a file to a Teamcenter volume).
 * </li>
 * </ul>
 * <br>
 * This service interoperates with the File Management System (FMS), and is intended
 * to be used with FMS client APIs.  The set of FMS client APIs includes various forms
 * and implementations of the FMS Client Cache (FCC) Client Proxy and the FMS Server
 * Cache (FSC) Client Proxy.
 * <br>
 * Please see the Teamcenter glossary for the definitions of any terms with which you
 * may not be familiar.  Please see the Teamcenter documentation for summary information
 * regarding the File Management System (FMS), or any other parts of the Teamcenter
 * product with which you are not familiar.
 * <br>
 * NOTE: The File Management System (FMS) APIs are unpublished and proprietary intellectual
 * property of Siemens Product Lifecycle Management (Siemens PLM).  The few published
 * portions of this service, which were created prior to the advent of unpublished Teamcenter
 * service operations, are not particularly useful to clients, for whom access to the
 * File Management System (FMS) APIs is unavailable.  This entire service is therefore
 * considered unpublished and proprietary intellectual property of Siemens Product Lifecycle
 * Management (Siemens PLM).
 * <br>
 * It is seldom necessary for a client to invoke the operations of this service directly.
 * The com.teamcenter.soa.client.FileManagementUtility class provides a simplified
 * interface for most use cases that require the use of this service.  The FileManagementUtility
 * class coordinates the task sequencing and error management between the <b>FileManagementService</b>
 * and the appropriate FMS client API, as described in this document.
 * <br>
 * FileManagementUtility supports both FCC client and FSC server interfaces.  Please
 * be sure to construct the form of FileManagementUtility instance appropriate for your
 * context.  The FSC interface should be used by all web tier services or applications.
 * The default, or FCC, form should only be used by client applications.
 * <br>
 * FileManagementUtility is a heavyweight, but reusable, object.  Please cache and reuse
 * the FileManagementUtility object within your application, whenever possible.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoacorestrongmngd.dll
 * </li>
 * <li type="disc">libtcsoacoretypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOACLIENTMNGD_API FilemanagementService
    : public Teamcenter::Services::Core::_2006_03::Filemanagement,
             public Teamcenter::Services::Core::_2007_01::Filemanagement
{
public:
    static FilemanagementService* getService( Teamcenter::Soa::Client::Connection* );


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

    /**
     * This operation gets the tickets for the desired files to be uploaded to the transient
     * volume. These tickets can be used to upload corresponding files via <code>FileManagementUtility::putFileViaTicket</code>.
     * The <code>TransientFileInfo</code> contains the basic information for a file to be
     * uploaded such as file name, file type and whether the file should be deleted after
     * reading.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation supports the uploading of files into the FMS transient volume.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * SOA Framework - The framework to expose the Teamcenter services to the clients.
     * The framework provices the means to define service interfaces (through BMIDE) and
     * exposes those in Java, C++, C# client bindings. The Session service is part of the
     * framework.
     *
     * @param transientFileInfos
     *        List containing the details of the files for which the tickets are requested.
     *
     * @return
     *         A <code>GetTransientFileTicketsResponse</code> structure, which will contain the
     *         file tickets and status of the operation.
     *
     */
    virtual Teamcenter::Services::Core::_2007_01::Filemanagement::GetTransientFileTicketsResponse getTransientFileTicketsForUpload ( const std::vector< Teamcenter::Services::Core::_2007_01::Filemanagement::TransientFileInfo >& transientFileInfos ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("FilemanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif

