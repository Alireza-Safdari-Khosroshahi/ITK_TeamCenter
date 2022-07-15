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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2013_05_TIMEWAYPLAN_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2013_05_TIMEWAYPLAN_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/manufacturing/Manufacturing_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Manufacturing
        {
            namespace _2013_05
            {
                class Timewayplan;

class TCSOAMANUFACTURINGSTRONGMNGD_API Timewayplan
{
public:

    struct Data;
    struct ProductImageInfo;
    struct TwpInfo;
    struct TwpInfoInput;
    struct TwpResponse;

    /**
     * The map of string which is a data identifier and its corresponding Data.
     */
    typedef std::map< std::string, Data > DetailedInformation;

    /**
     * A map of business objects for which TWP information is requested and its corresponding
     * TWP information.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , TwpInfo > InformationMap;

    /**
     * The structure holds the property value.
     */
    struct Data
    {
        /**
         * Type of the data. Valid types are "Boolean", "Character", "Integer", "Double", "String",
         * "Tag" and "Date". One of the data in this structure need to be accessed based on
         * the data type string.
         */
        std::string dataType;
        /**
         * The list of Boolean values.
         */
        std::vector< bool > boolProperties;
        /**
         * The string representing the list of characters. Each character in the string is a
         * value of the property.
         */
        std::string charProperties;
        /**
         * The list of integer values.
         */
        std::vector< int > integerProperties;
        /**
         * The list of double values.
         */
        std::vector< double > doubleProperties;
        /**
         * The list of string values.
         */
        std::vector< std::string > stringProperties;
        /**
         * The list of business objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > tagProperties;
        /**
         * The list of dates.
         */
        std::vector< Teamcenter::Soa::Common::DateTime > dateProperties;
    };

    /**
     * The input structure contains object(s) for which product image is to be set, the
     * business object of the dataset  representing the image and the product Bill Of Processes
     * (BOP) context.
     */
    struct ProductImageInfo
    {
        /**
         * The list of business objects for which the product image is to be set.
         * <br>
         * The valid types are as follows
         * <br>
         * <ul>
         * <li type="disc"><b>Mfg0BvrProcessStation</b> - process station.
         * </li>
         * <li type="disc"><b>Mfg0BvrProcessLine</b> - process line.
         * </li>
         * <li type="disc"><b>Mfg0BvrProcessArea</b> - process area.
         * </li>
         * <li type="disc"><b>Mfg0BvrPlantBOP</b> - plant Bill Of Processes (BOP).
         * </li>
         * </ul>
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > targetObjects;
        /**
         * The business object representing the top line of the Product Bill Of Processes(BOP).
         * This Product BOP is the context for which the product image is set with the targetObjects
         * and is of type <b>MEProductBOPRevision</b>.
         * <br>
         * This could be NULL provided that there is only one product BOP linked to the plant
         * BOP. In case multiple product BOPs are linked then corresponding error will be reported.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  contextProductBOP;
        /**
         * The business object of the dataset representing the product image. The same product
         * image will be common for all the objects in the input parameter targetObjects.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  imageDataset;
    };

    /**
     * Structure contains the object and its corresponding Time Way Plan (TWP) information.
     */
    struct TwpInfo
    {
        /**
         * The object for which information is fetched.
         * <br>
         * The valid types are
         * <br>
         * <ul>
         * <li type="disc"><b>Mfg0BvrProcessStation</b> - process station
         * </li>
         * <li type="disc"><b>Mfg0BvrProcessLine</b> - process line
         * </li>
         * <li type="disc"><b>Mfg0BvrProcessArea</b> - process area
         * </li>
         * <li type="disc"><b>Mfg0BvrPlantBOP</b> - plant bill of process (BOP) or
         * </li>
         * <li type="disc"><b>Mfg0BvrOperation</b> - operation.
         * </li>
         * </ul>
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * The map of string which is a data identifier and its corresponding Data.
         * <br>
         * Description of valid strings and its data
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;"Operations": Represents the operations executed under the
         * station.
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;"ExecutionPositions": Represents the execution positions
         * for the object of TwpInfo stucture.
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;"Direction": Represents the direction of the station in the
         * plant.
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;"ProductImage": Represents the product image for the station.
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;"PlantCarpet": Represents the carpet diagram of the plant.
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;"TWPLocationForms": Represents the business objects of the
         * TWP Location form associated with the station.
         * <br>
         */
        DetailedInformation detailedInfo;
    };

    /**
     * The input structure contains object(s) for which information is required, the list
     * of string specifying what information is required and the product Bill Of Process
     * (BOP) context. The object can be process station(s), process line(s), process area(s),
     * or plant BOP.
     */
    struct TwpInfoInput
    {
        /**
         * The list of business object for which TWP information is required. The valid types
         * are process station, process line, process area or plant Bill Of Process (BOP).
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > requestedObjects;
        /**
         * The business object representing the top line of the Product Bill Of Process (BOP).
         * This Product BOP is the context for which TWP information is fetched and is of type
         * MEProductBOPRevision   .
         * <br>
         * This could be NULL provided that there is only one product BOP linked to the plant
         * BOP. In case multiple product BOPs are linked then corresponding error will be reported.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  contextProductBOP;
        /**
         * List of string specifying what information is required.
         * <br>
         * The valid options are:
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;<b>OperationDetails:</b> To fetch the operation details of
         * given station.
         * <br>
         * Response will consist of information about all the operations under the given station,
         * the allocated time for those operations and their execution position. Other station
         * related information such as length, width, X-Y Coordinates specifying its location
         * in plant, orientation and direction will also be part of response.
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;<b>ExecutionPositions :</b> To fetch the execution positions
         * of the given station.
         * <br>
         * Other station related information such as length, width, X-Y Coordinates specifying
         * its location in plant, orientation and direction will also be part of response.
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;<b>ProductImage :</b> To fetch the product image which will
         * be displayed on the station in TWP view.
         * <br>
         * &nbsp;&nbsp;&nbsp;&nbsp;<b>PlantCarpet :</b> To fetch the carpet image of the plant.
         * This image is shown in the TWP view as plant layout.
         * <br>
         */
        std::vector< std::string > requiredData;
    };

    /**
     * The response contains a structure of the TWP data and the ServiceData. The possible
     * errors reported are:
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;251048 - The Plant Bill Of Process (BOP) is linked to multiple
     * Product BOPs. Please select one of the Product BOP as context.
     * <br>
     * &nbsp;&nbsp;&nbsp;&nbsp;251049 - The input Product Bill Of Process (BOP) and Plant
     * BOP are not linked.
     * <br>
     */
    struct TwpResponse
    {
        /**
         * The service data containing partial errors if any.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * A map of business objects for which TWP information is requested and its corresponding
         * TWP information.
         */
        InformationMap infoMap;
    };




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


protected:
    virtual ~Timewayplan() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

