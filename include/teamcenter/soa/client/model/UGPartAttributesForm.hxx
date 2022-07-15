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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_UGPARTATTRIBUTESFORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_UGPARTATTRIBUTESFORM_HXX

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


class TCSOACLIENTMNGD_API UGPartAttributesForm : public Teamcenter::Soa::Client::Model::Form
{
public:
    int get_flags();
    const Teamcenter::Soa::Client::StringVector& get_titles();
    const Teamcenter::Soa::Client::StringVector& get_values();
    const Teamcenter::Soa::Client::StringVector& get_fnd0sync_checksums();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("UGPartAttributesForm")

   virtual ~UGPartAttributesForm();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
