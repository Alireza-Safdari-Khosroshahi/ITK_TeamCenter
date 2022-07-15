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

#ifndef TEAMCENTER_SERVICES_SVCPROCESSING__2009_06_SERVICEPROCESSING_HXX
#define TEAMCENTER_SERVICES_SVCPROCESSING__2009_06_SERVICEPROCESSING_HXX

#include <teamcenter/soa/client/model/TransactionElement.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/svcprocessing/SvcProcessing_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Svcprocessing
        {
            namespace _2009_06
            {
                class Serviceprocessing;

class TCSOASVCPROCESSINGSTRONGMNGD_API Serviceprocessing
{
public:

    struct StatusInput;
    struct SetTxnStatusInfo;
    struct SetTxnStatusOutput;
    struct SetTxnStatusResponse;

    /**
     * StringMap
     */
    typedef std::map< std::string, std::string > StringMap;

    /**
     * StatusInput
     */
    struct StatusInput
    {
        /**
         * Business Object to change
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransactionElement>  transElem;
        /**
         * Map containing string status property values
         */
        StringMap stringProps;
    };

    /**
     * Input structure.
     */
    struct SetTxnStatusInfo
    {
        /**
         * A unique client identifier. This is a unique string supplied by the caller. This
         * ID
         * <br>
         * is used to identify return data elements and partial errors associated with this
         * input structure.
         * <br>
         */
        std::string clientId;
        /**
         * Input data comprising of the transaction element and the approval attribute based
         * on which the status is assigned.
         * <br>
         */
        Teamcenter::Services::Svcprocessing::_2009_06::Serviceprocessing::StatusInput data;
    };

    /**
     * The output structure.
     */
    struct SetTxnStatusOutput
    {
        /**
         * Identifier that helps the client track the object(s) created
         */
        std::string clientId;
        /**
         * Service data including partial errors that are mapped to the client id
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::TransactionElement>  > transElemObjs;
    };

    /**
     * Structure containing approval status and Service Data.
     */
    struct SetTxnStatusResponse
    {
        /**
         * This represents a vector of output objects
         */
        std::vector< Teamcenter::Services::Svcprocessing::_2009_06::Serviceprocessing::SetTxnStatusOutput > output;
        /**
         * The SOA framework object containing objects whose status for the approval attribute
         * is set based on the input and error information returned based on validations performed.
         * <br>
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation sets the status of the transaction element based on the <code>SetTxnStatusInfo</code>
     * supplied. The <code>SetTxnStatusInfo</code> contains information for properties such
     * as <code>clientId</code> and <code>data</code>. The value of the approval attribute
     * is obtained and the corresponding transaction element status is set by calling the
     * operation <code>setTxnElementStatus</code>.  This operation utilizes the input information
     * which consists of the approval value, the transaction element type and name. The
     * operation performs validations to ensure that all conditions are met and an attempt
     * to approve an object that is already approved throws an appropriate error message
     * to the user.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Service Processing - This Component is intended to identify all Operations and Services
     * under Service Processing.
     *
     * @param info
     *        Input parameter that represents data encompassing information about the
     *        <br>
     *        element name, element type and approval process.
     *        <br>
     *
     * @return
     *         <code>SetTxnStatusResponse</code> which contains the client id and status of the
     *         approval operation. Any failure will be returned in the standard<code> Service Data</code>
     *         under partial errors based on validations performed. Following are some error(s)
     *         returned:
     *         <br>
     *         <ul>
     *         <li type="disc">246002:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The object
     *         of type <i>object_type</i> with transaction id <i>id</i> is already approved.
     *         </li>
     *         <li type="disc">246004:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A remote object
     *         cannot be approved.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Svcprocessing::_2009_06::Serviceprocessing::SetTxnStatusResponse setTxnElementStatus ( const std::vector< Teamcenter::Services::Svcprocessing::_2009_06::Serviceprocessing::SetTxnStatusInfo >& info ) = 0;


protected:
    virtual ~Serviceprocessing() {}
};
            }
        }
    }
}

#include <teamcenter/services/svcprocessing/SvcProcessing_undef.h>
#endif

