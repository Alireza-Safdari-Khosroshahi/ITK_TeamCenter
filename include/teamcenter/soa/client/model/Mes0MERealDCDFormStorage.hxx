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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MES0MEREALDCDFORMSTORAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MES0MEREALDCDFORMSTORAGE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mes0MEDCDBaseFormStorage.hxx>

#include <teamcenter/soa/client/model/CmtmesMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTMESMODELMNGD_API Mes0MERealDCDFormStorage : public Teamcenter::Soa::Client::Model::Mes0MEDCDBaseFormStorage
{
public:
    double get_mes0MinValue();
    double get_mes0MaxValue();
    double get_mes0CautionMinValue();
    double get_mes0CautionMaxValue();
    double get_mes0AlertMinValue();
    double get_mes0AlertMaxValue();
    int get_mes0DecimalPlaces();
    const std::string& get_mes0OutOfRangeBhr();
    const std::string& get_mes0DataAcquisitionMethod();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mes0MERealDCDFormStorage")

   virtual ~Mes0MERealDCDFormStorage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtmesMngd_undef.h>
#endif
