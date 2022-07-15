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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING_TIMEWAYPLANSERVICE_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING_TIMEWAYPLANSERVICE_HXX

#include <teamcenter/services/manufacturing/_2013_05/Timewayplan.hxx>



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
            class TimewayplanService;

/**
 * This service exposes operations that are used to populate and fetch the Time Way
 * Plan (TWP) information of the business objects such as process stations, process
 * lines, process areas or plant BOP.
 * <br>
 * &nbsp;&nbsp;&nbsp;&nbsp;
 * <br>
 * Use Cases:
 * <br>
 * This service provides following use cases for the specified set of business objects
 * such as process stations, process lines, process area, or product BOP.
 * <br>
 * <ul>
 * <li type="disc"><b>Use Case 1:</b> Fetching TWP information for the business objects
 * such as Process Stations. The operation getTWPInformation can be used for fetching
 * the Time Way Plan information that are used to display the Time Way Plan. The user
 * can request either part of or full TWP data.
 * </li>
 * <li type="disc"><b>Use Case 2:</b> Setting product Image for the Process Station.
 * The operation setProductImage sets the product image associated with the Process
 * Station. This image is used in TWP view for that station.
 * </li>
 * <li type="disc"><b>Use Case 3: </b>Setting location information for the process station.
 * The operation setTWPLocationInfo sets the location information of process station
 * such as station length, station width, X-Y coordinates indicating its location in
 * plant and orientation.
 * </li>
 * </ul>
 * <br>
 * This information is used to display the station in TWP view.
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

class TCSOAMANUFACTURINGSTRONGMNGD_API TimewayplanService
    : public Teamcenter::Services::Manufacturing::_2013_05::Timewayplan
{
public:
    static TimewayplanService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This service operation fetches the Time Way Plan (TWP) information. The operation
     * takes objects from the plant Bill of Processes (BOP) for which TWP information is
     * required, the list of strings specifying what information is required and the context
     * product BOP. The object can be process station(s), process line(s), process area(s),
     * or plant BOP. The list of string will have values "OperationDetails", "ExecutionPositions",
     * "ProductDiagram", and "PlantCarpet" based on which response will contain the information.
     * These values will be applicable to all the objects for which TWP information is required.
     * <br>
     * <br>
     * This information is used to display the Time Way Plan view.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MPP - Core objects and relationships used by the Manufacturing Process Planner application.
     *
     * @param input
     *        The input structure contains object(s) for which information is required, the list
     *        of string specifying what information is required and the product Bill Of Process
     *        (BOP) context. The object can be process station(s), process line(s), process area(s),
     *        or plant BOP.
     *
     * @return
     *         The response contains a structure of the TWP data and the ServiceData. The possible
     *         errors reported are:
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;251048 - The Plant Bill Of Process (BOP) is linked to multiple
     *         Product BOPs. Please select one of the Product BOP as context.
     *         <br>
     *         &nbsp;&nbsp;&nbsp;&nbsp;251049 - The input Product Bill Of Process (BOP) and Plant
     *         BOP are not linked.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2013_05::Timewayplan::TwpResponse getTWPInformation ( const Teamcenter::Services::Manufacturing::_2013_05::Timewayplan::TwpInfoInput&  input ) = 0;

    /**
     * This service operation sets a product image for the given input object. The operation
     * takes objects from the plant Bill Of Processes (BOP) for which the product image
     * is to be set, the business object of the context product BOP, and the business object
     * of the dataset representing the product image. The object   from the plant BOP for
     * which product image is to be set can be process station(s), process line(s), process
     * area(s), or plant BOP.
     * <br>
     * This operation will create a relation between the object from the plant BOP input
     * object and  the dataset business object in context of the input product BOP.
     * <br>
     * The specified product image is displayed on the station in the Time Way Plan (TWP)
     * view.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MPP - Core objects and relationships used by the Manufacturing Process Planner application.
     *
     * @param input
     *        The input structure contains object(s) for which product image is to be set, the
     *        business object of the dataset  representing the image and the product Bill Of Processes
     *        (BOP) context. The object can be process station(s), process line(s), process area(s),
     *        or plant BOP.
     *
     * @return
     *         The ServiceData contains partial errors if any.
     *         <br>
     *         The possible errors reported are:
     *         <br>
     *         <ul>
     *         <li type="disc"><b>253126</b> - The target object "%1$" cannot be modified, because
     *         the user does not have write access.
     *         </li>
     *         <li type="disc"><b>251048</b> - The Plant Bill Of Processes  (BOP) is linked to multiple
     *         Product BOPs. Please select one of the Product BOP as context.
     *         </li>
     *         <li type="disc"><b>251049</b> - The input Product Bill Of Processes  (BOP) and Plant
     *         BOP are not linked.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setProductImage ( const std::vector< Teamcenter::Services::Manufacturing::_2013_05::Timewayplan::ProductImageInfo >& input ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TimewayplanService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

