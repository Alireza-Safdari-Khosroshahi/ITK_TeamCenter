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

#ifndef TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT_DIGITALSIGNATURESERVICE_HXX
#define TEAMCENTER_SERVICES_DOCUMENTMANAGEMENT_DIGITALSIGNATURESERVICE_HXX

#include <teamcenter/services/documentmanagement/_2010_04/Digitalsignature.hxx>



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
            class DigitalsignatureService;

/**
 * The DigitalSignature service provides operations for managing the digitally sign
 * <b>Dataset</b> object.
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

class TCSOADOCUMENTMANAGEMENTSTRONGMNGD_API DigitalsignatureService
    : public Teamcenter::Services::Documentmanagement::_2010_04::Digitalsignature
{
public:
    static DigitalsignatureService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DigitalsignatureService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/documentmanagement/DocumentManagement_undef.h>
#endif

