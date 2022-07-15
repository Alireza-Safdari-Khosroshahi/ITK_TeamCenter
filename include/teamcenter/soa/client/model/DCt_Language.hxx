/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

  Auto-generated source from Teamcenter Data Model.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DCT_LANGUAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DCT_LANGUAGE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API DCt_Language : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const std::string& get_languageName();
    const std::string& get_isoLanguageCode();
    const std::string& get_isoCountryCode();
    const std::string& get_langFileInitials();
    const std::string& get_langDescription();
    const std::string& get_defaultPubFont();
    const std::string& get_adminComment();
    bool get_loginEnabled();
    bool get_metadataEnabled();
    bool get_contentEnabled();
    const std::string& get_fnd0isoLanguageCountryCode();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DCt_Language")

   virtual ~DCt_Language();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
