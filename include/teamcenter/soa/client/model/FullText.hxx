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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FULLTEXT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FULLTEXT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Dataset.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API FullText : public Teamcenter::Soa::Client::Model::Dataset
{
public:
    const std::string& get_body_text();
    const std::string& get_body_cleartext();
    const std::string& get_content_type();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DMI_markup();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0_Symbolic_Link();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("FullText")

   virtual ~FullText();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
