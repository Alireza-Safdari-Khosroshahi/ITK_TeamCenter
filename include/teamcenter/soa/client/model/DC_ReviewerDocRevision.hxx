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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_REVIEWERDOCREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_REVIEWERDOCREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DocumentRevision.hxx>

#include <teamcenter/soa/client/model/ContmgmtbaseMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class DCt_Language;


class TCSOACONTMGMTBASEMODELMNGD_API DC_ReviewerDocRevision : public Teamcenter::Soa::Client::Model::DocumentRevision
{
public:
    int get_contentSize();
    bool get_contentModified();
    const std::string& get_topicReference();
    const std::string& get_languageRef();
    Teamcenter::Soa::Common::AutoPtr<DCt_Language> get_ctm0LanguageTagref();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_ReviewerDocRevision")

   virtual ~DC_ReviewerDocRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
