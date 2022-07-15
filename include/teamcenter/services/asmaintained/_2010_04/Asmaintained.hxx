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

#ifndef TEAMCENTER_SERVICES_ASMAINTAINED__2010_04_ASMAINTAINED_HXX
#define TEAMCENTER_SERVICES_ASMAINTAINED__2010_04_ASMAINTAINED_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/BOMWindow.hxx>
#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/MroRevisionRule.hxx>
#include <teamcenter/soa/client/model/PhysicalBOMLine.hxx>
#include <teamcenter/soa/client/model/PhysicalPartRevision.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/asmaintained/AsMaintained_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Asmaintained
        {
            namespace _2010_04
            {
                class Asmaintained;

class TCSOAASMAINTAINEDSTRONGMNGD_API Asmaintained
{
public:

    struct SearchInstallablePhysPartInfo;
    struct SearchInstallablePhysPartInputInfo;
    struct SearchInstallablePhysPartOutput;
    struct SearchInstallablePhysPartResponse;
    struct SetMroWindowTopLineInfo;
    struct SetMroWindowTopLineOutput;
    struct SetMroWindowTopLineResponse;

    /**
     * Contains the map based on seach phys part can be done.
     */
    typedef std::map< std::string, std::string > SearchInstallableAttributeMap;

    /**
     * Structure represents the parameters to get the installable physical part for the
     * specified usage.
     */
    struct SearchInstallablePhysPartInfo
    {
        /**
         * A structure containing the search criteria.
         */
        SearchInstallableAttributeMap searchMap;
    };

    /**
     * Structure represents the parameters to get the installable <b>PhysicalPart</b> for
     * the specified usage.
     */
    struct SearchInstallablePhysPartInputInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The line object, for  which the <b>PhysicalPart</b> objects are searched to install.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalBOMLine>  physBOMLine;
        /**
         * The line object corresponding to the selected usage.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  usageBOMLine;
        /**
         * A structure containing the search criteria.
         */
        Teamcenter::Services::Asmaintained::_2010_04::Asmaintained::SearchInstallablePhysPartInfo searchInfo;
    };

    /**
     * Structure represents the output parameters of the search installable physical part
     * operation.
     */
    struct SearchInstallablePhysPartOutput
    {
        /**
         * The <code>clientId</code> from the input <code>SearchInstallablePhysPartInputInfo</code>
         * element. This value is unchanged from the input, and can be used to identify this
         * response element with the corresponding input element.
         */
        std::string clientId;
        /**
         * A list of preferred objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  > prefInstallablePhysParts;
        /**
         * A list of alternate objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  > altInstallablePhysParts;
        /**
         * A list of substitute objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  > subInstallablePhysParts;
        /**
         * A list of deviated  objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  > deviatedInstallablePhysParts;
    };

    /**
     * Structure represents a list of installable <b>PhysicalPart</b> and the <code>ServiceData</code>.
     */
    struct SearchInstallablePhysPartResponse
    {
        /**
         * A list of installable <b>PhysicalPart</b> objects.
         */
        std::vector< Teamcenter::Services::Asmaintained::_2010_04::Asmaintained::SearchInstallablePhysPartOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure represents the parameters for setting the <b>BOMWindow</b> topline.
     */
    struct SetMroWindowTopLineInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The BOM window object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  bomWindow;
        /**
         * The <b>Item</b> object that would be set on the top line.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  item;
        /**
         * The revision object that would be set on the top line.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
        /**
         * As-maintained revision rule.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::MroRevisionRule>  mroRevRule;
    };

    /**
     * Structure represents the output parameters of the set window topline operation.
     */
    struct SetMroWindowTopLineOutput
    {
        /**
         * The <code>clientId</code> from the input <code>SetMroWindowTopLineInfo</code> element.
         * This value is unchanged from the input, and can be used to identify this response
         * element with the corresponding input element.
         */
        std::string clientId;
        /**
         * The created line object is set as the topline on the <b>MROBOMWindow</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  topLine;
    };

    /**
     * Structure represents the set top line and the <code>ServiceData</code>.
     */
    struct SetMroWindowTopLineResponse
    {
        /**
         * A list containing the top line.
         */
        std::vector< Teamcenter::Services::Asmaintained::_2010_04::Asmaintained::SetMroWindowTopLineOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation gets the installable <b>PhysicalPartRevision</b> based on the usage
     * name. It will get the <i>Preferred, Alternate, Substitute</i> and <i>Deviated</i>
     * <b>PhysicalPartRevision</b> for specified usage.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Maintained - This component provides capabilities to generate and perform
     * actions on As-Maintained structures.
     *
     * @param input
     *        The required information to search the installable Physical Parts.
     *
     * @return
     *         A list of structures with the <b>PhysicalPart</b> objects matching the criteria along
     *         with the <code>ServiceData</code> is returned. Any failure will be returned with
     *         client id mapped to error message in the <code>ServiceData</code> list of partial
     *         errors.
     *
     */
    virtual Teamcenter::Services::Asmaintained::_2010_04::Asmaintained::SearchInstallablePhysPartResponse searchInstallablePhysPart ( const std::vector< Teamcenter::Services::Asmaintained::_2010_04::Asmaintained::SearchInstallablePhysPartInputInfo >& input ) = 0;

    /**
     * This operation will set the given object as top line for the specified <b>BOMWindow</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Maintained - This component provides capabilities to generate and perform
     * actions on As-Maintained structures.
     *
     * @param input
     *        The required information to set the object as top line for a <b>BOMWindow</b>.
     *
     * @return
     *         A top line  along with the <code>ServiceData</code> is returned. The <b>AsMaintainedBOMLine</b>
     *         object created is returned in the created objects list of the <code>ServiceData</code>.
     *         Any failure will be returned with client id mapped to error message in the <code>ServiceData</code>
     *         list of partial errors.
     *
     */
    virtual Teamcenter::Services::Asmaintained::_2010_04::Asmaintained::SetMroWindowTopLineResponse setMroWindowTopLine ( const std::vector< Teamcenter::Services::Asmaintained::_2010_04::Asmaintained::SetMroWindowTopLineInfo >& input ) = 0;


protected:
    virtual ~Asmaintained() {}
};
            }
        }
    }
}

#include <teamcenter/services/asmaintained/AsMaintained_undef.h>
#endif

