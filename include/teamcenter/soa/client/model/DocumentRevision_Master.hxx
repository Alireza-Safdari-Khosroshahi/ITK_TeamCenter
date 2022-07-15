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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DOCUMENTREVISION_MASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DOCUMENTREVISION_MASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API DocumentRevision_Master : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_Title();
    const std::string& get_Author();
    const std::string& get_Subject();
    const Teamcenter::Soa::Client::StringVector& get_Keywords();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DocumentRevision_Master")

   virtual ~DocumentRevision_Master();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
