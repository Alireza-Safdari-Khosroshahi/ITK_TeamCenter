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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0MEPROCAREAPRODIMAGEREL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0MEPROCAREAPRODIMAGEREL_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ImanRelation.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Mfg0MEProductBOPRelation;


class TCSOACLIENTMNGD_API Mfg0MEProcAreaProdImageRel : public Teamcenter::Soa::Client::Model::ImanRelation
{
public:
    Teamcenter::Soa::Common::AutoPtr<Mfg0MEProductBOPRelation> get_Mfg0RelatedProductBOP();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0MEProcAreaProdImageRel")

   virtual ~Mfg0MEProcAreaProdImageRel();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
