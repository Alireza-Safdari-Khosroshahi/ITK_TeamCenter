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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_OPERATIONTEMPLATE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_OPERATIONTEMPLATE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Release;
                class OperationParameter;
                class MetaException;
                class DataTypeRef;


class TCSOACLIENTMNGD_API OperationTemplate : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_id();
    const std::string& get_name();
    bool get_const();
    bool get_static();
    bool get_returnConst();
    bool get_returnFreeMemory();
    const std::string& get_returnDescription();
    Teamcenter::Soa::Common::AutoPtr<Release> get_createRelease();
    const std::string& get_description();
    size_t count_parameters();
    Teamcenter::Soa::Common::AutoPtr<OperationParameter> get_parameters_at( size_t inx );
    size_t count_exceptions();
    Teamcenter::Soa::Common::AutoPtr<MetaException> get_exceptions_at( size_t inx );
    size_t count_operationReturnDataTypeRef();
    Teamcenter::Soa::Common::AutoPtr<DataTypeRef> get_operationReturnDataTypeRef_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("OperationTemplate")

   virtual ~OperationTemplate();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
