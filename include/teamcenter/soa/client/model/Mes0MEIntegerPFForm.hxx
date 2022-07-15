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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MES0MEINTEGERPFFORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MES0MEINTEGERPFFORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mes0MEPFBaseForm.hxx>

#include <teamcenter/soa/client/model/CmtmesMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTMESMODELMNGD_API Mes0MEIntegerPFForm : public Teamcenter::Soa::Client::Model::Mes0MEPFBaseForm
{
public:
    int get_mes0Value();
    int get_mes0MinValue();
    int get_mes0MaxValue();
    int get_mes0DefaultValue();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mes0MEIntegerPFForm")

   virtual ~Mes0MEIntegerPFForm();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtmesMngd_undef.h>
#endif
