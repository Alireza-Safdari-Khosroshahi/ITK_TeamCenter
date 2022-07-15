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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_RBFPARAMDEF_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_RBFPARAMDEF_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/BusinessElement.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ListOfValues;


class TCSOACLIENTMNGD_API RBFParamDef : public Teamcenter::Soa::Client::Model::BusinessElement
{
public:
    int get_data_type();
    const std::string& get_column_name();
    Teamcenter::Soa::Common::AutoPtr<ListOfValues> get_lov_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RBFParamDef")

   virtual ~RBFParamDef();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
