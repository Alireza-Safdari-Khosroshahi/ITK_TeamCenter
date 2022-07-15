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

#ifndef TEAMCENTER_SERVICES_CORE__2007_01_FILEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CORE__2007_01_FILEMANAGEMENT_HXX



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
            namespace _2007_01
            {
                class Filemanagement;

class TCSOACLIENTMNGD_API Filemanagement
{
public:

    struct GetTransientFileTicketsResponse;
    struct TransientFileInfo;
    struct TransientFileTicketInfo;

    /**
     * Holds the response returned from the <code>getTransientFileTicketsForUpload</code>
     * operation.
     */
    struct GetTransientFileTicketsResponse
    {
        /**
         * The requested transient files ticket information.
         */
        std::vector< Teamcenter::Services::Core::_2007_01::Filemanagement::TransientFileTicketInfo > transientFileTicketInfos;
        /**
         * This contains the status of the operation.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Holds the basic information for a file to be uploaded.
     */
    struct TransientFileInfo
    {
        /**
         * The name of the file. Path of the file should not be supplied.
         */
        std::string fileName;
        /**
         * True if the file is of binary type, false for text files.
         */
        bool isBinary;
        /**
         * True if the file should be deleted from temporary storage after it is read.
         */
        bool deleteFlag;
    };

    /**
     * Holds the file information with a ticket added.
     */
    struct TransientFileTicketInfo
    {
        /**
         * The unique identifier of the file to be uploaded.
         */
        Teamcenter::Services::Core::_2007_01::Filemanagement::TransientFileInfo transientFileInfo;
        /**
         * Holds the basic information for a file to be uploaded.
         */
        std::string ticket;
    };




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


protected:
    virtual ~Filemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif

