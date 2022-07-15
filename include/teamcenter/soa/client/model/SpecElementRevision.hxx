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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SPECELEMENTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SPECELEMENTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Dataset;


class TCSOACLIENTMNGD_API SpecElementRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    bool get_fnd0IsNumbered();
    Teamcenter::Soa::Common::AutoPtr<Dataset> get_fnd0FFObj();
    const std::string& get_body_text();
    const std::string& get_body_cleartext();
    const std::string& get_fnd0_body_text_url();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0ParentObject();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SpecElementRevision")

   virtual ~SpecElementRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
