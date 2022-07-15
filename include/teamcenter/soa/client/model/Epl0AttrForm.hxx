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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EPL0ATTRFORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EPL0ATTRFORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/EdalibraryMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAEDALIBRARYMODELMNGD_API Epl0AttrForm : public Teamcenter::Soa::Client::Model::Form
{
public:
    const Teamcenter::Soa::Common::DateTime& get_epl0ecad_lmd();
    const std::string& get_epl0ecad_version();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Epl0AttrForm")

   virtual ~Epl0AttrForm();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/EdalibraryMngd_undef.h>
#endif
