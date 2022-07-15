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

#ifndef TEAMCENTER_SERVICES_SYSTEMSENGINEERING__2011_06_FUNCTIONALMODELING_HXX
#define TEAMCENTER_SERVICES_SYSTEMSENGINEERING__2011_06_FUNCTIONALMODELING_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/systemsengineering/SystemsEngineering_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Systemsengineering
        {
            namespace _2011_06
            {
                class Functionalmodeling;

class TCSOASYSTEMSENGINEERINGSTRONGMNGD_API Functionalmodeling
{
public:

    struct DeleteFunctionStructInfo;

    /**
     * <b>DeleteFunctionStructInfo</b> structure represents the parameters required to delete
     * a BOM line or BOM structure.
     */
    struct DeleteFunctionStructInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The line to be deleted.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  funcBomLine;
        /**
         * If true, the entire BOM structure will be deleted.
         */
        bool isDeleteChildren;
    };




    /**
     * This operation deletes a <b>BOMLine</b> object and optionally deletes its entire
     * BOM structure. It not only deletes the structure relations but also deletes the objects
     * underlying the BOM lines. If user chooses to delete the entire BOM structure, the
     * structure is traversed and every node is validated for deletion. If the Teamcenter
     * business object is released or referenced or there are more than one revisions of
     * it, it cannot be deleted.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Systems Engineering - Application to construct Systems Engineering view of the product
     *
     * @param input
     *        holds the required information to delete a line or structure.
     *
     * @return
     *         There are no objects returned but in case of failure to delete the objects, following
     *         errors are returned in the <b>ServiceData</b>.
     *         <br>
     *         <ul>
     *         <li type="disc">292052&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If there are
     *         multiple revisions of the Item, it cannot be deleted.
     *         </li>
     *         <li type="disc">292053&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If the Teamcenter
     *         business object is released, it cannot be deleted.
     *         </li>
     *         <li type="disc">292054&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If the Teamcenter
     *         business object is referenced, it cannot be deleted.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteFunctionStructure ( const std::vector< Teamcenter::Services::Systemsengineering::_2011_06::Functionalmodeling::DeleteFunctionStructInfo >& input ) = 0;


protected:
    virtual ~Functionalmodeling() {}
};
            }
        }
    }
}

#include <teamcenter/services/systemsengineering/SystemsEngineering_undef.h>
#endif

