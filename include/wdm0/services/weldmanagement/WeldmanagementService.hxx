/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#ifndef WDM0_SERVICES_WELDMANAGEMENT_WELDMANAGEMENTSERVICE_HXX
#define WDM0_SERVICES_WELDMANAGEMENT_WELDMANAGEMENTSERVICE_HXX

#include <wdm0/services/weldmanagement/_2012_02/Weldmanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <wdm0/services/weldmanagement/WeldManagement_exports.h>

namespace Wdm0
{
    namespace Services
    {
        namespace Weldmanagement
        {
            class WeldmanagementService;

/**
 * Weld Management service.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libwdm0soaweldmanagementstrongmngd.dll
 * </li>
 * <li type="disc">libwdm0soaweldmanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class WDM0SOAWELDMANAGEMENTSTRONGMNGD_API WeldmanagementService
    : public Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement
{
public:
    static WeldmanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Creates or updates weld components.
     *
     * @param inputs
     *        List of create/update weld component inputs.
     *
     * @return
     *         List of weld components/features that created or updated.
     *
     */
    virtual Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::CreateWeldResp createUpdateWelds ( const std::vector< Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::CreateWeldInput >& inputs ) = 0;

    /**
     * Delete weld components.
     *
     * @param inputs
     *        List of delete weld component inputs.
     *
     * @return
     *         List of message on eached weld component showing whether is deleted or failed to
     *         be deleted.
     *
     */
    virtual Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::DeleteWeldResp deleteWelds ( const std::vector< Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::DeleteWeldInput >& inputs ) = 0;

    /**
     * Find weld components that connected to any of connection parts.
     *
     * @param inputs
     *        List of find weld component inputs.
     *
     * @return
     *         List of weld components.
     *
     */
    virtual Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::FindWeldResp findWelds ( const std::vector< Wdm0::Services::Weldmanagement::_2012_02::Weldmanagement::FindWeldInput >& inputs ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("WeldmanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <wdm0/services/weldmanagement/WeldManagement_undef.h>
#endif

