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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PROCESSORREVMASTERSTORAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PROCESSORREVMASTERSTORAGE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/EsmprocessorMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAESMPROCESSORMODELMNGD_API ProcessorRevMasterStorage : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_memoryType();
    bool get_programmableInService();
    const std::string& get_byteOrder();
    const std::string& get_hw_architecture();
    bool get_linked();
    bool get_isGateway();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ProcessorRevMasterStorage")

   virtual ~ProcessorRevMasterStorage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/EsmprocessorMngd_undef.h>
#endif
