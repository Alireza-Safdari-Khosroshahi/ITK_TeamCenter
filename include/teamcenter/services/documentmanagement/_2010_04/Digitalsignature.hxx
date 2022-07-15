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

#ifndef TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT__2010_04_DIGITALSIGNATURE_HXX
#define TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT__2010_04_DIGITALSIGNATURE_HXX

#include <teamcenter/soa/client/model/Dataset.hxx>


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
            namespace _2010_04
            {
                class Digitalsignature;

class TCSOADOCUMENTMANAGEMENTSTRONGMNGD_API Digitalsignature
{
public:

    struct DigitalSignSaveInput;
    struct DigtalSigningSaveResponse;

    /**
     * The digitalSigningSave input structure.
     */
    struct DigitalSignSaveInput
    {
        /**
         * The <b>Dataset</b> object that contains the named reference file to be signed.  This
         * is required.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  baseObj;
        /**
         * The FMS file ticket for uploading the signed file.  This is required.
         */
        std::string signedFileTicket;
        /**
         * The tool name that is used to sign the file.  This is required.
         */
        std::string createToolName;
        /**
         * If this is set to true, then the signature is valid; otherwise, it is not.  If the
         * signing tool does not declare the signature is valid, then the base dataset will
         * not be checkin.
         */
        bool validSignature;
        /**
         * The Teamcenter user name that completed the digitally sign operation.
         */
        std::string userNameWhoSign;
        /**
         * The timestamp of the digital signature in the signing tool.
         */
        std::string signTime;
    };

    /**
     * Digital signing save operation response
     */
    struct DigtalSigningSaveResponse
    {
        /**
         * If the<b> Dataset</b> is updated successfully, then the <b>Dataset</b> is returned.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Dataset>  basedDataset;
        /**
         * The partial error list if there is any system errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * The digitalSigningSave function will update an existing dataset that has the name
     * referenced uploaded signed file.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Document Management - Application to manage documents in Teamcenter; including managing
     * structured documents; rendition management; and digital rights management integrations.
     *
     * @param saveInput
     *        Digital signing input
     *
     * @return
     *         Return based dataset if successful.
     *
     * @deprecated
     *         As of Teamcenter 10.1, this operation has no code behind and not being used.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10.1, this operation has no code behind and not being used."))
#endif
    virtual Teamcenter::Services::Documentmanagement::_2010_04::Digitalsignature::DigtalSigningSaveResponse digitalSigningSave ( const Teamcenter::Services::Documentmanagement::_2010_04::Digitalsignature::DigitalSignSaveInput&  saveInput ) = 0;


protected:
    virtual ~Digitalsignature() {}
};
            }
        }
    }
}

#include <teamcenter/services/documentmanagement/DocumentManagement_undef.h>
#endif

