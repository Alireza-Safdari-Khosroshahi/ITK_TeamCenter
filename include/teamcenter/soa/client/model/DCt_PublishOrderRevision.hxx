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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DCT_PUBLISHORDERREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DCT_PUBLISHORDERREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DCt_ItemRevision.hxx>

#include <teamcenter/soa/client/model/ContmgmtbaseMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACONTMGMTBASEMODELMNGD_API DCt_PublishOrderRevision : public Teamcenter::Soa::Client::Model::DCt_ItemRevision
{
public:
    const Teamcenter::Soa::Client::StringVector& get_reportMsgs();
    const std::string& get_publOrderTitle();
    const std::string& get_compVersSelection();
    const std::string& get_translVersSel();
    const Teamcenter::Soa::Client::StringVector& get_toolLog();
    bool get_registerPublResult();
    const std::string& get_languageRef();
    const std::string& get_topicReference();
    const std::string& get_toolRef();
    const std::string& get_styleTypeRef();
    const std::string& get_documentRef();
    const std::string& get_composableRefVariant();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DCt_PublishOrderRevision")

   virtual ~DCt_PublishOrderRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
