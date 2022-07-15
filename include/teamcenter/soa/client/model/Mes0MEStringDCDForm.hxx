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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MES0MESTRINGDCDFORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MES0MESTRINGDCDFORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mes0MEDCDBaseForm.hxx>

#include <teamcenter/soa/client/model/CmtmesMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTMESMODELMNGD_API Mes0MEStringDCDForm : public Teamcenter::Soa::Client::Model::Mes0MEDCDBaseForm
{
public:
    int get_mes0MaxLength();
    const std::string& get_mes0ValueValidator();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mes0MEStringDCDForm")

   virtual ~Mes0MEStringDCDForm();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtmesMngd_undef.h>
#endif
