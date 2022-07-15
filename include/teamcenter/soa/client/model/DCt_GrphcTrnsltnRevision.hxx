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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DCT_GRPHCTRNSLTNREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DCT_GRPHCTRNSLTNREVISION_HXX

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
                class DCt_Language;


class TCSOACONTMGMTBASEMODELMNGD_API DCt_GrphcTrnsltnRevision : public Teamcenter::Soa::Client::Model::DCt_ItemRevision
{
public:
    int get_contentSize();
    int get_contentVersionReference();
    bool get_translationReceived();
    const std::string& get_languageRef();
    Teamcenter::Soa::Common::AutoPtr<DCt_Language> get_ctm0LanguageTagref();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DC_GrphcTrnsltnGrphcOptionR();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DCt_GrphcTrnsltnRevision")

   virtual ~DCt_GrphcTrnsltnRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
