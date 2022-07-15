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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING_CORESERVICE_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING_CORESERVICE_HXX

#include <teamcenter/services/manufacturing/_2008_06/Core.hxx>
#include <teamcenter/services/manufacturing/_2010_09/Core.hxx>
#include <teamcenter/services/manufacturing/_2013_05/Core.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/manufacturing/Manufacturing_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Manufacturing
        {
            class CoreService;

/**
 * Contains Core Services
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoamanufacturingstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoamanufacturingtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAMANUFACTURINGSTRONGMNGD_API CoreService
    : public Teamcenter::Services::Manufacturing::_2008_06::Core,
             public Teamcenter::Services::Manufacturing::_2010_09::Core,
             public Teamcenter::Services::Manufacturing::_2013_05::Core
{
public:
    static CoreService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Finds all the checked out items in the objects.
     *
     * @param searchScope
     *        Vector of lines, that we would like to get all the checked out objects from.
     *
     * @return
     *         Structure that contains a vector of all the checked out objects in search scope,
     *         also holds services exceptions.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2008_06::Core::FindCheckedOutsInStructureResponse findCheckedOutsInStructure ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& searchScope ) = 0;

    /**
     * Finding parallel line in a given window of a given line.
     *
     * @param input
     *        Input struct.
     *
     * @return
     *         The found lines.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2010_09::Core::FindNodeInContextResponse findNodeInContext ( const std::vector< Teamcenter::Services::Manufacturing::_2010_09::Core::FindNodeInContextInputInfo >& input ) = 0;

    /**
     * Returns the runtime properties of dependent nodes which are affected when the duration
     * of one or more nodes has been changed in a process or operation structure.
     *
     * @param arguments
     *        A list of GetAffectedPropertiesChanges structures that describe the changes that
     *        have been made to a process or operation structure.
     *
     * @param requestedProperties
     *        The names of the properties that are to be retrieved. In the first version only the
     *        properties that are processed by the Gantt application are accepted (Mfg0calc_duration,
     *        Mfg0calc_start_time, Mfg0calc_dur_start_time).
     *
     * @return
     *         A ServiceData structure that contains the computed property values in the DataObject
     *         member. The structure also informs about errors that occurred during the course of
     *         the operation.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData getAffectedProperties ( const std::vector< Teamcenter::Services::Manufacturing::_2010_09::Core::GetAffectedPropertiesArg >& arguments,
        const std::vector< std::string >& requestedProperties ) = 0;

    /**
     * Getting the related objects of the selected object from the target contexts according
     * to the input information.
     *
     * @param input
     *        Input struct
     *
     * @return
     *         The related objects of the input nodes are added to the response.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2010_09::Core::FindNodeInContextResponse findNodeInContext ( const std::vector< Teamcenter::Services::Manufacturing::_2013_05::Core::FindNodeInContextInputInfo >& input ) = 0;

    /**
     * This operation takes a list of pairs of runtime object and variant rule lists and
     * determines for each object/variant rule combination of each pair whether the object
     * is configured-in for the specified variant rule. Thereby it takes all aspects of
     * an object into account that determine the visibility of the object, such as the variant
     * conditions of the object itself and of all its parent objects as well as the conditions
     * of any assigned object and that of its respective parent objects. The results will
     * depend on the configuration state for IC, revision rule, effectivity etc of the implied
     * windows, including reference windows.
     * <br>
     * If a variant rule supplied in the arguments list is not matched by the variant configuration
     * of any involved window a warning message will be added to the response structure,
     * which indicates that the visibility check regarding the specific variant rule cannot
     * be reliably performed because the configuration of the window contradicts the variant
     * rule.
     * <br>
     * This operation currently does not support modular variants. Only saved variant rules
     * (business object <b>VariantRule</b>) for the classic variant model are accepted or
     * alternatively,  product variants (type <b>Mfg0BvrProductVariant</b>) which are linked
     * to <b>VariantRule</b> objects.
     * <br>
     *
     * @param args
     *        A list of structures, where each entry describes a list of runtime objects and a
     *        list of variant rules or product variants that are matched against each other.
     *
     * @return
     *         A response structure which holds for each runtime object the list of matching variant
     *         rules and/or product variants. The following partial errors are returned in case
     *         invalid parameters are passed to the service:
     *         <br>
     *         300052: If an invalid object is passed to the operation.
     *         <br>
     *         300054: If an object of a wrong type is passed to the operation.
     *         <br>
     *         300062: If there is no variant rule associated with a product variant.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2013_05::Core::MatchObjectsAgainstVariantRulesResponse matchObjectsAgainstVariantRules ( const std::vector< Teamcenter::Services::Manufacturing::_2013_05::Core::MatchObjectsAgainstVariantRulesArg >& args ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CoreService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

