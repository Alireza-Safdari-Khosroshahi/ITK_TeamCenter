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

#ifndef TEAMCENTER_SERVICES_ASBUILT__2010_04_ASBUILT_HXX
#define TEAMCENTER_SERVICES_ASBUILT__2010_04_ASBUILT_HXX

#include <teamcenter/soa/client/model/AsBuiltBOMLine.hxx>
#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/BOMWindow.hxx>
#include <teamcenter/soa/client/model/Item.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/model/PhysicalBOMLine.hxx>
#include <teamcenter/soa/client/model/PhysicalPartRevision.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/asbuilt/AsBuilt_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Asbuilt
        {
            namespace _2010_04
            {
                class Asbuilt;

class TCSOAASBUILTSTRONGMNGD_API Asbuilt
{
public:

    struct RebuildAsBuiltStructureInfo;
    struct RebuildAsBuiltStructureOutput;
    struct RebuildAsBuiltStructureResponse;
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
     * Structure represents the parameters required to rebuild an as-built <b>PhysicalPart</b>
     * structure from a released as-built structure.
     */
    struct RebuildAsBuiltStructureInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * Used as the installation time on the <b>AsBuiltStructure</b> relation objects in
         * the new as-built structure.
         */
        Teamcenter::Soa::Common::DateTime rebuildDate;
        /**
         * The top level object for rebuilding.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AsBuiltBOMLine>  selectedBOMLine;
    };

    /**
     * <code>The output data</code> of the rebuildAsBuiltStructure operation.
     */
    struct RebuildAsBuiltStructureOutput
    {
        /**
         * The <code>clientId</code> from the input <code>RebuildAsBuiltStructureInfo</code>
         * element. This value is unchanged from the input, and can be used to identify this
         * response element with the corresponding input element.
         */
        std::string clientId;
        /**
         * The newly created object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  newPhysPartRev;
    };

    /**
     * Structures containing the created top level as-built <b>PhysicalPart</b> object and
     * the <code>ServiceData</code>.
     */
    struct RebuildAsBuiltStructureResponse
    {
        /**
         * A list of rebuild <b>PhysicalPart</b> objects.
         */
        std::vector< Teamcenter::Services::Asbuilt::_2010_04::Asbuilt::RebuildAsBuiltStructureOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure represents the parameters required to search all the installable as-built
     * <b>PhysicalPartRevision</b> objects.
     */
    struct SearchInstallablePhysPartInfo
    {
        /**
         * A map of attribute names and value pairs (string/string).
         */
        SearchInstallableAttributeMap searchMap;
    };

    /**
     * Structure represents the parameters required to search all the installable as-built
     * <b>PhysicalPartRevision</b> objects.
     */
    struct SearchInstallablePhysPartInputInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure
         */
        std::string clientId;
        /**
         * The object under which the parts are going to be installed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalBOMLine>  physBOMLine;
        /**
         * The object corresponding to the usage specified.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  usageBOMLine;
        /**
         * Search criteria
         */
        Teamcenter::Services::Asbuilt::_2010_04::Asbuilt::SearchInstallablePhysPartInfo searchInfo;
    };

    /**
     * Structure represents the output parameters of the operation.
     */
    struct SearchInstallablePhysPartOutput
    {
        /**
         * The <code>clientId</code> from the input SearchInstallablePhysPartInputInfo element.
         * This value is unchanged from the input, and can be used to identify this response
         * element with the corresponding input element.
         */
        std::string clientId;
        /**
         * A list of <i>Preferred</i> <b>PhysicalPartRevision</b> objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  > prefInstallablePhysParts;
        /**
         * A list of <i>Alternate</i> <b>PhysicalPartRevision</b> objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  > altInstallablePhysParts;
        /**
         * A list of <i>Substitute</i> <b>PhysicalPartRevision</b> objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  > subInstallablePhysParts;
        /**
         * A list of <i>Deviated</i> <b>PhysicalPartRevision</b> objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  > deviatedInstallablePhysParts;
    };

    /**
     * Structures containing the lists of installable <b>PhysicalPartRevision</b> objects
     * and the <code>ServiceData</code>.
     */
    struct SearchInstallablePhysPartResponse
    {
        /**
         * A list of <b>PhysicalPart</b> objects matching the search criteria.
         */
        std::vector< Teamcenter::Services::Asbuilt::_2010_04::Asbuilt::SearchInstallablePhysPartOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure represents the parameters required to set an as-built <b>PhysicalPart</b>
     * object as a top line in a given <b>MroBOMWindow</b> object.
     */
    struct SetMroWindowTopLineInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The object for which the top line is to be set.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  bomWindow;
        /**
         * The <b>PhysicalPart</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Item>  item;
        /**
         * The <b>PhysicalPartRevision</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
    };

    /**
     * Structure represents the output parameters of the Set Top Line operation.
     */
    struct SetMroWindowTopLineOutput
    {
        /**
         * The <code>clientId</code> from the input SetMroWindowTopLineInfo element. This value
         * is unchanged from the input, and can be used to identify this response element with
         * the corresponding input element.
         */
        std::string clientId;
        /**
         * The created object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  topLine;
    };

    /**
     * Structures containing the created <b>AsBuiltBOMLine</b> object and the <code>ServiceData</code>.
     */
    struct SetMroWindowTopLineResponse
    {
        /**
         * Created <b>AsBuiltBOMLine</b> object.
         */
        std::vector< Teamcenter::Services::Asbuilt::_2010_04::Asbuilt::SetMroWindowTopLineOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation generates a new as-built <b>PhysicalPart</b> structure based on an
     * existing as-built structure. This activity is known as <i>Rebuilding</i>. The new
     * <b>PhysicalPart</b> objects created are linked to the design <b>Item</b> objects
     * of the parts in the existing as-built structure, with <b>PhysicalRealization</b>
     * relation object. New <b>AsBuiltStructure</b> relation objects are created between
     * the <b>PhysicalPartRevision</b> objects in the new structure.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Built - This component provides capabilities to generate and perform actions
     * on As-Built structures.
     *
     * @param input
     *        A list of <b>AsBuiltBOMLine</b> objects to rebuild an AsBuilt structure.
     *
     * @return
     *         The created top Physical Part object is returned in the created objects list of the
     *         <code>ServiceData</code>. Any failures will be returned with <code>clientId</code>
     *         mapped to the partial error.
     *         <br>
     *         <ul>
     *         <li type="disc">237051&nbsp;&nbsp;&nbsp;&nbsp;If the revision of the parent <b>PhysicalPart</b>
     *         object is not identified. A PhysicalPart object is said to be identified when it
     *         has all the required information like <i>Serial Number</i>, <i>Lot Number</i> (in
     *         case of Lot parts) and the <i>Manufacturer's id</i>.
     *         </li>
     *         <li type="disc">237052&nbsp;&nbsp;&nbsp;&nbsp;If the <b>PhysicalPartRevision</b>
     *         object is not the latest revision.
     *         </li>
     *         <li type="disc">237053&nbsp;&nbsp;&nbsp;&nbsp;If the <b>PhysicalPartRevision</b>
     *         object is not released.
     *         </li>
     *         <li type="disc">238019&nbsp;&nbsp;&nbsp;&nbsp;If the <i>Rebuild Date</i> specified
     *         is earlier than the <i>Installation Date</i> of any of the objects in the AsBuilt
     *         structure.
     *         </li>
     *         <li type="disc">238020&nbsp;&nbsp;&nbsp;&nbsp;If the Rebuild Date is specified as
     *         a future date.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asbuilt::_2010_04::Asbuilt::RebuildAsBuiltStructureResponse rebuildAsBuiltStructure ( const std::vector< Teamcenter::Services::Asbuilt::_2010_04::Asbuilt::RebuildAsBuiltStructureInfo >& input ) = 0;

    /**
     * This operation returns all the <b>PhysicalPartRevision</b> objects which can be installed
     * in a given position in an as-built structure.  Following are the lists of installable
     * objects returned based on the position selected.
     * <br>
     * <ul>
     * <li type="disc">Preferred Parts&nbsp;&nbsp;&nbsp;&nbsp;All the preferred revision
     * objects
     * </li>
     * <li type="disc">Alternate Parts &nbsp;&nbsp;&nbsp;&nbsp;All the revision objects
     * realized from the Alternate parts of the design <b>Item</b> object
     * </li>
     * <li type="disc">Substitute Parts &nbsp;&nbsp;&nbsp;&nbsp;All the revision objects
     * realized from the Substitute parts of the design <b>Item</b> object
     * </li>
     * <li type="disc">Deviated Parts &nbsp;&nbsp;&nbsp;&nbsp;All the revision objects which
     * have allowed deviations set up
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * MOIN
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Built - This component provides capabilities to generate and perform actions
     * on As-Built structures.
     *
     * @param input
     *        Structures which hold the required information to query all the installable as-built
     *        <b>PhysicalPartRevision</b> objects.
     *
     * @return
     *         A list of <b>PhysicalPart</b> objects matching the search criteria along with the
     *         <code>ServiceData</code> is returned. Any failure will be returned with <code>clientId</code>
     *         mapped to error message in the <code>ServiceData</code> list of partial errors.
     *
     */
    virtual Teamcenter::Services::Asbuilt::_2010_04::Asbuilt::SearchInstallablePhysPartResponse searchInstallablePhysPart ( const std::vector< Teamcenter::Services::Asbuilt::_2010_04::Asbuilt::SearchInstallablePhysPartInputInfo >& input ) = 0;

    /**
     * This operation sets a given <b>PhysicalPart</b> object as the top line in the given
     * <b>MroBOMWindow</b> object by constructing an object of <b>AsBuiltBOMLine</b>. If
     * the object is an as-built <b>PhysicalPartRevision</b>, then it is directly set as
     * the top line. If the object is a <b>PhysicalPart</b>, then the latest <i>as-built
     * revision</i> of the object is queried and set as the top line. It is possible for
     * a <b>PhysicalPart</b> object to have <i>as-built revisions</i> and non <i>as-built
     * revisions</i>.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createMROBOMWindows
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Built - This component provides capabilities to generate and perform actions
     * on As-Built structures.
     *
     * @param input
     *        Structure which holds the required information to set an as-built <b>PhysicalPart</b>
     *        or <b>PhysicalPartRevision</b> as the top line in a <b>MroBOMWindow</b> object.
     *
     * @return
     *         The created top <b>AsBuiltBOMLine</b> object is returned in the created objects list
     *         and the <b>MroBOMWindow</b> object is returned in the updated objects list of the
     *         <code>ServiceData</code>. Any failure will be returned with <code>clientId</code>
     *         mapped to error message in the <code>ServiceData</code> list of partial errors.
     *         Following error codes are returned in the <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">238017    If the object is not an as-built <b>PhysicalPartRevision</b>.
     *         </li>
     *         <li type="disc">238018    If the object is a <b>PhysicalPart</b> and has no revisions
     *         marked as <i>as-built revision</i>.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asbuilt::_2010_04::Asbuilt::SetMroWindowTopLineResponse setMroWindowTopLine ( const std::vector< Teamcenter::Services::Asbuilt::_2010_04::Asbuilt::SetMroWindowTopLineInfo >& input ) = 0;


protected:
    virtual ~Asbuilt() {}
};
            }
        }
    }
}

#include <teamcenter/services/asbuilt/AsBuilt_undef.h>
#endif

