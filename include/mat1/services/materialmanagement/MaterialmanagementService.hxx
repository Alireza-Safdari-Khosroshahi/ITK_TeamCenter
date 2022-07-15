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

#ifndef MAT1_SERVICES_MATERIALMANAGEMENT_MATERIALMANAGEMENTSERVICE_HXX
#define MAT1_SERVICES_MATERIALMANAGEMENT_MATERIALMANAGEMENTSERVICE_HXX

#include <mat1/services/materialmanagement/_2012_09/Materialmanagement.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <mat1/services/materialmanagement/MaterialManagement_exports.h>

namespace Mat1
{
    namespace Services
    {
        namespace Materialmanagement
        {
            class MaterialmanagementService;

/**
 * The Material Management service exposes operations that are used to query material
 * and substance related information associated with a part. Substances can be defined
 * as basic forms of matter that cannot be disintegrated further using some mechanical
 * or physical process, e.g. iron. Substances have Chemical Abstracts Service registry
 * numbers to uniquely identify them. Material is defined as matter composed of several
 * substances, e.g. iron, carbon, cadmium, etc. with definite or variable compositions.
 * A Teamcenter part can be made of several materials, e.g. Steel Alloy 440, Cast Iron
 * 2300 Series, etc. with definite masses of materials. The queries data is a set of
 * <b>Mat1MaterialInfo</b> objects that contains the material reference with the mass
 * in a unit of measure (UoM) related to <b>ItemRevision</b> or <b>BOMLine</b> objects
 * and a set of <b>Mat1SubstanceInfo</b> objects that contain the substance reference
 * with the mass in a UoM related to <b>ItemRevision</b> objects or <b>BOMLine</b> objects.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libmat1soamaterialmanagementstrongmngd.dll
 * </li>
 * <li type="disc">libmat1soamaterialmanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class MAT1SOAMATERIALMGMTSTRONGMNGD_API MaterialmanagementService
    : public Mat1::Services::Materialmanagement::_2012_09::Materialmanagement
{
public:
    static MaterialmanagementService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Method to query material and substance related information associated with a part.
     * Substances can be defined as basic form of matter which cannot be disintegrated further
     * using some mechanical or physical process, e.g. iron. Substances have a Chemical
     * Abstracts Service registry number to uniquely identify them. Material is defined
     * as matter composed of several substances, e.g. iron, carbon, cadmium etc. with definite
     * or variable compositions. A Teamcenter part can be made of several materials, e.g.
     * Steel Alloy 440, Cast Iron 2300 Series, etc. The query data is a set of <b>Mat1MaterialInfo</b>
     * objects that contain material references with their mass in a unit of measure (UoM)
     * related to <b>ItemRevision</b> or <b>BOMLine</b> objects, and a set of <b>Mat1SubstanceInfo</b>
     * objects that contain substance references with their mass in UoM related to <b>ItemRevision</b>
     * or <b>BOMLine</b> objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Material Management SOA Component - Component for Mat1SoaMaterialMgmt.
     *
     * @param objs
     *        References of <b>ItemRevision</b> objectss or <b>BOMLine</b> objects for which material
     *        and substance information is sought.
     *
     * @return
     *         Response that contains set of <b>Mat1MaterialInfo</b> objects, a set of <b>Mat1SubstanceInfo</b>
     *         objects related to <b>ItemRevision</b> objects or <b>BOMLine</b> objects, and service
     *         data. The <b>Mat1MaterialInfo</b> object contains material reference with the mass
     *         in a UoM related to <b>ItemRevision</b> or <b>BOMLine</b> objects. The <b>Mat1SubstanceInfo</b>
     *         object contains substance reference with the mass in a UoM related to <b>ItemRevision</b>
     *         or <b>BOMLine</b> objects.
     *
     */
    virtual Mat1::Services::Materialmanagement::_2012_09::Materialmanagement::MaterialSubstanceInfoResponse getMaterialSubstanceInfo ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objs ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MaterialmanagementService")

};
        }
    }
}


#pragma warning ( pop )

#include <mat1/services/materialmanagement/MaterialManagement_undef.h>
#endif

