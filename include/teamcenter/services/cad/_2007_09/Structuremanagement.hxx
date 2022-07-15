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

#ifndef TEAMCENTER_SERVICES_CAD__2007_09_STRUCTUREMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CAD__2007_09_STRUCTUREMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/cad/Cad_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Cad
        {
            namespace _2007_09
            {
                class Structuremanagement;

class TCSOACADSTRONGMNGD_API Structuremanagement
{
public:

    struct CreateOrUpdateVariantCondInput;
    struct VariantCondInfo;

    /**
     * This enum contains comparison operator has 6 values -<code> EQ, NEQ, LT, GT, GTEQ</code>
     * and <code>LTEQ</code>.
     */
    enum ComparisonOperator{ EQ,
                 NEQ,
                 LT,
                 GT,
                 GTEQ,
                 LTEQ
                 };

    /**
     * Contains the operation type as enum and has 2 values - <code>Create</code> and <code>Update</code>.
     */
    enum Operation{ Create,
                 Update
                 };

    /**
     * This enum contains the join operator type has 4 values - <code>AND</code>, <code>OR,
     * OPEN_BRACKET</code> and <code>CLOSE_BRACKET</code>.
     */
    enum VariantOperator{ AND,
                 OR,
                 OPEN_BRACKET,
                 CLOSE_BRACKET
                 };

    /**
     * Contains the input for create/update variant condition associated with a <b>BOMLine</b>
     * object.
     */
    struct CreateOrUpdateVariantCondInput
    {
        /**
         * Identifier that helps the client to track the object(s) created.
         */
        std::string clientId;
        /**
         * Refers to <code>Operation</code> enum which refers to the operation type.
         */
        Operation operation;
        /**
         * Refers to <b>BOMLine</b> object on which variant condition has been defined.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  bomLine;
        /**
         * Refers to a list of <code>VariantCondInfo</code> struct, and contains the information
         * needed to create/update a variant condition.
         */
        std::vector< Teamcenter::Services::Cad::_2007_09::Structuremanagement::VariantCondInfo > variantCondInfo;
    };

    /**
     * Contains the information related to classic variant condition.
     */
    struct VariantCondInfo
    {
        /**
         * Refers to the classic variant option name.
         */
        std::string optionName;
        /**
         * Refers to item id where classic variant option is defined.
         */
        std::string itemId;
        /**
         * Refers to <code>VariantOperator</code> enum.
         */
        VariantOperator joinOperator;
        /**
         * Refers to <code>ComparisonOperator</code> enum.
         */
        ComparisonOperator compOperator;
        /**
         * Refers to classic variant option value.
         */
        std::string value;
    };




    /**
     * This operation is to <code>create</code> or <code>update</code> (depending on the
     * Operation) a variantCondition ( which is variant expression of type load if) for
     * a <b>BOMLine</b> object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This operation will be used when user wants to create a new or update an existing
     * classic variant condition for a given <b>BOMLine</b> objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param inputObjects
     *        This has the list of <code>CreateOrUpdateVariantCondInput</code> struct, which are
     *        used to create a new variant condition or update an existing variant condition.
     *
     * @return
     *         The <code>serviceData</code> returned with objects in case of success scenario. In
     *         case of failure scenario, this will return partial errors with <code>serviceData</code>
     *         with original input object(s) if any.
     *         <br>
     *         Some of the application level errors codes are listed as below.
     *         <br>
     *         <ul>
     *         <li type="disc">46001 Invalid tag received by BOM Module
     *         </li>
     *         <li type="disc">46110 You cannot have substitutes of the top line of the BOM
     *         </li>
     *         <li type="disc">215160 Not a valid operation
     *         </li>
     *         <li type="disc">215161 Cannot find a valid Variant Expression block associated with
     *         this BOMLine
     *         </li>
     *         <li type="disc">215166 Failed to save BOMWindow.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData createOrUpdateVariantConditions2 ( const std::vector< Teamcenter::Services::Cad::_2007_09::Structuremanagement::CreateOrUpdateVariantCondInput >& inputObjects ) = 0;


protected:
    virtual ~Structuremanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/cad/Cad_undef.h>
#endif

