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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ADSTECHDOCUMENT_REVISION_MASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ADSTECHDOCUMENT_REVISION_MASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/AdsfoundationMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAADSFOUNDATIONMODELMNGD_API ADSTechDocument_Revision_Master : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_Title();
    const std::string& get_Author();
    const std::string& get_Subject();
    const Teamcenter::Soa::Client::StringVector& get_Keywords();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ADSTechDocument_Revision_Master")

   virtual ~ADSTechDocument_Revision_Master();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AdsfoundationMngd_undef.h>
#endif
