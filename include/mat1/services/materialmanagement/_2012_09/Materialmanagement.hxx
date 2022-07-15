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

#ifndef MAT1_SERVICES_MATERIALMANAGEMENT__2012_09_MATERIALMANAGEMENT_HXX
#define MAT1_SERVICES_MATERIALMANAGEMENT__2012_09_MATERIALMANAGEMENT_HXX

#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/POM_object.hxx>
#include <teamcenter/soa/client/model/WorkspaceObject.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <mat1/services/materialmanagement/MaterialManagement_exports.h>

namespace Mat1
{
    namespace Services
    {
        namespace Materialmanagement
        {
            namespace _2012_09
            {
                class Materialmanagement;

class MAT1SOAMATERIALMGMTSTRONGMNGD_API Materialmanagement
{
public:

    struct Material;
    struct MaterialSubstance;
    struct MaterialSubstanceInfo;
    struct MaterialSubstanceInfoResponse;
    struct Substance;

    /**
     * Dataset that contains set of Material objects, set of UOM of material and set of
     * material mass respectively, related to ItemRevision or BOMLine.
     */
    struct Material
    {
        /**
         * Reference to MaterialRevision
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  materialRef;
        /**
         * Unit of Measure
         */
        std::string materialUOMTag;
        /**
         * Mass in the UoM
         */
        double materialMass;
        /**
         * Name of Material
         */
        std::string materialName;
    };

    /**
     * Dataset that contains set of Material objects, set of Substance objects related to
     * ItemRevision or BOMLine. Material object contains Material reference with their mass
     * in UoM related to ItemRevision(s) or BOMLine(s). Substance object contains Substance
     * reference with their mass in UoM related to ItemRevision(s) or BOMLine(s).
     */
    struct MaterialSubstance
    {
        /**
         * std::vector<Mat1::Soa::MaterialManagement::_2012_09::MaterialManagement::Material>
         */
        std::vector< Mat1::Services::Materialmanagement::_2012_09::Materialmanagement::Material > materials;
        /**
         * Mat1::Soa::MaterialManagement::_2012_09::MaterialManagement::Substance
         */
        std::vector< Mat1::Services::Materialmanagement::_2012_09::Materialmanagement::Substance > substances;
    };

    /**
     * Dataset that contains set of <b>MaterialInfo</b> objects, set of <b>SubstanceInfo</b>
     * objects related to <b>ItemRevision</b> or <b>BOMLine</b>. <b>MaterialInfo</b> object
     * contains <b>Material</b> reference with their mass in UoM related to <b>ItemRevision</b>(s)
     * or <b>BOMLine</b>(s). <b>SubstanceInfo</b> object contains <b>Substance</b> reference
     * with their mass in UoM related to <b>ItemRevision</b>(s) or <b>BOMLine</b>(s).
     */
    struct MaterialSubstanceInfo
    {
        /**
         * Set of <b>Mat1MaterialInfo</b> objects that contains material reference with the
         * mass  in a UoM related to <b>ItemRevision</b> or <b>BOMLine</b> objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  > materialInfos;
        /**
         * Set of <b>Mat1SubstanceInfo</b> objects that contains substance reference with the
         * mass in a UoM related to the <b>ItemRevision</b> or <b>BOMLine</b> objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  > substanceInfos;
    };

    /**
     * Response that contains set of <b>MaterialSubstanceInfo</b> objects related to <b>ItemRevision</b>(s)
     * or <b>BOMLine</b>(s) in sequence and the <code>ServiceData</code>. <b>MaterialInfo</b>
     * objects contain <b>Material</b> reference with their mass in UoM related to each
     * <b>ItemRevision</b> or <b>BOMLine</b>. <b>SubstanceInfo</b> objects contain <b>Substance</b>
     * reference with their mass in UoM related to each <b>ItemRevision</b> or <b>BOMLine</b>.
     */
    struct MaterialSubstanceInfoResponse
    {
        /**
         * Returned service data related to the <code>MaterialSubstanceInfoResponse</code>.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * Response that contains a set of <b>Mat1lSubstanceInfo</b> objects related to <b>ItemRevision</b>
         * or <b>BOMLine</b> objects and the <code>ServiceData</code>.
         */
        std::vector< Mat1::Services::Materialmanagement::_2012_09::Materialmanagement::MaterialSubstanceInfo > materialSubstanceInfos;
        /**
         * Response that contains set of MaterialSubstance object related to ItemRevision(s)
         * or BOMLine(s) in sequence and the service data.
         */
        std::vector< Mat1::Services::Materialmanagement::_2012_09::Materialmanagement::MaterialSubstance > materialSubstance;
    };

    /**
     * Dataset that contains set of Substance objects, set of UOM of substance, set of minimum
     * substance mass, set of maximum substance mass and set of mass in range respectively,
     * related to ItemRevision or BOMLine.
     */
    struct Substance
    {
        /**
         * Reference to Substance
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::WorkspaceObject>  substanceRef;
        /**
         * Unit of Measure
         */
        std::string substanceUOMTag;
        /**
         * Minimum Mass
         */
        double substanceMinMass;
        /**
         * Maximum Mass
         */
        double substanceMaxMass;
        /**
         * Is the mass in range?
         */
        bool substanceMassInRange;
        /**
         * Name of Substance
         */
        std::string substanceName;
        /**
         * Substance CAS Number
         */
        std::string substanceCASNumber;
    };




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


protected:
    virtual ~Materialmanagement() {}
};
            }
        }
    }
}

#include <mat1/services/materialmanagement/MaterialManagement_undef.h>
#endif

