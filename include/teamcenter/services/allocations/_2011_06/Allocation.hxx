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

#ifndef TEAMCENTER_SERVICES_ALLOCATIONS__2011_06_ALLOCATION_HXX
#define TEAMCENTER_SERVICES_ALLOCATIONS__2011_06_ALLOCATION_HXX

#include <teamcenter/services/allocations/_2007_01/Allocation.hxx>
#include <teamcenter/soa/client/model/BOMWindow.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/allocations/Allocations_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Allocations
        {
            namespace _2011_06
            {
                class Allocation;

class TCSOAALLOCATIONSSTRONGMNGD_API Allocation
{
public:

    struct AllocationContextInput2;

    /**
     * The AttrValueMap map represents Attribute Value pair map for the Allocation Map attributes.
     */
    typedef std::map< std::string, std::string > AttrValueMap;

    /**
     * The <i>AllocationContextInput2</i> structure represents all the data necessary for
     * creating an Allocation Context. The basic attributes that are required by ITK are
     * passed as named elements in the structure. It will be used by the revised SOA createAllocationContext2()
     * which also handles extended attributes.
     */
    struct AllocationContextInput2
    {
        /**
         * The ID of the <b>AllocationMap</b> object to be created. If empty, will be generated.
         */
        std::string id;
        /**
         * The name of the <b>AllocationMap</b> object to be created. Optional input.
         */
        std::string name;
        /**
         * The type of the <b>AllocationMap</b> object to be created. If type is not provided,
         * the <b>AllocationMap</b> created will be of type <i>AllocationMap</i>.
         */
        std::string type;
        /**
         * The revision id for the <b>AllocationRevisionMap</b> object to be created.
         */
        std::string revision;
        /**
         * List of <b>BOMWindow</b> business objects to be associated to the <b>AllocationMap</b>
         * business object, where the created <b>AllocationMap</b> will be the context for the
         * Allocations created between the <b>BOMLines</b> of these <b>BOMWindows</b>.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMWindow>  > openedBOMWindows;
        /**
         * The map of  Attribute names and  value pairs to be used for <b>AllocationMap</b>
         * business object creation of type string/string. The client calling this operation
         * is responsible for converting the different property types (int , float, date etc)
         * to string  using the appropriate to XXXString functions. Multi valued properties
         * are represented with a comma separated string.
         */
        AttrValueMap attrValueMap;
    };




    /**
     * The operation creates an <b>AllocationMap</b> object for the given name, id and attribute
     * map input. This operation has Multi field key support for <b>AllocationMap</b> business
     * object creation. The created <b>AllocationMap</b> object is saved to Teamcenter.
     * It creates an <b>AllocationWindow</b> with the <b>AllocationMapRevision</b> object
     * as context. It adds the input <b>BOMWindow</b> objects as the <b>BOMWindow</b> objects
     * for the <b>AllocationWindow</b>. The created <b>AllocationMap</b>, <b>AllocationRevision</b>,
     * <b>AllocationWindow</b> are returned as created objects list in ServiceData Element.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Create </b><b>AllocationMap</b><b> object with Multi field key support</b>
     * <br>
     * The <b>AllocationMap</b> object can be created with full Multi field key support
     * using this operation. If the business constant of MFK for the <b>AllocationMap</b>
     * object has item_id and any other attribute, then the user can create <b>AllocationMap</b>
     * with same item id as well.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createBOMWindows
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Allocations - Provides the functionality to map occurrences between two or more structures.
     * Currently used in Mechatronics to map logical schematic structures to physical 3D
     * structures.
     *
     * @param input
     *        An <b>AllocationMap</b> business object is created using the input using the id,
     *        name, revision, type,<b> </b><b>BOMWindows</b>, extended attribute values provided
     *        in attrValuemap.
     *
     * @return
     *         Returns the <b>AllocationWindow</b> created, as created Objects list of the ServiceData
     *         Element.  The created <b>AllocationMap</b>, <b>AllocationMapRevision</b> business
     *         object are also returned as part of created objects list of the ServiceData element.
     *         Any errors during the operation will be returned as Partial Errors of the ServiceData
     *         element.
     *
     */
    virtual Teamcenter::Services::Allocations::_2007_01::Allocation::GetAllocationWindowResponse createAllocationContext2 ( const Teamcenter::Services::Allocations::_2011_06::Allocation::AllocationContextInput2&  input ) = 0;


protected:
    virtual ~Allocation() {}
};
            }
        }
    }
}

#include <teamcenter/services/allocations/Allocations_undef.h>
#endif

