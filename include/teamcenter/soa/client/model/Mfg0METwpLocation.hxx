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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0METWPLOCATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0METWPLOCATION_HXX

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


class TCSOACLIENTMNGD_API Mfg0METwpLocation : public Teamcenter::Soa::Client::Model::Form
{
public:
    int get_Mfg0Length();
    int get_Mfg0Width();
    int get_Mfg0X();
    int get_Mfg0Y();
    int get_Mfg0Orientation();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0METwpLocation")

   virtual ~Mfg0METwpLocation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
