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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_OPERATIONINPUTPROPERTY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_OPERATIONINPUTPROPERTY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Property.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ImanType;


class TCSOACLIENTMNGD_API OperationInputProperty : public Teamcenter::Soa::Client::Model::Property
{
public:
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_compoundObjectType();
    int get_fieldType();
    const std::string& get_compoundObjectConstant();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("OperationInputProperty")

   virtual ~OperationInputProperty();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
